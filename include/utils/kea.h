/*!
 *  \file kea.h kea.cpp
 *	\brief Kernel for Estimating Activity-distribution
 *	\details This file contains a C++ object for determining the distribution of
 *			radioactivity particles and activity onto debris particles in specific
 *			size classes. It is directly coupled with FAIRY to determine yields of
 *			nuclides from a specific nuclear event, then will be integrated into
 *			CRANE to establish the distribution of nuclides in the debris cloud.
 *			For the sake of modularity, this kernel will not be coupled with CRANE
 *			and instead CRANE will integrate this kernel into its source. Thus, the
 *			activity-distribution in KEA will be determined from information that is
 *			anticipated to be passed to the functions and objects developed here.
 *			That will allow for independent testing of this kernel and allow for 
 *			changes to how the activity-distribution is determined to be made on
 *			the fly. 
 *
 *			References for Activity-Distribution
 *			------------------------------------
 *			E.C. Freiling, "Radionuclide Fractionation in Bomb Debris," Science,
 *				1991-1998, 1961.
 *
 *			J.T. McGahan, E.J. Kownaki, "Sensitivity of Fallout Predictions to 
 *				Initial Conditions and Model Assumptions," Defense Nuclear Agency,
 *				DNA-3439F, 1974.
 *
 *			H.G. Norment, "DELFIC: Department of Defense Fallout Prediction System:
 *				Volume I - Fundamentals," Defense Nuclear Agency, DNA-5159F, 1979.
 *
 *			R.C. Tompkins, "DELFIC: Department of Defense Fallout Prediction System:
 *				Volume V - Pacticle Activity," US Army Nuclear Defense Laboratory, 
 *				DASA-1800-V, 1968.
 *
 *			D.A. Hooper, V.J. Jodoin, "Revision of the DELFIC Particle Activity Module,"
 *				Oak Ridge National Laboratory, ORNL/TM-2010/220, 2010.
 *
 *			Reference for Induced-Soil Activity
 *			-----------------------------------
 *			T.H. Jones, "A Prediction System for the Neutron-Induced Activity Contribution
 *				to Fallout Exposure Rates," U.S. Naval Radiological Defense Laboratory,
 *				USNRDL-TR-1056, 1966.
 *
 *			Reference for Neutron Absorption and Scattering Cross Sections (in EEL)
 *			-----------------------------------------------------------------------
 *			V.F. Sears, "Neutron Scattering Lengths and Cross Sections," Neutron News, 3,
 *				26-37, 1992. 
 *
 *  \author Austin Ladshaw
 *	\date 02/07/2019
 *	\copyright This software was designed and built at the Georgia Institute
 *             of Technology by Austin Ladshaw for research in the area
 *             of radioactive particle decay and transport. Copyright (c) 2018,
 *			   all rights reserved.
 */

#ifndef KEA_HPP_
#define KEA_HPP_

#include "fairy.h"
#include "mola.h"

/// Enumeration for the list of valid activity-size distribution methods
/** List of valid models for activity-size distributions.*/
typedef enum {freiling, freiling_tompkins, mod_freiling, mod_freiling_tompkins} asd_model;

/// Function to determine the activity-size distribution model type
asd_model activitymodel_choice(std::string &choice);

/// C++ Object for determining the activity-size distribution
/** This object inherits from FissionProducts and will determine the activity-size distributions
	of nuclides in a nuclear debris cloud. It will also be used to determine the induced activity
	in soil particles and from weapon material absorbtion of neutrons. While this kernel is developed
	independently from CRANE, it will be coupled with the size distributions and other parameters
	from CRANE. Then CRANE and KEA will be implemented together to fully describe the nuclear debris
	cloud post-detonation and to the time of cloud stabilization.
 */
class ActivityDistribution
{
public:
	ActivityDistribution();											///< Default constructor
	~ActivityDistribution();										///< Default destructor
	
