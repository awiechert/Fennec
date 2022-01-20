/*!
 *  \file CARDINAL_CloudIC.h
 *	\brief Initial Condition kernel for a Puff of Particles based from a CARDINAL simulation
 *	\details This file creates an initial condition for a non-linear variable
 *			that is dispersed in a debris cloud whose size and shape and concentration
 *			values all come from the simulation results from CARDINAL. The user MUST
 *			couple this kernel with the CARDINAL_Object UserObject in order to determine
 *			concentration values of this variable in space. Also, user MUST provide a
 *			local variable size index, which denotes the size class of this non-linear
 *			variable. That index is based on the ordering of the non-linear variables
 *			when coupled in a list in any other kernel. The list should also be in
 *			increasing size order.
 *
 *  \author Austin Ladshaw
 *	\date 08/28/2019
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

#pragma once

#include "InitialCondition.h"
#include "CARDINAL_Object.h"

/// CARDINAL_CloudIC class object forward declarations
class CARDINAL_CloudIC;

/// CARDINAL_CloudIC class object inherits from InitialCondition object
/** This class object inherits from the InitialCondition object in the MOOSE framework.
	All public and protected members of this class are required function overrides. The object
	will establish the initial conditions for a species' concentration as constant throughout the
	domain.
 */
class CARDINAL_CloudIC : public InitialCondition
{
public:
    /// Static Member Function for Input Parameters
    static InputParameters validParams();
    
    /// Required constructor for objects in MOOSE
    CARDINAL_CloudIC(const InputParameters & parameters);
    
    /// Required function override for setting the value of the non-linear variable at a given point
    /** This function passes a point p as an argument. The return value will be the value of the non-linear
     variable at that point. That information is used to establish the spatially varying initial condition
     for the given non-linear variable. */
    virtual Real value(const Point & p) override;
    
    /// Below are parameters to help define the debris cloud location and specific particle size class
    Real _x_center;							///< x-coordinate center of the cloud
    Real _y_center;							///< y-coordinate center of the cloud
    unsigned int _local_size_index;			///< Variable index for particle size bin of the variable this kernel acts on
    const CARDINAL_Object & _user_object;	///< User object for CARDINAL simulation data/results
    
private:
    
};

