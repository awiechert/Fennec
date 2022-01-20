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

#pragma once

#include "AuxKernel.h"
#include "CARDINAL_Object.h"

/// TotalAirIonization class object forward declaration
class TotalAirIonization;

/// TotalAirIonization class inherits from AuxKernel
/** This class object creates an AuxKernel for use in the MOOSE framework. The AuxKernel will
	calculate the total ionization rate for the air  */
class TotalAirIonization : public AuxKernel
{
public:
    /// Static Member Function for Input Parameters
    static InputParameters validParams();
    
    /// Standard MOOSE public constructor
    TotalAirIonization(const InputParameters & parameters);
    
protected:
    /// Required MOOSE function override
    /** This is the function that is called by the MOOSE framework when a calculation of the total
     system pressure is needed. You are required to override this function for any inherited
     AuxKernel. */
    virtual Real computeValue() override;
    
    std::vector<const VariableValue *> _coupled_u;	///< Pointer list for the non-linear variables for number concentrations
    const VariableValue & _air_dens;				///< Variable for the density of air (kg/m^3)  == Typical Value: 1.225 kg/m^3
    const CARDINAL_Object & _user_object;			///< User object for CARDINAL simulation data/results
    Real _background_ionization;					///< Constant value for background ionization (ion-pairs/m^3/s)
    
    int _size_bins;									///< Number of particle size bins to consider
    int _nuc_bins;									///< Number of nuclide bins to consider (if any)
    
private:
    
};

