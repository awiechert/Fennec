/*!
 *  \file VolumeBalanceCheck.h
 *	\brief Auxillary kernel to keep track of the total volume of all particles
 *	\details This file creates an auxillary kernel that computes the total volume of 
 *			all particles within the given domain/sub-domain. If the system is closed
 *			then this value should remain nearly unchanged at all time steps, thus
 *			preserving the total volume/mass of all particles in the system. This
 *			kernel is primarily used to check the validity of the population balance
 *			models being implemented.
 *
 *  \author Austin Ladshaw
 *	\date 08/06/2019
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

#pragma once

#include "AuxKernel.h"


/// VolumeBalanceCheck class object forward declaration
class VolumeBalanceCheck;

template<>
InputParameters validParams<VolumeBalanceCheck>();

/// VolumeBalanceCheck class inherits from AuxKernel
/** This class object creates an AuxKernel for use in the MOOSE framework. The AuxKernel will
	calculate the total volume of all particles within the domain and is used to check that
    we do not violate any conservation law.  */
class VolumeBalanceCheck : public AuxKernel
{
public:
    /// Standard MOOSE public constructor
    VolumeBalanceCheck(const InputParameters & parameters);
    
protected:
    /// Required MOOSE function override
    /** This is the function that is called by the MOOSE framework when a calculation of the total
     system pressure is needed. You are required to override this function for any inherited
     AuxKernel. */
    virtual Real computeValue() override;
    
    std::vector<const VariableValue *> _coupled_u;			///< Pointer list for the non-linear variables
    std::vector< Real > _dia;								///< List of the diameters of all particles (m)
    std::vector< Real > _vol;								///< List of the volumes of all particles (m^3)
    
private:
    
};

