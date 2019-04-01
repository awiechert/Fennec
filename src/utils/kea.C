/*!
 *  \file kea.h kea.cpp
 *	\brief Kernel for Estimating Activity-distribution
 *  \author Austin Ladshaw
 *	\date 02/07/2019
 *	\copyright This software was designed and built at the Georgia Institute
 *             of Technology by Austin Ladshaw for research in the area
 *             of radioactive particle decay and transport. Copyright (c) 2018,
 *			   all rights reserved.
 */

#include "kea.h"
#include "crane.h"  ///< For testing purposes only.

//Model choice
asd_model activitymodel_choice(std::string &choice)
{
	asd_model type = freiling;
	
	std::string copy = choice;
	for (int i=0; i<copy.size(); i++)
		copy[i] = tolower(copy[i]);
	
	if (copy == "freiling")
		type = freiling;
	else if (copy == "freiling-tompkins")
		type = freiling_tompkins;
	else if (copy == "modified-freiling")
		type = mod_freiling;
	else if (copy == "modified-freiling-tompkins")
		type = mod_freiling_tompkins;
	else
		type = freiling;
	
	return type;
}

/*
 *								Start: ActivityDistribution Class Definitions
 *	-------------------------------------------------------------------------------------
 */

//Constructor
ActivityDistribution::ActivityDistribution()
{
	model_type = freiling;
	capfis_ratio = 0.0;
	neutrons_emit = 1.5;
	fusion_yield = 25.0;
	fission_yield = 25.0;
	total_yield = 50.0;
	casing_cap = 0.2;
	casing_den = 8.05;
	casing_thickness = 10.0;
	casing_mw = 100.0;
	casing_thermal = 0.2;
	soil_thermal = 0.2;
	soil_scattering = 2.0;
	weapon_thermal = 0.2;
	size_cutoff = 100.0;
	burst_height = 0.0;
	escape_fraction = 0.0;
	volatile_fraction = 0.0;
	soil_capture_fraction = 0.0;
}

//Destructor
ActivityDistribution::~ActivityDistribution()
{
	delete_fractionation();
	delete_capture_fractions();
	delete_casing_components();
}

void ActivityDistribution::set_model_type(asd_model type)
{
	this->model_type = type;
}

void ActivityDistribution::set_capfis_ratio(double val)
{
	this->capfis_ratio = val;
}

void ActivityDistribution::set_neutrons_emit(double val)
{
	this->neutrons_emit = val;
}

void ActivityDistribution::set_fusion_yield(double val)
{
	this->fusion_yield = val;
}

void ActivityDistribution::set_fission_yield(double val)
{
	this->fission_yield = val;
}

void ActivityDistribution::set_total_yield(double val)
{
	this->total_yield = val;
}

void ActivityDistribution::set_casing_cap(double val)
{
	this->casing_cap = val;
}

void ActivityDistribution::set_casing_den(double val)
{
	this->casing_den = val;
}

void ActivityDistribution::set_casing_thickness(double val)
{
	this->casing_thickness = val;
}

void ActivityDistribution::set_casing_mw(double val)
{
	this->casing_mw = val;
}

void ActivityDistribution::set_casing_thermal(double val)
{
	this->casing_thermal = val;
}

void ActivityDistribution::set_soil_thermal(double val)
{
	this->soil_thermal = val;
}

void ActivityDistribution::set_soil_scattering(double val)
{
	this->soil_scattering = val;
}

void ActivityDistribution::set_weapon_thermal(double val)
{
	this->weapon_thermal = val;
}

void ActivityDistribution::set_size_cutoff(double val)
{
	this->size_cutoff = val;
}

void ActivityDistribution::set_burst_height(double val)
{
	this->burst_height = val;
}

void ActivityDistribution::set_escape_fraction(double val)
{
	this->escape_fraction = val;
}

void ActivityDistribution::set_volatile_fraction(double val)
{
	this->volatile_fraction = val;
}

void ActivityDistribution::set_soil_capture_fraction(double val)
{
	this->soil_capture_fraction = val;
}

void ActivityDistribution::initialize_fractionation_map(std::map<double, double> & part_conc)
{
	
}

void ActivityDistribution::delete_casing_components()
{
	this->casing_atom_frac.clear();
	this->casing_mat.clear();
	this->casing_frac.clear();
}

void ActivityDistribution::add_casing_component(std::string name, double frac)
{
	if (frac < 0.0)
		frac = 0.0;
	if (frac > 1.0)
		frac = 1.0;
	this->casing_frac[name] = frac;
	Molecule temp;
	if (name == "Other")
		temp.Register(0, 0, 0, 0, false, false, "Solid", name, name, "Fe10C");
	else
		temp.Register(0, 0, 0, 0, false, false, "Solid", name, name, name);
	this->casing_mat[name] = temp;
}

