/*!
 *  \file gsta_opt.h gsta_opt.cpp
 *	\brief Generalized Statistical Thermodynamic Adsorption (GSTA) Optimization Routine
 *	\details Optimization routine developed for the GSTA isotherm and data analysis. This
 *			algorithm was the primary subject of a publication made in Fluid Phase Equilibria.
 *			Please refer to the below paper for technical information about the algorithms.
 *
 *			Reference: Ladshaw, Yiacoumi, Tsouris, and DePaoli, Fluid Phase Equilibria, 388,
 *			169-181, 2015.
 *
 *			The GSTA model was first introduced by Llano-Restrepo and Mosquera (2009). Please
 *			refer to the below reference for theoretical information about the model.
 *
 *			Reference: Llano-Restrepo and Mosquera, Fluid Phase Equilibria, 283, 73-88, 2009.
 *
 *  \author Austin Ladshaw
 *	\date 12/17/2013
 *	\copyright This software was designed and built at the Georgia Institute
 *             of Technology by Austin Ladshaw for PhD research in the area
 *             of adsorption and surface science. Copyright (c) 2015, all
 *             rights reserved.
 */

#ifndef GSTA_OPT_HPP_
#define GSTA_OPT_HPP_

#include "lmcurve.h"			  //Main include to use the lmfit solver library
#include <stdio.h>				  //Line to allow for printf functions
#include <math.h>                 //Line added to allow usage of the pow (e, x) function
#include <iostream>				  //Line to allow for read/write to the console using cpp functions
#include <fstream>				  //Line to allow for read/write to and from .txt files
#include <stdlib.h>				  //Line need to convert strings to doubles
#include <vector>				  //Line needed to use dynamic arrays called vectors
#include <time.h>				  //Line needed to display program runtime
#include <float.h>				  //Line to allow use of machine constants
#include <string>    			  //Line to allow use of c++ strings
#include "error.h"

#ifndef	Po
#define Po 100.0				///< Standard State Pressure - Units: kPa
#endif

#ifndef	R
#define R 8.3144621				///< Gas Constant - Units: J/(K*mol) = kB * Na
#endif

#ifndef	Na
#define Na 6.0221413E+23		///< Avagadro's Number - Units: molecules/mol
#endif

/// Data structure used in the GSTA optimization routines
/** C-style structure that keeps track of all infomation during the optimization routine.
	All solutions and parameters to the GSTA isotherm are held in order to find the best
	solution with the fewest parameters. */
typedef struct
{
	int total_eval;												///< Keeps track of the total number of function evaluations
	int n_par;													///< Number of parameters being optimized for
	double qmax;												///< Maximum theoretical adsorption capacity (M/M) (0 if unknown)
 	int iso;													///< Keeps isotherm that is currently being optimized
    std::vector<std::vector<double> > Fobj;						///< Creates a dynamic array to store all Fobj values
    std::vector<std::vector<double> > q,P;						///< Creates a dynamic array for q and P data pairs
    std::vector<std::vector<double> > best_par;					///< Used to store the values of the parameters of best fit
    std::vector<std::vector<double> > Kno;						///< Dimensionless parameters determined from best_par
    std::vector<std::vector<std::vector<double> > > all_pars;  	///< Used to create a ragged array of all parameters
    std::vector<std::vector<double> > norms;					///< Used to store the values of all the calculated norms
    std::vector<double> opt_qmax;								///< If qmax is unknown, this vector holds it's optimized values
} GSTA_OPT_DATA;

/// Function rounds a double to an integer
/** This function returns a rounded value of d. Rounding up for any decimal 
	larger than 0.5 and down for all else. */
int roundIt(double d);

/// Function returns the rounded two-fifths result of int m
/** This function is used to determine what the maximum number of parameters should
	be based on the number of data points m. It is designed to prevent the algorithms
	from "over fitting" the data. */
int twoFifths(int m);

/// Function returns the order of magnitude for the parameter x
/** This function is used to help create initial guesses for the new GSTA parameters
	that are being optimized for. In order to make sure that those parameters are 
	considered relavent in the optimization routine, we need to make the initial 
	guesses to be around the same order of magnitude of the other GSTA parameters. */
int orderMag(double x);

/// Function returns the minimum integer in an array of integers
/** This function is used to determine the minimum number of GSTA parameters that
	were required to adequately fit the isotherm data. */
int minValue(std::vector<int> &array);

/// Function returns the index of the minimum integer in an array of integers
/** This function identifies the index of the minimum number of parameters needed
	for the GSTA model to fit the data. This index is common for all vectors in the
	GSTA_OPT_DATA structure and is used to identify the most suitable solution.*/
int minIndex(std::vector<double> &array);

/// Function returns the average integer value in an array of integers
/** This function is used to identify the average number of parameters that all
	the data fitting needed for each GSTA analysis. */
int avgPar(std::vector<int> &array);

/// Function returns an average in an array of doubles
double avgValue(std::vector<double> &array);

/// Function returns a weighted average in an array
/** This averaging scheme is used to approximate the qmax parameter for the GSTA isotherm
	model, if that value is unknown. The weighting is based on the euclidean norms of all
	the fits of the data. Smaller norms are more heavily weighted since they represent a
	better fit of the data. Once averaging is complete and we have an estimate for qmax,
	the entire algorithm is re-run holding that qmax constant. 
 
	\param enorm array of euclidean norms from the fitting of the data
	\param x array of optimum qmax values to be averaged
	\param n the number of enorm and x values in the array*/
