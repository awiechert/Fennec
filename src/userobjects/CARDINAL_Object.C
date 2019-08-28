/*!
 *  \file CARDINAL_Object.h
 *	\brief General User Object to contain all information and algorithms associated with CARDINAL
 *	\details This file creates a GeneralUserObject for CARDINAL objects and functions in MOOSE. The
 *			CARDINAL object is made public to allow any kernels using this General Object to call
 *			CARDINAL member functions and have access to CARDINAL data. The CARDINAL object will be used
 *			to establish initial conditions for FENNEC simulations by estimating the cloud rise
 *			following a nuclear explosion of a particular size.
 *
 *  \author Austin Ladshaw
 *	\date 07/19/2018
 *	\copyright This kernel was designed and built at the Georgia Institute
 *             of Technology by Austin Ladshaw for PhD research in the area
 *             of radioactive particle transport and settling following a
 *			   nuclear event. It was developed for the US DOD under DTRA
 *			   project No. 14-24-FRCWMD-BAA. Portions Copyright (c) 2018, all
 *             rights reserved.
 *
 *			   Austin Ladshaw does not claim any ownership or copyright to the
 *			   MOOSE framework in which these kernels are constructed, only
 *			   the kernels themselves. The MOOSE framework copyright is held
 *			   by the Battelle Energy Alliance, LLC (c) 2010, all rights reserved.
 */

/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "CARDINAL_Object.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", CARDINAL_Object);

template <>
InputParameters
validParams<CARDINAL_Object>()
{
	InputParameters params = validParams<GeneralUserObject>();
	params.addClassDescription("GeneralUserObject for CARDINAL member data and functions. CARDINAL is used to establish initial conditions for FENNEC simulations by estimating cloud rise, particle distributions, and establishing wind, temperature, pressure, and relative humidity profiles for the atmosphere.");
    params.addRequiredParam<std::string>("input_file", "Name and path (relative to the directory from which the fennec-opt executable is run) to the input file for the CARDINAL simulation");
    params.addRequiredParam<std::string>("atm_file","Name and path (relative to the directory from which the fennec-opt executable is run) to the atmospheric data file for CARDINAL");
    params.addRequiredParam<std::string>("data_path", "Path (relative to the directory from which the fennec-opt executable is run) to the database files needed for CARDINAL");
	return params;
}

CARDINAL_Object::CARDINAL_Object(const InputParameters & parameters) : GeneralUserObject(parameters),
_input_file(getParam<std::string>("input_file")),
_atm_file(getParam<std::string>("atm_file")),
_data_path(getParam<std::string>("data_path"))
{
    //Initializations
    int success = 0;
    double time;
    time = clock();
    
    //Opening output files (optional)
    FILE *file, *cloud;
    file = fopen("output/CARDINAL_CloudRise.txt", "w+");
    cloud = fopen("output/CARDINAL_CloudGrowth.txt", "w+");
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
    cardinal.getCloudRise().set_CloudFile(cloud);
    
    //Read and setup CRANE associated files
    success = cardinal.readInputFile(_input_file.c_str());
    if (success != 0) {mError(read_error); success = -1;}
    
    success = cardinal.readAtomsphereFile(_atm_file.c_str());
    if (success != 0) {mError(read_error); success = -1;}
    
    success = cardinal.setupCloudRiseSimulation(file);
    if (success != 0) {mError(read_error); success = -1;}
    
    //Read and setup KEA associated files
    success = cardinal.readDatabaseFiles(_data_path.c_str());
    if (success != 0) {mError(read_error); success = -1;}
    
    success = cardinal.setupActivityDistribution();
    if (success != 0) {mError(read_error); success = -1;}
    
    success = cardinal.runSimulations(0,"output/CARDINAL_Nuclides.txt");
    if (success != 0) {mError(simulation_fail); success = -1;}
    
    //Determine total runtime
    time = clock() - time;
    std::cout << "\nCARDINAL Runtime: " << (time / CLOCKS_PER_SEC) << " seconds\n";
    
    //Close the open files
    if (file!= nullptr)
        fclose(file);
    if (cloud!=nullptr)
        fclose(cloud);
    
    if (success != 0)
    	moose::internal::mooseErrorRaw("CARDINAL SIMULATION HAS FAILED!");
    
    _num_parcels = cardinal.getCloudRise().return_parcel_alt_top().rows();
    _num_size_bins = cardinal.getCloudRise().return_parcel_alt_top().columns();
    _parcel_alt_top.resize(_num_parcels);
    _parcel_alt_bot.resize(_num_parcels);
    _parcel_rad_top.resize(_num_parcels);
    _parcel_rad_bot.resize(_num_parcels);
    _parcel_conc.resize(_num_parcels);
    _parcel_vol.resize(_num_parcels);
    
    for (int i=0; i<_num_parcels; i++)
    {
        _parcel_alt_top[i].resize(_num_size_bins);
        _parcel_alt_bot[i].resize(_num_size_bins);
        _parcel_rad_top[i].resize(_num_size_bins);
        _parcel_rad_bot[i].resize(_num_size_bins);
        _parcel_conc[i].resize(_num_size_bins);
        _parcel_vol[i].resize(_num_size_bins);
    }
}

