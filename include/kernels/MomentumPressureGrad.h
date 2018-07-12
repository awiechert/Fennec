/*!
 *  \file MomentumPressureGrad.h
 *	\brief Kernel to couple a pressure gradient to a momentum conservation equation
 *	\details This file creates a standard MOOSE kernel that is to be used to coupled a pressure gradient
 *			to the conservation of momentum equation for fluid flow in a particular direction (x, y, z). 
 *			The direction on which this kernel acts must be explicitly given to know which component of 
 *			the pressure gradient to use. Also, this kernel will act on a velocity variable in that
 *			direction, but not use that variable directly. Thus, the Jacobian will return zero, but the
 *			off-diagonal Jacobian will be non-zero.
 *
 *  \author Austin Ladshaw
 *	\date 07/12/2018
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

#ifndef MOMENTUMPRESSUREGRAD_H
#define MOMENTUMPRESSUREGRAD_H

#include "Kernel.h"

/// MomentumPressureGrad class object forward declarations
class MomentumPressureGrad;

template<>
InputParameters validParams<MomentumPressureGrad>();

/// MomentumPressureGrad class object inherits from Kernel object
/** This class object inherits from the Kernel object in the MOOSE framework.
	All public and protected members of this class are required function overrides.
	The kernel couples a pressure gradient variable to a momentum balance for
	either x, y, or z components of fluid velocity. */
class MomentumPressureGrad : public Kernel
{
public:
	/// Required constructor for objects in MOOSE
	MomentumPressureGrad(const InputParameters & parameters);
	
protected:
	/// Required residual function for standard kernels in MOOSE
	/** This function returns a residual contribution for this object.*/
	virtual Real computeQpResidual();
	
	/// Required Jacobian function for standard kernels in MOOSE
	/** This function returns a Jacobian contribution for this object. The Jacobian being
		computed is the associated diagonal element in the overall Jacobian matrix for the
		system and is used in preconditioning of the linear sub-problem. */
	virtual Real computeQpJacobian();
	
	/// Not Required, but aids in the preconditioning step
	/** This function returns the off diagonal Jacobian contribution for this object. By
		returning a non-zero value we will hopefully improve the convergence rate for the
		cross coupling of the variables. */
	virtual Real computeQpOffDiagJacobian(unsigned int jvar);
	
	const VariableGradient & _press_grad;		///< Pressure gradient of the fluid
	
	unsigned int _dir;							///< Direction variable for direction this kernel acts on (0=x, 1=y, 2=z)
	
	const unsigned int _press_var;				///< Variable identification for density
	
private:
	
};

#endif // MOMENTUMPRESSUREGRAD_H
