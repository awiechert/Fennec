/*!
 *  \file ADAggregationMPB.h
 *	\brief AD Kernel for Mono-variate Population Balance Model with all coagulation coefficients
 *	\details This file creates a MOOSE AD kernel that will couple together multiple number
 *			concentrations of particles and calculate a population balance rate function
 *			assuming the collision efficiency and frequency are calculated from Brownian
 *			diffusion, Brownian convection enhancement, gravitational collection, turbulent 
 *			inertial motion, and turbulent shear functions.
 *
 *			Y.H. Kim, S. Yiacoumi, A. Nenes, C. Tsouris, J. Aero. Sci., 114, 283-300, 2017.
 *
 *			M.Z. Jacobson, Fundamentals of Atmospheric Modeling (2nd Ed.), Cambridge University
 *				Press, New York, 2005.
 *
 *  \author Alexander Wiechert
 *	\date 01/10/2022
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

#include "ADKernel.h"

/// ADAggregationMPB class object forward declarations
class ADAggregationMPB;

/// ADAggregationMPB class object inherits from ADKernel object
/** This class object inherits from the ADKernel object in the MOOSE framework.
	All public and protected members of this class are required function overrides.
	The kernel has a set of parameters (alpha and beta) that may be computed
    by other future kernels.
 */

class ADAggregationMPB : public ADKernel
{
public:
    /// Static Member Function for Input Parameters
    static InputParameters validParams();
    
    /// Required constructor for objects in MOOSE
    ADAggregationMPB(const InputParameters & parameters);
    
protected:
	/// Function to compute outcome of Kronecker Delta Function
    Real KroneckerDelta(int i, int j);
    
    /// Function to fill out all the alpha and beta parameters with constants
    void AlphaBetaFill();
    
    /// Function to fill out all the volume size bins
    void VolumeFill();
    
    /// Function to fill out all the fraction values
    void FractionFill();
    
    /// Function to fill out all the gama values
    void GamaFill();

    /// Required residual function for standard kernels in MOOSE
    /** This function returns a residual contribution for this object.*/
    virtual ADReal computeQpResidual() override;
    
    /// Parameters for the base class are listed below
    
    unsigned int _M;										///< Number of particle size bins
    std::vector< std::vector< std::vector<Real> > > _frac;	///< Set of vector fractions based on the size classes of the variables
    std::vector< Real > _dia;								///< Set of size class diameters (m)
    std::vector< Real > _vol;								///< Set of volume based size bins (m^3) [assumes spheres]
    std::vector< std::vector< ADReal > > _alpha;				///< Set of collision efficiencies (-)
    std::vector< std::vector< ADReal > > _beta;				///< Set of collision frequencies (m^3/s)
    std::vector< std::vector< Real > > _gama;				///< Set of volume check parameters computed at initialization
    
    std::vector<const VariableValue *> _coupled_u;		///< Pointer list to the coupled number concentrations (Gp/m^3)
    std::vector<unsigned int> _coupled_u_var;			///< Indices for the number concentrations in the system
    const unsigned int _u_var;							///< Variable identification for the primary coupled variable
    unsigned int _this_var;										///< Relative Index for this non-linear variable
    std::unordered_map<unsigned int, unsigned int> _those_var;	///< Relative indices for the list of non-linear variables
    
    bool _gama_correction;								///< Boolean to specify use of gama correction term (Always true when not testing)
    
    const MaterialProperty<std::vector<std::vector<Real> > > & _beta_Br;	///< MaterialProperty for the Brownian frequency (m^3/s) ==> size = num_var x num_var
    const MaterialProperty<std::vector<std::vector<Real> > > & _alpha_Br;	///< MaterialProperty for the Brownian, Convective, and van der Waals efficiency (-) ==> size = num_var x num_var
    
private:
    
};
