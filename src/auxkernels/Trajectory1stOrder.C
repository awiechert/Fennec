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

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", Trajectory1stOrder);

template<>
InputParameters validParams<Trajectory1stOrder>()
{
	InputParameters params = validParams<AuxKernel>();
	params.addRequiredCoupledVar("windx","Variable for wind velocity in x-direction");
    params.addRequiredCoupledVar("windy","Variable for wind velocity in y-direction");
    params.addRequiredCoupledVar("windz","Variable for wind velocity in z-direction");
    params.addRequiredCoupledVar("varx","Variable for Particle velocity in x-direction");
    params.addRequiredCoupledVar("vary","Variable for Particle velocity in y-direction");
    params.addRequiredCoupledVar("varz","Variable for Particle velocity in z-direction");
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
_wx(coupledValueOld("windx")),
_wy(coupledValueOld("windy")),
_wz(coupledValueOld("windz")),
_vx(coupledValueOld("varx")),
_vy(coupledValueOld("vary")),
_vz(coupledValueOld("varz")),
_air_dens(coupledValueOld("air_density")),
_air_visc(coupledValueOld("air_viscosity")),
_u_old(uOld()),
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
	Real ux = fabs(_vx[_qp] - _wx[_qp]);
    Real uy = fabs(_vy[_qp] - _wy[_qp]);
    Real uz = fabs(_vz[_qp] - _wz[_qp]);
	Real u_mag = sqrt(pow(ux, 2.0) + pow(uy, 2.0) + pow(uz, 2.0));
	Real Re = _air_dens[_qp]*_part_dia*u_mag/_air_visc[_qp];
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
	Real ux = fabs(_vx[_qp] - _wx[_qp]);
    Real uy = fabs(_vy[_qp] - _wy[_qp]);
    Real uz = fabs(_vz[_qp] - _wz[_qp]);
	Real C = _drag*pi*_part_dia*_part_dia*_air_dens[_qp]/8.0;
	Real a = pi*_part_dia*_part_dia*_part_dia*_grav*(_air_dens[_qp]-_part_dens)/6.0;
	Real m = _part_dens*pi*_part_dia*_part_dia*_part_dia/6.0;
    Real u_mag;
	Real wind;
	if (_n == 2)
    {
    	wind = _wz[_qp];
        u_mag = uz;
    }
	else if (_n == 1)
    {
    	wind = _wy[_qp];
        u_mag = uy;
    }
	else if (_n == 0)
    {
    	wind = _wx[_qp];
        u_mag = ux;
    }
    else
    {
        wind = _wz[_qp];
        u_mag = uz;
    }
	
	if (_n == 2)
		vel = (m*_u_old[_qp]+_dt*a+_dt*C*u_mag*wind)/(m+_dt*C*u_mag);
	else
		vel = (m*_u_old[_qp]+_dt*C*u_mag*wind)/(m+_dt*C*u_mag);
	
	if (_part_dia < 0.0001)
	{
		Real v_max;
		if (_n == 2)
			v_max = -sqrt(-a/C)+wind;
		else
			v_max = wind;
	
		if (fabs(v_max) < fabs(vel))
			vel = v_max;
	}
	
	return vel;
}


