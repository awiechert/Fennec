/*!
 *  \file ADAggregationMPB.h
 *	\brief AD Kernel for Mono-variate Population Balance Model with all coagulation coefficients
 *	\details This file creates a MOOSE AD kernel that will couple together multiple number
 *			concentrations of particles and calculate a population balance rate function
 *			assuming the collision efficiency and frequency are calculated from Brownian
 *			diffusion, Brownian convection enhancement, gravitational collection, turbulent 
 *			inertial motion, and turbulent shear functions.
 *
 *			Y.H. Kim, S. Yiacoumi, A. Nenes, C. Tsouris, J. Aero. Sci., 114, 283-300, 2017.
 *
 *			M.Z. Jacobson, Fundamentals of Atmospheric Modeling (2nd Ed.), Cambridge University
 *				Press, New York, 2005.
 *
 *  \author Alexander Wiechert
 *	\date 01/10/2022
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

//Non-functioning: Do Not Use (For Testing Only)

#include "ADAggregationMPB.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", ADAggregationMPB);

InputParameters ADAggregationMPB::validParams()
{
    InputParameters params = ADKernel::validParams();
    params.addParam<bool>("gama_correction",true,"Only change to false for testing purposes.");
    params.addRequiredParam< std::vector<Real> >("diameters","Set of particle diameters corresponding to each size bin (m) (Must have same order as the 'coupled_list')");
    params.addRequiredCoupledVar("coupled_list","List of names of the number concentration variables being coupled (including this variable)");
    params.addRequiredCoupledVar("main_variable","Name of the number concentration variable this kernel acts on");
    return params;
}

ADAggregationMPB::ADAggregationMPB(const InputParameters & parameters)
: ADKernel(parameters),
_dia(getParam<std::vector<Real> >("diameters")),
_u_var(coupled("main_variable")),
_gama_correction(getParam<bool>("gama_correction")),
_beta_Br(getADMaterialProperty<std::vector<std::vector<Real> > >("beta_Br")),
_alpha_Br(getADMaterialProperty<std::vector<std::vector<Real> > >("alpha_Br"))
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
    _gama.resize(_M);
    
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
        _frac[i].resize(_M);
        _alpha[i].resize(_M);
        _beta[i].resize(_M);
        _gama[i].resize(_M);
        for (int j=0; j<_M; j++)
        	_frac[i][j].resize(_M);
    }
    
    this->AlphaBetaFill();
    this->VolumeFill();
    this->FractionFill();
    this->GamaFill();
}

Real ADAggregationMPB::KroneckerDelta(int i, int j)
{
    if (i==j)
    	return 1.0;
    else
    	return 0.0;
}

void ADAggregationMPB::AlphaBetaFill()
{
    for (int l=0; l<_M; l++)
    {
        for (int m=0; m<_M; m++)
        {
            _beta[l][m] = _beta_Br[_qp][l][m];
            _alpha[l][m] = _alpha_Br[_qp][l][m];
        }
    }
}

void ADAggregationMPB::VolumeFill()
{
	
	Real pi = 3.14159;
    Real c = pi/6.0;
    for (int k=0; k<_M; k++)
    {
		_vol[k] = c*_dia[k]*_dia[k]*_dia[k];
    }
}

void ADAggregationMPB::FractionFill()
{
    for (int k=0; k<_M; k++)
    {
        for (int l=0; l<_M; l++)
        {
            for (int m=0; m<_M; m++)
            {
                if (k==0)
                {
                    Real combined = _vol[l]+_vol[m];
                    if (combined >= _vol[k] && combined <= _vol[k+1])
                    {
                        _frac[k][l][m] = (_vol[k+1] - combined) / (_vol[k+1] - _vol[k]);
                    }
                    else
                    {
                        _frac[k][l][m] = 0.0;
                    }
                }
                else if (k==_M-1)
                {
                    Real combined = _vol[l]+_vol[m];
                    if (combined >= _vol[k-1] && combined <= _vol[k])
                    {
                        _frac[k][l][m] = (combined - _vol[k-1]) / (_vol[k] - _vol[k-1]);
                    }
                    else
                    {
                        _frac[k][l][m] = 0.0;
                    }
                }
                else
                {
                    Real combined = _vol[l]+_vol[m];
                    if (combined >= _vol[k-1] && combined < _vol[k])
                    {
                        _frac[k][l][m] = (combined - _vol[k-1]) / (_vol[k] - _vol[k-1]);
                    }
                    else if (combined >= _vol[k] && combined <= _vol[k+1])
                    {
                        _frac[k][l][m] = (_vol[k+1] - combined) / (_vol[k+1] - _vol[k]);
                    }
                    else
                    {
                        _frac[k][l][m] = 0.0;
                    }
                }

            }
        }
    }
}

void ADAggregationMPB::GamaFill()
{
    for (int k=0; k<_M; k++)
    {
        for (int l=0; l<_M; l++)
        {
        	if ( (_vol[k]+_vol[l]) > _vol[_M-1] )
            	if (_gama_correction == true)
            		_gama[k][l] = 0.0;
                else
                	_gama[k][l] = 1.0;
            else
            	_gama[k][l] = 1.0;
        }
    }
}

ADReal ADAggregationMPB::computeQpResidual()
{
	ADReal rate = 0.0;
    ADReal source = 0.0;
    ADReal sink = 0.0;
    int k = _this_var;
    
    //Loop over all variables l
    for (int l=0; l<_M; l++)
    {
        sink += _gama[k][l]*_alpha[k][l]*_beta[k][l]*(*_coupled_u[l])[_qp];
        
        ADReal m_sum = 0.0;
        
        //Loop over m variables
        for (int m=0; m<=l; m++)
        {
            m_sum += (1.0-0.5*this->KroneckerDelta(l,m))*_frac[k][l][m]*_alpha[l][m]*_beta[l][m]*(*_coupled_u[m])[_qp];
        }
        source += m_sum*(*_coupled_u[l])[_qp];
    }
    rate = (_test[_i][_qp]*source - _test[_i][_qp]*_u[_qp]*sink);
    
    return -rate;
}
