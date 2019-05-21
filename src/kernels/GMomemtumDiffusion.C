/*!
 *  \file GMomentumDiffusion.h
 *	\brief Kernel for use with the corresponding DGMomentumDiffusion object
 *	\details This file creates a standard MOOSE kernel that is to be used in conjunction with the DGMomentumDiffusion kernel
 *			for the discontinous Galerkin formulation of momentum conservation in MOOSE.
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

#include "GMomentumDiffusion.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", GMomentumDiffusion);

template<>
InputParameters validParams<GMomentumDiffusion>()
{
	InputParameters params = validParams<GAnisotropicDiffusion>();
	params.addRequiredCoupledVar("viscosity","Variable for viscosity");
	return params;
}

GMomentumDiffusion::GMomentumDiffusion(const InputParameters & parameters) :
GAnisotropicDiffusion(parameters),
_viscosity(coupledValue("viscosity")),
_vis_var(coupled("viscosity"))
{

}

Real GMomentumDiffusion::computeQpResidual()
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
	
	return GAnisotropicDiffusion::computeQpResidual();
}

Real GMomentumDiffusion::computeQpJacobian()
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
	
	return GAnisotropicDiffusion::computeQpResidual();
}

Real GMomentumDiffusion::computeQpOffDiagJacobian(unsigned int jvar)
{
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
		
		return _Diffusion*_grad_test[_i][_qp]*_grad_u[_qp];
	}
	
	return 0.0;
}

