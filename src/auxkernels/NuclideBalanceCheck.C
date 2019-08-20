/*!
 *  \file NuclideBalanceCheck.h
 *	\brief Auxillary kernel to keep track of the total nuclides of all particles
 *	\details This file creates an auxillary kernel that computes the total nuclides of
 *			all particles within the given domain/sub-domain. If the system is closed
 *			then this value should remain nearly unchanged at all time steps, thus
 *			preserving the total numbers of all nuclides in the system. This
 *			kernel is primarily used to check the validity of the population balance
 *			models being implemented.
 *
 *  \author Austin Ladshaw
 *	\date 08/19/2019
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

#include "NuclideBalanceCheck.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", NuclideBalanceCheck);

template<>
InputParameters validParams<NuclideBalanceCheck>()
{
    InputParameters params = validParams<AuxKernel>();
    params.addCoupledVar("coupled_vars", "List of non-linear variables coupled to this object");
    params.addRequiredParam< std::vector<Real> >("total_nuclides","Set of total nuclide numbers corresponding to each nuclide bin (mol) (Must have same order as each column of 'coupled_list')");
    return params;
}

NuclideBalanceCheck::NuclideBalanceCheck(const InputParameters & parameters) :
AuxKernel(parameters),
_nuc(getParam<std::vector<Real> >("total_nuclides"))
{
    unsigned int n = coupledComponents("coupled_vars");
    if (n != _nuc.size())
    {
    	std::cout << "num_vars = " << n << "\tnum_bins = " << _nuc.size() << std::endl;
        moose::internal::mooseErrorRaw("Number of coupled variables does not match number of particle size bins!");
    }
    _coupled_u.resize(n);
    
    for (unsigned int i = 0; i<_coupled_u.size(); ++i)
    {
        _coupled_u[i] = &coupledValue("coupled_vars",i);
    }
    
}

Real NuclideBalanceCheck::computeValue()
{
    Real _total = 0.0;
    
    for (unsigned int i = 0; i<_coupled_u.size(); ++i)
    {
        double add = (*_coupled_u[i])[_qp]*_nuc[i];
        _total = _total + add;
    }
    return _total;
}



