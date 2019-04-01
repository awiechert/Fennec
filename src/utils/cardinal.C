/*!
 *  \file cardinal.h cardinal.cpp
 *	\brief Cloud-rise And Radioactivity Distribution Invoked from Nuclear Arms Launch
 *  \author Austin Ladshaw
 *	\date 02/22/2019
 *	\copyright This software was designed and built at the Georgia Institute
 *             of Technology by Austin Ladshaw for research in the area
 *             of radioactive particle decay and transport. Copyright (c) 2018,
 *			   all rights reserved.
 */

#include "cardinal.h"

/*
 *								Start: Cardinal Class Definitions
 *	-------------------------------------------------------------------------------------
 */

Cardinal::Cardinal()
{
	ConsoleOut = false;
}

Cardinal::~Cardinal()
{
	
}

void Cardinal::setConsoleOut(bool val)
{
	this->ConsoleOut = val;
	this->yields.setConsoleOut(val);
}

bool Cardinal::isConsoleOut()
{
	return this->ConsoleOut;
}

Crane & Cardinal::getCloudRise()
{
	return this->cloudrise;
}

ActivityDistribution & Cardinal::getActivity()
{
	return this->activity;
}

int Cardinal::readInputFile(const char *input)
{
	return this->input_file.executeYamlRead(input);
}

int Cardinal::readAtomsphereFile(const char *input)
{
	return this->cloudrise.read_atmosphere_profile(input);
}

int Cardinal::setupCloudRiseSimulation(FILE *outfile)
{
	int success = 0;
	
	//Read in Simulation_Options
	success = this->cloudrise.read_conditions(dove, this->input_file);
	if (success != 0) {mError(read_error); return -1;}
	this->setConsoleOut(this->cloudrise.get_ConsoleOut());
	
	if (this->isConsoleOut() == true)
	{
		std::cout << "\nCARDINAL SIMULATION CONDITIONS\n";
		std::cout <<   "------------------------------\n\n";
		std::cout << "Shear Velocity          = \t";
		if (this->cloudrise.get_includeShearVel() == true)
			std::cout << "True\n";
		else
			std::cout << "False\n";
		std::cout << "Bomb Yield (kT)         =\t" << this->cloudrise.get_bomb_yield() << std::endl;
		std::cout << "Burst Height (m)        =\t" << this->cloudrise.get_burst_height() << std::endl;
		std::cout << "Ground Altitude (m)     =\t" << this->cloudrise.get_ground_alt() << std::endl;
		std::cout << "Initial Time (s)        =\t" << this->cloudrise.get_current_time() << std::endl;
		std::cout << "Number of air parcels   =\t" << this->cloudrise.return_parcel_alt_top().rows() << std::endl;
		std::cout << "Number of particle bins = \t" << this->cloudrise.return_parcel_alt_top().columns() << std::endl;
		this->cloudrise.display_part_hist();
		std::cout << "Soil Solid. Temp. (K)   =\t" << this->cloudrise.get_solidification_temp() << std::endl;
		std::cout << "Soil Vapor. Temp. (K)   =\t" << this->cloudrise.get_vaporization_temp() << std::endl;
		std::cout << "Vaporized Soil (kg)     =\t" << this->cloudrise.get_initial_soil_vapor() << std::endl;
		this->cloudrise.display_soil_characteristics();
		std::cout << "\n";
	}
	
	//Read in ODE_Options
	success = this->cloudrise.read_dove_options(this->dove, outfile, this->input_file);
	if (success != 0) {mError(read_error); return -1;}
	
	//Read in Solver_Options
	success = this->cloudrise.read_pjfnk_options(this->dove, this->input_file);
	if (success != 0) {mError(read_error); return -1;}
	
	//Read in Wind_Profile
	success = this->cloudrise.read_wind_profile(this->input_file);
	if (success != 0) {mError(read_error); return -1;}
	
	//Run simulation case
	this->cloudrise.estimate_parameters(this->dove);
	if (this->isConsoleOut() == true)
	{
		std::cout << "\nInitial Conditions for Non-linear Variables\n";
		std::cout <<   "-------------------------------------------\n\n";
		for (int i=0; i<8; i++)
		{
			std::cout << dove.getVariableName(i) << " =\t " << dove.getNewU(i, this->dove.getNewU()) << std::endl;
		}
	}
	
	return success;
}

