/*!
 *  \file CollisionParameters.h
 *	\brief Material properties file to compute parameters associated with the population balance model
 *	\details This file creates a MaterialProperty to calculate and store parameter information associated
 *			with the collision frequencies and collision efficiencies associated with the population
 *			balance model for radioactive debris particles. Each parameter is stored for later use in
 *			other kernels of FENNEC. The calculated parameters can be used in either the Mono- or
 *			Bi-variate forms of the population balance model. Parameters for particle diffusion are also
 *			calculated and stored so that they can be used in the dispersion transport kernels. References
 *			for the calculations and model contain herein are given below.
 *
 *			References
 *			----------
 *			[1] Y.H. Kim, S. Yiacoumi, I. Lee, J. McFarlane, C. Tsouris, Environ. Sci. Tech., 48, 182-189, 2014.
 *			[2] Y.H. Kim, S. Yiacoumi, A. Nenes, C. Tsouris, Atmos. Chem. Phys., 16, 3449-3462, 2016.
 *			[3] Y.H. Kim, S. Yiacoumi, A. Nenes, C. Tsouris, J. Aero. Sci., 114, 283-300, 2017. 
 *			[4] C.F. Clement, R.A. Clement, R.G. Harrison, J. Aero. Sci., 26, 1207-1225, 1995.
 *			[5] M.Z. Jacobson, Fundamentals of Atmospheric Modeling (2nd Ed.), Cambridge U. Press, New York, 2005.
 *			[6] R.G. Harrison, K.S. Carslaw, Review of Geophysics, 41, 2003.
 *
 *  \author Austin Ladshaw
 *	\date 09/06/2019
 *	\copyright This kernel was designed and built at the Georgia Institute
 *             of Technology by Austin Ladshaw for PhD research in the area
 *             of radioactive particle transport and settling following a
 *			   nuclear event. It was developed for the US DOD under DTRA
 *			   project No. 14-24-FRCWMD-BAA. Portions Copyright (c) 2019, all
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

#include "Material.h"
#include "CARDINAL_Object.h"

/// CollisionParameters class object forward declaration
class CollisionParameters;

template<>
InputParameters validParams<CollisionParameters>();

/// CollisionParameters class object inherits from Material object
/** This class object inherits from the Material object in the MOOSE framework.
	All public and protected members of this class are required function overrides. The object
	will set up and calculate various parameters associated with collision frequencies and
    collision efficiencies and store those values as MaterialProperties. Coupling with non-linear
    variables is carried out using old values (i.e., loose coupling) for reliable convergence
    behavior. Diffusion of each debris size class is also calculated and stored. */
class CollisionParameters : public Material
{
public:
    /// Required constructor for objects in MOOSE
    CollisionParameters(const InputParameters & parameters);
    
protected:
    /// Required function override for Material objects in MOOSE
    /** This function computes the material properties when they are needed by other MOOSE objects.*/
    virtual void computeQpProperties();
    
    /// Required function override for Stateful Material objects in MOOSE
    /** This function is needed because we have to properly initialize our custom objects without
     having to reinitialize at each compute step. It takes more memory this way, but also prevents
     segfault errors and helps the kernel run faster after initialization. */
    virtual void initQpStatefulProperties();
    
    /// Calculation of mean ion charge
    void calculate_n0();
    
    /// Calculation of thermal speed of debris particles
    void calculate_vp();
    
    /// Calculation of y parameter
    void calculate_y();
    
    /// Calculation of omega parameter
    void calculate_omega();
    
    /// Calculation of average charge parameter
    void calculate_avg_charge();
    
    /// Calculation of charge boundaries for the average charge parameter
    void calculate_charge_bounds();
    
    /// Calculation of particle diffusion
    void calculate_diffusion();
    
    /// Calculation of intermediate for Brownian frequency
    Real del(int l);
    
    /// Calculation of Brownian frequency
    void calculate_beta_Br();
    
    /// Calcualtion of the Reynolds number for Convective frequency
    Real Reynolds(int qr);
    
    /// Calculation of the Schmidt number for Convective frequency
    Real Schmidt(int lm);
    
    /// Calculation of Convective frequency
    void calculate_beta_CE();
    
    /// Calculation of relative velocity between two particles
    Real RelVel(int lm, int qr);
    
    /// Calculation of Gravitational frequency
    void calculate_beta_GC();
    
    /// Calculation of Inertial frequency
    void calculate_beta_TI();
    
    /// Calculation of Shear frequency
    void calculate_beta_TS();
    
    /// f Helper function for van der Waals frequency
    Real f_rad(Real r, int l, int q);
    
