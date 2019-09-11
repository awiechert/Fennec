/*!
 *  \file CollisionTesting.h
 *	\brief Auxillary kernel to test the CollisionParameters
 *	\details This file creates an auxillary kernel that runs some tests associated with
 *			the CollisionParameters material property file.
 *
 *  \author Austin Ladshaw
 *	\date 09/09/2019
 *	\copyright This kernel was designed and built at the Georgia Institute
 *             of Technology by Austin Ladshaw for PhD research in the area
 *             of radioactive particle transport and settling following a
 *			   nuclear event. It was developed for the US DOD under DTRA
 *			   project No. 14-24-FRCWMD-BAA. Portions Copyright (c) 2019, all
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

#include "CollisionTesting.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", CollisionTesting);

template<>
InputParameters validParams<CollisionTesting>()
{
    InputParameters params = validParams<AuxKernel>();
    params.addRequiredCoupledVar("conc","Variable name for a coupled number concentration");
    params.addRequiredCoupledVar("conc_other","Variable name for another coupled number concentration");
    return params;
}

CollisionTesting::CollisionTesting(const InputParameters & parameters)
: AuxKernel(parameters),
_N(coupledValueOld("conc")),
_N_other(coupledValueOld("conc_other")),
_global_index(coupled("conc")),
_global_index_other(coupled("conc_other")),
_local_to_global(getMaterialProperty<std::vector<int> >("index_list")),
_diffusion(getMaterialProperty<std::vector<Real> >("particle_diffusion")),
_eddy_diff(getMaterialProperty<std::vector<Real> >("eddy_diffusion")),
_dispersion(getMaterialProperty<std::vector<Real> >("particle_dispersion")),
_beta_Br(getMaterialProperty<std::vector<std::vector<Real> > >("beta_Br")),
_beta_CE(getMaterialProperty<std::vector<std::vector<Real> > >("beta_CE")),
_beta_GC(getMaterialProperty<std::vector<std::vector<Real> > >("beta_GC")),
_beta_TI(getMaterialProperty<std::vector<std::vector<Real> > >("beta_TI")),
_beta_TS(getMaterialProperty<std::vector<std::vector<Real> > >("beta_TS")),
_beta_VW(getMaterialProperty<std::vector<std::vector<Real> > >("beta_VW")),
_alpha_Br(getMaterialProperty<std::vector<std::vector<Real> > >("alpha_Br")),
_alpha_GC(getMaterialProperty<std::vector<std::vector<Real> > >("alpha_GC"))
{
	_found = false;
}

Real CollisionTesting::computeValue()
{
	if (_found == false)
    	this->findLocalIndex();
    
    //Real _beta = (_beta_Br[_qp][_local_index][_local_index_other]+_beta_CE[_qp][_local_index][_local_index_other]+_beta_GC[_qp][_local_index][_local_index_other]+_beta_TI[_qp][_local_index][_local_index_other]+_beta_TS[_qp][_local_index][_local_index_other]+_beta_VW[_qp][_local_index][_local_index_other]);
    
    //return _alpha_Br[_qp][_local_index][_local_index_other]*_beta*_N[_qp]*_N_other[_qp];
    return _beta_CE[_qp][_local_index][_local_index_other];
}

/// Function to setup the local index
void CollisionTesting::findLocalIndex()
{
    for (int i=0; i<_local_to_global[_qp].size(); i++)
    {
        if (_global_index == _local_to_global[_qp][i])
        {
            _local_index = i;
            break;
        }
    }
    
    for (int i=0; i<_local_to_global[_qp].size(); i++)
    {
        if (_global_index_other == _local_to_global[_qp][i])
        {
            _local_index_other = i;
            break;
        }
    }
    _found = true;
}
