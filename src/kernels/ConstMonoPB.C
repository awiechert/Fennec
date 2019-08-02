/*!
 *  \file ConstMonoPB.h
 *	\brief Kernel for Mono-variate Population Balance Model with constant coefficients
 *	\details This file creates a MOOSE kernel that will couple together multiple number
 *			concentrations of particles and calculate a population balance rate function
 *			assuming the collision efficiency and frequency are known constants. This module
 *			is based on the following works:
 *
 *			Y.H. Kim, S. Yiacoumi, A. Nenes, C. Tsouris, J. Aero. Sci., 114, 283-300, 2017.
 *
 *			S. Kumar, D. Ramkrishna, Chem. Eng. Sci., 51, 1311-1332, 1996.
 *
 *  \author Austin Ladshaw
 *	\date 08/02/2019
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

#include "ConstMonoPB.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", ConstMonoPB);

template<>
InputParameters validParams<ConstMonoPB>()
{
    InputParameters params = validParams<Kernel>();
    params.addParam<Real>("efficiency",1.0,"Collision Efficiency (-)");
    params.addParam<Real>("frequency",1.0,"Collision Frequency (m^3/s)");
    params.addRequiredParam< std::vector<Real> >("diameters","Set of particle diameters corresponding to each size bin (m) (Must have same order as the 'coupled_list')");
    params.addRequiredCoupledVar("coupled_list","List of names of the number concentration variables being coupled (including this variable)");
    return params;
}

ConstMonoPB::ConstMonoPB(const InputParameters & parameters)
: Kernel(parameters),
_const_alpha(getParam<Real>("efficiency")),
_const_beta(getParam<Real>("frequency")),
_dia(getParam<std::vector<Real> >("diameters")),
_u_var(coupled("variable"))
{
    _M = coupledComponents("coupled_list");
    if (_M != _dia.size())
    	moose::internal::mooseErrorRaw("Number of coupled variables does not match number of particle size bins!");
    
    _coupled_u_var.resize(_M);
    _coupled_u.resize(_M);
    _frac.resize(_M);
    _alpha.resize(_M);
    _beta.resize(_M);
    _vol.resize(_M);
    
    for (unsigned int i = 0; i<_coupled_u.size(); ++i)
    {
        _coupled_u_var[i] = coupled("coupled_list",i);
        _coupled_u[i] = &coupledValue("coupled_list",i);
        // How to refer to the value of the coupled variable list:   _u_coupled[_qp] == (*_coupled_u[i])[_qp]   for each i
    }
    
    for (int i=0; i<_M; i++)
    {
        _frac[i].resize(_M);
        _alpha[i].resize(_M);
        _beta[i].resize(_M);
        for (int j=0; j<_M; j++)
        	_frac[i][j].resize(_M);
    }
    
    this->AlphaBetaFill();
    this->VolumeFill();
    this->FractionFill();
    
}

Real ConstMonoPB::KroneckerDelta(int i, int j)
{
    if (i==j)
    	return 1.0;
    else
    	return 0.0;
}

void ConstMonoPB::AlphaBetaFill()
{
    for (int l=0; l<_M; l++)
    {
        for (int m=0; m<_M; m++)
        {
            _alpha[l][m] = _const_alpha;
            _beta[l][m] = _const_beta;
        }
    }
}

void ConstMonoPB::VolumeFill()
{
	Real pi = 3.14159;
    Real c = pi/6.0;
    for (int k=0; k<_M; k++)
    {
		_vol[k] = c*_dia[k]*_dia[k]*_dia[k];
    }
}

void ConstMonoPB::FractionFill()
{
    for (int k=0; k<_M; k++)
    {
        for (int l=0; l<_M; l++)
        {
            for (int m=0; m<_M; m++)
            {
                
            }
        }
    }
}

Real ConstMonoPB::computeQpResidual()
{
    return 0.0;
}

Real ConstMonoPB::computeQpJacobian()
{
    return 0.0;
}

Real ConstMonoPB::computeQpOffDiagJacobian(unsigned int jvar)
{
    return 0.0;
}