    /// g Helper function for van der Waals frequency
    Real g_rad(Real r, int l, int q);
    
private:
	const CARDINAL_Object & _user_object;			///< User object for CARDINAL simulation data/results
	std::vector<const VariableValue *> _N;			///< Pointer list for the non-linear variables for number concentrations
    const VariableValue & _air_dens;				///< Variable for the density of air (kg/m^3)  == Typical Value: 1.225 kg/m^3
    const VariableValue & _air_visc;				///< Variable for the viscosity of air (kg/m/s)== Typical Value: 1.802e-5 kg/m/s
    const VariableValue & _temp;					///< Variable for the temperature of air (K)
    const VariableValue & _ions;					///< Variable for the ionization of air (ion-pairs/m^3/s)
    
    const VariableValue & _wx;				///< Wind velocity in the x-direction (m/s)
    const VariableValue & _wy;				///< Wind velocity in the y-direction (m/s)
    const VariableValue & _wz;				///< Wind velocity in the z-direction (m/s)
    std::vector<const VariableValue *> _vx;	///< Pointer list for the non-linear variables for particle velocities in x-dir (m/s)
    std::vector<const VariableValue *> _vy;	///< Pointer list for the non-linear variables for particle velocities in y-dir (m/s)
    std::vector<const VariableValue *> _vz;	///< Pointer list for the non-linear variables for particle velocities in z-dir (m/s)

    int _size_bins;							///< Number of particle size bins to consider
    int _nuc_bins;							///< Number of nuclide bins to consider (if any)
	Real _kB;								///< Boltzmann Constant (J/K) or (m^2*kg/s^2/K)
    Real _ma;								///< Average mass of an air molecule (kg)
    Real _va;								///< Thermal air speed of a molecule (m/s)
    Real _ed;								///< Rate of dissipation of turbulent kinetic energy (m^2/s^3)
    Real _AH;								///< Hamaker constant (J) or (m^2*kg/s^2)
    Real _ec;								///< Magnitude of electronic charge (C)
    Real _e0;								///< Permittivity of free space (C/V/m)
    Real _n0;								///< Mean electric charge concentration (charges/m^3)
    Real _m_neg;							///< Mobility of negative ions (m^2/V/s)
    Real _m_pos;							///< Mobility of positive ions (m^2/V/s)
    Real _arc;								///< Ion-Ion recombination coefficient (m^3/s)
    std::vector<Real> _rad;					///< Radii for debris particles of each size class (m) ==> size = num_size_bins
    std::vector<Real> _mass;				///< Mass for debris particles of each size class (kg) ==> size = num_size_bins
    std::vector<Real> _vp;					///< Thermal speed for debris particles of each size class (m/s) ==> size = num_size_bins
    std::vector<Real> _lam;					///< Mean free path of debris particles in the air (m)
    std::vector<Real> _y;					///< y parameter for charge Gaussian ==> size = num_size_bins
    std::vector<Real> _omega;				///< omega parameter for charge Gaussian ==> size = num_size_bins
    std::vector<Real> _avg_charge;			///< average charge number for charge Gaussian ==> size = num_size_bins
    std::vector<int> _charge_lb;			///< Lower bound charge number for charge Gaussian ==> size = num_size_bins
    std::vector<int> _charge_ub;			///< Upper bound charge number for charge Gaussian ==> size = num_size_bins
    std::vector<unsigned int> _index;		///< Indices for the particle variables in the system
    
    MaterialProperty<std::map<int,int> > & _global_to_local;///< MaterialProperty for the global indices for conc variables ==> size = num_var
    MaterialProperty<std::vector<Real> > & _diffusion;	///< MaterialProperty for the particle diffusion (m^2/s) ==> size = num_var
    
    MaterialProperty<std::vector<std::vector<Real> > > & _beta_Br;	///< MaterialProperty for the Brownian frequency (m^3/s) ==> size = num_var x num_var
    MaterialProperty<std::vector<std::vector<Real> > > & _beta_CE;	///< MaterialProperty for the Convective frequency (m^3/s) ==> size = num_var x num_var
    MaterialProperty<std::vector<std::vector<Real> > > & _beta_GC;	///< MaterialProperty for the Gravitational frequency (m^3/s) ==> size = num_var x num_var
    MaterialProperty<std::vector<std::vector<Real> > > & _beta_TI;	///< MaterialProperty for the Inertial frequency (m^3/s) ==> size = num_var x num_var
    MaterialProperty<std::vector<std::vector<Real> > > & _beta_TS;	///< MaterialProperty for the Shear frequency (m^3/s) ==> size = num_var x num_var
    MaterialProperty<std::vector<std::vector<Real> > > & _beta_VW;	///< MaterialProperty for the van der Waals frequency (m^3/s) ==> size = num_var x num_var
    MaterialProperty<std::vector<std::vector<Real> > > & _alpha_Br;	///< MaterialProperty for the Brownian efficiency (-) ==> size = num_var x num_var
};
