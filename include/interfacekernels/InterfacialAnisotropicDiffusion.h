/*!
 *  \file InterfacialAnisotropicDiffusion.h
 *	\brief Interface Kernel for Anisotropic Diffusion between domains
 *	\details This file creates a MOOSE interface kernel for anisotropic
 *			 diffusion across a designated mesh boundary from one subdomain
 *           and into another. Based on the DGAnisotropicDiffusion Kernel.
 *
 *  \author Alexander Wiechert
 *	\date 08/27/2021
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

#include "InterfaceKernel.h"
#include "MooseVariable.h"
#include <cmath>

/// DGAnisotropicDiffusion class object forward declarations
class InterfacialAnisotropicDiffusion;

/// InterfacialAnisotropicDiffusion class object inherits from InterfaceKernel object
/** This class object inherits from the InterfaceKernel object in the MOOSE framework.
	All public and protected members of this class are required function overrides. The object
	will provide residuals and Jacobians for the discontinous Galerkin formulation of advection
	physics in the MOOSE framework. The only parameter for this kernel is a diffusion tensor, 
	whose components can be set piecewise in the input file or by inheriting from this base class 
	and manually altering the tensor matrix.
*/

class InterfacialAnisotropicDiffusion : public InterfaceKernel
{
public:
    /// Static Member Function for Input Parameters
    static InputParameters validParams();
    
    /// Required constructor for objects in MOOSE
	InterfacialAnisotropicDiffusion(const InputParameters & parameters);
	
protected:
	/// Required residual function for Interface kernels in MOOSE
	/** This function returns a residual contribution for this object.*/
	virtual Real computeQpResidual(Moose::DGResidualType type) override;
	/// Required Jacobian function for Interface kernels in MOOSE
	/** This function returns a Jacobian contribution for this object. The Jacobian being
		computed is the associated diagonal element in the overall Jacobian matrix for the
		system and is used in preconditioning of the linear sub-problem. */
	virtual Real computeQpJacobian(Moose::DGJacobianType type) override;
	
	Real _epsilon;						///< Penalty term for gradient jumps between the solution and test functions
	Real _sigma;						///< Penalty term applied to element size
	RealTensorValue _Diffusion;			///< Diffusion tensor matrix parameter
	
	Real _Dxx, _Dxy, _Dxz;
	Real _Dyx, _Dyy, _Dyz;
	Real _Dzx, _Dzy, _Dzz;
	
private:
	
};

