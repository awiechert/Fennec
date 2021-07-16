/*!
 *  \file ExponentialWindIC.C
 *	\brief Initial Condition kernel for a Exponential Wind profile
 *	\details This file creates an initial condition for a non-linear variable
 *			that is distributed as an exponential function along the x or y-axis
 *			of the cartesian plane at the user's discretion.
 *
 *  \author Alexander Wiechert
 *	\date 04/20/2021
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

#include "ExponentialWindIC.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */

registerMooseObject("fennecApp", ExponentialWindIC);

template<> InputParameters validParams<ExponentialWindIC>()
{
	InputParameters params = validParams<InitialCondition>();
    params.addParam<bool>("x_axis",true,"If true, exponential function will use x-coordinates to calculate wind velocity, will use y-coordinates otherwise.");
    params.addRequiredParam< std::vector<Real> >("constants","Constants for exponential function ()");
	return params;
}

ExponentialWindIC::ExponentialWindIC(const InputParameters & parameters) :
InitialCondition(parameters),
_const(getParam<std::vector<Real> >("constants")),
_x_axis(getParam<bool>("x_axis"))
{

}

Real ExponentialWindIC::value(const Point & p)
{
	Real _value;
    
    if (_x_axis == true)
    {
        _value = _const[0]*pow(_const[1],_const[2]*p(0)) + _const[3];
    }
    
    else
    {
        _value = _const[0]*pow(_const[1],_const[2]*p(1)) + _const[3];
    }
    
	return _value;
	
}
