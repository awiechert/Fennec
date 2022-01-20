/*!
 *  \file AccelDT.h
 *	\brief Kernel used to accelerate the time steps for faster execution
 *	\details This file creates a MOOSE TimeStepper kernel that is to be used to accelerate simulations
 *				in time based on whether or not a previous time step completed successfully.
 *
 *  \author Austin Ladshaw
 *	\date 11/07/2019
 *	\copyright This kernel was designed and built at the Georgia Institute
 *             of Technology by Austin Ladshaw for PhD research in the area
 *             of radioactive particle transport and settling following a
 *			   nuclear event. It was developed for the US DOD under DTRA
 *			   project No. 14-24-FRCWMD-BAA. Portions Copyright (c) 2019, all
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

#include "AccelDT.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", AccelDT);

InputParameters AccelDT::validParams()
{
    InputParameters params = TimeStepper::validParams();
    params.addParam<Real>("dt_multiplier", 1.0, "Value to multiply by success dt size (1.0 <= dt_multiplier <= 2.0)");
    params.addParam<Real>("dt", 0.1, "Initial dt value");
    
    return params;
}

AccelDT::AccelDT(const InputParameters & parameters) : TimeStepper(parameters),
_dt_multiplier(getParam<Real>("dt_multiplier")),
_input_dt(getParam<Real>("dt"))
{
	if (_dt_multiplier > 2.0)
    	_dt_multiplier = 2.0;
    if (_dt_multiplier < 1.0)
        _dt_multiplier = 1.0;
}

Real AccelDT::computeInitialDT()
{
    return _input_dt;
}

Real AccelDT::computeDT()
{
    return getCurrentDT()*_dt_multiplier;
}
