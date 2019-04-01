/*!
 *  \file mola.h mola.cpp
 *	\brief Molecule Object Library from Atoms
 *	\details This file contains a C++ Class for creating Molecule objects from the
 *			Atom objects that were defined in eel.h. Molecules can be created and
 *			registered from basic information or can be registered from a growing
 *			list of pre-registered molecules that are accessible by name/formula.
 *
 *			Registered Molecules are are known and defined prior to runtime. They
 *			have a charge, energy characteristics, phase, name, and formula that they
 *			are recongized by. The formula is used to create the atoms that they are
 *			made from. If some information is incomplete, it must be specified as to
 *			what information is missing (i.e. denote whether the formation energies are
 *			known).
 *
 *			Formation energies are used to determine stability/dissociation/acidity
 *			equilibrium constants during runtime. If the formation energies are unknown,
 *			then the equilibrium constants must be given to a reaction object on when it
 *			is initialized.
 *
 *			The molecule formula's are given as strings which are parsed in the constructor
 *			to determine what atoms from the EEL files will be registered and used. Note,
 *			you will be able to build molecules from an input file, but the library molecules
 *			here are ready to be used in applications and require no more input other that
 *			the molecule's formula.
 *
 *			List of Currently Registered Molecules
 *			--------------------------------------
 *			Ag (s) \n
 *			Ag + (aq) \n
 *			AgBr (s) \n
 *			AgCl (s) \n
 *			AgI (s) \n
 *			Ag2S (s) \n
 *			AgOH (aq) \n
 *			Ag(OH)2 - (aq) \n
 *			AgCl (aq) \n
 *			AgCl2 - (aq) \n
 *			Al (s) \n
 *			Al 3+ (aq) \n
 *			AlOH 2+ (aq) \n
 *			Al(OH)2 + (aq) \n
 *			Al(OH)3 (aq) \n
 *			Al(OH)4 - (aq) \n
 *			Al2O3 (s) \n
 *			AlOOH (s) \n
 *			Al(OH)3 (s) \n
 *			Al2Si2(OH)4 (s) \n
 *			As (s) \n
 *			AsO4 3- (aq) \n
 *			
 *			Ba 2+ (aq) \n
 *			BaSO4 (s) \n
 *			BaCO3 (s) \n
 *			Be 2+ (aq) \n
 *			Be(OH)2 (s) \n
 *			Be3(OH)3 3+ (aq) \n
 *			B(OH)4 - (aq) \n
 *			Br2 (l) \n
 *			Br2 (aq) \n
 *			Br - (aq) \n
 *			BrO - (aq) \n
 *
 *			CO3 2- (aq) \n
 *			Cl - (aq) \n
 *			CaCl2 (aq) \n
 *			CaAl2Si2O8 (s) \n
 *			C (s) \n
 *			CO2 (g) \n
 *			CH4 (g) \n
 *			CH4 (aq) \n
 *			CH3OH (aq) \n
 *			CN - (aq) \n
 *			CH3COOH (aq) \n
 *			CH3COO - (aq) \n
 *			C2H5OH (aq) \n
 *			Ca 2+ (aq) \n
 *			CaOH + (aq) \n
 *			Ca(OH)2 (aq) \n
 *			Ca(OH)2 (s) \n
 *			CaCO3 (s) \n
 *			CaMg(CO3)2 (s) \n
 *			CaSiO3 (s) \n
 *			CaSO4 (s) \n
 *			CaSO4(H2O)2 (s) \n
 *			Ca5(PO4)3OH (s) \n
 *			Cd 2+ (aq) \n
 *			Cd(OH) + (aq) \n
 *			Cd(OH)3 - (aq) \n
 *			Cd(OH)4 2- (aq) \n
 *			Cd(OH)2 (aq) \n
 *			CdO (s) \n
 *			Cd(OH)2 (s) \n
 *			CdCl + (aq) \n
 *			CdCl2 (aq) \n
 *			CdCl3 - (aq) \n
 *			CdCO3 (s) \n
 *			Cl2 (g) \n
 *			Cl2 (aq) \n
 *			ClO - (aq) \n
 *			ClO2 (aq) \n
 *			ClO2 - (aq) \n
 *			ClO3 - (aq) \n
 *			ClO4 (aq) \n
 *			Co (s) \n
 *			Co 2+ (aq) \n
 *			Co 3+ (aq) \n
 *			CoOH + (aq) \n
 *			Co(OH)2 (aq) \n
 *			Co(OH)3 - (aq) \n
 *			Co(OH)2 (s) \n
 *			CoO (s) \n
 *			Co3O4 (s) \n
 *			Cr (s) \n
 *			Cr 2+ (aq) \n
 *			Cr 3+ (aq) \n
 *			CrOH 2+ (aq) \n
 *			Cr(OH)2 + (aq) \n
 *			Cr(OH)3 (aq) \n
 *			Cr(OH)4 - (aq) \n
 *			Cr2O3 (s) \n
 *			CrO4 2- (aq) \n
 *			Cr2O7 2- (aq) \n
 *			Cu (s) \n
 *			Cu + (aq) \n
 *			Cu 2+ (aq) \n
 *			CuOH + (aq) \n
 *			Cu(OH)2 (aq) \n
 *			Cu(OH)3 - (aq) \n
 *			Cu(OH)4 2- (aq) \n
 *			CuS (s) \n
 *			Cu2S (s) \n
 *			CuO (s) \n
 *			CuCO3Cu(OH)2 (s) \n
 *			(CuCO3)2Cu(OH)2 (s) \n
 *			
 *			F2 (g) \n
 *			F - (aq) \n
 *			Fe (s) \n
 *			Fe 2+ (aq) \n
 *			FeOH + (aq) \n
 *			Fe(OH)2 (aq) \n
 *			Fe(OH)3 - (aq) \n
 *			Fe 3+ (aq) \n
 *			FeOH 2+ (aq) \n
 *			Fe(OH)2 + (aq) \n
 *			Fe(OH)3 (aq) \n
 *			Fe(OH)4 - (aq) \n
 *			Fe2(OH)2 4+ (aq) \n
 *			FeS2 (s) \n
 *			FeO (s) \n
 *			Fe(OH)2 (s) \n
 *			Fe2O3 (s) \n
 *			Fe3O4 (s) \n
 *			FeOOH (s) \n
 *			Fe(OH)3 (s) \n
 *			FeCO3 (s) \n
 *			Fe2SiO4 (s) \n
 *
 *			H2O (l) \n
 *			H + (aq) \n
 *			H2CO3 (aq) \n
 *			HCO3 - (aq) \n
 *			HNO3 (aq) \n
 *			HCl (aq) \n
 *			H3AsO4 (aq) \n
 *			H2AsO4 - (aq) \n
 *			HAsO4 2- (aq) \n
 *			H2AsO3 - (aq) \n
 *			H3BO3 (aq) \n
 *			HBrO (aq) \n
 *			HCOOH (aq) \n
 *			HCOO - (aq) \n
 *			HCN (aq) \n
 *			HClO (aq) \n
 *			HCoO2 - (aq) \n
 *			HCrO4 - (aq) \n
 *			HCuO2 - (aq) \n
 *			HF (aq) \n
 *			HF2 - (aq) \n
 *			H2 (g) \n
 *			H2 (aq) \n
 *			H2O2 (aq) \n
 *			HO2 - (aq) \n
 *			H2O (g) \n
 *			Hg (l) \n
 *			Hg2 2+ (aq) \n
 *			Hg 2+ (aq) \n
 *			HgOH + (aq) \n
 *			Hg(OH)2 (aq) \n
 *			Hg(OH)3 - (aq) \n
 *			Hg2Cl2 (s) \n
 *			HgO (s) \n
 *			HgS (s) \n
 *			HgI2 (s) \n
 *			HgCl + (aq) \n
 *			HgCl2 (aq) \n
 *			HgCl3 - (aq) \n
 *			HgCl4 2- (aq) \n
 *			HgOH + (aq) \n
 *			Hg(OH)2 (aq) \n
 *			HgO2 - (aq) \n
 *			HIO (aq) \n
 *			HIO3 (aq) \n
 *			HNO2 (aq) \n
 *			HPO4 2- (aq) \n
 *			H2PO4 - (aq) \n
 *			H3PO4 (aq) \n
 *			H2S (g) \n
 *			H2S (aq) \n
 *			HS - (aq) \n
 *			HSO3 - (aq) \n
 *			H2SO3 (aq) \n
 *			HSO4 - (aq) \n
 *			H2SO4 (aq) \n
 *			HSeO3 - (aq) \n
 *			H2SeO3 (aq) \n
 *			HSeO4 - (aq) \n
 *			H4SiO4 (aq) \n
 *			HV2O5 - (aq) \n
 *			H4VO4 + (aq) \n
 *			H3VO4 (aq) \n
 *			H2VO4 - (aq) \n
 *			HVO4 2- (aq) \n
 *			H4VO4(C2O4)2 3- (aq) \n
 *			H4VO4C2O4 - (aq) \n
 *			H2V10O28 4- (aq) \n
 *			HV10O28 5- (aq) \n
 *			HV2O7 3- (aq) \n
 *			
 *			I2 (s) \n
 *			I2 (aq) \n
 *			I - (aq) \n
 *			I3 - (aq) \n
 *			IO - (aq) \n
 *			IO3 - (aq) \n
 *
 *			KAl3Si3O10(OH)2 (s) \n
 *			K + (aq) \n
 *
 *			Mg(OH)2 (aq) \n
 *			Mg5Al2Si3O10(OH)8 (s) \n
 *			Mg (s) \n
 *			Mg 2+ (aq) \n
 *			MgOH + (aq) \n
 *			Mg(OH)2 (s) \n
 *			Mn (s) \n
 *			Mn 2+ (aq) \n
 *			Mn(OH)2 (s) \n
 *			Mn3O4 (s) \n
 *			MnOOH (s) \n
 *			MnO2 (s) \n
 *			MnCO3 (s) \n
 *			MnS (s) \n
 *			MnSiO3 (s) \n
 *
 *			NaHCO3 (aq) \n
 *			NaCO3 - (aq) \n
 *			Na + (aq) \n
 *			NaCl (aq) \n
 *			NaOH (aq) \n
 *			NO3 - (aq) \n
 *			NH3 (aq) \n
 *			NaAlSiO3O8 (s) \n
 *			NH2CH2COOH (aq) \n
 *			NH2CH2COO - (aq) \n
 *			N2 (g) \n
 *			N2O (g) \n
 *			NH3 (g) \n
 *			NH4 + (aq) \n
 *			NO2 - (aq) \n
 *			Ni 2+ (aq) \n
 *			NiOH + (aq) \n
 *			Ni(OH)2 (aq) \n
 *			Ni(OH)3 - (aq) \n
 *			NiO (s) \n
 *			NiS (s) \n
 *
 *			OH - (aq) \n
 *			O2 (g) \n
 *			O2 (aq) \n
 *			O3 (g) \n
 *
 *			P (s) \n
 *			PO4 3- (aq) \n
 *			Pb (s) \n
 *			Pb 2+ (aq) \n
 *			PbOH + (aq) \n
 *			Pb(OH)2 (aq) \n
 *			Pb(OH)3 - (aq) \n
 *			Pb(OH)4 2- (aq) \n
 *			Pb(OH)2 (s) \n
 *			PbO (s) \n
 *			PbO2 (s) \n
 *			Pb3O4 (s) \n
 *			PbS (s) \n
 *			PbSO4 (s) \n
 *			PbCO3 (s) \n
 *			
 *			S (s) \n
 *			SO2 (g) \n
 *			SO3 (g) \n
 *			S 2- (aq) \n
 *			SO3 2- (aq) \n
 *			SO4 2- (aq) \n
 *			Se (s) \n
 *			SeO3 2- (aq) \n
 *			SeO4 2- (aq) \n
 *			Si (s) \n
 *			SiO2 (s) \n
 *			Sr 2+ (aq) \n
 *			SrOH + (aq) \n
 *			SrCO3 (s) \n
 *			SrSO4 (s) \n
 *
 *			UO2 2+ (aq) \n
 *			UO2NO3 + (aq) \n
 *			UO2(NO3)2 (aq) \n
 *			UO2OH + (aq) \n
 *			UO2(OH)2 (aq) \n
 *			UO2(OH)3 - (aq) \n
 *			UO2(OH)4 2- (aq) \n
 *			(UO2)2OH 3+ (aq) \n
 *			(UO2)2(OH)2 2+ (aq) \n
 *			(UO2)3(OH)4 2+ (aq) \n
 *			(UO2)3(OH)5 + (aq) \n
 *			(UO2)3(OH)7 - (aq) \n
 *			(UO2)4(OH)7 + (aq) \n
 *			UO2CO3 (aq) \n
 *			UO2(CO3)2 2- (aq) \n
 *			UO2(CO3)3 4- (aq) \n
 *			UO2Cl + (aq) \n
 *			UO2Cl2 (aq) \n
 *			UO2Cl3 - (aq) \n
 *			UO2SO4 (aq) \n
 *			UO2(SO4)2 2- (aq) \n
 *
 *			VO 2+ (aq) \n
 *			VOOH + (aq) \n
 *			VO(OH)2 (s) \n
 *			V2O4 (s) \n
 *			(VO)2(OH)2 + (aq) \n
 *			VOF + (aq) \n
 *			VOF2 (aq) \n
 *			VOF3 - (aq) \n
 *			VOF4 2- (aq) \n
 *			VOCl + (aq) \n
 *			VOSO4 (aq) \n
 *			VO(C2O4)2 2- (aq) \n
 *			VOOHC2O4 - (aq) \n
 *			VOCH3COO + (aq) \n
 *			VO(CH3COO)2 (aq) \n
 *			VOCO3 (aq) \n
 *			VOOHCO3 - (aq) \n
 *			V4O9 2- (aq) \n
 *			VO2 + (aq) \n
 *			VO4 3- (aq) \n
 *			V2O5 (s) \n
 *			V10O28 6- (aq) \n
 *			V2O7 4- (aq) \n
 *			V4O12 4- (aq) \n
 *			VO2SO4 - (aq) \n
 *			VO2OHCO3 2- (aq) \n
 *			VO2(CO3)2 3- (aq) \n
 *
 *			Zn (s) \n
 *			Zn 2+ (aq) \n
 *			ZnOH + (aq) \n
 *			Zn(OH)2 (aq) \n
 *			Zn(OH)3 - (aq) \n
 *			Zn(OH)4 2- (aq) \n
 *			Zn(OH)2 (s) \n
 *			ZnCl + (aq) \n
 *			ZnCl2 (aq) \n
 *			ZnCl3 - (aq) \n
 *			ZnCl4 2- (aq) \n
 *			ZnCO3 (s) \n
 *
 *			Those registered molecules follow a strict naming convention by which they
 *			can be recognized (see below)...
 *
 *			Naming Convention
 *			-----------------
 *			Plus (+) and minus (-) charges are denoted by the numeric value of the charge
 *			followed by a + or - sign, respectively ( e.g. UO2(CO3)3 4- (aq) )
 *
 *			The phase is always denoted last and will be marked as (l) for
 *			liquid, (s) for solid, (aq) for aqueous, and (g) for gas (see above).
 *
 *			When registering a molecule that is not in the library, you must
 *			also provide a linear formula during construction or registration.
 *			This is needed so that the string parsing is easier to handle when the
 *			molecule subsequently registers the necessary atoms. (e.g. UO2(CO3)3 =
 *			UO2C3O9 or UO11C3).
 *
 *  \author Austin Ladshaw
 *	\date 02/24/2014
 *	\copyright This software was designed and built at the Georgia Institute
 *             of Technology by Austin Ladshaw for PhD research in the area
 *             of adsorption and surface science. Copyright (c) 2015, all
 *             rights reserved.
 */