void ActivityDistribution::verify_casing_components()
{
	//Iterate through the map
	std::map<std::string,double>::iterator it;
	double sum = 0.0;
	int count = 0;
	for (it=this->casing_frac.begin(); it!=this->casing_frac.end(); ++it)
	{
		sum += it->second;
		count++;
	}
	if (count == 0)
	{
		this->add_casing_component("Other", 1.0);
	}
	else
	{
		if ( sum > 1.0 )
		{
			for (it=this->casing_frac.begin(); it!=this->casing_frac.end(); ++it)
			{
				it->second = it->second / sum;
			}
		}
		if ( sum < 1.0 )
		{
			double diff = 1.0 - sum;
			it = this->casing_frac.find("Other");
			if (it == this->casing_frac.end())
			{
				this->add_casing_component("Other", diff);
			}
			else
			{
				this->casing_frac["Other"] += diff;
			}
		}
	}
	
	//Create the soil atom map
	for (it=this->casing_frac.begin(); it!=this->casing_frac.end(); ++it)
	{
		for (int i=0; i<this->casing_mat[it->first].getAtoms().size(); i++)
		{
			this->casing_atom_frac[this->casing_mat[it->first].getAtoms()[i].AtomSymbol()] = 0.0;
		}
	}
	//Fill the soil atom map
	for (it=this->casing_frac.begin(); it!=this->casing_frac.end(); ++it)
	{
		for (int i=0; i<this->casing_mat[it->first].getAtoms().size(); i++)
		{
			this->casing_atom_frac[this->casing_mat[it->first].getAtoms()[i].AtomSymbol()] += it->second*(1.0/(double)this->casing_mat[it->first].getAtoms().size());
		}
	}
	
	for (it=this->casing_atom_frac.begin(); it!=this->casing_atom_frac.end(); ++it)
	{
		Atom temp;
		temp.Register(it->first);
		this->casing_atom[it->first] = temp;
	}
}

void ActivityDistribution::delete_fractionation()
{
	this->nuc_fractionation.clear();
	this->total_moles.clear();
	this->refractory_moles.clear();
	this->freiling_numbers.clear();
	this->distribution.clear();
}

void ActivityDistribution::delete_capture_fractions()
{
	this->casing_capfrac.clear();
	this->soil_capfrac.clear();
	this->weapon_capfrac.clear();
}

asd_model ActivityDistribution::get_model_type()
{
	return this->model_type;
}

double ActivityDistribution::get_capfis_ratio()
{
	return this->capfis_ratio;
}

double ActivityDistribution::get_neutrons_emit()
{
	return this->neutrons_emit;
}

double ActivityDistribution::get_fusion_yield()
{
	return this->fusion_yield;
}

double ActivityDistribution::get_fission_yield()
{
	return this->fission_yield;
}

double ActivityDistribution::get_total_yield()
{
	return this->total_yield;
}

double ActivityDistribution::get_casing_cap()
{
	return this->casing_cap;
}

double ActivityDistribution::get_casing_den()
{
	return this->casing_den;
}

double ActivityDistribution::get_casing_thickness()
{
	return this->casing_thickness;
}

double ActivityDistribution::get_casing_mw()
{
	return this->casing_mw;
}

double ActivityDistribution::get_casing_thermal()
{
	return this->casing_thermal;
}

double ActivityDistribution::get_soil_thermal()
{
	return this->soil_thermal;
}

double ActivityDistribution::get_soil_scattering()
{
	return this->soil_scattering;
}

double ActivityDistribution::get_weapon_thermal()
{
	return this->weapon_thermal;
}

double ActivityDistribution::get_size_cutoff()
{
	return this->size_cutoff;
}

double ActivityDistribution::get_burst_height()
{
	return this->burst_height;
}

double ActivityDistribution::get_escape_fraction()
{
	return this->escape_fraction;
}

double ActivityDistribution::get_volatile_fraction()
{
	return this->volatile_fraction;
}

double ActivityDistribution::get_soil_capture_fraction()
{
	return this->soil_capture_fraction;
}

void ActivityDistribution::compute_neutrons_emit(double fission, double fusion)
{
	this->set_neutrons_emit( 1.5 + (3.0*fusion/fission) );
}

void ActivityDistribution::compute_casing_mw()
{
	double mw = 0.0;
	
	//Iterate through the map
	std::map<std::string,double>::iterator it;
	for (it=this->casing_frac.begin(); it!=this->casing_frac.end(); it++)
	{
		mw += it->second*this->casing_mat[it->first].MolarWeight();
	}
	this->set_casing_mw(mw);
}

void ActivityDistribution::compute_casing_thermal()
{
	double sum = 0.0;
	
	//Iterate through the map
	std::map<std::string,double>::iterator it;
	for (it=this->casing_atom_frac.begin(); it!=this->casing_atom_frac.end(); it++)
	{
		sum += it->second*this->casing_atom[it->first].ThermalXSection();
	}
	this->set_casing_thermal(sum);
}

void ActivityDistribution::compute_soil_thermal(std::map<std::string, double> & soil_atom_frac, std::map<std::string, Atom> & soil_atom)
{
	double sum = 0.0;
	//Iterate through the map
	std::map<std::string,double>::iterator it;
	for (it=soil_atom_frac.begin(); it!=soil_atom_frac.end(); it++)
	{
		sum += it->second*soil_atom[it->first].ThermalXSection();
	}
	this->set_soil_thermal(sum);
}

