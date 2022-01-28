/*!
 *  \file ADDGAdvection.h
 *	\brief Discontinous Galerkin ADKernel for density advection
 *	\details This file creates a discontinous Galerkin ADKernel for density advection in a given domain. It is a generic
 *			advection kernel that is meant to be inherited from to make a more specific kernel for a given problem.
 *
 *	\note Any ADDG kernel under FENNEC will have a cooresponding ADG kernel (usually of same name) that must be included
 *		with the ADDG kernel in the input file. This is because the ADDG finite element method breaks into several different
 *		residual pieces, only a handful of which are handled by the ADDG kernel system and the other parts must be handled
 *		by the standard Galerkin system. This my be due to some legacy code in MOOSE. I am not sure if it is possible to
 *		lump all of these actions into a single DG kernel.
 *
 *  \author Alexander Wiechert
 *	\date 01/25/2022
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

#include "ADDGKernel.h"

/// DGConcentrationAdvection class object forward declarations
class ADDGAdvection;

	/// ADDGAdvection class object inherits from ADDGKernel object
	/** This class object inherits from the ADDGKernel object in the MOOSE framework.
	All public and protected members of this class are required function overrides. The object
	will provide residuals and Jacobians for the discontinous Galerkin formulation of advection
	physics in the MOOSE framework. The only parameter for this ADKernel is a generic velocity
	vector, whose components can be set piecewise in the input file or by inheriting from this
	base class and manually altering the velocity vector.

	\note As a reminder, any ADDGKernel in MOOSE was be accompanied by the equivalent ADGKernel in
	order to provide the full residuals and Jacobians for the system. */
    
class ADDGAdvection : public ADDGKernel
{
public:
    /// Static Member Function for Input Parameters
    static InputParameters validParams();

	/// Required constructor for objects in MOOSE
	ADDGAdvection(const InputParameters & parameters);

protected:
	/// Required residual function for ADDG kernels in MOOSE
	/** This function returns a residual contribution for this object.*/
	virtual ADReal computeQpResidual(Moose::DGResidualType type) override;

	ADRealVectorValue _velocity;			///< Vector of velocity

	const ADVariableValue & _ux;			///< Velocity in the x-direction
	const ADVariableValue & _uy;			///< Velocity in the y-direction
	const ADVariableValue & _uz;			///< Velocity in the z-direction

private:

};

