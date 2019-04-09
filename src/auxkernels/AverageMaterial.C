/*!
 *  \file AverageMaterial.h
 *	\brief Auxillary kernel to keep track of the average amount of a set of variables
 *	\details This file creates an auxillary kernel that computes the average amount of a
 *			set of non-linear variables that has passed through a particular element in the mesh.
 *			This kernel couples with a non-linear variable and integrates it over the volume
 *			of the current element. That integrated amount is then added to other non-linear
 *			integrals calculated to create a running average of material that has passed
 *			through the element at each time step.
 *
 *  \author Austin Ladshaw
 *	\date 04/09/2019
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

#include "AverageMaterial.h"

template<>
InputParameters validParams<AverageMaterial>()
{
	InputParameters params = validParams<AuxKernel>();
	params.addCoupledVar("coupled_vars", "List of non-linear variables coupled to this object");
	return params;
}

AverageMaterial::AverageMaterial(const InputParameters & parameters) :
AuxKernel(parameters)
{
	unsigned int n = coupledComponents("coupled_vars");
	_coupled_u.resize(n);
	
	for (unsigned int i = 0; i<_coupled_u.size(); ++i)
	{
		_coupled_u[i] = &coupledValue("coupled_vars",i);
	}
	
}

Real AverageMaterial::computeValue()
{
	Real _total = 0.0;
	
	for (unsigned int i = 0; i<_coupled_u.size(); ++i)
	{
		double add = (*_coupled_u[i])[_qp];
		_total = _total + add;
	}
	return _total;
}



