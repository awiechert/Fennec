/*!
 *  \file BrownianMonoPB.h
 *	\brief Kernel for Mono-variate Population Balance Model with Brownian coefficients
 *	\details This file creates a MOOSE kernel that will couple together multiple number
 *			concentrations of particles and calculate a population balance rate function
 *			assuming the collision efficiency and frequency are calculated from the Brownian
 *			functions.
 *
 *			Y.H. Kim, S. Yiacoumi, A. Nenes, C. Tsouris, J. Aero. Sci., 114, 283-300, 2017.
 *
 *			M.Z. Jacobson, Fundamentals of Atmospheric Modeling (2nd Ed.), Cambridge University
 *				Press, New York, 2005.
 *
 *  \author Austin Ladshaw
 *	\date 10/07/2019
 *	\copyright This kernel was designed and built at the Georgia Institute
 *             of Technology by Austin Ladshaw for PhD research in the area
 *             of radioactive particle transport and settling following a
 *			   nuclear event. It was developed for the US DOD under DTRA
 *			   project No. 14-24-FRCWMD-BAA. Portions Copyright (c) 2019, all
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

#include "BrownianMonoPB.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", BrownianMonoPB);

template<>
InputParameters validParams<BrownianMonoPB>()
{
    InputParameters params = validParams<Kernel>();
    params.addParam<bool>("alpha_correction",true,"Only change to false for testing purposes.");
    params.addRequiredCoupledVar("coupled_list","List of names of the number concentration variables being coupled (including this variable)");
    params.addRequiredCoupledVar("main_variable","Name of the number concentration variable this kernel acts on");
    return params;
}

BrownianMonoPB::BrownianMonoPB(const InputParameters & parameters)
: Kernel(parameters),
_u_var(coupled("main_variable")),
_diameter(getMaterialProperty<std::vector<Real> >("diameter")),
_beta_Br(getMaterialProperty<std::vector<std::vector<Real> > >("beta_Br")),
_alpha_Br(getMaterialProperty<std::vector<std::vector<Real> > >("alpha_Br")),
_useAlpha(getParam<bool>("alpha_correction"))
{
    _M = coupledComponents("coupled_list");
    
    _coupled_u_var.resize(_M);
    _coupled_u.resize(_M);
    _frac.resize(_M);
    _alpha.resize(_M);
    _beta.resize(_M);
    _vol.resize(_M);
    _dia.resize(_M);
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
    
    _setup = true;
}


Real BrownianMonoPB::KroneckerDelta(int i, int j)
{
    if (i==j)
        return 1.0;
    else
        return 0.0;
}

void BrownianMonoPB::AlphaBetaFill()
{
    for (int l=0; l<_M; l++)
    {
        for (int m=0; m<_M; m++)
        {
        	if (_useAlpha == true)
            {
            	_alpha[l][m] = _alpha_Br[_qp][l][m];
            }
            else
            	_alpha[l][m] = 1.0;
            _beta[l][m] = _beta_Br[_qp][l][m];
        }
    }
}

void BrownianMonoPB::VolumeFill()
{
    Real pi = 3.14159;
    Real c = pi/6.0;
    for (int k=0; k<_M; k++)
    {
    	_dia[k] = _diameter[_qp][k];
        _vol[k] = c*_dia[k]*_dia[k]*_dia[k];
    }
}

void BrownianMonoPB::FractionFill()
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

void BrownianMonoPB::GamaFill()
{
    for (int k=0; k<_M; k++)
    {
        for (int l=0; l<_M; l++)
        {
            if ( (_vol[k]+_vol[l]) > _vol[_M-1] )
                _gama[k][l] = 0.0;
            else
                _gama[k][l] = 1.0;
        }
    }
}

Real BrownianMonoPB::computeQpResidual()
{
	if (_setup == true)
    {
    	if (_M != _diameter[_qp].size())
    		moose::internal::mooseErrorRaw("Number of coupled variables does not match number of particle size bins!");
    
    	this->VolumeFill();
    	this->FractionFill();
   	 	this->GamaFill();
        _setup = false;
    }
    this->AlphaBetaFill();
    
    if (_u[_qp] > 0.0)
    {
    	Real rate = 0.0;
    	Real source = 0.0;
    	Real sink = 0.0;
    	int k = _this_var;
    
    	//Loop over all variables l
    	for (int l=0; l<_M; l++)
    	{
    		if ((*_coupled_u[l])[_qp] > 0.0)
        		sink += _gama[k][l]*_alpha[k][l]*_beta[k][l]*((*_coupled_u[l])[_qp]);
        
        	Real m_sum = 0.0;
        
        	//Loop over m variables
        	for (int m=0; m<=l; m++)
        	{
        		if ((*_coupled_u[m])[_qp] > 0.0)
            		m_sum += (1.0-0.5*this->KroneckerDelta(l,m))*_frac[k][l][m]*_alpha[l][m]*_beta[l][m]*((*_coupled_u[m])[_qp]);
        	}
        	if ((*_coupled_u[l])[_qp] > 0.0)
        		source += m_sum*((*_coupled_u[l])[_qp]);
    	}
    	rate = _test[_i][_qp]*source;
    	if (_u[_qp] > 0.0)
    		rate += - _test[_i][_qp]*(_u[_qp])*sink;
    
    	return -rate;
    }
    else
    	return 10.0*_test[_i][_qp]*(_u[_qp]);
}

Real BrownianMonoPB::computeQpJacobian()
{
    // Partial Derivatives with respect to this variable
    int k = _this_var;
    if (_u[_qp] > 0.0)
    {
    	Real m_sum = 0.0;
    	Real l_sum_source = 0.0;
    	Real l_sum_sink = 0.0;
    
    	for (int m=0; m<=k; m++)
    	{
    		if ((*_coupled_u[m])[_qp] > 0.0)
        		m_sum += (1.0+this->KroneckerDelta(k,m))*(1.0-0.5*this->KroneckerDelta(k,m))*_frac[k][k][m]*_alpha[k][m]*_beta[k][m]*((*_coupled_u[m])[_qp]);
    	}
    
    	for (int l=0; l<_M; l++)
    	{
        	if (l!=k)
        	{
        		if ((*_coupled_u[l])[_qp] > 0.0)
            	{
            		l_sum_source += ((*_coupled_u[l])[_qp])*(1.0-0.5*this->KroneckerDelta(l,k))*_frac[k][l][k]*_alpha[l][k]*_beta[l][k];
            		l_sum_sink += _gama[k][l]*_alpha[k][l]*_beta[k][l]*((*_coupled_u[l])[_qp]);
            	}
        	}
    	}
		Real jac =_test[_i][_qp]*_phi[_j][_qp]*m_sum + _test[_i][_qp]*_phi[_j][_qp]*l_sum_source - _test[_i][_qp]*_phi[_j][_qp]*l_sum_sink;
    
    	if (_u[_qp] > 0.0)
    		jac += -_test[_i][_qp]*2.0*_phi[_j][_qp]*_gama[k][k]*_alpha[k][k]*_beta[k][k]*(_u[_qp]);
    
    	return -jac;
    }
    else
    	return 10.0*_test[_i][_qp]*_phi[_j][_qp];
}

Real BrownianMonoPB::computeQpOffDiagJacobian(unsigned int jvar)
{
    // Partial Derivatives with respect to other variables
    int h = _those_var[jvar];
    int k = _this_var;
    if (_u[_qp] > 0.0)
    {
    	Real m_sum = 0.0;
    	Real l_sum_source = 0.0;
    
    	for (int m=0; m<=h; m++)
    	{
    		if ((*_coupled_u[m])[_qp] > 0.0)
        		m_sum += (1.0+this->KroneckerDelta(h,m))*(1.0-0.5*this->KroneckerDelta(h,m))*_frac[k][h][m]*_alpha[h][m]*_beta[h][m]*((*_coupled_u[m])[_qp]);
    	}
    
    	for (int l=0; l<_M; l++)
    	{
        	if (l!=h)
        	{
        		if ((*_coupled_u[l])[_qp] > 0.0)
            		l_sum_source += ((*_coupled_u[l])[_qp])*(1.0-0.5*this->KroneckerDelta(l,h))*_frac[k][l][h]*_alpha[l][h]*_beta[l][h];
        	}
    	}
    	Real jac =_test[_i][_qp]*_phi[_j][_qp]*m_sum + _test[_i][_qp]*_phi[_j][_qp]*l_sum_source;
    	if ((*_coupled_u[k])[_qp] > 0.0)
    		jac += -_test[_i][_qp]*_phi[_j][_qp]*_gama[k][h]*_alpha[k][h]*_beta[k][h]*((*_coupled_u[k])[_qp]);
    	return -jac;
    }
    else
    	return 0.0;
}

