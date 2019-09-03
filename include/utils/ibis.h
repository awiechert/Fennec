/*!
 *  \file ibis.h ibis.cpp
 *	\brief Implicit Branching Isotope System
 *	\details This file contains a C++ object for creating and utilizing isotopes
 *			in a branching isotope decay chain. The object inherits from Class Atom
 *			(see eel.h), which creates individual atoms from names, symbols, or
 *			atomic numbers, then adds the ability to decay those atoms to different
 *			isotopes through various decay modes. Added to the Atom object are parameters
 *			for decay rates (half-lifes), branching ratios, and decay modes (alpha, beta,
 *			etc). The intent of this system is to determine how radioactive decay occurs
 *			when given a single or multiple starting isotopes. The branching system of
 *			isotopes is solved analytically using an eigenvector-eigenvalue solution
 *			coupled with a sorting algorithm to guarentee a lower triangular coefficient
 *			matrix. In addition, we also solve for the accumulation of the stable isotopes
 *			by integrating the unstable solution through time. This method is based on
 *			similar methods from the following sources:
 *
 *			Decay Solution Methods:
 *			-----------------------
 *			[1] M. Amaku, P.R. Pascholati, V.R. Vanin, Comp. Phys. Com. 181, 21-23, 2010.
 *			[2] D. Yuan, W. Kernan, J. Appl. Phys. 101, 094907, 2007.
 *
 *			Also implemented in the Isotope class are methods to estimate the mean radiation
 *			energy of beta emitters and the ionization rate coefficient for nuclides of any
 *			decay modes. The mean radiation energy uses approximations for the Fermi Function
 *			and Shape Function of the beta spectra. Methods could potentially be improved upon
 *			by updating those two functions. The ionization coefficient is calculated using
 *			the Linear Energy Transfer (LET) model coupled with theoretical models for the
 *			Stopping Power of the emissions based on decay type. References are as follows:
 *
 *			LET and Stopping Power Functions:
 *			---------------------------------
 *			[1] Y.H. Kim, S. Yiacoumi, C. Tsouris, J. Env. Radio. 143, 91-99, 2015.
 *			[2] H. Huizenga, P.R.M. Storchi, Phys. Med. Biol. 34, 1371-1396, 1989.
 *			[3] ICRU Report 37, "Stopping Powers for Electrons and Positrons," 1984.
 *			[4] W.A. Tome, J.R. Palta, Med. Phys. 5, 758-772, 1998.
 *			[5] Q.H. Mohammad, H.A. Maghdid, Research Reviews: J. Pure Appl. Phys. 5, 22-28, 2017.
 *
 *			Mean Energy, Fermi Functions, and Beta Spectra Shape Functions:
 *			---------------------------------------------------------------
 *			[1] X. Mougeot, Phys. Rev. C, 91, 055504, 2015.
 *			[2] V. Venkataramaiah, K. Gopala, A. Basavaraju, S.S. Suryanarayana, H. Sanjeeviah,
 *				J. Phys. G: Nucl. Phys. 11, 359-364, 1985.
 *			[3] P.J. Mohr, B.N. Taylor, D.B. Newell, Reviews of Mod. Phys. 84, 1527-1605, 2012.
 *
 *  \author Austin Ladshaw
 *	\date 09/04/2018
 *	\copyright This software was designed and built at the Georgia Institute
 *             of Technology by Austin Ladshaw for research in the area
 *             of radioactive particle decay. Copyright (c) 2018, all
 *             rights reserved.
 */

#ifndef IBIS_HPP_
#define IBIS_HPP_

#include "eel.h"
#include "yaml_wrapper.h"
#include "dove.h"
#include <unordered_map>

/// Function returns the order of magnitude for the parameter x
/** This function is used to help create initial guesses for the new GSTA parameters
	that are being optimized for. In order to make sure that those parameters are
	considered relavent in the optimization routine, we need to make the initial
	guesses to be around the same order of magnitude of the other GSTA parameters. */