	void set_model_type(asd_model type);							///< Set the model_type parameter
	void set_capfis_ratio(double val);								///< Set the capfis_ratio parameter
	void set_neutrons_emit(double val);								///< Set the neutrons_emit parameter
	void set_fusion_yield(double val);								///< Set the fusion_yield parameter
	void set_fission_yield(double val);								///< Set the fission_yield parameter
	void set_total_yield(double val);								///< Set the total_yield parameter
	void set_casing_cap(double val);								///< Set the casing_cap parameter
	void set_casing_den(double val);								///< Set the casing_den parameter
	void set_casing_thickness(double val);							///< Set the casing_thickness parameter
	void set_casing_mw(double val);									///< Set the casing_mw parameter
	void set_casing_thermal(double val);							///< Set the casing_thermal parameter
	void set_soil_thermal(double val);								///< Set the soil_thermal parameter
	void set_soil_scattering(double val);							///< Set the soil_scattering parameter
	void set_weapon_thermal(double val);							///< Set the weapon_thermal parameter
	void set_size_cutoff(double val);								///< Set the size_cutoff parameter
	void set_burst_height(double val);								///< Set the burst_height parameter
	void set_escape_fraction(double val);							///< Set the escape_fraction parameter
	void set_volatile_fraction(double val);							///< Set the volatile_fraction parameter
	void set_soil_capture_fraction(double val);						///< Set the soil_capture_fraction parameter
	
	void initialize_fractionation_map(std::map<double, double> & part_conc);	///< Setup nuc_frac given the part_conc from CRANE
	
	void delete_casing_components();								///< Function to remove all casing components and parameters
	void add_casing_component(std::string name, double frac);	///< Function to add casing components and corresponding molefraction
	void verify_casing_components();							///< Function to check casing components for errors and correct
	
	void delete_fractionation();								///< Function to remove all maps with isotope fractionation
	void delete_capture_fractions();							///< Function to delete all maps with neutron capture fractions
	
	asd_model get_model_type();								///< Get the model_type parameter
	double get_capfis_ratio();								///< Get the capfis_ratio parameter
	double get_neutrons_emit();								///< Get the neutrons_emit parameter
	double get_fusion_yield();								///< Get the fusion_yield parameter
	double get_fission_yield();								///< Get the fission_yield parameter
	double get_total_yield();								///< Get the total_yield parameter
	double get_casing_cap();								///< Get the casing_cap parameter
	double get_casing_den();								///< Get the casing_den parameter
	double get_casing_thickness();							///< Get the casing_thickness parameter
	double get_casing_mw();									///< Get the casing_mw parameter
	double get_casing_thermal();							///< Get the casing_thermal parameter
	double get_soil_thermal();								///< Get the soil_thermal parameter
	double get_soil_scattering();							///< Get the soil_scattering parameter
	double get_weapon_thermal();							///< Get the weapon_thermal parameter
	double get_size_cutoff();								///< Get the size_cutoff parameter
	double get_burst_height();								///< Get the burst_height parameter
	double get_escape_fraction();							///< Get the escape_fraction parameter
	double get_volatile_fraction();							///< Get the volatile_fraction parameter
	double get_soil_capture_fraction();						///< Get the soil_capture_fraction parameter
	
	void compute_neutrons_emit(double fission, double fusion);		///< Compute the neutrons emitted per fission (atoms/fission)
	void compute_casing_mw();										///< Compute the casing MW (must have initialized materials first)
	void compute_casing_thermal();									///< Compute the casing thermal capture cross-section
	
	/// Compute the soil thermal capture cross-section
	void compute_soil_thermal(std::map<std::string, double> & soil_atom_frac, std::map<std::string, Atom> & soil_atom);
	/// Compute the soil scattering cross-section
	void compute_soil_scattering(std::map<std::string, double> & soil_atom_frac, std::map<std::string, Atom> & soil_atom);
	
	/// Compute the weapon thermal capture cross-section
	void compute_weapon_thermal(FissionProducts & weapon);
	
	/// Functions below compute all the capture fractions and will call the above functions for thermal and scattering info
	void compute_casing_capfrac();
	void compute_soil_capfrac(std::map<std::string, double> & soil_atom_frac, std::map<std::string, Atom> & soil_atom);
	void compute_weapon_capfrac(FissionProducts & weapon);
	
	void compute_casing_cap();										///< Compute the casing capture fraction (Sigma)
	void compute_escape_fraction();									///< Compute the casing escape fraction
	
	void compute_volatile_fraction(double h, double W);				///< Compute the neutron fraction entering soil given h (m) and W (kT)
	
	/// Compute the fraction of neutrons captured by soil
	void compute_soil_capture_fraction(std::map<std::string, double> & soil_atom_frac, std::map<std::string, Atom> & soil_atom);
	
	void initialize_fractionation(FissionProducts & yields, yaml_cpp_class & data);		///< Initialize fractionation via yield data
	
