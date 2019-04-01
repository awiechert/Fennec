/*!
 *  \file cardinal.h cardinal.cpp
 *	\brief Cloud-rise And Radioactivity Distribution Invoked from Nuclear Arms Launch
 *	\details This file contains a C++ object for coupling cloud rise simulations and
 *			activity-size distributions. It will link together libraries for nuclide
 *			half-lifes and decay modes with libraries for fission product yields from
 *			different nuclear materials. User must provide the common path to both
 *			the nuclide data and fission product data. User must also provide input
 *			files to control the cloud rise simulation and provide atomspheric data.
 *
 *  \author Austin Ladshaw
 *	\date 02/22/2019
 *	\copyright This software was designed and built at the Georgia Institute
 *             of Technology by Austin Ladshaw for research in the area
 *             of radioactive particle decay and transport. Copyright (c) 2018,
 *			   all rights reserved.
 */

#ifndef CARDINAL_HPP_
#define CARDINAL_HPP_

#include "kea.h"
#include "crane.h"

/// C++ object for coupling cloud rise and activity distribution
/** Object will contain all data and function associated with running the cloud rise and
	activity-size distribution simulations coupled together. User is required to provide
	three inputs to run the CARDINAL_SCENARIO: (i) Input Control File, (ii) Atomspheric
	Data file, and (iii) Common Path to Static Database files. All of this information
	is necessary in order to fully run and couple simulations together. */
class Cardinal
{
public:
	Cardinal();											///< Default constructor
	~Cardinal();										///< Default destructor
	
	void setConsoleOut(bool val);						///< Function to set the console output parameter
	
	bool isConsoleOut();								///< Returns the ConsoleOut parameter
	
	Crane &getCloudRise();								///< Return reference to the cloud rise simulation data
	ActivityDistribution &getActivity();				///< Return reference to the activity distribution data
	
	int readInputFile(const char *input);				///< Read the yaml input file
	int readAtomsphereFile(const char *input);			///< Read the atomspheric data file
	int setupCloudRiseSimulation(FILE *outfile);		///< Setup the cloud rise simulations (post-read)
	int readDatabaseFiles(const char *path);			///< Read the Nuclides and Fission Yields from the given path
	int setupActivityDistribution();					///< Setup the activity distribution simulations (post-read)
	
	int runSimulations();								///< Run all the simulations
	
protected:

private:
	ActivityDistribution activity;						///< Object for the activity-size distributions
	Crane cloudrise;									///< Object for the cloud rise simulations
	FissionProducts yields;								///< Object for the fission product yields
	Dove dove;											///< Object for the ODE solver
	yaml_cpp_class nuc_data;							///< Object for the nuclide data
	yaml_cpp_class yield_data;							///< Object for the yield data
	yaml_cpp_class input_file;							///< Object for the input file
	bool ConsoleOut;									///< Boolean used to determine whether or not to print info to the console
};

int CARDINAL_SCENARIO(const char *yaml_input, const char *atmosphere_data, const char *data_path);

#endif /* CARDINAL_HPP_ */