int orderMag(double x);

/// Enumeration for the list of valid decay modes
/** List of valid types of radioactive decay. The type of decay dictates
	how the Isotope object will transform the given isotope. */
typedef enum {alpha, beta_min, beta_plus, stable, spon_fiss, iso_trans, neutron_em, proton_em,
				beta_min_neutron_em, beta_plus_neutron_em, beta_plus_alpha, beta_plus_beta_plus,
				beta_min_beta_min, beta_min_2neutron_em, beta_min_alpha, proton_em_proton_em,
				neutron_em_neutron_em, beta_min_3neutron_em, beta_min_4neutron_em, beta_plus_2proton_em,
				beta_plus_3proton_em, specific_isotope, beta_plus_proton_em, undefined} decay_mode;

/// Enumeration for the list of valid units of half-life
/** List of valid units for half-lifes for better readability of code.*/
typedef enum {seconds, minutes, hours, days, years} time_units;

/// Function to convert from a starting unit and value to and ending unit and value (returns converted value)
double time_conversion(time_units end_unit, double start_value, time_units start_unit);

/// Function to determine what type of time units are used based on given string argument
time_units timeunits_choice(std::string &choice);

/// Function to determine the decay mode based on given string
decay_mode decaymode_choice(std::string &choice);

/// Function to return a string for the name of a decay mode given the enum
std::string decaymode_string(decay_mode mode);

/// Function to return a string for the units
std::string timeunits_string(time_units units);

/// Empirical formulation of the Fermi Function
double EmpFermi(int z, double W);

/// Empirical formulation of the Shape Function
double EmpShape(int L, double W0, double W);

/// Distribution of beta energy function
double DistEnergy(int z, int L, double W0, double W);

/// Stepwise integration for average energy
double MeanEnergy_Stepwise(int z, int L, double E0);

/// Auxillary Function for beta-
double aux_beta_minus(double beta, double eta, double tau);

/// Auxillary Function for beta+
double aux_beta_plus(double beta, double eta, double tau);

/// Mean Excitation energy (in eV)
double mean_excitation_energy(int atom_num);

/// Stopping power for beta minus
double stopping_power_beta_minus(double mean_energy, int Zj, double Aj, double delta);

/// Stopping power for beta plus
double stopping_power_beta_plus(double mean_energy, int Zj, double Aj, double delta);

/// Stopping power for non-beta
double stopping_power_nonbeta(double mean_energy, int Zj, double Aj, double delta, double charge);

/// Mean path length for beta (cm)
double mean_path_beta(double mean_energy, double density);

/// Mean path length for non-beta (cm)
double mean_path_nonbeta(double mean_energy);

/// Isotope object to hold information and provide decay operations
/** This is the C++ object to store information and functions associated with the
	decay of radioactive isotopes. It herits from the Atom object and extends that
	object to include information such as decay constants, branching ratios, and
	decay modes. It can be used to determine branching paths and setup systems of
	equations involving decay products. */
class Isotope : Atom
{
public:
    Isotope();											///< Default constructor
    ~Isotope();											///< Default destructor
    
    void loadNuclides(yaml_cpp_class &data);			///< Function to load the nuclide library into the pointer
    void unloadNuclides();								///< Delete the pointer to nuclide library to free space
    void clearChain();									///< Delete the chain for this isotope to free space
    int registerIsotope(std::string isotope_name);		///< Register an isotope given the isotope name (e.g., H-2)
    int registerIsotope(std::string symbol, int iso);	///< Register an isotope given an atomic symbol (e.g., H) and isotope number (e.g., 2)
    int registerIsotope(int atom_num, int iso_num);		///< Register an isotope given both an atomic and isotope number (e.g., H-2 = 1, 2)
    
    void DisplayInfo();									///< Print out isotope information to the console
    void DisplayChain();								///< Print out chain information to the console
    void createChain();									///< Function to create and fill in the chain of nuclides for this starting isotope
    
