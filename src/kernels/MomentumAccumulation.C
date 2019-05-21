/*!
 *  \file MomentumAccumulation.h
 *	\brief Time Derivative kernel for the accumulation of momentum of a component of velocity
 *	\details This file creates a time derivative kernel to be used in the momentum transport equations for a velocity
 *			component.
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

#include "MomentumAccumulation.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", MomentumAccumulation);

template<>
InputParameters validParams<MomentumAccumulation>()
{
	InputParameters params = validParams<TimeDerivative>();
	params.addRequiredCoupledVar("density","Variable for density");
	return params;
}


MomentumAccumulation::MomentumAccumulation(const InputParameters & parameters)
:TimeDerivative(parameters),
_density(coupledValue("density")),
_den_var(coupled("density"))
{
	
}

Real MomentumAccumulation::computeQpResidual()
{
	return _density[_qp] * TimeDerivative::computeQpResidual();
}

Real MomentumAccumulation::computeQpJacobian()
{
	return _density[_qp] * TimeDerivative::computeQpJacobian();
}

Real MomentumAccumulation::computeQpOffDiagJacobian(unsigned int jvar)
{
	if (jvar == _den_var)
	{
		return _phi[_j][_qp] * TimeDerivative::computeQpResidual();
	}
	
	return 0.0;
}
