/*!
 *  \file ShearMultiFragLinearMonoPB.C
 *	\brief Kernel for Shear Driven Multi-Fragment Breakage in a Mono-variate Population Balance Model
 *	\details This file creates a MOOSE kernel that will couple together multiple number
 *			concentrations of particles and calculate a population balance rate function
 *			for particle breakup based on the muli-fragment linear binary breakage function
 *			with a breakup rate coefficient calculated using a semi-emperical formula for
 *			shear driven breakup.
 *
 *			This module's breakup function is based on the following works:
 *
 *			S. Kumar, D. Ramkrisha, Chem. Eng. Sci., 51, 1311-1332, 1996a.
 *
 *			P.J. Hill, K.M. Ng, AIChE J., 41, 1204-1216, 1995.
 *
 *			Y.K. Ho, P. Doshi, H.K. Yeoh, G.C. Ngoh, Chem. Eng. Sci., 116, 601-610, 2014.
 *
 *  \author Alexander Wiechert
 *	\date 05/14/2021
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

#include "ShearMultiFragLinearMonoPB.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", ShearMultiFragLinearMonoPB);

InputParameters ShearMultiFragLinearMonoPB::validParams()
{
    InputParameters params = Kernel::validParams();
    params.addParam<Real>("breakup_constant",1.0,"Breakup Constant (-)");
    params.addParam<Real>("prime_radius",1.0e-9,"Radius of the Prime Particle in Aggregate (m)");
    params.addParam<Real>("fragment_number",3.0,"Number of Fragments formed during breakup (-), Cannot be less than two and should always be set to two when simulating binary breakage");
    params.addCoupledVar("kinematic_viscosity",1.562e-5,"[Variable] Kinematic Viscosity of Air (m^2/s)");
    params.addCoupledVar("energy_dissipation",0.3,"[Variable] Turbulent Energy Dissipation Rate in Atmosphere (m^2/s^3)");
    params.addRequiredParam< std::vector<Real> >("diameters","Set of particle diameters corresponding to each size bin (m) (Must have same order as the 'coupled_list')");
    params.addRequiredParam< std::vector<Real> >("packing_density","Set of particle packing densities corresponding to each size bin (-) (Must have same order as the 'coupled_list')");
    params.addRequiredParam< std::vector<Real> >("fractal_dimensions","Set of particle fractal dimensions corresponding to each size bin (-) (Must have same order as the 'coupled_list')");
    params.addRequiredCoupledVar("coupled_list","List of names of the number concentration variables being coupled (including this variable)");
    params.addRequiredCoupledVar("main_variable","Name of the number concentration variable this kernel acts on");
    return params;

}

ShearMultiFragLinearMonoPB::ShearMultiFragLinearMonoPB(const InputParameters & parameters)
: Kernel(parameters),
_b_con(getParam<Real>("breakup_constant")),
_p_rad(getParam<Real>("prime_radius")),
_f_num(getParam<Real>("fragment_number")),
_k_vis(coupledValueOld("kinematic_viscosity")),
_e_dis(coupledValueOld("energy_dissipation")),
_dia(getParam<std::vector<Real> >("diameters")),
_p_den(getParam<std::vector<Real> >("packing_density")),
_f_dim(getParam<std::vector<Real> >("fractal_dimensions")),
_u_var(coupled("main_variable"))
{
    _M = coupledComponents("coupled_list");
    if (_M != _dia.size())
        moose::internal::mooseErrorRaw("Number of coupled variables does not match number of particle size bins!");

    _coupled_u_var.resize(_M);
    _coupled_u.resize(_M);
    _frag.resize(_M);
    _num.resize(_M);
    _rat.resize(_M);
    _vol.resize(_M);

    for (unsigned int i = 0; i<_coupled_u.size(); ++i)
    {
        _coupled_u_var[i] = coupled("coupled_list",i);
        _coupled_u[i] = &coupledValue("coupled_list",i);

        if (_coupled_u_var[i] == _u_var)
            _this_var = i;
        else
            _those_var[_coupled_u_var[i]] = i;
        // How to refer to the value of the coupled variable list:   _u_coupled[_qp] == (*_coupled_u[i])[_qp]   for each i
    }

    for (int i=0; i<_M; i++)
    {
        _frag[i].resize(_M);
    }

    this->VolumeFill();
    this->FragmentFill();
    this->NumberFill();
}

Real ShearMultiFragLinearMonoPB::KroneckerDelta(int i, int j)
{
    if (i==j)
        return 1.0;
    else
        return 0.0;
}

void ShearMultiFragLinearMonoPB::VolumeFill()
{
    Real pi = 3.14159;
    Real c = pi/6.0;
    for (int k=0; k<_M; k++)
    {
        _vol[k] = c*_dia[k]*_dia[k]*_dia[k];
    }
}

void ShearMultiFragLinearMonoPB::NumberFill()
{
    Real pi = 3.14159;
    Real c = pi/6.0;
    Real v_prime = 8.0*c*_p_rad*_p_rad*_p_rad;

    for (int k=0; k<_M; k++)
    {
        _num[k] = _vol[k]/v_prime;
    }
}

void ShearMultiFragLinearMonoPB::BreakupRateFill()
{
    Real pi = 3.14159;
    Real m = pow(4.0/(15.0*pi),0.5);

    for (int k=0; k<_M; k++)
    {
        _rat[k] = m*pow(_e_dis[_qp]/_k_vis[_qp],0.5)*exp(-_b_con/(_e_dis[_qp]*_p_rad*pow(_num[k]/_p_den[k],1.0/_f_dim[k])));
    }
}

void ShearMultiFragLinearMonoPB::FragmentFill()
{
    Real B = -6.0*(_f_num-2.0);
    Real A = 2.0 - 2.0*B/3.0;
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
            	Real c = (1/(_vol[k]-_vol[k-1]))*((A*(_vol[k]*_vol[k]-_vol[k-1]*_vol[k-1])/(2*_vol[l]))+(B*(_vol[k]*_vol[k]*_vol[k]-_vol[k-1]*_vol[k-1]*_vol[k-1])/(3*_vol[l]*_vol[l])));
                Real d = (_vol[k-1]/(_vol[k]-_vol[k-1]))*(A*(_vol[k]-_vol[k-1])/_vol[l]+B*(_vol[k]*_vol[k]-_vol[k-1]*_vol[k-1])/(2*_vol[l]*_vol[l]));
                _frag[k][l] = c-d;
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
                Real a = (_vol[k+1]/(_vol[k+1]-_vol[k]))*(A*(_vol[k+1]-_vol[k])/_vol[l]+B*(_vol[k+1]*_vol[k+1]-_vol[k]*_vol[k])/(2*_vol[l]*_vol[l]));
                Real b = (1/(_vol[k+1]-_vol[k]))*((A*(_vol[k+1]*_vol[k+1]-_vol[k]*_vol[k])/(2*_vol[l]))+(B*(_vol[k+1]*_vol[k+1]*_vol[k+1]-_vol[k]*_vol[k]*_vol[k])/(3*_vol[l]*_vol[l])));
                Real c = (1/(_vol[k]-_vol[k-1]))*((A*(_vol[k]*_vol[k]-_vol[k-1]*_vol[k-1])/(2*_vol[l]))+(B*(_vol[k]*_vol[k]*_vol[k]-_vol[k-1]*_vol[k-1]*_vol[k-1])/(3*_vol[l]*_vol[l])));
                Real d = (_vol[k-1]/(_vol[k]-_vol[k-1]))*(A*(_vol[k]-_vol[k-1])/_vol[l]+B*(_vol[k]*_vol[k]-_vol[k-1]*_vol[k-1])/(2*_vol[l]*_vol[l]));
                _frag[k][l] = (a-b)+(c-d);
            }
        }
    }
}

Real ShearMultiFragLinearMonoPB::computeQpResidual()
{
    Real source = 0.0;
    Real rate = 0.0;
    int k = _this_var;
	this->BreakupRateFill();
    
    for (int l=0; l<_M; l++)
    {
        source = source + _frag[k][l]*_rat[l]*(*_coupled_u[l])[_qp];
    }

    rate = source*_test[_i][_qp] - (1.0-this->KroneckerDelta(k,0))*_rat[k]*_u[_qp]*_test[_i][_qp];
    return -rate;
}

Real ShearMultiFragLinearMonoPB::computeQpJacobian()
{
    int k = _this_var;
    this->BreakupRateFill();
    return -_phi[_j][_qp]*_test[_i][_qp]*(_frag[k][k]*_rat[k]-(1-this->KroneckerDelta(k,0))*_rat[k]);
}

Real ShearMultiFragLinearMonoPB::computeQpOffDiagJacobian(unsigned int jvar)
{
    int k = _this_var;
    int h = _those_var[jvar];
    this->BreakupRateFill();
    return -_phi[_j][_qp]*_test[_i][_qp]*(_frag[k][h]*_rat[h]);
}
