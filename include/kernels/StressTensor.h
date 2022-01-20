/*!
 *  \file StressTensor.h
 *	\brief Kernel used to integrate a Stress Tensor into conservation of momentum
 *	\details This file creates a standard MOOSE kernel that is to be used in with other conservation of 
 *			momentum kernels. Momentum conservation couples velocity terms together in Cartesian coordinates.
 *
 *  \author Austin Ladshaw
 *	\date 07/09/2018
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

/// StressTensor class object forward declarations
class StressTensor;

/// StressTensor class object inherits from Kernel object
/** This class object inherits from the Kernel object in the MOOSE framework.
	All public and protected members of this class are required function overrides.
*/
class StressTensor : public Kernel
{
public:
    /// Static Member Function for Input Parameters
    static InputParameters validParams();
    
    /// Required constructor for objects in MOOSE
	StressTensor(const InputParameters & parameters);
	
protected:
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
	
	const VariableGradient & _ux_grad;			///< Velocity gradient for d(ux)/dx
	const VariableGradient & _uy_grad;			///< Velocity gradient for d(uy)/dy
	const VariableGradient & _uz_grad;			///< Velocity gradient for d(uz)/dz
	
	const VariableValue & _viscosity;			///< Viscosity of the fluid
	
	unsigned int _dir;							///< Direction variable for direction this kernel acts on (0=x, 1=y, 2=z)
	
	const unsigned int _ux_var;					///< Variable identification for ux
	const unsigned int _uy_var;					///< Variable identification for uy
	const unsigned int _uz_var;					///< Variable identification for uz
	const unsigned int _vis_var;				///< Variable identification for viscosity
	
private:
	
};