void ActivityDistribution::compute_soil_scattering(std::map<std::string, double> & soil_atom_frac, std::map<std::string, Atom> & soil_atom)
{
	double sum = 0.0;
	//Iterate through the map
	std::map<std::string,double>::iterator it;
	for (it=soil_atom_frac.begin(); it!=soil_atom_frac.end(); it++)
	{
		sum += it->second*soil_atom[it->first].ScatterXSection();
	}
	this->set_soil_scattering(sum);
}

void ActivityDistribution::compute_weapon_thermal(FissionProducts & weapon)
{
	double sum = 0.0;
	for (int i=0; i<weapon.getWeaponMat().size(); i++)
	{
		sum += weapon.getWeaponFrac()[i]/100.0*weapon.getWeaponMat()[i].ThermalXSection();
	}
	this->set_weapon_thermal(sum);
}

void ActivityDistribution::compute_casing_capfrac()
{
	this->compute_casing_thermal();
	//Iterate through the map
	std::map<std::string,double>::iterator it;
	for (it=this->casing_atom_frac.begin(); it!=this->casing_atom_frac.end(); it++)
	{
		this->casing_capfrac[it->first] = it->second*this->casing_atom[it->first].ThermalXSection()/this->get_casing_thermal();
	}
}

void ActivityDistribution::compute_soil_capfrac(std::map<std::string, double> & soil_atom_frac, std::map<std::string, Atom> & soil_atom)
{
	this->compute_soil_thermal(soil_atom_frac, soil_atom);
	this->compute_soil_scattering(soil_atom_frac, soil_atom);
	//Iterate through the map
	std::map<std::string,double>::iterator it;
	for (it=soil_atom_frac.begin(); it!=soil_atom_frac.end(); it++)
	{
		this->soil_capfrac[it->first] = it->second*soil_atom[it->first].ThermalXSection()/this->get_soil_thermal();
	}
}

void ActivityDistribution::compute_weapon_capfrac(FissionProducts & weapon)
{
	this->compute_weapon_thermal(weapon);
	for (int i=0; i<weapon.getWeaponMat().size(); i++)
	{
		this->weapon_capfrac[weapon.getWeaponMat()[i].IsotopeName()] = 0.0;
	}
	for (int i=0; i<weapon.getWeaponMat().size(); i++)
	{
		this->weapon_capfrac[weapon.getWeaponMat()[i].IsotopeName()] += weapon.getWeaponFrac()[i]/100.0*weapon.getWeaponMat()[i].ThermalXSection()/this->get_weapon_thermal();
	}
	
}

void ActivityDistribution::compute_casing_cap()
{
	this->compute_casing_mw();
	this->compute_casing_thermal();
	this->set_casing_cap( this->get_casing_den()*Na*this->get_casing_thermal()*1.0E-24/this->get_casing_mw() );
}

void ActivityDistribution::compute_escape_fraction()
{
	this->compute_casing_cap();
	this->set_escape_fraction( exp(-this->get_casing_thickness()*this->get_casing_cap()) );
}

void ActivityDistribution::compute_volatile_fraction(double h, double W)
{
	//Convert h (m) to h (ft)
	this->set_burst_height(h*3.28084);
	
	//Form the scaled burst height
	double scaled = this->get_burst_height()/pow(W,(1.0/3.0));
	if (scaled < 0.0) scaled = 0.0;
	double val = 0.0;
	
	if (scaled > 36.0)
		val = 0.0;
	else
		val = 1.0 - (scaled / pow(4.24*scaled*scaled - 234.0*scaled + 4225.0, 0.5));
	
	this->set_volatile_fraction(val);
}

void ActivityDistribution::compute_soil_capture_fraction(std::map<std::string, double> & soil_atom_frac, std::map<std::string, Atom> & soil_atom)
{
	this->compute_soil_thermal(soil_atom_frac, soil_atom);
	this->compute_soil_scattering(soil_atom_frac, soil_atom);
	
	this->set_soil_capture_fraction( 1.155*pow(this->get_soil_thermal()/(this->get_soil_thermal()+this->get_soil_scattering()), 0.5) );
}

void ActivityDistribution::initialize_fractionation(FissionProducts & yields, yaml_cpp_class & data)
{
	//yields.loadFissionProductYields();
	yields.loadFissionProductYields(data);
	yields.evaluateYields();
	this->initial_frac = yields;
}

