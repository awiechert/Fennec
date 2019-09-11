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
*			[7] B. Zhao, J. Wu, Atmospheric Environment, 40, 457-466, 2006.
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
_local_to_global(declareProperty<std::vector<int> >("index_list")),
_diffusion(declareProperty<std::vector<Real> >("particle_diffusion")),
_eddy_diff(declareProperty<std::vector<Real> >("eddy_diffusion")),
_dispersion(declareProperty<std::vector<Real> >("particle_dispersion")),
_beta_Br(declareProperty<std::vector<std::vector<Real> > >("beta_Br")),
_beta_CE(declareProperty<std::vector<std::vector<Real> > >("beta_CE")),
_beta_GC(declareProperty<std::vector<std::vector<Real> > >("beta_GC")),
_beta_TI(declareProperty<std::vector<std::vector<Real> > >("beta_TI")),
_beta_TS(declareProperty<std::vector<std::vector<Real> > >("beta_TS")),
_beta_VW(declareProperty<std::vector<std::vector<Real> > >("beta_VW")),
_alpha_Br(declareProperty<std::vector<std::vector<Real> > >("alpha_Br")),
_alpha_GC(declareProperty<std::vector<std::vector<Real> > >("alpha_GC"))
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
    _index.resize(n);
    
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
    _eddy_diff[_qp].resize(_N.size());
    _dispersion[_qp].resize(_N.size());
    _beta_Br[_qp].resize(_N.size());
    _beta_CE[_qp].resize(_N.size());
    _beta_GC[_qp].resize(_N.size());
    _beta_TI[_qp].resize(_N.size());
    _beta_TS[_qp].resize(_N.size());
    _beta_VW[_qp].resize(_N.size());
    _alpha_Br[_qp].resize(_N.size());
    _alpha_GC[_qp].resize(_N.size());
    _local_to_global[_qp].resize(_N.size());
    
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
    _tau.resize(_user_object.return_size_bins());
    _y.resize(_user_object.return_size_bins());
    _omega.resize(_user_object.return_size_bins());
    _avg_charge.resize(_user_object.return_size_bins());
    _std_charge.resize(_user_object.return_size_bins());
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
    	_local_to_global[_qp][lm] = _index[lm];
        _beta_Br[_qp][lm].resize(_N.size());
        _beta_CE[_qp][lm].resize(_N.size());
        _beta_GC[_qp][lm].resize(_N.size());
        _beta_TI[_qp][lm].resize(_N.size());
        _beta_TS[_qp][lm].resize(_N.size());
        _beta_VW[_qp][lm].resize(_N.size());
        _alpha_Br[_qp][lm].resize(_N.size());
        _alpha_GC[_qp][lm].resize(_N.size());
    }
    
}

//Compute properties
void CollisionParameters::computeQpProperties()
{
    //Initialize Space
    if (_diffusion[_qp].size() < _N.size())
        this->initQpStatefulProperties();
	
	//Simple inline calculations
    _va = sqrt( 8.0*_kB*_temp[_qp]/3.14159/_ma );
    _AH = 100.0*_kB*_temp[_qp]; //NOTE: May change to more precise calculation later
    calculate_n0();
    
    //Calculation of vector parameters
    calculate_vp();
    calculate_y();
    calculate_omega();
    calculate_avg_charge();
    calculate_std_charge();
    calculate_charge_bounds();
    
    //Calculation of the material properties
    calculate_diffusion();
    calculate_dispersion();
    calculate_beta_Br();
    calculate_beta_CE();
    calculate_beta_GC();
    calculate_beta_TI();
    calculate_beta_TS();
    calculate_beta_VW();
    calculate_alpha_Br();
    calculate_alpha_GC();
}



// ------------------ Functions below are where the bulk of the calculations are performed ------------------


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
    	_y[l] = _e0*_user_object.return_activity(l)/1.0E18/_ec/_m_neg/_n0;
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

