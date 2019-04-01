/*!
 *  \file fairy.h fairy.cpp
 *	\brief Fission-products from Atomic Incident and their Respective Yields
 *  \author Austin Ladshaw
 *	\date 12/07/2018
 *	\copyright This software was designed and built at the Georgia Institute
 *             of Technology by Austin Ladshaw for research in the area
 *             of radioactive particle decay and transport. Copyright (c) 2018,
 *				all rights reserved.
 */

#include "fairy.h"

//Pick fission type
fiss_type fisstype_choice(std::string &choice)
{
	fiss_type type = neutron;
	
	std::string copy = choice;
	for (int i=0; i<copy.size(); i++)
		copy[i] = tolower(copy[i]);
	
	if (copy == "neutron" || copy == "neutron-induced")
		type = neutron;
	else if (copy == "spontaneous")
		type = spontaneous;
	else if (copy == "explosion" || copy == "bomb" || copy == "blast")
		type = explosion;
	else
		type = neutron;
	
	return type;
}


/*
 *								Start: FissionProducts Class Definitions
 *	-------------------------------------------------------------------------------------
 */

//Default constructor
FissionProducts::FissionProducts()
{
	type = explosion;
	total_mass = 1.0;
	fiss_extent = 50.0;
	energy_level = 0.0;
}

//Default destructor
FissionProducts::~FissionProducts()
{
	InitialMat.clear();
	MatFrac.clear();
	Yields.clear();
}

//Display information
void FissionProducts::DisplayInfo()
{
	std::cout << "Type of Fission Event:\t";
	switch (this->type)
	{
		case neutron:
			std::cout << "Neutron-Induced\n";
			break;
			
		case spontaneous:
			std::cout << "Spontaneous\n";
			break;
			
		case explosion:
			std::cout << "Explosion\n";
			break;
			
		default:
			std::cout << "Neutron-Induced\n";
			break;
	}
	std::cout << "Neutron Source Energy (eV) =\t" << this->energy_level << std::endl;
	std::cout << "Extent of Fission (%)  =\t" << this->fiss_extent << std::endl;
	std::cout << "Mass of Materials (kg) = \t" << this->total_mass << std::endl;
	std::cout << "\tMaterial\tPercentage\n";
	std::cout << "\t--------\t----------\n";
	for (int i=0; i<this->InitialMat.size(); i++)
	{
		std::cout << "\t" << this->InitialMat[i].IsotopeName() << "\t\t" << this->MatFrac[i] << std::endl;
	}
}

//Display map
void FissionProducts::DisplayMap()
{
	this->DecayChain::DisplayMap();
}

//Load library
void FissionProducts::loadNuclides(yaml_cpp_class &data)
{
	this->DecayChain::loadNuclides(data);
}

//Unload library
void FissionProducts::unloadNuclides()
{
	this->DecayChain::unloadNuclides();
}

//Register initial nuclide
int FissionProducts::registerInitialNuclide(std::string isotope_name)
{
	return this->DecayChain::registerInitialNuclide(isotope_name);
}

//Register initial nuclide
int FissionProducts::registerInitialNuclide(std::string symb, int iso)
{
	return this->DecayChain::registerInitialNuclide(symb, iso);
}

//Register initial nuclide
int FissionProducts::registerInitialNuclide(int atom_num, int iso_num)
{
	return this->DecayChain::registerInitialNuclide(atom_num, iso_num);
}

//Register initial nuclide
int FissionProducts::registerInitialNuclide(std::string isotope_name, double ic)
{
	return this->DecayChain::registerInitialNuclide(isotope_name,ic);
}

//Register initial nuclide
int FissionProducts::registerInitialNuclide(std::string symb, int iso, double ic)
{
	return this->DecayChain::registerInitialNuclide(symb, iso, ic);
}

//Register initial nuclide
int FissionProducts::registerInitialNuclide(int atom_num, int iso_num, double ic)
{
	return this->DecayChain::registerInitialNuclide(atom_num, iso_num, ic);
}

//Load FPY library
std::string FissionProducts::fileFissionProductYields()
{
	std::string file;
	switch (this->type)
	{
		case neutron:
			file = "NeutronFissionProductYields.yml";
			break;
			
		case spontaneous:
			file = "SpontaneousFissionProductYields.yml";
			break;
			
		case explosion:
			file = "NeutronFissionProductYields.yml";
			break;
			
		default:
			file = "NeutronFissionProductYields.yml";
			break;
	}
	return file;
}

