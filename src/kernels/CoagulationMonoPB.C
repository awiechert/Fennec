/*!
 *  \file CoagulationMonoPB.h
 *	\brief Kernel for Mono-variate Population Balance Model with all coagulation coefficients
 *	\details This file creates a MOOSE kernel that will couple together multiple number
 *			concentrations of particles and calculate a population balance rate function
 *			assuming the collision efficiency and frequency are calculated from Brownian
 *			diffusion, Brownian convection, gravitational collection, turbulent inertial
 * 			motion, and turbulent shear functions.
 *
 *			Y.H. Kim, S. Yiacoumi, A. Nenes, C. Tsouris, J. Aero. Sci., 114, 283-300, 2017.
 *
 *			M.Z. Jacobson, Fundamentals of Atmospheric Modeling (2nd Ed.), Cambridge University
 *				Press, New York, 2005.
 *
 *  \author Alexander Wiechert and Austin Ladshaw
 *	\date 04/09/2020
 *	\copyright This kernel was designed and built at the Georgia Institute
 *             of Technology by Alexander Wiechert and Austin Ladshaw for 
 *			   research in the area of radioactive particle transport and 
 *             settling following a nuclear event. It was developed for the 
 *			   US DOD under DTRA project No. 14-24-FRCWMD-BAA. Portions 
 *			   Copyright (c) 2019, all rights reserved.
 *
 *			   Alexander Wiechert and Austin Ladshaw does not claim any 
 *			   ownership or copyright to the MOOSE framework in which these 
 *			   kernels are constructed, only the kernels themselves. The MOOSE 
 *			   framework copyright is held by the Battelle Energy Alliance, 
 *	           LLC (c) 2010, all rights reserved.
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

#include "CoagulationMonoPB.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */

registerMooseObject("fennecApp", CoagulationMonoPB);

template<>
InputParameters validParams<CoagulationMonoPB>()
{
    InputParameters params = validParams<Kernel>();
    params.addParam<Real>("alpha_TS",1.0,"Turbulent Shear Collision Efficiency (-)");
    params.addParam<Real>("alpha_TI",1.0,"Turbulent Inertial Motion Collision Efficiency (-)");
    params.addParam<bool>("alpha_correction",true,"Only change to false for testing purposes.");
    params.addParam<bool>("PBM_FullImplicit",true,"true = full implicit coupling (slow), false = semi-implicit coupling (fast)");
    params.addRequiredCoupledVar("coupled_list","List of names of the number concentration variables being coupled (including this variable)");
    params.addRequiredCoupledVar("main_variable","Name of the number concentration variable this kernel acts on");
    return params;
}