    void setInitialCondition(double ic);				///< Set the value for the initial condition of this nuclide
    void setConcentration(double c);					///< Set the concentration value for the nuclide
    void setActivity(double a);                         ///< Set the activity value for the nuclide
    void setUnits2Moles(bool opt);                      ///< Set concentration units to moles if True is passed
    void setWarnings(bool opt);							///< Set the warnings boolean value
    void setThreshold(double val);						///< Set the threshold value for half-life (in sec)
    void updateDecayRate();								///< Increase decay rate by 1% (used to correct issues with same eigenvalues)
    
    /// Calculate the ionization coefficient given a list of atoms and their mass fractions in a particular media
    /** This function uses the Linear Energy Transfer function to calculate the average ionization potential
    	of this nuclide decaying in a media made up of the given set of atoms and their respective mass
     fractions. The result is stored in the ionization_coeff parameter and can be accessed via the
     IonizationCoeff() return function. As the density and/or mass fraction of the media changes, this
     function needs to be re-called to update that ionization coefficient.
     
     \param atoms reference to a list of atoms in the media
     \param mass_fracs reference to a list of mass fractions for the list of atoms
     \param density density of the media in g/cm^3
     \param potential ionization potential of the media in eV*/
    int calculateIonization(std::vector<Atom> &atoms, std::vector<double> &mass_fracs, double density, double potential);
    
    int IsotopeNumber();								///< Return the isotope number of the atom (i.e., mass number)
    double DecayRate();									///< Return the decay rate of the isotope
    double HalfLife(time_units units);					///< Return the half-life in the given units
    time_units HalfLifeUnits();							///< Return the half-life units
    std::string IsotopeName();							///< Return the name of the isotope
    bool isStable();									///< Return stability condition
    bool isIsomericState();								///< Return isomeric condition
    bool isMolar();                                     ///< Returns True if concentration units are moles
    int DecayModes();									///< Return the number of decay modes
    double getInitialCondition();						///< Return the value of the initial condition
    double getConcentration();							///< Return the concentration value of the nuclide
    double getActivity();                               ///< Return the activity value of the nuclide
    double AtomicWeight();								///< Return the atomic weight of the isotope
    double MeltingPoint();								///< Returns the melting point
    double BoilingPoint();								///< Returns the boiling point
    double ThermalXSection();							///< Returns the thermal cross section
    double ScatterXSection();							///< Returns the scattering cross section
    double MassExcess();								///< Returns the mass-excess of the nuclide (in MeV)
    double Jpi();										///< Returns the magnitude of the spin-parity
    double IonizationCoeff();							///< Returns the average number of ion pairs produced from this nuclide decay
    
    decay_mode DecayMode(int i);						///< Return the ith decay mode
    double BranchFraction(int i);						///< Return the ith branch fraction
    std::string ParticleEmitted(int i);					///< Return the name of the particle emitted for the ith decay mode
    int NumberParticlesEmitted(int i);					///< Return the number of particles that get emitted
    std::string Daughter(int i);						///< Return the name of the daughter isotope
    double QValue(int i);								///< Return the ith Q-value (in MeV)
    int deltaJ(int i);									///< Return the ith spin jump
    double MeanEnergy(int i);							///< Return the ith mean radiation energy (in MeV)
    
    /// Return a list of indices of the decay modes that this daughter isotope is formed from given the parent isotope's name
    /** This function will iterate through the decay modes for the parent isotope we are investigating and return a
     list of indices that represent the modes of decay that form this isotope from the given parent. If the mode
     does not form this isotope, then it will have an index of -1. The size of the vector on return will equal
     the size of the list of decay modes for the parent. If the parent is invalid, then it will return a vector
     of size 0. If the parent does not form this isotope, then all indices will be -1. */
    std::vector<int> DaughterIndices(std::string parent);
    