//Load FPY library
void FissionProducts::loadFissionProductYields(yaml_cpp_class & data)
{
	this->fpy_data = &data;
}

//Unload FPY library
void FissionProducts::unloadFissionProductYields()
{
	this->fpy_data->DeleteContents();
}

//Set type
void FissionProducts::setFissionType(fiss_type opt)
{
	this->type = opt;
}

//Set mass
void FissionProducts::setTotalMass(double mass)
{
	if (mass <= 0.0)
		mass = 1.0;
	this->total_mass = mass;
}

//Set fission extent
void FissionProducts::setFissionExtent(double per)
{
	if (per > 100.)
		per = 100;
	if (per <= 0.0)
		per = 0.0;
	this->fiss_extent = per;
}

//Set energy
void FissionProducts::setEnergyLevel(double el)
{
	if (el < 0.0)
		el = 0.0;
	this->energy_level = el;
}

//set threshold
void FissionProducts::setThreshold(double val)
{
	if (val < 0.0)
		val = 0.0;
	this->DecayChain::setThreshold(val);
}

//set threshold from time of detonation
void FissionProducts::timeSinceDetonation(double time, double per)
{
	if (time < 0.0)
		time = 0.0;
	per = per/100.0;
	if (per < 0.0)
		per = 0.0;
	if (per >= 1.0)
		per = 0.99;
	this->setThreshold(time*log(0.5)/log(1-per));
}

//set time units
void FissionProducts::setTimeUnits(time_units units)
{
	this->t_units = units;
}

//set end time
void FissionProducts::setEndTime(double end)
{
	if (end < 0.0)
		end = 0;
	this->end_time = end;
}

//set time steps
void FissionProducts::setTimeSteps(int steps)
{
	if (steps < 0)
		steps = 0;
	this->time_steps = steps;
}

//set verify
void FissionProducts::setVerifySoln(bool opt)
{
	this->VerifyEigen = opt;
}

//set sparsity
void FissionProducts::setPrintSparsity(bool opt)
{
	this->PrintSparsity = opt;
}

//set chain
void FissionProducts::setPrintChain(bool opt)
{
	this->PrintChain = opt;
}

//set results
void FissionProducts::setPrintResults(bool opt)
{
	this->PrintResults = opt;
}

//set console out
void FissionProducts::setConsoleOut(bool opt)
{
	this->ConsoleOut = opt;
}

//return total moles
double FissionProducts::getTotalMoles()
{
    return this->total_moles;
}

//return extent
double FissionProducts::getFissionExtent()
{
    return this->fiss_extent;
}

//return console bool
bool FissionProducts::isConsoleOut()
{
	return this->ConsoleOut;
}

//return isotopes
std::vector<Isotope> & FissionProducts::getWeaponMat()
{
	return this->InitialMat;
}

//return isotope molefractions
std::vector<double> & FissionProducts::getWeaponFrac()
{
	return this->MatFrac;
}

//run simulation
int FissionProducts::run_simulation(std::string file_name)
{
	int success = 0;
	success = this->DecayChain::run_simulation(file_name);
	success = this->print_yields();
	return success;
}

//print yields
int FissionProducts::print_yields()
{
	int success = 0;
	
	//Open a file to print results to
	FILE *file;
	file = fopen("output/FAIRY_Yields.txt", "w+");
	if (file == nullptr)
	{
		system("mkdir output");
		file = fopen("output/FAIRY_Yields.txt", "w+");
	}
	
	//Loop through yield map and print data
	fprintf(file, "Mass Number\tYield (%%)\n");
	for (std::map<int,double>::iterator it=this->Yields.begin(); it!=this->Yields.end(); it++)
	{
		fprintf(file, "%i\t%.6g\n", it->first, it->second);
	}
	
	//Close the open file
	if (file != nullptr)
		fclose(file);
	
	return success;
}

//Add isotope
void FissionProducts::addIsotopeMaterial(std::string iso, double percent)
{
	Isotope temp;
	temp.loadNuclides(*this->nuclides);
	temp.registerIsotope(iso);
	this->InitialMat.push_back(temp);
	if (percent > 100.)
		percent = 100;
	if (percent <= 0.0)
		percent = 0.0;
	this->MatFrac.push_back(percent);
}

//Add isotope
void FissionProducts::addIsotopeMaterial(std::string sym, int iso_num, double percent)
{
	Isotope temp;
	temp.loadNuclides(*this->nuclides);
	temp.registerIsotope(sym, iso_num);
	this->InitialMat.push_back(temp);
	if (percent > 100.)
		percent = 100;
	if (percent <= 0.0)
		percent = 0.0;
	this->MatFrac.push_back(percent);
}