int ActivityDistribution::evaluate_initial_fractionation()
{
	/** Must have finished initializing and calculating all related neutron capture fractions first */
	std::map<std::string,double>::iterator it;
	
	//Registering Soil Nuclides
	for (it=this->soil_capfrac.begin(); it!=this->soil_capfrac.end(); ++it)
	{
		double preprod = this->initial_frac.getTotalMoles()*this->initial_frac.getFissionExtent()/100.0*this->get_neutrons_emit()*this->get_escape_fraction()*this->get_soil_capture_fraction()*this->get_volatile_fraction();
		Atom temp;
		temp.Register(it->first);
		int iso_num = temp.Neutrons()+temp.Protons()+1;
		double ic = preprod*it->second;
		this->initial_frac.registerInitialNuclide(it->first, iso_num, ic);
	}
	
	//Registering Casing Nuclides
	for (it=this->casing_capfrac.begin(); it!=this->casing_capfrac.end(); ++it)
	{
		double preprod = this->initial_frac.getTotalMoles()*this->initial_frac.getFissionExtent()/100.0*this->get_neutrons_emit()*(1.0-this->get_escape_fraction());
		Atom temp;
		temp.Register(it->first);
		int iso_num = temp.Neutrons()+temp.Protons()+1;
		double ic = preprod*it->second;
		this->initial_frac.registerInitialNuclide(it->first, iso_num, ic);
	}
	
	//Registering Weapon Nuclides
	for (it=this->weapon_capfrac.begin(); it!=this->weapon_capfrac.end(); ++it)
	{
		int iso_num = 1;
		std::string symb = "n";
		
		char *str = new char[it->first.length()+1];
		strcpy(str, it->first.c_str());
		char * pch;
		pch = strtok(str, "-");
		while (pch != NULL)
		{
			if (isdigit(pch[0]) != 0)
				iso_num = atoi(pch)+1;
			else
				symb = pch;
			pch = strtok (NULL, " ,.-");
		}
		delete [] str;
		
		double ic = this->initial_frac.getTotalMoles()*this->initial_frac.getFissionExtent()/100.0*this->get_neutrons_emit()*(1.0-this->initial_frac.getFissionExtent()/100.0)*it->second;
		this->initial_frac.registerInitialNuclide(symb, iso_num, ic);
	}
	this->initial_frac.evaluateEigenSolution();
	return this->initial_frac.verifyEigenSoln();
}

void ActivityDistribution::evaluate_freiling_ratios(double solid_time, double solid_temp)
{
	this->initial_frac.calculateFractionation(solid_time);
	
	//Reset all initial conditions
	double conc = 0.0;
	for (int i=0; i<this->initial_frac.getNumberNuclides(); i++)
	{
		conc = this->initial_frac.getIsotope(i).getConcentration();
		if (conc < 0.0) conc = 0.0;
		this->initial_frac.getIsotope(i).setInitialCondition(conc);
	}
	for (int i=0; i<this->initial_frac.getNumberStableNuclides(); i++)
	{
		conc = this->initial_frac.getStableIsotope(i).getConcentration();
		if (conc < 0.0) conc = 0.0;
		this->initial_frac.getStableIsotope(i).setInitialCondition(conc);
	}
	
	//Setup all Freiling Ratios
	int mass_num = this->initial_frac.getIsotope(0).IsotopeNumber();
	this->total_moles[mass_num] = 0.0;
	this->refractory_moles[mass_num] = 0.0;
	for (int i=0; i<this->initial_frac.getNumberNuclides(); i++)
	{
		if (mass_num == this->initial_frac.getIsotope(i).IsotopeNumber())
		{
			this->total_moles[mass_num] += this->initial_frac.getIsotope(i).getInitialCondition();
			if (this->initial_frac.getIsotope(i).BoilingPoint() >= solid_temp)
				this->refractory_moles[mass_num] += this->initial_frac.getIsotope(i).getInitialCondition();
		}
		else
		{
			mass_num = this->initial_frac.getIsotope(i).IsotopeNumber();
			this->total_moles[mass_num] = this->initial_frac.getIsotope(i).getInitialCondition();
			if (this->initial_frac.getIsotope(i).BoilingPoint() >= solid_temp)
				this->refractory_moles[mass_num] = this->initial_frac.getIsotope(i).getInitialCondition();
		}
	}
	std::map<int, double>::iterator it;
	mass_num = this->initial_frac.getStableIsotope(0).IsotopeNumber();
	it = this->total_moles.find(mass_num);
	if (it == this->total_moles.end())
	{
		this->total_moles[mass_num] = 0.0;
		this->refractory_moles[mass_num] = 0.0;
	}
	for (int i=0; i<this->initial_frac.getNumberStableNuclides(); i++)
	{
		if (mass_num == this->initial_frac.getStableIsotope(i).IsotopeNumber())
		{
			this->total_moles[mass_num] += this->initial_frac.getStableIsotope(i).getInitialCondition();
			if (this->initial_frac.getStableIsotope(i).BoilingPoint() >= solid_temp)
				this->refractory_moles[mass_num] += this->initial_frac.getStableIsotope(i).getInitialCondition();
		}
		else
		{
			mass_num = this->initial_frac.getStableIsotope(i).IsotopeNumber();
			it = this->total_moles.find(mass_num);
			if (it == this->total_moles.end())
			{
				this->total_moles[mass_num] = this->initial_frac.getStableIsotope(i).getInitialCondition();
				if (this->initial_frac.getStableIsotope(i).BoilingPoint() >= solid_temp)
					this->refractory_moles[mass_num] = this->initial_frac.getStableIsotope(i).getInitialCondition();
			}
			else
			{
				this->total_moles[mass_num] += this->initial_frac.getStableIsotope(i).getInitialCondition();
				if (this->initial_frac.getStableIsotope(i).BoilingPoint() >= solid_temp)
					this->refractory_moles[mass_num] += this->initial_frac.getStableIsotope(i).getInitialCondition();
			}
		}
	}
	
	for (it=this->total_moles.begin(); it!=this->total_moles.end(); ++it)
	{
		if (it->second > 0.0)
			this->freiling_numbers[it->first] = sqrt(this->refractory_moles[it->first]/it->second);
		else
			this->freiling_numbers[it->first] = 0.0;
	}
}

