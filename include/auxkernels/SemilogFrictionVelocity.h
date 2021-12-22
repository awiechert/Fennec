/*!
 *  \file SemilogFrictionVelocity.C
 *	\brief Auxillary kernel for friction velocity from a semilog profile
 *	\details This file creates an auxillary kernel to calculate the friction
 *           velocity based on a semilog profile (Loosemore 2003). Centerline
 *           velocity, centerline height, and aerodynamic roughness height are
 *           required inputs. These values are coupled with variables and may
 *		     be calculated using other auxillary kernels.
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

#pragma once

#include "AuxKernel.h"


/// SemilogFrictionVelocity class object forward declaration
class SemilogFrictionVelocity;

template<>
InputParameters validParams<SemilogFrictionVelocity>();

/// SemilogFrictionVelocity class inherits from AuxKernel
/** This class object creates an AuxKernel for use in the MOOSE framework. The AuxKernel will
	calculate the parabolic wind velocity in the n-direction. */
class SemilogFrictionVelocity : public AuxKernel
{
public:
	/// Standard MOOSE public constructor
	SemilogFrictionVelocity(const InputParameters & parameters);
	
protected:
	/// Required MOOSE function override
	/** This is the function that is called by the MOOSE framework when a calculation of the total
		system pressure is needed. You are required to override this function for any inherited
		AuxKernel. */
	virtual Real computeValue() override;		///< Computes friction velocity in n-direction (m/s)
	
    const VariableValue & _cv;			///< Centerline wind velocity in the n-direction (m/s)
    const VariableValue & _ch;			///< Height of the centerline velocity in the n-direction (m)
    const VariableValue & _arh;			///< Aerodynamic roughness height (m)
		
private:
	
};
