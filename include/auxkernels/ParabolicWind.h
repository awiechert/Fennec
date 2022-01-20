/*!
 *  \file ParabolicWind.h
 *	\brief Auxillary kernel for a Parabolic Wind profile
 *	\details This file creates an auxillary kernel for a non-linear variable
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

#pragma once

#include "AuxKernel.h"


/// ParabolicWind class object forward declaration
class ParabolicWind;

/// ParabolicWind class inherits from AuxKernel
/** This class object creates an AuxKernel for use in the MOOSE framework. The AuxKernel will
	calculate the parabolic wind velocity in the n-direction. */
class ParabolicWind : public AuxKernel
{
public:
    /// Static Member Function for Input Parameters
    static InputParameters validParams();
    
    /// Standard MOOSE public constructor
	ParabolicWind(const InputParameters & parameters);
	
protected:
	/// Required MOOSE function override
	/** This is the function that is called by the MOOSE framework when a calculation of the total
		system pressure is needed. You are required to override this function for any inherited
		AuxKernel. */
	virtual Real computeValue() override;		///< Computes velocity in n-direction (m/s)
	
	Real _v_max;			///< Maximum horizontal wind velocity (m/s)
	Real _v_min;			///< Minimum horizontal wind velocity (m/s)
	Real _z_max;			///< Altitude at which wind velocity is a maximum (m)
	Real _alpha;			///< Power Law parameter to describe shape of parabola
		
private:
	
};
