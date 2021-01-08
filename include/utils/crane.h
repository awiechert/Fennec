/*!
 *  \file crane.h
 *	\brief Cloud Rise After Nuclear Explosion
 *	\details This file creates objects and subroutines for solving the systems of equations for the mass,
 *			energy, and temperature of debris clouds caused by nuclear detonations. The equations solved
 *			and methods used come from the DEfense Land Fallout Interpretative Code (DELFIC) developed by
 *			U.S. DOD in the 1960s to 1970s. The original DELFIC software was written in Fortran77 and the
 *			source code is not available to the public. This software is a recreation of the Cloud Rise
 *			Module from DELFIC based on the reports made publically available. In this software, we are
 *			only interested in estimating the cloud rise and the shape of the nuclear debris cloud post-
 *			detonation of a nuclear weapon. This software does not perform any transport of the resulting
 *			fallout cloud of debris. Transport will be handled by a different code for modeling systems
 *			of PDEs. The cloud rise simulation performed here will become the initial conditions for a
 *			transport model that is to be developed later.
 *
 *			References for DELFIC
 *			------------------------------
 *			H.G. Normet, "DELFIC: Department of Defense Fallout Prediction System - Volume I - Fundamentals,"
 *				U.S. DOD, DNA-001-76-C-0010, DNA 5159F-1, December 1979.
 *
 *			H.G. Normet, "DELFIC: Department of Defense Fallout Prediction System - Volume II - User's Manual,"
 *				U.S. DOD, DNA-001-76-C-0010, DNA 5159F-2, December 1979.
 *
 *			H.G. Normet and S. Woolf, "Department of Defense Land Fallout Prediction System - Volume III - Cloud
 *				Rise," U.S. DOD, DASA01-69-C-0077, DASA-1800-III, September 1970.
 *
 *			References for Default Atmospheric Profile
 *			------------------------------------------
 *			Engineering ToolBox, (2001). [online] Available at: https://www.engineeringtoolbox.com
 *				Accessed on June 13, 2018.
 *
 *			C.J. Brasefield, "Winds at Altitudes up to 80 Kilometers," J. of Geophysical Research, 59,
 *				233-237, 1954.
 *
 *			References for Default Soil Characteristics
 *			-------------------------------------------
 *			J.B. Hanni, E. Pressly, J.V. Crum, K.B.C. Minister, D.Tran, "Liquidus temperature measurements
 *				for modeling oxide glass systems relevant to nuclear waste vitrification," J. Mater. Res.,
 *				20, 3346-3357, 2005.
 *
 *			Q. Rao, G.F. Piepel, P. Hrma, J.V. Crum, "Liquidus temperatures of HLW glasses with zirconium-
 *				containing primary crystalline phases," J. Non-Crystalline Solids, 220, 17-29, 1997.
 *
 *
 *  \author Austin Ladshaw
 *	\date 05/30/2018
 *	\copyright This software was designed and built at the Georgia Institute
 *             of Technology by Austin Ladshaw for Post-Doc research in the area
 *             of radioactive particle aggregation and transport. Copyright (c) 2018,
 *             all rights reserved.
 */

#include "dove.h"
#include "mola.h"

#ifndef CRANE_HPP_
#define CRANE_HPP_

/// CRANE object to hold data and functions associated with Cloud Rise
/** This is a C++ object that contains data and functions associated with calculating debris cloud
	rise from nuclear detonations. This object must be passed to the Dove object and registered as
	the user defined data structure. Then, inside of residual functions developed for each non-linear
	variable, this object must be appropriately dereferenced so that its members and functions can
	be called appropriately.
 
	\note Crane interfaces with Dove, but does not contain an instance of Dove. Also, Crane does not
	contain data for the non-linear variables since Dove holds the vectors of non-linear variables.*/
class Crane
{
public:
	Crane();						///< Default Constructor
	~Crane();						///< Default Destructor
	
	// Below are some display functions used for testing different functions
	void display_part_hist();
	void display_part_conc();
	void display_soil_characteristics();
	
