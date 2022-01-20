/*!
 *  \file ConstMonoPB.h
 *	\brief Kernel for Mono-variate Population Balance Model with constant coefficients
 *	\details This file creates a MOOSE kernel that will couple together multiple number 
 *			concentrations of particles and calculate a population balance rate function
 *			assuming the collision efficiency and frequency are known constants. This module
 *			is based on the following works:
 *
 *			Y.H. Kim, S. Yiacoumi, A. Nenes, C. Tsouris, J. Aero. Sci., 114, 283-300, 2017.
 *			
 *			S. Kumar, D. Ramkrishna, Chem. Eng. Sci., 51, 1311-1332, 1996.
 *
 *  \author Austin Ladshaw
 *	\date 08/02/2019
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

#include "Kernel.h"

/// ConstMonoPB class object forward declarations
class ConstMonoPB;

/// ConstMonoPB class object inherits from Kernel object
/** This class object inherits from the Kernel object in the MOOSE framework.
	All public and protected members of this class are required function overrides.
	The kernel has a set of parameters (alpha and beta) that may be computed
    by other future kernels.
 */
class ConstMonoPB : public Kernel
{
public:
    /// Static Member Function for Input Parameters
    static InputParameters validParams();
    
    /// Required constructor for objects in MOOSE
    ConstMonoPB(const InputParameters & parameters);
    
protected:
	/// Function to compute outcome of Kronecker Delta Function
    Real KroneckerDelta(int i, int j);
    
    /// Function to fill out all the alpha and beta parameters with constants
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
    
    /// Parameters for the base class are listed below
    
    unsigned int _M;										///< Number of particle size bins
    Real _const_alpha;										///< Constant value for the efficiency (-)
    Real _const_beta;										///< Constant value for the frequency (m^3/s)
    std::vector< std::vector< std::vector<Real> > > _frac;	///< Set of vector fractions based on the size classes of the variables
    std::vector< Real > _dia;								///< Set of size class diameters (m)
    std::vector< Real > _vol;								///< Set of volume based size bins (m^3) [assumes spheres]
    std::vector< std::vector< Real > > _alpha;				///< Set of collision efficiencies (-)
    std::vector< std::vector< Real > > _beta;				///< Set of collision frequencies (m^3/s)
    std::vector< std::vector< Real > > _gama;				///< Set of volume check parameters computed at initialization
    
    std::vector<const VariableValue *> _coupled_u;		///< Pointer list to the coupled number concentrations (Gp/m^3)
    std::vector<unsigned int> _coupled_u_var;			///< Indices for the number concentrations in the system
    const unsigned int _u_var;							///< Variable identification for the primary coupled variable
    unsigned int _this_var;										///< Relative Index for this non-linear variable
    std::unordered_map<unsigned int, unsigned int> _those_var;	///< Relative indices for the list of non-linear variables
    
    bool _gama_correction;								///< Boolean to specify use of gama correction term (Always true when not testing)
    
private:
    
};