int Cardinal::readDatabaseFiles(const char *path)
{
	int success = 0;
	std::string s_path = path;
	std::string nuc = s_path + "NuclideLibrary.yml";
	std::string fpy = s_path + "NeutronFissionProductYields.yml";
	
	success = this->nuc_data.executeYamlRead(nuc.c_str());
	if (success != 0) {mError(read_error); return -1;}
	
	success = this->yield_data.executeYamlRead(fpy.c_str());
	if (success != 0) {mError(read_error); return -1;}
	
	this->yields.loadNuclides(this->nuc_data);
	
	return success;
}

int Cardinal::setupActivityDistribution()
{
	int success = 0;
	
	this->yields.setConsoleOut(this->ConsoleOut);
	this->yields.setFissionType(explosion);
	this->yields.setTimeUnits(seconds);
	try
	{
		this->yields.setTotalMass( this->input_file.getYamlWrapper()("Weapon_Info")["total_mass"].getDouble() );
	}
	catch (std::out_of_range)
	{
		mError(missing_information);
		return -1;
	}
	try
	{
		this->yields.setFissionExtent( this->input_file.getYamlWrapper()("Weapon_Info")["fission_extent"].getDouble() );
	}
	catch (std::out_of_range)
	{
		mError(missing_information);
		return -1;
	}
	double cutoff = 99.0;
	try
	{
		cutoff = this->input_file.getYamlWrapper()("Weapon_Info")["yield_cutoff"].getDouble();
	}
	catch (std::out_of_range)
	{
		cutoff = 99.0;
	}
	if (cutoff >= 100.0) cutoff = 99.0;
	this->yields.timeSinceDetonation(this->cloudrise.get_current_time(), cutoff);
	double fission = this->cloudrise.get_bomb_yield();
	try
	{
		fission = this->input_file.getYamlWrapper()("Weapon_Info")["fission_yield"].getDouble();
		if (fission >= this->cloudrise.get_bomb_yield()) fission = this->cloudrise.get_bomb_yield();
	}
	catch (std::out_of_range)
	{
		fission = this->cloudrise.get_bomb_yield();
	}
	this->activity.set_fission_yield(fission);
	this->activity.set_fusion_yield(this->cloudrise.get_bomb_yield()-fission);
	this->activity.set_total_yield(this->activity.get_fission_yield()+this->activity.get_fusion_yield());
	this->activity.compute_neutrons_emit(this->activity.get_fission_yield(), this->activity.get_fusion_yield());
	double thickness = 0.0;
	try
	{
		thickness = this->input_file.getYamlWrapper()("Weapon_Info")["casing_thickness"].getDouble();
	}
	catch (std::out_of_range)
	{
		thickness = 0.0;
	}
	if (thickness < 0.0) thickness = 0.0;
	this->activity.set_casing_thickness(thickness);
	try
	{
		std::string choice = this->input_file.getYamlWrapper()("Weapon_Info")["fractionation_model"].getString();
		this->activity.set_model_type( activitymodel_choice(choice) );
	}
	catch (std::out_of_range)
	{
		this->activity.set_model_type(freiling);
	}
	
	//Loop to setup weapon isotopes
	try
	{
		for (auto &x: this->input_file.getYamlWrapper()("Weapon_Info")("fissionable_isotopes").getDataMap())
		{
			this->yields.addIsotopeMaterial(x.first, x.second.getDouble());
		}
	}
	catch (std::out_of_range)
	{
		this->yields.addIsotopeMaterial("U-235", 100);
	}
	
	//Loop to setup casing materials
	try
	{
		for (auto &x: this->input_file.getYamlWrapper()("Weapon_Info")("casing_components").getDataMap())
		{
			this->activity.add_casing_component(x.first, x.second.getDouble());
		}
	}
	catch (std::out_of_range)
	{
		this->activity.add_casing_component("Fe10C", 1.0);
	}
	this->activity.verify_casing_components();
	
	//Setup all neutron captures
	this->activity.compute_casing_capfrac();
	this->activity.compute_soil_capfrac(this->cloudrise.get_soil_atom_frac(), this->cloudrise.get_soil_atom());
	this->activity.compute_weapon_capfrac(this->yields);
	
	//Compute all capture fractions
	this->activity.compute_escape_fraction();
	this->activity.compute_volatile_fraction(this->cloudrise.get_burst_height(), this->cloudrise.get_bomb_yield());
	this->activity.compute_soil_capture_fraction(this->cloudrise.get_soil_atom_frac(), this->cloudrise.get_soil_atom());
	
	return success;
}