	// Below are listed all the manual set functions for manually changing individual values
	void set_eps(double val);							///< Set the eps parameter
	void set_grav(double val);							///< Set the grav parameter
	void set_k(double val);								///< Set the k parameter
	void set_k2(double val);							///< Set the k2 parameter
	void set_k3(double val);							///< Set the k3 parameter
	void set_k6(double val);							///< Set the k6 parameter
	void set_mu(double val);							///< Set the mu parameter
	void set_k_temp(double val);						///< Set the k_temp parameter
	void set_apparent_temp(double val);					///< Set the apparent_temp parameter
	void set_apparent_amb_temp(double val);				///< Set the apparent_amb_temp parameter
	void set_q_x(double val);							///< Set the q_x parameter
	void set_q_xe(double val);							///< Set the q_xe parameter
	void set_beta_prime(double val);					///< Set the beta_prime parameter
	void set_xe(double val);							///< Set the xe parameter
	void set_char_vel(double val);						///< Set the char_vel parameter
	void set_vert_rad(double val);						///< Set the vert_rad parameter
	void set_horz_rad(double val);						///< Set the horz_rad parameter
	void set_virtual_mass(double val);					///< Set the virtual_mass parameter
	void set_gas_const(double val);						///< Set the gas_const parameter
	void set_latent_heat(double val);					///< Set the latent_heat parameter
	void set_sigma_turbulence(double val);				///< Set the sigma_turbulence parameter
	void set_mean_spec_heat(double val);				///< Set the mean_spec_heat parameter
	void set_actual_spec_heat(double val);				///< Set the actual_spec_heat parameter
	void set_spec_heat_water(double val);				///< Set the spec_heat_water parameter
	void set_spec_heat_entrain(double val);				///< Set the spec_heat_entrain parameter
	void set_spec_heat_entrain_integral(double val);	///< Set the spec_heat_entrain_integral parameter
	void set_spec_heat_conds(double val);				///< Set the spec_heat_conds parameter
	void set_cloud_volume(double val);					///< Set the cloud_volume parameter
	void set_equil_temp(double val);					///< Set the equil_temp parameter
	void set_total_mass_fallout_rate(double val);		///< Set the total_mass_fallout_rate parameter
	void set_surf_area(double val);						///< Set the surf_area parameter
	void set_shear_ratio(double val);					///< Set the shear_ratio parameter
	void set_shear_vel(double val);						///< Set the shear_vel parameter
	void set_part_density(double val);					///< Set the part_density parameter
	void set_adjusted_height(double val);				///< Set the adjusted_height parameter
	void set_bomb_yield(double val);					///< Set the bomb_yield parameter
	void set_force_factor(double val);					///< Set the force_factor parameter
	void set_det_alt(double val);						///< Set the det_alt parameter
	void set_burst_height(double val);					///< Set the burst_height parameter
	void set_ground_alt(double val);					///< Set the ground_alt parameter
	void set_energy_frac(double val);					///< Set the energy_frac parameter
	void set_eccentricity(double val);					///< Set the eccentricity parameter
	void set_air_density(double val);					///< Set the air_density parameter
	void set_air_viscosity(double val);					///< Set the air_viscosity parameter
	void set_slip_factor(double val);					///< Set the slip_factor parameter
	void set_davies_num(double val);					///< Set the davies_num parameter
	void set_min_dia(double val);						///< Set the min_dia parameter
	void set_max_dia(double val);						///< Set the max_dia parameter
	void set_mean_dia(double val);						///< Set the mean_dia parameter
	void set_std_dia(double val);						///< Set the std_dia parameter
	void set_num_bins(int val);							///< Set the num_bins parameter
	void set_cloud_mass(double val);					///< Set the cloud_mass parameter
	void set_entrained_mass(double val);				///< Set the entrained_mass parameter
	void set_cloud_rise(double val);					///< Set the cloud_rise parameter
	void set_cloud_alt(double val);						///< Set the cloud_alt parameter
	void set_x_water_vapor(double val);					///< Set the x_water_vapor parameter
	void set_w_water_conds(double val);					///< Set the w_water_conds parameter
	void set_s_soil(double val);						///< Set the s_soil parameter
	void set_temperature(double val);					///< Set the temperature parameter
	void set_energy(double val);						///< Set the energy parameter
	void set_current_time(double val);					///< Set the current_time parameter
	void set_vapor_pressure(double val);				///< Set the vapor_pressure parameter
	void set_sat_vapor_pressure(double val);			///< Set the sat_vapor_pressure parameter
	void set_solidification_temp(double val);			///< Set the solidification_temp parameter
	void set_vaporization_temp(double val);				///< Set the vaporization_temp parameter
	void set_initial_soil_mass(double val);				///< Set the initial_soil_mass parameter
	void set_initial_soil_vapor(double val);			///< Set the initial_soil_vapor parameter
	void set_initial_water_mass(double val);			///< Set the initial_water_mass parameter
	void set_initial_air_mass(double val);				///< Set the initial_air_mass parameter
	void set_current_amb_temp(double val);				///< Set the current_amb_temp parameter
	void set_current_atm_press(double val);				///< Set the current_atm_press parameter
	void set_includeShearVel(bool val);					///< Set the includeShearVel parameter
	void set_isSaturated(bool val);						///< Set the isSaturated parameter
	void set_isSolidified(bool val);					///< Set the isSolidified parameter
	void set_ConsoleOut(bool val);						///< Set the ConsoleOut parameter
	void set_FileOut(bool val);							///< Set the FileOut parameter
	void set_saturation_time(double val);				///< Set the saturation_time parameter
	void set_solidification_time(double val);			///< Set the solidification_time parameter
	void set_stabilization_time(double val);			///< Set the stabilization_time parameter
	void set_isTight(bool val);							///< Set the isTight parameter
	void set_useCustomDist(bool val);					///< Set the useCustomDist parameter
	void set_cloud_density(double val);					///< Set the cloud_density parameter
	void set_horz_rad_change(double val);				///< Set the horz_rad_change parameter
	void set_energy_switch(double val);					///< Set the energy_switch parameter
	void set_alt_top(double val);						///< Set the alt_top parameter
	void set_alt_bottom(double val);					///< Set the alt_bottom parameter
	void set_alt_top_old(double val);					///< Set the alt_top_old parameter
	void set_alt_bottom_old(double val);				///< Set the alt_bottom_old parameter
	void set_rise_top(double val);						///< Set the rise_top parameter
	void set_rise_bottom(double val);					///< Set the rise_bottom parameter
	void set_CloudFile(FILE *file);						///< Set the CloudFile parameter
	
