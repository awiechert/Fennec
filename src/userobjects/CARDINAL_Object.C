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

InputParameters CARDINAL_Object::validParams()
{
	InputParameters params = GeneralUserObject::validParams();
	params.addClassDescription("GeneralUserObject for CARDINAL member data and functions. CARDINAL is used to establish initial conditions for FENNEC simulations by estimating cloud rise, particle distributions, and establishing wind, temperature, pressure, and relative humidity profiles for the atmosphere.");
    params.addRequiredParam<std::string>("input_file", "Name and path (relative to the directory from which the fennec-opt executable is run) to the input file for the CARDINAL simulation");
    params.addRequiredParam<std::string>("atm_file","Name and path (relative to the directory from which the fennec-opt executable is run) to the atmospheric data file for CARDINAL");
    params.addRequiredParam<std::string>("data_path", "Path (relative to the directory from which the fennec-opt executable is run) to the database files needed for CARDINAL");
    params.addParam<bool>("mono_variate_population",true,"True = Using the Mono-variate population balance model, False = Using the bi-variate population balance model. Set to True be default");
	return params;
}

CARDINAL_Object::CARDINAL_Object(const InputParameters & parameters) : GeneralUserObject(parameters),
_input_file(getParam<std::string>("input_file")),
_atm_file(getParam<std::string>("atm_file")),
_data_path(getParam<std::string>("data_path")),
_mono_variate_model(getParam<bool>("mono_variate_population"))
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
    //if (file!= nullptr)
    //    fclose(file);
    //if (cloud!=nullptr)
    //    fclose(cloud);
    
    if (success != 0)
    	moose::internal::mooseErrorRaw("CARDINAL SIMULATION HAS FAILED!");
    
    _num_parcels = cardinal.getCloudRise().return_parcel_alt_top().rows();
    _num_size_bins = cardinal.getCloudRise().return_parcel_alt_top().columns();
    _num_nuc_bins = _num_size_bins;
    _debris_density = cardinal.getCloudRise().get_part_density();
    _parcel_alt_top.resize(_num_parcels);
    _parcel_alt_bot.resize(_num_parcels);
    _parcel_rad_top.resize(_num_parcels);
    _parcel_rad_bot.resize(_num_parcels);
    _parcel_conc.resize(_num_parcels);
    _parcel_vol.resize(_num_parcels);
    _total_nuclides_per_bin.resize(_num_size_bins);
    _total_debris_per_bin.resize(_num_size_bins);
    _bivariate_nuclide_density.resize(_num_size_bins);
    _monovariate_nuclide_density.resize(_num_size_bins);
    _diameters.resize(_num_size_bins);
    _activity.resize(_num_size_bins);
    
    //Initializations for air information (used with air ionization calculations) [MAY NEED TO CHANGE]
    _air_atoms.resize(4);
    _air_atoms[0].Register("C");
    _air_atoms[1].Register("N");
    _air_atoms[2].Register("O");
    _air_atoms[3].Register("Ar");
    _air_frac.resize(4);
    _air_frac[0] = 0.000124;
    _air_frac[1] = 0.755267;
    _air_frac[2] = 0.231781;
    _air_frac[3] = 0.012827;
    _Wair = 34.0;
    
    for (int i=0; i<_num_parcels; i++)
    {
        _parcel_alt_top[i].resize(_num_size_bins);
        _parcel_alt_bot[i].resize(_num_size_bins);
        _parcel_rad_top[i].resize(_num_size_bins);
        _parcel_rad_bot[i].resize(_num_size_bins);
        _parcel_conc[i].resize(_num_size_bins);
        _parcel_vol[i].resize(_num_size_bins);
    }
    
    // Calculation of parcel concentrations, volumes, and locations
    _total_initial_debris = 0.0;
    _total_solids_volume = 0.0;
    for (int j=0; j<_num_size_bins; j++)
    	_total_debris_per_bin[j] = 0.0;
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
            
            _total_initial_debris += _parcel_vol[i][j]*_parcel_conc[i][j]/1.0e9;
            _total_debris_per_bin[j] += _parcel_vol[i][j]*_parcel_conc[i][j]/1.0e9;
        }
    }
    
    // Calculation of the total moles of nuclides on all debris particles
    _total_nuclides = 0.0;
    std::map<double, FissionProducts>::iterator kt;
    int bin = 0;
    for (kt=cardinal.getActivity().getNuclideDistributionMap().begin(); kt!=cardinal.getActivity().getNuclideDistributionMap().end(); ++kt)
    {
    	_diameters[bin] = kt->first;
    	double part_vol = 3.14159/6.0*kt->first*kt->first*kt->first;
        double total_vol = part_vol*_total_debris_per_bin[bin]*1e9*1e9;
        _total_solids_volume += total_vol;
    
    	_total_nuclides_per_bin[bin] = 0.0;
        for (int i=0; i<kt->second.getNumberNuclides(); i++)
        {
            _total_nuclides += kt->second.getIsotope(i).getConcentration();
            _total_nuclides_per_bin[bin] += kt->second.getIsotope(i).getConcentration();
        }
        for (int i=0; i<kt->second.getNumberStableNuclides(); i++)
        {
            _total_nuclides += kt->second.getStableIsotope(i).getConcentration();
            _total_nuclides_per_bin[bin] += kt->second.getStableIsotope(i).getConcentration();
        }
        bin++;
    }
    _avg_nuclide_density = _total_nuclides/_total_initial_debris;
    _avg_nuc_per_solid_vol = _total_nuclides/_total_solids_volume;
    for (int j=0; j<_num_size_bins; j++)
    	_bivariate_nuclide_density[j] = _total_nuclides_per_bin[j]/_total_debris_per_bin[j];
    
    // Calculate nuclide distribution for mono-variable model
    bin = 0;
    for (kt=cardinal.getActivity().getNuclideDistributionMap().begin(); kt!=cardinal.getActivity().getNuclideDistributionMap().end(); ++kt)
    {
    	double part_vol = 3.14159/6.0*kt->first*kt->first*kt->first;
        _monovariate_nuclide_density[bin] = _avg_nuc_per_solid_vol*part_vol*1e9*1e9;
    	bin++;
    }
    
    // Initialize/reset the isotope concentrations in KEA for each size bin
    bin = 0;
    for (kt=cardinal.getActivity().getNuclideDistributionMap().begin(); kt!=cardinal.getActivity().getNuclideDistributionMap().end(); ++kt)
    {
    	//Initialize Radioactivity
        cardinal.getActivity().getRadioactivityDistributionMap()[kt->first] = 0.0;
        //Looping through the stable and unstable nuclides
        for (int i=0; i<kt->second.getNumberNuclides(); i++)
        {
        	if (_mono_variate_model == true)
            	kt->second.getIsotope(i).setInitialCondition(kt->second.getIsotope(i).getConcentration()/_total_nuclides_per_bin[bin]*_monovariate_nuclide_density[bin]);
            else
            	kt->second.getIsotope(i).setInitialCondition(kt->second.getIsotope(i).getConcentration()/_total_nuclides_per_bin[bin]*_bivariate_nuclide_density[bin]);
            kt->second.getIsotope(i).setConcentration(kt->second.getIsotope(i).getInitialCondition());
            
            cardinal.getActivity().getRadioactivityDistributionMap()[kt->first] += kt->second.getIsotope(i).getActivity();
        }
        for (int i=0; i<kt->second.getNumberStableNuclides(); i++)
        {
        	if (_mono_variate_model == true)
            	kt->second.getStableIsotope(i).setInitialCondition(kt->second.getStableIsotope(i).getConcentration()/_total_nuclides_per_bin[bin]*_monovariate_nuclide_density[bin]);
            else
            	kt->second.getStableIsotope(i).setInitialCondition(kt->second.getStableIsotope(i).getConcentration()/_total_nuclides_per_bin[bin]*_bivariate_nuclide_density[bin]);
            kt->second.getStableIsotope(i).setConcentration(kt->second.getStableIsotope(i).getInitialCondition());
            
            cardinal.getActivity().getRadioactivityDistributionMap()[kt->first] += kt->second.getStableIsotope(i).getActivity();
        }
        _activity[bin] = cardinal.getActivity().getRadioactivityDistributionMap()[kt->first];
        bin++;
    }
    
    //Iterate through atmospheric data map and initialize the ionization parameter space
    std::map<double, double>::iterator it;
    for (it=cardinal.getCloudRise().return_atm_press_map().begin(); it!=cardinal.getCloudRise().return_atm_press_map().end(); ++it)
    {
    	double z = it->first;
    	double Te = cardinal.getCloudRise().return_amb_temp(z);
        double P = cardinal.getCloudRise().return_atm_press(z);
        double HR = cardinal.getCloudRise().return_rel_humid(z);
        cardinal.getCloudRise().compute_xe(Te, P, HR);
        cardinal.getCloudRise().compute_air_density(P, cardinal.getCloudRise().get_xe(), Te);
        std::vector<double> temp;
        temp.resize(_num_size_bins);
        _ionization_func[cardinal.getCloudRise().get_air_density()] = temp;
    }
    
}