void ActivityDistribution::evalute_freiling_dist(std::map<double, double> & part_conc)
{
	//Loop through all mass numbers
	std::map<int, double>::iterator it;
	for (it=this->freiling_numbers.begin(); it!=this->freiling_numbers.end(); ++it)
	{
		//Loop through all the particle sizes
		std::map<double, double>::iterator kt;
		for (kt=part_conc.begin(); kt!=part_conc.end(); ++kt)
		{
			//Now calculuate the distribution (j loop over part_conc)
			double denom = 0.0;
			std::map<double, double>::iterator jt;
			for (jt=part_conc.begin(); jt!=part_conc.end(); ++jt)
			{
				denom += jt->second*pow(jt->first, (it->second+2.0) );
			}
			this->distribution[it->first][kt->first] = kt->second*pow(kt->first, (it->second+2.0))/denom;
		}
	}
}

void ActivityDistribution::evalute_freiling_tompkins_dist(std::map<double, double> & part_hist)
{
	//Loop through all mass numbers
	std::map<int, double>::iterator it;
	for (it=this->freiling_numbers.begin(); it!=this->freiling_numbers.end(); ++it)
	{
		//Loop through all the particle sizes
		std::map<double, double>::iterator kt;
		for (kt=part_hist.begin(); kt!=part_hist.end(); ++kt)
		{
			//Now calculuate the distribution (j loop over part_hist)
			double denom = 0.0;
			std::map<double, double>::iterator jt;
			for (jt=part_hist.begin(); jt!=part_hist.end(); ++jt)
			{
				denom += jt->second*pow(jt->first, (it->second-1.0) );
			}
			double E_factor = 1.0/denom;
			this->distribution[it->first][kt->first] = (E_factor/(1.0+E_factor*pow(this->get_size_cutoff(), (it->second-1.0)) ) ) * (pow(this->get_size_cutoff(), (it->second-1.0))+pow(kt->first, (it->second-1.0))) * kt->second;
			
		}
	}
}

void ActivityDistribution::evalute_mod_freiling_dist(std::map<double, double> & part_hist)
{
	//Loop through all mass numbers
	std::map<int, double>::iterator it;
	for (it=this->freiling_numbers.begin(); it!=this->freiling_numbers.end(); ++it)
	{
		double FR = it->second*it->second;
		//Loop through all the particle sizes
		std::map<double, double>::iterator kt;
		for (kt=part_hist.begin(); kt!=part_hist.end(); ++kt)
		{
			//Now calculuate the distribution sum (j loop over part_conc)
			double sum = 0.0;
			std::map<double, double>::iterator jt;
			for (jt=part_hist.begin(); jt!=part_hist.end(); ++jt)
			{
				sum += jt->second*pow(jt->first, -1.0 );
			}
			this->distribution[it->first][kt->first] = kt->second*(FR + ((1.0-FR)*pow(kt->first, -1.0)/sum) );
		}
	}
}

void ActivityDistribution::evalute_mod_freiling_tompkins_dist(std::map<double, double> & part_hist)
{
	//Loop through all mass numbers
	std::map<int, double>::iterator it;
	for (it=this->freiling_numbers.begin(); it!=this->freiling_numbers.end(); ++it)
	{
		double FR = it->second*it->second;
		//Loop through all the particle sizes
		std::map<double, double>::iterator kt;
		for (kt=part_hist.begin(); kt!=part_hist.end(); ++kt)
		{
			//Now calculuate the distribution (j loop over part_hist)
			double denom = 0.0;
			std::map<double, double>::iterator jt;
			for (jt=part_hist.begin(); jt!=part_hist.end(); ++jt)
			{
				denom += jt->second*pow(jt->first, -1.0 );
			}
			double Ri = 1.0 + FR + ((1.0-FR)*(1.0 - (pow(this->get_size_cutoff(), -1.0)/denom)));
			Ri = 1.0/Ri;
			this->distribution[it->first][kt->first] = kt->second*(1.0-(Ri*(1.0-FR)*(1.0-(pow(kt->first, -1.0)/denom))));
		}
	}
}

