/*!
 *  \file UniformBinaryMonoPB.h
 *	\brief Kernel for Uniform Binary Breakage in a Mono-variate Population Balance Model
 *	\details This file creates a MOOSE kernel that will couple together multiple number
 *			concentrations of particles and calculate a population balance rate function
 *			for particle breakup based on the uniform binary breakage function. This module 
 *			is based on the following works:
 *
 *			S. Kumar, D. Ramkrisha, Chem. Eng. Sci., 51, 1311-1332, 1996a.
 *
 *			P.J. Hill, K.M. Ng, AIChE J., 41, 1204-1216, 1995.
 *
 *			Y.K. Ho, P. Doshi, H.K. Yeoh, G.C. Ngoh, Chem. Eng. Sci., 116, 601-610, 2014.
 *
 *  \author Alexander Wiechert
 *	\date 01/11/2021
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

#include "UniformBinaryMonoPB.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", UniformBinaryMonoPB);

InputParameters UniformBinaryMonoPB::validParams()
{
    InputParameters params = Kernel::validParams();
    params.addParam<Real>("breakup_coefficient",1.0,"Breakup Rate Coefficient (1/s)");
    params.addParam<Real>("fragment_number",2.0,"Number of Fragments formed during breakup (-), Cannot be less than two and should always be set to two when simulating binary breakage");
    params.addRequiredParam< std::vector<Real> >("diameters","Set of particle diameters corresponding to each size bin (m) (Must have same order as the 'coupled_list')");
    params.addRequiredCoupledVar("coupled_list","List of names of the number concentration variables being coupled (including this variable)");
    params.addRequiredCoupledVar("main_variable","Name of the number concentration variable this kernel acts on");
    return params;
    
}

UniformBinaryMonoPB::UniformBinaryMonoPB(const InputParameters & parameters)
: Kernel(parameters),
_b_coeff(getParam<Real>("breakup_coefficient")),
_f_num(getParam<Real>("fragment_number")),
_dia(getParam<std::vector<Real> >("diameters")),
_u_var(coupled("main_variable"))
{
    _M = coupledComponents("coupled_list");
    if (_M != _dia.size())
        moose::internal::mooseErrorRaw("Number of coupled variables does not match number of particle size bins!");
    
    _coupled_u_var.resize(_M);
    _coupled_u.resize(_M);
    _frag.resize(_M);
    _vol.resize(_M);
    
    for (unsigned int i = 0; i<_coupled_u.size(); ++i)
    {
        _coupled_u_var[i] = coupled("coupled_list",i);
        _coupled_u[i] = &coupledValue("coupled_list",i);
        _those_var[_coupled_u_var[i]] = i;
        
        if (_coupled_u_var[i] == _u_var)
            _this_var = i;
        // How to refer to the value of the coupled variable list:   _u_coupled[_qp] == (*_coupled_u[i])[_qp]   for each i
    }
    
    for (int i=0; i<_M; i++)
    {
        _frag[i].resize(_M);
    }
    
    this->VolumeFill();
    this->FragmentFill();

}

Real UniformBinaryMonoPB::KroneckerDelta(int i, int j)
{
    if (i==j)
        return 1.0;
    else
        return 0.0;
}

void UniformBinaryMonoPB::VolumeFill()
{
    Real pi = 3.14159;
    Real c = pi/6.0;
    for (int k=0; k<_M; k++)
    {
        _vol[k] = c*_dia[k]*_dia[k]*_dia[k];
    }
}

void UniformBinaryMonoPB::FragmentFill()
{
    for (int k=_M-1; k>=0; k--)
    {
        for (int l=_M-1; l>=0; l--)
        {
    		if (k>l && k>1)
            {
                _frag[k][l] = 0.0;
            }
            else if (k==l && k>1)
            {
                _frag[k][l] = (_vol[k]-_vol[k-1])/_vol[l];
            }
            else if (k==1)
            {
            	if (l>1)
                {
                    Real vol_sum = 0.0;
                    Real num_sum = 0.0;
                    for (int i=2; i<=l; i++)
                    {
                        vol_sum = vol_sum + _frag[i][l]*_vol[i];
                        num_sum = num_sum + _frag[i][l];
                    }
                	_frag[k][l] = ((_vol[l]-vol_sum)-(_f_num-num_sum)*_vol[0])/(_vol[1]-_vol[0]);
                }
                else if (l==1)
                {
                    _frag[k][l] = (_vol[l]-_f_num*_vol[0])/(_vol[1]-_vol[0]);
                }
                else
                {
                    _frag[k][l] = 0.0;
                }

            }
            else if (k==0)
            {
            	if (l>1)
                {
                    Real num_sum = 0.0;
                    for (int m=2; m<=l; m++)
                    {
                        num_sum = num_sum + _frag[m][l];
                    }
                    _frag[k][l] = _f_num - num_sum - _frag[1][l];
                }
                else if (l==1)
                {
                    _frag[k][l] = _f_num - _frag[1][l];
                }
                else
                {
                    _frag[k][l] = 0.0;
                }
            }
            else
            {
             	_frag[k][l] = (_vol[k+1]-_vol[k-1])/_vol[l];
            }
        }
    }
}

Real UniformBinaryMonoPB::computeQpResidual()
{
	Real source = 0.0;
    Real rate = 0.0;
    int k = _this_var;
    
    for (int l=0; l<_M; l++)
    {
        source = source + _frag[k][l]*_b_coeff*(*_coupled_u[l])[_qp];
    }
    
    rate = source - (1.0-this->KroneckerDelta(k,0))*_b_coeff*_u[_qp];
    return -rate*_test[_i][_qp];
}

Real UniformBinaryMonoPB::computeQpJacobian()
{
	int k = _this_var;
    return -_phi[_j][_qp]*_test[_i][_qp]*(_frag[k][k]*_b_coeff-(1-this->KroneckerDelta(k,0))*_b_coeff);
}

Real UniformBinaryMonoPB::computeQpOffDiagJacobian(unsigned int jvar)
{
    return 0.0;
}