#ifndef MOLA_HPP_
#define MOLA_HPP_

#include <ctype.h>
#include "eel.h"

#ifndef M_PI
#define M_PI 3.14159
#endif

#ifndef SphereVolume
#define SphereVolume(r) ((4.0/3.0)*M_PI*r*r*r)
#endif

#ifndef SphereArea
#define SphereArea(r) (4.0*M_PI*r*r)
#endif

typedef enum {SOLID, LIQUID, AQUEOUS, GAS, PLASMA, ADSORBED, OTHER} valid_phase;

/// C++ Molecule Object built from Atom Objects (click Molecule to go to function definitions)
/** C++ Class Object that stores information and certain operations associated with molecules.
	Registered molecules are built up from their respective atoms so that the molecule can keep
	track of information such as molecular weigth and oxidation states. Primarily, this object
	is used in conjunction with shark.h to formulate the system of equations necessary for solving
	speciation type problems in aqueous systems. However, this object is generalized enough to be
	of use in RedOx calculations, reaction formulation, and molecular transformations.
 
	All information for a molecule should be initialized prior to performing operations with or 
	on the object. There are several molecules already defined for construction by the formulas
	listed at the top of this section. */
class Molecule
{
public:
	Molecule();								///< Default Constructor (builds an empty molecule object)
	~Molecule();							///< Default Destructor (clears out memory)
	
