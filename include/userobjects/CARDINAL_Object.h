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

#pragma once

#include "GeneralUserObject.h"
#include "cardinal.h"

/// CARDINAL_Object class object forward declaration
class CARDINAL_Object;

template <>
InputParameters validParams<CARDINAL_Object>();

/// CARDINAL_Object class object inherits from GeneralUserObject
/** This class object inherits from the GeneralUserObject.
	All public and protected members of this class are required function overrides.
	The initialization step will read input and simulate cloud rise to serve as initial
	conditions for FENNEC transport simulations. Execution and finalize steps will not
	be utilized here. */
class CARDINAL_Object : public GeneralUserObject
{
public:
	/// Required constructor for GeneralUserObjects in MOOSE
	CARDINAL_Object(const InputParameters & parameters);
	
	/// Required initialization override for GeneralUserObjects in MOOSE
	/** This is called before execute so you can reset any internal data. */
	virtual void initialize() override;
	
	/// Required execution override for GeneralUserObjects in MOOSE
	/** Called on every "object" (like every element or node). */
	virtual void execute() override;
	
	/// Required finalize override for GeneralUserObjects in MOOSE
	/** Called _once_ after execute has been called all "objects". */
	virtual void finalize() override;
    
    // -------- const functions below are to grab specific info from CARDINAL --------
    
    /// Function to get the number of parcels
    int return_num_parcels() const;
    
    /// Function to get the number of size bins
    int return_size_bins() const;
    
    /// Function to get the number of nuclide bins
    int return_nuc_bins() const;
    
    /// Function to return the boolean argument for the mono/bi-variate options
    bool isMonoVariate() const;
    
    /// Function to get the top of the parcel
    Real return_parcel_alt_top(int par, int bin) const;
    
    /// Function to get the bottom of the parcel
    Real return_parcel_alt_bot(int par, int bin) const;
    
    /// Function to get the top radius of the parcel
    Real return_parcel_rad_top(int par, int bin) const;
    
    /// Function to get the bottom radius of the parcel
    Real return_parcel_rad_bot(int par, int bin) const;
    
    /// Function to get the parcel concentration
    Real return_parcel_conc(int par, int bin) const;
    
    /// Function to get the parcel volume
    Real return_parcel_vol(int par, int bin) const;
    
    /// Function to get the diameter of the given particle bin
    Real return_diameter(int bin) const;
    
    /// Function to get the nuclide density of bivariate bins
    Real return_bivar_nuclides(int bin) const;
    
    /// Function to get the nuclide density of monovariate bins
    Real return_monovar_nuclides(int bin) const;
    
    /// Function to get the activity of nuclides in the given bin
    Real return_activity(int bin) const;
    
    /// Function to get the decay chain of nuclides in the given bin (use this to compute ionization rates in other kernels)
    FissionProducts return_decay_chain(int bin) const;
    
protected:
    Cardinal cardinal;					///< Cardinal Object from utils folder
	std::string _input_file;			///< Location and name of the input file for CARDINAL
    std::string _atm_file;				///< Location and name of the atmospheric data file for CARDINAL
    std::string _data_path;				///< Path of the database files for CARDINAL
    bool _mono_variate_model;			///< Boolean to determine whether or not we consider a mono- or bi-variate population
    
    /// Variables associated with parcel sub-divisions of the debris cloud
    int _num_parcels;
    int _num_size_bins;
    int _num_nuc_bins;
    std::vector< std::vector<Real> > _parcel_alt_top; 	//m
    std::vector< std::vector<Real> > _parcel_alt_bot; 	//m
    std::vector< std::vector<Real> > _parcel_rad_top; 	//m
    std::vector< std::vector<Real> > _parcel_rad_bot; 	//m
    std::vector< std::vector<Real> > _parcel_conc;		//Gp/m^3
    std::vector< std::vector<Real> > _parcel_vol;		//m^3
    
    Real _total_nuclides;								//moles - Total amount of all nuclides produced
    Real _total_initial_debris;							//GGp - Total number of debris particles (billions of billions)
    Real _avg_nuclide_density;							//moles/GGp - Total nuclides divided by total particles
    Real _total_solids_volume;							//um^3 - Total solid volume of all debris particles
    Real _avg_nuc_per_solid_vol;						//moles/um^3 - Average nuclides per solid volume of particles
    std::vector<Real> _total_nuclides_per_bin;			//moles - Total amount of nuclides in each particle size bin
    std::vector<Real> _total_debris_per_bin;			//GGp - Total number of debris particles in each size bin
    std::vector<Real> _bivariate_nuclide_density;		//moles/GGp - Nuclides per GGp for each size bin (bivariate model)
    std::vector<Real> _monovariate_nuclide_density;		//moles/GGp - Nuclides per GGp for each size bin (monovariate model)
    std::vector<Real> _diameters;						//um - Diameters of debris particles in each size bin
    std::vector<Real> _activity;						//Bq/GGp - Radioactivity of nuclides on particles for each size bin
    
    std::vector<FissionProducts> _decay_chain;			//List of decay chains on each particle size bin
    
private:
	
};

