/*!
 *  \file UniformAdhesionResuspension.C
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

#include "UniformAdhesionResuspension.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", UniformAdhesionResuspension);

template<> InputParameters validParams<UniformAdhesionResuspension>()
{
	InputParameters params = validParams<AuxKernel>();
    params.addRequiredCoupledVar("resonance_frequency","Variable for Typical Resonance Frequency (1/s)");
    params.addRequiredCoupledVar("adhesion_force","Variable for Uniform Adsheion Force (N)");
    params.addRequiredCoupledVar("aerodynamic_force","Variable for Mean Aerodynamic Force (N)");
    params.addRequiredCoupledVar("aerosol_diameter","Diameter of the Aerosol Being Considered (m)");
    params.addRequiredCoupledVar("aerosol_density","Density of the Aerosol Being Considered (kg/m^3)");
	return params;
}

UniformAdhesionResuspension::UniformAdhesionResuspension(const InputParameters & parameters) :
AuxKernel(parameters),
_trf(coupledValue("resonance_frequency")),
_uaf(coupledValue("adhesion_force")),
_maf(coupledValue("aerodynamic_force")),
_dia(coupledValue("aerosol_diameter")),
_den(coupledValue("aerosol_density"))
{

}

Real UniformAdhesionResuspension::computeValue()
{
	Real res_con;
    Real grav = 9.80665*M_PI*_dia[_qp]*_dia[_qp]*_dia[_qp]*_den[_qp]/12.0;
    Real f_sum = (_uaf[_qp] + grav - _maf[_qp])/(0.2*(_maf[_qp] - grav));
    
    if (f_sum > 0.75)
    	res_con = _trf[_qp]*exp(-f_sum*f_sum/2.0)/(0.5*(1.0 + erf(f_sum/sqrt(2.0))));
    else if (f_sum <= 0.0 && grav >= _maf[_qp])
        res_con = 0.0;
    else
        res_con = _trf[_qp];
    
	return res_con*exp(-res_con*_t);
}
