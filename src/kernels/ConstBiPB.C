/*!
 *  \file ConstBiPB.h
 *	\brief Kernel for Bi-variate Population Balance Model with constant coefficients
 *	\details This file creates a MOOSE kernel that will couple together multiple number
 *			concentrations of particles and calculate a population balance rate function
 *			assuming the collision efficiency and frequency are known constants. This module
 *			is based on the following works:
 *
 *			Y.H. Kim, S. Yiacoumi, A. Nenes, C. Tsouris, J. Aero. Sci., 114, 283-300, 2017.
 *
 *			S. Kumar, D. Ramkrishna, Chem. Eng. Sci., 51, 1311-1332, 1996.
 *
 *			H.M. Vale, T.F. McKenna, Ind. Eng. Chem. Res., 44, 7885-7891, 2005.
 *
 *			NOTE: This module differs from the ConstMonoPB kernel in that the particles are
 *			not just distributed by size, but also by the number of total nuclides they contain.
 *			Thus, it involves a 'matrix-like' set of non-linear variables to be coupled together.
 *			The standard adopted for importing the 'matrix' of variables is to import them as an
 *			array storing all matrix elements in ROW MAJOR order.
 *
 *			e.g., coupled_list = 'N00 N01 ... N10 N11 ...'
 *
 *  \author Austin Ladshaw
 *	\date 08/16/2019
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

#include "ConstBiPB.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", ConstBiPB);

template<>
InputParameters validParams<ConstBiPB>()
{
    InputParameters params = validParams<Kernel>();
    params.addParam<Real>("efficiency",1.0,"Collision Efficiency (-)");
    params.addParam<Real>("frequency",1.0,"Collision Frequency (m^3/s)");
    params.addRequiredParam< std::vector<Real> >("diameters","Set of particle diameters corresponding to each size bin (m) (Must have same order as each row of 'coupled_list')");
    params.addRequiredParam< std::vector<Real> >("total_nuclides","Set of total nuclide numbers corresponding to each nuclide bin (mol) (Must have same order as each column of 'coupled_list')");
    params.addRequiredCoupledVar("coupled_list","List of names of the number concentration variables being coupled (including this variable)");
    params.addRequiredCoupledVar("main_variable","Name of the number concentration variable this kernel acts on");
    return params;
}

ConstBiPB::ConstBiPB(const InputParameters & parameters)
: Kernel(parameters),
_const_alpha(getParam<Real>("efficiency")),
_const_beta(getParam<Real>("frequency")),
_dia(getParam<std::vector<Real> >("diameters")),
_nuc(getParam<std::vector<Real> >("total_nuclides")),
_u_var(coupled("main_variable"))
{
    _MO = coupledComponents("coupled_list");
    _M = _dia.size();
    _O = _nuc.size();
    if (_MO != _M*_O)
        moose::internal::mooseErrorRaw("Number of coupled variables does not match total number of bins!");
    
    _coupled_u_var.resize(_MO);
    _coupled_u.resize(_MO);
    
    _frac.resize(_MO);
    _alpha.resize(_MO);
    _beta.resize(_MO);
    _vol.resize(_M);
    _gama.resize(_MO);
    
    for (unsigned int i = 0; i<_coupled_u.size(); ++i)
    {
        _coupled_u_var[i] = coupled("coupled_list",i);
        _coupled_u[i] = &coupledValue("coupled_list",i);
        // How to refer to the value of the coupled variable list:   _u_coupled[_qp] == (*_coupled_u[i])[_qp]   for each i
    }
    
    for (int i=0; i<_MO; i++)
    {
        _frac[i].resize(_MO);
        _alpha[i].resize(_MO);
        _beta[i].resize(_MO);
        _gama[i].resize(_MO);
        for (int j=0; j<_MO; j++)
            _frac[i][j].resize(_MO);
    }
    
    this->AlphaBetaFill();
    this->VolumeFill();
    this->FractionFill();
    this->GamaFill();
}

Real ConstBiPB::KroneckerDelta(int i, int j)
{
    if (i==j)
        return 1.0;
    else
        return 0.0;
}

void ConstBiPB::AlphaBetaFill()
{
    for (int lm=0; lm<_MO; lm++)
    {
        for (int qr=0; qr<_MO; qr++)
        {
            _alpha[lm][qr] = _const_alpha;
            _beta[lm][qr] = _const_beta;
        }
    }
}

void ConstBiPB::VolumeFill()
{
    Real pi = 3.14159;
    Real c = pi/6.0;
    for (int k=0; k<_M; k++)
    {
        _vol[k] = c*_dia[k]*_dia[k]*_dia[k];
    }
}

void ConstBiPB::FractionFill()
{
	int k, p, l, m, q, r;
	for (int kp=0; kp<_MO; kp++)
    {
    	this->RowCol(kp, k, p);
        for (int lm=0; lm<_MO; lm++)
        {
        	this->RowCol(lm, l, m);
            for (int qr=0; qr<_MO; qr++)
            {
            	this->RowCol(qr, q, r);
                Real tot_vol = _vol[l] + _vol[q];
                Real tot_nuc = _nuc[m] + _nuc[r];
                
                //Check 9 possible edge cases
                if (k==0)
                {
                    if (p==0)
                    {
                        if ( (tot_vol >= _vol[k] && tot_vol <= _vol[k+1]) && (tot_nuc >= _nuc[p] && tot_nuc <= _nuc[p+1]) )
                        {
                            _frac[kp][lm][qr] = ((_vol[k+1]-tot_vol)/(_vol[k+1]-_vol[k]))*((_nuc[p+1]-tot_nuc)/(_nuc[p+1]-_nuc[p]));
                        }
                        else
                        {
                            _frac[kp][lm][qr] = 0.0;
                        }
                    }
                    else if (p==_O-1)
                    {
                        if ( (tot_vol >= _vol[k] && tot_vol <= _vol[k+1]) && (tot_nuc >= _nuc[p-1] && tot_nuc <= _nuc[p]) )
                        {
                            _frac[kp][lm][qr] = ((_vol[k+1]-tot_vol)/(_vol[k+1]-_vol[k]))*((tot_nuc-_nuc[p-1])/(_nuc[p]-_nuc[p-1]));
                        }
                        else
                        {
                            _frac[kp][lm][qr] = 0.0;
                        }
                    }
                    else
                    {
                        if ( (tot_vol >= _vol[k] && tot_vol <= _vol[k+1]) && (tot_nuc >= _nuc[p-1] && tot_nuc < _nuc[p]) )
                        {
                            _frac[kp][lm][qr] = ((_vol[k+1]-tot_vol)/(_vol[k+1]-_vol[k]))*((tot_nuc-_nuc[p-1])/(_nuc[p]-_nuc[p-1]));
                        }
                        else if ( (tot_vol >= _vol[k] && tot_vol <= _vol[k+1]) && (tot_nuc >= _nuc[p] && tot_nuc <= _nuc[p+1]) )
                        {
                            _frac[kp][lm][qr] = ((_vol[k+1]-tot_vol)/(_vol[k+1]-_vol[k]))*((_nuc[p+1]-tot_nuc)/(_nuc[p+1]-_nuc[p]));
                        }
                        else
                        {
                            _frac[kp][lm][qr] = 0.0;
                        }
                    }
                }
                else if (k==_M-1)
                {
                    if (p==0)
                    {
                        if ( (tot_vol >= _vol[k-1] && tot_vol <= _vol[k]) && (tot_nuc >= _nuc[p] && tot_nuc <= _nuc[p+1]) )
                        {
                            _frac[kp][lm][qr] = ((tot_vol-_vol[k-1])/(_vol[k]-_vol[k-1]))*((_nuc[p+1]-tot_nuc)/(_nuc[p+1]-_nuc[p]));
                        }
                        else
                        {
                            _frac[kp][lm][qr] = 0.0;
                        }
                    }
                    else if (p==_O-1)
                    {
                        if ( (tot_vol >= _vol[k-1] && tot_vol <= _vol[k]) && (tot_nuc >= _nuc[p-1] && tot_nuc <= _nuc[p]) )
                        {
                            _frac[kp][lm][qr] = ((tot_vol-_vol[k-1])/(_vol[k]-_vol[k-1]))*((tot_nuc-_nuc[p-1])/(_nuc[p]-_nuc[p-1]));
                        }
                        else
                        {
                            _frac[kp][lm][qr] = 0.0;
                        }
                    }
                    else
                    {
                        if ( (tot_vol >= _vol[k-1] && tot_vol <= _vol[k]) && (tot_nuc >= _nuc[p-1] && tot_nuc < _nuc[p]) )
                        {
                            _frac[kp][lm][qr] = ((tot_vol-_vol[k-1])/(_vol[k]-_vol[k-1]))*((tot_nuc-_nuc[p-1])/(_nuc[p]-_nuc[p-1]));
                        }
                        else if ( (tot_vol >= _vol[k-1] && tot_vol <= _vol[k]) && (tot_nuc >= _nuc[p] && tot_nuc <= _nuc[p+1]) )
                        {
                            _frac[kp][lm][qr] = ((tot_vol-_vol[k-1])/(_vol[k]-_vol[k-1]))*((_nuc[p+1]-tot_nuc)/(_nuc[p+1]-_nuc[p]));
                        }
                        else
                        {
                            _frac[kp][lm][qr] = 0.0;
                        }
                    }
                }
                else
                {
                    if (p==0)
                    {
                        if ( (tot_vol >= _vol[k-1] && tot_vol < _vol[k]) && (tot_nuc >= _nuc[p] && tot_nuc <= _nuc[p+1]) )
                        {
                            _frac[kp][lm][qr] = ((tot_vol-_vol[k-1])/(_vol[k]-_vol[k-1]))*((_nuc[p+1]-tot_nuc)/(_nuc[p+1]-_nuc[p]));
                        }
                        else if ( (tot_vol >= _vol[k] && tot_vol <= _vol[k+1]) && (tot_nuc >= _nuc[p] && tot_nuc <= _nuc[p+1]) )
                        {
                            _frac[kp][lm][qr] = ((_vol[k+1]-tot_vol)/(_vol[k+1]-_vol[k]))*((_nuc[p+1]-tot_nuc)/(_nuc[p+1]-_nuc[p]));
                        }
                        else
                        {
                            _frac[kp][lm][qr] = 0.0;
                        }
                    }
                    else if (p==_O-1)
                    {
                        if ( (tot_vol >= _vol[k-1] && tot_vol < _vol[k]) && (tot_nuc >= _nuc[p-1] && tot_nuc <= _nuc[p]) )
                        {
                            _frac[kp][lm][qr] = ((tot_vol-_vol[k-1])/(_vol[k]-_vol[k-1]))*((tot_nuc-_nuc[p-1])/(_nuc[p]-_nuc[p-1]));
                        }
                        else if ( (tot_vol >= _vol[k] && tot_vol <= _vol[k+1]) && (tot_nuc >= _nuc[p-1] && tot_nuc <= _nuc[p]) )
                        {
                            _frac[kp][lm][qr] = ((_vol[k+1]-tot_vol)/(_vol[k+1]-_vol[k]))*((tot_nuc-_nuc[p-1])/(_nuc[p]-_nuc[p-1]));
                        }
                        else
                        {
                            _frac[kp][lm][qr] = 0.0;
                        }
                    }
                    else
                    {
                        if ( (tot_vol >= _vol[k-1] && tot_vol < _vol[k]) && (tot_nuc >= _nuc[p-1] && tot_nuc < _nuc[p]) )
                        {
                            _frac[kp][lm][qr] = ((tot_vol-_vol[k-1])/(_vol[k]-_vol[k-1]))*((tot_nuc-_nuc[p-1])/(_nuc[p]-_nuc[p-1]));
                        }
                        else if ( (tot_vol >= _vol[k] && tot_vol <= _vol[k+1]) && (tot_nuc >= _nuc[p-1] && tot_nuc < _nuc[p]) )
                        {
                            _frac[kp][lm][qr] = ((_vol[k+1]-tot_vol)/(_vol[k+1]-_vol[k]))*((tot_nuc-_nuc[p-1])/(_nuc[p]-_nuc[p-1]));
                        }
                        else if ( (tot_vol >= _vol[k-1] && tot_vol < _vol[k]) && (tot_nuc >= _nuc[p] && tot_nuc <= _nuc[p+1]) )
                        {
                            _frac[kp][lm][qr] = ((tot_vol-_vol[k-1])/(_vol[k]-_vol[k-1]))*((_nuc[p+1]-tot_nuc)/(_nuc[p+1]-_nuc[p]));
                        }
                        else if ( (tot_vol >= _vol[k] && tot_vol <= _vol[k+1]) && (tot_nuc >= _nuc[p] && tot_nuc <= _nuc[p+1]) )
                        {
                            _frac[kp][lm][qr] = ((_vol[k+1]-tot_vol)/(_vol[k+1]-_vol[k]))*((_nuc[p+1]-tot_nuc)/(_nuc[p+1]-_nuc[p]));
                        }
                        else
                        {
                            _frac[kp][lm][qr] = 0.0;
                        }
                    }
                }
                /*
                if (_frac[kp][lm][qr] > 0.0)
                {
                	std::cout << "\nk = " << k << "\tp = " << p << std::endl;
                	std::cout << "l = " << l << "\tm = " << m << std::endl;
                	std::cout << "q = " << q << "\tr = " << r << std::endl;
                	std::cout << "eta = " << _frac[kp][lm][qr] << std::endl;
                }
                */
            }
        }
    }
}

