/*!
 *  \file ADDGAdvection.C
 *	\brief Discontinous Galerkin ADKernel for density advection
 *	\details This file creates a discontinous Galerkin ADKernel for density advection in a given domain. It is a generic
 *			advection kernel that is meant to be inherited from to make a more specific kernel for a given problem.
 *
 *	\note Any ADDG kernel under FENNEC will have a cooresponding ADG kernel (usually of same name) that must be included
 *		with the ADDG kernel in the input file. This is because the ADDG finite element method breaks into several different
 *		residual pieces, only a handful of which are handled by the ADDG kernel system and the other parts must be handled
 *		by the standard Galerkin system. This my be due to some legacy code in MOOSE. I am not sure if it is possible to
 *		lump all of these actions into a single DG kernel.
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

#include "ADDGAdvection.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */

registerMooseObject("fennecApp", ADDGAdvection);

InputParameters ADDGAdvection::validParams()
{
	InputParameters params = ADDGKernel::validParams();
	params.addRequiredCoupledVar("ux","Variable for velocity in x-direction");
	params.addRequiredCoupledVar("uy","Variable for velocity in y-direction");
	params.addRequiredCoupledVar("uz","Variable for velocity in z-direction");
	return params;
}

ADDGAdvection::ADDGAdvection(const InputParameters & parameters) :
ADDGKernel(parameters),
_ux(adCoupledValue("ux")),
_uy(adCoupledValue("uy")),
_uz(adCoupledValue("uz"))
{

}

ADReal ADDGAdvection::computeQpResidual(Moose::DGResidualType type)
{
    _velocity(0)=_ux[_qp];
    _velocity(1)=_uy[_qp];
    _velocity(2)=_uz[_qp];
    
    ADReal r = 0;
    switch (type)
    {
        case Moose::Element:
            if ( (_velocity * _normals[_qp]) >= 0.0)
                r += (_velocity * _normals[_qp]) * _u[_qp] * _test[_i][_qp];
            else
                r += (_velocity * _normals[_qp]) * _u_neighbor[_qp] * _test[_i][_qp];
            break;
            
        case Moose::Neighbor:
            if ( (_velocity * _normals[_qp]) >= 0.0)
                r += -(_velocity * _normals[_qp]) * _u[_qp] * _test_neighbor[_i][_qp];
            else
                r += -(_velocity * _normals[_qp]) * _u_neighbor[_qp] * _test_neighbor[_i][_qp];
            break;
    }
    return r;
}