	int evaluate_initial_fractionation();							///< Go through all soil, casing, and weapon data to add nuclides
	
	void evaluate_freiling_ratios(double solid_time, double solid_temp);///< Evaluate the initial fractionation to the solidification time
	
	void evalute_freiling_dist(std::map<double, double> & part_conc);				///< Evaluate the freiling distribution
	void evalute_freiling_tompkins_dist(std::map<double, double> & part_hist);		///< Evaluate the freiling-tompkins distribution
	void evalute_mod_freiling_dist(std::map<double, double> & part_hist);			///< Evaluate the modified freiling distribution
	void evalute_mod_freiling_tompkins_dist(std::map<double, double> & part_hist);	///< Evaluate the modified freiling-tompkins distribution
	
	/// Call and evaluate the appropriate distribution function
	void evalute_distribution(std::map<double, double> & part_conc, std::map<double, double> & part_hist);
	
	void distribute_nuclides(std::map<double, double> & part_hist);	///< Distribute nuclides on particle sizes according to distribution fractions
	
	/// Run fractionation simulation to cloud stabilization time and print results to file
	void evaluate_fractionation(std::string file_name, bool file_out, double solid_time, double stab_time);
	
protected:
	asd_model model_type;											///< Type of activity-size distribution model to use
    // capfis_ratio = No*(fc)_i
	double capfis_ratio;											///< Neutron capture-to-fission ratio for induced activity
	
	/// Below are all the parameters associated with the induced-soil-activity models
	double neutrons_emit;											///< Neutrons emitted per fission in atoms/fission (No)
	double fusion_yield;											///< Fusion yield in kT (Wfu)
	double fission_yield;											///< Fission yield in kT (Wfis)
    double total_yield;                                             ///< Total weapon yield in kT (W)
	double casing_cap;												///< Weapon casing capture (Sigma)
	double casing_den;												///< Weapon casing material density in g/cm^3 (rho_c)
	double casing_thickness;										///< Weapon casing material thickness in cm (X)
	double casing_mw;												///< Weapon casing average molecular weight in g/mol (A)
	double casing_thermal;											///< Weapon casing average thermal neutron x-sec in barns (sigma_c)
	double soil_thermal;											///< Soil material average thermal neutron x-sec in barns (sigma_s)
	double soil_scattering;											///< Soil material average neutron scattering in barns (sigma_ssc)
	double weapon_thermal;											///< Weapone material thermal neutron x-sec in barns
	double size_cutoff;												///< Size cutoff point for the Freiling-Tompkins distributions in um (D)
	std::map<std::string, Atom> casing_atom;						///< Stores a map of casing atom components (key is the atom)
	std::map<std::string, double> casing_atom_frac;					///< Stores a map of casing atom components (key is the atom)
	std::map<std::string, Molecule> casing_mat;						///< Weapon casing molecular composition
	std::map<std::string, double> casing_frac;						///< Weapon casing molefractions
	double burst_height;											///< Weapon burst height above ground (ft)
	double escape_fraction;											///< Neutron fraction that escapes casing (e^-Sigma*X)
	double volatile_fraction;										///< Neutron fraction that enters volatilized soil
	double soil_capture_fraction;									///< Neutron fraction that is captured by soil
    
    /// Below are the parameters associated with the activity-size distributions
	FissionProducts initial_frac;									///< Initial fractionation prior to size differentiation
    std::map<double, FissionProducts> nuc_fractionation;            ///< Fractionation of nuclides with particle size (um)
	std::map<int, double> total_moles;								///< Total moles of nuclides for each mass number chain
    std::map<int, double> refractory_moles;							///< Refractory moles of nuclides for each mass number chain
	std::map<int, double> freiling_numbers;							///< Map of the Freiling ratio numbers (b_i)
	std::unordered_map<int, std::unordered_map<double, double> > distribution;///< Map of the distributions for nuclides [i] ==> mass num [k] ==> particle size
	
	/// Neutron fractional captures by all atomic materials
	std::map<std::string, double> casing_capfrac;					///< Casing neutron capture fractions (by atom symbol)
	std::map<std::string, double> soil_capfrac;						///< Soil neutron capture fractions (by atom symbol)
	std::map<std::string, double> weapon_capfrac;					///< Weapon neutron capture fractions (by isotope name)
	
private:
	
};

/// Test function for KEA
int KEA_TESTS();

#endif /* KEA_HPP_ */