	/// Construct any molecule from the available information
	/** This constructor will build a user defined custom molecule. 
	 
		\param charge the ionic charge of the molecule
		\param enthalpy the standard formation enthalpy of the molecule (J/mol)
		\param entropy the standard formation entropy of the molecule (J/K/mol)
		\param energy the standard Gibb's Free Energy of formation of the molecule (J/mol)
		\param HS boolean to be set to true if enthalpy and entropy were given
		\param G boolean to be set to true if the energy was given
		\param Phase string denoting molecule's phase (i.e., Liquid, Aqueous, Gas, Solid)
		\param Name string denoting the common name of the molecule (i.e., H2O -> Water)
		\param Formula string denoting the formula by which the molecule is referened (i.e., Cl - (aq))
		\param lin_formula string denoting all the atoms in the molecule (i.e., UO2(OH)2 -> UO4H2)*/
	Molecule(int charge,
			 double enthalpy,
			 double entropy,
			 double energy,
			 bool HS,
			 bool G,
			 std::string Phase,
			 std::string Name,
			 std::string Formula,
			 std::string lin_formula);
	
	/// Function to register this molecule from the available information
	/** This function will build a user defined custom molecule.
	 
		\param charge the ionic charge of the molecule
		\param enthalpy the standard formation enthalpy of the molecule (J/mol)
		\param entropy the standard formation entropy of the molecule (J/K/mol)
		\param energy the standard Gibb's Free Energy of formation of the molecule (J/mol)
		\param HS boolean to be set to true if enthalpy and entropy were given
		\param G boolean to be set to true if the energy was given
		\param Phase string denoting molecule's phase (i.e., Liquid, Aqueous, Gas, Solid)
		\param Name string denoting the common name of the molecule (i.e., H2O -> Water)
		\param Formula string denoting the formula by which the molecule is referened (i.e., Cl - (aq))
		\param lin_formula string denoting all the atoms in the molecule (i.e., UO2(OH)2 -> UO4H2)*/
	void Register(int charge,
				  double enthalpy,
				  double entropy,
				  double energy,
				  bool HS,
				  bool G,
				  std::string Phase,
				  std::string Name,
				  std::string Formula,
				  std::string lin_formula);
	