void ConstBiPB::GamaFill()
{
    int k, p, l, m;
    for (int kp=0; kp<_MO; kp++)
    {
        this->RowCol(kp, k, p);
        for (int lm=0; lm<_MO; lm++)
        {
            this->RowCol(lm, l, m);
            if ( (_vol[k]+_vol[l]) > _vol[_M-1] || (_nuc[p]+_nuc[m]) > _nuc[_O-1] )
            {
                _gama[kp][lm] = 0.0;
            }
            else
            {
                _gama[kp][lm] = 1.0;
            }
            /*
            if (_gama[kp][lm] > 0.0)
            {
            	std::cout << "\nk = " << k << "\tp = " << p << std::endl;
            	std::cout << "l = " << l << "\tm = " << m << std::endl;
            	std::cout << "gama = " << _gama[kp][lm] << std::endl;
            }
            */
        }
    }
}

int ConstBiPB::ArrayIndex(int k, int p)
{
    return (k*_O)+p;
}

void ConstBiPB::RowCol(int i, int & k, int & p)
{
    k = (int)i/_M;
    p = i - (k*_O);
}

Real ConstBiPB::computeQpResidual()
{
	Real rate = 0.0;
    Real source = 0.0;
    Real sink = 0.0;
    int kp = _u_var;
    int k, p, l, m, q, r;
    
    this->RowCol(kp, k, p);
    //Loop over all variables lm
    for (int lm=0; lm<_MO; lm++)
    {
    	this->RowCol(lm, l, m);
    	sink += _gama[kp][lm]*_alpha[kp][lm]*_beta[kp][lm]*(*_coupled_u[lm])[_qp];
        
    	Real qr_sum = 0.0;
        //Loop over qr
        for (int qr=0; qr<_MO; qr++)
        {
        	this->RowCol(qr, q, r);
            if (q<l && r<m)
            	break;
            
            qr_sum += (1.0-0.5*this->KroneckerDelta(l,q)*this->KroneckerDelta(m,r))*_frac[kp][lm][qr]*_alpha[lm][qr]*_beta[lm][qr]*(*_coupled_u[qr])[_qp];
        }
        source += qr_sum*(*_coupled_u[lm])[_qp];
    }
	rate = (_test[_i][_qp]*source - _test[_i][_qp]*_u[_qp]*sink);

	return -rate;
}