    /// Return a list of indices of the decay modes that this particle emission is formed from given the parent isotope's name
    /** This function will iterate through the decay modes for the parent isotope we are investigating and return a
     list of indices that represent the modes of decay that form this isotope from the given parent. If the mode
     does not form this isotope, then it will have an index of -1. The size of the vector on return will equal
     the size of the list of decay modes for the parent. If the parent is invalid, then it will return a vector
     of size 0. If the parent does not form this isotope, then all indices will be -1. */
    std::vector<int> EmissionIndices(std::string parent);
    
protected:
    std::string IsoName;								///< Name of the isotope (e.g., H-2)
    std::vector<decay_mode> decay_modes;				///< List of decay modes the given isotope can undergo
    std::vector<double> branch_ratios;					///< Branching ratios for each possible decay mode
    std::vector<std::string> particle_emitted;			///< Name of the particle(s) ejected during spec_iso decay
    std::vector<int> num_particles;						///< Numbers of particles emitted during decay mode
    std::vector<std::string> daughter;					///< Name of the daughter isotope formed
    std::vector<double> Q_values;						///< Q-value (or maximum radiation energy) of the decay mode (in MeV)
    std::vector<double> mean_radiation_energy;			///< Mean radiation energy of the decay modes (calculated in MeV)
    std::vector<int> spin_jump;							///< Magnitude of change in spin from parent to daughter
    
    /// List of all parent and daughter/particles pairs in a chain given this isotope
    /** Stores the list of parent and daughter pairs. If the parent produces emitted particles, those go
     in this list as well. If the parent produces more than one daughter, all those daughters go in the
     list as well.
     
     chain[i] = contains lists of parent daughter pairs at the ith level of the chain
     chain[i][j] = contains the jth pair at the ith level
     chain[i][j].first = contains the name of the parent
     chain[i][j].second = contains the name of the daughter/particle emitted
     
     Example:
     --------
     
     Levels:							A			A = Principal Parent
     -------						   / \
     level 0:					  B   C			B = 1st Daughter (pair A/B), C = 1st particle emission (pair A/C)
     / \   \
     level 1:                    D   E   F       D = 1st Daugher of 1st Daughter, E = 2nd Daughter of 1st Daughter, F = Stable Daughter
     / |   | \
     level 2:                 G  H   I  J		So on and so forth...
     
     */
    std::vector< std::vector< std::pair<std::string,std::string> > > chain;
    
    double decay_rate;									///< Rate of decay for the given isotope (1/s)
    double half_life;									///< Half-life of the isotope (in hl_units)
    time_units hl_units;								///< Units given for the half-life
    double hl_threshold;								///< Half-life value (in seconds) at which 99% of isotope has been converted
    int isotope_number;									///< isotope number for the object (i.e., mass number)
    bool Stable;										///< Boolean is True if isotope is stable
    bool IsomericState;									///< Boolean is True if isotope is in an isomeric state
    double initial_condition;							///< Value to hold initial condition for this nuclide (moles or atoms)
    double concentration;								///< Value to hold concentration after a point in time (moles or atoms)
    bool Warnings;										///< Boolean is True if you want to print warnings to console
    bool inMoles;                                       ///< Boolean is True if units of concentration are in moles, False if units in atoms
    double activity;                                    ///< Radioactivity of the current nuclide (in disintigrations per second) or (Bq)
    double mass_excess;									///< Mass excess of the nuclide (in MeV)
    double spin_parity;									///< Magnitude of the spin parity of the nuclide
    double ionization_coeff;							///< Average number of ion pairs produced per decay of this nuclide
    
    yaml_cpp_class *nuclides;							///< Pointer to a yaml object storing the digital library of all nuclides
    
    int setConstants();									///< Set the decay_modes, branch_ratios, and other info based on load library
    int calculateMeanEnergies();						///< Calculate the mean radiation energies for the isotope
    void computeDecayRate();							///< Compute the decay rate (in 1/s) based on the half-life
    int addPairs(int i, std::string parent);			///< Function to add parent/daughter pairs given the parent's name and the current level
    YamlWrapper& getNuclideLibrary();					///< Return reference to the nuclide library
    
private:
    
};

