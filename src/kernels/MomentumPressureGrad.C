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

#include "MomentumPressureGrad.h"

template<>
InputParameters validParams<MomentumPressureGrad>()
{
	InputParameters params = validParams<Kernel>();
	params.addRequiredCoupledVar("pressure","Variable for fluid pressure");
	params.addParam<unsigned int>("direction",0,"Integer to denote the direction this kernel acts on");
	
	return params;
}


MomentumPressureGrad::MomentumPressureGrad(const InputParameters & parameters)
:Kernel(parameters),
_press_grad(coupledGradient("pressure")),
_dir(getParam<unsigned int>("direction")),
_press_var(coupled("pressure"))
{
	if (_dir > 2)
		_dir = 0;
}

Real MomentumPressureGrad::computeQpResidual()
{
	return _press_grad[_qp](_dir)*_test[_i][_qp];
}

Real MomentumPressureGrad::computeQpJacobian()
{
	return 0.0;
}

Real MomentumPressureGrad::computeQpOffDiagJacobian(unsigned int jvar)
{
	if (jvar == _press_var)
	{
		return _grad_phi[_j][_qp](_dir)*_test[_i][_qp];
	}
	
	return 0.0;
}
