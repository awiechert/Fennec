/*!
 *  \file SemilogFrictionVelocity.C
 *	\brief Auxiliary kernel for friction velocity from a semilog profile
 *	\details This file creates an auxiliary kernel to calculate the friction
 *           velocity based on a semilog profile (Loosemore 2003). Centerline 
 *           velocity, centerline height, and aerodynamic roughness height are
 *           required inputs. These values are coupled with variables and may
 *		     be calculated using other auxiliary kernels.
 *           
 *			 Loosmore, G. Evaluation and Development of Models for Resuspension 
 *			 of Aerosols at Short Times After Deposition. Atm. Environ. 37 (2003).
 *
 *  \author Alexander Wiechert
 *	\date 10/15/2021
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

#include "SemilogFrictionVelocity.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", SemilogFrictionVelocity);

template<> InputParameters validParams<SemilogFrictionVelocity>()
{
	InputParameters params = validParams<AuxKernel>();
    params.addRequiredCoupledVar("centerline_velocity","Centerline Wind Velocity (m/s)");
    params.addRequiredCoupledVar("centerline_height","Height of the Centerline Velocity (m)");
    params.addRequiredCoupledVar("roughness_height","Aerodynamic Roughness Height (m)");
	return params;
}

SemilogFrictionVelocity::SemilogFrictionVelocity(const InputParameters & parameters) :
AuxKernel(parameters),
_cv(coupledValue("centerline_velocity")),
_ch(coupledValue("centerline_height")),
_arh(coupledValue("roughness_height"))
{

}

Real SemilogFrictionVelocity::computeValue()
{
	return _cv[_qp]/(2.5*log(_ch[_qp]/_arh[_qp]));
}
