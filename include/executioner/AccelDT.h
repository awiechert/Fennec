/*!
 *  \file AccelDT.h
 *	\brief Kernel used to accelerate the time steps for faster execution
 *	\details This file creates a MOOSE TimeStepper kernel that is to be used to accelerate simulations
 *				in time based on whether or not a previous time step completed successfully.
 *
 *  \author Austin Ladshaw
 *	\date 11/07/2019
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

#pragma once

#include "TimeStepper.h"

/// AccelDT class object forward declarations
class AccelDT;

template<>
InputParameters validParams<AccelDT>();

/**
 * Adjust the timestep based on whether or not the solution converged.
 */
class AccelDT : public TimeStepper
{
public:
    AccelDT(const InputParameters & parameters);
    
protected:
    virtual Real computeInitialDT();
    virtual Real computeDT();
    
private:
	Real _dt_multiplier;				///< Value to scale dt
    Real _input_dt;						///< Initial dt
    
};