/// DecayChain object to hold and store a set of unique isotopes in a branched decay chain
/** C++ style object that will contain a list of unique nuclides that can be used to numerically
	solve a decay chain system. User will provide a list of initial nuclides present and this
	object will then use that information to build the list of all possible nuclides that can
	be formed. One of the key features of this object is that the nuclide list will be unique
	(i.e., no duplicate nuclides) so that we can iterate through that list to apply the branch
	fractions and decay constants to solve the fractionation as a function of time.
 
	First, create chains of isotope from the initial nuclides given. Then, reduce chains to remove
	redundant isotopes and order the isotopes in final_nuc list to ensure that only the highest
	mass number isotopes are listed first. Lastly, fill out the parents and branches lists to
	allow for direct access to all necessary decay information to speed up computation and
	evaluation of the chains. */
class DecayChain
{
public:
    DecayChain();											///< Default constructor
    ~DecayChain();											///< Default destructor
    
    void DisplayList();										///< Display list of nuclides to console
    void DisplayStableList();								///< Display list of stable nuclides to the console
    void DisplayInfo();										///< Display final nuclides and their parents and branches
    void DisplayStableInfo();								///< Display stable nuclides and their direct parents and branches
    void DisplayMap();										///< Display the coefficient map to the console
    void DisplayEigenMap();									///< Display the eigenvector map to the console
    
    void loadNuclides(yaml_cpp_class &data);				///< Function to load the nuclide library into the pointer
    void unloadNuclides();									///< Delete the pointer to nuclide library to free space
    
    int registerInitialNuclide(std::string isotope_name);	///< Register an initial nuclide by name (e.g., H-2)
    int registerInitialNuclide(std::string symb, int iso);	///< Register an initial nuclide by symbol (e.g., H) and isotope number (e.g., 2)
    int registerInitialNuclide(int atom_num, int iso_num);	///< Register an initial nuclide by atomic and mass numbers (e.g., H-2 = 1, 2)
    
    /// NOTE: The below functions will register isotopes with their initial conditions as well
    int registerInitialNuclide(std::string isotope_name, double ic);///< Register an initial nuclide by name (e.g., H-2)
    int registerInitialNuclide(std::string symb, int iso, double ic);///< Register an initial nuclide by symbol (e.g., H) and iso number (e.g., 2)
    int registerInitialNuclide(int atom_num, int iso_num, double ic);///< Register an initial nuclide by atomic and mass numbers (e.g., H-2 = 1, 2)
    
    void setWarnings(bool opt);								///< Set the warnings boolean value
    void setConsoleOut(bool opt);							///< Set the ConsoleOut boolean value
    void setThreshold(double val);						///< Set the threshold value for half-life (in sec)
    void createChains();									///< Function to create unique list of final nuclides from decay chains of initial
    void formEigenvectors();								///< Function to produce eigenvectors from coefficient matrix
    int verifyEigenSoln();									///< Function will verify that the eigenvectors and eigenvalues are correct
    
    /// Function to calculate the isotope fractionation given a time t in seconds
    /** This function must be called after createChains() and after formEigenvectors().
     It will use the eigenvector solution to estimate the isotope concentrations for
     each isotope in the chain at the given time t. Those concentrations are based on
     values given for the initial concentrations of each isotope and are stored in
     each isotope object as the current concentration value.
     
     Use an analytical solution based on linear combinations of eigenvectors. */
    void calculateFractionation(double t);
    
    /// Calculate the ionization rate given a list of atoms and their mass fractions in a particular media
    /** This function uses the Linear Energy Transfer function to calculate the average ionization potential
    	of this nuclide decaying in a media made up of the given set of atoms and their respective mass
     fractions. The result is stored in the ionization_coeff parameter and can be accessed via the
     IonizationCoeff() return function. As the density and/or mass fraction of the media changes, this
     function needs to be re-called to update that ionization rate.
     
     \param atoms reference to a list of atoms in the media
     \param mass_fracs reference to a list of mass fractions for the list of atoms
     \param density density of the media in g/cm^3
     \param potential ionization potential of the media in eV*/
    void calculateIonizationRate(std::vector<Atom> &atoms, std::vector<double> &mass_fracs, double density, double potential);
    