	/// Function to register this molecule based on the given formula (if formula is in library)
	/** This function will create this molecule object from the given formula, but only if that
		formula is already registered in the library. See the top of this class section for a 
		list of all currently registered formulas. */
	
	/** \note The formula is checked against a known set of molecules inside of the registration function
	*	If the formula is unknown, an error will print to the screen. Unknown molecules should be registered
	*	using the full registration function from above. The library can only be added to by a going in and
	*	editing the source code of the mola.cpp file. However, this is a relatively simple task.
	*/
	void Register(std::string formula);
	
	void setFormula(std::string form);				///< Sets the formula for a molecule
	void calculateMolarWeight();					///< Forces molecule to calculate its molar weight
	void calculateMolarVolume();					///< Force molecule to calculate van der Waals volume
	void calculateMolarArea();						///< Force molecule to calculate van der Waals area
	void setMolarWeigth(double mw);					///< Set the molar weight of species to a constant
	void setMolarVolume(double v);					///< Set the van der Waals volume of the species to a constant
	void setMolarArea(double a);					///< Set the van der Waals area of the species to a constant
	void editCharge(int c);							///< Change the ionic charge of a molecule
	
	/// Change oxidation state of one of the given atoms (always first match found)
	/** This function will search the list of Atoms that make up the Molecule for the given
		atomic Symbol. It will change the oxidation state of the first found matching atom with
		the given state. */
	void editOneOxidationState(int state,
							   std::string Symbol);
	
