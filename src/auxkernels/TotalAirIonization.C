/*!
 *  \file TotalAirIonization.h
 *	\brief Auxillary kernel to keep track of the total ionization of air (ion-pairs/m^3/s)
 *	\details This file creates an auxillary kernel that computes the total ionization of
 *			the air as a function of the air density. Calculations require coupling with
 *			the CARDINAL_Object, which will pass over the nuclide information for the
 *			particles of each size class. Then, FAIRY/IBIS will handle the calculation
 *			of the ionization coefficients for each nuclides on the debris particles.
 *
 *  \author Austin Ladshaw
 *	\date 08/30/2019
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

#include "TotalAirIonization.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", TotalAirIonization);

template<>
InputParameters validParams<TotalAirIonization>()
{
    InputParameters params = validParams<AuxKernel>();
    params.addRequiredCoupledVar("coupled_list","List of names of the number concentration variables being coupled");
    params.addRequiredCoupledVar("air_density","Variable for air density (kg/m^3)");
    params.addRequiredParam<UserObjectName>("cardinal_object","Name of the CARDINAL_Object object");
    return params;
}

TotalAirIonization::TotalAirIonization(const InputParameters & parameters) :
AuxKernel(parameters),
_air_dens(coupledValueOld("air_density")),
_user_object(getUserObject<CARDINAL_Object>("cardinal_object"))
{
    unsigned int n = coupledComponents("coupled_list");
    _coupled_u.resize(n);
    
    for (unsigned int i = 0; i<_coupled_u.size(); ++i)
    {
        _coupled_u[i] = &coupledValue("coupled_list",i);
    }
    
}

Real TotalAirIonization::computeValue()
{
    Real _total = 0.0;
    
    return _total;
}
