/*!
 *  \file JKRSmoothAdhesiveForce.C
 *	\brief Auxiliary kernel for calculating smooth contact adhesion
 *	\details This file creates an auxiliary kernel to provide an estimate of the adhesive
 *			 force between a spherical particle and a perfectly smooth surface using the 
 *			 JKR model (Johnson, Kendal, and Roberts 1971). Adhesive surface energy and
 *			 particle diameter are required inputs. These values are coupled with variables 
 *			 and may be calculated using other auxiliary kernels.
 *           
 *			 Johnson, K.L. Kendall, K. Roberts, A.D. Surface Energy and the Contact of Elastic 
 *			 Solids. Proc. R. Soc. Lond. A. 324 (1971) 301-313.
 *
 *  \author Alexander Wiechert
 *	\date 11/9/2021
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

#include "JKRSmoothAdhesiveForce.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", JKRSmoothAdhesiveForce);

InputParameters JKRSmoothAdhesiveForce::validParams()
{
	InputParameters params = AuxKernel::validParams();
    params.addRequiredCoupledVar("aerosol_diameter","Diameter of the Aerosol Being Considered (m)");
    params.addRequiredCoupledVar("adhesive_energy","Particle-Substrate Adhesive Surface Energy (N/m)");
	return params;
}

JKRSmoothAdhesiveForce::JKRSmoothAdhesiveForce(const InputParameters & parameters) :
AuxKernel(parameters),
_dia(coupledValue("aerosol_diameter")),
_ase(coupledValue("adhesive_energy"))
{

}

Real JKRSmoothAdhesiveForce::computeValue()
{
	return 3.0*M_PI*_ase[_qp]*_dia[_qp]/4.0;
}