double weightedAvg(double *enorm, double *x, int n);

/// Function calculates the Coefficient of Determination (R Squared) for the temperature regression
/** This function is used to determine the "fittness" of the linear regression performed on the
	temperature independent parameters of the GSTA isotherm. A good linear regression should return
	a value between 1.0 and 0.9. 
 
	\param x observations in the x-axis
	\param y observations in the y-axis
	\param slope slope of the linear regression 
	\param vint intercept of the linear regression
	\param m_dat number of data points used in the linear regression*/
double rSq(double *x, double *y, double slope, double vint, int m_dat);

/// Function looks at the list of parameters to check if they are smoothly changing
/** This function takes the parameter array par and GSTA_OPT_DATA structure and checks
	to see if those parameters are changing smoothly. If they are erratic or non-smooth,
	then it could be an indication of "over fitting" of the data. */
bool isSmooth(double *par, void *data);

/// Function performs an Orthogonal Linear Regression on a set of data
/** This function takes an array of x and y observations and performs an orthogonal
	linear regression on that information to find optimum parameters for slope and
	intercept. 
 
	\param x array of x-axis observations
	\param y array of y-axis observations
	\param par array of parameter results after regression
	\param m_dat number of data points or observations
	\param n_par number of parameters to seek (if n_par != 1 or 2, then par[0] = intercept and par[1] = slope)*/
void orthoLinReg(double *x, double *y, double *par, int m_dat, int n_par);

/// Function will formed an educated guess for the next set of parameters in the GSTA analysis
/** This function takes partial pressure and adsorption observations, P and q, and tries to give
	a decent initial guess to what the GSTA parameters, par, will be for the next iteration. 
 
	\param P partial pressure observations in the data (kPa)
	\param q adsorption observations in the data (any units)
	\param par parameter array for the GSTA isotherm
	\param k index of the current number of parameters being considered
	\param m_dat number of pressure-adsorption observations in the isotherm
	\param data pointer to the GSTA_OPT_DATA data structure*/
void eduGuess(double *P, double *q, double *par, int k, int m_dat, void *data);

/// Function evaluates the result of the GSTA isotherm model
/** This function will evaluate the GSTA model and return the adsorbed amount given the current
	partial pressure p and the equilibrium parameters K.
 
	\param p current partial pressure (kPa)
	\param K array of equilibrium parameters (1/kPa^n)
	\param qmax the theorectical maximum capacity for the isotherm
	\param n_par the number of equilibrium parameters*/
double gstaFunc( double p, const double *K, double qmax, int n_par);

/// Function to evaulate the GSTA objective function value
/** The objective function seeks to penalize the relative fittness of the model based on the number
	of parameters it took to minimize the euclidean norms. By penalizing the fittness of the model
	in this fashion, we can find the best solution to the system that required the least number of
	equilibrium parameters. */
double gstaObjFunc(double *t, double *y, double *par, int m_dat, void *data);

/// Function to evaluate the GSTA model and feed into the lmfit routine
/** This function will formulate the residuals that go into the Levenberg-Marquardt's Algorithm for
	non-linear least squares regression. The form of this function is specific to how we interface
	with the lmfit routines. */
void eval_GSTA(const double *par, int m_dat, const void *data, double *fvec, int *info);

/// Function to perform the GSTA optimization routine
/** This function is callable from the UI and is used to find the optimum parameters of the GSTA
	isotherm model given a particular set of isotherm data for single-component adsorption equilibria.
	
	\param fileName name of the input file that holds the isotherm data*/

/** \note The input file for the GSTA optimization routine is a text file holding the necessary information
	and data needed to run the routine. That input file has a very specific format that is detailed below. \n
 
	Number of Isotherm Curves \n
	Theoretical Maximum Adsorption Capacity (if unknown, provide 0) \n
	Temperature of the ith Isotherm (K) \n
	Number of Data points for the ith Isotherm \n
	Partial Pressure (kPa)      [tab]       Corresponding Adsorbed Amount (any units) \n
 
	(2nd Line down is repeated for all isotherms you are optimizing on...) \n
 
	Example:
	--------
	2 \n
	21.0 \n
	298.15 \n
	4 \n
	0.000165483	   2.77 \n
	0.000306379	   2.75 \n
	0.00044922	   5.00 \n
	0.000939259	   10.40 \n
	313.15 \n
	4 \n
	0.000589636	   2.75 \n
	0.001063584	   3.70 \n
	0.001351836	   4.2 \n
	0.001543464	   4.6 \n
 
	The above example would be for 2 sets of isotherms at 298.15 and 313.15 K, respectively. Maximum adsorption
	capacity is given as 21 (which in this has units of wt%). Each isotherm has 4 data points, which are given in
	a list as p (kPa) and q (wt%) pairs. Units of adsorption don't matter as long as they are consistent. If you
	give maximum capacity in mol/kg, then the q's in the lists must also be in mol/kg.
	*/
int gsta_optimize(const char* fileName);

#endif
