/*!
 *  \file fairy.h fairy.cpp
 *	\brief Fission-products from Atomic Incident and their Respective Yields
 *	\details This file contains a C++ object for determining fission products and
 *			their yields from some nuclear event based on: (i) type of fission,
 *			either neutron-induced or spontaneous, (ii) energy level of neutron
 *			source or bomb yield, (iii) extent of fission, and (iv) initial mass
 *			and composition of fuel or bomb materials. Data for fission products
 *			comes from ENDF-6 data libraries that were read with a python script
 *			and output into a yaml format (see 'scripts/fission-product-yields').
 *
 *  \author Austin Ladshaw
 *	\date 12/07/2018
 *	\copyright This software was designed and built at the Georgia Institute
 *             of Technology by Austin Ladshaw for research in the area
 *             of radioactive particle decay and transport. Copyright (c) 2018, 
 *				all rights reserved.
 */

#ifndef FAIRY_HPP_
#define FAIRY_HPP_

#include "ibis.h"

/// Enumeration for Fission Product Yield Type
typedef enum {neutron, spontaneous, explosion} fiss_type;

/// Function to determine the fission type based on given string
fiss_type fisstype_choice(std::string &choice);

/// FissionProducts class object to create decay chains from fission yields
/** This object inherits from DecayChain and will formulate decay chains based on starting weapon or
	fuel materials, as well as the type of fission taking place and the extent of fission for a given
	mass of the starting material. Fission Product Yields (FPYs) are based on the Evaluated Nuclear 
	Data Format (ENDF) libraries, which contain FPYs for a number of fuel and weapon materials at
	various energy levels for two different types of fission: (i) neutron-induced and (ii) spontaneous.
	*/
class FissionProducts : DecayChain
{
public:
	FissionProducts();								///< Default Constructor
	~FissionProducts();								///< Default Destructor
	
	void DisplayInfo();								///< Display the FAIRY information, initial materials and fractions
	void DisplayMap();								///< Display the map for the DecayChain object
	
	void loadNuclides(yaml_cpp_class &data);		///< Function to load the nuclide library into the pointer
	void unloadNuclides();							///< Delete the pointer to nuclide library to free space
	
	int registerInitialNuclide(std::string isotope_name);	///< Register an initial nuclide by name (e.g., H-2)
	int registerInitialNuclide(std::string symb, int iso);	///< Register an initial nuclide by symbol (e.g., H) and isotope number (e.g., 2)
	int registerInitialNuclide(int atom_num, int iso_num);	///< Register an initial nuclide by atomic and mass numbers (e.g., H-2 = 1, 2)
	
	/// NOTE: The below functions will register isotopes with their initial conditions as well
	int registerInitialNuclide(std::string isotope_name, double ic);///< Register an initial nuclide by name (e.g., H-2)
	int registerInitialNuclide(std::string symb, int iso, double ic);///< Register an initial nuclide by symbol (e.g., H) and iso number (e.g., 2)
	int registerInitialNuclide(int atom_num, int iso_num, double ic);///< Register an initial nuclide by atomic and mass numbers (e.g., H-2 = 1, 2)
	
	std::string fileFissionProductYields();			///< Function to read in the library and put into the Yaml object
	void loadFissionProductYields(yaml_cpp_class & data);	///< Function to load the fission product library into the Yaml object
	void unloadFissionProductYields();				///< Function to delete the items in the Yaml object
	
	void setFissionType(fiss_type opt);				///< Set the fission type for the Fission Products
	void setTotalMass(double mass);					///< Set the total mass of fissible materials (kg)
	void setFissionExtent(double per);				///< Set the extent of fission parameter (%)
	void setEnergyLevel(double el);					///< Set the energy level for neutron source (eV)
	void setThreshold(double val);					///< Set the threshold value for half-life (in sec)
	
	/// Automatically sets the threshold value given time (in sec) after detonation and percent conversion rate (default 99%)
	void timeSinceDetonation(double time, double per);
	
	void setTimeUnits(time_units units);			///< Set the time units for the simulation
	void setEndTime(double end);					///< Set the end time for the simulation (in choosen units)
	void setTimeSteps(int steps);					///< Set the number of time steps to simulate
	void setVerifySoln(bool opt);					///< Set boolean to verify eigen solution
	void setPrintSparsity(bool opt);				///< Set boolean to print sparsity on output
	void setPrintChain(bool opt);					///< Set boolean to print chain info
	void setPrintResults(bool opt);					///< Set boolean to print results of simulation
	void setConsoleOut(bool opt);					///< Set boolean to print output to console
    
    double getTotalMoles();                         ///< Return total moles of weapon
    double getFissionExtent();                      ///< Return the % of fission extent
	bool isConsoleOut();							///< Return boolean option for console output
	
	std::vector<Isotope> & getWeaponMat();			///< Return reference to vector of isotopes in weapon
	std::vector<double> & getWeaponFrac();			///< Return reference to vector of molefractions of weapon isotopes
	
	int run_simulation(std::string file_name);		///< Run a decay simulation from Fission Products
	
	int print_yields();								///< Print yield data for weapon or fuel to output file 
	
	/// NOTE: For each of the below functions, you must first call the loadNuclides function
	void addIsotopeMaterial(std::string iso, double percent);				///< Add an isotope for the fissible material (checks string value)
	void addIsotopeMaterial(std::string sym, int iso_num, double percent);	///< Add an isotope for the fissible material (by symbol and mass num)
	void addIsotopeMaterial(int atom_num, int iso_num, double percent);		///< Add an isotope for the fissible material (by atom num and mass num)
	
	void checkFractions();							///< Check fractions of materials in fuel/weapone and correct if necessary
	int evaluateYields();							///< Read yield data and set isotope fractionation based on yields
	void evaluateEigenSolution();					///< Take the initialized yield info and form the eigenvectors
	int verifyEigenSoln();							///< Function will verify that the eigenvectors and eigenvalues are correct
	
	/// Function to calculate the isotope fractionation given a time t in seconds
	/** This function must be called after createChains() and after formEigenvectors().
		It will use the eigenvector solution to estimate the isotope concentrations for
		each isotope in the chain at the given time t. Those concentrations are based on
		values given for the initial concentrations of each isotope and are stored in
		each isotope object as the current concentration value.
	 
		Use an analytical solution based on linear combinations of eigenvectors. */
	void calculateFractionation(double t);
	double returnFractionation(std::string iso_name, double t);		///< Return the fractionation of the given nuclide
	
	int getNumberNuclides();								///< Return the number of nuclides in the decay chain
	int getNumberStableNuclides();							///< Return the number of stable nuclides
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
	fiss_type type;								///< Type of fission products to be produced
	std::vector<Isotope> InitialMat;			///< Initial materials/isotopes to undergoe fission (Conc. in moles)
	std::vector<double> MatFrac;				///< Material fractionation of the initial material (%)
	std::map<int, double> Yields;				///< Map of fission yields of material based on atomic mass
	double total_mass;							///< Total mass of the weapon or fuel rod (kg)
    double total_moles;                         ///< Total moles of fissionable materials (mol)
	double fiss_extent;							///< Percentage of the starting material that undergoes fission (%)
	double energy_level;						///< Energy level of neutron source (eV)
	yaml_cpp_class *fpy_data;					///< Yaml object to read and store the FPY library files
	
private:
	
};

/// Test function for FAIRY
int FAIRY_TESTS();

#endif /* FAIRY_HPP_ */
