/*!
 *  \file AverageMaterial.h
 *	\brief Auxillary kernel to keep track of the average amount of a set of variables
 *	\details This file creates an auxillary kernel that computes the average amount of a
 *			set of non-linear variables that has passed through a particular element in the mesh.
 *			This kernel couples with a non-linear variable and integrates it over the volume
 *			of the current element. That integrated amount is then added to other non-linear
 *			integrals calculated to create a running average of material that has passed
 *			through the element at each time step.
 *
 *  \author Austin Ladshaw
 *	\date 04/09/2019
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

#ifndef AverageMaterial_H
#define AverageMaterial_H

#include "AuxKernel.h"


/// AverageMaterial class object forward declaration
class AverageMaterial;

template<>
InputParameters validParams<AverageMaterial>();

/// AverageMaterial class inherits from AuxKernel
/** This class object creates an AuxKernel for use in the MOOSE framework. The AuxKernel will
	calculate the average of a set of non-linear variables that has passed through the elements
	of the mesh. Thereby creating a running average of all materials over time. This is useful for
	visualizing the actual debris cloud made from several size classes of particles. */
class AverageMaterial : public AuxKernel
{
public:
	/// Standard MOOSE public constructor
	AverageMaterial(const InputParameters & parameters);
	
protected:
	/// Required MOOSE function override
	/** This is the function that is called by the MOOSE framework when a calculation of the total
		system pressure is needed. You are required to override this function for any inherited
		AuxKernel. */
	virtual Real computeValue();
	
	std::vector<const VariableValue *> _coupled_u;			///< Pointer list for the non-linear variables
	
private:
	
};

#endif //AverageMaterial_H
