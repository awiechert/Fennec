/*!
 *  \file FlowDivergence.h
 *	\brief Kernel used to integrate a Flow Divergence condition into a simulation
 *	\details This file creates a standard MOOSE kernel that is to be used in with other conservation of
 *			momentum kernels. For incompressible flow, the divergence of the velocity kernels must be
 *			zero. Thus, you must create an additional non-linear variable that this kernel couples with.
 *
 *  \author Austin Ladshaw
 *	\date 08/15/2019
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

#include "FlowDivergence.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", FlowDivergence);

InputParameters FlowDivergence::validParams()
{
    InputParameters params = Kernel::validParams();
    params.addRequiredCoupledVar("ux","Variable for velocity in x-direction");
    params.addRequiredCoupledVar("uy","Variable for velocity in y-direction");
    params.addRequiredCoupledVar("uz","Variable for velocity in z-direction");
    return params;
}

FlowDivergence::FlowDivergence(const InputParameters & parameters) :
Kernel(parameters),
_ux_grad(coupledGradient("ux")),
_uy_grad(coupledGradient("uy")),
_uz_grad(coupledGradient("uz")),
_ux_var(coupled("ux")),
_uy_var(coupled("uy")),
_uz_var(coupled("uz"))
{

}

Real FlowDivergence::computeQpResidual()
{
    return _test[_i][_qp]*(_ux_grad[_qp](0) + _uy_grad[_qp](1) + _uz_grad[_qp](2));
}

Real FlowDivergence::computeQpJacobian()
{
    return 0.0;
}

Real FlowDivergence::computeQpOffDiagJacobian(unsigned int jvar)
{
    if (jvar == _ux_var)
    {
        return _test[_i][_qp]*_grad_phi[_j][_qp](0);
    }
    
    if (jvar == _uy_var)
    {
        return _test[_i][_qp]*_grad_phi[_j][_qp](1);
    }
    
    if (jvar == _uz_var)
    {
        return _test[_i][_qp]*_grad_phi[_j][_qp](2);
    }
    
    return 0.0;
}