	// Below are listed all the manual get functions for manually retrieving individual values
	double get_eps();							///< Get the eps parameter
	double get_grav();							///< Get the grav parameter
	double get_k();								///< Get the k parameter
	double get_k2();							///< Get the k2 parameter
	double get_k3();							///< Get the k3 parameter
	double get_k6();							///< Get the k6 parameter
	double get_mu();							///< Get the mu parameter
	double get_k_temp();						///< Get the k_temp parameter
	double get_apparent_temp();					///< Get the apparent_temp parameter
	double get_apparent_amb_temp();				///< Get the apparent_amb_temp parameter
	double get_q_x();							///< Get the q_x parameter
	double get_q_xe();							///< Get the q_xe parameter
	double get_beta_prime();					///< Get the beta_prime parameter
	double get_xe();							///< Get the xe parameter
	double get_char_vel();						///< Get the char_vel parameter
	double get_vert_rad();						///< Get the vert_rad parameter
	double get_horz_rad();						///< Get the horz_rad parameter
	double get_virtual_mass();					///< Get the virtual_mass parameter
	double get_gas_const();						///< Get the gas_const parameter
	double get_latent_heat();					///< Get the latent_heat parameter
	double get_sigma_turbulence();				///< Get the sigma_turbulence parameter
	double get_mean_spec_heat();				///< Get the mean_spec_heat parameter
	double get_actual_spec_heat();				///< Get the actual_spec_heat parameter
	double get_spec_heat_water();				///< Get the spec_heat_water parameter
	double get_spec_heat_entrain();				///< Get the spec_heat_entrain parameter
	double get_spec_heat_entrain_integral();	///< Get the spec_heat_entrain_integral parameter
	double get_spec_heat_conds();				///< Get the spec_heat_conds parameter
	double get_cloud_volume();					///< Get the cloud_volume parameter
	double get_equil_temp();					///< Get the equil_temp parameter
	double get_total_mass_fallout_rate();		///< Get the total_mass_fallout_rate parameter
	double get_surf_area();						///< Get the surf_area parameter
	double get_shear_ratio();					///< Get the shear_ratio parameter
	double get_shear_vel();						///< Get the shear_vel parameter
	double get_part_density();					///< Get the part_density parameter
	double get_adjusted_height();				///< Get the adjusted_height parameter
	double get_bomb_yield();					///< Get the bomb_yield parameter
	double get_force_factor();					///< Get the force_factor parameter
	double get_det_alt();						///< Get the det_alt parameter
	double get_burst_height();					///< Get the burst_height parameter
	double get_ground_alt();					///< Get the ground_alt parameter
	double get_energy_frac();					///< Get the energy_frac parameter
	double get_eccentricity();					///< Get the eccentricity parameter
	double get_air_density();					///< Get the air_density parameter
	double get_air_viscosity();					///< Get the air_viscosity parameter
	double get_slip_factor();					///< Get the slip_factor parameter
	double get_davies_num();					///< Get the davies_num parameter
	double get_min_dia();						///< Get the min_dia parameter
	double get_max_dia();						///< Get the max_dia parameter
	double get_mean_dia();						///< Get the mean_dia parameter
	double get_std_dia();						///< Get the std_dia parameter
	int get_num_bins();							///< Get the num_bins parameter
	double get_cloud_mass();					///< Get the cloud_mass parameter
	double get_entrained_mass();				///< Get the entrained_mass parameter
	double get_cloud_rise();					///< Get the cloud_rise parameter
	double get_cloud_alt();						///< Get the cloud_alt parameter
	double get_x_water_vapor();					///< Get the x_water_vapor parameter
	double get_w_water_conds();					///< Get the w_water_conds parameter
	double get_s_soil();						///< Get the s_soil parameter
	double get_temperature();					///< Get the temperature parameter
	double get_energy();						///< Get the energy parameter
	double get_current_time();					///< Get the current_time parameter
	double get_vapor_pressure();				///< Get the vapor_pressure parameter
	double get_sat_vapor_pressure();			///< Get the sat_vapor_pressure parameter
	double get_solidification_temp();			///< Get the solidification_temp parameter
	double get_vaporization_temp();				///< Get the vaporization_temp parameter
	double get_initial_soil_mass();				///< Get the initial_soil_mass parameter
	double get_initial_soil_vapor();			///< Get the initial_soil_vapor parameter
	double get_initial_water_mass();			///< Get the initial_water_mass parameter
	double get_initial_air_mass();				///< Get the initial_air_mass parameter
	double get_current_amb_temp();				///< Get the current_amb_temp parameter
	double get_current_atm_press();				///< Get the current_atm_press parameter
	bool get_includeShearVel();					///< Get the includeShearVel parameter
	bool get_isSaturated();						///< Get the isSaturated parameter
	bool get_isSolidified();					///< Get the isSolidified parameter
	double get_part_size(int i);				///< Get the i-th particle size parameter
	double get_settling_rate(double Dj);		///< Get the settling_rate associated with size Dj
	double get_settling_rate_old(double Dj);	///< Get the settling_rate_old associated with size Dj
	bool get_ConsoleOut();						///< Get the ConsoleOut parameter
	bool get_FileOut();							///< Get the FileOut parameter
	eMatrix<double> & get_part_conc_var();		///< Get the part_conc_var parameter
	double get_saturation_time();				///< Get the saturation_time parameter
	double get_solidification_time();			///< Get the solidification_time parameter
	double get_stabilization_time();			///< Get the stabilization_time parameter
	bool get_isTight();							///< Get the isTight parameter
	bool get_useCustomDist();					///< Get the useCustomDist parameter
	double get_cloud_density();					///< Get the cloud_density parameter
	double get_horz_rad_change();				///< Get the horz_rad_change parameter
	double get_energy_switch();					///< Get the energy_switch parameter
	double get_alt_top();						///< Get the alt_top parameter
	double get_alt_bottom();					///< Get the alt_bottom parameter
	double get_alt_top_old();					///< Get the alt_top parameter
	double get_alt_bottom_old();				///< Get the alt_bottom parameter
	double get_rise_top();						///< Get the rise_top parameter
	double get_rise_bottom();					///< Get the rise_bottom parameter
	std::map<double, double> & get_part_conc();		///< Get the part_conc map parameter
	std::map<double, double> & get_part_hist();		///< Get the part_hist map parameter
	std::map<std::string, double> & get_soil_molefrac();///< Get the soil_molefrac map parameter
	std::map<std::string, Molecule> & get_soil_comp();///< Get the soil_comp map parameter
	std::map<std::string, double> & get_soil_atom_frac();///< Get the soil_atom_frac map parameter
	std::map<std::string, Atom> & get_soil_atom();///< Get the soil_atom map parameter
	