int Cardinal::runSimulations()
{
	int success = 0;
	
	success = this->cloudrise.run_crane_simulation(this->dove);
	if (success != 0) {mError(simulation_fail); return -1;}
	
	if (this->isConsoleOut() == true)
	{
		std::cout << "\nFinal Results for Non-linear Variables\n";
		std::cout <<   "---------------------------------------\n\n";
		for (int i=0; i<8; i++)
		{
			std::cout << this->dove.getVariableName(i) << " =\t " << this->dove.getNewU(i, this->dove.getNewU()) << std::endl;
		}
	
		std::cout << "\nSolidification Time (s) =\t";
		if (this->cloudrise.get_saturation_time() > 0.0)
			std::cout << this->cloudrise.get_solidification_time() << std::endl;
		else
			std::cout << "Unsolidified\n";
		std::cout << "Saturation Time (s)     =\t";
		if (this->cloudrise.get_saturation_time() > 0.0)
			std::cout << this->cloudrise.get_saturation_time() << std::endl;
		else
			std::cout << "Unsaturated\n";
		std::cout << "Stabilization Time (s) =\t" << this->cloudrise.get_stabilization_time() << std::endl;
	}
	
	//Now we need to incorporate neutron captures into initial fission products
	this->activity.initialize_fractionation(this->yields, this->yield_data);
	success = this->activity.evaluate_initial_fractionation();
	if (success != 0) {mError(simulation_fail); std::cout << "\nEigen Solution not tolerable...\n\n"; return -1;}
	
	//Simulate fractionation
	this->activity.evaluate_freiling_ratios(this->cloudrise.get_solidification_time(), this->cloudrise.get_solidification_temp());
	this->activity.evalute_distribution(this->cloudrise.get_part_conc(), this->cloudrise.get_part_hist());
	this->activity.distribute_nuclides(this->cloudrise.get_part_hist());
	this->activity.evaluate_fractionation("output/CARDINAL_Nuclides.txt", true, this->cloudrise.get_solidification_time(), this->cloudrise.get_stabilization_time());
	
	return success;
}

/*
 *	-------------------------------------------------------------------------------------
 *								End: Cardinal Class Definitions
 */

int CARDINAL_SCENARIO(const char *yaml_input, const char *atmosphere_data, const char *data_path)
{
	//Initializations
	int success = 0;
	double time;
	Cardinal cardinal;
	time = clock();
	
	//Opening output files (optional)
	FILE *file, *cloud;
	file = fopen("output/CARDINAL_CloudRise.txt", "w+");
	cloud = fopen("output/CARDINAL_CloudGrowth.txt", "w+");
	if (cardinal.getCloudRise().get_FileOut() == true)
	{
		if (file == nullptr)
		{
			system("mkdir output");
			file = fopen("output/CARDINAL_CloudRise.txt", "w+");
		}
		if (cloud == nullptr)
		{
			system("mkdir output");
			cloud = fopen("output/CARDINAL_CloudGrowth.txt", "w+");
		}
	}
	cardinal.getCloudRise().set_CloudFile(cloud);
	
	//Read and setup CRANE associated files
	success = cardinal.readInputFile(yaml_input);
	if (success != 0) {mError(read_error); return -1;}
	
	success = cardinal.readAtomsphereFile(atmosphere_data);
	if (success != 0) {mError(read_error); return -1;}
	
	success = cardinal.setupCloudRiseSimulation(file);
	if (success != 0) {mError(read_error); return -1;}
	
	//Read and setup KEA associated files
	success = cardinal.readDatabaseFiles(data_path);
	if (success != 0) {mError(read_error); return -1;}
	
	success = cardinal.setupActivityDistribution();
	if (success != 0) {mError(read_error); return -1;}
	
	success = cardinal.runSimulations();
	if (success != 0) {mError(simulation_fail); return -1;}
	
	//Determine total runtime
	time = clock() - time;
	std::cout << "\nCARDINAL Runtime: " << (time / CLOCKS_PER_SEC) << " seconds\n";
	
	//Close the open files
	if (file!= nullptr)
		fclose(file);
	if (cloud!=nullptr)
		fclose(cloud);
	
	return success;
}
