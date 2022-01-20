/*!
*  \file DGContinuumBC.h
*	\brief Boundary Condition kernel for the continuity equation applied at boundary conditions
*	\details This file creates a boundary condition kernel for the continuity of momemtum at boundaries.
*			Use this BC for systems involving the conservation of momentum where no additional momentum is
*			being added to the system from the boundaries.
*
*  \author Austin Ladshaw
*	\date 07/10/2018
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

#include "DGContinuumBC.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", DGContinuumBC);

InputParameters DGContinuumBC::validParams()
{
	InputParameters params = DGMomentumFluxBC::validParams();
	return params;
}

DGContinuumBC::DGContinuumBC(const InputParameters & parameters) :
DGMomentumFluxBC(parameters)
{
	if (_dir > 2)
		_dir = 0;
}

Real DGContinuumBC::computeQpResidual()
{
	_velocity(0)=_ux[_qp];
	_velocity(1)=_uy[_qp];
	_velocity(2)=_uz[_qp];
	
	return _test[_i][_qp]*(_velocity*_normals[_qp])*_u[_qp]*_density[_qp];
}

Real DGContinuumBC::computeQpJacobian()
{
	_velocity(0)=_ux[_qp];
	_velocity(1)=_uy[_qp];
	_velocity(2)=_uz[_qp];
	
	Real r = 0;
	
	r += _test[_i][_qp]*(_velocity*_normals[_qp])*_phi[_j][_qp];
	r += _test[_i][_qp]*_u[_qp]*_density[_qp]*(_phi[_j][_qp]*_normals[_qp](_dir));
	
	return r;
}

Real DGContinuumBC::computeQpOffDiagJacobian(unsigned int jvar)
{
	_velocity(0)=_ux[_qp];
	_velocity(1)=_uy[_qp];
	_velocity(2)=_uz[_qp];
	
	Real r = 0;
	
	if (jvar == _ux_var)
	{
		r += _test[_i][_qp]*_u[_qp]*_density[_qp]*(_phi[_j][_qp]*_normals[_qp](0));

		return r;
	}
	
	if (jvar == _uy_var)
	{
		r += _test[_i][_qp]*_u[_qp]*_density[_qp]*(_phi[_j][_qp]*_normals[_qp](1));
		
		return r;
	}
	
	if (jvar == _uz_var)
	{
		r += _test[_i][_qp]*_u[_qp]*_density[_qp]*(_phi[_j][_qp]*_normals[_qp](2));

		return r;
	}
	
	if (jvar == _den_var)
	{
		r += _test[_i][_qp]*_u[_qp]*_phi[_j][_qp]*(_velocity*_normals[_qp]);
		
		return r;
	}
	
	return 0.0;
}

