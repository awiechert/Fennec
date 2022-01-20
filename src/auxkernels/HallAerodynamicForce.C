/*!
 *  \file HallAerodynamicForce.C
 *	\brief Auxiliary kernel for determining mean aerodynamic pull-off force
 *	\details This file creates an auxiliary kernel to calculate the mean aerodynamic
 *			 pull-off force acting on a deposited aerosol as a combination of the mean
 *			 lift and drag force (Hall 1998). Air density, kinematic viscosity, aerosol
 *			 diameter, and friction velocity are required inputs. These values are coupled 
 *			 with variables and may be calculated using other auxiliary kernels.
 *           
 *			 Hall, D. Measurements of the Mean Force on a Particle Near a Boundary in
 *			 Turbulent Flow. J. Fluid Mech. 187 (1988) 451-466.
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

#include "HallAerodynamicForce.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", HallAerodynamicForce);

InputParameters HallAerodynamicForce::validParams()
{
	InputParameters params = AuxKernel::validParams();
    params.addRequiredCoupledVar("air_density","Variable for Air Density (kg/m^3)");
    params.addRequiredCoupledVar("kinematic_viscosity","Variable for Air Kinematic Viscocity (m^2/s)");
    params.addRequiredCoupledVar("aerosol_diameter","Diameter of the Aerosol Being Considered (m)");
    params.addRequiredCoupledVar("friction_velocity","Variable for Friction Velocity at Surface (m/s)");
    params.addRequiredCoupledVar("lever_arm","Variable for Lever-Arm Distance (m)");
	return params;
}

HallAerodynamicForce::HallAerodynamicForce(const InputParameters & parameters) :
AuxKernel(parameters),
_den(coupledValue("air_density")),
_kin(coupledValue("kinematic_viscosity")),
_dia(coupledValue("aerosol_diameter")),
_frv(coupledValue("friction_velocity")),
_lva(coupledValue("lever_arm"))
{

}

Real HallAerodynamicForce::computeValue()
{
	Real Lift = 20.9*_den[_qp]*_kin[_qp]*_kin[_qp]*pow(_dia[_qp]*_frv[_qp]/(2.0*_kin[_qp]),2.31);
    Real Drag = 8.0*_den[_qp]*_dia[_qp]*_dia[_qp]*_frv[_qp]*_frv[_qp];
    Real Aero = Lift/2.0 + (_dia[_qp]/(2.0*_lva[_qp]))*Drag;
	return Aero;
}