void ActivityDistribution::evalute_distribution(std::map<double, double> & part_conc, std::map<double, double> & part_hist)
{
	switch (this->model_type)
	{
		case freiling:
			this->evalute_freiling_dist(part_conc);
			break;
			
		case freiling_tompkins:
			this->evalute_freiling_tompkins_dist(part_hist);
			break;
			
		case mod_freiling:
			this->evalute_mod_freiling_dist(part_hist);
			break;
			
		case mod_freiling_tompkins:
			this->evalute_mod_freiling_tompkins_dist(part_hist);
			break;
			
		default:
			this->evalute_freiling_dist(part_conc);
			break;
	}
	
	//Iterate through distribution map and correct by normalization
	/**
	std::unordered_map<int, std::unordered_map<double, double> >::iterator it;
	for (it=this->distribution.begin(); it!=this->distribution.end(); ++it)
	{
		double sum = 0.0;
		std::unordered_map<double, double>::iterator kt;
		for (kt=it->second.begin(); kt!=it->second.end(); ++kt)
		{
			sum += kt->second;
		}
		std::cout << sum << std::endl;
	}
	*/
}

void ActivityDistribution::distribute_nuclides(std::map<double, double> & part_hist)
{
	//Loop through all the particle sizes and initialize FissionProducts
	std::map<double, double>::iterator kt;
	for (kt=part_hist.begin(); kt!=part_hist.end(); ++kt)
	{
		this->nuc_fractionation[kt->first] = this->initial_frac;
	}
	
	//Loop through nuclides fraction map
	std::map<double, FissionProducts>::iterator it;
	for (it=this->nuc_fractionation.begin(); it!=this->nuc_fractionation.end(); ++it)
	{
		//Looping through the stable and unstable nuclides
		for (int i=0; i<it->second.getNumberNuclides(); i++)
		{
			int mass_num = it->second.getIsotope(i).IsotopeNumber();
			it->second.getIsotope(i).setInitialCondition(it->second.getIsotope(i).getInitialCondition()*this->distribution[mass_num][it->first]);
		}
		for (int i=0; i<it->second.getNumberStableNuclides(); i++)
		{
			int mass_num = it->second.getStableIsotope(i).IsotopeNumber();
			it->second.getStableIsotope(i).setInitialCondition(it->second.getStableIsotope(i).getInitialCondition()*this->distribution[mass_num][it->first]);
		}
	}

}

void ActivityDistribution::evaluate_fractionation(std::string file_name, bool file_out, double solid_time, double stab_time)
{
	
	//Open a file to print results to
	std::map<double, FissionProducts>::iterator kt;
	FILE *file;
	
	if (file_out == true)
	{
		file = fopen(file_name.c_str(), "w+");
		if (file == nullptr)
		{
			system("mkdir output");
			file = fopen(file_name.c_str(), "w+");
		}
	
		//Print out initial conditions (at solidification time)
		fprintf(file, "Solidification Time (s) =\t%.6g\n",solid_time);
		for (int i=0; i<this->initial_frac.getNumberNuclides(); i++)
		{
			if (i==0)
				fprintf(file, "\tUnstable");
			else
				fprintf(file, "\t***");
		}
		for (int i=0; i<this->initial_frac.getNumberStableNuclides(); i++)
		{
			if (i==0)
				fprintf(file, "\tStable");
			else
				fprintf(file, "\t###");
		}
		fprintf(file, "\n");
		fprintf(file, "Size (um)");
		for (int i=0; i<this->initial_frac.getNumberNuclides(); i++)
			fprintf(file, "\t%s", this->initial_frac.getIsotope(i).IsotopeName().c_str());
		for (int i=0; i<this->initial_frac.getNumberStableNuclides(); i++)
			fprintf(file, "\t%s", this->initial_frac.getStableIsotope(i).IsotopeName().c_str());
		fprintf(file, "\n");
		for (kt=this->nuc_fractionation.begin(); kt!=nuc_fractionation.end(); ++kt)
		{
			fprintf(file, "%.6g", kt->first);
			for (int i=0; i<kt->second.getNumberNuclides(); i++)
				fprintf(file, "\t%.6g", kt->second.getIsotope(i).getInitialCondition());
			for (int i=0; i<kt->second.getNumberStableNuclides(); i++)
				fprintf(file, "\t%.6g", kt->second.getStableIsotope(i).getInitialCondition());
			fprintf(file, "\n");
		}
		fprintf(file, "\n");
	}
	
	//Run simulations
	if (this->initial_frac.isConsoleOut() == true)
		std::cout << "Running fractionation simulation for all size classes. Please wait...\n";
	double percent_comp = 0.0;
	int points = (int)this->nuc_fractionation.size();
	int current_point = 0;
	for (kt=this->nuc_fractionation.begin(); kt!=nuc_fractionation.end(); ++kt)
	{
		percent_comp = (double)current_point / (double)points;
			
		if (this->initial_frac.isConsoleOut() == true)
			std::cout << "\t[" << (int)(percent_comp*100.0) << " %]\n";
	
		kt->second.calculateFractionation((stab_time-solid_time));
		current_point++;
	}
	if (this->initial_frac.isConsoleOut() == true)
		std::cout << "\t[100 %]\n\n";
	
	//Print out final result (at stabilization time)
	if (file_out == true)
	{
		fprintf(file, "Stabilization Time (s) =\t%.6g\n",stab_time);
		for (int i=0; i<this->initial_frac.getNumberNuclides(); i++)
		{
			if (i==0)
				fprintf(file, "\tUnstable");
			else
				fprintf(file, "\t***");
		}
		for (int i=0; i<this->initial_frac.getNumberStableNuclides(); i++)
		{
			if (i==0)
				fprintf(file, "\tStable");
			else
				fprintf(file, "\t###");
		}
		fprintf(file, "\n");
		fprintf(file, "Size (um)");
		for (int i=0; i<this->initial_frac.getNumberNuclides(); i++)
			fprintf(file, "\t%s", this->initial_frac.getIsotope(i).IsotopeName().c_str());
		for (int i=0; i<this->initial_frac.getNumberStableNuclides(); i++)
			fprintf(file, "\t%s", this->initial_frac.getStableIsotope(i).IsotopeName().c_str());
		fprintf(file, "\n");
		for (kt=this->nuc_fractionation.begin(); kt!=nuc_fractionation.end(); ++kt)
		{
			fprintf(file, "%.6g", kt->first);
			for (int i=0; i<kt->second.getNumberNuclides(); i++)
				fprintf(file, "\t%.6g", kt->second.getIsotope(i).getConcentration());
			for (int i=0; i<kt->second.getNumberStableNuclides(); i++)
				fprintf(file, "\t%.6g", kt->second.getStableIsotope(i).getConcentration());
			fprintf(file, "\n");
		}
	}
	
	//Close the open file
	if (file != nullptr)
		fclose(file);
}