void CARDINAL_Object::initialize()
{
	//std::cout << "\n... Initializing CARDINAL data...\n\n";
    
    for (int i=0; i<_num_parcels; i++)
    {
        for (int j=0; j<_num_size_bins; j++)
        {
            _parcel_alt_top[i][j] = cardinal.getCloudRise().return_parcel_alt_top()(i,j);
            _parcel_alt_bot[i][j] = cardinal.getCloudRise().return_parcel_alt_bot()(i,j);
            _parcel_rad_top[i][j] = cardinal.getCloudRise().return_parcel_rad_top()(i,j);
            _parcel_rad_bot[i][j] = cardinal.getCloudRise().return_parcel_rad_bot()(i,j);
            _parcel_conc[i][j] = cardinal.getCloudRise().return_parcel_conc()(i,j);
            
            double h = _parcel_alt_top[i][j] - _parcel_alt_bot[i][j];
            if (h <= 0.0) h = 0.0;
            double Rtop = _parcel_rad_top[i][j];
            double Rbot = _parcel_rad_bot[i][j];
            double Vol = (M_PI*h/3.0)*(Rtop*Rtop+Rbot*Rtop+Rbot*Rbot);
            if (Vol <= 0.0)
                Vol = 0.0;
            _parcel_vol[i][j] = Vol;
        }
    }
}

void CARDINAL_Object::execute()
{
	//std::cout << "Executed\n";
}

void CARDINAL_Object::finalize()
{
	//std::cout << "Finalized\n";
}

/// Function to get the number of parcels
int CARDINAL_Object::return_num_parcels() const
{
    return _num_parcels;
}

/// Function to get the number of size bins
int CARDINAL_Object::return_size_bins() const
{
    return _num_size_bins;
}

/// Function to get the top of the parcel
Real CARDINAL_Object::return_parcel_alt_top(int i, int j) const
{
    return _parcel_alt_top[i][j];
}

/// Function to get the bottom of the parcel
Real CARDINAL_Object::return_parcel_alt_bot(int i, int j) const
{
    return _parcel_alt_bot[i][j];
}

/// Function to get the top radius of the parcel
Real CARDINAL_Object::return_parcel_rad_top(int i, int j) const
{
    return _parcel_rad_top[i][j];
}

/// Function to get the bottom radius of the parcel
Real CARDINAL_Object::return_parcel_rad_bot(int i, int j) const
{
    return _parcel_rad_bot[i][j];
}

/// Function to get the parcel concentration
Real CARDINAL_Object::return_parcel_conc(int i, int j) const
{
    return _parcel_conc[i][j];
}

/// Function to get the parcel volume
Real CARDINAL_Object::return_parcel_vol(int i, int j) const
{
    return _parcel_vol[i][j];
}


