/*!
*  \file CollisionParameters.h
*	\brief Material properties file to compute parameters associated with the population balance model
*	\details This file creates a MaterialProperty to calculate and store parameter information associated
*			with the collision frequencies and collision efficiencies associated with the population
*			balance model for radioactive debris particles. Each parameter is stored for later use in
*			other kernels of FENNEC. The calculated parameters can be used in either the Mono- or
*			Bi-variate forms of the population balance model. Parameters for particle diffusion are also
*			calculated and stored so that they can be used in the dispersion transport kernels. References
*			for the calculations and model contain herein are given below.
*
*			References
*			----------
*			[1] Y.H. Kim, S. Yiacoumi, I. Lee, J. McFarlane, C. Tsouris, Environ. Sci. Tech., 48, 182-189, 2014.
*			[2] Y.H. Kim, S. Yiacoumi, A. Nenes, C. Tsouris, Atmos. Chem. Phys., 16, 3449-3462, 2016.
*			[3] Y.H. Kim, S. Yiacoumi, A. Nenes, C. Tsouris, J. Aero. Sci., 114, 283-300, 2017.
*			[4] C.F. Clement, R.A. Clement, R.G. Harrison, J. Aero. Sci., 26, 1207-1225, 1995.
*			[5] M.Z. Jacobson, Fundamentals of Atmospheric Modeling (2nd Ed.), Cambridge U. Press, New York, 2005.
*			[6] R.G. Harrison, K.S. Carslaw, Review of Geophysics, 41, 2003.
*
*  \author Austin Ladshaw
*	\date 09/06/2019
*	\copyright This kernel was designed and built at the Georgia Institute
*             of Technology by Austin Ladshaw for PhD research in the area
*             of radioactive particle transport and settling following a
*			  nuclear event. It was developed for the US DOD under DTRA
*			  project No. 14-24-FRCWMD-BAA. Portions Copyright (c) 2019, all
*             rights reserved.
*
*			  Austin Ladshaw does not claim any ownership or copyright to the
*			  MOOSE framework in which these kernels are constructed, only
*			  the kernels themselves. The MOOSE framework copyright is held
*			  by the Battelle Energy Alliance, LLC (c) 2010, all rights reserved.
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

#include "CollisionParameters.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", CollisionParameters);

template<>
InputParameters validParams<CollisionParameters>()
{
    InputParameters params = validParams<Material>();
    params.addRequiredParam<UserObjectName>("cardinal_object","Name of the CARDINAL_Object object");
    params.addRequiredCoupledVar("coupled_conc","List of names of the number concentration variables being coupled (Must order the same in each kernel following Row Major Order)");
    params.addRequiredCoupledVar("air_density","Variable for air density (kg/m^3)");
    params.addRequiredCoupledVar("air_viscosity","Variable for air viscosity (kg/m/s)");
    params.addRequiredCoupledVar("temperature","Variable for air temperature (K)");
    params.addRequiredCoupledVar("ionization","Variable for air ionization (ion-pairs/m^3/s)");
    params.addRequiredCoupledVar("windx","Variable for wind velocity in x-direction");
    params.addRequiredCoupledVar("windy","Variable for wind velocity in y-direction");
    params.addRequiredCoupledVar("windz","Variable for wind velocity in z-direction");
    params.addRequiredCoupledVar("coupled_vx","List of names of the particle velocities in the x-direction being coupled (Must be in same order as coupled_conc list)");
    params.addRequiredCoupledVar("coupled_vy","List of names of the particle velocities in the y-direction being coupled (Must be in same order as coupled_conc list)");
    params.addRequiredCoupledVar("coupled_vz","List of names of the particle velocities in the z-direction being coupled (Must be in same order as coupled_conc list)");
    
    params.addParam<Real>("dissipation",0.0005,"Rate of dissipation of turbulent kinetic energy (m^2/s^3) - Typical values vary between 0.0003 on a clear day and 0.2 on a cloudy day.");
    params.addParam<Real>("neg_mobility",1.598E-4,"Mobility of negative ions (m^2/V/s) - Typical value: 1.598E-4.");
    params.addParam<Real>("pos_mobility",1.285E-4,"Mobility of positive ions (m^2/V/s) - Typical value: 1.285E-4.");
    params.addParam<Real>("ion_recomb",1.6E-12,"Ion-ion recombination coefficient (m^3/s) - Typical value: 1.6E-12.");
    
    return params;
}

CollisionParameters::CollisionParameters(const InputParameters & parameters):Material(parameters),

_user_object(getUserObject<CARDINAL_Object>("cardinal_object")),
_air_dens(coupledValueOld("air_density")),
_air_visc(coupledValueOld("air_viscosity")),
_temp(coupledValueOld("temperature")),
_ions(coupledValueOld("ionization")),
_wx(coupledValueOld("windx")),
_wy(coupledValueOld("windy")),
_wz(coupledValueOld("windz")),
_ed(getParam<Real>("dissipation")),
_m_neg(getParam<Real>("neg_mobility")),
_m_pos(getParam<Real>("pos_mobility")),
_arc(getParam<Real>("ion_recomb")),
_global_to_local(declareProperty<std::map<int,int> >("index_map")),
_diffusion(declareProperty<std::vector<Real> >("particle_diffusion")),
_beta_Br(declareProperty<std::vector<std::vector<Real> > >("particle_diffusion")),
_beta_CE(declareProperty<std::vector<std::vector<Real> > >("particle_diffusion")),
_beta_GC(declareProperty<std::vector<std::vector<Real> > >("particle_diffusion")),
_beta_TI(declareProperty<std::vector<std::vector<Real> > >("particle_diffusion")),
_beta_TS(declareProperty<std::vector<std::vector<Real> > >("particle_diffusion")),
_beta_VW(declareProperty<std::vector<std::vector<Real> > >("particle_diffusion")),
_alpha_Br(declareProperty<std::vector<std::vector<Real> > >("particle_diffusion"))
{
    unsigned int n = coupledComponents("coupled_conc");
    unsigned int xn = coupledComponents("coupled_vx");
    unsigned int yn = coupledComponents("coupled_vy");
    unsigned int zn = coupledComponents("coupled_vz");
    
    //Check for input file errors
    if (n != xn || n != yn || n != zn)
        moose::internal::mooseErrorRaw("Number of coupled variables does not match between given lists!");
    
    _N.resize(n);
    _vx.resize(n);
    _vy.resize(n);
    _vz.resize(n);
    
    for (unsigned int i = 0; i<_N.size(); ++i)
    {
    	_index[i] = coupled("coupled_conc",i);
        _N[i] = &coupledValueOld("coupled_conc",i);
        _vx[i] = &coupledValueOld("coupled_vx",i);
        _vy[i] = &coupledValueOld("coupled_vy",i);
        _vz[i] = &coupledValueOld("coupled_vz",i);
    }
    
    //Check for Mono- or Bi-variate population
    if (_user_object.isMonoVariate() == true)
    {
        _size_bins = _user_object.return_size_bins();
        _nuc_bins = 1;
    }
    else
    {
        _size_bins = _user_object.return_size_bins();
        _nuc_bins = _user_object.return_nuc_bins();
    }
    
}

//Initialize information
void CollisionParameters::initQpStatefulProperties()
{
	//Initialize memory space
    _diffusion[_qp].resize(_N.size());
    _beta_Br[_qp].resize(_N.size());
    _beta_CE[_qp].resize(_N.size());
    _beta_GC[_qp].resize(_N.size());
    _beta_TI[_qp].resize(_N.size());
    _beta_TS[_qp].resize(_N.size());
    _beta_VW[_qp].resize(_N.size());
    _alpha_Br[_qp].resize(_N.size());
    
    //Initialize constants
    _kB = 1.38065E-23;
    _ma = 4.8061E-26;
    _ec = 1.6E-19;
    _e0 = 8.85E-12;
    
    //Initialize intermediate vectors
    _rad.resize(_user_object.return_size_bins());
    _mass.resize(_user_object.return_size_bins());
    _vp.resize(_user_object.return_size_bins());
    _lam.resize(_user_object.return_size_bins());
    _y.resize(_user_object.return_size_bins());
    _omega.resize(_user_object.return_size_bins());
    _avg_charge.resize(_user_object.return_size_bins());
    _charge_lb.resize(_user_object.return_size_bins());
    _charge_ub.resize(_user_object.return_size_bins());
    
    //Calculate some unchanging values
    for (int i=0; i<_user_object.return_size_bins(); i++)
    {
        _rad[i] = (_user_object.return_diameter(i)/2.0)*1.0E-6;
        Real vol = (4.0/3.0)*3.14159*_rad[i]*_rad[i]*_rad[i];
        _mass[i] = vol*_user_object.return_debris_density();
    }
    
    //Fill out global indices
    for (unsigned int lm = 0; lm<_N.size(); ++lm)
    {
    	//Give global index of variable and return local index in parameters/lists
    	_global_to_local[_qp][_index[lm]] = lm;
        _beta_Br[_qp][lm].resize(_N.size());
        _beta_CE[_qp][lm].resize(_N.size());
        _beta_GC[_qp][lm].resize(_N.size());
        _beta_TI[_qp][lm].resize(_N.size());
        _beta_TS[_qp][lm].resize(_N.size());
        _beta_VW[_qp][lm].resize(_N.size());
        _alpha_Br[_qp][lm].resize(_N.size());
    }
    
}

//Compute properties
void CollisionParameters::computeQpProperties()
{
	//Simple inline calculations
    _va = sqrt( 8.0*_kB*_temp[_qp]/3.14159/_ma );
    _AH = 100.0*_kB*_temp[_qp]; //NOTE: May change to more precise calculation later
    calculate_n0();
    
    //Calculation of vector parameters
    calculate_vp();
    calculate_y();
    calculate_omega();
    calculate_avg_charge();
    calculate_charge_bounds();
    
    //Calculation of the material properties
    calculate_diffusion();
    calculate_beta_Br();
    calculate_beta_CE();
    calculate_beta_GC();
}

/// Calculation of mean ion charge
void CollisionParameters::calculate_n0()
{
    Real sum = 0.0;
    for (unsigned int lm = 0; lm<_N.size(); ++lm)
    {
        int l = (int)lm/_nuc_bins;
        sum += (*_N[lm])[_qp]*_user_object.return_activity(l);
    }
    _n0 = sqrt( (_ions[_qp] + sum)/_arc );
}

/// Calculation of thermal speed of debris particles
void CollisionParameters::calculate_vp()
{
    for (unsigned int l = 0; l<_size_bins; l++)
    {
        _vp[l] = sqrt( 8.0*_kB*_temp[_qp]/3.14159/_mass[l] );
    }
}

/// Calculation of y parameter
void CollisionParameters::calculate_y()
{
    for (unsigned int l = 0; l<_size_bins; l++)
    {
    	_y[l] = _e0*_user_object.return_activity(l)/_ec/_m_neg/_n0;
    }
}

/// Calculation of omega parameter
void CollisionParameters::calculate_omega()
{
    for (unsigned int l = 0; l<_size_bins; l++)
    {
        _omega[l] = _ec*_ec/8.0/3.14159/_e0/_rad[l]/_kB/_temp[_qp];
    }
}

/// Calculation of average charge parameter
void CollisionParameters::calculate_avg_charge()
{
    for (unsigned int l = 0; l<_size_bins; l++)
    {
    	Real check = _omega[l]*_y[l];
        Real X = _m_pos/_m_neg;
        if (check > 0.22)
        	_avg_charge[l] = _y[l] - ( (_y[l]*(X-1.0)) / (exp(2.0*check)-1.0) );
        else
        	_avg_charge[l] = _y[l] + ((X-1.0)/(2.0*_omega[l]));
    }
}

/// Calculation of charge boundaries for the average charge parameter
void CollisionParameters::calculate_charge_bounds()
{
    for (unsigned int l = 0; l<_size_bins; l++)
    {
    	_charge_lb[l] = (int)_avg_charge[l] - 15;
        _charge_ub[l] = (int)_avg_charge[l] + 15;
    }
}

/// Calculation of particle diffusion
void CollisionParameters::calculate_diffusion()
{
    for (unsigned int lm = 0; lm<_N.size(); ++lm)
    {
        int l = (int)lm/_nuc_bins;
        Real lambda = 2.0*_air_visc[_qp]/_air_dens[_qp]/_va;
        Real Kn = lambda/_rad[l];
        Real G = 1.0 + Kn*(1.249 + 0.42*exp(-0.87/Kn));
        _diffusion[_qp][lm] = _kB*_temp[_qp]*G/6.0/3.14159/_air_visc[_qp]/_rad[l];
        _lam[l] = 8.0*_diffusion[_qp][lm]/3.14159/_vp[l];
    }
}

/// Calculation of intermediate for Brownian frequency
Real CollisionParameters::del(int l)
{
    Real top = pow(2.0*_rad[l] + _lam[l],3.0) - pow(4.0*_rad[l]*_rad[l] + _lam[l]*_lam[l],3.0/2.0);
    Real bot = 6.0*_rad[l]*_lam[l];
    return (top/bot) - 2.0*_rad[l];
}

/// Calculation of Brownian frequency
void CollisionParameters::calculate_beta_Br()
{
    for (unsigned int lm = 0; lm<_N.size(); ++lm)
    {
        int l = (int)lm/_nuc_bins;
        Real dl = del(l);
        for (unsigned int qr = 0; qr<_N.size(); ++qr)
        {
            int q = (int)qr/_nuc_bins;
            Real dq = del(q);
            
            Real top = 4.0*3.14159*(_rad[l]+_rad[q])*(_diffusion[_qp][lm]+_diffusion[_qp][qr]);
            Real bot = ( (_rad[l]+_rad[q]) / ((_rad[l]+_rad[q])+sqrt(dl*dl+dq*dq)) ) + ( (4.0*(_diffusion[_qp][lm]+_diffusion[_qp][qr])) / ((_rad[l]+_rad[q])*sqrt(_vp[l]*_vp[l]+_vp[q]*_vp[q])) );
            
            _beta_Br[_qp][lm][qr] = top/bot;
        }
    }
}

/// Calcualtion of the Reynolds number for Convective frequency
Real CollisionParameters::Reynolds(int qr)
{
	int q = (int)qr/_nuc_bins;
    Real ux = fabs((*_vx[qr])[_qp] - _wx[_qp]);
    Real uy = fabs((*_vy[qr])[_qp] - _wy[_qp]);
    Real uz = fabs((*_vz[qr])[_qp] - _wz[_qp]);
    Real u_mag = sqrt(pow(ux, 2.0) + pow(uy, 2.0) + pow(uz, 2.0));
    
    return 2.0*_air_dens[_qp]*_rad[q]*u_mag/_air_visc[_qp];
}

/// Calculation of the Schmidt number for Convective frequency
Real CollisionParameters::Schmidt(int lm)
{
    return _air_visc[_qp]/_diffusion[_qp][lm]/_air_dens[_qp];
}

/// Calculation of Convective frequency
void CollisionParameters::calculate_beta_CE()
{
    for (unsigned int lm = 0; lm<_N.size(); ++lm)
    {
        Real Sc = Schmidt(lm);
        for (unsigned int qr = 0; qr<_N.size(); ++qr)
        {
            Real Re = Reynolds(qr);
            
            if (Re <= 1.0)
            	_beta_CE[_qp][lm][qr] = 0.45*_beta_Br[_qp][lm][qr]*pow(Re,1.0/3.0)*pow(Sc,1.0/3.0);
            else
            	_beta_CE[_qp][lm][qr] = 0.45*_beta_Br[_qp][lm][qr]*pow(Re,1.0/2.0)*pow(Sc,1.0/3.0);
        }
    }
}

/// Calculation of relative velocity between two particles
Real CollisionParameters::RelVel(int lm, int qr)
{
    Real ux = fabs((*_vx[lm])[_qp] - (*_vx[qr])[_qp]);
    Real uy = fabs((*_vy[lm])[_qp] - (*_vy[qr])[_qp]);
    Real uz = fabs((*_vz[lm])[_qp] - (*_vz[qr])[_qp]);
    return sqrt(pow(ux, 2.0) + pow(uy, 2.0) + pow(uz, 2.0));
}

/// Calculation of Gravitational frequency
void CollisionParameters::calculate_beta_GC()
{
    for (unsigned int lm = 0; lm<_N.size(); ++lm)
    {
    	int l = (int)lm/_nuc_bins;
        for (unsigned int qr = 0; qr<_N.size(); ++qr)
        {
        	int q = (int)qr/_nuc_bins;
            Real vel = RelVel(lm,qr);
            _beta_GC[_qp][lm][qr] = 3.14159*(_rad[l]+_rad[q])*(_rad[l]+_rad[q])*vel;
        }
    }
}