    /// Function to print results to file based on end_time and number of points
    /** This function will open an output file named IBIS_Results.txt and print the
     simulation results to that file starting from time = 0 s to end_time in (s).
     The integer 'points' is used to determine how many points at which the
     calculation of fractionation will take place. The output file will be opened
     and closed within this function so the user is not responsible for keeping
     track of the file. All output is printed to the 'output/' folder from the
     working directory. */
    void print_results(FILE *file, time_units units, double end_time, int points);
    
    int read_conditions(yaml_cpp_class &yaml);						///< Read the Runtime conditions for the simulation case
    int read_isotopes(yaml_cpp_class &yaml);						///< Read the Isotope conditions for the simulation case
    int run_simulation(std::string file_name);						///< Runs the simulation set up by the input files
    
    double returnUnstableFractionation(int i, double t);			///< Return the fractionation of the ith unstable nuclide
    double returnStableFractionation(int i, double t);				///< Return the fractionation of the ith stable nuclide
    double returnFractionation(std::string iso_name, double t);		///< Return the fractionation of the given nuclide
    
    int getNumberNuclides();								///< Return the number of nuclides in the decay chain
    int getNumberStableNuclides();							///< Return the number of stable nuclides
    double getIonizationRate();								///< Return the stored ionization rate (in ion-pairs/second)
    int getIsotopeIndex(std::string iso_name);				///< Return the unstable isotope index that corresponds to the given name
    int getStableIsotopeIndex(std::string iso_name);		///< Return the stable isotope index that corresponds to the given name
    std::vector<int>& getParentList(int i);					///< Return the vector list of parents for the ith isotope in the nuclide list
    std::vector<int>& getStableParentList(int i);			///< Return the vector list of parents for the ith stable isotope
    std::vector<int>& getBranchList(int i, int j);			///< Return the vector list of branch fractions for the jth parent of the ith nuclide
    std::vector<int>& getStableBranchList(int i, int j);	///< Return the list of branch fractions for the jth parent of the ith stable nuclide
    Isotope& getIsotope(int i);								///< Return the ith isotope in the nuclide list
    Isotope& getStableIsotope(int i);						///< Return the ith stable isotope
    Isotope& getIsotope(std::string iso_name);				///< Return the isotope (Stable or Unstable) that corresponds to the given name
    
protected:
    yaml_cpp_class *nuclides;								///< Pointer to a yaml object storing the digital library of all nuclides
    void roughInsertSort(Isotope iso);						///< Insert an isotope to the initial nuclide list and sort according to isotope number
    void finalSort();										///< Sort the list of nuclides after creating the chains
    
    /// Return a sorted list of isotopes given reference to another list
    /** All isotopes in the list given will have the same isotope number, so we are
     sorting the list based on partents and daughters. */
    std::vector<Isotope> sameIsoNumSort(std::vector<Isotope> &list);
    
    void fillOutBranchData();								///< Function to fill out all branching data and parent indices
    
    void fillOutCoefMap();									///< Function to fill out all coefficients in the map
    
