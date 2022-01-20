/*!
 *  \file BrownianMonoPB.h
 *	\brief Kernel for Mono-variate Population Balance Model with Brownian coefficients
 *	\details This file creates a MOOSE kernel that will couple together multiple number
 *			concentrations of particles and calculate a population balance rate function
 *			assuming the collision efficiency and frequency are calculated from Brownian
 *			diffusion functions. This module is based on the following works:
 *
 *			Y.H. Kim, S. Yiacoumi, A. Nenes, C. Tsouris, J. Aero. Sci., 114, 283-300, 2017.
 *
 *			M.Z. Jacobson, Fundamentals of Atmospheric Modeling (2nd Ed.), Cambridge University
 *				Press, New York, 2005.
 *
 *  \author Alexander Wiechert
 *	\date 04/21/2020
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

#include "BrownianMonoPB.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", BrownianMonoPB);

InputParameters BrownianMonoPB::validParams()
{
    InputParameters params = ConstMonoPB::validParams();
    return params;
}

BrownianMonoPB::BrownianMonoPB(const InputParameters & parameters)
: ConstMonoPB(parameters),
_beta_Br(getMaterialProperty<std::vector<std::vector<Real> > >("beta_Br")),
_alpha_Br(getMaterialProperty<std::vector<std::vector<Real> > >("alpha_Br"))
{

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
            _beta[l][m] = _beta_Br[_qp][l][m];
            _alpha[l][m] = _alpha_Br[_qp][l][m];
        }
    }
}

void BrownianMonoPB::VolumeFill()
{
	ConstMonoPB::VolumeFill();
}

void BrownianMonoPB::FractionFill()
{
	ConstMonoPB::FractionFill();
}

void BrownianMonoPB::GamaFill()
{
	ConstMonoPB::GamaFill();
}

Real BrownianMonoPB::computeQpResidual()
{
    this->AlphaBetaFill();
    return ConstMonoPB::computeQpResidual();
}

Real BrownianMonoPB::computeQpJacobian()
{
    return ConstMonoPB::computeQpJacobian();
}

Real BrownianMonoPB::computeQpOffDiagJacobian(unsigned int jvar)
{
    return ConstMonoPB::computeQpOffDiagJacobian(jvar);
}
