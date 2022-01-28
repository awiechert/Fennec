/*!
 *  \file ADGAnisotropicDiffusion.C
 *	\brief ADKernel for use with the corresponding ADDGAnisotropicDiffusion object
 *
 *  \author Alexander Wiechert
 *	\date 01/25/2022
 *	\copyright This kernel was designed and built at the Georgia Institute
 *             of Technology by Alexander Wiechert for research in the area
 *             of radioactive particle transport and settling following a
 *			   nuclear event. It was developed for the US DOD under DTRA
 *			   project No. 14-24-FRCWMD-BAA. Portions Copyright (c) 2018, all
 *             rights reserved.
 *
 *			   Alexander Wiechert does not claim any ownership or copyright to the
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

#include "ADGAnisotropicDiffusion.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */

registerMooseObject("fennecApp", ADGAnisotropicDiffusion);

InputParameters ADGAnisotropicDiffusion::validParams()
{
	InputParameters params = ADKernel::validParams();
	params.addParam<Real>("Dxx",0,"xx-component of diffusion tensor");
	params.addParam<Real>("Dxy",0,"xy-component of diffusion tensor");
	params.addParam<Real>("Dxz",0,"xz-component of diffusion tensor");
	params.addParam<Real>("Dyx",0,"yx-component of diffusion tensor");
	params.addParam<Real>("Dyy",0,"yy-component of diffusion tensor");
	params.addParam<Real>("Dyz",0,"yz-component of diffusion tensor");
	params.addParam<Real>("Dzx",0,"zx-component of diffusion tensor");
	params.addParam<Real>("Dzy",0,"zy-component of diffusion tensor");
	params.addParam<Real>("Dzz",0,"zz-component of diffusion tensor");
	return params;
}

ADGAnisotropicDiffusion::ADGAnisotropicDiffusion(const InputParameters & parameters) :
ADKernel(parameters),
_Dxx(getParam<Real>("Dxx")),
_Dxy(getParam<Real>("Dxy")),
_Dxz(getParam<Real>("Dxz")),
_Dyx(getParam<Real>("Dyx")),
_Dyy(getParam<Real>("Dyy")),
_Dyz(getParam<Real>("Dyz")),
_Dzx(getParam<Real>("Dzx")),
_Dzy(getParam<Real>("Dzy")),
_Dzz(getParam<Real>("Dzz"))
{
	_Diffusion(0,0) = _Dxx;
	_Diffusion(0,1) = _Dxy;
	_Diffusion(0,2) = _Dxz;
	
	_Diffusion(1,0) = _Dyx;
	_Diffusion(1,1) = _Dyy;
	_Diffusion(1,2) = _Dyz;
	
	_Diffusion(2,0) = _Dzx;
	_Diffusion(2,1) = _Dzy;
	_Diffusion(2,2) = _Dzz;
}

ADReal ADGAnisotropicDiffusion::computeQpResidual()
{
	return _Diffusion*_grad_test[_i][_qp]*_grad_u[_qp];
}
