/*!
 *  \file BrownianConvecMonoPB.h
 *	\brief Kernel for Mono-variate Population Balance Model with Brownian coefficients
 *	\details This file creates a MOOSE kernel that will couple together multiple number
 *			concentrations of particles and calculate a population balance rate function
 *			assuming the collision efficiency and frequency are calculated from Brownian
 *			diffusion and the convective Brownian diffusion enhancement functions. This
 *			module is based on the following works:
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

#include "BrownianConvecMonoPB.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */

registerMooseObject("fennecApp", BrownianConvecMonoPB);

InputParameters BrownianConvecMonoPB::validParams()
{
    InputParameters params = BrownianMonoPB::validParams();
    return params;
}

BrownianConvecMonoPB::BrownianConvecMonoPB(const InputParameters & parameters)
: BrownianMonoPB(parameters),
_beta_Ce(getMaterialProperty<std::vector<std::vector<Real> > >("beta_CE"))
{

}

Real BrownianConvecMonoPB::KroneckerDelta(int i, int j)
{
    if (i==j)
    	return 1.0;
    else
    	return 0.0;
}

void BrownianConvecMonoPB::AlphaBetaFill()
{
    for (int l=0; l<_M; l++)
    {
        for (int m=0; m<_M; m++)
        {
            _beta[l][m] = _beta_Br[_qp][l][m]+_beta_Ce[_qp][l][m];
            _alpha[l][m] = _alpha_Br[_qp][l][m];
        }
    }
}

void BrownianConvecMonoPB::VolumeFill()
{
	ConstMonoPB::VolumeFill();
}

void BrownianConvecMonoPB::FractionFill()
{
	ConstMonoPB::FractionFill();
}

void BrownianConvecMonoPB::GamaFill()
{
	ConstMonoPB::GamaFill();
}

Real BrownianConvecMonoPB::computeQpResidual()
{
    this->AlphaBetaFill();
    return ConstMonoPB::computeQpResidual();
}

Real BrownianConvecMonoPB::computeQpJacobian()
{
    this->AlphaBetaFill();
    return ConstMonoPB::computeQpJacobian();
}

Real BrownianConvecMonoPB::computeQpOffDiagJacobian(unsigned int jvar)
{
    this->AlphaBetaFill();
    return ConstMonoPB::computeQpOffDiagJacobian(jvar);
}
