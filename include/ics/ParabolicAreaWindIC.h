/*!
 *  \file ParabolicAreaWindIC.h
 *	\brief Initial Condition kernel for a Parabolic Wind profile over an Area
 *	\details This file creates an initial condition for a non-linear variable
 *			that is distributed as a parabolic function along the x or y-axis
 *			of the cartesian plane at the user's discretion.
 *
 *  \author Alexander Wiechert
 *	\date 04/22/2021
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

#include "InitialCondition.h"

/// ParabolicAreaWindIC class object forward declarations
class ParabolicAreaWindIC;

template<> InputParameters validParams<ParabolicAreaWindIC>();

/// ParabolicAreaWindIC class object inherits from InitialCondition object
/** This class object inherits from the InitialCondition object in the MOOSE framework.
	All public and protected members of this class are required function overrides. The object
	will establish the initial conditions for a Parabolic Wind Profile.
 */
class ParabolicAreaWindIC : public InitialCondition
{
public:
	/// Required constructor for objects in MOOSE
	ParabolicAreaWindIC(const InputParameters & parameters);
	
	/// Required function override for setting the value of the non-linear variable at a given point
	/** This function passes a point p as an argument. The return value will be the value of the non-linear variable at that point. That information is used to establish the spatially varying initial condition for the given non-linear variable. 
    */
	
    virtual Real value(const Point & p) override;
	
	std::vector< Real > _const;								///< Constants for parabolic function ()
	bool _x_axis;											///< Boolean to specify the Cartesian direction used in the parabolic function to calculate wind velocity
private:
	
};
