/*!
 *  \file Trajectory1stOrder.h
 *	\brief Auxillary kernel to estimate particle trajectory in n-direction with 1st Order method
 *	\details This file creates an auxillary kernel that computes the particle velocity in the n
 *				dimension using a 1st order approximation method. It should be coupled with 
 *				variables for air density and wind velocity. Those variables will be calculated
 *				using other auxillary kernels or can be non-linear variables. Particles are assumed
 *				spherical in shape and are impacted by gravitational settling as well as wind velocity.
 *				You must indication the direction with the integer n.
 *
 *  \author Austin Ladshaw
 *	\date 04/05/2019
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

#pragma once

#include "AuxKernel.h"


/// Trajectory1stOrder class object forward declaration
class Trajectory1stOrder;

template<>
InputParameters validParams<Trajectory1stOrder>();

/// Trajectory1stOrder class inherits from AuxKernel
/** This class object creates an AuxKernel for use in the MOOSE framework. The AuxKernel will
	calculate the particle velocity in the n-direction. */
class Trajectory1stOrder : public AuxKernel
{
public:
	/// Standard MOOSE public constructor
	Trajectory1stOrder(const InputParameters & parameters);
	
protected:
	/// Required MOOSE function override
	/** This is the function that is called by the MOOSE framework when a calculation of the total
		system pressure is needed. You are required to override this function for any inherited
		AuxKernel. */
	virtual Real computeValue() override;		///< Computes velocity in n-direction (m/s)
	
	void computeDrag();					///< Function to compute drag coefficient
	
	const VariableValue & _w;			///< Wind velocity in the n-direction (m/s)
	const VariableValue & _air_dens;	///< Variable for the density of air (kg/m^3)  == Typical Value: 1.225 kg/m^3
	const VariableValue & _air_visc;	///< Variable for the viscosity of air (kg/m/s)== Typical Value: 1.802e-5 kg/m/s
	
	Real _part_dia;						///< Parameter for particle diameter (m)
	Real _part_dens;					///< Parameter for particle density (kg/m^3)
	Real _grav;							///< Parameter for gravitational accel (m/s^2)
	Real _drag;							///< Parameter for drag-coefficient (-)
	
	int _n;								///< Cartesian direction (0 = x, 1 = y, 2 = z)
	
private:
	
};
