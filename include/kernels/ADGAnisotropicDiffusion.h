/*!
 *  \file ADGAnisotropicDiffusion.C
 *	\brief ADKernel for use with the corresponding ADDGAnisotropicDiffusion object
 *	\details This file creates a MOOSE ADKernel that is to be used in conjunction with the ADDGAnisotropicDiffusion 
 *			 kernel	for the discontinous Galerkin formulation of advection physics in MOOSE. In order to complete the DG
 *			formulation of the advective physics, this kernel must be utilized with every variable that also uses
 *			the ADDGAAnisotropicDiffusion kernel.
 *
 *  \author Alexander Wiechert
 *	\date 01/25/2022
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

#include "ADKernel.h"

/// GAnisotropicDiffusion class object forward declarations
class ADGAnisotropicDiffusion;

/// ADGAnisotropicDiffusion class object inherits from ADKernel object
/** This class object inherits from the ADKernel object in the MOOSE framework.
	All public and protected members of this class are required function overrides.
	The kernel has a diffusion tensor whose components can be set piecewise in an
	input file.
 
	\note To create a specific ADGAnisotropicDiffusion kernel, inherit from this class and override
	the components of the diffusion tensor, then call the residual and Jacobian functions
	for this object. */

class ADGAnisotropicDiffusion : public ADKernel
{
public:
    /// Static Member Function for Input Parameters
    static InputParameters validParams();
    
    /// Required constructor for objects in MOOSE
	ADGAnisotropicDiffusion(const InputParameters & parameters);
	
protected:
	/// Required residual function for standard kernels in MOOSE
	/** This function returns a residual contribution for this object.*/
	virtual ADReal computeQpResidual() override;
	
	RealTensorValue _Diffusion;			///< Diffusion tensor matrix parameter
	
	Real _Dxx, _Dxy, _Dxz;
	Real _Dyx, _Dyy, _Dyz;
	Real _Dzx, _Dzy, _Dzz;
	
private:
	
};