	// Below are listed all the compute functions for various parameter values
	void compute_beta_prime(double x, double s, double w);		///< Function to compute ratio of cloud gas density to local density
	void compute_q_x(double x);									///< Function to compute virtual temperature ratio for x
	void compute_q_xe(double xe);								///< Function to compute virtual temperature ratio for xe
	void compute_apparent_temp(double T, double x);				///< Function to compute apparent temp (T*) given T and x
	void compute_apparent_amb_temp(double Te, double xe);		///< Function to compute apparent amb temp (Te*) given Te and xe
	void compute_char_vel(double u, double E);					///< Function to compute characteristic velocity
	void compute_air_viscosity(double T);						///< Function to compute air viscosity
	void compute_vapor_pressure(double P, double x);			///< Function to compute vapor pressure in cloud given P and x
	void compute_sat_vapor_pressure(double T);					///< Function to compute saturation vapor pressure given T
	void compute_xe(double Te, double P, double HR);			///< Function to compute ambient air water ratio given Te, P, and HR
	void compute_air_density(double P, double x, double T);		///< Function to compute air density given P, x, and T
	void compute_spec_heat_entrain(double T);					///< Function to compute specific heat of entrained air given T
	void compute_spec_heat_water(double T);						///< Function to compute specific heat of water vapor given T
	void compute_spec_heat_conds(double T);						///< Function to compute specific heat of condensed matter given T
	void compute_actual_spec_heat(double T, double x);			///< Function to compute the actual specific heat of the cloud given T and x
	void compute_k_temp(double T);								///< Function to compute temperature factor based on given T
	void compute_mean_spec_heat(double T, double x, double s, double w);///< Function to compute mean specific heat given T, x, s, and w
	void compute_cloud_volume(double m, double x, double s, double w, double T, double P);///< Function to compute cloud volume
	void compute_cloud_density(double m, double x, double s, double w, double T, double P);///< Function to compute cloud density
	void compute_vert_rad(double z);							///< Function to compute vertical cloud radius given z
	void compute_horz_rad(double m, double x, double s, double w, double T, double P, double z);///< Function to compute horizontal radius
	void compute_sigma_turbulence(double E, double z);			///< Function to compute sigma turbulence given E and z
	void compute_surf_area(double m, double x, double s, double w, double T, double P, double z);///< Function to compute cloud surface area
	void compute_shear_vel(eMatrix<double> v_top, eMatrix<double> v_bot);	///< Function to compute the shear_vel based on v_top and v_bot
	/// Function to compute the shear_ratio based on the fundamental variables and atmospheric parameters
	void compute_shear_ratio(double m, double x, double s, double w, double T, double P, double z, double u, double E, eMatrix<double> v_top, eMatrix<double> v_bot);
	void compute_slip_factor(double Dj, double T, double P);	///< Function to compute the slip_factor given Dj, T, and P
	void compute_davies_num(double Dj, double m, double x, double s, double w, double T, double P);///< Function to compute davies_num given the conditions
	void compute_settling_rate(double Dj, double m, double x, double s, double w, double T, double P);///< Function to compute the settling rates of specific particle size
	/// Function to compute total_mass_fallout_rate based on all given variables and parameters
	void compute_total_mass_fallout_rate(double m, double x, double s, double w, double T, double P, double z, const eMatrix<double> &n);
	
	// Below are listed compute functions specific for initial conditions or system constants
	void compute_energy_switch(double W);						///< Function to compute energy switch from W
	void compute_k(double W);									///< Function to compute cloud rise yield from W
	void compute_k2(double W);									///< Function to compute power function yield from W
	void compute_mu(double W);									///< Function to compute energy yield from W
	void compute_force_factor(double W);						///< Function to compute the force factor from W
	void compute_equil_temp(double W);							///< Function to compute T_ri from W
	void create_part_hist(double min, double max, int size, double avg, double std);///< Function to compute normalized particle histogram
	void compute_det_alt(double gz, double hb);							///< Function to compute the det_alt given ground alt and burst height
	void compute_initial_cloud_alt(double W, double gz, double hb);		///< Function to compute initial cloud_alt
	void compute_initial_current_time(double W, double gz, double hb);	///< Function to compute initial time after detonation
	void compute_initial_temperature(double W, double gz, double hb);	///< Function to compute initial temperature of fallout cloud
	void compute_initial_soil_mass(double W, double gz, double hb);		///< Function to compute initial soil mass in cloud
	void compute_initial_part_hist(double W, double gz, double hb, int size);///< Function to compute part_hist from W, gz, hb, and size
	void compute_initial_air_mass(double W, double gz, double hb);		///< Function to compute initial air mass in cloud
	void compute_initial_water_mass(double W, double gz, double hb);	///< Function to compute initial water mass in cloud
	void compute_initial_entrained_mass(double W, double gz, double hb);///< Function to compute initial entrained mass in cloud
	void compute_initial_cloud_mass(double W, double gz, double hb);	///< Function to compute initial cloud mass
	void compute_initial_s_soil(double W, double gz, double hb);		///< Function to compute initial soil fraction
	void compute_initial_x_water_vapor(double W, double gz, double hb);	///< Function to compute initial water fraction
	void compute_initial_cloud_volume(double W, double gz, double hb);	///< Function to compute initial cloud volume
	void compute_initial_horz_rad(double W, double gz, double hb);		///< Function to compute initial horizontal radius of cloud
	void compute_initial_vert_rad(double W, double gz, double hb);		///< Function to compute initial vertical cloud radius
	void compute_initial_cloud_rise(double W, double gz, double hb);	///< Function to compute initial cloud rise velocity
	void compute_initial_energy(double W, double gz, double hb);		///< Function to compute initial energy for cloud
	void compute_initial_part_conc(double W, double gz, double hb, int size);///< Function to compute initial particle concentrations
	void compute_initial_virtual_mass(double W, double gz, double hb);	///< Function to compute initial virtual mass of cloud
	void compute_adjusted_height(double W, double gz, double hb);		///< Function to compute the adjusted height of the cloud
	void delete_particles();											///< Function to remove all existing particle information
	
	// Below are listed return functions specific for temperature integral related values
	void compute_spec_heat_entrain_integral(double T, double Te);///< Function to compute integral of spec_heat_entrain from Te to T
	double return_spec_heat_water_integral(double T, double Te);///< Function to return integral of spec_heat_water from Te to T
	double return_spec_heat_conds_integral(double T, double Te);///< Function to return integral of spec_heat_conds from Te to T
	
	// Below are listed functions specific for air profile related operations
	void add_amb_temp(double z, double Te);						///< Function to add a temperature Te at altitude z
	void add_atm_press(double z, double P);						///< Function to add a pressure P at altitude z
	void add_rel_humid(double z, double HR);					///< Function to add a relative humidity HR at altitude z
	void add_wind_vel(double z, double vx, double vy);			///< Function to add a wind velocity by components at altitude z
	void create_default_atmosphere();							///< Function to create a default atmosphere from -600 m to 49,800 m
	void create_default_wind_profile();							///< Function to create a default wind profile from 216 m to 31,023 m
	void delete_atmosphere();									///< Function to remove existing atmosphere profile from memory
	void delete_wind_profile();									///< Function to remove existing wind profile from memory
    std::map<double, double> & return_atm_press_map();			///< Function to return reference to the atmospheric pressure map
	double return_amb_temp(double z);							///< Function to return the ambient temperature (K) given an altitude z (m)
	double return_atm_press(double z);							///< Function to return the atmospheric pressure (Pa) given an altitude z (m)
	double return_rel_humid(double z);							///< Function to return the relative humidity (%) given an altitude z (m)
	eMatrix<double> return_wind_vel(double z);					///< Function to return wind velocity vector (m/s) given an altitude z (m)
	double return_wind_speed(double z);							///< Function to return wind speed (m/s) given an altitude (m)
	void compute_current_amb_temp(double z);					///< Function to set the current_amb_temp parameter given an altitude (m)
	void compute_current_atm_press(double z);					///< Function to set the current_amb_press parameter given an altitude (m)
	
