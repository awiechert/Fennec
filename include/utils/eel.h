/*!
 *  \file eel.h eel.cpp
 *	\brief Easy-access Element Library
 *	\details This file contains two C++ objects: (i) Atom and (ii) PeriodicTable. 
 
			The Atom class defines all relavent information necessary for dealing with actual 
			atoms. However, this is not necessarilly all the information that one may need for 
			any simulation dealing with atoms. Instead, it is really just a place holder used 
			to construct Molecules and hold oxidation state and molecular/atomic wieght information.
 
			The PeriodicTable class creates a digital version of a complete periodic table. Further
			development of this object can make it possible to query this structure for a particular
			atom upon user request.
 
 *	\warning The Atom class is mostly complete, but the PeriodicTable object is just a place holder.
 *  \author Austin Ladshaw
 *	\date 02/23/2015
 *	\copyright This software was designed and built at the Georgia Institute
 *             of Technology by Austin Ladshaw for PhD research in the area
 *             of adsorption and surface science. Copyright (c) 2015, all
 *             rights reserved.
 */

#ifndef EEL_HPP_
#define EEL_HPP_

#include <stdio.h>				// Line to allow cout functionality
#include <math.h>               // Line added to allow usage of the pow (e, x) function
#include <iostream>				// Line to allow for read/write to the console using cpp functions
#include <fstream>				// Line to allow for read/write to and from .txt files
#include <stdlib.h>				// Line need to convert strings to doubles
#include <vector>				// Line needed to use dynamic arrays called vectors
#include <time.h>				// Line needed to display program runtime
#include <float.h>				// Line to allow use of machine precision constants
#include <string>				// Line to allow use of strings as a data type
#include "error.h"				// Line to allow use of the custom error file

/// Atom object to hold information about specific atoms in the periodic table (click Atom to go to function definitions)
/** C++ class object holding data and functions associated with atoms. Objects can be 
	registered at the time of object construction, or after declaring an Atom object.
	Registration can be done via the atomic symbol or atomic number. Valid atoms go 
	from Hydrogen (1) to Oganesson (118). */
class Atom
{
public:
	Atom();									///< Default Constructor
	~Atom();								///< Default Destructor
	
	void Register(std::string Symbol);		///< Register an atom object by symbol
	void Register(int number);				///< Register an atom object by number
	
	void editAtomicWeight(double AW);		///< Manually changes the atomic weight
	void editOxidationState(int state);		///< Manually changes the oxidation state
	void editProtons(int proton);			///< Manually changes the number of protons
	void editNeutrons(int neutron);			///< Manually changes the number of neutrons
	void editElectrons(int electron);		///< Manually changes the number of electrons
	void editValence(int val);				///< Manually changes the number of valence electrons
	void editRadii(double r);				///< Manually changes the van der Waals radii
	void editMeltingPoint(double val);		///< Manually changes the melting point
	void editBoilingPoint(double val);		///< Manually changes the boiling point
	void editThermalXSection(double val);	///< Manually changes the thermal cross section
	void editScatterXSection(double val);	///< Manually changes the scattering cross section
	
	void removeProton();					///< Manually removes 1 proton and adjusts weight
	void removeNeutron();					///< Manually removes 1 neutron and adjusts weight
	void removeElectron();					///< Manually removes 1 electron from valence
	
	double AtomicWeight();					///< Returns the current atomic weight (g/mol)
	int OxidationState();					///< Returns the current oxidation state
	int Protons();							///< Returns the current number of protons
	int Neutrons();							///< Returns the current number of neutrons
	int Electrons();						///< Returns the current number of electrons
	int BondingElectrons();					///< Returns the number of electrons available for bonding
	double AtomicRadii();					///< Returns the current van der Waals radii (in angstroms)
	double MeltingPoint();					///< Returns the melting point
	double BoilingPoint();					///< Returns the boiling point
	double ThermalXSection();				///< Returns the thermal cross section
	double ScatterXSection();				///< Returns the scattering cross section
	
	std::string AtomName();					///< Returns the name of the atom
	std::string AtomSymbol();				///< Returns the symbol of the atom
	std::string AtomCategory();				///< Returns the category of the atom
	std::string AtomState();				///< Returns the state of the atom
	int AtomicNumber();						///< Returns the atomic number of the atom
	
	void DisplayInfo();						///< Displays Atom information to console
	
protected:
	double atomic_weight;					///< Holds the atomic weight of the atom
	int oxidation_state;					///< Holds the oxidation state of the atom
	int protons;							///< Holds the number of protons in the atom
	int neutrons;							///< Holds the number of neutrons in the atom
	int electrons;							///< Holds the number of electrons in the atom
	int valence_e;							///< Holds the number of valence electrons in the atom
	double atomic_radii;					///< Holds the van der Waals radii of the element (in angstroms)
	double melting_point;					///< Holds the melting point of the element (in K)
	double boiling_point;					///< Holds the boiling point of the element (in K)
	double thermal_x_sec;					///< Holds the thermal neutron cross section of the element (in barns)
	double scatter_x_sec;					///< Holds the scattering neutron cross section of the element (in barns)
	std::string Name;						///< Holds the name of the atom
	std::string Symbol;						///< Holds the atomic symbol for the atom
	std::string Category;					///< Holds the category of the atom (e.g., Alkali Metal)
	std::string NaturalState;				///< Holds the natural state of the atom (e.g., Gas)
	int atomic_number;						///< Holds the atomic number of the atom
	
private:
	
};

/// Class object that store a digitial copy of all Atom objects
/** C++ class object to hold digitally registered Atom objects. All registered atoms (Hydrogen
	to Ununoctium) are stored as in a vector. Currently, this object is unused, but could be 
	modified to be explorable and used as a constant referece for all atoms in the table. */
class PeriodicTable
{
public:
	PeriodicTable();								///< Default Constructor - Build Perodic Table
	~PeriodicTable();								///< Default Destructor - Destroy the table
	PeriodicTable(int *n, int N);					///< Construct a partial table from a list of atomic numbers
	PeriodicTable(std::vector<std::string> &Symbol);///< Construct a partial table from a vector of atom symbols
	PeriodicTable(std::vector<int> &n);				///< Construct a partial table from a vector of atomic numbers
	
	void DisplayTable();							///< Displays the periodic table via symbols
	
protected:
	std::vector<Atom> Table;						///< Storage vector for all atoms in the table
	
private:
	int number_elements;							///< Number of atom objects being stored
	
};

/// Test function to exercise the class objects and check for errors
int EEL_TESTS();

#endif
