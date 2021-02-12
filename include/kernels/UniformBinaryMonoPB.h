/*!
*  \file UniformBinaryMonoPB.h
*	\brief Kernel for Uniform Binary Breakage in a Mono-variate Population Balance Model
*	\details This file creates a MOOSE kernel that will couple together multiple number
*			concentrations of particles and calculate a population balance rate function
*			for particle breakup based on the uniform binary breakage function. This module
*			is based on the following works:
*
*			S. Kumar, D. Ramkrisha, Chem. Eng. Sci., 51, 1311-1332, 1996a.
*
*			P.J. Hill, K.M. Ng, AIChE J., 41, 1204-1216, 1995.
*
*			Y.K. Ho, P. Doshi, H.K. Yeoh, G.C. Ngoh, Chem. Eng. Sci., 116, 601-610, 2014.
*
*  \author Alexander Wiechert
*	\date 01/11/2021
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

#include "Kernel.h"

/// UniformBinaryMonoPB class object forward declarations
class UniformBinaryMonoPB;

template<>
InputParameters validParams<UniformBinaryMonoPB>();

/// UniformBinaryMonoPB class object inherits from Kernel object
/** This class object inherits from the Kernel object in the MOOSE framework.
All public and protected members of this class are required function overrides.
The kernel has a set of parameters (alpha and beta) that may be computed
by other future kernels.
*/

class UniformBinaryMonoPB : public Kernel
{
public:
	/// Required constructor for objects in MOOSE
	UniformBinaryMonoPB(const InputParameters & parameters);

protected:
	/// Function to compute outcome of Kronecker Delta Function
	Real KroneckerDelta(int i, int j);

	/// Function to fill out all the volume size bins
	void VolumeFill();

	/// Function to fill out all fragment numbers
	void FragmentFill();

	/// Required residual function for standard kernels in MOOSE
	/** This function returns a residual contribution for this object.*/
	virtual Real computeQpResidual() override;

	/// Required Jacobian function for standard kernels in MOOSE
	/** This function returns a Jacobian contribution for this object. The Jacobian being
	computed is the associated diagonal element in the overall Jacobian matrix for the
	system and is used in preconditioning of the linear sub-problem. */
	virtual Real computeQpJacobian() override;

	/// Not Required, but aids in the preconditioning step
	/** This function returns the off diagonal Jacobian contribution for this object. By
	returning a non-zero value we will hopefully improve the convergence rate for the
	cross coupling of the variables. */
	virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

	/// Parameters for the base class are listed below

	unsigned int _M;									///< Number of particle size bins
	Real _b_coeff;										///< Constant breakup rate coefficient (1/s)
	Real _f_num;										///< Number of fragments formed during breakup (-)

	std::vector< Real > _dia;							///< Set of size class diameters (m)
	std::vector< Real > _vol;							///< Set of volume based size bins (m^3) [assumes spheres]
    std::vector< std::vector< Real > > _frag;			///< Set of fragmentation number for breakup (-)

	std::vector<const VariableValue *> _coupled_u;		///< Pointer list to the coupled number concentrations (Gp/m^3)
	std::vector<unsigned int> _coupled_u_var;			///< Indices for the number concentrations in the system

	const unsigned int _u_var;							///< Variable identification for the primary coupled variable
	unsigned int _this_var;								///< Relative Index for this non-linear variable

	std::unordered_map<unsigned int, unsigned int> _those_var;	///< Relative indices for the list of non-linear variables

private:

};