CoagulationMonoPB::CoagulationMonoPB(const InputParameters & parameters)
: Kernel(parameters),
_alpha_TI(getParam<Real>("alpha_TI")),
_alpha_TS(getParam<Real>("alpha_TS")),
_u_var(coupled("main_variable")),
_diameter(getMaterialProperty<std::vector<Real> >("diameter")),
_beta_Br(getMaterialProperty<std::vector<std::vector<Real> > >("beta_Br")),
_alpha_Br(getMaterialProperty<std::vector<std::vector<Real> > >("alpha_Br")),
_beta_Ce(getMaterialProperty<std::vector<std::vector<Real> > >("beta_CE")),
_beta_Gc(getMaterialProperty<std::vector<std::vector<Real> > >("beta_GC")),
_alpha_Gc(getMaterialProperty<std::vector<std::vector<Real> > >("alpha_GC")),
_beta_TI(getMaterialProperty<std::vector<std::vector<Real> > >("beta_TI")),
_beta_TS(getMaterialProperty<std::vector<std::vector<Real> > >("beta_TS")),
_useAlpha(getParam<bool>("alpha_correction")),
_useFullImplicit(getParam<bool>("PBM_FullImplicit"))
{
    _M = coupledComponents("coupled_list");
    
    _coupled_u_var.resize(_M);
    _coupled_u.resize(_M);
    _frac.resize(_M);
    _alpha_beta.resize(_M);
    _vol.resize(_M);
    _dia.resize(_M);
    _gama.resize(_M);
    
    for (unsigned int i = 0; i<_coupled_u.size(); ++i)
    {
        _coupled_u_var[i] = coupled("coupled_list",i);
        if (_useFullImplicit == true)
            _coupled_u[i] = &coupledValue("coupled_list",i);   		//FULL Implicit (Slow convergence: Error ~<1%)
        else
            _coupled_u[i] = &coupledValueOld("coupled_list",i);   //SEMI-Explicit (Fast convergence: Error ~5-10%)
        _those_var[_coupled_u_var[i]] = i;
        
        if (_coupled_u_var[i] == _u_var)
            _this_var = i;
        // How to refer to the value of the coupled variable list:   _u_coupled[_qp] == (*_coupled_u[i])[_qp]   for each i
    }
    
    for (int i=0; i<_M; i++)
    {
        _frac[i].resize(_M);
        _alpha_beta[i].resize(_M);
        _gama[i].resize(_M);
        for (int j=0; j<_M; j++)
            _frac[i][j].resize(_M);
    }
    
    _setup = true;
}


Real CoagulationMonoPB::KroneckerDelta(int i, int j)
{
    if (i==j)
        return 1.0;
    else
        return 0.0;
}

void CoagulationMonoPB::AlphaBetaFill()
{
    for (int l=0; l<_M; l++)
    {
        for (int m=0; m<_M; m++)
        {
        	if (_useAlpha == true)
            {
            	_alpha_beta[l][m] = _alpha_Br[_qp][l][m]*_beta_Br[_qp][l][m]+_alpha_Br[_qp][l][m]*_beta_Ce[_qp][l][m]+_alpha_Gc[_qp][l][m]*_beta_Gc[_qp][l][m]+_alpha_TI*_beta_TI[_qp][l][m]+_alpha_TS*_beta_TS[_qp][l][m];
            }
            else
            {
                _alpha_beta[l][m] = _beta_Br[_qp][l][m]+_beta_Ce[_qp][l][m]+_beta_Gc[_qp][l][m]+_beta_TI[_qp][l][m]+_beta_TS[_qp][l][m];
            }
        }
    }
}

void CoagulationMonoPB::VolumeFill()
{
    Real pi = 3.14159;
    Real c = pi/6.0;
    for (int k=0; k<_M; k++)
    {
        _dia[k] = _diameter[_qp][k];
        _vol[k] = c*_dia[k]*_dia[k]*_dia[k];
    }
}

void CoagulationMonoPB::FractionFill()
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

void CoagulationMonoPB::GamaFill()
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

Real CoagulationMonoPB::computeQpResidual()
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
    
    
    /** NOTE: This scheme is SEMI-EXPLICIT and makes use of OLD states of variables to improve convergence.
     As such, it is likely only 1st order accurate in time. See ConstMonoPB.C for the full implicit
     version of the code.
     */
    Real rate = 0.0;
    Real source = 0.0;
    Real sink = 0.0;
    int k = _this_var;
    
    //Loop over all variables l
    for (int l=0; l<_M; l++)
    {
        sink += _gama[k][l]*_alpha_beta[k][l]*fabs((*_coupled_u[l])[_qp]);
        
        Real m_sum = 0.0;
        
        //Loop over m variables
        for (int m=0; m<=l; m++)
        {
            m_sum += (1.0-0.5*this->KroneckerDelta(l,m))*_frac[k][l][m]*_alpha_beta[l][m]*fabs((*_coupled_u[m])[_qp]);
        }
        source += m_sum*fabs((*_coupled_u[l])[_qp]);
    }
    rate = _test[_i][_qp]*source;
    
    rate += - _test[_i][_qp]*_u[_qp]*sink;
    
    return -rate;
}