/// Calculation of std charge parameter
void CollisionParameters::calculate_std_charge()
{
    for (unsigned int l = 0; l<_size_bins; l++)
    {
    	_std_charge[l] = sqrt( _y[l] + (1.0/(2.0*_omega[l])) );
    }
}

/// Calculation of charge boundaries for the average charge parameter
void CollisionParameters::calculate_charge_bounds()
{
    for (unsigned int l = 0; l<_size_bins; l++)
    {
    	_charge_lb[l] = _avg_charge[l] - 2.0*_std_charge[l];
        _charge_ub[l] = _avg_charge[l] + 2.0*_std_charge[l];
    }
}

/// Calculation of normal distribution of charge
Real CollisionParameters::charge_dist(Real charge, int l)
{
	Real value = 0.0;
    
    //Sum up all number concentrations associated with size bin l
    Real sum = 0.0;
    int start = l*_nuc_bins;
    int end = start+_nuc_bins;
    for (int i=start; i<end; i++)
    {
        sum += (*_N[i])[_qp];
    }
    
    //Estimate normalized charge distribution for given charge value and size class l
    value = exp( -(charge - _avg_charge[l])*(charge - _avg_charge[l])/(2.0*_std_charge[l]*_std_charge[l]) ) / ( _std_charge[l]*sqrt(2.0*3.14159) );
    
    return value*sum;
}

/// Helper function for calculation of interium alpha function for collision efficiency
Real CollisionParameters::alpha_int(Real charge_l, Real charge_q, int l, int q)
{
    Real Y = charge_l*charge_q*_ec*_ec/(4.0*3.14159*_e0*_kB*_temp[_qp]*(_rad[l]+_rad[q]));
    if (Y == 0.0)
    	return 1.0;
    else
    	return Y/(exp(Y)-1.0);
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
        _tau[l] = 2.0*G*_user_object.return_debris_density()*_rad[l]*_rad[l]/9.0/_air_visc[_qp];
    }
}

