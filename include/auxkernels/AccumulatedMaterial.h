/*!
 *  \file AccumulatedMaterial.h
 *	\brief Auxillary kernel to keep track of the total accumulated amount of a variable on a surface
 *	\details This file creates an auxillary kernel that computes the total accumulated amount
 *			of a non-linear variable that has passed through a particular boundary in the mesh.
 *			This kernel couples with a non-linear variable and integrates it over the flux
 *			accross the current boundary. That integrated amount is then continuously added to
 *			prior integrals calculated to create a running total of material that has passed
 *			through the boundary.
 *
 *  \author Austin Ladshaw
 *	\date 05/18/2018
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


/// AccumulatedMaterial class object forward declaration
class AccumulatedMaterial;

template<>
InputParameters validParams<AccumulatedMaterial>();

/// AccumulatedMaterial class inherits from AuxKernel
/** This class object creates an AuxKernel for use in the MOOSE framework. The AuxKernel will
	calculate the total accumulation of a non-linear variable that has passed through the elements
	of the mesh. Thereby creating a running total of all material over time. This is useful for 
	determining the total amount of particles that may be deposited on a surface via settling. */
class AccumulatedMaterial : public AuxKernel
{
public:
	/// Standard MOOSE public constructor
	AccumulatedMaterial(const InputParameters & parameters);
	
protected:
	/// Required MOOSE function override
	/** This is the function that is called by the MOOSE framework when a calculation of the total
		system pressure is needed. You are required to override this function for any inherited
		AuxKernel. */
	virtual Real computeValue() override;
	
	std::vector<const VariableValue *> _coupled_u;			///< Pointer list for the non-linear variables
    std::vector<const VariableValue *> _coupled_u_old;		///< Pointer list for the non-linear variables at prior step
    
    std::vector<const VariableValue *> _vx;			///< Pointer list for the x-direction velocities
    std::vector<const VariableValue *> _vy;			///< Pointer list for the y-direction velocities
    std::vector<const VariableValue *> _vz;			///< Pointer list for the z-direction velocities
	
private:
	
};

