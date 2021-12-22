/*!
 *  \file InterfacialResuspension.C
 *	\brief Interface Kernel for Resuspension of Deposited Particles
 *	\details This file creates a MOOSE interface kernel for the resuspension
 *			 of previously deposited aerosols into the atmosphere across a
 *           designated mesh boundary. Resuspension depends upon the
 *		     resuspension rate derived elsewhere.
 *
 *  \author Alexander Wiechert
 *	\date 10/14/2021
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

#pragma once

#include "InterfaceKernel.h"
#include <cmath>

/// InterfacialResuspension class object forward declarations
class InterfacialResuspension;

template<>
InputParameters validParams<InterfaceKernel>();

/// InterfacialResuspension class object inherits from InterfaceKernel object
/** This class object inherits from the InterfaceKernel object in the MOOSE framework.
	All public and protected members of this class are required function overrides. The object
	will provide residuals and Jacobians for aerosol resuspension in the MOOSE framework. 
*/

class InterfacialResuspension : public InterfaceKernel
{
public:
	/// Required constructor for objects in MOOSE
	InterfacialResuspension(const InputParameters & parameters);
	
protected:
	/// Required residual function for Interface Kernels in MOOSE
	/** This function returns a residual contribution for this object.*/
	virtual Real computeQpResidual(Moose::DGResidualType type) override;
    
	/// Required Jacobian function for Interface Kernels in MOOSE
	/** This function returns a Jacobian contribution for this object. The Jacobian being
		computed is the associated diagonal element in the overall Jacobian matrix for the
		system and is used in preconditioning of the linear sub-problem. */
	virtual Real computeQpJacobian(Moose::DGJacobianType type) override;

    /// Not required, but recomended function for Kernels in MOOSE
    /** This function returns an off-diagonal jacobian contribution for this object. The jacobian
     being computed will be associated with the variables coupled to this object and not the
     main coupled variable itself. */
    virtual Real computeQpOffDiagJacobian(Moose::DGJacobianType type, unsigned int jvar) override;
    
    const VariableValue & _lamda;		///< Aerosol Resuspension Rate (1/s)
	
private:
	
};