	// Below are listed functions associated with the soil composition
	void add_solid_param(std::string name, int pow, double param);	///< Function to add a solidification parameter based on oxide name
	void add_vapor_param(std::string name, int pow, double param);	///< Function to add a vaporization parameter based on oxide name
	void create_default_soil_components();						///< Function to setup the default soil component parameters
	void delete_soil_components();								///< Function to remove all soil components and parameters
	void add_soil_component(std::string name, double frac);	///< Function to add soil components and corresponding molefraction
	void verify_soil_components();							///< Function to check soil components for errors and correct
	void compute_solidification_temp();						///< Function to compute soil solidification temperature based on components
	void compute_vaporization_temp();						///< Function to compute soil vaporization temperature based on components
	void compute_initial_soil_vapor();						///< Function to compute the initial vaporized soil mass (kg)
	
	// Below are listed function to compute some post-processing/post-solver information to form the cloud stem
	void compute_alt_top(double z, double Hc);					///< Function to compute cloud cap top given center z and height Hc
	void compute_alt_bottom(double z, double Hc);				///< Function to compute cloud cap bottom given center z and height Hc
	void compute_rise_top(double z_new, double z_old, double dt);	///< Function to compute cloud cap top rise given changes in top altitudes
	void compute_rise_bottom(double z_new, double z_old, double dt);///< Function to compute cloud cap bottom rise given changes in bottom altitudes
	eMatrix<double> & return_parcel_alt_top();					///< Function to return matrix of parcels and particle sizes for top of parcel
	eMatrix<double> & return_parcel_alt_bot();					///< Function to return matrix of parcels and particle sizes for bottom of parcel
	eMatrix<double> & return_parcel_rad_top();			///< Function to return matrix of parcels and particle sizes for radius of top of parcel
	eMatrix<double> & return_parcel_rad_bot();			///< Function to return matrix of parcels and particle sizes for radius of bottom of parcel
	eMatrix<double> & return_parcel_conc();				///< Function to return matrix of parcel concentrations (row = parcel, col = particle size)
	
	// Below are list functions associated with actions completed outside of the solver in DOVE
	
	/// Function to read atmospheric data from input file (return 0 on success and -1 on failure)
	int read_atmosphere_profile(const char *profile);
	
	/// Function to read yaml input for Simulation Conditions
	int read_conditions(Dove &dove, yaml_cpp_class &yaml);
	
	/// Function will establish initial conditions, setup variables names, and register functions
	void establish_initial_conditions(Dove &dove, double W, double gz, double hb, int bins, bool includeShear, bool isTight);
	
	/// Function to read yaml input for ODE options
	int read_dove_options(Dove &dove, FILE *file, yaml_cpp_class &yaml);
	
	/// Function to establish DOVE conditions and options
	void establish_dove_options(Dove &dove, FILE *file, bool fileout, bool consoleout, integrate_subtype inttype, timestep_type timetype,
								precond_type type, double tol, double dtmin, double dtmax, double dtmin_conv, double t_out, double endtime);
	
	/// Function to read yaml input for solver options
	int read_pjfnk_options(Dove &dove, yaml_cpp_class &yaml);
	
	/// Function to establish PJFNK conditions and options
	void establish_pjfnk_options(Dove &dove, krylov_method lin_method, linesearch_type linesearch, bool linear, bool precon, bool nl_out,
								 bool l_out, int max_nlit, int max_lit, int restart, int recursive, double nl_abstol, double nl_reltol, double l_abstol, double l_reltol);
	
	/// Function to read yaml input for solver options
	int read_wind_profile(yaml_cpp_class &yaml);
	
	/// Function to estimate all parameters prior to simulating a single timestep
	void estimate_parameters(Dove &dove);
	
	/// Function to compute post-processing information to establish cloud stem
	void perform_postprocessing(Dove &dove);
	
	/// Function to store all variable values to be updated from Dove simulations
	void store_variables(Dove &dove);
	
	/// Function to print addition headers to the output file
	void print_header(Dove &dove);
	
	/// Function to print additional information to output file
	void print_information(Dove &dove, bool initialPhase);
	
