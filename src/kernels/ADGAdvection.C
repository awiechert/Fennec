/*!
 *  \file ADGAdvection.C
 *	\brief ADKernel for use with the corresponding ADDGAdvection object
 *	\details This file creates an ADKernel that is to be used in conjunction with ADDGAdvection for the 
 *			 discontinous Galerkin formulation of momentum advection in MOOSE. In order to complete the DG
 *			 formulation of the advective physics, this ADKernel must be utilized with every variable that 
 *			 also uses the ADDGAdvection kernel.
 *
 *  \author Alexander Wiechert
 *	\date 01/25/2022
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

#include "ADGAdvection.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */

registerMooseObject("fennecApp", ADGAdvection);

InputParameters ADGAdvection::validParams()
{
	InputParameters params = ADKernel::validParams();
	params.addRequiredCoupledVar("ux","Variable for velocity in x-direction");
	params.addRequiredCoupledVar("uy","Variable for velocity in y-direction");
	params.addRequiredCoupledVar("uz","Variable for velocity in z-direction");
	return params;
}

ADGAdvection::ADGAdvection(const InputParameters & parameters) :
ADKernel(parameters),
_ux(adCoupledValue("ux")),
_uy(adCoupledValue("uy")),
_uz(adCoupledValue("uz"))
{

}

ADReal ADGAdvection::computeQpResidual()
{
    _velocity(0)=_ux[_qp];
    _velocity(1)=_uy[_qp];
    _velocity(2)=_uz[_qp];
    
    return -_u[_qp]*(_velocity*_grad_test[_i][_qp]);
}
