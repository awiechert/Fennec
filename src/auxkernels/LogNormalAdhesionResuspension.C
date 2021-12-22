/*!
 *  \file LogNormalAdhesionResuspension.C
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

#include "LogNormalAdhesionResuspension.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", LogNormalAdhesionResuspension);

template<> InputParameters validParams<LogNormalAdhesionResuspension>()
{
	InputParameters params = validParams<AuxKernel>();
    params.addRequiredCoupledVar("resonance_frequency","Variable for Typical Resonance Frequency (1/s)");
    params.addRequiredCoupledVar("mean_adhesion_force","Variable for the Mean of the Actual Adsheion Force (N)");
    params.addRequiredCoupledVar("std_adhesion","Standard Deviation of the Normalized Adsheion Force (-)");
    params.addRequiredCoupledVar("aerodynamic_force","Variable for Mean Aerodynamic Force (N)");
    params.addRequiredCoupledVar("aerosol_diameter","Diameter of the Aerosol Being Considered (m)");
    params.addRequiredCoupledVar("aerosol_density","Density of the Aerosol Being Considered (kg/m^3)");
    params.addParam<Real>("adhesion_range",2.0e-6,"Adhesion Force Range for Solving Resuspension Rate (N)");
    params.addParam<int>("adhesion_bins",200,"Number of Adhesion Force Bins (-)");
	return params;
}

LogNormalAdhesionResuspension::LogNormalAdhesionResuspension(const InputParameters & parameters) :
AuxKernel(parameters),
_res_freq(coupledValue("resonance_frequency")),
_mean_adh(coupledValue("mean_adhesion_force")),
_std_adh(coupledValue("std_adhesion")),
_mean_aer(coupledValue("aerodynamic_force")),
_dia(coupledValue("aerosol_diameter")),
_den(coupledValue("aerosol_density")),
_adh_rang(getParam<Real>("adhesion_range")),
_adh_bins(getParam<int>("adhesion_bins"))
{

}

Real LogNormalAdhesionResuspension::computeValue()
{
	
    Real step_size = _adh_rang/_adh_bins;
    Real adh_force = step_size/2.0;
    
    Real grav = 9.80665*M_PI*_dia[_qp]*_dia[_qp]*_dia[_qp]*_den[_qp]/12.0;
    
    Real _value = log(1.0+_std_adh[_qp]*_std_adh[_qp]/(_mean_adh[_qp]*_mean_adh[_qp]));
    Real _unit = log(_mean_adh[_qp]/(1.0+_std_adh[_qp]*_std_adh[_qp]/(_mean_adh[_qp]*_mean_adh[_qp])));
    
    Real lamda = 0.0;
    Real resus_const = 0.0;
    Real adh_prob = 0.0;
    Real f_sum = 0.0;
    
    for (unsigned int i = 0; i<_adh_bins; ++i)
    {
        adh_prob = step_size*exp(-((log(adh_force)-_unit)*(log(adh_force)-_unit))/(2.0*_value))/(adh_force*sqrt(2.0*M_PI*_value));
        
        Real f_sum = (adh_force + grav - _mean_aer[_qp])/(0.2*(_mean_aer[_qp] - grav));
        
    	if (f_sum > 0.75)
    		resus_const = _res_freq[_qp]*exp(-f_sum*f_sum/2.0)/(0.5*(1.0 + erf(f_sum/sqrt(2.0))));
    	else if (f_sum <= 0.0 && grav >= _mean_aer[_qp])
        	resus_const = 0.0;
    	else
        	resus_const = _res_freq[_qp];
        
        adh_force += step_size;
        lamda += adh_prob*resus_const*exp(-resus_const*_t);
    }
    
    return lamda;
}
