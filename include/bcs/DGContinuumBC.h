/*!
 *  \file DGContinuumBC.h
 *	\brief Boundary Condition kernel for the continuity equation applied at boundary conditions
 *	\details This file creates a boundary condition kernel for the continuity of momemtum at boundaries. 
 *			Use this BC for systems involving the conservation of momentum where no additional momentum is
 *			being added to the system from the boundaries.
 *
 *  \author Austin Ladshaw
 *	\date 07/10/2018
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

#include "DGMomentumFluxBC.h"

/// DGContinuumBC class object forward declaration
class DGContinuumBC;

/// DGMomentumFluxBC class object inherits from IntegratedBC object
/** This class object inherits from the IntegratedBC object.
	All public and protected members of this class are required function overrides.
	The flux BC uses the velocity in the system to apply a boundary
	condition based on whether or not material is leaving or entering the boundary. */
class DGContinuumBC : public DGMomentumFluxBC
{
public:
    /// Static Member Function for Input Parameters
    static InputParameters validParams();
    
    /// Required constructor for BC objects in MOOSE
	DGContinuumBC(const InputParameters & parameters);
	
protected:
	/// Required function override for BC objects in MOOSE
	/** This function returns a residual contribution for this object.*/
	virtual Real computeQpResidual() override;
	
	/// Required function override for BC objects in MOOSE
	/** This function returns a Jacobian contribution for this object. The Jacobian being
		computed is the associated diagonal element in the overall Jacobian matrix for the
		system and is used in preconditioning of the linear sub-problem. */
	virtual Real computeQpJacobian() override;
	
	/// Not Required, but aids in the preconditioning step
	/** This function returns the off diagonal Jacobian contribution for this object. By
		returning a non-zero value we will hopefully improve the convergence rate for the
		cross coupling of the variables. */
	virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;
	
private:
	
};

