/*!
 *  \file ReeksResonanceFrequency.C
 *	\brief Auxiliary kernel for approximating the resonance frequency
 *	\details This file creates an auxiliary kernel to provide an estimate of the typical
 *			 forcing frequency for particle motion within a potential well assuming the
 *			 resonant energy transfer is zero (Reeks and Hall 2001). Friction velocity
 *			 and kinematic viscosity are required inputs. These values are coupled
 *			 with variables and may be calculated using other auxiliary kernels.
 *           
 *			 Reeks, M.W. Hall, D. Kinetic Models for Particle Resuspension in Turbulent
 *			 Flows: Theory and Measurement. J. Aero. Sci. 32 (2001) 1-31
 *
 *  \author Alexander Wiechert
 *	\date 11/9/2021
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

#include "ReeksResonanceFrequency.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", ReeksResonanceFrequency);

InputParameters ReeksResonanceFrequency::validParams()
{
	InputParameters params = AuxKernel::validParams();
    params.addRequiredCoupledVar("kinematic_viscosity","Variable for Air Kinematic Viscocity (m^2/s)");
    params.addRequiredCoupledVar("friction_velocity","Variable for Friction Velocity at Surface (m/s)");
	return params;
}

ReeksResonanceFrequency::ReeksResonanceFrequency(const InputParameters & parameters) :
AuxKernel(parameters),
_kin(coupledValue("kinematic_viscosity")),
_frv(coupledValue("friction_velocity"))
{

}

Real ReeksResonanceFrequency::computeValue()
{
	return 0.00658*_frv[_qp]*_frv[_qp]/_kin[_qp];
}
