/*!
 *  \file AccumulatedMaterial.h
 *	\brief Auxillary kernel to keep track of the total accumulated amount of a variable
 *	\details This file creates an auxillary kernel that computes the total accumulated amount
 *			of a non-linear variable that has passed through a particular element in the mesh.
 *			This kernel couples with a non-linear variable and integrates it over the volume
 *			of the current element. That integrated amount is then continuously added to
 *			prior integrals calculated to create a running total of material that has passed
 *			through the element.
 *
 *  \author Austin Ladshaw
 *	\date 05/18/2018
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

#include "AccumulatedMaterial.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", AccumulatedMaterial);

template<>
InputParameters validParams<AccumulatedMaterial>()
{
	InputParameters params = validParams<AuxKernel>();
	params.addCoupledVar("coupled_vars", "List of non-linear variables coupled to this object");
	return params;
}

AccumulatedMaterial::AccumulatedMaterial(const InputParameters & parameters) :
AuxKernel(parameters)
{
	unsigned int n = coupledComponents("coupled_vars");
	_coupled_u.resize(n);
	
	for (unsigned int i = 0; i<_coupled_u.size(); ++i)
	{
		_coupled_u[i] = &coupledValue("coupled_vars",i);
	}
	
}

Real AccumulatedMaterial::computeValue()
{
	Real _total = 0.0;
	
	for (unsigned int i = 0; i<_coupled_u.size(); ++i)
	{
		double add = (*_coupled_u[i])[_qp]*_current_elem->volume();
		if (add > 0.0)
			_total = _total + add;
	}
	return _u_old[_qp] + _total;
}
