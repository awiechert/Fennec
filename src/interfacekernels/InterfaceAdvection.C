/*!
 *  \file InterfaceAdvection.C
 *	\brief Interface Kernel for Advection between domains
 *	\details This file creates a MOOSE interface kernel for advection across
 *           a designated mesh boundary from one subdomain and into another.
 *		     Based on the DGConcentrationAdvection Kernel.
 *
 *  \author Alexander Wiechert
 *	\date 08/24/2021
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

#include "InterfaceAdvection.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */

registerMooseObject("fennecApp", InterfaceAdvection);

InputParameters InterfaceAdvection::validParams()
{
	InputParameters params = InterfaceKernel::validParams();
    params.addRequiredCoupledVar("ux","Variable for velocity in x-direction");
    params.addRequiredCoupledVar("uy","Variable for velocity in y-direction");
    params.addRequiredCoupledVar("uz","Variable for velocity in z-direction");
	return params;
}

InterfaceAdvection::InterfaceAdvection(const InputParameters & parameters) :
InterfaceKernel(parameters),
_ux(coupledValue("ux")),
_uy(coupledValue("uy")),
_uz(coupledValue("uz")),
_ux_var(coupled("ux")),
_uy_var(coupled("uy")),
_uz_var(coupled("uz"))
{

}

Real InterfaceAdvection::computeQpResidual(Moose::DGResidualType type)
{
    _velocity(0)=_ux[_qp];
    _velocity(1)=_uy[_qp];
    _velocity(2)=_uz[_qp];
    
    Real r = 0;
	
	switch (type)
	{
		case Moose::Element:
			if ( (_velocity * _normals[_qp]) >= 0.0)
				r += (_velocity * _normals[_qp]) * _u[_qp] * _test[_i][_qp];
			else
				r += (_velocity * _normals[_qp]) * _neighbor_value[_qp] * _test[_i][_qp];
			break;
			
		case Moose::Neighbor:
			if ( (_velocity * _normals[_qp]) >= 0.0)
				r += -(_velocity * _normals[_qp]) * _u[_qp] * _test_neighbor[_i][_qp];
			else
				r += -(_velocity * _normals[_qp]) * _neighbor_value[_qp] * _test_neighbor[_i][_qp];
			break;
	}
	return r;
}

Real InterfaceAdvection::computeQpJacobian(Moose::DGJacobianType type)
{
    _velocity(0)=_ux[_qp];
    _velocity(1)=_uy[_qp];
    _velocity(2)=_uz[_qp];

	Real r = 0;
	
	switch (type)
	{
			
		case Moose::ElementElement:
			if ( (_velocity * _normals[_qp]) >= 0.0)
				r += (_velocity * _normals[_qp]) * _phi[_j][_qp] * _test[_i][_qp];
			else
				r += 0.0;
			break;
			
		case Moose::ElementNeighbor:
			if ( (_velocity * _normals[_qp]) >= 0.0)
				r += 0.0;
			else
				r += (_velocity * _normals[_qp]) * _phi_neighbor[_j][_qp] * _test[_i][_qp];
			break;
			
		case Moose::NeighborElement:
			if ( (_velocity * _normals[_qp]) >= 0.0)
				r += -(_velocity * _normals[_qp]) * _phi[_j][_qp] * _test_neighbor[_i][_qp];
			else
				r += 0.0;
			break;
			
		case Moose::NeighborNeighbor:
			if ( (_velocity * _normals[_qp]) >= 0.0)
				r += 0.0;
			else
				r += -(_velocity * _normals[_qp]) * _phi_neighbor[_j][_qp] * _test_neighbor[_i][_qp];
			break;
	}
	return r;
}