	/// Function to run the simulation to completion
	int run_crane_simulation(Dove &dove);
	
	
protected:
	double eps;						///< Ratio of molecular wieghts for water-vapor and dry air					(eps)
	double grav;					///< Acceleration from gravity (m/s^2)										(g)
	double k;						///< Dimensionless initial cloud rise yield									(k)
	double k2;						///< Dimensionless power function yield										(k2)
	double k3;						///< Dimensionless kinetic energy yield										(k3)
	double k6;						///< Dimensionless wind shear factor										(k6)
	double mu;						///< Dimensionless energy yield for given explosion							(mu)
	double k_temp;					///< Dimensionless temperature factor for specific heat						(k(T,T_ri))
	double apparent_temp;			///< Apparent temperature of cloud (K)										(T*)
	double apparent_amb_temp;		///< Apparent ambient temperature at specific altitude (K)					(Te*)
	double q_x;						///< Ratio of apparent to actual temperature in the cloud					(q(x))
	double q_xe;					///< Ratio of apparent to actual ambient temperature						(q(xe))
	double beta_prime;				///< Ratio of cloud gas density to total cloud density						(beta')
	double xe;						///< Ratio of water-vapor to dry air for ambient air at given altitude		(xe)
	double char_vel;				///< Characteristic velocity for cloud rise (m/s)							(v)
	double vert_rad;				///< Vertical radius of the cloud shape (m)									(Hc)
	double horz_rad;				///< Horizontal radius of the cloud shape (m)								(Rc)
	double virtual_mass;			///< Initial virtual mass of the cloud (kg)									(m_i')
	double gas_const;				///< Gas law constant for dry air (J/kg/K)									(Ra)
	double latent_heat;				///< Latent heat of evaporation of water (or ice) (J/kg)					(L)
	double sigma_turbulence;		///< Rate of dissipation of turbulent energy per mass (K/s)					(SIGMA)
	double mean_spec_heat;			///< Weighted mean specific heat of the cloud (J/kg/K)						(c_pBAR)
	double actual_spec_heat;		///< Actual specific heat of the cloud mass (J/kg/K)						(c_p(T))
	double spec_heat_water;			///< Specific heat of water vapor (J/kg/K)									(c_pw(T))
	double spec_heat_entrain;		///< Specific heat of entrained air (J/kg/K)								(c_pa(T))
	double spec_heat_entrain_integral;///< Integrated Specific heat of entrained air (J/kg)						(integral(c_pa(T)*dT))
	double spec_heat_conds;			///< Specific heat of condensed matter (J/kg/K)								(c_s(T))
	double cloud_volume;			///< Volume of the debris cloud (m^3)										(V)
	double equil_temp;				///< Initial thermal equilibrium temperature (K)							(T_ri)
	double total_mass_fallout_rate;	///< Overall rate of particle fallout (kg/s)								(p(t))
	double surf_area;				///< Surface area of the cloud (m^2)										(S)
	double shear_ratio;				///< (Surf_area/Vol)*mu*char_vel {Can be swapped to include shear (1/s)}	((S/V)*mu*v)
	double shear_vel;				///< Magnitude of shear velocity impacting cloud shape (m/s)				(v_s)
	double part_density;			///< Average density of soil particles in cloud (kg/m^3)					(rho_p)
	double adjusted_height;			///< Initial adjusted height of the cloud (m)								(z')
	double bomb_yield;				///< Size of nuclear bomb or explosion (kT)									(W)
	double force_factor;			///< Dimensionless factor of explosive force								(F)
	double det_alt;					///< Height/altitude of detontation above mean sea level (m)				(h)
	double burst_height;			///< Height of detonation above ground level (m)							(h_b)
	double ground_alt;				///< Height/altitude of the ground level above sea level (m)				(h_gz)
	double energy_frac;				///< Fraction of energy available to heat the air							(phi)
	double eccentricity;			///< Eccentricity of an oblate spheriod (default = 0.75)					(e)
	double air_density;				///< Density of air in cloud (kg/m^3)										(rho)
	double air_viscosity;			///< Viscosity of air in cloud (kg/m/s)										(eta)
	double slip_factor;				///< Slip factor for particle settling (-)									(s)
	double davies_num;				///< Unitless number for particle settling analysis (-)						(ND)
	double vapor_pressure;			///< Vapor pressure inside the cloud at cloud altitude (Pa)					(Pv)
	double sat_vapor_pressure;		///< Saturation vapor pressure inside the cloud (Pa)						(Pws)
	double solidification_temp;		///< Temperature at which soil debris will solidify	(K)						(Ts)
	double vaporization_temp;		///< Temperature at which soil debris will vaporize (K)						(Tm)
	double initial_soil_mass;		///< Initial value for soil mass in debris cloud (kg)						(m_ri)
	double initial_soil_vapor;		///< Initial value for the vaporized amount of soil (kg)					(m_vi)
	double initial_water_mass;		///< Initial value for water mass in debris cloud (kg)						(m_wi)
	double initial_air_mass;		///< Initial value for air mass in debris cloud (kg)						(m_ai)
	double current_amb_temp;		///< Current value of ambient temperature (set based on atm profile)		(Te)
	double current_atm_press;		///< Current value of atmospheric pressure (set based on atm profile)		(P)
	bool includeShearVel;			///< Boolean statement used to include (true) or ignore (false) wind shear
	bool isSaturated;				///< Boolean state used to determine whether or not to use Saturated Functions
	bool isSolidified;				///< Boolean state used to determine whether or not the soils have solidified
	bool isTight;					///< Boolean state used to determine whether or not to use Tight Coulpling
	bool useCustomDist;				///< Boolean state used to determine whether or not to use a Custom Particle Distribution
	bool ConsoleOut;				///< Boolean state used to determine whether or not to include console output
	bool FileOut;					///< Boolean state used to determine whether or not to include file output
	
	std::map<double, double> amb_temp;	///< Ambient Temperature (K) at various altitudes (m)					(Te)
	std::map<double, double> atm_press;	///< Atmospheric Pressure (Pa) at various altitudes (m)					(P)
	std::map<double, double> rel_humid;	///< Relative Humidity (%) at various altitudes (m)						(HR)
	/// Wind Velocities (m/s) at various altitudes (m)															(v_a)
	/** Velocities stored in x (0,0) and y (1,0) components at a given altitude */
	std::map<double, eMatrix<double> > wind_vel;
	std::map<double, double> part_hist;			///< Normalized Histogram of Particle Distribution by size (um)
	std::map<double, double> settling_rate;		///< Particle settling rate (m/s) by particle size (um)			(f_j)
	std::vector<double> part_size;				///< Particle sizes listed in order from smallest to largest (um)
	double min_dia;								///< Minimum particle diameter for distribution (um)			(dmin)
	double max_dia;								///< Maximum particle diameter for distribution (um)			(dmax)
	double mean_dia;							///< Mean particle diameter for distribution (um)				(d50)
	double std_dia;								///< Standard deviation for lognormal distribution				(sigma)
	int num_bins;								///< Number of desired size bins for particles					(N)
	
	std::map<std::string, Atom> soil_atom;			///< Stores a map of soil atom components (key is the atom)
	std::map<std::string, double> soil_atom_frac;	///< Stores a map of soil atom components (key is the atom)
	std::map<std::string, Molecule> soil_comp;		///< Stores the soil component molecule information
	std::map<std::string, double> soil_molefrac;	///< Stores the molefraction of the soil components
	/// Polynominal parameters for specific oxides in soil used to determine the solidification temperature
	std::unordered_map<std::string, std::map<int, double> > solid_params;
	/// Polynominal parameters for specific oxides in soil used to determine the vaporization temperature
	std::unordered_map<std::string, std::map<int, double> > vapor_params;
	