// ---- Functions below dictate what to calculate between timesteps (in specified order) ----

// First: Setup before/after each time step
void CARDINAL_Object::initialize()
{
	//Perform any data initializations as needed
}

// Second: Execute before/after each time step
void CARDINAL_Object::execute()
{
	//Simulate decay of nuclides for segment of time _dt (ASSUMES _dt IS IN SECONDS)
    std::map<double, FissionProducts>::iterator kt;
    int bin = 0;
    for (kt=cardinal.getActivity().getNuclideDistributionMap().begin(); kt!=cardinal.getActivity().getNuclideDistributionMap().end(); ++kt)
    {
        kt->second.calculateFractionation(_dt);
        cardinal.getActivity().getRadioactivityDistributionMap()[kt->first] = 0.0;
        //Looping through the stable and unstable nuclides
        for (int i=0; i<kt->second.getNumberNuclides(); i++)
        {
            cardinal.getActivity().getRadioactivityDistributionMap()[kt->first] += kt->second.getIsotope(i).getActivity();
        }
        for (int i=0; i<kt->second.getNumberStableNuclides(); i++)
        {
            cardinal.getActivity().getRadioactivityDistributionMap()[kt->first] += kt->second.getStableIsotope(i).getActivity();
        }
        _activity[bin] = cardinal.getActivity().getRadioactivityDistributionMap()[kt->first];
        
        //Loop over the ionization map at various air densities
        std::map<double, std::vector<double> >::iterator it;
        for (it=_ionization_func.begin(); it!=_ionization_func.end(); ++it)
        {
        	kt->second.calculateIonizationRate(_air_atoms, _air_frac, it->first, _Wair);
            it->second[bin] = kt->second.getIonizationRate();
        }
        
    	bin++;
    }
}

