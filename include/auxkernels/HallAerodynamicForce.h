/*!
 *  \file HallAerodynamicForce.h
 *	\brief Auxilary kernel for determining mean aerodynamic pull-off force
 *	\details This file creates an auxilary kernel to calculate the mean aerodynamic
 *			 pull-off force acting on a deposited aerosol as a combination of the mean
 *			 lift and drag force (Hall 1998). Air density, kinematic viscosity, aerosol
 *			 diameter, and friction velocity are required inputs. These values are coupled
 *			 with variables and may be calculated using other auxilary kernels.
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

#pragma once

#include "AuxKernel.h"


/// HallAerodynamicForce class object forward declaration
class HallAerodynamicForce;

template<>
InputParameters validParams<HallAerodynamicForce>();

/// HallAerodynamicForce class inherits from AuxKernel
/** This class object creates an AuxKernel for use in the MOOSE framework. The AuxKernel will
	calculate the mean aerodynamic pull-off force acting on a particle in the n-direction. */
class HallAerodynamicForce : public AuxKernel
{
public:
	/// Standard MOOSE public constructor
	HallAerodynamicForce(const InputParameters & parameters);
	
protected:
	/// Required MOOSE function override
	/** This is the function that is called by the MOOSE framework when a calculation of the total
		system pressure is needed. You are required to override this function for any inherited
		AuxKernel. */
	virtual Real computeValue() override;		///< Computes pull-off force in the n-direction (N)
	
    const VariableValue & _den;			///< Variable for Air Density (kg/m^3)
    const VariableValue & _kin;			///< Variable for Air Kinematic Viscocity (m^2/s)
    const VariableValue & _dia;			///< Diameter of the Aerosol Being Considered (m)
    const VariableValue & _frv;			///< Variable for Friction Velocity at Surface (m/s)
    const VariableValue & _lva;			///< Variable for Lever-Arm Distance (m)
		
private:
	
};