	/// Change oxidation state of all of the given atoms
	/** This function will search the list of Atoms that make up the Molecule for the given
		atomic Symbol. It will change the oxidation state of all found matching atoms with
		the given state. */
	void editAllOxidationStates(int state,
								std::string Symbol);
	
	/// Function to calculate the average oxidation state of the atoms
	/** This function search the atoms in the molecule for the matching atomic Symbol. It
		then looks at all oxidation states of that atom in the molecule and then sets all 
		the oxidation states of that atom to the average value calculated. */
	void calculateAvgOxiState(std::string Symbol);
	
	void editEnthalpy(double enthalpy);				///< Edit the molecules formation enthalpy (J/mol)
	void editEntropy(double entropy);				///< Edit the molecules formation entropy (J/K/mol)
	
	/// Edit both formation enthalpy and entropy
	/** This function will change or set the values for formation enthalpy (J/mol) and
		formation entropy (J/K/mol) based on the given values.
		
		\param H formation enthalpy (J/mol)
		\param S formation entropy (J/K/mol)*/
	void editHS(double H, double S);
	
	void editEnergy(double energy);					///< Edit Gibb's formation energy
	
	void removeOneAtom(std::string Symbol);			///< Removes one atom of the symbol given (always the first atom found)
	void removeAllAtoms(std::string Symbol);		///< Removes all atoms of the symbol given
	