    int time_steps;										///< Integer option to hold number of time steps to simulate
    double end_time;									///< Time at which to end decay simulations
    time_units t_units;									///< Units of time for which the end time is given
    bool VerifyEigen;									///< Boolean option to check eigenvector solution
    bool PrintChain;									///< Boolean option to print decay chain data to output file
    bool PrintResults;									///< Boolean option to print simulation results to output file
    bool PrintSparsity;									///< Boolean option to print sparsity pattern to output file
    bool Warnings;										///< Boolean is True if you want to print warnings to console
    double avg_eig_error;								///< Stores the average error in eigen solution
    double hl_threshold;								///< Half-life value (in seconds) at which 99% of isotope has been converted
    bool ConsoleOut;									///< Boolean is True if you want to print console messages
    double ionization_rate;								///< Total number of ion-pairs produced per second from this decay chain
    
private:
    std::vector<Isotope> nuc_list;							///< List of (ith) nuclides that make up the decay chain
    std::unordered_map< std::string, int> nuc_map;			///< Map of unstable nuclides by isotope name (maps to index in nuc_list)
    std::vector<Isotope> stable_list;						///< List of (ith) stable nuclides that terminate decay chains
    std::unordered_map< std::string, int> stable_map;		///< Map of stable nuclides by isotope name (maps to index in stable_list)
    
    /// List of the indices that each isotope has from the nuc_list
    /** List of indices for all parents of an isotope in the list of all isotopes.
     
     parents[i] = list of parent indices for the ith isotope
     parents[i][j] = jth parent index of the ith isotope */
    std::vector< std::vector<int> > parents;
    
    /// List of the indices for all branches of a parent to an isotope in nuc_list
    /** List of indices for direct access to necessary information to develop the chain scheme.
     
     branches[i] = list of a list of all branch indices (by parent) for ith isotope
     branches[i][j] = list of all branches that contribute to formation of ith isotope by jth parent
     branches[i][j][k] = kth branch index for the jth parent that forms the ith isotope */
    std::vector< std::vector< std::vector<int> > > branches;
    
    std::vector< std::map<int, double> > CoefMap;				///< Coefficient Map for matrix representing the ODE system
    
    /// List of the indices that each stable isotope has from the stable_list
    /** List of indices for all parents of a stable isotope in the list of all isotopes.
     
     stable_parents[i] = list of parent indices for the ith isotope
     stable_parents[i][j] = jth parent index of the ith isotope */
    std::vector< std::vector<int> > stable_parents;
    
    /// List of the indices for all branches of a parent to a stable isotope in stable_list
    /** List of indices for direct access to necessary information to develop the chain scheme.
     
     stable_branches[i] = list of a list of all branch indices (by parent) for ith isotope
     stable_branches[i][j] = list of all branches that contribute to formation of ith isotope by jth parent
     stable_branches[i][j][k] = kth branch index for the jth parent that forms the ith isotope */
    std::vector< std::vector< std::vector<int> > > stable_branches;
    
    std::vector< std::map<int, double> > stable_CoefMap;		///< Coefficient Map for matrix representing the ODE system for stable isotopes
    
    std::vector< std::map<int, double> > EigenMap;				///< Map for all eigenvalues (row x column)
    
};

/// IBIS Executable given an input file
/** Main IBIS executable from the ecosystem cli. User must provide a yaml-style input file directing
	all simulation, isotope, and runtime options. See example yaml-style input file below.
 
	Input file has a Runtime block and an Isotopes block. The Runtime block is used to direct the
	type of simulation to be run, what time units to use, and what information to print to the
	output file. If print_results is false, then the simulations are not carried out for the
	isotope fractionation. If verify is false, then IBIS will skip the verification of the eigen
	solution.
 
	The Isotopes block is where you provide the inital conditions for a starting set of isotopes.
	Each sub-block in Isotopes must be the name of an isotope registered in the Nuclide library. 
	Currently, initial conditions for isotopes can only be given in moles of isotopes.
 
	Yaml Input File Example
	-----------------------
 
	Runtime:
	---
	time_units: seconds
	end_time: 3600
	time_steps: 10
 
	verify: true
	print_sparsity: true
	print_chain: true
	print_results: false
	...
 
	Isotopes:
	---
	- U-235:
 initial_cond: 90
 
	- U-238:
 initial_cond: 10
	...
 
 */
int IBIS_SCENARIO(const char *yaml_input);

///< Function to test the implementation of Isotope 
int IBIS_TESTS();

#endif /* IBIS_HPP_ */
