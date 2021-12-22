/*!
 *  \file JKRSmoothAdhesiveForce.h
 *	\brief Auxiliary kernel for calculating smooth contact adhesion
 *	\details This file creates an auxiliary kernel to provide an estimate of the adhesive
 *			 force between a spherical particle and a perfectly smooth surface using the
 *			 JKR model (Johnson, Kendal, and Roberts 1971). Adhesive surface energy and
 *			 particle diameter are required inputs. These values are coupled with variables
 *			 and may be calculated using other auxiliary kernels.
 *
 *			 Johnson, K.L. Kendall, K. Roberts, A.D. Surface Energy and the Contact of Elastic
 *			 Solids. Proc. R. Soc. Lond. A. 324 (1971) 301-313.
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


/// JKRSmoothAdhesiveForce class object forward declaration
class JKRSmoothAdhesiveForce;

template<>
InputParameters validParams<JKRSmoothAdhesiveForce>();

/// JKRSmoothAdhesiveForce class inherits from AuxKernel
/** This class object creates an AuxKernel for use in the MOOSE framework. The AuxKernel will
	approximate the adhesive force between a spherical particle and a perfectly smooth surface. */
class JKRSmoothAdhesiveForce : public AuxKernel
{
public:
	/// Standard MOOSE public constructor
	JKRSmoothAdhesiveForce(const InputParameters & parameters);
	
protected:
	/// Required MOOSE function override
	/** This is the function that is called by the MOOSE framework when a calculation of the total
		system pressure is needed. You are required to override this function for any inherited
		AuxKernel. */
	virtual Real computeValue() override;		///< Adhesive Force on Smooth Surface (N)
	
    const VariableValue & _dia;			///< Diameter of the Aerosol Being Considered (m)
    const VariableValue & _ase;			///< Particle-Substrate Adhesive Surface Energy (N/m)
		
private:
	
};