Real CoagulationMonoPB::computeQpJacobian()
{
    /*
     // Partial Derivatives with respect to this variable
     int k = _this_var;
     
     //if (_u[_qp] > 0.0)
     //{
    	Real m_sum = 0.0;
    	Real l_sum_source = 0.0;
    	Real l_sum_sink = 0.0;
     
    	for (int m=0; m<=k; m++)
    	{
     //if ((*_coupled_u[m])[_qp] > 0.0)
     m_sum += (1.0+this->KroneckerDelta(k,m))*(1.0-0.5*this->KroneckerDelta(k,m))*_frac[k][k][m]*_alpha_beta[k][m]*((*_coupled_u[m])[_qp]);
    	}
     
    	for (int l=0; l<_M; l++)
    	{
     if (l!=k)
     {
     //if ((*_coupled_u[l])[_qp] > 0.0)
     {
     l_sum_source += ((*_coupled_u[l])[_qp])*(1.0-0.5*this->KroneckerDelta(l,k))*_frac[k][l][k]*_alpha_beta[l][k];
     l_sum_sink += _gama[k][l]*_alpha_beta[k][l]*((*_coupled_u[l])[_qp]);
     }
     }
    	}
     Real jac =_test[_i][_qp]*_phi[_j][_qp]*m_sum + _test[_i][_qp]*_phi[_j][_qp]*l_sum_source - _test[_i][_qp]*_phi[_j][_qp]*l_sum_sink;
     
    	//if (_u[_qp] > 0.0)
     jac += -_test[_i][_qp]*2.0*_phi[_j][_qp]*_gama[k][k]*_alpha_beta[k][k]*(_u[_qp]);
     
    	return -jac;
     //}
     //else
    	//return 10.0*_test[_i][_qp]*_phi[_j][_qp];
     */
    
    int k = _this_var;
    Real l_sum_sink = 0.0;
    
    for (int l=0; l<_M; l++)
    {
        
        l_sum_sink += _gama[k][l]*_alpha_beta[k][l]*fabs((*_coupled_u[l])[_qp]);
    }
    
    return _test[_i][_qp]*l_sum_sink*_phi[_j][_qp];
    
    //Preconditioning with this kernel seems to not work
    //return 0.0;
}

Real CoagulationMonoPB::computeQpOffDiagJacobian(unsigned int jvar)
{
    // Partial Derivatives with respect to other variables
    /*
     int h = _those_var[jvar];
     int k = _this_var;
     if (_u[_qp] > 0.0)
     {
    	Real m_sum = 0.0;
    	Real l_sum_source = 0.0;
     
    	for (int m=0; m<=h; m++)
    	{
     if ((*_coupled_u[m])[_qp] > 0.0)
     m_sum += (1.0+this->KroneckerDelta(h,m))*(1.0-0.5*this->KroneckerDelta(h,m))*_frac[k][h][m]*_alpha_beta[h][m]*((*_coupled_u[m])[_qp]);
    	}
     
    	for (int l=0; l<_M; l++)
    	{
     if (l!=h)
     {
     if ((*_coupled_u[l])[_qp] > 0.0)
     l_sum_source += ((*_coupled_u[l])[_qp])*(1.0-0.5*this->KroneckerDelta(l,h))*_frac[k][l][h]*_alpha_beta[l][h];
     }
    	}
    	Real jac =_test[_i][_qp]*_phi[_j][_qp]*m_sum + _test[_i][_qp]*_phi[_j][_qp]*l_sum_source;
    	if ((*_coupled_u[k])[_qp] > 0.0)
     jac += -_test[_i][_qp]*_phi[_j][_qp]*_gama[k][h]*_alpha_beta[k][h]*((*_coupled_u[k])[_qp]);
    	return -jac;
     }
     else
    	return 0.0;
     */
    
    //Preconditioning with this kernel seems to not work
    return 0.0;
}

