/*!
 *  \file UniformAdhesionResuspension.h
 *	\brief Auxiliary kernel for determining resuspension based on a uniform adhesion force
 *	\details This file creates an auxiliary kernel to calculate the resuspension rate for
 *			 particles of a particular size deposited within a domain where the adhesion
 *			 force is uniform. Typical resonance frequency, adhesion force, mean aerodynamic
 *			 force, particle diameter, and particle density required inputs. These values are
 *		     coupled with variables and may be calculated using other auxiliary kernels.
 *           
 *			 Brambilla, S. Speckart, S. Rush, M.N. Montano, G.A. Brown, M.J. Glass Particle
 *			 Resuspension from a Contaminated (Dirty) Glass Surface. J. Aero. Sci. 132 (2018) 
 *			 122-130. 
 *
 *			 Brambilla, S. Brown, M.J. Impact of the Adhesion-Force Lever-Arm "a" on the Rock
 *		     'n' Roll Resuspension Model and How to Compute It from Contact Mechanics. J. Aero.
 *			 Sci. 143 (2020) 105525.
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

/// UniformAdhesionResuspension class object forward declaration
class UniformAdhesionResuspension;

/// UniformAdhesionResuspension class inherits from AuxKernel
/** This class object creates an AuxKernel for use in the MOOSE framework. The AuxKernel will calculate 
	the resuspension rate in a domain with uniform adhesion for all particles of a given size. */

class UniformAdhesionResuspension : public AuxKernel
{
public:
    /// Static Member Function for Input Parameters
    static InputParameters validParams();
    
    /// Standard MOOSE public constructor
	UniformAdhesionResuspension(const InputParameters & parameters);
	
protected:
	/// Required MOOSE function override
	/** This is the function that is called by the MOOSE framework when a calculation of the total
		system pressure is needed. You are required to override this function for any inherited
		AuxKernel. */
	virtual Real computeValue() override;		///< Computes resuspension rate the n-direction (1/s)
	
    const VariableValue & _trf;			///< Variable for Typical Resonance Frequency (1/s)
    const VariableValue & _uaf;			///< Variable for Uniform Adsheion Force (N)
    const VariableValue & _maf;			///< Variable for Mean Aerodynamic Force (N)
    const VariableValue & _dia;			///< Diameter of the Aerosol Being Considered (m)
    const VariableValue & _den;			///< Density of the Aerosol Being Considered (kg/m^3)
		
private:
	
};
