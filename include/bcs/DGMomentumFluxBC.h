/*!
*  \file DGMomentumFluxBC.h
*	\brief Boundary Condition kernel for the flux of momentum across a boundary of the domain
*	\details This file creates a generic boundary condition kernel for the flux of momentum accross
*			a boundary. The flux is based on a velocity vector and is valid
*			in all directions and all boundaries of a DG method. Since the DG method's flux boundary
*			conditions are essitially the same for input and ouput boundaries, this kernel will check
*			the sign of the flux normal to the boundary and determine automattically whether it is
*			an output or input boundary, then apply the appropriate conditions.
*
*  \author Austin Ladshaw
 *	\date 07/09/2018
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

#include "DGFluxBC.h"

/// DGMomentumFluxBC class object forward declaration
class DGMomentumFluxBC;

/// DGMomentumFluxBC class object inherits from IntegratedBC object
/** This class object inherits from the IntegratedBC object.
	All public and protected members of this class are required function overrides.
	The flux BC uses the velocity in the system to apply a boundary
	condition based on whether or not material is leaving or entering the boundary. */
class DGMomentumFluxBC : public DGFluxBC
{
public:
    /// Static Member Function for Input Parameters
    static InputParameters validParams();
    
    /// Required constructor for BC objects in MOOSE
	DGMomentumFluxBC(const InputParameters & parameters);
	
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
	
	const VariableValue & _ux;			///< Velocity in the x-direction
	const VariableValue & _uy;			///< Velocity in the y-direction
	const VariableValue & _uz;			///< Velocity in the z-direction
	
	const VariableValue & _density;				///< Density of the fluid
	
	unsigned int _dir;							///< Direction variable for direction this kernel acts on (0=x, 1=y, 2=z)
	
	const unsigned int _ux_var;					///< Variable identification for ux
	const unsigned int _uy_var;					///< Variable identification for uy
	const unsigned int _uz_var;					///< Variable identification for uz
	const unsigned int _den_var;				///< Variable identification for density
	
private:
	
};

