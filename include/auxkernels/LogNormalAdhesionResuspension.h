/*!
 *  \file LogNormalAdhesionResuspension.h
 *	\brief Auxiliary kernel for determining resuspension based on a lognormal force distribution
 *	\details This file creates an auxiliary kernel to calculate the resuspension rate for
 *			 particles of a particular size deposited within a domain where the adhesion
 *			 force has a lognormal distribution. Typical resonance frequency, mean smooth
 *			 adhesion force, mean actual adhesion force, normalized standard deviaiton of
 *			 the adhesion force, mean aerodynamic force, particle diameter, and particle
 *			 density required inputs. These values are coupled with variables and may be
 *		     calculated using other auxiliary kernels. Additionally, the range of adhesion
 *			 forces and the number of adhesion force bins that the resuspension rate will
 *			 be solved over are also necessary.
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
 *	\date 11/18/2021
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

/// LogNormalAdhesionResuspension class object forward declaration
class LogNormalAdhesionResuspension;

template<>
InputParameters validParams<LogNormalAdhesionResuspension>();

/// LogNormalAdhesionResuspension class inherits from AuxKernel
/** This class object creates an AuxKernel for use in the MOOSE framework. The AuxKernel calculates
	the resuspension rate in a domain where paritcle adhesion is distributed lognormally. */

class LogNormalAdhesionResuspension : public AuxKernel
{
public:
	/// Standard MOOSE public constructor
	LogNormalAdhesionResuspension(const InputParameters & parameters);
	
protected:
	/// Required MOOSE function override
	/** This is the function that is called by the MOOSE framework when a calculation of the total
		system pressure is needed. You are required to override this function for any inherited
		AuxKernel. */
	virtual Real computeValue() override;		///< Computes resuspension rate the n-direction (1/s)
	
    const VariableValue & _res_freq;			///< Variable for Typical Resonance Frequency (1/s)
    const VariableValue & _mean_adh;			///< Variable for the Mean of the Actual Adsheion Force (N)
    const VariableValue & _std_adh;				///< Standard Deviation of the Normalized Adsheion Force (-)
    const VariableValue & _mean_aer;			///< Variable for Mean Aerodynamic Force (N)
    const VariableValue & _dia;					///< Diameter of the Aerosol Being Considered (m)
    const VariableValue & _den;					///< Density of the Aerosol Being Considered (kg/m^3)
    
    Real _adh_rang;  							///< Adhesion Force Range for Solving Resuspension Rate (N)
    
    int _adh_bins; 								///< Number of Adhesion Force Bins (-)
		
private:
	
};
