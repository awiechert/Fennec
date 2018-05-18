/*!
 *  \file ConstantEllipsoidIC.h
 *	\brief Initial Condition kernel for an Ellipsoid Puff of Particles
 *	\details This file creates an initial condition for a non-linear variable 
 *			that is dispersed in an ellipsoid pattern in space. Area inside the
 *			ellipsoid is given one value and outside the ellipsoid is given another.
 *			The ellipsoid boundary can be smoothed based on a smoothing distance that
 *			will distribute the non-linear variable linearly from the outer to the
 *			inner ellipsoid.
 *
 *  \author Austin Ladshaw
 *	\date 05/18/2018
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

#ifndef ConstantEllipsoidIC_H
#define	ConstantEllipsoidIC_H

#include "InitialCondition.h"

/// ConstantEllipsoidIC class object forward declarations
class ConstantEllipsoidIC;

template<> InputParameters validParams<ConstantEllipsoidIC>();

/// ConcentrationIC class object inherits from InitialCondition object
/** This class object inherits from the InitialCondition object in the MOOSE framework.
	All public and protected members of this class are required function overrides. The object
	will establish the initial conditions for a species' concentration as constant throughout the
	domain.
 */
class ConstantEllipsoidIC : public InitialCondition
{
public:
	/// Required constructor for objects in MOOSE
	ConstantEllipsoidIC(const InputParameters & parameters);
	
	/// Required function override for setting the value of the non-linear variable at a given point
	/** This function passes a point p as an argument. The return value will be the value of the non-linear
		variable at that point. That information is used to establish the spatially varying initial condition
		for the given non-linear variable. */
	virtual Real value(const Point & p);
	
	/// Below are parameters to defind the ellipsoid in 3D space
	Real _x_rad;			///< Radius of the ellipsoid in x
	Real _y_rad;			///< Radius of the ellipsoid in y
	Real _z_rad;			///< Radius of the ellipsoid in z
	Real _x_center;			///< x-coordinate center of the ellipsoid
	Real _y_center;			///< y-coordinate center of the ellipsoid
	Real _z_center;			///< z-coordinate center of the ellipsoid
	
	Real _value_internal;	///< Value of the non-linear variable inside the ellipsoid
	Real _value_external;	///< Value of the non-linear variable outside the ellipsoid
	Real _smoother_distance;	///< Distance over which to smooth the non-linear variable from interior to exterior
	
private:

};

#endif //ConstantEllipsoidIC_H
