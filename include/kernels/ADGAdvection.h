/*!
 *  \file ADGAdvection.h
 *	\brief ADKernel for use with the corresponding ADDGAdvection object
 *	\details This file creates an ADKernel that is to be used in conjunction with ADDGAdvection for the
 *			 discontinous Galerkin formulation of momentum advection in MOOSE. In order to complete the DG
 *			 formulation of the advective physics, this ADKernel must be utilized with every variable that
 *			 also uses the ADDGAdvection kernel.
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

/// ADAdvection class object forward declarations
class ADGAdvection;

/// ADAdvection class object inherits from ADKernel object
/** This class object inherits from the ADKernel object in the MOOSE framework.
	All public and protected members of this class are required function overrides.
	The kernel has a velocity vector whose components can be set piecewise in an
	input file.
 
	\note To create a specific GAdvection kernel, inherit from this class and override
	the components of the velocity vector, then call the residual and Jacobian functions
	for this object. */

class ADGAdvection : public ADKernel
{
public:
    /// Static Member Function for Input Parameters
    static InputParameters validParams();
    
    /// Required constructor for objects in MOOSE
	ADGAdvection(const InputParameters & parameters);
	
protected:
	/// Required residual function for standard kernels in MOOSE
	/** This function returns a residual contribution for this object.*/
	virtual ADReal computeQpResidual() override;
    
    ADRealVectorValue _velocity;	///< Vector of velocity
    
	const ADVariableValue & _ux;			///< Velocity in the x-direction
	const ADVariableValue & _uy;			///< Velocity in the y-direction
	const ADVariableValue & _uz;			///< Velocity in the z-direction
	
private:
	
};

