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

#pragma once

#include "AuxKernel.h"

/// CollisionTesting class object forward declaration
class CollisionTesting;

template<>
InputParameters validParams<CollisionTesting>();

/// CollisionTesting class inherits from AuxKernel
/** This class object creates an AuxKernel for use in the MOOSE framework.  */
class CollisionTesting : public AuxKernel
{
public:
    /// Standard MOOSE public constructor
    CollisionTesting(const InputParameters & parameters);
    
protected:
    /// Required MOOSE function override
    /** This is the function that is called by the MOOSE framework when a calculation of the total
     system pressure is needed. You are required to override this function for any inherited
     AuxKernel. */
    virtual Real computeValue() override;
    
    /// Function to setup the local index
    void findLocalIndex();
    
    const VariableValue & _N;					///< Variable for number concentration
    const VariableValue & _N_other;				///< Variable for number concentration
    unsigned int _global_index;					///< Variable for global index for number concentration
    unsigned int _local_index;					///< Variable for local index for number concentration
    unsigned int _global_index_other;			///< Variable for global index for number concentration
    unsigned int _local_index_other;			///< Variable for local index for number concentration
    bool _found;								///< Boolean used to determine if index has been found
    
    const MaterialProperty<std::vector<int> > & _local_to_global;///< MaterialProperty for the local -> global indices for conc variables ==> size = num_var
    const MaterialProperty<std::vector<Real> > & _diffusion;	///< MaterialProperty for the particle diffusion (m^2/s) ==> size = num_var
    
    const MaterialProperty<std::vector<std::vector<Real> > > & _beta_Br;	///< MaterialProperty for the Brownian frequency (m^3/s) ==> size = num_var x num_var
    const MaterialProperty<std::vector<std::vector<Real> > > & _beta_CE;	///< MaterialProperty for the Convective frequency (m^3/s) ==> size = num_var x num_var
    const MaterialProperty<std::vector<std::vector<Real> > > & _beta_GC;	///< MaterialProperty for the Gravitational frequency (m^3/s) ==> size = num_var x num_var
    const MaterialProperty<std::vector<std::vector<Real> > > & _beta_TI;	///< MaterialProperty for the Inertial frequency (m^3/s) ==> size = num_var x num_var
    const MaterialProperty<std::vector<std::vector<Real> > > & _beta_TS;	///< MaterialProperty for the Shear frequency (m^3/s) ==> size = num_var x num_var
    const MaterialProperty<std::vector<std::vector<Real> > > & _beta_VW;	///< MaterialProperty for the van der Waals frequency (m^3/s) ==> size = num_var x num_var
    const MaterialProperty<std::vector<std::vector<Real> > > & _alpha_Br;	///< MaterialProperty for the Brownian efficiency (-) ==> size = num_var x num_var
    
private:
    
};