//Add isotope
void FissionProducts::addIsotopeMaterial(int atom_num, int iso_num, double percent)
{
	Isotope temp;
	temp.loadNuclides(*this->nuclides);
	temp.registerIsotope(atom_num, iso_num);
	this->InitialMat.push_back(temp);
	if (percent > 100.)
		percent = 100;
	if (percent <= 0.0)
		percent = 0.0;
	this->MatFrac.push_back(percent);
}

//Check mass error
void FissionProducts::checkFractions()
{
	double sum = 0.0;
	for (int i=0; i<this->MatFrac.size(); i++)
	{
		sum += this->MatFrac[i];
	}
	if (sum <= 0.0) {mError(invalid_molefraction); return;}
	if (sum-100.0 > 0.0)
	{
		double correction = 100.0/sum;
		for (int i=0; i<this->MatFrac.size(); i++)
		{
			this->MatFrac[i] = this->MatFrac[i]*correction;
		}
	}
}

//Evaluate the yields from data
int FissionProducts::evaluateYields()
{
	int success = 0;
	this->checkFractions();
	if (this->type == explosion)
	{
		std::string high_key;
        this->total_moles = 0.0;
		for (int i=0; i<this->InitialMat.size(); i++)
		{
			//Calculate moles of isotope and find header
			double moles;
			moles = this->total_mass*this->MatFrac[i]/100.0*1000.0/this->InitialMat[i].AtomicWeight();
            this->total_moles += moles;
			int levels = 0;
			try
			{
				levels = (int)this->fpy_data->getYamlWrapper()(this->InitialMat[i].IsotopeName()).getHeadMap().size();
			}
			catch (std::out_of_range)
			{
				mError(key_not_found);
				std::cout << this->InitialMat[i].IsotopeName() << " does not exist in yield data...\n\n";
				return -1;
			}
			
			//Loop through energy levels to find high key value
			double high = 0.0;
			for (auto &x: this->fpy_data->getYamlWrapper()(this->InitialMat[i].IsotopeName()).getHeadMap())
			{
				try
				{
					double energy = x.second["Energy"].getDouble();
					if (energy >= high)
					{
						high = energy;
						high_key = x.first;
					}
				}
				catch (std::out_of_range)
				{
					mError(key_not_found);
					std::cout << "Energy key does not exist in yield data...\n\n";
					return -1;
				}
			}
			
			//Read in yields for all isotopes from high_key
			try
			{
				levels = (int)this->fpy_data->getYamlWrapper()(this->InitialMat[i].IsotopeName())(high_key).getSubMap().size();
			}
			catch (std::out_of_range)
			{
				mError(key_not_found);
				std::cout << "Error in determining the High_Key value...\n\n";
				return -1;
			}
			
			//Loop through all isotopes produced in fission
			double yield = 0.0;
			double sum = 0.0;
			for (auto &x: this->fpy_data->getYamlWrapper()(this->InitialMat[i].IsotopeName())(high_key).getSubMap())
			{
				try
				{
					yield = x.second["Yield"].getDouble();
					if (moles > 0.0)
					{
						success = this->registerInitialNuclide(x.first, yield*moles*this->fiss_extent/100.0);
						if (success != 0)
						{
							success = 0;
							sum += yield;
						}
						else
						{
							char *str;
							char iso[256];
							strcpy(iso, x.first.c_str());
							str = strtok(iso, "-");
							std::string sym;
							int iso_num;
						
							int a=0;
							while (str != NULL)
							{
								if (a == 0)
									sym = str;
								if (a == 1)
									iso_num = atoi(str);
								str = strtok(NULL, "-");
								a++;
							}
						
							std::map<int, double>::iterator it;
							it = this->Yields.find(iso_num);
							if (it != this->Yields.end())
								this->Yields[iso_num] = this->Yields[iso_num]+yield*this->MatFrac[i];
							else
								this->Yields[iso_num] = yield*this->MatFrac[i];
						}
					}
				}
				catch (std::out_of_range)
				{
					mError(key_not_found);
					std::cout << "Missing Yield key value pair...\n\n";
					return -1;
				}
			}
			if (this->fiss_extent < 100.0)
				if (moles > 0.0)
					success = this->registerInitialNuclide(this->InitialMat[i].IsotopeName(), moles*(100.0-this->fiss_extent)/100.0);
			if (sum >= 1e-6)
			{
				mError(invalid_molefraction);
				std::cout << "Sum of independent yields contains too much error...\n\n";
				return -1;
			}
		}
	}
	else
	{
		//Need to do linear interpolation for neutron energy sources
		mError(opt_no_support);
		std::cout << "Must choose type = explosion for now...\n\n";
		return -1;
	}
	return success;
}