	int Charge();							///< Return the charge of the molecule
	double MolarWeight();					///< Return the molar weight of the molecule
	double MolarVolume();					///< Return the van der Waals volume of the molecule
	double MolarArea();						///< Return the van der Waals area of the molecule
	bool HaveHS();							///< Returns true if enthalpy and entropy are known
	bool HaveEnergy();						///< Returns true if the Gibb's energy is known
	bool isRegistered();					///< Returns true if the molecule has been registered
	double Enthalpy();						///< Return the formation enthalpy of the molecule
	double Entropy();						///< Return the formation entropy of the molecule
	double Energy();						///< Return the Gibb's formation energy of the molecule
	std::string MoleculeName();				///< Return the common name of the molecule
	std::string MolecularFormula();			///< Return the molecular formula of the molecule
	std::string MoleculePhase();			///< Return the phase of the molecule
	int MoleculePhaseID();					///< Return the enum phase ID of the molecule
	std::vector<Atom> & getAtoms();			///< Return reference to the vector of atoms
	
	void DisplayInfo();						///< Function to display molecule information
	
protected:
	int charge;								///< Ionic charge of the molecule - specified
	double molar_weight;					///< Molar weight of the molecule (g/mol) - determined from atoms or specified
	double molar_volume;					///< van der Waals Volume of the molecule (cubic angstroms) - determined from atoms or specified
	double molar_area;						///< van der Waals Area of the molecule (square angstroms) - determined from atoms or specified
	double formation_enthalpy;				///< Enthalpy of formation of the molecule (J/mol) - constant
	double formation_entropy;				///< Entropy of formation of the molecule (J/K/mol) - constant
	double formation_energy;				///< Gibb's energy of formation (J/mol) - given
	
	std::string Phase;						///< Phase of the molecule (i.e. Solid, Liquid, Aqueous, Gas...)
	int PhaseID;							///< Phase ID of the molecule (from the enum)
	std::vector<Atom> atoms;				///< Atoms which make up the molecule - based on Formula
	
private:
	std::string Name;						///< Name of the Molecule - Common Name (i.e. H2O = Water)
	std::string Formula;					///< Formula for the molecule - specified (i.e. H2O)
	bool haveG;								///< True = given Gibb's energy of formation
	bool haveHS;							///< True = give enthalpy and entropy of formation
	bool registered;						///< True = the object was registered
	
};

/// Function to run the MOLA tests
/** This function is callable from the UI and is used to run several
	algorithm tests for the Molecule objects. This test should never
	report any errors. */
int MOLA_TESTS();

#endif
