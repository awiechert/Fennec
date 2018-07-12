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

#include "MomentumAcceleration.h"

template<>
InputParameters validParams<MomentumAcceleration>()
{
	InputParameters params = validParams<Kernel>();
	params.addRequiredCoupledVar("density","Variable for density");
	params.addRequiredCoupledVar("acceleration","Variable for acceleration in the direction of the velocity this kernel acts on");
	return params;
}


MomentumAcceleration::MomentumAcceleration(const InputParameters & parameters)
:Kernel(parameters),
_density(coupledValue("density")),
_accel(coupledValue("acceleration")),
_den_var(coupled("density")),
_accel_var(coupled("acceleration"))
{
	
}

Real MomentumAcceleration::computeQpResidual()
{
	return -_density[_qp]*_accel[_qp]*_test[_i][_qp];
}

Real MomentumAcceleration::computeQpJacobian()
{
	return 0.0;
}

Real MomentumAcceleration::computeQpOffDiagJacobian(unsigned int jvar)
{
	if (jvar == _den_var)
	{
		return -_phi[_j][_qp]*_accel[_qp]*_test[_i][_qp];
	}
	if (jvar == _accel_var)
	{
		return -_density[_qp]*_phi[_j][_qp]*_test[_i][_qp];
	}
	
	return 0.0;
}
