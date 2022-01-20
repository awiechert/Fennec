/*!
 *  \file ParabolicWindIC.h
 *	\brief Initial Condition kernel for a Parabolic Wind profile
 *	\details This file creates an initial condition for a non-linear variable
 *			that is distributed as a parabola in the z-direction of cartesian
 *			coordinates. The parabola is created using the Power Law representation
 *			of wind velocities in x and y (Offer and Goossens, 1994). This Power
 *			Law representation is valid for the lower 15% of the Atmospheric Boundary
 *			Layer (ABL). The ABL is typically between 500 to 600 m of depth. Thus,
 *			this approximation is only good between 80 to 100 m of air thickness. Above
 *			100 m, the wind velocities will be assumed constant.
 *
 *  \author Austin Ladshaw
 *	\date 04/15/2019
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

#include "ParabolicWindIC.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", ParabolicWindIC);

InputParameters ParabolicWindIC::validParams()
{
	InputParameters params = InitialCondition::validParams();
	params.addParam<Real>("max_velocity",10,"Maximum horizontal wind velocity (m/s) : Vmin < Vmax < 25 : (Typical Value = 10)");
	params.addParam<Real>("min_velocity",0,"Minimum horizontal wind velocity (m/s) : 0 < Vmin < Vmax : (Typical Value = 0)");
	params.addParam<Real>("max_altitude",1,"Altitude at which wind velocity is a maximum (m) : 80 < Zmax < 100 : (Typical Value = 100)");
	params.addParam<Real>("power_param",0,"Power Law parameter to describe shape of parabola : 0.1 < alpha < 0.5 : (Typical Value = 0.5)");
	return params;
}

ParabolicWindIC::ParabolicWindIC(const InputParameters & parameters) :
InitialCondition(parameters),
_v_max(getParam<Real>("max_velocity")),
_v_min(getParam<Real>("min_velocity")),
_z_max(getParam<Real>("max_altitude")),
_alpha(getParam<Real>("power_param"))
{
	if (_v_max >= 25.0)
		_v_max = 25.0;
	
	if (_v_min < 0.0)
		_v_min = 0.0;
	
	if (_v_min >= _v_max)
		_v_min = _v_max;
	
	if (_v_max <= _v_min)
		_v_max = _v_min;
	
	if (_z_max > 100.0)
		_z_max = 100.0;
	
	if (_z_max < 80.0 )
		_z_max = 80.0;
	
	if (_alpha > 0.5)
		_alpha = 0.5;
	
	if ( _alpha < 0.1 )
		_alpha = 0.1;
}

Real ParabolicWindIC::value(const Point & p)
{
	Real _value;
	
	if (p(2) > _z_max)
		_value = _v_max + _v_min;
	else
		_value = _v_max*pow(p(2)/_z_max,_alpha) + _v_min;
		
	return _value;
	
}
