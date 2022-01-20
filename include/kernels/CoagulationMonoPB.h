/*!
 *  \file CoagulationMonoPB.h
 *	\brief Kernel for Mono-variate Population Balance Model with all coagulation coefficients
 *	\details This file creates a MOOSE kernel that will couple together multiple number
 *			concentrations of particles and calculate a population balance rate function
 *			assuming the collision efficiency and frequency are calculated from Brownian
 *			diffusion, Brownian convection enhancement, gravitational collection, turbulent
 *			inertial motion, and turbulent shear functions.
 *
 *			Y.H. Kim, S. Yiacoumi, A. Nenes, C. Tsouris, J. Aero. Sci., 114, 283-300, 2017.
 *
 *			M.Z. Jacobson, Fundamentals of Atmospheric Modeling (2nd Ed.), Cambridge University
 *				Press, New York, 2005.
 *
 *  \author Alexander Wiechert
 *	\date 04/22/2020
 *	\copyright This kernel was designed and built at the Georgia Institute
 *             of Technology by Alexander Wiechert for research in the area
 *             of radioactive particle transport and settling following a
 *			   nuclear event. It was developed for the US DOD under DTRA
 *			   project No. 14-24-FRCWMD-BAA. Portions Copyright (c) 2018, all
 *             rights reserved.
 *
 *			   Alexander Wiechert does not claim any ownership or copyright to the
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

#include "BrownianConvecMonoPB.h"

/// CoagulationMonoPB class object forward declarations
class CoagulationMonoPB;

/// CoagulationMonoPB class object inherits from BrownianConvecMonoPB object
/** This class object inherits from the BrownianConvecMonoPB object in the MOOSE framework.
	All public and protected members of this class are required function overrides.
	The kernel has a set of parameters (alpha and beta) that may be computed
    by other future kernels.
 */
class CoagulationMonoPB : public BrownianConvecMonoPB
{
public:
    /// Static Member Function for Input Parameters
    static InputParameters validParams();
    
    /// Required constructor for objects in MOOSE
    CoagulationMonoPB(const InputParameters & parameters);
    
protected:
    /// Function to compute outcome of Kronecker Delta Function
    Real KroneckerDelta(int i, int j);
    
    /// Function to fill out all the alpha and beta parameters
    void AlphaBetaFill();
    
    /// Function to fill out all the volume size bins
    void VolumeFill();
    
    /// Function to fill out all the fraction values
    void FractionFill();
    
    /// Function to fill out all the gama values
    void GamaFill();
    
    /// Required residual function for standard kernels in MOOSE
    /** This function returns a residual contribution for this object.*/
    virtual Real computeQpResidual() override;
    
    /// Required Jacobian function for standard kernels in MOOSE
    /** This function returns a Jacobian contribution for this object. The Jacobian being
     computed is the associated diagonal element in the overall Jacobian matrix for the
     system and is used in preconditioning of the linear sub-problem. */
    virtual Real computeQpJacobian() override;
    
    /// Not Required, but aids in the preconditioning step
    /** This function returns the off diagonal Jacobian contribution for this object. By
     returning a non-zero value we will hopefully improve the convergence rate for the
     cross coupling of the variables. */
    virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;
    
    /// Parameters for the class are listed below

    Real _alpha_TI;											///< Collision efficiency for turbulent inertial motion (-)
    Real _alpha_TS;											///< Collision efficiency for turbulent shear (-)

    const MaterialProperty<std::vector<std::vector<Real> > > & _beta_GC;	///< MaterialProperty for the gravitational collection frequency (m^3/s) ==> size = num_var x num_var
    const MaterialProperty<std::vector<std::vector<Real> > > & _beta_TI;	///< MaterialProperty for the collision frequency from turbulent inertial motion (m^3/s) ==> size = num_var x num_var
    const MaterialProperty<std::vector<std::vector<Real> > > & _beta_TS;	///< MaterialProperty for the Brownian convection frequency (m^3/s) ==> size = num_var x num_var
    const MaterialProperty<std::vector<std::vector<Real> > > & _alpha_GC;	///< MaterialProperty for the gravitational collection efficiency (-) ==> size = num_var x num_var
    const MaterialProperty<std::vector<std::vector<Real> > > & _beta_VW;	///< MaterialProperty for the Brownian frequency (m^3/s) ==> size = num_var x num_var
    
private:
    
};
