/*!
 *  \file DGMomentumDiffusion.h
 *	\brief Discontinous Galerkin kernel for viscous momentum dispersion
 *	\details This file creates a discontinous Galerkin kernel for momentum diffusion. It is build on utilizing the
 *			existing DGAnisotropicDiffusion kernel and replaces the Diffusion coefficient with fluid viscosity.
 *
 *	\note Any DG kernel under FENNEC will have a cooresponding G kernel (usually of same name) that must be included
 *		with the DG kernel in the input file. This is because the DG finite element method breaks into several different
 *		residual pieces, only a handful of which are handled by the DG kernel system and the other parts must be handled
 *		by the standard Galerkin system. This my be due to some legacy code in MOOSE. I am not sure if it is possible to
 *		lump all of these actions into a single DG kernel.
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

#include "DGMomentumDiffusion.h"

template<>
InputParameters validParams<DGMomentumDiffusion>()
{
	InputParameters params = validParams<DGAnisotropicDiffusion>();
	params.addRequiredCoupledVar("viscosity","Variable for viscosity");
	return params;
}

DGMomentumDiffusion::DGMomentumDiffusion(const InputParameters & parameters) :
DGAnisotropicDiffusion(parameters),
_viscosity(coupledValue("viscosity")),
_vis_var(coupled("viscosity"))
{

}

Real DGMomentumDiffusion::computeQpResidual(Moose::DGResidualType type)
{
	_Diffusion(0,0) = _viscosity[_qp];
	_Diffusion(0,1) = 0.0;
	_Diffusion(0,2) = 0.0;
	
	_Diffusion(1,0) = 0.0;
	_Diffusion(1,1) = _viscosity[_qp];
	_Diffusion(1,2) = 0.0;
	
	_Diffusion(2,0) = 0.0;
	_Diffusion(2,1) = 0.0;
	_Diffusion(2,2) = _viscosity[_qp];
	
	return DGAnisotropicDiffusion::computeQpResidual(type);
}

Real DGMomentumDiffusion::computeQpJacobian(Moose::DGJacobianType type)
{
	_Diffusion(0,0) = _viscosity[_qp];
	_Diffusion(0,1) = 0.0;
	_Diffusion(0,2) = 0.0;
	
	_Diffusion(1,0) = 0.0;
	_Diffusion(1,1) = _viscosity[_qp];
	_Diffusion(1,2) = 0.0;
	
	_Diffusion(2,0) = 0.0;
	_Diffusion(2,1) = 0.0;
	_Diffusion(2,2) = _viscosity[_qp];
	
	return DGAnisotropicDiffusion::computeQpJacobian(type);
}

Real DGMomentumDiffusion::computeQpOffDiagJacobian(Moose::DGJacobianType type, unsigned int jvar)
{
	Real r = 0;
	
	if (jvar == _vis_var)
	{
		_Diffusion(0,0) = _phi[_j][_qp];
		_Diffusion(0,1) = 0.0;
		_Diffusion(0,2) = 0.0;
	
		_Diffusion(1,0) = 0.0;
		_Diffusion(1,1) = _phi[_j][_qp];
		_Diffusion(1,2) = 0.0;
	
		_Diffusion(2,0) = 0.0;
		_Diffusion(2,1) = 0.0;
		_Diffusion(2,2) = _phi[_j][_qp];
	
		switch (type)
		{
			case Moose::ElementElement:
				r -= 0.5 * (_Diffusion * _grad_u[_qp] * _normals[_qp] + _Diffusion * _grad_u_neighbor[_qp] * _normals[_qp]) * _test[_i][_qp];
				r += _epsilon * 0.5 * (_u[_qp] - _u_neighbor[_qp]) * _Diffusion * _grad_test[_i][_qp] * _normals[_qp];
				break;
			
			case Moose::ElementNeighbor:
				r -= 0.5 * (_Diffusion * _grad_u[_qp] * _normals[_qp] + _Diffusion * _grad_u_neighbor[_qp] * _normals[_qp]) * _test[_i][_qp];
				r += _epsilon * 0.5 * (_u[_qp] - _u_neighbor[_qp]) * _Diffusion * _grad_test[_i][_qp] * _normals[_qp];
				break;
			
			case Moose::NeighborElement:
				r += 0.5 * (_Diffusion * _grad_u[_qp] * _normals[_qp] + _Diffusion * _grad_u_neighbor[_qp] * _normals[_qp]) * _test_neighbor[_i][_qp];
				r += _epsilon * 0.5 * (_u[_qp] - _u_neighbor[_qp]) * _Diffusion * _grad_test_neighbor[_i][_qp] * _normals[_qp];
				break;
			
			case Moose::NeighborNeighbor:
				r += 0.5 * (_Diffusion * _grad_u[_qp] * _normals[_qp] + _Diffusion * _grad_u_neighbor[_qp] * _normals[_qp]) * _test_neighbor[_i][_qp];
				r += _epsilon * 0.5 * (_u[_qp] - _u_neighbor[_qp]) * _Diffusion * _grad_test_neighbor[_i][_qp] * _normals[_qp];
				break;
		}
	}
	
	return r;
}