/*
 *	-------------------------------------------------------------------------------------
 *								End: ActivityDistribution Class Definitions
 */

int KEA_TESTS()
{
	int success = 0;
	double time;
	
	std::cout << "\nTesting of the KEA module for the individual functions\n";
	std::cout <<   "------------------------------------------------------\n\n";
	
	ActivityDistribution test;
	Crane cranetest;
	FissionProducts yeildtest;
	Dove dove;
	yaml_cpp_class nuc_data;
	yaml_cpp_class yeild_data;
	std::string path = "database/";
	time = clock();
	
	/// ----------------- Initialize FAIRY for the Weapon Components ----------------------------------
	std::string file1 = path + "NuclideLibrary.yml";
	std::string file2 = path + "NeutronFissionProductYields.yml";
	nuc_data.executeYamlRead(file1.c_str());
	yeild_data.executeYamlRead(file2.c_str());
	yeildtest.loadNuclides(nuc_data);
	
	yeildtest.setConsoleOut(true);
	yeildtest.setTotalMass(50.0);
	yeildtest.setFissionExtent(3.0);
	yeildtest.setFissionType(explosion);
	yeildtest.setEnergyLevel(1000.0);
	yeildtest.timeSinceDetonation(3.0, 99.0); //Set yeild to 3 sec cutoff based on 99% conversion to daughters
	yeildtest.addIsotopeMaterial("U-235", 90.0);
	yeildtest.addIsotopeMaterial("U-238", 10.0);
	yeildtest.setTimeUnits(seconds);
	
	/// ----------------- END Initialize FAIRY for the Weapon Components ----------------------------------
	
	FILE *file, *cloud;
	file = fopen("output/KEA_CRANE_Tests.txt", "w+");
	cloud = fopen("output/KEA_CRANE_CloudGrowth.txt", "w+");
	if (file == nullptr)
	{
		system("mkdir output");
		file = fopen("output/KEA_CRANE_Tests.txt", "w+");
	}
	if (cloud == nullptr)
	{
		system("mkdir output");
		cloud = fopen("output/KEA_CRANE_CloudGrowth.txt", "w+");
	}
	cranetest.set_CloudFile(cloud);
	
	//Weapon casing is typically steel with a lead or lead-bismuth alloy lining
	test.add_casing_component("Fe10C", 0.9);
	test.add_casing_component("PbBi", 0.1);
	test.verify_casing_components();
	
	//Determine number of neutrons emitted per fission
	test.set_fission_yield(25.0);
	test.set_fusion_yield(25.0);
	test.set_total_yield(test.get_fission_yield()+test.get_fusion_yield());
	test.compute_neutrons_emit(test.get_fission_yield(), test.get_fusion_yield());
	
	/// ----------------- Initialize CRANE for the Soil Components ----------------------------------
	
	//V. Jodoin Test Case from 1994 Thesis
	double W = 50.0; //50 kT
	double hb = 0.0;// 0 m
	double gz = 500.0; //500 m
	
	int bins = 10;
	bool includeShear = true;
	bool isTight = true;
	
	cranetest.add_soil_component("SiO2", 0.75);
	cranetest.add_soil_component("CaO", 0.25);
	cranetest.establish_initial_conditions(dove, W, gz, hb, bins, includeShear, isTight);
	
	std::cout << "Shear Velocity          = \t";
	if (includeShear == true)
	std::cout << "True\n";
	else
	std::cout << "False\n";
	std::cout << "Bomb Yield (kT)         =\t" << W << std::endl;
	std::cout << "Burst Height (m)        =\t" << hb << std::endl;
	std::cout << "Ground Altitude (m)     =\t" << gz << std::endl;
	std::cout << "Initial Time (s)        =\t" << cranetest.get_current_time() << std::endl;
	std::cout << "Number of air parcels   =\t" << cranetest.return_parcel_alt_top().rows() << std::endl;
	std::cout << "Number of particle bins =\t" << cranetest.return_parcel_alt_top().columns() << std::endl;
	cranetest.display_part_hist();
	std::cout << "Soil Solid. Temp. (K)   =\t" << cranetest.get_solidification_temp() << std::endl;
	std::cout << "Soil Vapor. Temp. (K)   =\t" << cranetest.get_vaporization_temp() << std::endl;
	std::cout << "Vaporized Soil (kg)     =\t" << cranetest.get_initial_soil_vapor() << std::endl;
	cranetest.display_soil_characteristics();
	std::cout << "\n";
	
	bool fileout = true;
	bool consoleout = false;
	double tol = 0.1;
	double dtmin = 1e-8;
	double dtmax = 0.1; //ABS MAX!!! Beyond this point the numerical errors become too large...
	double dtmin_conv = 0.0001;
	double t_out = 1.0;
	double endtime = 1000.0;
	
	cranetest.establish_dove_options(dove, file, fileout, consoleout, BDF2, ADAPTIVE, SGS, tol, dtmin, dtmax, dtmin_conv, t_out, endtime);
	
	bool isLinear = false;
	bool isPrecon = false;
	bool nl_out = true;
	bool l_out = false;
	int max_nlit = 50;
	int max_lit = 200;
	int restart = 20;
	int recursive = 2;
	double nl_abstol = 1e-6;
	double nl_reltol = 1e-6;
	double l_abstol = 1e-6;
	double l_reltol = 1e-4;
	
	cranetest.establish_pjfnk_options(dove, QR, BT, isLinear, isPrecon, nl_out, l_out, max_nlit, max_lit, restart, recursive, nl_abstol, nl_reltol, l_abstol, l_reltol);
	
	std::cout << "\nInitial Conditions for Non-linear Variables\n";
	std::cout <<   "-------------------------------------------\n\n";
	cranetest.estimate_parameters(dove);
	for (int i=0; i<8; i++)
	{
		std::cout << dove.getVariableName(i) << " =\t " << dove.getNewU(i, dove.getNewU()) << std::endl;
	}
	cranetest.display_part_conc();
	
	success = cranetest.run_crane_simulation(dove);
	if (success != 0) {mError(simulation_fail); return -1;}
	
	std::cout << "\nFinal Results for Non-linear Variables\n";
	std::cout <<   "---------------------------------------\n\n";
	for (int i=0; i<8; i++)
	{
		std::cout << dove.getVariableName(i) << " =\t " << dove.getNewU(i, dove.getNewU()) << std::endl;
	}
	cranetest.display_part_conc();
	
	std::cout << "\nSaturation Time (s)     =\t";
	if (cranetest.get_saturation_time() > 0.0)
		std::cout << cranetest.get_saturation_time() << std::endl;
	else
		std::cout << "Unsaturated\n";
	std::cout << "Solidification Time (s) =\t";
	if (cranetest.get_saturation_time() > 0.0)
		std::cout << cranetest.get_solidification_time() << std::endl;
	else
		std::cout << "Unsolidified\n";
	std::cout << "Stabilization Time (s) =\t" << cranetest.get_stabilization_time() << std::endl;
	
	/// ----------------- END Initialize CRANE for the Soil Components ----------------------------------
	
	//Setup all neutron captures
	test.compute_casing_capfrac();
	test.compute_soil_capfrac(cranetest.get_soil_atom_frac(), cranetest.get_soil_atom());
	test.compute_weapon_capfrac(yeildtest);
	
	//Compute all capture fractions
	test.compute_escape_fraction();
	test.compute_volatile_fraction(cranetest.get_burst_height(), cranetest.get_bomb_yield());
	test.compute_soil_capture_fraction(cranetest.get_soil_atom_frac(), cranetest.get_soil_atom());
	
	//Now we need to incorporate neutron captures into initial fission products
	test.initialize_fractionation(yeildtest, yeild_data);
	success = test.evaluate_initial_fractionation();
	if (success != 0) {mError(simulation_fail); return -1;}
	
	//Simulate fractionations
	test.set_model_type(mod_freiling_tompkins);
	test.evaluate_freiling_ratios(cranetest.get_solidification_time(), cranetest.get_solidification_temp());
	test.evalute_distribution(cranetest.get_part_conc(), cranetest.get_part_hist());
	test.distribute_nuclides(cranetest.get_part_hist());
	test.evaluate_fractionation("output/KEA_Nuclides.txt", true, cranetest.get_solidification_time(), cranetest.get_stabilization_time());
	
	if (file!= nullptr)
		fclose(file);
	if (cloud!=nullptr)
		fclose(cloud);
	
	time = clock() - time;
	std::cout << "\nTest Runtime: " << (time / CLOCKS_PER_SEC) << " seconds\n";
	
	return success;
}