Real ConstBiPB::computeQpJacobian()
{
	int kp = _u_var;
    Real qr_sum = 0.0;
    Real lm_sum_source = 0.0;
    Real lm_sum_sink = 0.0;
    int k, p, l, m, q, r;
    
    this->RowCol(kp, k, p);
    //Loop over qr
    for (int qr=0; qr<_MO; qr++)
    {
        this->RowCol(qr, q, r);
        if (q<k && r<p)
            break;
        qr_sum += (1.0+this->KroneckerDelta(k,q)*this->KroneckerDelta(p,r))*(1.0-0.5*this->KroneckerDelta(k,q)*this->KroneckerDelta(p,r))*_frac[kp][kp][qr]*_alpha[kp][qr]*_beta[kp][qr]*(*_coupled_u[qr])[_qp];
    }
    
    //Loop over lm
    for (int lm=0; lm<_MO; lm++)
    {
    	this->RowCol(lm, l, m);
        if (lm!=kp)
        {
            lm_sum_source += (*_coupled_u[lm])[_qp]*(1.0-0.5*this->KroneckerDelta(l,k)*this->KroneckerDelta(m,p))*_frac[kp][lm][kp]*_alpha[lm][kp]*_beta[lm][kp];
            lm_sum_sink += _gama[kp][lm]*_alpha[kp][lm]*_beta[kp][lm]*(*_coupled_u[lm])[_qp];
        }
    }
    
	return -(_test[_i][_qp]*_phi[_j][_qp]*qr_sum + _test[_i][_qp]*_phi[_j][_qp]*lm_sum_source - _test[_i][_qp]*_phi[_j][_qp]*lm_sum_sink - _test[_i][_qp]*2.0*_phi[_j][_qp]*_gama[kp][kp]*_alpha[kp][kp]*_beta[kp][kp]*_u[_qp]);
}

