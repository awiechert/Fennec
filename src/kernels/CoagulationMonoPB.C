/*!
 *  \file CoagulationMonoPB.h
 *	\brief Kernel for Mono-variate Population Balance Model with all coagulation coefficients
 *	\details This file creates a MOOSE kernel that will couple together multiple number
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
 *	\date 04/22/2020
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
    InputParameters params = validParams<BrownianConvecMonoPB>();
    params.addParam<Real>("alpha_TI",1.0,"Collision Efficiency for Turbulent Inertial Motion (-)");
    params.addParam<Real>("alpha_TS",1.0,"Collision Efficiency for Turbulent Shear (-)");
    return params;

}

CoagulationMonoPB::CoagulationMonoPB(const InputParameters & parameters)
: BrownianConvecMonoPB(parameters),
_alpha_TI(getParam<Real>("alpha_TI")),
_alpha_TS(getParam<Real>("alpha_TS")),
_beta_GC(getMaterialProperty<std::vector<std::vector<Real> > >("beta_GC")),
_beta_TI(getMaterialProperty<std::vector<std::vector<Real> > >("beta_TI")),
_beta_TS(getMaterialProperty<std::vector<std::vector<Real> > >("beta_TS")),
_alpha_GC(getMaterialProperty<std::vector<std::vector<Real> > >("alpha_GC")),
_beta_VW(getMaterialProperty<std::vector<std::vector<Real> > >("beta_VW"))
{

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
        	Real BM = _alpha_Br[_qp][l][m]*_beta_Br[_qp][l][m];
            Real BC = _alpha_Br[_qp][l][m]*_beta_Ce[_qp][l][m];
            Real GC = _alpha_GC[_qp][l][m]*_beta_GC[_qp][l][m];
            Real TI = _alpha_TI*_beta_TI[_qp][l][m];
            Real TS = _alpha_TS*_beta_TS[_qp][l][m];
            Real VW = _alpha_Br[_qp][l][m]*_beta_VW[_qp][l][m];
            
            _beta[l][m] = BM+BC+GC+TI+TS+VW;
            _alpha[l][m] = 1.0;
        }
    }
}

void CoagulationMonoPB::VolumeFill()
{
	ConstMonoPB::VolumeFill();
}

void CoagulationMonoPB::FractionFill()
{
	ConstMonoPB::FractionFill();
}

void CoagulationMonoPB::GamaFill()
{
	ConstMonoPB::GamaFill();
}

Real CoagulationMonoPB::computeQpResidual()
{
    this->AlphaBetaFill();
    return ConstMonoPB::computeQpResidual();
}

Real CoagulationMonoPB::computeQpJacobian()
{
	/*
    this->AlphaBetaFill();
    
    Real rate = 0.0;
    Real source = 0.0;
    Real sink = 0.0;
    int k = _this_var;
    
    for (int l=0; l<_M; l++)
    {
        if (l!=k)
        {
            sink = sink + _gama[k][l]*_alpha[k][l]*_beta[k][l]*(*_coupled_u[l])[_qp];
        }
        else
        {
            sink = sink + 2.0*_gama[k][l]*_alpha[k][l]*_beta[k][l]*(*_coupled_u[l])[_qp];
        }
        
        Real m_sum = 0.0;
        
        for (int m=0; m<=l; m++)
        {
            if (l!=k && m!=k)
            {
                m_sum = m_sum;
            }
            else if (l==k && m!=k)
            {
                m_sum = m_sum + (1.0-0.5*this->KroneckerDelta(l,m))*_frac[k][l][m]*_alpha[l][m]*_beta[l][m]*(*_coupled_u[m])[_qp];
            }
            else if (l!=k && m==k)
            {
                m_sum = m_sum + (1.0-0.5*this->KroneckerDelta(l,m))*_frac[k][l][m]*_alpha[l][m]*_beta[l][m]*(*_coupled_u[l])[_qp];
            }
            else
            {
                m_sum = m_sum + 2.0*(1.0-0.5*this->KroneckerDelta(l,m))*_frac[k][l][m]*_alpha[l][m]*_beta[l][m]*(*_coupled_u[l])[_qp];
            }
        }
        
        source = source + m_sum;
    }
    
    rate = (source-sink)*_phi[_j][_qp]*_test[_i][_qp];
    return -rate;
    */
    return 0.0;
}

Real CoagulationMonoPB::computeQpOffDiagJacobian(unsigned int jvar)
{
    return 0.0;
}
