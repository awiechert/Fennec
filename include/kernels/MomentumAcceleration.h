/*!
 *  \file MomentumAcceleration.h
 *	\brief Kernel to couple density and acceleration variables to a momentum conservation equation
 *	\details This file creates a standard MOOSE kernel that is to be used to coupled acceleration variables (such
 *			as gravity) with density variables within the momentum balance for fluid velocity in a particular
 *			direction (x, y, z). This kernel will act on a velocity variable in x, y, or z, but not explicitly use
 *			that variable. So, as a result there is no Jacobian for this residual. Instead, there will be two off
 *			diagonal Jacobians, which indicate the coupling of density and acceleration variables.
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

#ifndef MOMENTUMACCELERATION_H
#define MOMENTUMACCELERATION_H

#include "Kernel.h"

/// MomentumAcceleration class object forward declarations
class MomentumAcceleration;

template<>
InputParameters validParams<MomentumAcceleration>();

/// MomentumAcceleration class object inherits from Kernel object
/** This class object inherits from the Kernel object in the MOOSE framework.
	All public and protected members of this class are required function overrides.
	The kernel couples acceleration and density variables to a momentum balance for
	either x, y, or z components of fluid velocity. */
class MomentumAcceleration : public Kernel
{
public:
	/// Required constructor for objects in MOOSE
	MomentumAcceleration(const InputParameters & parameters);
	
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
	
	const VariableValue & _density;				///< Density of the fluid
	const VariableValue & _accel;				///< Variable for acceleration in the vector direction the kernel acts on
	
	const unsigned int _den_var;				///< Variable identification for density
	const unsigned int _accel_var;				///< Variable identification for acceleration
	
private:
	
};

#endif // MOMENTUMACCELERATION_H