Real ConstBiPB::computeQpOffDiagJacobian(unsigned int jvar)
{
	int ho = jvar;
    int kp = _u_var;
    Real qr_sum = 0.0;
    Real lm_sum_source = 0.0;
    int k, p, l, m, q, r, h, o;
    
    this->RowCol(kp, k, p);
    this->RowCol(ho, h, o);
    //Loop over qr
    for (int qr=0; qr<_MO; qr++)
    {
        this->RowCol(qr, q, r);
        if (q<h && r<o)
            break;
        qr_sum += (1.0+this->KroneckerDelta(h,q)*this->KroneckerDelta(o,r))*(1.0-0.5*this->KroneckerDelta(h,q)*this->KroneckerDelta(o,r))*_frac[kp][ho][qr]*_alpha[ho][qr]*_beta[ho][qr]*(*_coupled_u[qr])[_qp];
    }
    
    //Loop over lm
    for (int lm=0; lm<_MO; lm++)
    {
        this->RowCol(lm, l, m);
        if (lm!=ho)
        {
        	lm_sum_source += (*_coupled_u[lm])[_qp]*(1.0-0.5*this->KroneckerDelta(l,h)*this->KroneckerDelta(m,o))*_frac[kp][lm][ho]*_alpha[lm][ho]*_beta[lm][ho];
        }
    }
    
	return -(_test[_i][_qp]*_phi[_j][_qp]*qr_sum + _test[_i][_qp]*_phi[_j][_qp]*lm_sum_source - _test[_i][_qp]*_phi[_j][_qp]*_gama[kp][ho]*_alpha[kp][ho]*_beta[kp][ho]*(*_coupled_u[kp])[_qp]);
}