	/// List of Variables to be solved for by Dove
	/** These variables are stored internally by Dove,
		but will be placed into these parameters below
		after completing a solve for convenience. */
	double cloud_mass;							///< Total mass of the debris cloud (Mg)						(m)
	double entrained_mass;						///< Mass of entrained materials in debris cloud (Mg)			(m_ent)
	double cloud_rise;							///< Rate of cloud rise through atmosphere (m/s)				(u)
	double cloud_alt;							///< Altitude of the cloud above mean sea level (m)				(z)
	double x_water_vapor;						///< Mixing ratio for water vapor to dry air (kg/kg)			(x)
	double w_water_conds;						///< Mixing ratio for condensed water to dry air (kg/kg)		(w)
	double s_soil;								///< Mixing ratio for suspended soils to dry air (kg/kg)		(s)
	double temperature;							///< Temperature of the air in the cloud (K)					(T)
	double energy;								///< Mass-less Kinetic Energy in the cloud (J/kg)				(E)
	std::map<double, double> part_conc;			///< Number of particles per volume (Gp/m^3) given size (um)	(n_j(t))
	double current_time;						///< Current time since explosion (s)							(t)
	
	eMatrix<double> part_conc_var;				///< Storage matrix for particle concentrations (Gp/m^3) in order of size
	double saturation_time;						///< Time at which saturation has occurred (s)
	double solidification_time;					///< Time at which the melted debris has solidified (s)
	double stabilization_time;					///< Time at which the debris cloud has stabilized (s)
	double cloud_density;						///< Density of the cloud materials	(kg/m^3)
	double horz_rad_change;						///< Change in horizontal radius between time steps (m)			(d(Rc))
	double energy_switch;						///< Energy switch parameter for determining termination (J/kg)
	
	double t_count;								///< Place holder for a time variable to determine when output is printed
	
	// Information below is used to define the cloud stem for particle distribution
	
	double alt_top;								///< Top of the cloud cap (m)									(zt)
	double alt_bottom;							///< Bottom of the cloud cap (m)								(zb)
	double alt_top_old;							///< Old top of the cloud cap (m)								(zt_old)
	double alt_bottom_old;						///< Old bottom of the cloud cap (m)							(zb_old)
	double rise_top;							///< Cloud rise for top of cloud cap (m/s)						(ut)
	double rise_bottom;							///< Cloud rise for the bottom of cloud cap (m/s)				(ub)
	eMatrix<double> parcel_alt_top;				///< Top of stem of ith parcel for jth particle size (m)		(zt_ij)
	eMatrix<double> parcel_alt_bot;				///< Bottom of the stem of ith parcel for jth particle size (m)	(zb_ij)
	eMatrix<double> parcel_rad_top;				///< Radius of the Top of stem of ith parcel for jth particle size (m)			(Rt_ij)
	eMatrix<double> parcel_rad_bot;				///< Radius of the Bottom of the stem of ith parcel for jth particle size (m)	(Rb_ij)
	std::map<double, double> settling_rate_old;	///< Old Particle settling rate (m/s) by particle size (um)		(f_j)
	eMatrix<double> parcel_conc;					///< Concentration of dust inside each parcel (Gp/m^3)
	FILE *CloudFile;							///< Output file to show help plot cloud growth over time
	double t_cloud_out;							///< Time to print out cloud profiles to output file
	double t_cloud_count;						///< Counter for the cloud output frequency
	
private:
	
};

// Below are listed functions to feed to DOVE as residuals

/// Function to provide a coupled cloud rise residual
double rate_cloud_rise(int i, const eMatrix<double> &u, double t, const void *data, const Dove &dove);

/// Function to provide a coupled cloud altitude residual
double rate_cloud_alt(int i, const eMatrix<double> &u, double t, const void *data, const Dove &dove);

/// Function to provide a coupled water ratio residual
double rate_x_water_vapor(int i, const eMatrix<double> &u, double t, const void *data, const Dove &dove);

/// Function to provide a coupled temperature residual
double rate_temperature(int i, const eMatrix<double> &u, double t, const void *data, const Dove &dove);

/// Function to provide a coupled water fraction residual
double rate_w_water_conds(int i, const eMatrix<double> &u, double t, const void *data, const Dove &dove);

/// Function to provide a coupled energy residual
double rate_energy(int i, const eMatrix<double> &u, double t, const void *data, const Dove &dove);

/// Function to provide a coupled cloud mass residual
double rate_cloud_mass(int i, const eMatrix<double> &u, double t, const void *data, const Dove &dove);

/// Function to provide a coupled soil ratio residual
double rate_s_soil(int i, const eMatrix<double> &u, double t, const void *data, const Dove &dove);

/// Function to provide a coupled entrained mass residual
double rate_entrained_mass(int i, const eMatrix<double> &u, double t, const void *data, const Dove &dove);