Real InterfaceAdvection::computeQpOffDiagJacobian(Moose::DGJacobianType type, unsigned int jvar)
{
	_velocity(0)=_ux[_qp];
	_velocity(1)=_uy[_qp];
	_velocity(2)=_uz[_qp];
	
	if (jvar == _ux_var)
	{
		Real r = 0.0;
		
		switch (type)
		{
				
			case Moose::ElementElement:
				if ( (_velocity * _normals[_qp]) >= 0.0)
					r += ( _phi[_j][_qp] * _normals[_qp](0) ) * _u[_qp] * _test[_i][_qp];
				else
					r += ( _phi[_j][_qp] * _normals[_qp](0) ) * _neighbor_value[_qp] * _test[_i][_qp];
				break;
				
			case Moose::ElementNeighbor:
				if ( (_velocity * _normals[_qp]) >= 0.0)
					r += ( _phi[_j][_qp] * _normals[_qp](0) ) * _u[_qp] * _test[_i][_qp];
				else
					r += ( _phi[_j][_qp] * _normals[_qp](0) ) * _neighbor_value[_qp] * _test[_i][_qp];
				break;
				
			case Moose::NeighborElement:
				if ( (_velocity * _normals[_qp]) >= 0.0)
					r += -( _phi[_j][_qp] * _normals[_qp](0) ) * _u[_qp] * _test_neighbor[_i][_qp];
				else
					r += -( _phi[_j][_qp] * _normals[_qp](0) ) * _neighbor_value[_qp] * _test_neighbor[_i][_qp];
				break;
				
			case Moose::NeighborNeighbor:
				if ( (_velocity * _normals[_qp]) >= 0.0)
					r += -( _phi[_j][_qp] * _normals[_qp](0) ) * _u[_qp] * _test_neighbor[_i][_qp];
				else
					r += -( _phi[_j][_qp] * _normals[_qp](0) ) * _neighbor_value[_qp] * _test_neighbor[_i][_qp];
				break;
		}
		
		return r;
	}
	
	if (jvar == _uy_var)
	{
		Real r = 0.0;
		
		switch (type)
		{
				
			case Moose::ElementElement:
				if ( (_velocity * _normals[_qp]) >= 0.0)
					r += ( _phi[_j][_qp] * _normals[_qp](1) ) * _u[_qp] * _test[_i][_qp];
				else
					r += ( _phi[_j][_qp] * _normals[_qp](1) ) * _neighbor_value[_qp] * _test[_i][_qp];
				break;
				
			case Moose::ElementNeighbor:
				if ( (_velocity * _normals[_qp]) >= 0.0)
					r += ( _phi[_j][_qp] * _normals[_qp](1) ) * _u[_qp] * _test[_i][_qp];
				else
					r += ( _phi[_j][_qp] * _normals[_qp](1) ) * _neighbor_value[_qp] * _test[_i][_qp];
				break;
				
			case Moose::NeighborElement:
				if ( (_velocity * _normals[_qp]) >= 0.0)
					r += -( _phi[_j][_qp] * _normals[_qp](1) ) * _u[_qp] * _test_neighbor[_i][_qp];
				else
					r += -( _phi[_j][_qp] * _normals[_qp](1) ) * _neighbor_value[_qp] * _test_neighbor[_i][_qp];
				break;
				
			case Moose::NeighborNeighbor:
				if ( (_velocity * _normals[_qp]) >= 0.0)
					r += -( _phi[_j][_qp] * _normals[_qp](1) ) * _u[_qp] * _test_neighbor[_i][_qp];
				else
					r += -( _phi[_j][_qp] * _normals[_qp](1) ) * _neighbor_value[_qp] * _test_neighbor[_i][_qp];
				break;
		}
		
		return r;
	}
	
	if (jvar == _uz_var)
	{
		Real r = 0.0;
		
		switch (type)
		{
				
			case Moose::ElementElement:
				if ( (_velocity * _normals[_qp]) >= 0.0)
					r += ( _phi[_j][_qp] * _normals[_qp](2) ) * _u[_qp] * _test[_i][_qp];
				else
					r += ( _phi[_j][_qp] * _normals[_qp](2) ) * _neighbor_value[_qp] * _test[_i][_qp];
				break;
				
			case Moose::ElementNeighbor:
				if ( (_velocity * _normals[_qp]) >= 0.0)
					r += ( _phi[_j][_qp] * _normals[_qp](2) ) * _u[_qp] * _test[_i][_qp];
				else
					r += ( _phi[_j][_qp] * _normals[_qp](2) ) * _neighbor_value[_qp] * _test[_i][_qp];
				break;
				
			case Moose::NeighborElement:
				if ( (_velocity * _normals[_qp]) >= 0.0)
					r += -( _phi[_j][_qp] * _normals[_qp](2) ) * _u[_qp] * _test_neighbor[_i][_qp];
				else
					r += -( _phi[_j][_qp] * _normals[_qp](2) ) * _neighbor_value[_qp] * _test_neighbor[_i][_qp];
				break;
				
			case Moose::NeighborNeighbor:
				if ( (_velocity * _normals[_qp]) >= 0.0)
					r += -( _phi[_j][_qp] * _normals[_qp](2) ) * _u[_qp] * _test_neighbor[_i][_qp];
				else
					r += -( _phi[_j][_qp] * _normals[_qp](2) ) * _neighbor_value[_qp] * _test_neighbor[_i][_qp];
				break;
		}
		
		return r;
	}
	
	return 0.0;
}