// Third: Finish before/after each time step  (Repeat above)
void CARDINAL_Object::finalize()
{
	//When set is finished, perpare data for next step
    std::map<double, FissionProducts>::iterator kt;
    for (kt=cardinal.getActivity().getNuclideDistributionMap().begin(); kt!=cardinal.getActivity().getNuclideDistributionMap().end(); ++kt)
    {
        //Looping through the stable and unstable nuclides
        for (int i=0; i<kt->second.getNumberNuclides(); i++)
        {
            kt->second.getIsotope(i).setInitialCondition(kt->second.getIsotope(i).getConcentration());
        }
        for (int i=0; i<kt->second.getNumberStableNuclides(); i++)
        {
            kt->second.getStableIsotope(i).setInitialCondition(kt->second.getStableIsotope(i).getConcentration());
        }
    }
}




// ---- Functions below provide data access to specific CARDINAL information to couple with other kernels -----

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

/// Function to get the number of size bins
int CARDINAL_Object::return_nuc_bins() const
{
    return _num_nuc_bins;
}

/// Function to return the boolean argument for the mono/bi-variate options
bool CARDINAL_Object::isMonoVariate() const
{
    return _mono_variate_model;
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

/// Function to get the diameter of the given particle bin
Real CARDINAL_Object::return_diameter(int bin) const
{
    return _diameters[bin];
}

/// Function to get the nuclide density of bivariate bins
Real CARDINAL_Object::return_bivar_nuclides(int bin) const
{
    return _bivariate_nuclide_density[bin];
}

/// Function to get the nuclide density of monovariate bins
Real CARDINAL_Object::return_monovar_nuclides(int bin) const
{
    return _monovariate_nuclide_density[bin];
}

/// Function to get the activity of nuclides in the given bin
Real CARDINAL_Object::return_activity(int bin) const
{
    return _activity[bin];
}

/// Function to get the approximated air ionization given the particle bin and density
Real CARDINAL_Object::return_ionization_coeff(int bin, double density) const
{
    Real ion = 0.0;
    
    //Setup the iterators
    std::map<double, std::vector<double> >::const_iterator it=_ionization_func.begin();
    std::map<double, std::vector<double> >::const_reverse_iterator rit=_ionization_func.rbegin();
    
    //Special Case 1: z less than lowest value in map
    if (density <= it->first)
        return it->second[bin];
    
    //Special Case 2: z greater than highest value in map
    if (density >= rit->first)
        return rit->second[bin];
    
    //Iterate through map
    double old_dens = it->first;
    double old_ion = it->second[bin];
    for (it=_ionization_func.begin(); it!=_ionization_func.end(); ++it)
    {
        if (it->first > density)
        {
            double slope = (it->second[bin] - old_ion) / (it->first - old_dens);
            double inter = it->second[bin] - (slope*it->first);
            ion = slope*density + inter;
            break;
        }
        else
        {
            old_dens = it->first;
            old_ion = it->second[bin];
        }
    }
    
    return ion;
}

/// Function to get the debris particle density (kg/m^3)
Real CARDINAL_Object::return_debris_density() const
{
    return _debris_density;
}