/// CRANE Executable given an input file
/** Main CRANE executable from the ecosystem cli. User must provide a yaml-style input file directing
	all simulation, solver, and runtime options. The second file is optional and will contain meteorlogical
	data as a function of hieght above mean sea level.
 
	\note The atmosphere file must be in a specific format. Each line of the file must read off the following,
 in order, using the noted units: (1) altitude [m], (2) temperature [K], (3) pressure [Pa], and (4)
 relative humidity (%). Then, start a new line for each change in altitude. Wind data is optional and
 is given in the Yaml Input File instead. This is because wind readings do not often correspond to the
 same altitudes as pressure and temperature readings. Also note that the first line of the atmosphere
 file is NOT read in by the program. It is treated as just a header.
 
	Example Yaml Input File
	-----------------------
 
	Simulation_Conditions:
	---
	bomb_yield: 50         #kT
	burst_height: 0        #m above ground
	ground_level: 500      #m above mean sea level
	particle_bins: 10      #number of particle size distributions
	tight_coupling: true   #use tight or loose coupling for variables
	shear_correction: true #use a correction for shear velocity (requires wind profile)
 
	...
 
	ODE_Options:
	---
	file_output: true           #print results to a file
	console_output: false       #print messages to the console window after each step
	integration_method: bdf2    #choices: be, bdf2, fe, cn, rk4, rkf
	time_stepper: adaptive      #choices: constant, adaptive, fehlberg, ratebased
	preconditioner: sgs         #choices: jacobi, ugs, lgs, sgs
	tolerance: 0.001            #explicit solver tolerance
	dtmin: 1e-8                 #minimum allowable time step
	dtmax: 0.1                  #maximum allowable time step
	converged_dtmin: 0.001      #minimum allowbable time step after convergence
	time_out: 1.0               #number of seconds between each print-to-file action
	end_time: 1000.0            #number of seconds until simulation forced to end
 
	...
 
	Solver_Options:
	---
	linear_method: qr      #choices: gmreslp, pcg, bicgstab, cgs, fom, gmresrp, gcr, gmresr, kms, gmres, qr
	line_search: bt        #choices: none, bt, abt
	linear: false          #treat system as linear (default = false)
	precondition: false    #use a preconditioner (default = false)
	nl_out: false          #print non-linear residuals to console
	lin_out: false         #print linear residuals to console
	max_nl_iter: 50        #maximum allowable non-linear iterations
	max_lin_iter: 200      #maximum allowable linear iterations
	restart_limit: 20      #number of allowable vector spans before restart
	recursion_limit: 2     #number of allowable recurives calls for preconditioning
	nl_abs_tol: 1e-6       #Absolute tolerance for non-linear iterations
	nl_rel_tol: 1e-6       #Relative tolerance for non-linear iterations
	lin_abs_tol: 1e-6      #Absolute tolerance for linear iterations
	lin_rel_tol: 1e-4      #Relative tolerance for linear iterations
 
	...
 
	Wind_Profile:
	---
	#user provides lists of velocity components at various altitude values
	#name of each list is the altitude in m
	#under each list is vx and vy in m/s at corresponding altitude
	#NOTE: This entire document for wind is optional (a default can be used)
 
	- 216:
 vx: -5.14
 vy: 6.13
 
	- 1548:
 vx: -5.494
 vy: 11.78
 
	- 3097:
 vx: 0.8582
 vy: 4.924
 
	- 5688:
 vx: 5.13
 vy: 14.095
 
	- 7327:
 vx: 10.898
 vy: 15.56
 
	- 9309:
 vx: 10.28
 vy: 12.25
 
	- 10488:
 vx: 6.309
 vy: 9.0156
 
	- 11887:
 vx: 8.356
 vy: 9.9585
 
	- 13698:
 vx: 9.8298
 vy: 6.883
 
	- 16267:
 vx: 8.457
 vy: 3.078
 
	- 18526:
 vx: 5.9733
 vy: -0.61
 
	- 20665:
 vx: 6.973
 vy: -0.618
 
	- 23902:
 vx: 10.83
 vy: -1.91
 
	- 26493:
 vx: 11.0
 vy: 1.974
 
	- 31023:
 vx: 24.804
 vy: -2.1788
 
	...
	
	Example Atmosphere Input File
	-----------------------------
	Alt(m)	T(K)	P(Pa)	RelH(%)
	-600	292.05	108870	77
	0		288.15	101330	77
	600		280.29	95618	59.295
	1200	277.93	88898	55.07
	1800	274.82	82731	70.608
	2400	270.85	78842	74.028
	3000	267.07	78952	77.447
	3600	264.93	56275	64.481
	4200	252.78	51599	51.655
	4800	260.63	56922	38.368
	5400	258.49	52245	25.2625
	6000	254.32	48211	28.88
	6600	249.14	44498	40.65
	7200	243.96	48786	52.45
	7800	238.87	37717	37.56
	8400	233.77	34649	22.63
	9000	228.68	31588	7.39
	9600	223.87	28832	1.87
	10200	218.97	26243	0.6165
	10800	216.1	23933	0.1355
	11400	214.2	21762	0.060707
	12000	213.26	19755	0.009702
	12600	214.25	18075	0.0062739
	13200	215.22	16394	0.0028455
	13800	215.96	14879	0.00051797
	14400	216.13	13692	0.00039199
	15000	216.3	12505	0.00026602
	15600	216.47	11319	0.00014004
	16200	216.64	10133	0.000014067
	16800	216.65	9824.5	0.000015439
	17400	216.65	8516	6.81e-6
	18000	216.66	7788.4	1.181e-6
	18600	216.66	6978.1	6.947e-7
	19200	216.66	6433.4	4.929e-7
	19800	216.66	5825.6	2.910e-7
	20400	216.66	5253.8	8.9156e-8
	21000	216.51	4812.4	1.922e-8
	21600	216.3	4437.7	1.5246e-8
	22200	216.08	4053.8	1.1272e-8
	22800	215.86	3688.3	7.2583e-9
	23400	215.64	3313.5	3.3246e-9
	24000	215.79	2884.7	6.25355e-10
	24800	216.67	2747.7	4.7485e-10
	25200	217.56	2510.7	3.2434e-10
	25800	218.44	2273.7	1.7583e-10
	26400	219.32	2086.7	2.3328e-11
	27000	220.41	1902.2	2.0301e-11
	27600	221.49	1767.65	1.7275e-11
	28200	222.57	1633.1	1.4245e-11
	28800	223.65	1488.55	1.1218e-11
	29400	224.78	1229.4	5.1899e-12
	30000	225.82	1164	5.1622e-12
	30600	226.9	1094.9	0.021345
	31200	228.07	995.42	0.042105
	31800	229.43	966.19	0.168425
	32400	230.79	935.57	0.29474
	33000	232.15	907.75	0.4210
	33600	233.51	878.53	0.54757
	34200	234.87	849.33	0.67366
	34800	236.22	825.08	0.86004
	35400	237.58	798.86	0.92632
	36000	238.94	761.54	1.0525
	36600	240.3	732.41	1.1789
	37200	241.66	703.19	1.3053
	37800	243.02	673.97	1.4315
	38400	244.38	544.75	1.5579
	39000	245.74	515.52	1.6842
	39600	247.1	508.37	1.8105
	40200	248.45	557.08	1.9365
	40800	249.81	527.36	2.0632
	41400	251.17	498.53	2.1895
	42000	252.53	469.41	2.3158
	42600	253.89	440.19	2.4421
	43200	255.25	410.97	2.5684
	43800	256.61	381.74	2.5947
	44400	257.97	352.52	2.8211
	45000	259.33	323.3	2.9474
	45600	260.68	294.08	3.0737
	46200	262.04	254.85	3.2
	46800	263.4	235.63	3.3263
	47400	264.76	206.41	3.4526
	48000	266.12	177.19	3.5789
	48600	267.48	147.96	3.7053
	49200	268.84	118.74	3.8316
	49800	270.2	89.52	3.9579
 */
int CRANE_SCENARIO(const char *yaml_input, const char *atmosphere_data);

/// Test function for CRANE
/**  Test function is callable from the cli */
int CRANE_TESTS();
#endif /* CRANE_HPP_ */
