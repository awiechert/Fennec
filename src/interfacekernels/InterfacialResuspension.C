/*!
 *  \file InterfacialResuspension.C
 *	\brief Interface Kernel for Resuspension of Deposited Particles
 *	\details This file creates a MOOSE interface kernel for the resuspension 
 *			 of previously deposited aerosols into the atmosphere across a 
 *           designated mesh boundary. Resuspension depends upon the
 *		     resuspension rate derived elsewhere.
 *
 *  \author Alexander Wiechert
 *	\date 10/14/2021
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

#include "InterfacialResuspension.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */

registerMooseObject("fennecApp", InterfacialResuspension);

InputParameters InterfacialResuspension::validParams()
{
    InputParameters params = InterfaceKernel::validParams();
    params.addRequiredCoupledVar("lamda","Aerosol Resuspension Rate (1/s)");
	return params;
}

InterfacialResuspension::InterfacialResuspension(const InputParameters & parameters) :
InterfaceKernel(parameters),
_lamda(coupledValue("lamda"))
{

}

Real InterfacialResuspension::computeQpResidual(Moose::DGResidualType type)
{
    Real r = 0;
	switch (type)
	{
		case Moose::Element:
            r = -_test[_i][_qp] * _lamda[_qp] * _neighbor_value[_qp];
			break;
			
		case Moose::Neighbor:
            r = _test_neighbor[_i][_qp] * _lamda[_qp] * _neighbor_value[_qp];
			break;
	}
	return r;
}

Real InterfacialResuspension::computeQpJacobian(Moose::DGJacobianType type)
{
	Real jac = 0;
	switch (type)
    {
        case Moose::ElementElement:
            jac = 0.0;
            break;
        case Moose::NeighborNeighbor:
            jac = _test_neighbor[_i][_qp] * _lamda[_qp] * _phi_neighbor[_j][_qp];
            break;
        case Moose::NeighborElement:
            jac = 0.0;
            break;
        case Moose::ElementNeighbor:
            jac = -_test[_i][_qp] * _lamda[_qp] * _phi_neighbor[_j][_qp];
            break;
    }
	return jac;
}

Real InterfacialResuspension::computeQpOffDiagJacobian(Moose::DGJacobianType type, unsigned int jvar)
{
    return 0.0;
}