/// Calculation of particle disperision (molecular diffusion + eddy diffusion)
void CollisionParameters::calculate_dispersion()
{
    Real ux = fabs(_wx[_qp]);
    Real uy = fabs(_wy[_qp]);
    Real uz = fabs(_wz[_qp]);
    Real u_mag = sqrt(pow(ux, 2.0) + pow(uy, 2.0) + pow(uz, 2.0));
    
    for (unsigned int lm = 0; lm<_N.size(); ++lm)
    {
        int l = (int)lm/_nuc_bins;
        Real kin = _air_visc[_qp]/_air_dens[_qp];
        Real y = _rad[l]*u_mag/kin;
        
        //Estimate eddy diffusion
        if (y <= 0.0)
    		_eddy_diff[_qp][lm] = 0.0;
        else
        {
        	Real coeff = (0.005*y*y)/(1.0+0.002923*pow(y,2.128));
            Real vy = u_mag*u_mag*coeff*coeff;
            
            Real vt = 0.01;
            if (y > 0.0 && y <= 4.3)
            {
                vt = kin*(7.669E-4*pow(y,3.0));
            }
            else if (y > 4.3 && y <= 12.5)
            {
                vt = kin*(1.0E-3*pow(y,2.8214));
            }
            else if (y > 12.5 && y <= 30.0)
            {
                vt = kin*(1.07E-2*pow(y,1.8895));
            }
            else
            {
                vt = kin*(0.1*pow(y,1.23));
            }
            
            Real tau_l = vt/vy;
            _eddy_diff[_qp][lm] = vt/(1.0+(_tau[l]/tau_l));
        }
        
        //Estimate overall dispersion
        _dispersion[_qp][lm] = _eddy_diff[_qp][lm] + _diffusion[_qp][lm];
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
            
            _beta_Br[_qp][lm][qr] = top/bot*1.0E18;
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

/// Calculation of the Stokes number for Gravitational efficiency
Real CollisionParameters::Stokes(int lm, int qr)
{
    int q = (int)qr/_nuc_bins;
    int l = (int)lm/_nuc_bins;
    
    if (_rad[q] >= _rad[l])
    {
    	Real ux = fabs((*_vx[lm])[_qp] - _wx[_qp]);
    	Real uy = fabs((*_vy[lm])[_qp] - _wy[_qp]);
    	Real uz = fabs((*_vz[lm])[_qp] - _wz[_qp]);
    	Real u_mag = sqrt(pow(ux, 2.0) + pow(uy, 2.0) + pow(uz, 2.0));
    
    	return u_mag*RelVel(qr,lm)/_rad[q]/9.8;
    }
    else
    {
        Real ux = fabs((*_vx[qr])[_qp] - _wx[_qp]);
        Real uy = fabs((*_vy[qr])[_qp] - _wy[_qp]);
        Real uz = fabs((*_vz[qr])[_qp] - _wz[_qp]);
        Real u_mag = sqrt(pow(ux, 2.0) + pow(uy, 2.0) + pow(uz, 2.0));
        
        return u_mag*RelVel(lm,qr)/_rad[l]/9.8;
    }
}

/// Calculation of Convective frequency
void CollisionParameters::calculate_beta_CE()
{
    for (unsigned int lm = 0; lm<_N.size(); ++lm)
    {
    	int l = (int)lm/_nuc_bins;
        
        for (unsigned int qr = 0; qr<_N.size(); ++qr)
        {
        	int q = (int)qr/_nuc_bins;
            
            Real Re = 0.0;
            Real Sc = 0.0;
            if (_rad[q] >= _rad[l])
            {
            	Re = Reynolds(qr);
                Sc = Schmidt(lm);
            }
            else
            {
            	Re = Reynolds(lm);
                Sc = Schmidt(qr);
            }
            
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
            _beta_GC[_qp][lm][qr] = 3.14159*(_rad[l]+_rad[q])*(_rad[l]+_rad[q])*vel*1.0E18;
        }
    }
}

/// Calculation of Inertial frequency
void CollisionParameters::calculate_beta_TI()
{
    for (unsigned int lm = 0; lm<_N.size(); ++lm)
    {
        int l = (int)lm/_nuc_bins;
        for (unsigned int qr = 0; qr<_N.size(); ++qr)
        {
            int q = (int)qr/_nuc_bins;
            Real vel = RelVel(lm,qr);
            _beta_TI[_qp][lm][qr] = (pow(_air_dens[_qp],0.25)*pow(_ed,0.75)/9.8/pow(_air_visc[_qp],0.25))*3.14159*(_rad[l]+_rad[q])*(_rad[l]+_rad[q])*vel*1.0E18;
        }
    }
}

/// Calculation of Shear frequency
void CollisionParameters::calculate_beta_TS()
{
    for (unsigned int lm = 0; lm<_N.size(); ++lm)
    {
        int l = (int)lm/_nuc_bins;
        for (unsigned int qr = 0; qr<_N.size(); ++qr)
        {
            int q = (int)qr/_nuc_bins;
            _beta_TS[_qp][lm][qr] = sqrt(8.0*3.14159*_air_dens[_qp]*_ed/15.0/_air_visc[_qp])*(_rad[l]+_rad[q])*(_rad[l]+_rad[q])*(_rad[l]+_rad[q])*1.0E18;
        }
    }
}

// -------------- BE AWARE: Estimates for van der Waals interactions are very rough due to numerical integration --------------

/// f Helper function for van der Waals frequency
Real CollisionParameters::f_rad(Real r, int l, int q)
{
	Real t1, t2, t3;
    t1 = (2.0*_rad[l]*_rad[q]*1.0E+6*1.0E+6)/(r*r-(_rad[l]+_rad[q])*1.0E+6*(_rad[l]+_rad[q])*1.0E+6);
    t2 = (2.0*_rad[l]*_rad[q]*1.0E+6)/(r*r-(_rad[l]-_rad[q])*1.0E+6*(_rad[l]-_rad[q])*1.0E+6);
    t3 = log((r*r-(_rad[l]+_rad[q])*1.0E+6*(_rad[l]+_rad[q])*1.0E+6)/(r*r-(_rad[l]-_rad[q])*1.0E+6*(_rad[l]-_rad[q])*1.0E+6));
    return -_AH/6.0*(t1+t2+t3);
}

/// g Helper function for van der Waals frequency
Real CollisionParameters::g_rad(Real r, int l, int q)
{
	Real t1, t2;
    t1 = (2.6*_rad[l]*_rad[q]*1.0E+6*1.0E+6)/((_rad[l]+_rad[q])*1.0E+6*(_rad[l]+_rad[q])*1.0E+6);
    t2 = (_rad[l]*_rad[q]*1.0E+6*1.0E+6)/((_rad[l]+_rad[q])*1.0E+6*(r-_rad[l]-_rad[q])*1.0E+6);
    return 1.0+t1*sqrt(t2)+t2;
}

/// Integration helper function
Real CollisionParameters::trap_rule(Real f_xp1, Real f_x, Real dx)
{
    return dx*(f_xp1+f_x)/2.0;
}

/// Wk Helpter function for van der Waals frequency
Real CollisionParameters::Wk_integral(Real lb, Real eps, int l, int q)
{
    Real value = 0.0;
    Real pre_int = -1.0/(2.0*(_rad[l]+_rad[q])*1.0E+6*(_rad[l]+_rad[q])*1.0E+6*_kB*_temp[_qp]);
    
    Real r = lb+eps;
    Real dr = 0.1;
    Real new_add;
    Real sum = 0.0;
    int step = 0;
    
    do
    {
        Real f_r;
        Real f_rdr;
        Real f_rmr;
        Real der;
        Real der2;
        
        f_r = f_rad(r, l, q);
        f_rdr = f_rad(r+dr, l, q);
        f_rmr = f_rad(r+0.5*dr, l, q);
        der = (f_rdr-f_r)/dr;
        der2 = (f_rdr-2.0*f_rmr+f_r)/dr/dr*4.0;
        
        Real F_x = (der + r*der2)*exp(-(0.5*r*der+f_r)/(_kB*_temp[_qp]))*r*r;
        
        r = r+dr;
        f_r = f_rad(r, l, q);
        f_rdr = f_rad(r+dr, l, q);
        f_rmr = f_rad(r-dr, l, q);
        der = (f_rdr-f_r)/dr;
        der2 = (f_rdr-2.0*f_r+f_rmr)/dr/dr;
        
        Real F_xp1 = (der + r*der2)*exp(-(0.5*r*der+f_r)/(_kB*_temp[_qp]))*r*r;
        
        new_add = trap_rule(F_xp1, F_x, dr);
        
        sum = sum + new_add;
        step++;
    } while (fabs(new_add) > eps && step < 20);
    
    value = pre_int*sum;
    
    if (isnan(value) || isinf(value))
    	value = 1.0;
    
    return value;
}

/// Wc Helpter function for van der Waals frequency
Real CollisionParameters::Wc_integral(Real lb, Real eps, int l, int q)
{
    Real value = 0.0;
    Real pre_int = (_rad[l]+_rad[q])*1.0E+6;
    
    Real r = lb+eps;
    Real dr = 0.1;
    Real new_add;
    Real sum = 0.0;
    int step = 0;
    
    do
    {
        Real f_r = f_rad(r, l, q);
        Real g_r = g_rad(r, l, q);
        
        Real F_x = g_r*exp(f_r/(_kB*_temp[_qp]))/(r*r);
        
        r = r+dr;
        f_r = f_rad(r, l, q);
        g_r = g_rad(r, l, q);
        
        Real F_xp1 = g_r*exp(f_r/(_kB*_temp[_qp]))/(r*r);
        
        new_add = trap_rule(F_xp1, F_x, dr);
        
        sum = sum + new_add;
        step++;
    } while (new_add > eps && step < 20);
    
    value = 1.0/(pre_int*sum);
    
    if (isnan(value) || isinf(value))
        value = 0.0;
    
    return value;
}

/// Calculation of van der Waals frequency
void CollisionParameters::calculate_beta_VW()
{
    for (unsigned int lm = 0; lm<_N.size(); ++lm)
    {
        int l = (int)lm/_nuc_bins;
        for (unsigned int qr = 0; qr<_N.size(); ++qr)
        {
            int q = (int)qr/_nuc_bins;
            Real Wk = Wk_integral((_rad[l]+_rad[q])*1.0E+6, 1.0E-6, l, q);
            Real Wc = Wc_integral((_rad[l]+_rad[q])*1.0E+6, 1.0E-6, l, q);
            Real rat = Wc/Wk;
            if (isnan(rat))
            	rat = Wc/(Wk+1.0E-6);
            Real top = 1.0 + ( (4*(_diffusion[_qp][lm]+_diffusion[_qp][qr]))/((_rad[l]+_rad[q])*sqrt(_vp[l]*_vp[l]+_vp[q]*_vp[q])) );
            top = top*Wc;
            Real bot = 1.0+(rat)*( (4*(_diffusion[_qp][lm]+_diffusion[_qp][qr]))/((_rad[l]+_rad[q])*sqrt(_vp[l]*_vp[l]+_vp[q]*_vp[q])) );
            _beta_VW[_qp][lm][qr] = _beta_Br[_qp][lm][qr]*((top/bot)-1.0);
        }
    }
}


/// Calculation of Brownian efficiency
void CollisionParameters::calculate_alpha_Br()
{
    for (unsigned int lm = 0; lm<_N.size(); ++lm)
    {
        int l = (int)lm/_nuc_bins;
        for (unsigned int qr = 0; qr<_N.size(); ++qr)
        {
            int q = (int)qr/_nuc_bins;
            
            //Temp variables
            Real top_sum = 0.0;
            Real bot_sum = 0.0;
            
            //Sum over charges for l (n_l)
            Real n_l = _charge_lb[l];
            Real dn_l = (_charge_ub[l] - _charge_lb[l])/10.0;
            for (int nl_i=0; nl_i<11; nl_i++)
            {
                //Sum over charges for q (n_q)
                Real n_q = _charge_lb[q];
                Real dn_q = (_charge_ub[q] - _charge_lb[q])/10.0;
                for (int nq_i=0; nq_i<11; nq_i++)
                {
                    Real alpha = alpha_int(n_l, n_q, l, q);
                    top_sum += charge_dist(n_l, l)*charge_dist(n_q, q)*(alpha - 1.0);
                    bot_sum += charge_dist(n_l, l)*charge_dist(n_q, q);
                    
                    n_q += dn_q;
                }//End q sum
                
                n_l += dn_l;
            }//End l sum
            
            //Compute average alpha
            _alpha_Br[_qp][lm][qr] = 1.0 + (top_sum/bot_sum);
            
        }
    }
}

/// Calculation of Gravitational efficiency
void CollisionParameters::calculate_alpha_GC()
{
    for (unsigned int lm = 0; lm<_N.size(); ++lm)
    {
    	int l = (int)lm/_nuc_bins;
        for (unsigned int qr = 0; qr<_N.size(); ++qr)
        {
        	int q = (int)qr/_nuc_bins;
        	Real Re;
            if (_rad[q] >= _rad[l])
            	Re = Reynolds(qr);
            else
            	Re = Reynolds(lm);
            Real St = Stokes(lm,qr);
            Real EA = (St*St)/((St+0.5)*(St+0.5));
            Real EV = 0.0;
            
            if (St > 1.214)
            	EV = 1.0/( (1.0 + (0.75*log(2.0*St))/(St-1.214))*(1.0 + (0.75*log(2.0*St))/(St-1.214)) );
            else
            	EV = 0.0;
            
            _alpha_GC[_qp][lm][qr] = (60.0*EV + EA*Re)/(60.0+Re);
        }
    }
}


