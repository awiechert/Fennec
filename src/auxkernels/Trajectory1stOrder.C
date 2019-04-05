/*!
 *  \file Trajectory1stOrder.h
 *	\brief Auxillary kernel to estimate particle trajectory in z-direction with 1st Order method
 *	\details This file creates an auxillary kernel that computes the particle velocity in the z
 *				dimension using a 1st order approximation method. It should be coupled with
 *				variables for air density and wind velocity. Those variables will be calculated
 *				using other auxillary kernels or can be non-linear variables. Particles are assumed
 *				spherical in shape and are impacted by gravitational settling as well as wind velocity.
 *				There are a set of each of the kernels for each cartesian direction
 *
 *  \author Austin Ladshaw
 *	\date 04/05/2019
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

#include "Trajectory1stOrder.h"

template<>
InputParameters validParams<Trajectory1stOrder>()
{
	InputParameters params = validParams<AuxKernel>();
	params.addRequiredCoupledVar("wind","Variable for wind velocity in n-direction");
	params.addRequiredCoupledVar("air_density","Variable for air density (kg/m^3)");
	params.addRequiredCoupledVar("air_viscosity","Variable for air viscosity (kg/m/s)");
	params.addParam<Real>("particle_diameter",0.001,"Spherical particle diameter (m)");
	params.addParam<Real>("particle_density",2600.0,"Spherical particle density (kg/m^3)");
	params.addParam<Real>("gravity",9.8,"Gravitational acceleration (m/s^2)");
	params.addParam<int>("direction",2,"Cartesian direction for velocity calculation (0 = x, 1 = y, 2 = z");
	return params;
}

Trajectory1stOrder::Trajectory1stOrder(const InputParameters & parameters) :
AuxKernel(parameters),
_w(coupledValueOld("wind")),
_air_dens(coupledValueOld("air_density")),
_air_visc(coupledValueOld("air_viscosity")),
_part_dia(getParam<Real>("particle_diameter")),
_part_dens(getParam<Real>("particle_density")),
_grav(getParam<Real>("gravity")),
_n(getParam<int>("direction"))
{
	if (_n < 0 || _n > 2) _n = 2;
}

// Drag coefficient calculation is based on the Turton & Levenspiel (1986) approximation method
void Trajectory1stOrder::computeDrag()
{
	Real u = fabs(_u_old[_qp] - _w[_qp]);
	Real Re = _air_dens[_qp]*_part_dia*u/_air_visc[_qp];
	if (Re < 0.1)
		_drag = 500.0;
	else
		_drag = (24.0/Re) + (4.152/pow(Re,0.343)) + (0.413/(1+16300.0*pow(Re,-1.09)));
}

Real Trajectory1stOrder::computeValue()
{
	Real vel = 0.0;
	
	this->computeDrag();
	
	Real pi = 3.14159;
	Real C = _drag*pi*_part_dia*_part_dia*_air_dens[_qp]/8.0;
	Real u = fabs(_u_old[_qp] - _w[_qp]);
	Real a = pi*_part_dia*_part_dia*_part_dia*_grav*(_air_dens[_qp]-_part_dens)/6.0;
	Real m = _part_dens*pi*_part_dia*_part_dia*_part_dia/6.0;
	
	if (_n == 2)
		vel = (m*_u_old[_qp]+_dt*a+_dt*C*u*_w[_qp])/(m+_dt*C*u);
	else
		vel = (m*_u_old[_qp]+_dt*C*u*_w[_qp])/(m+_dt*C*u);
	
	return vel;
}


