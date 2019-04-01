/*!
 *  \file CARDINAL_Object.h
 *	\brief General User Object to contain all information and algorithms associated with CARDINAL
 *	\details This file creates a GeneralUserObject for CARDINAL objects and functions in MOOSE. The
 *			CARDINAL object is made public to allow any kernels using this General Object to call
 *			CARDINAL member functions and have access to CARDINAL data. The CARDINAL object will be used
 *			to establish initial conditions for FENNEC simulations by estimating the cloud rise
 *			following a nuclear explosion of a particular size.
 *
 *  \author Austin Ladshaw
 *	\date 07/19/2018
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

#ifndef CARDINAL_OBJECT_H
#define CARDINAL_OBJECT_H

#include "GeneralUserObject.h"
#include "cardinal.h"

/// CARDINAL_Object class object forward declaration
class CARDINAL_Object;

template <>
InputParameters validParams<CARDINAL_Object>();

/// CARDINAL_Object class object inherits from GeneralUserObject
/** This class object inherits from the GeneralUserObject.
	All public and protected members of this class are required function overrides.
	The initialization step will read input and simulate cloud rise to serve as initial
	conditions for FENNEC transport simulations. Execution and finalize steps will not
	be utilized here. */
class CARDINAL_Object : public GeneralUserObject
{
public:
	/// Required constructor for GeneralUserObjects in MOOSE
	CARDINAL_Object(const InputParameters & parameters);
	
	/// Required initialization override for GeneralUserObjects in MOOSE
	/** This is called before execute so you can reset any internal data. */
	virtual void initialize();
	
	/// Required execution override for GeneralUserObjects in MOOSE
	/** Called on every "object" (like every element or node). */
	virtual void execute();
	
	/// Required finalize override for GeneralUserObjects in MOOSE
	/** Called _once_ after execute has been called all "objects". */
	virtual void finalize();
	
	/// Cardinal Object from utils folder
	/** This is made public so all kernels using this object will have access to Cardinal functions. */
	Cardinal cardinal;
	
protected:
	// ---------- Used to Establish Initial Conditions for Crane ------------
	double _yield;					///< Nuclear bomb yield (kT)
	double _det_hieght;				///< Hieght of detonation above ground (m)
	double _ground_zero;			///< Altitude of ground level above mean sea level (m)
	int _bins;						///< Number of bins for particle sizes
	bool _includeShear = false;		///< Boolean to determine whether or not to include wind shear in cloud rise
	bool _tightCoupling = false;	///< Boolean to determine whether or not to tightly couple cloud rise simulation
	
	// ---------- Used to Establish Dove Options for Crane ------------
	bool _fileout = false;
	bool _consoleout = false;
	double _tol = 0.1;
	double _dtmin = 1e-8;
	double _dtmax = 1.0;
	double _dtmin_conv = 0.0001;
	double _t_out = 0.1;
	double _endtime = 20.0;
	
	// ---------- Used to Establish PJFNK Options for Crane ------------
	bool _isLinear = false;
	bool _isPrecon = false;
	bool _nl_out = false;
	bool _l_out = false;
	int _max_nlit = 50;
	int _max_lit = 200;
	int _restart = 20;
	int _recursive = 2;
	double _nl_abstol = 1e-4;
	double _nl_reltol = 1e-6;
	double _l_abstol = 1e-6;
	double _l_reltol = 1e-4;
	
private:
	
};

#endif // CARDINAL_OBJECT_H
