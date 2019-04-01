/*!
 *  \file CARDINAL_Object.h
 *	\brief General User Object to contain all information and algorithms associated with CARDINAL
 *	\details This file creates a GeneralUserObject for CARDINAL objects and functions in MOOSE. The
 *			CARDINAL object is made public to allow any kernels using this General Object to call
 *			CARDINAL member functions and have access to CARDINAL data. The CARDINAL object will be used
 *			to establish initial conditions for FENNEC simulations by estimating the cloud rise
 *			following a nuclear explosion of a particular size.
 *
 *  \author Austin Ladshaw
 *	\date 07/19/2018
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

#include "CARDINAL_Object.h"

template <>
InputParameters
validParams<CARDINAL_Object>()
{
	InputParameters params = validParams<GeneralUserObject>();
	params.addClassDescription("GeneralUserObject for CARDINAL member data and functions. CARDINAL is used to establish initial conditions for FENNEC simulations by estimating cloud rise, particle distributions, and establishing wind, temperature, pressure, and relative humidity profiles for the atmosphere.");
	return params;
}

CARDINAL_Object::CARDINAL_Object(const InputParameters & parameters) : GeneralUserObject(parameters)
{
	
}

void CARDINAL_Object::initialize()
{
	
}

void CARDINAL_Object::execute()
{
	
}

void CARDINAL_Object::finalize()
{
	
}
