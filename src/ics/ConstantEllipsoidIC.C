/*!
 *  \file ConstantEllipsoidIC.h
 *	\brief Initial Condition kernel for an Ellipsoid Puff of Particles
 *	\details This file creates an initial condition for a non-linear variable
 *			that is dispersed in an ellipsoid pattern in space. Area inside the
 *			ellipsoid is given one value and outside the ellipsoid is given another.
 *			The ellipsoid boundary can be smoothed based on a smoothing distance that
 *			will distribute the non-linear variable linearly from the outer to the
 *			inner ellipsoid.
 *
 *  \author Austin Ladshaw
 *	\date 05/18/2018
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

#include "ConstantEllipsoidIC.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", ConstantEllipsoidIC);

InputParameters ConstantEllipsoidIC::validParams()
{
	InputParameters params = InitialCondition::validParams();
	params.addParam<Real>("x_length",1,"Length of x-coordinate radius");
	params.addParam<Real>("y_length",1,"Length of y-coordinate radius");
	params.addParam<Real>("z_length",1,"Length of z-coordinate radius");
	
	params.addParam<Real>("x_center",0,"Center of x-coordinate radius");
	params.addParam<Real>("y_center",0,"Center of y-coordinate radius");
	params.addParam<Real>("z_center",0,"Center of z-coordinate radius");
	
	params.addParam<Real>("value_inside",1,"Value of the non-linear variable inside ellipsoid");
	params.addParam<Real>("value_outside",0,"Value of the non-linear variable outside ellipsoid");
	
	params.addParam<Real>("smoother_distance",0,"Distance over which to smooth the non-linear variable from interior to exterior");
	return params;
}

ConstantEllipsoidIC::ConstantEllipsoidIC(const InputParameters & parameters) :
InitialCondition(parameters),
_x_rad(getParam<Real>("x_length")),
_y_rad(getParam<Real>("y_length")),
_z_rad(getParam<Real>("z_length")),
_x_center(getParam<Real>("x_center")),
_y_center(getParam<Real>("y_center")),
_z_center(getParam<Real>("z_center")),
_value_internal(getParam<Real>("value_inside")),
_value_external(getParam<Real>("value_outside")),
_smoother_distance(getParam<Real>("smoother_distance"))
{
	if (_smoother_distance >= 1.0 || _smoother_distance < 0.0)
		_smoother_distance = 0.0;
	
	if (_x_rad <= 0.0)
		_x_rad = 1.0;
	
	if (_y_rad <= 0.0)
		_y_rad = 1.0;
	
	if (_z_rad <= 0.0)
		_z_rad = 1.0;
}

Real ConstantEllipsoidIC::value(const Point & p)
{
	// Ellipsoid Formula: (x - x_center)^2/x_length^2 + (y - y_center)^2/y_length + (z - z_center)^2/z_length
	
	double dr = _smoother_distance*0.5;
	
	// If evaluation at point p(x,y,z) <= 1, then p is inside of the ellipsoid
	double eval_out = ( (p(0) - _x_center)*(p(0) - _x_center)/(_x_rad+dr)/(_x_rad+dr) ) + ( (p(1) - _y_center)*(p(1) - _y_center)/(_y_rad+dr)/(_y_rad+dr) ) + ( (p(2) - _z_center)*(p(2) - _z_center)/(_z_rad+dr)/(_z_rad+dr) );
	double eval_in = ( (p(0) - _x_center)*(p(0) - _x_center)/(_x_rad-dr)/(_x_rad-dr) ) + ( (p(1) - _y_center)*(p(1) - _y_center)/(_y_rad-dr)/(_y_rad-dr) ) + ( (p(2) - _z_center)*(p(2) - _z_center)/(_z_rad-dr)/(_z_rad-dr) );
	
	if (eval_in <= 1.0 && eval_out <= 1.0)
		return _value_internal;
	else if (eval_out <= 1.0 && eval_in > 1.0)
		return (_value_internal+_value_external)/2.0;
	else
		return _value_external;
	
}