void FissionProducts::evaluateEigenSolution()
{
	this->createChains();
	this->formEigenvectors();
	this->unloadFissionProductYields();
}

//verfiy eigenvectors and eigenvalues
int FissionProducts::verifyEigenSoln()
{
	return this->DecayChain::verifyEigenSoln();
}

//Calculate fractionation
void FissionProducts::calculateFractionation(double t)
{
	this->DecayChain::calculateFractionation(t);
}

//Calculate fractionation for given isotope
double FissionProducts::returnFractionation(std::string iso_name, double t)
{
	return this->DecayChain::returnFractionation(iso_name, t);
}

//Return num nuc
int FissionProducts::getNumberNuclides()
{
	return this->DecayChain::getNumberNuclides();
}

//Return num stable nuc
int FissionProducts::getNumberStableNuclides()
{
	return this->DecayChain::getNumberStableNuclides();
}

//Return unstable index
int FissionProducts::getIsotopeIndex(std::string iso_name)
{
	return this->DecayChain::getIsotopeIndex(iso_name);
}

//Return stable index
int FissionProducts::getStableIsotopeIndex(std::string iso_name)
{
	return this->DecayChain::getStableIsotopeIndex(iso_name);
}

//Return parents
std::vector<int>& FissionProducts::getParentList(int i)
{
	return this->DecayChain::getParentList(i);
}

//Return stable parents
std::vector<int>& FissionProducts::getStableParentList(int i)
{
	return this->DecayChain::getStableParentList(i);
}

//Return branches
std::vector<int>& FissionProducts::getBranchList(int i, int j)
{
	return this->DecayChain::getBranchList(i, j);
}

//Return stable branches
std::vector<int>& FissionProducts::getStableBranchList(int i, int j)
{
	return this->DecayChain::getStableBranchList(i, j);
}

//Return isotope
Isotope& FissionProducts::getIsotope(int i)
{
	return this->DecayChain::getIsotope(i);
}

//Return stable isotope
Isotope& FissionProducts::getStableIsotope(int i)
{
	return this->DecayChain::getStableIsotope(i);
}

//Return stable or unstable isotope
Isotope& FissionProducts::getIsotope(std::string iso_name)
{
	return this->DecayChain::getIsotope(iso_name);
}

/*
 *	-------------------------------------------------------------------------------------
 *								End: FissionProducts Class Definitions
 */

/// Test function for FAIRY
int FAIRY_TESTS()
{
	//Initializations
	int success = 0;
	double time;
	yaml_cpp_class nuc_data;
	yaml_cpp_class yield_data;
	std::string path = "database/";
	std::cout << "\nRunning FAIRY tests...\n";
	
	//Declarations
	time = clock();
	path = path + "NuclideLibrary.yml";
	nuc_data.executeYamlRead(path.c_str());
	FissionProducts test;
	test.loadNuclides(nuc_data);
	
	test.setTotalMass(50.0);
	test.setFissionExtent(3.0);
	test.setFissionType(explosion);
	test.setEnergyLevel(1000.0);
	test.timeSinceDetonation(3.0, 99.0); //Set yeild to 3 sec cutoff based on 99% conversion to daughters
	test.addIsotopeMaterial("U-235", 100.0);
	test.addIsotopeMaterial("U-238", 0.0);
	
	test.DisplayInfo();
	
	yield_data.executeYamlRead("database/NeutronFissionProductYields.yml");
	test.loadFissionProductYields(yield_data);
	test.evaluateYields();
	test.evaluateEigenSolution();
    std::cout << "Total Moles = " << test.getTotalMoles() << std::endl;
	
	//Run simulation after setting options
	test.setTimeUnits(hours);
	test.setEndTime(1.0);
	test.setTimeSteps(10);
	test.setPrintSparsity(false);
	test.setVerifySoln(true);
	test.setPrintChain(false);
	test.setPrintResults(true);
	test.setConsoleOut(true);
	
	test.run_simulation("output/FAIRY_Results.txt");
	
	time = clock() - time;
	std::cout << "\nRuntime: " << (time / CLOCKS_PER_SEC) << " seconds\n";
	
	return success;
}
