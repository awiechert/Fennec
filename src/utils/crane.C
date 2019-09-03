/*!
 *  \file crane.h
 *	\brief Cloud Rise After Nuclear Explosion
 *  \author Austin Ladshaw
 *	\date 05/30/2018
 *	\copyright This software was designed and built at the Georgia Institute
 *             of Technology by Austin Ladshaw for Post-Doc research in the area
 *             of radioactive particle aggregation and transport. Copyright (c) 2018,
 *             all rights reserved.
 */

#include "crane.h"

/*
 *								Start: Crane Class Definitions
 *	-------------------------------------------------------------------------------------
 */

//Default constructor
Crane::Crane()
{
    eps = 18.0/29.0;
    grav = 9.8;
    k = 0.0;
    k2 = 0.075;
    k3 = 0.175;
    k6 = 1.0;
    mu = 0.12;
    k_temp = 1.0;
    apparent_temp = 298.0;
    apparent_amb_temp = 298.0;
    q_x = 1.0;
    q_xe = 1.0;
    beta_prime = 1.0;
    xe = 0.0;
    char_vel = 0.0;
    vert_rad = 0.0;
    horz_rad = 0.0;
    virtual_mass = 0.0;
    gas_const = 287.0;
    latent_heat = 2.5e6;
    sigma_turbulence = 0.0;
    mean_spec_heat = 1005.0;
    actual_spec_heat = 1005.0;
    spec_heat_water = 2108.0;
    spec_heat_conds = 1480.0;
    spec_heat_entrain = 1005.0;
    spec_heat_entrain_integral = 0.0;
    cloud_volume = 0.0;
    equil_temp = 1000.0;
    total_mass_fallout_rate = 0.0;
    surf_area = 0.0;
    shear_ratio = 0.0;
    shear_vel = 0.0;
    part_density = 2600.0;
    adjusted_height = 0.0;
    bomb_yield = 0.0;
    force_factor = 0.0;
    det_alt = 0.0;
    burst_height = 0.0;
    ground_alt = 0.0;
    energy_frac = 0.9999;
    eccentricity = 0.75;
    air_density = 1.225;
    air_viscosity = 1.81e-5;
    slip_factor = 1.0;
    davies_num = 1.0;
    vapor_pressure = 0.0;
    sat_vapor_pressure = 1.0;
    solidification_temp = 1673.0;
    vaporization_temp = 2500.0;
    initial_soil_mass = 0.0;
    initial_soil_vapor = 0.0;
    initial_water_mass = 0.0;
    initial_air_mass = 0.0;
    current_amb_temp = 298.0;
    current_atm_press = 101325.0;
    includeShearVel = false;
    isSaturated = false;
    isSolidified = false;
    ConsoleOut = true;
    FileOut = false;
    isTight = true;
    useCustomDist = false;
    saturation_time = 0.0;
    solidification_time = 0.0;
    stabilization_time = 0.0;
    min_dia = 0.001;
    max_dia = 100.0;
    mean_dia = 0.407;
    std_dia = 4.0;
    num_bins = 22;
    cloud_mass = 0.0;
    entrained_mass = 0.0;
    cloud_rise = 0.0;
    cloud_alt = 0.0;
    x_water_vapor = 0.0;
    w_water_conds = 0.0;
    s_soil = 0.0;
    temperature = 298;
    energy = 0.0;
    current_time = 0.0;
    cloud_density = 0.0;
    horz_rad_change = 0.0;
    energy_switch = 0.0;
    t_count = 0.0;
    t_cloud_count = 0.0;
    
    alt_top = 0.0;
    alt_bottom = 0.0;
    alt_top_old = 0.0;
    alt_bottom_old = 0.0;
    rise_top = 0.0;
    rise_bottom = 0.0;
    t_cloud_out = 0.0;
    
    create_default_atmosphere();
    create_default_wind_profile();
    create_default_soil_components();
}

//Default destructor
Crane::~Crane()
{
    delete_atmosphere();
    delete_particles();
    delete_wind_profile();
    delete_soil_components();
}

// Below are some display functions used for testing different functions
void Crane::display_part_hist()
{
    std::cout << "Normalized Particle Distribution by Size\n";
    std::cout << "----------------------------------------\n";
    std::cout << "Size (um)\tNormalDist\n";
    //Iterate through map
    for (std::map<double,double>::iterator it=this->part_hist.begin(); it!=this->part_hist.end(); ++it)
    {
        std::cout << it->first << "   \t" << it->second << std::endl;
    }
    std::cout << "\n";
}

void Crane::display_part_conc()
{
    std::cout << "\nCloud Volume (m^3) =\t" << this->get_cloud_volume() << std::endl;
    std::cout << "Soil Mass (kg) =\t" << this->get_initial_soil_mass() << std::endl;
    std::cout << "Particle Concentration Distribution by Size\n";
    std::cout << "----------------------------------------\n";
    std::cout << "Size (um)\tConcDist (Gp/m^3)\n";
    //Iterate through map
    for (std::map<double,double>::iterator it=this->part_conc.begin(); it!=this->part_conc.end(); ++it)
    {
        std::cout << it->first << "   \t" << it->second << std::endl;
    }
    std::cout << "\n";
}

void Crane::display_soil_characteristics()
{
    std::cout << "Approximate Soil Components (by molefraction)\n";
    std::cout << "---------------------------------------------\n";
    std::cout << "Comp\t    Molefrac\n";
    //Iterate through map
    for (std::map<std::string, double>::iterator it=this->soil_molefrac.begin(); it!=this->soil_molefrac.end(); ++it)
    {
        std::cout << it->first << "      \t" << it->second << std::endl;
    }
    std::cout << "\n";
}

///< Below are the set functions for various parameters
void Crane::set_eps(double val)
{
    this->eps = val;
}

void Crane::set_grav(double val)
{
    this->grav = val;
}

void Crane::set_k(double val)
{
    this->k = val;
}

void Crane::set_k2(double val)
{
    this->k2 = val;
}

void Crane::set_k3(double val)
{
    this->k3 = val;
}

void Crane::set_k6(double val)
{
    this->k6 = val;
}

void Crane::set_mu(double val)
{
    this->mu = val;
}

void Crane::set_k_temp(double val)
{
    this->k_temp = val;
}

void Crane::set_apparent_temp(double val)
{
    this->apparent_temp = val;
}

void Crane::set_apparent_amb_temp(double val)
{
    this->apparent_amb_temp = val;
}

void Crane::set_q_x(double val)
{
    this->q_x = val;
}

void Crane::set_q_xe(double val)
{
    this->q_xe = val;
}

void Crane::set_beta_prime(double val)
{
    this->beta_prime = val;
}

void Crane::set_xe(double val)
{
    this->xe = val;
}

void Crane::set_char_vel(double val)
{
    this->char_vel = val;
}

void Crane::set_vert_rad(double val)
{
    this->vert_rad = val;
}

void Crane::set_horz_rad(double val)
{
    this->horz_rad = val;
}

void Crane::set_virtual_mass(double val)
{
    this->virtual_mass = val;
}

void Crane::set_gas_const(double val)
{
    this->gas_const = val;
}

void Crane::set_latent_heat(double val)
{
    this->latent_heat = val;
}

void Crane::set_sigma_turbulence(double val)
{
    this->sigma_turbulence = val;
}

void Crane::set_mean_spec_heat(double val)
{
    this->mean_spec_heat = val;
}

void Crane::set_actual_spec_heat(double val)
{
    this->actual_spec_heat = val;
}

void Crane::set_spec_heat_water(double val)
{
    this->spec_heat_water = val;
}

void Crane::set_spec_heat_entrain(double val)
{
    this->spec_heat_entrain = val;
}

void Crane::set_spec_heat_entrain_integral(double val)
{
    this->spec_heat_entrain_integral = val;
}

void Crane::set_spec_heat_conds(double val)
{
    this->spec_heat_conds = val;
}

void Crane::set_cloud_volume(double val)
{
    this->cloud_volume = val;
}

void Crane::set_equil_temp(double val)
{
    this->equil_temp = val;
}

void Crane::set_total_mass_fallout_rate(double val)
{
    this->total_mass_fallout_rate = val;
}

void Crane::set_surf_area(double val)
{
    this->surf_area = val;
}

void Crane::set_shear_ratio(double val)
{
    this->shear_ratio = val;
}

void Crane::set_shear_vel(double val)
{
    this->shear_vel = val;
}

void Crane::set_part_density(double val)
{
    this->part_density = val;
}

void Crane::set_adjusted_height(double val)
{
    this->adjusted_height = val;
}

void Crane::set_bomb_yield(double val)
{
    this->bomb_yield = val;
}

void Crane::set_force_factor(double val)
{
    this->force_factor = val;
}

void Crane::set_det_alt(double val)
{
    this->det_alt = val;
}

void Crane::set_burst_height(double val)
{
    this->burst_height = val;
}

void Crane::set_ground_alt(double val)
{
    this->ground_alt = val;
}

void Crane::set_energy_frac(double val)
{
    this->energy_frac = val;
}

void Crane::set_eccentricity(double val)
{
    this->eccentricity = val;
}

void Crane::set_air_density(double val)
{
    this->air_density = val;
}

void Crane::set_air_viscosity(double val)
{
    this->air_viscosity = val;
}

void Crane::set_slip_factor(double val)
{
    this->slip_factor = val;
}

void Crane::set_davies_num(double val)
{
    this->davies_num = val;
}

void Crane::set_min_dia(double val)
{
    this->min_dia = val;
}

void Crane::set_max_dia(double val)
{
    this->max_dia = val;
}

void Crane::set_mean_dia(double val)
{
    this->mean_dia = val;
}

void Crane::set_std_dia(double val)
{
    this->std_dia = val;
}

void Crane::set_num_bins(int val)
{
    this->num_bins = val;
}

void Crane::set_cloud_mass(double val)
{
    this->cloud_mass = val;
}

void Crane::set_entrained_mass(double val)
{
    this->entrained_mass = val;
}

void Crane::set_cloud_rise(double val)
{
    this->cloud_rise = val;
}

void Crane::set_cloud_alt(double val)
{
    this->cloud_alt = val;
}

void Crane::set_x_water_vapor(double val)
{
    this->x_water_vapor = val;
}

void Crane::set_w_water_conds(double val)
{
    this->w_water_conds = val;
}

void Crane::set_s_soil(double val)
{
    this->s_soil = val;
}

void Crane::set_temperature(double val)
{
    this->temperature = val;
}

void Crane::set_energy(double val)
{
    this->energy = val;
}

void Crane::set_current_time(double val)
{
    this->current_time = val;
}

void Crane::set_vapor_pressure(double val)
{
    this->vapor_pressure = val;
}

void Crane::set_sat_vapor_pressure(double val)
{
    this->sat_vapor_pressure = val;
}

void Crane::set_solidification_temp(double val)
{
    this->solidification_temp = val;
}

void Crane::set_vaporization_temp(double val)
{
    this->vaporization_temp = val;
}

void Crane::set_initial_soil_mass(double val)
{
    this->initial_soil_mass = val;
}

void Crane::set_initial_soil_vapor(double val)
{
    this->initial_soil_vapor = val;
}

void Crane::set_initial_water_mass(double val)
{
    this->initial_water_mass = val;
}

void Crane::set_initial_air_mass(double val)
{
    this->initial_air_mass = val;
}

void Crane::set_current_amb_temp(double val)
{
    this->current_amb_temp = val;
}

void Crane::set_current_atm_press(double val)
{
    this->current_atm_press = val;
}

void Crane::set_includeShearVel(bool val)
{
    this->includeShearVel = val;
}

void Crane::set_isSaturated(bool val)
{
    this->isSaturated = val;
}

void Crane::set_isSolidified(bool val)
{
    this->isSolidified = val;
}

void Crane::set_ConsoleOut(bool val)
{
    this->ConsoleOut = val;
}

void Crane::set_FileOut(bool val)
{
    this->FileOut = val;
}

void Crane::set_saturation_time(double val)
{
    this->saturation_time = val;
}

void Crane::set_solidification_time(double val)
{
    this->solidification_time = val;
}

void Crane::set_stabilization_time(double val)
{
    this->stabilization_time = val;
}

void Crane::set_isTight(bool val)
{
    this->isTight = val;
}

void Crane::set_useCustomDist(bool val)
{
    this->useCustomDist = val;
}

void Crane::set_cloud_density(double val)
{
    this->cloud_density = val;
}

void Crane::set_horz_rad_change(double val)
{
    this->horz_rad_change = val;
}

void Crane::set_energy_switch(double val)
{
    this->energy_switch = val;
}

void Crane::set_alt_top(double val)
{
    this->alt_top = val;
}

void Crane::set_alt_bottom(double val)
{
    this->alt_bottom = val;
}

void Crane::set_alt_top_old(double val)
{
    this->alt_top_old = val;
}

void Crane::set_alt_bottom_old(double val)
{
    this->alt_bottom_old = val;
}

void Crane::set_rise_top(double val)
{
    this->rise_top = val;
}

void Crane::set_rise_bottom(double val)
{
    this->rise_bottom = val;
}

void Crane::set_CloudFile(FILE *file)
{
    this->CloudFile = file;
}

///< Below are the get functions for various parameters

double Crane::get_eps()
{
    return this->eps;
}

double Crane::get_grav()
{
    return this->grav;
}

double Crane::get_k()
{
    return this->k;
}

double Crane::get_k2()
{
    return this->k2;
}

double Crane::get_k3()
{
    return this->k3;
}

double Crane::get_k6()
{
    return this->k6;
}

double Crane::get_mu()
{
    return this->mu;
}

double Crane::get_k_temp()
{
    return this->k_temp;
}

double Crane::get_apparent_temp()
{
    return this->apparent_temp;
}

double Crane::get_apparent_amb_temp()
{
    return this->apparent_amb_temp;
}

double Crane::get_q_x()
{
    return this->q_x;
}

double Crane::get_q_xe()
{
    return this->q_xe;
}

double Crane::get_beta_prime()
{
    return this->beta_prime;
}

double Crane::get_xe()
{
    return this->xe;
}

double Crane::get_char_vel()
{
    return this->char_vel;
}

double Crane::get_vert_rad()
{
    return this->vert_rad;
}

double Crane::get_horz_rad()
{
    return this->horz_rad;
}

double Crane::get_virtual_mass()
{
    return this->virtual_mass;
}

double Crane::get_gas_const()
{
    return this->gas_const;
}

double Crane::get_latent_heat()
{
    return this->latent_heat;
}

double Crane::get_sigma_turbulence()
{
    return this->sigma_turbulence;
}

double Crane::get_mean_spec_heat()
{
    return this->mean_spec_heat;
}

double Crane::get_actual_spec_heat()
{
    return this->actual_spec_heat;
}

double Crane::get_spec_heat_water()
{
    return this->spec_heat_water;
}

double Crane::get_spec_heat_entrain()
{
    return this->spec_heat_entrain;
}

double Crane::get_spec_heat_entrain_integral()
{
    return this->spec_heat_entrain_integral;
}

double Crane::get_spec_heat_conds()
{
    return this->spec_heat_conds;
}

double Crane::get_cloud_volume()
{
    return this->cloud_volume;
}

double Crane::get_equil_temp()
{
    return this->equil_temp;
}

double Crane::get_total_mass_fallout_rate()
{
    return this->total_mass_fallout_rate;
}

double Crane::get_surf_area()
{
    return this->surf_area;
}

double Crane::get_shear_ratio()
{
    return this->shear_ratio;
}

double Crane::get_shear_vel()
{
    return this->shear_vel;
}

double Crane::get_part_density()
{
    return this->part_density;
}

double Crane::get_adjusted_height()
{
    return this->adjusted_height;
}

double Crane::get_bomb_yield()
{
    return this->bomb_yield;
}

double Crane::get_force_factor()
{
    return this->force_factor;
}

double Crane::get_det_alt()
{
    return this->det_alt;
}

double Crane::get_burst_height()
{
    return this->burst_height;
}

double Crane::get_ground_alt()
{
    return this->ground_alt;
}

double Crane::get_energy_frac()
{
    return this->energy_frac;
}

double Crane::get_eccentricity()
{
    return this->eccentricity;
}

double Crane::get_air_density()
{
    return this->air_density;
}

double Crane::get_air_viscosity()
{
    return this->air_viscosity;
}

double Crane::get_slip_factor()
{
    return this->slip_factor;
}

double Crane::get_davies_num()
{
    return this->davies_num;
}

double Crane::get_min_dia()
{
    return this->min_dia;
}

double Crane::get_max_dia()
{
    return this->max_dia;
}

double Crane::get_mean_dia()
{
    return this->mean_dia;
}

double Crane::get_std_dia()
{
    return this->std_dia;
}

int Crane::get_num_bins()
{
    return this->num_bins;
}

double Crane::get_cloud_mass()
{
    return this->cloud_mass;
}

double Crane::get_entrained_mass()
{
    return this->entrained_mass;
}

double Crane::get_cloud_rise()
{
    return this->cloud_rise;
}

double Crane::get_cloud_alt()
{
    return this->cloud_alt;
}

double Crane::get_x_water_vapor()
{
    return this->x_water_vapor;
}

double Crane::get_w_water_conds()
{
    return this->w_water_conds;
}

double Crane::get_s_soil()
{
    return this->s_soil;
}

double Crane::get_temperature()
{
    return this->temperature;
}

double Crane::get_energy()
{
    return this->energy;
}

double Crane::get_current_time()
{
    return this->current_time;
}

double Crane::get_vapor_pressure()
{
    return this->vapor_pressure;
}

double Crane::get_sat_vapor_pressure()
{
    return this->sat_vapor_pressure;
}

double Crane::get_solidification_temp()
{
    return this->solidification_temp;
}

double Crane::get_vaporization_temp()
{
    return this->vaporization_temp;
}

double Crane::get_initial_soil_mass()
{
    return this->initial_soil_mass;
}

double Crane::get_initial_soil_vapor()
{
    return this->initial_soil_vapor;
}

double Crane::get_initial_water_mass()
{
    return this->initial_water_mass;
}

double Crane::get_initial_air_mass()
{
    return this->initial_air_mass;
}

double Crane::get_current_amb_temp()
{
    return this->current_amb_temp;
}

double Crane::get_current_atm_press()
{
    return this->current_atm_press;
}

bool Crane::get_includeShearVel()
{
    return this->includeShearVel;
}

bool Crane::get_isSaturated()
{
    return this->isSaturated;
}

bool Crane::get_isSolidified()
{
    return this->isSolidified;
}

double Crane::get_part_size(int i)
{
    if (i < 0 || i >= this->part_size.size())
        return 0.0;
    
    return this->part_size[i];
}

double Crane::get_settling_rate(double Dj)
{
    return this->settling_rate[Dj];
}

double Crane::get_settling_rate_old(double Dj)
{
    return this->settling_rate_old[Dj];
}

bool Crane::get_ConsoleOut()
{
    return this->ConsoleOut;
}

bool Crane::get_FileOut()
{
    return this->FileOut;
}

Matrix<double> & Crane::get_part_conc_var()
{
    return this->part_conc_var;
}

double Crane::get_saturation_time()
{
    return this->saturation_time;
}

double Crane::get_solidification_time()
{
    return this->solidification_time;
}

double Crane::get_stabilization_time()
{
    return this->stabilization_time;
}

bool Crane::get_isTight()
{
    return this->isTight;
}

bool Crane::get_useCustomDist()
{
    return this->useCustomDist;
}

double Crane::get_cloud_density()
{
    return this->cloud_density;
}

double Crane::get_horz_rad_change()
{
    return this->horz_rad_change;
}

double Crane::get_energy_switch()
{
    return this->energy_switch;
}

double Crane::get_alt_top()
{
    return this->alt_top;
}

double Crane::get_alt_bottom()
{
    return this->alt_bottom;
}

double Crane::get_alt_top_old()
{
    return this->alt_top_old;
}

double Crane::get_alt_bottom_old()
{
    return this->alt_bottom_old;
}

double Crane::get_rise_top()
{
    return this->rise_top;
}

double Crane::get_rise_bottom()
{
    return this->rise_bottom;
}

std::map<double, double> & Crane::get_part_conc()
{
    return this->part_conc;
}

std::map<double, double> & Crane::get_part_hist()
{
    return this->part_hist;
}

std::map<std::string, double> & Crane::get_soil_molefrac()
{
    return this->soil_molefrac;
}

std::map<std::string, Molecule> & Crane::get_soil_comp()
{
    return this->soil_comp;
}

std::map<std::string, double> & Crane::get_soil_atom_frac()
{
    return this->soil_atom_frac;
}

std::map<std::string, Atom> & Crane::get_soil_atom()
{
    return this->soil_atom;
}

// Below are listed all the compute function for various parameters
void Crane::compute_beta_prime(double x, double s, double w)
{
    if (x < 0.0)	x = 0.0;
    if (s < 0.0)	s = 0.0;
    if (w < 0.0)	w = 0.0;
    double val = (1.0 + x) / (1.0 + x + s + w);
    this->set_beta_prime(val);
}

void Crane::compute_q_x(double x)
{
    if (x < 0.0)	x = 0.0;
    double val = (1.0 + (x/this->get_eps())) / (1.0 + x);
    this->set_q_x(val);
}

void Crane::compute_q_xe(double xe)
{
    if (xe < 0.0)	xe = 0.0;
    double val = (1.0 + (xe/this->get_eps())) / (1.0 + xe);
    this->set_q_xe(val);
}

void Crane::compute_apparent_temp(double T, double x)
{
    if (T < 0.0)	T = 0.0;
    this->compute_q_x(x);
    this->set_apparent_temp(T*this->get_q_x());
}

void Crane::compute_apparent_amb_temp(double Te, double xe)
{
    if (Te < 0.0)	Te = 0.0;
    this->compute_q_xe(xe);
    this->set_apparent_amb_temp(Te*this->get_q_xe());
}

void Crane::compute_char_vel(double u, double E)
{
    if (E < 0.0)	E = 0.0;
    this->set_char_vel(fmax(fabs(u), sqrt(2.0*E)));
}

void Crane::compute_air_viscosity(double T)
{
    if (T < 0.0)	T = 0.0;
    this->set_air_viscosity( (145.8*pow(10.0, -8.0)*pow(T, (3.0/2.0))) / (110.4 + T) );
}

void Crane::compute_vapor_pressure(double P, double x)
{
    if (x < 0.0)	x = 0.0;
    if (P < 0.0)	P = 0.0;
    this->set_vapor_pressure( (P*x) / (this->get_eps() + x) );
}

void Crane::compute_sat_vapor_pressure(double T)
{
    if (T < 0.0)	T = 0.0;
    T = T - 273.15;
    double Pws = 618.8*exp(17.27*T/(T+237.3));
    this->set_sat_vapor_pressure(Pws);
}

void Crane::compute_xe(double Te, double P, double HR)
{
    if (Te < 0.0)	Te = 0.0;
    if (P < 0.0)	P = 0.0;
    if (HR < 0.0)	HR = 0.0;
    double val = (109.98*HR/29.0/P)*pow(Te/273.0, -5.13)*exp(25.0*(Te-273.0)/Te);
    this->set_xe(val);
}

void Crane::compute_air_density(double P, double x, double T)
{
    if (x < 0.0)	x = 0.0;
    if (P < 0.0)	P = 0.0;
    if (T < 0.0)	T = 0.0;
    this->set_air_density( (P/this->get_gas_const()/T)*(1.0+x)/(1.0+x*1.609) );
}

void Crane::compute_spec_heat_entrain(double T)
{
    if (T < 0.0)	T = 0.0;
    if (T <= 2300.0)
    {
        this->set_spec_heat_entrain(946.6+(0.1971*T));
    }
    else
    {
        this->set_spec_heat_entrain(-3587.5+(2.125*T));
    }
}

void Crane::compute_spec_heat_water(double T)
{
    if (T < 0.0)	T = 0.0;
    this->set_spec_heat_water(1697.66+(1.144174*T));
}

void Crane::compute_spec_heat_conds(double T)
{
    if (T < 0.0)	T = 0.0;
    if (T <= 848.0)
    {
        this->set_spec_heat_conds(781.6+(0.5612*T)-(1.881e7/T/T));
    }
    else
    {
        this->set_spec_heat_conds(1003.8+(0.1351*T));
    }
}

void Crane::compute_actual_spec_heat(double T, double x)
{
    if (x < 0.0)	x = 0.0;
    this->compute_spec_heat_entrain(T);
    this->compute_spec_heat_water(T);
    this->set_actual_spec_heat( (this->get_spec_heat_entrain() + (x*this->get_spec_heat_water())) / (1.0+x) );
}

void Crane::compute_k_temp(double T)
{
    if (T < 0.0)	T = 0.0;
    if (T > this->equil_temp)
    {
        this->set_k_temp(0.0);
    }
    else
    {
        this->set_k_temp(1.0);
    }
}

void Crane::compute_mean_spec_heat(double T, double x, double s, double w)
{
    this->compute_k_temp(T);
    this->compute_beta_prime(x, s, w);
    this->compute_actual_spec_heat(T, x);
    this->compute_spec_heat_conds(T);
    this->set_mean_spec_heat( this->get_beta_prime()*this->get_actual_spec_heat() + (1.0-this->get_beta_prime())*this->get_k_temp()*this->get_spec_heat_conds() );
}

void Crane::compute_cloud_volume(double m, double x, double s, double w, double T, double P)
{
    if (P < 0.0)	P = 0.0;
    if (m < 0.0)	m = 0.0;
    m = m * 1000.0 * 1000.0;	//Conversion from Gg to kg
    this->compute_beta_prime(x, s, w);
    this->compute_apparent_temp(T, x);
    this->set_cloud_volume( m*this->get_beta_prime()*this->get_gas_const()*this->get_apparent_temp()/P );
}

void Crane::compute_cloud_density(double m, double x, double s, double w, double T, double P)
{
    this->compute_cloud_volume(m, x, s, w, T, P);
    if (m < 0.0)	m = 0.0;
    m = m * 1000.0 * 1000.0;	//Conversion from Gg to kg
    this->set_cloud_density( m/this->get_cloud_volume()*this->get_beta_prime() );
}

void Crane::compute_vert_rad(double z)
{
    this->set_vert_rad( this->get_mu()*(z - this->get_adjusted_height()) );
}

void Crane::compute_horz_rad(double m, double x, double s, double w, double T, double P, double z)
{
    this->compute_cloud_volume(m, x, s, w, T, P);
    this->compute_vert_rad(z);
    this->set_horz_rad( sqrt(3.0*this->get_cloud_volume()/4.0/M_PI/this->get_vert_rad()) );
}

void Crane::compute_sigma_turbulence(double E, double z)
{
    if (E < 0.0)	E = 0.0;
    this->compute_vert_rad(z);
    this->set_sigma_turbulence( this->get_k3()*pow(2.0*E, 3.0/2.0)/this->get_vert_rad() );
}

void Crane::compute_surf_area(double m, double x, double s, double w, double T, double P, double z)
{
    this->compute_horz_rad(m, x, s, w, T, P, z);
    this->set_surf_area( 4.0*M_PI*pow(this->get_horz_rad(), 2.0) );
}

void Crane::compute_shear_vel(Matrix<double> v_top, Matrix<double> v_bot)
{
    this->set_shear_vel( (v_top-v_bot).norm() );
}

void Crane::compute_shear_ratio(double m, double x, double s, double w, double T, double P, double z, double u, double E, Matrix<double> v_top, Matrix<double> v_bot)
{
    this->compute_surf_area(m, x, s, w, T, P, z);
    this->compute_cloud_volume(m, x, s, w, T, P);
    this->compute_char_vel(u, E);
    this->compute_shear_vel(v_top, v_bot);
    
    if (this->get_includeShearVel() == true)
    {
        this->set_shear_ratio( this->get_mu()*((this->get_surf_area()*this->get_char_vel()/this->get_cloud_volume())+(this->get_k6()*1.5*this->get_shear_vel()/this->get_horz_rad())) );
    }
    else
    {
        this->set_shear_ratio( this->get_mu()*(this->get_surf_area()*this->get_char_vel()/this->get_cloud_volume()) );
    }
}

void Crane::compute_slip_factor(double Dj, double T, double P)
{
    //NOTE: Dj comes in as um --> convert to m
    if (T < 0.0)	T = 0.0;
    if (P < 0.0)	P = 0.0;
    double dj = Dj/1.0E+6;
    this->compute_air_viscosity(T);
    this->set_slip_factor( 1.0 + (54.088*this->get_air_viscosity()*pow(T, 0.5)/dj/P) );
}

void Crane::compute_davies_num(double Dj, double m, double x, double s, double w, double T, double P)
{
    //NOTE: Dj comes in as um --> convert to m
    double dj = Dj/1.0E+6;
    this->compute_air_density(P, x, T);
    this->compute_cloud_density(m, x, s, w, T, P);
    this->compute_air_viscosity(T);
    this->set_davies_num( (4.0*this->get_air_density()*(this->get_part_density()-this->get_air_density())*this->get_grav()*pow(dj,3.0)) / (3.0*pow(this->get_air_viscosity(),2.0)) );
}

void Crane::compute_settling_rate(double Dj, double m, double x, double s, double w, double T, double P)
{
    //NOTE: Dj comes in as um --> convert to m
    double dj = Dj/1.0E+6;
    this->compute_slip_factor(Dj, T, P);
    this->compute_davies_num(Dj, m, x, s, w, T, P);
    double rho = this->get_air_density();
    
    //If statements for flow conditions
    if (this->get_davies_num() <= 0.3261)
    {
        this->settling_rate[Dj] = this->get_air_viscosity()*this->get_davies_num()*this->get_slip_factor()/24.0/rho/dj;
    }
    else if (this->get_davies_num() <= 84.175)
    {
        double Y = log(this->get_davies_num());
        double a = -3.18657 + (0.992696*Y) - (0.153193E-2*pow(Y,2.0)) - (0.987059E-3*pow(Y,3.0)) - (0.578878E-3*pow(Y,4.0)) + (0.855176E-4*pow(Y,5.0)) - (0.327815E-5*pow(Y,6.0));
        this->settling_rate[Dj] = this->get_air_viscosity()*exp(a)*this->get_slip_factor()/rho/dj;
    }
    else if (this->get_davies_num() < 140.0)
    {
        double poly = 4.1667E-2 - (2.3363E-4*this->get_davies_num()) + (2.0154E-6*this->get_davies_num()*this->get_davies_num()) - (6.9105E-9*this->get_davies_num()*this->get_davies_num()*this->get_davies_num());
        this->settling_rate[Dj] = this->get_air_viscosity()*poly*this->get_slip_factor()*this->get_davies_num()/rho/dj;
    }
    else if (this->get_davies_num() < 4.5E+7)
    {
        double X = log10(this->get_davies_num());
        double poly = -1.29536 + (0.986*X) - (0.046677*X*X) + (1.1235E-3*X*X*X);
        this->settling_rate[Dj] = this->get_air_viscosity()*pow(10.0,poly)/rho/dj;
    }
    else
    {
        double X = log10(this->get_davies_num());
        double poly = -1.29536 + (0.986*X) - (0.046677*X*X) + (1.1235E-3*X*X*X);
        this->settling_rate[Dj] = this->get_air_viscosity()*pow(10.0,poly)/rho/dj;
    }
    
}

void Crane::compute_total_mass_fallout_rate(double m, double x, double s, double w, double T, double P, double z, const Matrix<double> &n)
{
    this->compute_horz_rad(m, x, s, w, T, P, z);
    this->settling_rate.clear();
    double sum = 0.0;
    int i = 0;
    
    //Iterate through part_hist map for summation term (NOTE: first N variables in matrix will correspond to particle concentrations)
    for (std::map<double,double>::iterator it=this->part_hist.begin(); it!=this->part_hist.end(); ++it)
    {
        //NOTE: Dj comes in as um --> convert to m
        double ni = n(i,0);
        if (ni < 0.0)	ni = 0.0;
        double dj = it->first/1.0E+6;
        this->compute_settling_rate(it->first, m, x, s, w, T, P);
        sum += this->settling_rate[it->first]*M_PI*dj*dj*dj*ni*1.0e9/6.0;
        i++;
    }
    sum = sum*M_PI*this->get_horz_rad()*this->get_horz_rad()*this->get_part_density();
    this->set_total_mass_fallout_rate(sum);
}

// Below are listed compute functions specific for initial conditions
void Crane::compute_energy_switch(double W)
{
    this->set_energy_switch(fmax( 10.0, fmin(23.0+9.0*log10(W), 60.0) ));
}

void Crane::compute_k(double W)
{
    this->set_k(595.0*pow(W, -0.0527));
}

void Crane::compute_k2(double W)
{
    this->set_k2( fmax(0.004, fmin(0.1, 0.1*pow(W, -(1.0/3.0)))) );
}

void Crane::compute_mu(double W)
{
    this->set_mu( fmax(fmax(0.12, 0.1*pow(W, 0.1)), 0.01*pow(W, (1.0/3.0)))	);
}

void Crane::compute_force_factor(double W)
{
    this->set_force_factor(0.44*pow(W, 0.014));
}

void Crane::compute_equil_temp(double W)
{
    this->set_equil_temp(200.0*log10(W)+1000.0);
}

void Crane::create_part_hist(double min, double max, int size, double avg, double std)
{
    if (max <= min || max <= 0.0 || min <= 0.0 || size < 1 || avg <= 0.0 || std <= 0.0)
    {
        mError(distribution_impossible);
        return;
    }
    
    this->part_hist.clear();
    this->settling_rate.clear();
    this->part_size.clear();
    this->set_min_dia(min);
    this->set_max_dia(max);
    this->set_num_bins(size);
    this->set_mean_dia(avg);
    this->set_std_dia(std);
    this->part_size.resize(size);
    this->part_conc_var.set_size(size, 1);
    
    double distance = log10(this->get_max_dia()) - log10(this->get_min_dia());
    double logstep = distance / ((double)this->get_num_bins());
    double current_log = log10(this->get_min_dia());
    double sum = 0.0;
    
    //Loop to create initial map
    for (int i=0; i<this->get_num_bins(); i++)
    {
        double next_log = current_log + logstep;
        double Dj = sqrt(pow(10.0,current_log)*pow(10.0,next_log));
        double Nj = ( 1.0 / sqrt(2.0*M_PI) / Dj / log(this->get_std_dia()) ) * exp( -0.5*pow( log(Dj/this->get_mean_dia())/log(this->get_std_dia()) ,2.0) );
        this->part_hist[Dj] = Nj*(pow(10.0,next_log)-pow(10.0,current_log));
        this->settling_rate[Dj] = 0.0;
        this->part_size[i] = Dj;
        sum += Nj*(pow(10.0,next_log)-pow(10.0,current_log));
        current_log += logstep;
    }
    
    //Iterate through map to normalize
    for (std::map<double,double>::iterator it=this->part_hist.begin(); it!=this->part_hist.end(); ++it)
    {
        it->second = it->second/sum;
    }
}

void Crane::compute_det_alt(double gz, double hb)
{
    this->set_ground_alt(gz);
    this->set_burst_height(hb);
    this->set_det_alt(gz+hb);
}

void Crane::compute_initial_cloud_alt(double W, double gz, double hb)
{
    this->compute_det_alt(gz, hb);
    this->set_cloud_alt(this->get_det_alt() + 108.0*pow(W,0.349));
}

void Crane::compute_initial_current_time(double W, double gz, double hb)
{
    this->set_bomb_yield(W);
    this->compute_det_alt(gz, hb);
    double scaled = fabs(hb)*3.281 / pow(W,1.0/3.0);
    double t2m;
    
    if (scaled <= 180.0)
    {
        t2m = 0.037*pow(1.216,scaled/180.0)*pow(W, 0.49 - (0.07*scaled/180.0));
    }
    else
    {
        t2m = 0.045*pow(W, 0.42);
    }
    
    this->set_current_time(56.0*t2m*pow(W, -0.3));
}

void Crane::compute_initial_temperature(double W, double gz, double hb)
{
    this->compute_initial_current_time(W, gz, hb);
    double scaled = fabs(hb)*3.281 / pow(W,1.0/3.0);
    double t2m;
    double K, n;
    
    if (scaled <= 180.0)
    {
        t2m = 0.037*pow(1.216,scaled/180.0)*pow(W, 0.49 - (0.07*scaled/180.0));
        K = 5980.0*pow(1.145, scaled/180.0)*pow(W, -0.0395 + (0.0264*scaled/180.0));
        n = -0.4473*pow(W, 0.0436);
    }
    else
    {
        t2m = 0.045*pow(W, 0.42);
        K = 6847.0*pow(W, -0.0131);
        n = -0.4473*pow(W, 0.0436);
    }
    
    this->set_temperature( K*pow(this->get_current_time()/t2m, n) + 1500.0 );
}

void Crane::compute_initial_soil_mass(double W, double gz, double hb)
{
    this->compute_det_alt(gz, hb);
    double scaled;
    //Check for underground detonation
    if (hb < 0.0)
    {
        scaled = fabs(hb*3.281)/pow(W, 1.0/3.4);
        double Rad = 112.5 + 0.755*scaled - 9.6e-6*scaled*scaled*scaled - 9.11e-12*scaled*scaled*scaled*scaled*scaled;
        double D = 32.7 + 0.851*scaled - 2.52e-5*scaled*scaled*scaled - 1.78e-10*scaled*scaled*scaled*scaled*scaled;
        
        this->set_initial_soil_mass( 2.182*pow(W, 3.0/3.4)*Rad*Rad*D );
    }
    else
    {
        scaled = fabs(hb)*3.281 / pow(W, 1.0/3.4);
        
        if (scaled <= 180.0)
        {
            this->set_initial_soil_mass( 0.07741*pow(W, 3.0/3.4)*pow(180.0-scaled,2.0)*(360.0+scaled) );
        }
        else
        {
            this->set_initial_soil_mass( 90.7 );
        }
    }
    
}

void Crane::compute_initial_part_hist(double W, double gz, double hb, int size)
{
    this->compute_det_alt(gz, hb);
    this->compute_initial_vert_rad(W, gz, hb);
    double scaled = fabs(hb)*3.281 / pow(W, 1.0/3.4);
    
    if (this->get_useCustomDist() == false)
    {
        if (scaled < 180.0)
        {
            this->create_part_hist(0.001, 100, size, 0.407, 4.0);
        }
        else
        {
            this->create_part_hist(0.001, 100, size, 0.15, 2.0);
        }
    }
    else
    {
        this->create_part_hist(this->min_dia, this->max_dia, size, this->mean_dia, this->std_dia);
    }
    
    
    int parcels = 15 + (int)log(W);
    this->parcel_alt_top.set_size(parcels+10, size);
    this->parcel_alt_bot.set_size(parcels+10, size);
    this->parcel_rad_top.set_size(parcels+10, size);
    this->parcel_rad_bot.set_size(parcels+10, size);
    this->parcel_conc.set_size(parcels+10, size);
}

void Crane::compute_initial_air_mass(double W, double gz, double hb)
{
    this->compute_initial_cloud_alt(W, gz, hb);
    this->compute_force_factor(W);
    this->compute_initial_soil_mass(W, gz, hb);
    this->compute_initial_temperature(W, gz, hb);
    this->compute_equil_temp(W);
    double Tei = this->return_amb_temp(this->get_cloud_alt());
    double P = this->return_atm_press(this->get_cloud_alt());
    double HR = this->return_rel_humid(this->get_cloud_alt());
    this->compute_xe(Tei, P, HR);
    double cs_int = this->return_spec_heat_conds_integral(this->get_equil_temp(), Tei);
    this->compute_spec_heat_entrain_integral(this->get_temperature(), Tei);
    double cpw_int = this->return_spec_heat_water_integral(this->get_temperature(), Tei);
    
    this->set_initial_air_mass( this->get_energy_frac()*(4.18e12*this->get_force_factor()*W - this->get_initial_soil_mass()*cs_int)/(this->get_spec_heat_entrain_integral() + (this->get_xe()*cpw_int)) );
    
}

void Crane::compute_initial_water_mass(double W, double gz, double hb)
{
    this->compute_initial_air_mass(W, gz, hb);
    if (this->get_temperature() >= 273.15)
        this->set_latent_heat(2.5E+6);
    else
        this->set_latent_heat(2.83E+6);
    double Tei = this->return_amb_temp(this->get_cloud_alt());
    double cs_int = this->return_spec_heat_conds_integral(this->get_equil_temp(), Tei);
    double cpw_int = this->return_spec_heat_water_integral(this->get_temperature(), Tei);
    
    this->set_initial_water_mass( ( (1.0-this->get_energy_frac())*(4.18e12*this->get_force_factor()*W - this->get_initial_soil_mass()*cs_int)/(cpw_int + this->get_latent_heat()) ) + (this->get_xe()*this->get_initial_air_mass()) );
    
}

void Crane::compute_initial_entrained_mass(double W, double gz, double hb)
{
    this->compute_initial_water_mass(W, gz, hb);
    this->set_entrained_mass(this->get_initial_air_mass()+this->get_initial_water_mass());
}

void Crane::compute_initial_cloud_mass(double W, double gz, double hb)
{
    this->compute_initial_entrained_mass(W, gz, hb);
    this->set_cloud_mass( (this->get_entrained_mass()+this->get_initial_soil_mass())/1000.0/1000.0 );
}

void Crane::compute_initial_s_soil(double W, double gz, double hb)
{
    this->compute_initial_air_mass(W, gz, hb);
    this->set_s_soil(this->get_initial_soil_mass()/this->get_initial_air_mass());
}

void Crane::compute_initial_x_water_vapor(double W, double gz, double hb)
{
    this->compute_initial_water_mass(W, gz, hb);
    this->set_x_water_vapor(this->get_initial_water_mass()/this->get_initial_air_mass());
}

void Crane::compute_initial_cloud_volume(double W, double gz, double hb)
{
    this->compute_initial_entrained_mass(W, gz, hb);
    this->compute_initial_x_water_vapor(W, gz, hb);
    this->compute_apparent_temp(this->get_temperature(), this->get_x_water_vapor());
    this->set_cloud_volume( (this->get_initial_air_mass()+this->get_initial_water_mass()) * this->get_gas_const() * this->get_apparent_temp() / this->return_atm_press(this->get_cloud_alt()) );
}

void Crane::compute_initial_horz_rad(double W, double gz, double hb)
{
    this->compute_initial_cloud_volume(W, gz, hb);
    double top = 3.0*this->get_cloud_volume();
    double bot = 4.0*M_PI*sqrt(1.0 - (this->get_eccentricity()*this->get_eccentricity()));
    this->set_horz_rad( pow(top/bot, 1.0/3.0) );
}

void Crane::compute_initial_vert_rad(double W, double gz, double hb)
{
    this->compute_initial_horz_rad(W, gz, hb);
    this->set_vert_rad( sqrt(this->get_horz_rad()*this->get_horz_rad()*(1.0 - (this->get_eccentricity()*this->get_eccentricity()))) );
}

void Crane::compute_initial_cloud_rise(double W, double gz, double hb)
{
    this->compute_initial_horz_rad(W, gz, hb);
    this->set_cloud_rise( 1.2*sqrt(this->get_grav()*this->get_horz_rad()) );
}

void Crane::compute_initial_energy(double W, double gz, double hb)
{
    this->compute_initial_cloud_rise(W, gz, hb);
    this->set_energy(this->get_cloud_rise()*this->get_cloud_rise()/2.0);
}

void Crane::compute_initial_part_conc(double W, double gz, double hb, int size)
{
    this->compute_initial_cloud_volume(W, gz, hb);
    this->compute_initial_part_hist(W, gz, hb, size);
    double conc = this->get_initial_soil_mass() / this->get_cloud_volume();
    
    //Iterate through map
    int i=0;
    for (std::map<double,double>::iterator it=this->part_hist.begin(); it!=this->part_hist.end(); ++it)
    {
        //NOTE: Dj comes in as um --> convert to m
        double dj = it->first/1.0E+6;
        double mass = this->get_part_density() * M_PI * dj*dj*dj / 6.0;
        this->part_conc[it->first] = it->second * conc / mass / 1.0e9;
        this->part_conc_var(i,0) = this->part_conc[it->first];
        
        for (int p=0; p<this->return_parcel_conc().rows(); p++)
        {
            this->return_parcel_conc().edit(p, i, this->part_conc_var(i,0));
        }
        
        i++;
    }
}

void Crane::compute_initial_virtual_mass(double W, double gz, double hb)
{
    this->compute_initial_cloud_mass(W, gz, hb);
    this->compute_initial_s_soil(W, gz, hb);
    this->compute_initial_x_water_vapor(W, gz, hb);
    this->compute_apparent_temp(this->get_temperature(), this->get_x_water_vapor());
    double Tei = this->return_amb_temp(this->get_cloud_alt());
    this->compute_apparent_amb_temp(Tei, this->get_xe());
    this->compute_beta_prime(this->get_x_water_vapor(), this->get_s_soil(), this->get_w_water_conds());
    
    this->set_virtual_mass( this->get_cloud_mass()*this->get_beta_prime()*this->get_apparent_temp()/2.0/this->get_apparent_amb_temp() );
}

void Crane::compute_adjusted_height(double W, double gz, double hb)
{
    this->compute_initial_vert_rad(W, gz, hb);
    this->compute_mu(W);
    this->compute_initial_cloud_alt(W, gz, hb);
    this->set_adjusted_height( this->get_cloud_alt() - (this->get_vert_rad()/this->get_mu()) );
}

void Crane::delete_particles()
{
    part_hist.clear();
    settling_rate.clear();
    part_conc.clear();
    part_size.clear();
    settling_rate_old.clear();
}

// Below are listed return functions specific for temperature integral related values

void Crane::compute_spec_heat_entrain_integral(double T, double Te)
{
    //Integration by parts for a piecewise polynomial
    double upper = 0.0, lower = 0.0;
    if (T > 2300.0)
        upper = (-3587.5*T + (2.125/2.0)*T*T) - (-3587.5*2300.0 + (2.125/2.0)*2300.0*2300.0);
    else
        upper = (946.6*T + (0.1971/2.0)*T*T) - (946.6*2300.0 + (0.1971/2.0)*2300.0*2300.0);
    
    if (Te > 2300.0)
        lower = (-3587.5*2300.0 + (2.125/2.0)*2300.0*2300.0) - (-3587.5*Te + (2.125/2.0)*Te*Te);
    else
        lower = (946.6*2300.0 + (0.1971/2.0)*2300.0*2300.0) - (946.6*Te + (0.1971/2.0)*Te*Te);
    
    this->set_spec_heat_entrain_integral(upper + lower);
}

double Crane::return_spec_heat_water_integral(double T, double Te)
{
    return (1697.66*T + (1.144174/2.0)*T*T) - (1697.66*Te + (1.144174/2.0)*Te*Te);
}

double Crane::return_spec_heat_conds_integral(double T, double Te)
{
    //Integration by parts for a piecewise polynomial
    double upper = 0.0, lower = 0.0;
    if (T > 848.0)
        upper = (1003.8*T + (0.1351/2.0)*T*T) - (1003.8*848.0 + (0.1351/2.0)*848.0*848.0);
    else
        upper = (781.6*T + (0.5612/2.0)*T*T + 1.881e+7/T) - (781.6*848.0 + (0.5612/2.0)*848.0*848.0 + 1.881e+7/848.0);
    
    if (Te > 848.0)
        lower = (1003.8*848.0 + (0.1351/2.0)*848.0*848.0) - (1003.8*Te + (0.1351/2.0)*Te*Te);
    else
        lower = (781.6*848.0 + (0.5612/2.0)*848.0*848.0 + 1.881e+7/848.0) - (781.6*Te + (0.5612/2.0)*Te*Te + 1.881e+7/Te);
    
    return upper+lower;
}

// Below are listed functions specific for air profile related operations

void Crane::add_amb_temp(double z, double Te)
{
    this->amb_temp[z] = Te;
}

void Crane::add_atm_press(double z, double P)
{
    this->atm_press[z] = P;
}

void Crane::add_rel_humid(double z, double HR)
{
    this->rel_humid[z] = HR;
}

void Crane::add_wind_vel(double z, double vx, double vy)
{
    Matrix<double> v(2,1);
    v(0,0) = vx;
    v(1,0) = vy;
    this->wind_vel[z] = v;
}

void Crane::create_default_atmosphere()
{
    this->delete_atmosphere();
    
    this->add_amb_temp(-600, 292.05);
    this->add_atm_press(-600, 108870);
    this->add_rel_humid(-600, 77);
    
    this->add_amb_temp(0, 288.15);
    this->add_atm_press(0, 101330);
    this->add_rel_humid(0, 77);
    
    this->add_amb_temp(600, 280.29);
    this->add_atm_press(600, 95618);
    this->add_rel_humid(600, 59.295);
    
    this->add_amb_temp(1200, 277.93);
    this->add_atm_press(1200, 88898);
    this->add_rel_humid(1200, 55.07);
    
    this->add_amb_temp(1800, 274.82);
    this->add_atm_press(1800, 82731);
    this->add_rel_humid(1800, 70.608);
    
    this->add_amb_temp(2400, 270.85);
    this->add_atm_press(2400, 78842);
    this->add_rel_humid(2400, 74.028);
    
    this->add_amb_temp(3000, 267.07);
    this->add_atm_press(3000, 78952);
    this->add_rel_humid(3000, 77.447);
    
    this->add_amb_temp(3600, 264.93);
    this->add_atm_press(3600, 56275);
    this->add_rel_humid(3600, 64.481);
    
    this->add_amb_temp(4200, 252.78);
    this->add_atm_press(4200, 51599);
    this->add_rel_humid(4200, 51.655);
    
    this->add_amb_temp(4800, 260.63);
    this->add_atm_press(4800, 56922);
    this->add_rel_humid(4800, 38.368);
    
    this->add_amb_temp(5400, 258.49);
    this->add_atm_press(5400, 52245);
    this->add_rel_humid(5400, 25.2625);
    
    this->add_amb_temp(6000, 254.32);
    this->add_atm_press(6000, 48211);
    this->add_rel_humid(6000, 28.88);
    
    this->add_amb_temp(6600, 249.14);
    this->add_atm_press(6600, 44498);
    this->add_rel_humid(6600, 40.65);
    
    this->add_amb_temp(7200, 243.96);
    this->add_atm_press(7200, 48786);
    this->add_rel_humid(7200, 52.45);
    
    this->add_amb_temp(7800, 238.87);
    this->add_atm_press(7800, 37717);
    this->add_rel_humid(7800, 37.56);
    
    this->add_amb_temp(8400, 233.77);
    this->add_atm_press(8400, 34649);
    this->add_rel_humid(8400, 22.63);
    
    this->add_amb_temp(9000, 228.68);
    this->add_atm_press(9000, 31588);
    this->add_rel_humid(9000, 7.39);
    
    this->add_amb_temp(9600, 223.78);
    this->add_atm_press(9600, 28832);
    this->add_rel_humid(9600, 1.87);
    
    this->add_amb_temp(10200, 218.97);
    this->add_atm_press(10200, 26243);
    this->add_rel_humid(10200, 0.6165);
    
    this->add_amb_temp(10800, 216.1);
    this->add_atm_press(10800, 23933);
    this->add_rel_humid(10800, 0.1355);
    
    this->add_amb_temp(11400, 214.2);
    this->add_atm_press(11400, 21762);
    this->add_rel_humid(11400, 0.060707);
    
    this->add_amb_temp(12000, 213.26);
    this->add_atm_press(12000, 19755);
    this->add_rel_humid(12000, 0.009702);
    
    this->add_amb_temp(12600, 214.25);
    this->add_atm_press(12600, 18075);
    this->add_rel_humid(12600, 0.0062739);
    
    this->add_amb_temp(13200, 215.22);
    this->add_atm_press(13200, 16394);
    this->add_rel_humid(13200, 0.0028455);
    
    this->add_amb_temp(13800, 215.96);
    this->add_atm_press(13800, 14879);
    this->add_rel_humid(13800, 0.00051797);
    
    this->add_amb_temp(14400, 216.13);
    this->add_atm_press(14400, 13692);
    this->add_rel_humid(14400, 0.00039199);
    
    this->add_amb_temp(15000, 216.3);
    this->add_atm_press(15000, 12505);
    this->add_rel_humid(15000, 0.00026602);
    
    this->add_amb_temp(15600, 216.47);
    this->add_atm_press(15600, 11319);
    this->add_rel_humid(15600, 0.00014004);
    
    this->add_amb_temp(16200, 216.64);
    this->add_atm_press(16200, 10133);
    this->add_rel_humid(16200, 0.000014067);
    
    this->add_amb_temp(16800, 216.65);
    this->add_atm_press(16800, 9824.5);
    this->add_rel_humid(16800, 0.000015439);
    
    this->add_amb_temp(17400, 216.65);
    this->add_atm_press(17400, 8516);
    this->add_rel_humid(17400, 6.81e-6);
    
    this->add_amb_temp(18000, 216.66);
    this->add_atm_press(18000, 7788.4);
    this->add_rel_humid(18000, 1.181e-6);
    
    this->add_amb_temp(18600, 216.66);
    this->add_atm_press(18600, 6978.1);
    this->add_rel_humid(18600, 6.947e-7);
    
    this->add_amb_temp(19200, 216.66);
    this->add_atm_press(19200, 6433.4);
    this->add_rel_humid(19200, 4.929e-7);
    
    this->add_amb_temp(19800, 216.66);
    this->add_atm_press(19800, 5825.6);
    this->add_rel_humid(19800, 2.910e-7);
    
    this->add_amb_temp(20400, 216.66);
    this->add_atm_press(20400, 5253.8);
    this->add_rel_humid(20400, 8.9156e-8);
    
    this->add_amb_temp(21000, 216.51);
    this->add_atm_press(21000, 4812.4);
    this->add_rel_humid(21000, 1.922e-8);
    
    this->add_amb_temp(21600, 216.3);
    this->add_atm_press(21600, 4437.7);
    this->add_rel_humid(21600, 1.5246e-8);
    
    this->add_amb_temp(22200, 216.08);
    this->add_atm_press(22200, 4053.8);
    this->add_rel_humid(22200, 1.1272e-8);
    
    this->add_amb_temp(22800, 215.86);
    this->add_atm_press(22800, 3688.3);
    this->add_rel_humid(22800, 7.2583e-9);
    
    this->add_amb_temp(23400, 215.64);
    this->add_atm_press(23400, 3313.5);
    this->add_rel_humid(23400, 3.3246e-9);
    
    this->add_amb_temp(24000, 215.79);
    this->add_atm_press(24000, 2884.7);
    this->add_rel_humid(24000, 6.25355e-10);
    
    this->add_amb_temp(24800, 216.67);
    this->add_atm_press(24800, 2747.7);
    this->add_rel_humid(24800, 4.7485e-10);
    
    this->add_amb_temp(25200, 217.56);
    this->add_atm_press(25200, 2510.7);
    this->add_rel_humid(25200, 3.2434e-10);
    
    this->add_amb_temp(25800, 218.44);
    this->add_atm_press(25800, 2273.7);
    this->add_rel_humid(25800, 1.7583e-10);
    
    this->add_amb_temp(26400, 219.32);
    this->add_atm_press(26400, 2086.7);
    this->add_rel_humid(26400, 2.3328e-11);
    
    this->add_amb_temp(27000, 220.41);
    this->add_atm_press(27000, 1902.2);
    this->add_rel_humid(27000, 2.0301e-11);
    
    this->add_amb_temp(27600, 221.49);
    this->add_atm_press(27600, 1767.65);
    this->add_rel_humid(27600, 1.7275e-11);
    
    this->add_amb_temp(28200, 222.57);
    this->add_atm_press(28200, 1633.1);
    this->add_rel_humid(28200, 1.4245e-11);
    
    this->add_amb_temp(28800, 223.65);
    this->add_atm_press(28800, 1488.55);
    this->add_rel_humid(28800, 1.1218e-11);
    
    this->add_amb_temp(29400, 224.78);
    this->add_atm_press(29400, 1229.4);
    this->add_rel_humid(29400, 5.1899e-12);
    
    this->add_amb_temp(30000, 225.82);
    this->add_atm_press(30000, 1164);
    this->add_rel_humid(30000, 5.1622e-12);
    
    this->add_amb_temp(30600, 226.9);
    this->add_atm_press(30600, 1094.9);
    this->add_rel_humid(30600, 0.021345);
    
    this->add_amb_temp(31200, 228.07);
    this->add_atm_press(31200, 995.42);
    this->add_rel_humid(31200, 0.042105);
    
    this->add_amb_temp(31800, 229.43);
    this->add_atm_press(31800, 966.19);
    this->add_rel_humid(31800, 0.168425);
    
    this->add_amb_temp(32400, 230.79);
    this->add_atm_press(32400, 935.57);
    this->add_rel_humid(32400, 0.29474);
    
    this->add_amb_temp(33000, 232.15);
    this->add_atm_press(33000, 907.75);
    this->add_rel_humid(33000, 0.4210);
    
    this->add_amb_temp(33600, 233.51);
    this->add_atm_press(33600, 878.53);
    this->add_rel_humid(33600, 0.54757);
    
    this->add_amb_temp(34200, 234.87);
    this->add_atm_press(34200, 849.33);
    this->add_rel_humid(34200, 0.67366);
    
    this->add_amb_temp(34800, 236.22);
    this->add_atm_press(34800, 825.08);
    this->add_rel_humid(34800, 0.86004);
    
    this->add_amb_temp(35400, 237.58);
    this->add_atm_press(35400, 798.86);
    this->add_rel_humid(35400, 0.92632);
    
    this->add_amb_temp(36000, 238.94);
    this->add_atm_press(36000, 761.54);
    this->add_rel_humid(36000, 1.0525);
    
    this->add_amb_temp(36600, 240.3);
    this->add_atm_press(36600, 732.41);
    this->add_rel_humid(36600, 1.1789);
    
    this->add_amb_temp(37200, 241.66);
    this->add_atm_press(37200, 703.19);
    this->add_rel_humid(37200, 1.3053);
    
    this->add_amb_temp(37800, 243.02);
    this->add_atm_press(37800, 673.97);
    this->add_rel_humid(37800, 1.4315);
    
    this->add_amb_temp(38400, 244.38);
    this->add_atm_press(38400, 544.75);
    this->add_rel_humid(38400, 1.5579);
    
    this->add_amb_temp(39000, 245.74);
    this->add_atm_press(39000, 515.52);
    this->add_rel_humid(39000, 1.6842);
    
    this->add_amb_temp(39600, 247.1);
    this->add_atm_press(39600, 508.37);
    this->add_rel_humid(39600, 1.8105);
    
    this->add_amb_temp(40200, 248.45);
    this->add_atm_press(40200, 557.08);
    this->add_rel_humid(40200, 1.9365);
    
    this->add_amb_temp(40800, 249.81);
    this->add_atm_press(40800, 527.36);
    this->add_rel_humid(40800, 2.0632);
    
    this->add_amb_temp(41400, 251.17);
    this->add_atm_press(41400, 498.53);
    this->add_rel_humid(41400, 2.1895);
    
    this->add_amb_temp(42000, 252.53);
    this->add_atm_press(42000, 469.41);
    this->add_rel_humid(42000, 2.3158);
    
    this->add_amb_temp(42600, 253.89);
    this->add_atm_press(42600, 440.19);
    this->add_rel_humid(42600, 2.4421);
    
    this->add_amb_temp(43200, 255.25);
    this->add_atm_press(43200, 410.97);
    this->add_rel_humid(43200, 2.5684);
    
    this->add_amb_temp(43800, 256.61);
    this->add_atm_press(43800, 381.74);
    this->add_rel_humid(43800, 2.5947);
    
    this->add_amb_temp(44400, 257.97);
    this->add_atm_press(44400, 352.52);
    this->add_rel_humid(44400, 2.8211);
    
    this->add_amb_temp(45000, 259.33);
    this->add_atm_press(45000, 323.3);
    this->add_rel_humid(45000, 2.9474);
    
    this->add_amb_temp(45600, 260.68);
    this->add_atm_press(45600, 294.08);
    this->add_rel_humid(45600, 3.0737);
    
    this->add_amb_temp(46200, 262.04);
    this->add_atm_press(46200, 254.85);
    this->add_rel_humid(46200, 3.2);
    
    this->add_amb_temp(46800, 263.4);
    this->add_atm_press(46800, 235.63);
    this->add_rel_humid(46800, 3.3263);
    
    this->add_amb_temp(47400, 264.76);
    this->add_atm_press(47400, 206.41);
    this->add_rel_humid(47400, 3.4526);
    
    this->add_amb_temp(48000, 266.12);
    this->add_atm_press(48000, 177.19);
    this->add_rel_humid(48000, 3.5789);
    
    this->add_amb_temp(48600, 267.48);
    this->add_atm_press(48600, 147.96);
    this->add_rel_humid(48600, 3.7053);
    
    this->add_amb_temp(49200, 268.84);
    this->add_atm_press(49200, 118.74);
    this->add_rel_humid(49200, 3.8316);
    
    this->add_amb_temp(49800, 270.2);
    this->add_atm_press(49800, 89.52);
    this->add_rel_humid(49800, 3.9579);
}

void Crane::create_default_wind_profile()
{
    this->delete_wind_profile();
    
    this->add_wind_vel(216, -5.14, 6.13);
    this->add_wind_vel(1548, -5.494, 11.78);
    this->add_wind_vel(3097, 0.8582, 4.924);
    this->add_wind_vel(5688, 5.13, 14.095);
    this->add_wind_vel(7327, 10.898, 15.56);
    this->add_wind_vel(9309, 10.28, 12.25);
    this->add_wind_vel(10488, 6.309, 9.0156);
    this->add_wind_vel(11887, 8.356, 9.9585);
    this->add_wind_vel(13698, 9.8298, 6.883);
    this->add_wind_vel(16267, 8.457, 3.078);
    this->add_wind_vel(18526, 5.9733, -0.61);
    this->add_wind_vel(20665, 6.973, -0.618);
    this->add_wind_vel(23902, 10.83, -1.91);
    this->add_wind_vel(26493, 11.0, 1.974);
    this->add_wind_vel(31023, 24.804, -2.1788);
}

void Crane::delete_atmosphere()
{
    this->amb_temp.clear();
    this->atm_press.clear();
    this->rel_humid.clear();
}

void Crane::delete_wind_profile()
{
    this->wind_vel.clear();
}

std::map<double, double> & Crane::return_atm_press_map()
{
    return this->atm_press;
}

void Crane::add_solid_param(std::string name, int pow, double param)
{
    this->solid_params[name][pow] = param;
}

void Crane::add_vapor_param(std::string name, int pow, double param)
{
    this->vapor_params[name][pow] = param;
}

void Crane::create_default_soil_components()
{
    this->add_solid_param("Al2O3", 1, 2291.808);
    
    this->add_solid_param("B2O3", 1, 470.728);
    this->add_solid_param("B2O3", 2, 0.0);
    this->add_solid_param("B2O3", 3, 0.863);
    
    this->add_solid_param("CaO", 1, 1470.932);
    this->add_solid_param("CaO", 2, 1117.638);
    
    this->add_solid_param("Na2O", 1, 721.183);
    this->add_solid_param("Na2O", 4, 409.184);
    
    this->add_solid_param("SiO2", 1, 748.503);
    this->add_solid_param("SiO2", 4, 943.883);
    
    this->add_solid_param("Fe2O3", 1, 488.275);
    this->add_solid_param("Fe2O3", 2, 388.747);
    this->add_solid_param("Fe2O3", 3, 347.072);
    this->add_solid_param("Fe2O3", 4, 340.824);
    
    this->add_solid_param("Li2O", 2, 1002.059);
    this->add_solid_param("Li2O", 3, 283.818);
    this->add_solid_param("Li2O", 4, 152.218);
    
    this->add_solid_param("NiO", 1, 61.949);
    this->add_solid_param("NiO", 2, 680.155);
    this->add_solid_param("NiO", 3, 616.105);
    this->add_solid_param("NiO", 4, 596.780);
    
    this->add_solid_param("ZrO2", 1, 2732.195);
    
    this->add_solid_param("Cr2O3", 1, 2435.526);
    
    this->add_solid_param("ZnO", 1, 1939.413);
    this->add_solid_param("ZnO", 3, 35.571);
    
    this->add_solid_param("MnO", 1, 1124.363);
    this->add_solid_param("MnO", 2, 264.251);
    this->add_solid_param("MnO", 3, 250.261);
    this->add_solid_param("MnO", 4, 306.210);
    
    this->add_solid_param("K2O", 2, 1.588);
    this->add_solid_param("K2O", 4, 737.881);
    
    this->add_solid_param("Other", 1, 1174);
    
    this->add_vapor_param("Al2O3", 1, 2977);
    this->add_vapor_param("B2O3", 1, 1860);
    this->add_vapor_param("CaO", 1, 2850);
    this->add_vapor_param("Na2O", 1, 1950);
    this->add_vapor_param("SiO2", 1, 2950);
    this->add_vapor_param("Fe2O3", 1, 1565);
    this->add_vapor_param("Li2O", 1, 2600);
    this->add_vapor_param("NiO", 1, 1955);
    this->add_vapor_param("ZrO2", 1, 4300);
    this->add_vapor_param("Cr2O3", 1, 4000);
    this->add_vapor_param("ZnO", 1, 2360);
    this->add_vapor_param("MnO", 1, 3127);
    this->add_vapor_param("K2O", 1, 740);
    this->add_vapor_param("Other", 1, 2556);
}

void Crane::delete_soil_components()
{
    this->vapor_params.clear();
    this->solid_params.clear();
    this->soil_molefrac.clear();
    this->soil_comp.clear();
}

void Crane::add_soil_component(std::string name, double frac)
{
    if (frac < 0.0)
        frac = 0.0;
    if (frac > 1.0)
        frac = 1.0;
    this->soil_molefrac[name] = frac;
    Molecule temp;
    if (name == "Other")
        temp.Register(0, 0, 0, 0, false, false, "Solid", name, name, "C5H7O2N");
    else
        temp.Register(0, 0, 0, 0, false, false, "Solid", name, name, name);
    this->soil_comp[name] = temp;
}

void Crane::verify_soil_components()
{
    //Iterate through the map
    std::map<std::string,double>::iterator it;
    double sum = 0.0;
    int count = 0;
    for (it=this->soil_molefrac.begin(); it!=this->soil_molefrac.end(); it++)
    {
        sum += it->second;
        count++;
    }
    if (count == 0)
    {
        this->add_soil_component("Other", 1.0);
    }
    else
    {
        if ( sum > 1.0 )
        {
            for (it=this->soil_molefrac.begin(); it!=this->soil_molefrac.end(); it++)
            {
                it->second = it->second / sum;
            }
        }
        if ( sum < 1.0 )
        {
            double diff = 1.0 - sum;
            it = this->soil_molefrac.find("Other");
            if (it == this->soil_molefrac.end())
            {
                this->add_soil_component("Other", diff);
            }
            else
            {
                this->soil_molefrac["Other"] += diff;
            }
        }
    }
    
    //Create the soil atom map
    for (it=this->soil_molefrac.begin(); it!=this->soil_molefrac.end(); it++)
    {
        for (int i=0; i<this->soil_comp[it->first].getAtoms().size(); i++)
        {
            this->soil_atom_frac[this->soil_comp[it->first].getAtoms()[i].AtomSymbol()] = 0.0;
        }
    }
    //Fill the soil atom map
    for (it=this->soil_molefrac.begin(); it!=this->soil_molefrac.end(); it++)
    {
        for (int i=0; i<this->soil_comp[it->first].getAtoms().size(); i++)
        {
            this->soil_atom_frac[this->soil_comp[it->first].getAtoms()[i].AtomSymbol()] += it->second*(1.0/(double)this->soil_comp[it->first].getAtoms().size());
        }
    }
    
    for (it=this->soil_atom_frac.begin(); it!=this->soil_atom_frac.end(); it++)
    {
        Atom temp;
        temp.Register(it->first);
        this->soil_atom[it->first] = temp;
    }
}

void Crane::compute_solidification_temp()
{
    //Iterate through the map
    std::map<std::string,double>::iterator it;
    std::unordered_map<std::string, std::map<int, double> >::const_iterator jt;
    double temp = 0.0;
    std::string name;
    for (it=this->soil_molefrac.begin(); it!=this->soil_molefrac.end(); it++)
    {
        jt = this->solid_params.find(it->first);
        if (jt == this->solid_params.end())
            name = "Other";
        else
            name = it->first;
        
        for (auto &x: this->solid_params[name])
        {
            temp += x.second*pow(it->second, (double)x.first);
        }
    }
    
    this->set_solidification_temp(temp+273.15);
}

void Crane::compute_vaporization_temp()
{
    //Iterate through the map
    std::map<std::string,double>::iterator it;
    std::unordered_map<std::string, std::map<int, double> >::const_iterator jt;
    double temp = 0.0;
    std::string name;
    for (it=this->soil_molefrac.begin(); it!=this->soil_molefrac.end(); it++)
    {
        jt = this->vapor_params.find(it->first);
        if (jt == this->vapor_params.end())
            name = "Other";
        else
            name = it->first;
        
        for (auto &x: this->vapor_params[name])
        {
            temp += x.second*pow(it->second, (double)x.first);
        }
    }
    
    this->set_vaporization_temp(temp+273.15);
}

void Crane::compute_initial_soil_vapor()
{
    double mass = 0.00015*this->get_initial_soil_mass()*(this->get_temperature() - this->get_vaporization_temp());
    if (mass < 0.0)
        mass = 0.0;
    if (mass > this->get_initial_soil_mass())
        mass = this->get_initial_soil_mass();
    this->set_initial_soil_vapor(mass);
}

double Crane::return_amb_temp(double z)
{
    double Te = 0.0;
    
    //Setup the iterators
    std::map<double,double>::iterator it=this->amb_temp.begin();
    std::map<double,double>::reverse_iterator rit=this->amb_temp.rbegin();
    
    //Special Case 1: z less than lowest value in map
    if (z <= it->first)
        return it->second;
    
    //Special Case 2: z greater than highest value in map
    if (z >= rit->first)
        return rit->second;
    
    //Iterate through map
    double old_z = it->first;
    double old_Te = it->second;
    for (it=this->amb_temp.begin(); it!=this->amb_temp.end(); ++it)
    {
        if (it->first > z)
        {
            double slope = (it->second - old_Te) / (it->first - old_z);
            double inter = it->second - (slope*it->first);
            Te = slope*z + inter;
            break;
        }
        else
        {
            old_z = it->first;
            old_Te = it->second;
        }
    }
    
    return Te;
}

double Crane::return_atm_press(double z)
{
    double P = 0.0;
    
    //Setup the iterators
    std::map<double,double>::iterator it=this->atm_press.begin();
    std::map<double,double>::reverse_iterator rit=this->atm_press.rbegin();
    
    //Special Case 1: z less than lowest value in map
    if (z <= it->first)
        return it->second;
    
    //Special Case 2: z greater than highest value in map
    if (z >= rit->first)
        return rit->second;
    
    //Iterate through map
    double old_z = it->first;
    double old_Te = it->second;
    for (it=this->atm_press.begin(); it!=this->atm_press.end(); ++it)
    {
        if (it->first > z)
        {
            double slope = (it->second - old_Te) / (it->first - old_z);
            double inter = it->second - (slope*it->first);
            P = slope*z + inter;
            break;
        }
        else
        {
            old_z = it->first;
            old_Te = it->second;
        }
    }
    
    return P;
}

double Crane::return_rel_humid(double z)
{
    double HR = 0.0;
    
    //Setup the iterators
    std::map<double,double>::iterator it=this->rel_humid.begin();
    std::map<double,double>::reverse_iterator rit=this->rel_humid.rbegin();
    
    //Special Case 1: z less than lowest value in map
    if (z <= it->first)
        return it->second;
    
    //Special Case 2: z greater than highest value in map
    if (z >= rit->first)
        return rit->second;
    
    //Iterate through map
    double old_z = it->first;
    double old_Te = it->second;
    for (it=this->rel_humid.begin(); it!=this->rel_humid.end(); ++it)
    {
        if (it->first > z)
        {
            double slope = (it->second - old_Te) / (it->first - old_z);
            double inter = it->second - (slope*it->first);
            HR = slope*z + inter;
            break;
        }
        else
        {
            old_z = it->first;
            old_Te = it->second;
        }
    }
    
    return HR;
}

Matrix<double> Crane::return_wind_vel(double z)
{
    Matrix<double> HR;
    
    //Setup the iterators
    std::map<double,Matrix<double>>::iterator it=this->wind_vel.begin();
    std::map<double,Matrix<double>>::reverse_iterator rit=this->wind_vel.rbegin();
    
    //Special Case 1: z less than lowest value in map
    if (z <= it->first)
        return it->second;
    
    //Special Case 2: z greater than highest value in map
    if (z >= rit->first)
        return rit->second;
    
    //Iterate through map
    double old_z = it->first;
    Matrix<double> old_Te = it->second;
    for (it=this->wind_vel.begin(); it!=this->wind_vel.end(); ++it)
    {
        if (it->first > z)
        {
            Matrix<double> slope = (it->second - old_Te) / (it->first - old_z);
            Matrix<double> inter = it->second - (slope*it->first);
            HR = slope*z + inter;
            break;
        }
        else
        {
            old_z = it->first;
            old_Te = it->second;
        }
    }
    
    return HR;
}

double Crane::return_wind_speed(double z)
{
    Matrix<double> v = this->return_wind_vel(z);
    return v.norm();
}

void Crane::compute_current_amb_temp(double z)
{
    this->set_current_amb_temp( this->return_amb_temp(z) );
}

void Crane::compute_current_atm_press(double z)
{
    this->set_current_atm_press( this->return_atm_press(z) );
}

// Below are listed functions to feed to DOVE as residuals

double rate_cloud_rise(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    double res = 0.0;
    
    Crane *dat = (Crane *) data;
    double m = ( u(dove.getVariableIndex("m (Gg)"),0) );
    double U = u(dove.getVariableIndex("u (m/s)"),0);
    double dm_dt = dove.coupledTimeDerivative("m (Gg)",u);
    double T = ( u(dove.getVariableIndex("T (K)"),0) );
    double x = ( u(dove.getVariableIndex("x (kg/kg)"),0) );
    double s = ( u(dove.getVariableIndex("s (kg/kg)"),0) );
    double w = ( u(dove.getVariableIndex("w (kg/kg)"),0) );
    double z = u(dove.getVariableIndex("z (m)"),0);
    
    if (dat->get_isTight() == true)
    {
        dat->compute_apparent_temp(T, x);
        dat->compute_beta_prime(x, s, w);
        dat->compute_vert_rad(z);
    }
    
    double p1 = (((dat->get_apparent_temp()/dat->get_apparent_amb_temp())*dat->get_beta_prime()) - 1.0) * dat->get_grav();
    double p2 = (2.0*dat->get_k2()*dat->get_char_vel()*dat->get_apparent_temp()*dat->get_beta_prime())/(dat->get_vert_rad()*dat->get_apparent_amb_temp());
    double p3 = (dm_dt/m);
    
    res = p1 - ((p2+p3)*U);
    
    return res;
}

double rate_cloud_alt(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    return u(dove.getVariableIndex("u (m/s)"),0);
}

double rate_x_water_vapor(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    double res = 0.0;
    
    Crane *dat = (Crane *) data;
    
    // Check for saturation
    if (dat->get_isSaturated() == true)
    {
        double x = ( u(dove.getVariableIndex("x (kg/kg)"),0) );
        double T = ( u(dove.getVariableIndex("T (K)"),0) );
        double U = u(dove.getVariableIndex("u (m/s)"),0);
        double dT_dt = dove.coupledTimeDerivative("T (K)",u);
        
        double p1 = (1.0 + (x/dat->get_eps()))*(dat->get_latent_heat()*dat->get_eps()/dat->get_gas_const()/T/T)*dT_dt;
        double p2 = (1.0 + (x/dat->get_eps()))*dat->get_grav()*U/dat->get_gas_const()/dat->get_apparent_amb_temp();
        
        res = x*(p1+p2);
    }
    else
    {
        double m = ( u(dove.getVariableIndex("m (Gg)"),0) );
        double dment_dt = rate_entrained_mass(0, u, dove.getCurrentTime(), data, dove);
        double x = ( u(dove.getVariableIndex("x (kg/kg)"),0) );
        double s = ( u(dove.getVariableIndex("s (kg/kg)"),0) );
        
        res = -((1.0+x+s)/(1.0+dat->get_xe()))*(x - dat->get_xe())*dment_dt/m;
    }
    
    return res;
}

double rate_temperature(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    double res = 0.0;
    
    Crane *dat = (Crane *) data;
    
    // Check for saturation
    if (dat->get_isSaturated() == true)
    {
        double x = ( u(dove.getVariableIndex("x (kg/kg)"),0) );
        double T = ( u(dove.getVariableIndex("T (K)"),0) );
        double m = ( u(dove.getVariableIndex("m (Gg)"),0) );
        double dment_dt = rate_entrained_mass(0, u, dove.getCurrentTime(), data, dove);
        double E = ( u(dove.getVariableIndex("E (J/kg)"),0) );
        double s = ( u(dove.getVariableIndex("s (kg/kg)"),0) );
        double w = ( u(dove.getVariableIndex("w (kg/kg)"),0) );
        double U = u(dove.getVariableIndex("u (m/s)"),0);
        double z = u(dove.getVariableIndex("z (m)"),0);
        
        if (dat->get_isTight() == true)
        {
            dat->compute_apparent_temp(T, x);
            dat->compute_beta_prime(x, s, w);
            dat->compute_sigma_turbulence(E, z);
            dat->compute_actual_spec_heat(T, x);
        }
        
        double p1 = dat->get_beta_prime() / (1.0 + (dat->get_latent_heat()*dat->get_latent_heat()*x*dat->get_eps()/dat->get_actual_spec_heat()/dat->get_gas_const()/T/T));
        double p2 = ( T - dat->get_current_amb_temp() + (dat->get_latent_heat()*(x-dat->get_xe())/dat->get_actual_spec_heat()) ) * dment_dt/m/dat->get_beta_prime();
        double p3 = (dat->get_apparent_temp()*dat->get_grav()*U/dat->get_apparent_amb_temp()/dat->get_actual_spec_heat())*(1.0+(dat->get_latent_heat()*x/dat->get_gas_const()/T));
        double p4 = dat->get_sigma_turbulence()/dat->get_actual_spec_heat();
        
        res = -p1*(p2+p3-p4);
        
    }
    else
    {
        double x = ( u(dove.getVariableIndex("x (kg/kg)"),0) );
        double T = ( u(dove.getVariableIndex("T (K)"),0) );
        double m = ( u(dove.getVariableIndex("m (Gg)"),0) );
        double dment_dt = rate_entrained_mass(0, u, dove.getCurrentTime(), data, dove);
        double E = ( u(dove.getVariableIndex("E (J/kg)"),0) );
        double s = ( u(dove.getVariableIndex("s (kg/kg)"),0) );
        double w = ( u(dove.getVariableIndex("w (kg/kg)"),0) );
        double U = u(dove.getVariableIndex("u (m/s)"),0);
        double z = ( u(dove.getVariableIndex("z (m)"),0) );
        
        if (dat->get_isTight() == true)
        {
            dat->compute_apparent_temp(T, x);
            dat->compute_beta_prime(x, s, w);
            dat->compute_sigma_turbulence(E, z);
            dat->compute_actual_spec_heat(T, x);
            dat->compute_spec_heat_entrain_integral(T, dat->get_current_amb_temp());
        }
        
        double p1 = dat->get_beta_prime()/dat->get_actual_spec_heat();
        double p2 = dat->get_apparent_temp()*dat->get_grav()*U/dat->get_apparent_amb_temp();
        double p3 = dat->get_spec_heat_entrain_integral()*dment_dt/dat->get_beta_prime()/m;
        
        res = -p1*(p2 + p3 - dat->get_sigma_turbulence());
    }
    
    return res;
}

double rate_w_water_conds(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    double res = 0.0;
    
    Crane *dat = (Crane *) data;
    
    // Check for saturation
    if (dat->get_isSaturated() == true)
    {
        double x = ( u(dove.getVariableIndex("x (kg/kg)"),0) );
        double T = ( u(dove.getVariableIndex("T (K)"),0) );
        double m = ( u(dove.getVariableIndex("m (Gg)"),0) );
        double dment_dt = rate_entrained_mass(0, u, dove.getCurrentTime(), data, dove);
        double dx_dt = dove.coupledTimeDerivative("x (kg/kg)",u);
        double s = ( u(dove.getVariableIndex("s (kg/kg)"),0) );
        double w = ( u(dove.getVariableIndex("w (kg/kg)"),0) );
        double z = u(dove.getVariableIndex("z (m)"),0);
        
        if (dat->get_isTight() == true)
        {
            dat->compute_beta_prime(x, s, w);
            dat->compute_total_mass_fallout_rate(m, x, s, w, T, dat->get_current_atm_press(), z, dat->get_part_conc_var());
        }
        
        double p1 = (1.0/dat->get_beta_prime())*((1.0+x)/(1.0+dat->get_xe()))*(w+x-dat->get_xe())*dment_dt/m;
        double p2 = ((1.0+x+s+w)/m)*(w/(s+w))*dat->get_total_mass_fallout_rate()/1000.0/1000.0;
        
        res = -p1 - dx_dt - p2;
    }
    else
    {
        res = 0.0;
    }
    
    return res;
}

double rate_energy(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    double res = 0.0;
    
    Crane *dat = (Crane *) data;
    
    double x = ( u(dove.getVariableIndex("x (kg/kg)"),0) );
    double T = ( u(dove.getVariableIndex("T (K)"),0) );
    double m = ( u(dove.getVariableIndex("m (Gg)"),0) );
    double dment_dt = rate_entrained_mass(0, u, dove.getCurrentTime(), data, dove);
    double E = ( u(dove.getVariableIndex("E (J/kg)"),0) );
    double s = ( u(dove.getVariableIndex("s (kg/kg)"),0) );
    double w = ( u(dove.getVariableIndex("w (kg/kg)"),0) );
    double U = u(dove.getVariableIndex("u (m/s)"),0);
    double z = u(dove.getVariableIndex("z (m)"),0);
    
    if (dat->get_isTight() == true)
    {
        dat->compute_apparent_temp(T, x);
        dat->compute_beta_prime(x, s, w);
        dat->compute_vert_rad(z);
        dat->compute_sigma_turbulence(E, z);
    }
    
    double p1 = 2.0*dat->get_k2()*dat->get_apparent_temp()*dat->get_beta_prime()*U*U*dat->get_char_vel()/dat->get_apparent_amb_temp()/dat->get_vert_rad();
    double p2 = U*U*dment_dt/2.0/m;
    double p3 = E*dment_dt/m;
    
    res = p1+p2-p3-dat->get_sigma_turbulence();
    
    return res;
}

double rate_cloud_mass(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    double res = 0.0;
    
    Crane *dat = (Crane *) data;
    
    double x = ( u(dove.getVariableIndex("x (kg/kg)"),0) );
    double T = ( u(dove.getVariableIndex("T (K)"),0) );
    double m = ( u(dove.getVariableIndex("m (Gg)"),0) );
    double dment_dt = rate_entrained_mass(0, u, dove.getCurrentTime(), data, dove);
    double s = ( u(dove.getVariableIndex("s (kg/kg)"),0) );
    double w = ( u(dove.getVariableIndex("w (kg/kg)"),0) );
    double z = u(dove.getVariableIndex("z (m)"),0);
    
    if (dat->get_isTight() == true)
        dat->compute_total_mass_fallout_rate(m, x, s, w, T, dat->get_current_atm_press(), z, dat->get_part_conc_var());
    
    res = dment_dt - (dat->get_total_mass_fallout_rate()/1000.0/1000.0);
    
    return res;
}

double rate_s_soil(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    double res = 0.0;
    
    Crane *dat = (Crane *) data;
    
    double x = ( u(dove.getVariableIndex("x (kg/kg)"),0) );
    double T = ( u(dove.getVariableIndex("T (K)"),0) );
    double m = ( u(dove.getVariableIndex("m (Gg)"),0) );
    double dment_dt = rate_entrained_mass(0, u, dove.getCurrentTime(), data, dove);
    double s = ( u(dove.getVariableIndex("s (kg/kg)"),0) );
    double w = ( u(dove.getVariableIndex("w (kg/kg)"),0) );
    double z = u(dove.getVariableIndex("z (m)"),0);
    
    if (dat->get_isTight() == true)
    {
        dat->compute_total_mass_fallout_rate(m, x, s, w, T, dat->get_current_atm_press(), z, dat->get_part_conc_var());
        dat->compute_beta_prime(x, s, w);
    }
    
    double p1 = ((1.0+x)/(1.0+dat->get_xe()))*s*dment_dt/m/dat->get_beta_prime();
    double p2 = ((1.0+x+s+w)/m)*(s/(s+w))*dat->get_total_mass_fallout_rate()/1000.0/1000.0;
    
    res = -p1-p2;
    
    return res;
}

double rate_entrained_mass(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    double res = 0.0;
    
    Crane *dat = (Crane *) data;
    
    // Check for saturation
    if (dat->get_isSaturated() == true)
    {
        double x = ( u(dove.getVariableIndex("x (kg/kg)"),0) );
        double T = ( u(dove.getVariableIndex("T (K)"),0) );
        double m = ( u(dove.getVariableIndex("m (Gg)"),0) );
        double E = ( u(dove.getVariableIndex("E (J/kg)"),0) );
        double s = ( u(dove.getVariableIndex("s (kg/kg)"),0) );
        double w = ( u(dove.getVariableIndex("w (kg/kg)"),0) );
        double U = u(dove.getVariableIndex("u (m/s)"),0);
        double z = u(dove.getVariableIndex("z (m)"),0);
        
        if (dat->get_isTight() == true)
        {
            dat->compute_apparent_temp(T, x);
            dat->compute_beta_prime(x, s, w);
            dat->compute_sigma_turbulence(E, z);
            dat->compute_actual_spec_heat(T, x);
        }
        
        double p1 = T - dat->get_current_amb_temp() + (dat->get_latent_heat()*(x-dat->get_xe())/dat->get_actual_spec_heat());
        p1 = p1 / (1.0+(dat->get_latent_heat()*dat->get_latent_heat()*x*dat->get_eps()/dat->get_actual_spec_heat()/dat->get_gas_const()/T/T));
        
        p1 = dat->get_beta_prime()*m/(1.0 - (dat->get_beta_prime()*p1/dat->get_apparent_temp()));
        
        double p2 = ((dat->get_grav()*U*dat->get_apparent_temp()/dat->get_actual_spec_heat()/dat->get_apparent_amb_temp())*(1.0+(dat->get_latent_heat()*x/dat->get_gas_const()/T))) - (dat->get_sigma_turbulence()/dat->get_actual_spec_heat());
        p2 = p2 / (1.0+(dat->get_latent_heat()*dat->get_latent_heat()*x*dat->get_eps()/dat->get_actual_spec_heat()/dat->get_gas_const()/T/T));
        p2 = dat->get_beta_prime()*p2/dat->get_apparent_temp();
        
        double p3 = dat->get_grav()*U/dat->get_gas_const()/dat->get_apparent_amb_temp();
        
        res = p1*(dat->get_shear_ratio()+p2-p3);
    }
    else
    {
        double x = ( u(dove.getVariableIndex("x (kg/kg)"),0) );
        double T = ( u(dove.getVariableIndex("T (K)"),0) );
        double m = ( u(dove.getVariableIndex("m (Gg)"),0) );
        double E = ( u(dove.getVariableIndex("E (J/kg)"),0) );
        double s = ( u(dove.getVariableIndex("s (kg/kg)"),0) );
        double w = ( u(dove.getVariableIndex("w (kg/kg)"),0) );
        double U = u(dove.getVariableIndex("u (m/s)"),0);
        double z = u(dove.getVariableIndex("z (m)"),0);
        
        if (dat->get_isTight() == true)
        {
            dat->compute_apparent_temp(T, x);
            dat->compute_beta_prime(x, s, w);
            dat->compute_sigma_turbulence(E, z);
            dat->compute_mean_spec_heat(T, x, s, w);
            dat->compute_actual_spec_heat(T, x);
            dat->compute_spec_heat_entrain_integral(T, dat->get_current_amb_temp());
        }
        
        double p1 = dat->get_beta_prime()*dat->get_spec_heat_entrain_integral()/dat->get_apparent_temp()/dat->get_mean_spec_heat();
        p1 = dat->get_beta_prime()*m/(1.0 - p1);
        
        double p2 = (dat->get_apparent_temp()*dat->get_grav()*U/dat->get_apparent_amb_temp()) - dat->get_sigma_turbulence();
        p2 = dat->get_beta_prime()*p2/dat->get_apparent_temp()/dat->get_actual_spec_heat();
        
        double p3 = dat->get_grav()*U/dat->get_gas_const()/dat->get_apparent_amb_temp();
        
        res = p1*(dat->get_shear_ratio()+p2-p3);
    }
    
    return res;
}

// Below are listed function to compute some post-processing/post-solver information to form the cloud stem

void Crane::compute_alt_top(double z, double Hc)
{
    this->set_alt_top(z+Hc);
}

void Crane::compute_alt_bottom(double z, double Hc)
{
    double bot = z-Hc;
    if (bot < 0.0)
        this->set_alt_bottom(0.0);
    else
        this->set_alt_bottom(bot);
}

void Crane::compute_rise_top(double z_new, double z_old, double dt)
{
    this->set_rise_top((z_new-z_old)/dt);
}

void Crane::compute_rise_bottom(double z_new, double z_old, double dt)
{
    this->set_rise_bottom((z_new-z_old)/dt);
}

Matrix<double> & Crane::return_parcel_alt_top()
{
    return this->parcel_alt_top;
}

Matrix<double> & Crane::return_parcel_alt_bot()
{
    return this->parcel_alt_bot;
}

Matrix<double> & Crane::return_parcel_rad_top()
{
    return this->parcel_rad_top;
}

Matrix<double> & Crane::return_parcel_rad_bot()
{
    return this->parcel_rad_bot;
}

Matrix<double> & Crane::return_parcel_conc()
{
    return this->parcel_conc;
}

// Below are list functions associated with actions completed outside of the solver in DOVE

int Crane::read_atmosphere_profile(const char *profile)
{
    int success = 0;
    
    //Check to see if any argument was given
    if (profile == nullptr || profile == NULL)
    {
        std::cout << "WARNING!!! No atmospheric profile was given!\nUsing default atmosphere instead...\n\n";
        this->create_default_atmosphere();
        return 0;
    }
    
    //Check for existence of file, if no file, then use default
    std::ifstream inputFile( profile );
    if (inputFile.good()==false)
    {
        mError(file_dne);
        std::cout << "Using default atmosphere...\n\n";
        this->create_default_atmosphere();
        return 0;
    }
    
    //Read all as strings, but parse into characters and determine types automatically
    std::string s_read;
    char line[256];
    ValueTypePair data;
    char *num;
    int count = 0;
    this->delete_atmosphere();
    double alt = 0;
    
    //Reading in the first line as a header (not used)
    inputFile.getline(line, 256);
    
    //Read input until reaching end-of-file
    do
    {
        inputFile.getline(line, 256);
        
        //Read numbers delimited by spaces, commas, and/or tabs
        num = strtok(line, " ,\t");
        
        count = 0;
        while (num != NULL)
        {
            s_read = num;
            data.editValue(num);
            data.findType();
            
            if (data.getType() != DOUBLE && data.getType() != INT)
            {
                mError(read_error);
                return -1;
            }
            
            //Store altitude of current line
            if (count == 0)
                alt = data.getDouble();
            
            //Register temperature of current line
            if (count == 1)
                this->add_amb_temp(alt, data.getDouble());
            
            //Register pressure of current line
            if (count == 2)
                this->add_atm_press(alt, data.getDouble());
            
            //Register humidity of current line
            if (count == 3)
                this->add_rel_humid(alt, data.getDouble());
            
            if (count > 3)
            {
                mError(read_error);
                std::cout << "Too many arguments in single line of Atmospheric Input File...\n";
                return -1;
            }
            
            num = strtok(NULL, " ,\t");
            count++;
        }
        
        if (count < 3)
        {
            mError(read_error);
            std::cout << "Too few arguments in single line of Atmospheric Input File...\n";
            return -1;
        }
        
    } while (!inputFile.eof());
    
    
    //END of Input Read
    inputFile.close();
    
    return success;
}

int Crane::read_conditions(Dove &dove, yaml_cpp_class &yaml)
{
    int success = 0;
    double W = 0, gz = 0, hb = 0;
    int bins = 0;
    bool includeShear = false, isTight = false;
    
    try
    {
        W = yaml.getYamlWrapper()("Simulation_Conditions")["bomb_yield"].getDouble();
    }
    catch (std::out_of_range)
    {
        mError(missing_information);
        return -1;
    }
    try
    {
        this->set_ConsoleOut( yaml.getYamlWrapper()("Simulation_Conditions")["console_output"].getBool() );
    }
    catch (std::out_of_range)
    {
        this->set_ConsoleOut( true );
    }
    try
    {
        hb = yaml.getYamlWrapper()("Simulation_Conditions")["burst_height"].getDouble();
    }
    catch (std::out_of_range)
    {
        mError(missing_information);
        return -1;
    }
    try
    {
        gz = yaml.getYamlWrapper()("Simulation_Conditions")["ground_level"].getDouble();
    }
    catch (std::out_of_range)
    {
        mError(missing_information);
        return -1;
    }
    try
    {
        bins = yaml.getYamlWrapper()("Simulation_Conditions")["particle_bins"].getInt();
    }
    catch (std::out_of_range)
    {
        bins = 10;
    }
    try
    {
        isTight = yaml.getYamlWrapper()("Simulation_Conditions")["tight_coupling"].getBool();
    }
    catch (std::out_of_range)
    {
        isTight = true;
    }
    try
    {
        includeShear = yaml.getYamlWrapper()("Simulation_Conditions")["shear_correction"].getBool();
    }
    catch (std::out_of_range)
    {
        includeShear = false;
    }
    
    if (bins > 20) isTight = false;
    
    //Read in optional Particle size distribution parameters
    try
    {
        this->set_useCustomDist( yaml.getYamlWrapper()("Simulation_Conditions")("part_dist")["useCustom"].getBool() );
    }
    catch (std::out_of_range)
    {
        this->set_useCustomDist(false);
    }
    if (this->get_useCustomDist() == true)
    {
        try
        {
            this->set_min_dia( yaml.getYamlWrapper()("Simulation_Conditions")("part_dist")["min_dia"].getDouble() );
        }
        catch (std::out_of_range)
        {
            this->set_min_dia( 0.001 );
        }
        try
        {
            this->set_max_dia( yaml.getYamlWrapper()("Simulation_Conditions")("part_dist")["max_dia"].getDouble() );
        }
        catch (std::out_of_range)
        {
            this->set_max_dia( 100.0 );
        }
        try
        {
            this->set_mean_dia( yaml.getYamlWrapper()("Simulation_Conditions")("part_dist")["mean_dia"].getDouble() );
        }
        catch (std::out_of_range)
        {
            this->set_mean_dia( 0.407 );
        }
        try
        {
            this->set_std_dia( yaml.getYamlWrapper()("Simulation_Conditions")("part_dist")["std_dia"].getDouble() );
        }
        catch (std::out_of_range)
        {
            this->set_std_dia( 4.0 );
        }
    }
    
    //Read in optional soil components
    try
    {
        for (auto &x: yaml.getYamlWrapper()("Simulation_Conditions")("soil_comp").getDataMap())
        {
            this->add_soil_component(x.first, x.second.getDouble());
        }
    }
    catch (std::out_of_range)
    {
        //Do nothing
    }
    
    this->establish_initial_conditions(dove, W, gz, hb, bins, includeShear, isTight);
    
    return success;
}

void Crane::establish_initial_conditions(Dove &dove, double W, double gz, double hb, int bins, bool includeShear, bool isTight)
{
    this->compute_energy_switch(W);
    this->compute_initial_current_time(W, gz, hb);
    this->compute_initial_temperature(W, gz, hb);
    this->compute_initial_cloud_alt(W, gz, hb);
    this->compute_initial_cloud_rise(W, gz, hb);
    this->compute_initial_cloud_mass(W, gz, hb);
    this->compute_initial_x_water_vapor(W, gz, hb);
    this->compute_initial_s_soil(W, gz, hb);
    this->compute_initial_energy(W, gz, hb);
    this->compute_initial_part_conc(W, gz, hb, bins);
    this->compute_initial_virtual_mass(W, gz, hb);
    this->compute_initial_entrained_mass(W, gz, hb);
    this->compute_initial_cloud_volume(W, gz, hb);
    this->compute_initial_horz_rad(W, gz, hb);
    this->compute_initial_vert_rad(W, gz, hb);
    this->compute_adjusted_height(W, gz, hb);
    this->compute_equil_temp(W);
    this->compute_k(W);
    this->compute_k2(W);
    this->compute_mu(W);
    this->set_includeShearVel(includeShear);
    this->set_isTight(isTight);
    this->set_isSaturated(false);
    this->verify_soil_components();
    this->compute_solidification_temp();
    this->compute_vaporization_temp();
    this->compute_initial_soil_vapor();
    
    // Post-processing ICs
    this->compute_alt_top(this->get_cloud_alt(), this->get_vert_rad());
    this->compute_alt_bottom(this->get_cloud_alt(), this->get_vert_rad());
    this->set_alt_top_old(this->get_alt_top());
    this->set_alt_bottom_old(this->get_alt_bottom());
    this->set_rise_top(this->get_cloud_rise());
    this->set_rise_bottom(this->get_cloud_rise());
    double dz = 2.0*this->get_vert_rad()/(double)(this->return_parcel_alt_top().rows()-10);
    double z = this->get_alt_bottom();
    double Vol = 0.0;
    double z_start = hb + gz;
    double z_end = this->get_alt_bottom();
    double dz_extra = (z_end - z_start) / 10.0;
    double low_rad = 0.0;
    double high_rad = 0.0;
    
    //Loop through i parcels
    for (int i=10; i<this->return_parcel_alt_top().rows(); i++)
    {
        // Bottom radius
        double mult = (1.0 - ( ((z-this->get_cloud_alt())*(z-this->get_cloud_alt()))/(this->get_vert_rad()*this->get_vert_rad()) ));
        if (mult < 0.0 + sqrt(DBL_EPSILON))	mult = 0.0;
        double r_b = sqrt( this->get_horz_rad()*this->get_horz_rad()*mult );
        
        //Loop through j particle sizes
        for (int j=0; j<this->return_parcel_alt_top().columns(); j++)
        {
            this->return_parcel_alt_bot().edit(i, j, z);
            this->return_parcel_alt_top().edit(i, j, z+dz);
        }
        z = dz + z;
        
        // Top radius
        mult = (1.0 - ( ((z-this->get_cloud_alt())*(z-this->get_cloud_alt()))/(this->get_vert_rad()*this->get_vert_rad()) ));
        if (mult < 0.0 + sqrt(DBL_EPSILON))	mult = 0.0;
        double r_t = sqrt( this->get_horz_rad()*this->get_horz_rad()*mult );
        
        if (r_b < 0.0 + sqrt(DBL_EPSILON)) r_b = (0.45*r_b+0.55*r_t);
        if (r_t < 0.0 + sqrt(DBL_EPSILON)) r_t = (0.55*r_b+0.45*r_t);
        
        if (i == 10) low_rad = r_b;
        if (r_b > high_rad) high_rad = r_b;
        
        //Loop through j particle sizes
        for (int j=0; j<this->return_parcel_alt_top().columns(); j++)
        {
            this->return_parcel_rad_top().edit(i, j, r_t);
            this->return_parcel_rad_bot().edit(i, j, r_b);
        }
        
        double h = this->return_parcel_alt_top()(i,0) - this->return_parcel_alt_bot()(i,0);
        Vol += (M_PI*h/3.0)*(r_t*r_t+r_b*r_t+r_b*r_b);
        
    }
    
    //Loop through i parcels
    double z_b = z_start;
    for (int i = 0; i < 10; i++)
    {
        //Loop through j particle sizes
        for (int j = 0; j<this->return_parcel_alt_top().columns(); j++)
        {
            this->return_parcel_alt_bot().edit(i, j, z_start);
            this->return_parcel_alt_top().edit(i, j, z_start + dz_extra);
            
            double pow_b = (z_start - z_b) / (z_end - z_b);
            double pow_t = (z_start + dz_extra - z_b) / (z_end - z_b);
            double bot = high_rad*pow(low_rad / high_rad, pow_b);
            double top = high_rad*pow(low_rad / high_rad, pow_t);
            this->return_parcel_rad_bot().edit(i, j, bot);
            this->return_parcel_rad_top().edit(i, j, top);
        }
        z_start = dz_extra + z_start;
    }
    
    // Setup data
    dove.set_userdata(this);
    dove.set_numfunc(8);
    
    // Name variables
    
    dove.set_variableName(0, "z (m)");
    dove.set_variableName(1, "m (Gg)");
    dove.set_variableName(2, "x (kg/kg)");
    dove.set_variableName(3, "T (K)");
    dove.set_variableName(4, "w (kg/kg)");
    dove.set_variableName(5, "u (m/s)");
    dove.set_variableName(6, "E (J/kg)");
    dove.set_variableName(7, "s (kg/kg)");
    
    // Register rate functions
    
    dove.regFunction("z (m)", rate_cloud_alt);
    dove.registerCoeff("z (m)", default_coeff);
    
    dove.regFunction("w (kg/kg)", rate_w_water_conds);
    dove.registerCoeff("w (kg/kg)", default_coeff);
    
    dove.regFunction("x (kg/kg)", rate_x_water_vapor);
    dove.registerCoeff("x (kg/kg)", default_coeff);
    
    dove.regFunction("s (kg/kg)", rate_s_soil);
    dove.registerCoeff("s (kg/kg)", default_coeff);
    
    dove.regFunction("u (m/s)", rate_cloud_rise);
    dove.registerCoeff("u (m/s)", default_coeff);
    
    dove.regFunction("m (Gg)", rate_cloud_mass);
    dove.registerCoeff("m (Gg)", default_coeff);
    
    dove.regFunction("E (J/kg)", rate_energy);
    dove.registerCoeff("E (J/kg)", default_coeff);
    
    dove.regFunction("T (K)", rate_temperature);
    dove.registerCoeff("T (K)", default_coeff);
    
    // Set initial conditions
    
    dove.set_starttime(this->get_current_time());
    dove.set_initialcondition("z (m)", this->get_cloud_alt());
    dove.set_initialcondition("w (kg/kg)", this->get_w_water_conds());
    dove.set_initialcondition("x (kg/kg)", this->get_x_water_vapor());
    dove.set_initialcondition("s (kg/kg)", this->get_s_soil());
    dove.set_initialcondition("u (m/s)", this->get_cloud_rise());
    dove.set_initialcondition("m (Gg)", this->get_cloud_mass());
    dove.set_initialcondition("E (J/kg)", this->get_energy());
    dove.set_initialcondition("T (K)", this->get_temperature());
    dove.set_timestep(1.0/this->get_cloud_rise()/10.0);
}

int Crane::read_dove_options(Dove &dove, FILE *file, yaml_cpp_class &yaml)
{
    int success = 0;
    bool fileout = true, consoleout = false;
    integrate_subtype inttype = BE;
    timestep_type timetype = CONSTANT;
    precond_type type = SGS;
    double tol = 0.1, dtmin = 1e-6, dtmax = 0.1, dtmin_conv = 0.001, t_out = 1.0, endtime = 1000.0;
    
    try
    {
        fileout = yaml.getYamlWrapper()("ODE_Options")["file_output"].getBool();
    }
    catch (std::out_of_range)
    {
        fileout = false;
    }
    try
    {
        consoleout = yaml.getYamlWrapper()("ODE_Options")["console_output"].getBool();
    }
    catch (std::out_of_range)
    {
        consoleout = false;
    }
    try
    {
        std::string choice;
        choice = yaml.getYamlWrapper()("ODE_Options")["integration_method"].getString();
        inttype = integration_choice(choice);
    }
    catch (std::out_of_range)
    {
        inttype = BDF2;
    }
    try
    {
        std::string choice;
        choice = yaml.getYamlWrapper()("ODE_Options")["time_stepper"].getString();
        timetype = timestepper_choice(choice);
    }
    catch (std::out_of_range)
    {
        timetype = ADAPTIVE;
    }
    try
    {
        std::string choice;
        choice = yaml.getYamlWrapper()("ODE_Options")["preconditioner"].getString();
        type = preconditioner_choice(choice);
    }
    catch (std::out_of_range)
    {
        type = SGS;
    }
    try
    {
        tol = yaml.getYamlWrapper()("ODE_Options")["tolerance"].getDouble();
    }
    catch (std::out_of_range)
    {
        tol = 0.001;
    }
    try
    {
        dtmin = yaml.getYamlWrapper()("ODE_Options")["dtmin"].getDouble();
    }
    catch (std::out_of_range)
    {
        dtmin = 1e-8;
    }
    try
    {
        dtmax = yaml.getYamlWrapper()("ODE_Options")["dtmax"].getDouble();
    }
    catch (std::out_of_range)
    {
        dtmax = 0.1;
    }
    if (dtmax > 0.1) dtmax = 0.1;
    try
    {
        dtmin_conv = yaml.getYamlWrapper()("ODE_Options")["converged_dtmin"].getDouble();
    }
    catch (std::out_of_range)
    {
        dtmin_conv = 0.1;
    }
    try
    {
        t_out = yaml.getYamlWrapper()("ODE_Options")["time_out"].getDouble();
    }
    catch (std::out_of_range)
    {
        t_out = 1.0;
    }
    try
    {
        endtime = yaml.getYamlWrapper()("ODE_Options")["end_time"].getDouble();
    }
    catch (std::out_of_range)
    {
        endtime = 1000.0;
    }
    
    this->establish_dove_options(dove, file, fileout, consoleout, inttype, timetype, type, tol, dtmin, dtmax, dtmin_conv, t_out, endtime);
    
    return success;
}

void Crane::establish_dove_options(Dove &dove, FILE *file, bool fileout, bool consoleout, integrate_subtype inttype, timestep_type timetype,
                                   precond_type type, double tol, double dtmin, double dtmax, double dtmin_conv, double t_out, double endtime)
{
    dove.set_outputfile(file);
    dove.set_fileoutput(fileout);
    dove.set_headeroutput(fileout);
    this->set_FileOut(fileout);
    dove.set_output(consoleout);
    dove.set_integrationtype(inttype);
    dove.set_timestepper(timetype);
    dove.set_preconditioner(type);
    dove.set_tolerance(tol);
    dove.set_timestepmin(dtmin);
    dove.set_timestepmax(dtmax);
    dove.set_timestepmin_converged(dtmin_conv);
    dove.set_t_out(t_out);
    dove.set_endtime(endtime);
    
    this->t_cloud_out = t_out * (double)this->return_parcel_alt_bot().rows();
    
    if (dove.getIntegrationType() == EXPLICIT)
        this->set_isTight(false);
}

int Crane::read_pjfnk_options(Dove &dove, yaml_cpp_class &yaml)
{
    int success = 0;
    
    krylov_method lin_method = QR;
    linesearch_type linesearch = BT;
    bool linear = false, precon = false, nl_out = false, l_out = false;
    int max_nlit = 10, max_lit = 100, restart = 10, recursive = 2;
    double nl_abstol = 1e-6, nl_reltol = 1e-6, l_abstol = 1e-6, l_reltol = 1e-6;
    
    try
    {
        std::string choice;
        choice = yaml.getYamlWrapper()("Solver_Options")["linear_method"].getString();
        lin_method = linearsolver_choice(choice);
    }
    catch (std::out_of_range)
    {
        lin_method = QR;
    }
    try
    {
        std::string choice;
        choice = yaml.getYamlWrapper()("Solver_Options")["line_search"].getString();
        linesearch = linesearch_choice(choice);
    }
    catch (std::out_of_range)
    {
        linesearch = BT;
    }
    try
    {
        linear = yaml.getYamlWrapper()("Solver_Options")["linear"].getBool();
    }
    catch (std::out_of_range)
    {
        linear = false;
    }
    try
    {
        precon = yaml.getYamlWrapper()("Solver_Options")["precondition"].getBool();
    }
    catch (std::out_of_range)
    {
        precon = false;
    }
    try
    {
        nl_out = yaml.getYamlWrapper()("Solver_Options")["nl_out"].getBool();
    }
    catch (std::out_of_range)
    {
        nl_out = false;
    }
    try
    {
        l_out = yaml.getYamlWrapper()("Solver_Options")["lin_out"].getBool();
    }
    catch (std::out_of_range)
    {
        l_out = false;
    }
    try
    {
        max_nlit = yaml.getYamlWrapper()("Solver_Options")["max_nl_iter"].getInt();
    }
    catch (std::out_of_range)
    {
        max_nlit = 10;
    }
    try
    {
        max_lit = yaml.getYamlWrapper()("Solver_Options")["max_lin_iter"].getInt();
    }
    catch (std::out_of_range)
    {
        max_lit = 100;
    }
    try
    {
        restart = yaml.getYamlWrapper()("Solver_Options")["restart_limit"].getInt();
    }
    catch (std::out_of_range)
    {
        restart = 100;
    }
    try
    {
        recursive = yaml.getYamlWrapper()("Solver_Options")["recursion_limit"].getInt();
    }
    catch (std::out_of_range)
    {
        recursive = 2;
    }
    try
    {
        nl_abstol = yaml.getYamlWrapper()("Solver_Options")["nl_abs_tol"].getDouble();
    }
    catch (std::out_of_range)
    {
        nl_abstol = 1e-6;
    }
    try
    {
        nl_reltol = yaml.getYamlWrapper()("Solver_Options")["nl_rel_tol"].getDouble();
    }
    catch (std::out_of_range)
    {
        nl_reltol = 1e-6;
    }
    try
    {
        l_abstol = yaml.getYamlWrapper()("Solver_Options")["lin_abs_tol"].getDouble();
    }
    catch (std::out_of_range)
    {
        l_abstol = 1e-6;
    }
    try
    {
        l_reltol = yaml.getYamlWrapper()("Solver_Options")["lin_rel_tol"].getDouble();
    }
    catch (std::out_of_range)
    {
        l_reltol = 1e-6;
    }
    
    this->establish_pjfnk_options(dove, lin_method, linesearch, linear, precon, nl_out, l_out, max_nlit, max_lit, restart, recursive, nl_abstol, nl_reltol, l_abstol, l_reltol);
    
    return success;
}

void Crane::establish_pjfnk_options(Dove &dove, krylov_method lin_method, linesearch_type linesearch, bool linear, bool precon, bool nl_out,
                                    bool l_out, int max_nlit, int max_lit, int restart, int recursive, double nl_abstol, double nl_reltol, double l_abstol, double l_reltol)
{
    dove.set_LinearMethod(lin_method);
    dove.set_LineSearchMethod(linesearch);
    dove.set_LinearStatus(linear);
    dove.set_Preconditioning(precon);
    dove.set_NonlinearOutput(nl_out);
    dove.set_LinearOutput(l_out);
    dove.set_MaxNonLinearIterations(max_nlit);
    dove.set_MaxLinearIterations(max_lit);
    dove.set_RestartLimit(restart);
    dove.set_RecursionLevel(recursive);
    dove.set_NonlinearAbsTol(nl_abstol);
    dove.set_NonlinearRelTol(nl_reltol);
    dove.set_LinearAbsTol(l_abstol);
    dove.set_LinearRelTol(l_reltol);
    dove.set_NonlinearOutput(false);
    dove.set_LinearOutput(false);
}

int Crane::read_wind_profile(yaml_cpp_class &yaml)
{
    int success = 0;
    this->delete_wind_profile();
    
    int num_data = 0;
    try
    {
        num_data = (int) yaml.getYamlWrapper()("Wind_Profile").getHeadMap().size();
    }
    catch (std::out_of_range)
    {
        num_data = 0;
    }
    if (num_data == 0)
    {
        std::cout << "WARNING!!! No wind profile data was given!\nUsing default wind profile instead...\n\n";
        this->create_default_wind_profile();
        return 0;
    }
    
    double vx = 0, vy = 0;
    for (auto &x: yaml.getYamlWrapper()("Wind_Profile").getHeadMap())
    {
        ValueTypePair alt;
        alt.editValue(x.first);
        alt.findType();
        if (alt.getType() != DOUBLE && alt.getType() != INT)
        {
            mError(read_error);
            std::cout << "Altitute not a number...\n";
            return -1;
        }
        
        try
        {
            vx = yaml.getYamlWrapper()("Wind_Profile")(x.first)["vx"].getDouble();
        }
        catch (std::out_of_range)
        {
            mError(missing_information);
            std::cout << "Velocity in x-direction missing!!!\n";
            return -1;
        }
        try
        {
            vy = yaml.getYamlWrapper()("Wind_Profile")(x.first)["vy"].getDouble();
        }
        catch (std::out_of_range)
        {
            mError(missing_information);
            std::cout << "Velocity in y-direction missing!!!\n";
            return -1;
        }
        
        this->add_wind_vel(alt.getDouble(), vx, vy);
    }
    
    return success;
}

void Crane::estimate_parameters(Dove &dove)
{
    this->compute_beta_prime(this->get_x_water_vapor(), this->get_s_soil(), this->get_w_water_conds());
    this->compute_q_x(this->get_x_water_vapor());
    
    this->compute_vert_rad(this->get_cloud_alt());
    
    double Te, P, HR;
    Matrix<double> v_top(2,1), v_bot(2,1);
    Te = this->return_amb_temp(this->get_cloud_alt());
    P = this->return_atm_press(this->get_cloud_alt());
    HR = this->return_rel_humid(this->get_cloud_alt());
    v_top = this->return_wind_vel(this->get_cloud_alt()+this->get_vert_rad());
    v_bot = this->return_wind_vel(this->get_cloud_alt()-this->get_vert_rad());
    
    this->set_current_amb_temp(Te);
    this->set_current_atm_press(P);
    this->compute_xe(Te, P, HR);
    
    if (this->get_temperature() >= 273.15)
        this->set_latent_heat(2.5E+6);
    else
        this->set_latent_heat(2.83E+6);
    
    //Call the compute functions that are not called by any other compute function (note these functions call other functions needed)
    this->compute_apparent_amb_temp(Te, this->get_xe());
    this->compute_vapor_pressure(P, this->get_x_water_vapor());
    this->compute_sat_vapor_pressure(this->get_temperature());
    this->compute_spec_heat_entrain_integral(this->get_temperature(), Te);
    this->compute_mean_spec_heat(this->get_temperature(), this->get_x_water_vapor(), this->get_s_soil(), this->get_w_water_conds());
    this->compute_sigma_turbulence(this->get_energy(), this->get_cloud_alt());
    this->compute_shear_ratio(this->get_cloud_mass(), this->get_x_water_vapor(), this->get_s_soil(), this->get_w_water_conds(), this->get_temperature(), P, this->get_cloud_alt(), this->get_cloud_rise(), this->get_energy(), v_top, v_bot);
    this->compute_total_mass_fallout_rate(this->get_cloud_mass(), this->get_x_water_vapor(), this->get_s_soil(), this->get_w_water_conds(), this->get_temperature(), P, this->get_cloud_alt(), this->get_part_conc_var());
    
    if (this->get_isSaturated() == false)
    {
        if (this->get_vapor_pressure() > this->get_sat_vapor_pressure())
        {
            this->set_isSaturated(true);
            if (this->get_saturation_time() <= 0.0)
                this->set_saturation_time(this->get_current_time());
        }
        else
            this->set_isSaturated(false);
    }
    
    if (this->get_isSolidified() == false)
    {
        if (this->get_temperature() <= this->get_solidification_temp())
        {
            this->set_isSolidified(true);
            if (this->get_solidification_time() <= 0.0)
                this->set_solidification_time(this->get_current_time());
        }
        else
            this->set_isSolidified(false);
    }
    
}

void Crane::perform_postprocessing(Dove &dove)
{
    this->compute_alt_top(this->get_cloud_alt(), this->get_vert_rad());
    this->compute_alt_bottom(this->get_cloud_alt(), this->get_vert_rad());
    this->compute_rise_top(this->get_alt_top(), this->get_alt_top_old(), dove.getTimeStep());
    this->compute_rise_bottom(this->get_alt_bottom(), this->get_alt_bottom_old(), dove.getTimeStep());
    
    //NOTE: Use settling_rate_old here because settling rate for next step has already been calculated
    double Uu_b = 0.0, Uu_t = 0.0;
    //Loop through i parcels
    for (int i=0; i<this->return_parcel_alt_top().rows(); i++)
    {
        //Loop through j particle sizes
        for (int j=0; j<this->return_parcel_alt_top().columns(); j++)
        {
            //Calculate old volume of each parcel
            double h = this->return_parcel_alt_top()(i,j) - this->return_parcel_alt_bot()(i,j);
            double Rtop = this->return_parcel_rad_top()(i,j);
            double Rbot = this->return_parcel_rad_bot()(i,j);
            double Vol_old = (M_PI*h/3.0)*(Rtop*Rtop+Rbot*Rtop+Rbot*Rbot);
            
            //Inside Cloud Cap for bottom of parcel
            if (this->return_parcel_alt_bot()(i,j) > this->get_alt_bottom())
            {
                Uu_b = this->get_rise_bottom() + ((this->return_parcel_alt_bot()(i,j)-this->get_alt_bottom())*(this->get_rise_top()-this->get_rise_bottom())/(this->get_alt_top()-this->get_alt_bottom()));
            }
            //Below Cloud Cap for bottom of parcel
            else
            {
                Uu_b = this->get_rise_bottom() * (1.0 - ((this->get_alt_bottom()-this->return_parcel_alt_bot()(i,j))/(this->get_alt_bottom()-this->get_ground_alt())));
            }
            
            //Inside Cloud Cap for top of parcel
            if (this->return_parcel_alt_top()(i,j) > this->get_alt_bottom())
            {
                Uu_t = this->get_rise_bottom() + ((this->return_parcel_alt_top()(i,j)-this->get_alt_bottom())*(this->get_rise_top()-this->get_rise_bottom())/(this->get_alt_top()-this->get_alt_bottom()));
            }
            //Below Cloud Cap for top of parcel
            else
            {
                Uu_t = this->get_rise_bottom() * (1.0 - ((this->get_alt_bottom()-this->return_parcel_alt_top()(i,j))/(this->get_alt_bottom()-this->get_ground_alt())));
            }
            
            //Calculate the new altitudes for top and bottom of the parcel
            double new_zj_t = this->return_parcel_alt_top()(i,j) + (dove.getTimeStep()*(Uu_t-this->get_settling_rate_old(this->get_part_size(j))));
            double new_zj_b = this->return_parcel_alt_bot()(i,j) + (dove.getTimeStep()*(Uu_b-this->get_settling_rate_old(this->get_part_size(j))));
            
            if (new_zj_b <= this->get_ground_alt()) new_zj_b = this->get_ground_alt();
            if (new_zj_t <= new_zj_b) new_zj_t = new_zj_b + 1.0;
            
            this->return_parcel_alt_top().edit(i, j, new_zj_t);
            this->return_parcel_alt_bot().edit(i, j, new_zj_b);
            
            //	Update the top and bottom radii of the parcels
            // Bottom radius
            double mult = (1.0 - ( ((new_zj_b-this->get_cloud_alt())*(new_zj_b-this->get_cloud_alt()))/(this->get_vert_rad()*this->get_vert_rad()) ));
            if (mult < 0.0 + sqrt(DBL_EPSILON))	mult = 0.0;
            double r_b = sqrt( this->get_horz_rad()*this->get_horz_rad()*mult );
            
            // Top radius
            mult = (1.0 - ( ((new_zj_t-this->get_cloud_alt())*(new_zj_t-this->get_cloud_alt()))/(this->get_vert_rad()*this->get_vert_rad()) ));
            if (mult < 0.0 + sqrt(DBL_EPSILON))	mult = 0.0;
            double r_t = sqrt( this->get_horz_rad()*this->get_horz_rad()*mult );
            
            if (r_b < 0.0 + sqrt(DBL_EPSILON)) r_b = (0.45*r_b+0.55*r_t);
            if (r_t < 0.0 + sqrt(DBL_EPSILON)) r_t = (0.55*r_b+0.45*r_t);
            
            //Inside Cloud Cap for bottom of parcel
            if (this->return_parcel_alt_bot()(i,j) >= this->get_alt_bottom())
            {
                if (this->return_parcel_rad_bot()(i,j) < r_b)
                    this->return_parcel_rad_bot().edit(i, j, r_b);
            }
            //Below Cloud Cap for bottom of parcel
            else
            {
                //No update (keeps old radius)
            }
            
            //Inside Cloud Cap for top of parcel
            if (this->return_parcel_alt_top()(i,j) >= this->get_alt_bottom())
            {
                if (this->return_parcel_rad_top()(i,j) < r_t)
                    this->return_parcel_rad_top().edit(i, j, r_t);
            }
            //Below Cloud Cap for top of parcel
            else
            {
                //No update (keeps old radius)
            }
            
            //Now update particle concentrations
            //Calculate old volume of each parcel
            h = this->return_parcel_alt_top()(i,j) - this->return_parcel_alt_bot()(i,j);
            if (h <= 0.0) h = 0.0;
            Rtop = this->return_parcel_rad_top()(i,j);
            Rbot = this->return_parcel_rad_bot()(i,j);
            double Vol_new = (M_PI*h/3.0)*(Rtop*Rtop+Rbot*Rtop+Rbot*Rbot);
            if (Vol_new <= 0.0)
                this->return_parcel_conc().edit(i, j, 0.0);
            else
                this->return_parcel_conc().edit(i, j, this->return_parcel_conc()(i,j)*Vol_old/Vol_new);
            
        }
        
    }
    
    this->set_alt_top_old(this->get_alt_top());
    this->set_alt_bottom_old(this->get_alt_bottom());
}

void Crane::store_variables(Dove &dove)
{
    if ( dove.getNewU()(dove.getVariableIndex("m (Gg)"), 0) < 0.0)
    {
        dove.getNewU()(dove.getVariableIndex("m (Gg)"), 0) = dove.getCurrentU()(dove.getVariableIndex("m (Gg)"), 0);
    }
    if ( dove.getNewU()(dove.getVariableIndex("x (kg/kg)"), 0) < 0.0)
    {
        dove.getNewU()(dove.getVariableIndex("x (kg/kg)"), 0) = dove.getCurrentU()(dove.getVariableIndex("x (kg/kg)"), 0);
    }
    if ( dove.getNewU()(dove.getVariableIndex("w (kg/kg)"), 0) < 0.0)
    {
        dove.getNewU()(dove.getVariableIndex("w (kg/kg)"), 0) = dove.getCurrentU()(dove.getVariableIndex("w (kg/kg)"), 0);
    }
    if ( dove.getNewU()(dove.getVariableIndex("s (kg/kg)"), 0) < 0.0)
    {
        dove.getNewU()(dove.getVariableIndex("s (kg/kg)"), 0) = dove.getCurrentU()(dove.getVariableIndex("s (kg/kg)"), 0);
    }
    if ( dove.getNewU()(dove.getVariableIndex("T (K)"), 0) < 0.0)
    {
        dove.getNewU()(dove.getVariableIndex("T (K)"), 0) = dove.getCurrentU()(dove.getVariableIndex("T (K)"), 0);
    }
    if ( dove.getNewU()(dove.getVariableIndex("E (J/kg)"), 0) < 0.0)
    {
        dove.getNewU()(dove.getVariableIndex("E (J/kg)"), 0) = dove.getCurrentU()(dove.getVariableIndex("E (J/kg)"), 0);
    }
    
    for (int i=0; i<this->part_conc_var.rows(); i++)
    {
        this->settling_rate_old[this->get_part_size(i)] = this->get_settling_rate(this->get_part_size(i));
        double rate = M_PI*this->get_horz_rad()*this->get_horz_rad()*this->get_settling_rate(this->get_part_size(i))/this->get_cloud_volume();
        this->part_conc_var(i,0) = this->part_conc_var(i,0)*exp(-rate*dove.getTimeStep());
        this->part_conc[this->get_part_size(i)] = this->part_conc_var(i,0);
    }
    
    this->set_current_time(dove.getCurrentTime());
    this->set_cloud_mass( fabs( dove.getNewU("m (Gg)", dove.getNewU()) ) );
    this->set_cloud_rise( dove.getNewU("u (m/s)", dove.getNewU()) );
    this->set_cloud_alt( dove.getNewU("z (m)", dove.getNewU()) );
    this->set_x_water_vapor( fabs( dove.getNewU("x (kg/kg)", dove.getNewU()) ) );
    if (this->get_isSaturated() == false)
        dove.getNewU()(dove.getVariableIndex("w (kg/kg)"),0) = 0.0;
    this->set_w_water_conds( fabs( dove.getNewU("w (kg/kg)", dove.getNewU()) ) );
    this->set_s_soil( fabs( dove.getNewU("s (kg/kg)", dove.getNewU()) ) );
    this->set_temperature( fabs( dove.getNewU("T (K)", dove.getNewU()) ) );
    this->set_energy( fabs( dove.getNewU("E (J/kg)", dove.getNewU()) ) );
    
    double Rc_old = this->get_horz_rad();
    double P = this->return_atm_press(this->get_cloud_alt());
    this->compute_horz_rad(this->get_cloud_mass(), this->get_x_water_vapor(), this->get_s_soil(), this->get_w_water_conds(), this->get_temperature(), P, this->get_cloud_alt());
    this->set_horz_rad_change(Rc_old - this->get_horz_rad());
    
}

void Crane::print_header(Dove &dove)
{
    fprintf(dove.getFile(), "\tV (m^3)\tHc (m)\tRc (m)");
    fprintf(dove.getFile(), "\tz_b (m)\tz_t (m)");
    fprintf(dove.getFile(), "\tu_b (m/s)\tu_t (m/s)");
    
    fprintf(dove.getFile(), "\n");
}

void Crane::print_information(Dove &dove, bool initialPhase)
{
    
    if (initialPhase == true)
    {
        //Print to standard output file
        fprintf(dove.getFile(), "\t%.6g\t%.6g\t%.6g", this->get_cloud_volume(), this->get_vert_rad(), this->get_horz_rad());
        fprintf(dove.getFile(), "\t%.6g\t%.6g", this->get_alt_bottom(), this->get_alt_top());
        fprintf(dove.getFile(), "\t%.6g\t%.6g", this->get_rise_bottom(), this->get_rise_top());
        
        fprintf(dove.getFile(), "\n");
        
        //Print to cloud growth file
        fprintf(this->CloudFile, "Time (s) = \t%.6g\n",this->get_current_time());
        for (int j=0; j<this->return_parcel_alt_top().columns(); j++)
        {
            fprintf(this->CloudFile, "R_%i\tz_%i\t", j, j);
        }
        fprintf(this->CloudFile, "\n");
        
        for (int j = 0; j<this->return_parcel_alt_top().columns(); j++)
        {
            fprintf(this->CloudFile, "%.6g\t%.6g\t", this->return_parcel_rad_bot()(0, j), this->return_parcel_alt_bot()(0, j));
        }
        fprintf(this->CloudFile, "\n");
        for (int i=0; i<this->return_parcel_alt_top().rows(); i++)
        {
            for (int j=0; j<this->return_parcel_alt_top().columns(); j++)
            {
                fprintf(this->CloudFile, "%.6g\t%.6g\t", this->return_parcel_rad_top()(i,j),	this->return_parcel_alt_top()(i,j));
            }
            fprintf(this->CloudFile, "\n");
        }
    }
    else
    {
        this->t_cloud_count = this->t_cloud_count + dove.getTimeStep();
        
        if (this->t_cloud_count >= (this->t_cloud_out + sqrt(DBL_EPSILON))
            || this->t_cloud_count >= (this->t_cloud_out - sqrt(DBL_EPSILON))
            || dove.getCurrentTime() == dove.getEndTime())
        {
            //Print to cloud growth file
            fprintf(this->CloudFile, "\n");
            fprintf(this->CloudFile, "Time (s) = \t%.6g\n", this->get_current_time());
            for (int j = 0; j<this->return_parcel_alt_top().columns(); j++)
            {
                fprintf(this->CloudFile, "R_%i\tz_%i\t", j, j);
            }
            fprintf(this->CloudFile, "\n");
            
            for (int j = 0; j<this->return_parcel_alt_top().columns(); j++)
            {
                fprintf(this->CloudFile, "%.6g\t%.6g\t", this->return_parcel_rad_bot()(0, j), this->return_parcel_alt_bot()(0, j));
            }
            fprintf(this->CloudFile, "\n");
            for (int i = 0; i<this->return_parcel_alt_top().rows(); i++)
            {
                for (int j = 0; j<this->return_parcel_alt_top().columns(); j++)
                {
                    fprintf(this->CloudFile, "%.6g\t%.6g\t", this->return_parcel_rad_top()(i, j), this->return_parcel_alt_top()(i, j));
                }
                fprintf(this->CloudFile, "\n");
            }
            this->t_cloud_count = 0.0;
        }
        
        this->t_count = this->t_count + dove.getTimeStep();
        
        if (this->t_count >= (dove.getOutputTime()+sqrt(DBL_EPSILON))
            || this->t_count >= (dove.getOutputTime()-sqrt(DBL_EPSILON))
            || dove.getCurrentTime() == dove.getEndTime())
        {
            //Print to standard output file
            fprintf(dove.getFile(), "\t%.6g\t%.6g\t%.6g", this->get_cloud_volume(), this->get_vert_rad(), this->get_horz_rad());
            fprintf(dove.getFile(), "\t%.6g\t%.6g", this->get_alt_bottom(), this->get_alt_top());
            fprintf(dove.getFile(), "\t%.6g\t%.6g", this->get_rise_bottom(), this->get_rise_top());
            
            fprintf(dove.getFile(), "\n");
            this->t_count = 0.0;
        }
    }
    
}

int Crane::run_crane_simulation(Dove &dove)
{
    int success = 0;
    
    dove.reset_all();
    
    if (this->get_FileOut() == true)
    {
        dove.print_header(false);
        this->print_header(dove);
        dove.print_result(false);
        this->print_information(dove, true);
    }
    if (this->get_ConsoleOut() == true)
    {
        std::cout << "\nDove Scheme: ";
        switch (dove.getIntegrationMethod())
        {
            case BE:
                std::cout << "Backwards-Euler method.";
                break;
                
            case FE:
                std::cout << "Forwards-Euler method.";
                break;
                
            case CN:
                std::cout << "Crank-Nicholson method. ";
                break;
                
            case BDF2:
                std::cout << "Backwards-Differentiation 2nd Order method.";
                break;
                
            case RK4:
                std::cout << "Runge-Kutta 4th Order method.";
                break;
                
            case RKF:
                std::cout << "Runge-Kutta-Fehlberg method.";
                break;
                
            default:
                std::cout << "Backwards-Euler method.";
                break;
                
        }
        std::cout << "\n------------------------------------------------------";
    }
    
    //Do-while loop
    this->estimate_parameters(dove);
    double percent_comp = 0.0;
    double print_comp = 0.0;
    if (this->get_ConsoleOut() == true)
        std::cout << "\nPercent Completion...\n";
    do
    {
        percent_comp = (dove.getCurrentTime() - dove.getStartTime()) / (dove.getEndTime() - dove.getStartTime());
        
        if ( (percent_comp - print_comp) >= 0.0)
        {
            print_comp = print_comp + 0.1;
            
            if (this->get_ConsoleOut() == true)
                std::cout << "\t[" << (int)(percent_comp*100.0) << " %]\n";
        }
        
        dove.update_timestep();
        success = dove.solve_timestep();
        if (success != 0)
        {
            mError(simulation_fail);
            return -1;
        }
        
        this->store_variables(dove);
        this->estimate_parameters(dove);
        this->perform_postprocessing(dove);
        if (this->get_FileOut() == true)
        {
            dove.print_newresult(false);
            this->print_information(dove, false);
        }
        dove.update_states();
        
        //Check for early termination
        if (this->get_cloud_rise() <= 0.0 && this->get_energy() < this->get_energy_switch())
        {
            if (this->get_ConsoleOut() == true)
                std::cout << "Cloud has stabilized at " << this->get_current_time() << " (s)... Ending Early...\n";
            dove.set_endtime(this->get_current_time());
            this->set_stabilization_time(this->get_current_time());
            if (this->get_FileOut() == true)
            {
                dove.print_newresult(false);
                this->print_information(dove, false);
            }
            
            break;
        }
        if (this->get_cloud_rise() <= 0.0 && fabs(this->get_horz_rad_change()) <= (dove.getTimeStep()*this->get_horz_rad()*pow(this->get_bomb_yield(), 0.014778)/1153.0) )
        {
            if (this->get_ConsoleOut() == true)
                std::cout << "Cloud has stopped expanding at " << this->get_current_time() << " (s)... Ending Early...\n";
            dove.set_endtime(this->get_current_time());
            if (this->get_FileOut() == true)
            {
                dove.print_newresult(false);
                this->print_information(dove, false);
            }
            
            break;
        }
        
    } while (dove.getEndTime() > (dove.getCurrentTime()+dove.getMinTimeStep()) );
    
    if (this->get_ConsoleOut() == true)
        std::cout << "\t[100 %]\n\n";
    
    return success;
}

/*
 *	-------------------------------------------------------------------------------------
 *								End: Crane Class Definitions
 */

//CRANE executable scenario
int CRANE_SCENARIO(const char *yaml_input, const char *atmosphere_data)
{
    int success = 0;
    double time;
    
    Crane crane;
    Dove dove;
    yaml_cpp_class yaml;
    time = clock();
    
    FILE *file, *cloud;
    file = fopen("output/CRANE_Results.txt", "w+");
    cloud = fopen("output/CRANE_CloudGrowth.txt", "w+");
    if (file == nullptr)
    {
        system("mkdir output");
        file = fopen("output/CRANE_Results.txt", "w+");
    }
    if (cloud == nullptr)
    {
        system("mkdir output");
        cloud = fopen("output/CRANE_CloudGrowth.txt", "w+");
    }
    crane.set_CloudFile(cloud);
    
    std::cout << "\n";
    
    //Execule yaml read of input file
    success = yaml.executeYamlRead(yaml_input);
    if (success != 0) {mError(file_dne); return -1;}
    
    //Read in the atmosphere data (if file exists)
    success = crane.read_atmosphere_profile(atmosphere_data);
    if (success != 0) {mError(read_error); return -1;}
    
    //Read in Simulation_Options
    success = crane.read_conditions(dove, yaml);
    if (success != 0) {mError(read_error); return -1;}
    
    std::cout << "\nCRANE SIMULATION CONDITIONS\n";
    std::cout <<   "---------------------------\n\n";
    std::cout << "Shear Velocity          = \t";
    if (crane.get_includeShearVel() == true)
        std::cout << "True\n";
    else
        std::cout << "False\n";
    std::cout << "Bomb Yield (kT)         =\t" << crane.get_bomb_yield() << std::endl;
    std::cout << "Burst Height (m)        =\t" << crane.get_burst_height() << std::endl;
    std::cout << "Ground Altitude (m)     =\t" << crane.get_ground_alt() << std::endl;
    std::cout << "Initial Time (s)        =\t" << crane.get_current_time() << std::endl;
    std::cout << "Number of air parcels   =\t" << crane.return_parcel_alt_top().rows() << std::endl;
    std::cout << "Number of particle bins = \t" << crane.return_parcel_alt_top().columns() << std::endl;
    crane.display_part_hist();
    std::cout << "Soil Solid. Temp. (K)   =\t" << crane.get_solidification_temp() << std::endl;
    std::cout << "Soil Vapor. Temp. (K)   =\t" << crane.get_vaporization_temp() << std::endl;
    std::cout << "Vaporized Soil (kg)     =\t" << crane.get_initial_soil_vapor() << std::endl;
    crane.display_soil_characteristics();
    std::cout << "\n";
    
    //Read in ODE_Options
    success = crane.read_dove_options(dove, file, yaml);
    if (success != 0) {mError(read_error); return -1;}
    
    //Read in Solver_Options
    success = crane.read_pjfnk_options(dove, yaml);
    if (success != 0) {mError(read_error); return -1;}
    
    //Read in Wind_Profile
    success = crane.read_wind_profile(yaml);
    if (success != 0) {mError(read_error); return -1;}
    
    //Run simulation case
    std::cout << "\nInitial Conditions for Non-linear Variables\n";
    std::cout <<   "-------------------------------------------\n\n";
    crane.estimate_parameters(dove);
    for (int i=0; i<8; i++)
    {
        std::cout << dove.getVariableName(i) << " =\t " << dove.getNewU(i, dove.getNewU()) << std::endl;
    }
    
    crane.run_crane_simulation(dove);
    
    std::cout << "\nFinal Results for Non-linear Variables\n";
    std::cout <<   "---------------------------------------\n\n";
    for (int i=0; i<8; i++)
    {
        std::cout << dove.getVariableName(i) << " =\t " << dove.getNewU(i, dove.getNewU()) << std::endl;
    }
    
    std::cout << "\nSaturation Time (s)     =\t";
    if (crane.get_saturation_time() > 0.0)
        std::cout << crane.get_saturation_time() << std::endl;
    else
        std::cout << "Unsaturated\n";
    std::cout << "Solidification Time (s) =\t";
    if (crane.get_saturation_time() > 0.0)
        std::cout << crane.get_solidification_time() << std::endl;
    else
        std::cout << "Unsolidified\n";
    
    time = clock() - time;
    std::cout << "\nCRANE Runtime: " << (time / CLOCKS_PER_SEC) << " seconds\n";
    
    if (file!= nullptr)
        fclose(file);
    if (cloud!=nullptr)
        fclose(cloud);
    
    return success;
}

//Test function
int CRANE_TESTS()
{
    int success = 0;
    double time;
    
    Crane test;
    Dove dove;
    time = clock();
    
    FILE *file, *cloud;
    file = fopen("output/CRANE_Tests.txt", "w+");
    cloud = fopen("output/CRANE_Tests_CloudGrowth.txt", "w+");
    if (file == nullptr)
    {
        system("mkdir output");
        file = fopen("output/CRANE_Tests.txt", "w+");
    }
    if (cloud == nullptr)
    {
        system("mkdir output");
        cloud = fopen("output/CRANE_Tests_CloudGrowth.txt", "w+");
    }
    test.set_CloudFile(cloud);
    
    // Nevada Plumbbob Boltzman Test Case
    //double W = 12.0; //12 kT
    //double hb = 500.0*0.3048;// 500 ft
    //double gz = 1155; //1155 m (Nevada Test Site)
    
    //V. Jodoin Test Case from 1994 Thesis
    double W = 50.0; //50 kT
    double hb = 0.0;// 0 m
    double gz = 500.0; //500 m
    
    //Tsar Bomb (Cloud rise not calibrated for Megaton yields)
    //double W = 50000.0; //50 MT
    //double hb = 4000.0;// 4000 m
    //double gz = 200.0; //200 m
    
    //Bravo Test Case (no data available)
    //double W = 15000.0; //15 MT
    //double hb = 2.13;// 2.13 m
    //double gz = 1000.0; //1000 m?
    
    int bins = 10;
    bool includeShear = true;
    bool isTight = true;
    
    test.add_soil_component("SiO2", 0.75);
    //test.add_soil_component("CaO", 0.25);
    
    test.establish_initial_conditions(dove, W, gz, hb, bins, includeShear, isTight);
    
    std::cout << "\nTesting of the CRANE for the 1979 DELFIC Test Case with Default Atmosphere\n";
    std::cout <<   "--------------------------------------------------------------------------\n\n";
    std::cout << "Shear Velocity          = \t";
    if (includeShear == true)
        std::cout << "True\n";
    else
        std::cout << "False\n";
    std::cout << "Bomb Yield (kT)         =\t" << W << std::endl;
    std::cout << "Burst Height (m)        =\t" << hb << std::endl;
    std::cout << "Ground Altitude (m)     =\t" << gz << std::endl;
    std::cout << "Initial Time (s)        =\t" << test.get_current_time() << std::endl;
    std::cout << "Number of air parcels   =\t" << test.return_parcel_alt_top().rows() << std::endl;
    std::cout << "Number of particle bins =\t" << test.return_parcel_alt_top().columns() << std::endl;
    test.display_part_hist();
    std::cout << "Soil Solid. Temp. (K)   =\t" << test.get_solidification_temp() << std::endl;
    std::cout << "Soil Vapor. Temp. (K)   =\t" << test.get_vaporization_temp() << std::endl;
    std::cout << "Vaporized Soil (kg)     =\t" << test.get_initial_soil_vapor() << std::endl;
    test.display_soil_characteristics();
    std::cout << "\n";
    
    bool fileout = true;
    bool consoleout = false;
    double tol = 0.1;
    double dtmin = 1e-8;
    double dtmax = 0.1; //ABS MAX!!! Beyond this point the numerical errors become too large...
    double dtmin_conv = 0.0001;
    double t_out = 1.0;
    double endtime = 1000.0;
    
    test.establish_dove_options(dove, file, fileout, consoleout, BDF2, ADAPTIVE, SGS, tol, dtmin, dtmax, dtmin_conv, t_out, endtime);
    
    bool isLinear = false;
    bool isPrecon = false;
    bool nl_out = true;
    bool l_out = false;
    int max_nlit = 50;
    int max_lit = 200;
    int restart = 20;
    int recursive = 2;
    double nl_abstol = 1e-6;
    double nl_reltol = 1e-6;
    double l_abstol = 1e-6;
    double l_reltol = 1e-4;
    
    test.establish_pjfnk_options(dove, QR, BT, isLinear, isPrecon, nl_out, l_out, max_nlit, max_lit, restart, recursive, nl_abstol, nl_reltol, l_abstol, l_reltol);
    
    
    std::cout << "\nInitial Conditions for Non-linear Variables\n";
    std::cout <<   "-------------------------------------------\n\n";
    test.estimate_parameters(dove);
    for (int i=0; i<8; i++)
    {
        std::cout << dove.getVariableName(i) << " =\t " << dove.getNewU(i, dove.getNewU()) << std::endl;
    }
    test.display_part_conc();
    
    test.run_crane_simulation(dove);
    
    std::cout << "\nFinal Results for Non-linear Variables\n";
    std::cout <<   "---------------------------------------\n\n";
    for (int i=0; i<8; i++)
    {
        std::cout << dove.getVariableName(i) << " =\t " << dove.getNewU(i, dove.getNewU()) << std::endl;
    }
    test.display_part_conc();
    
    //test.return_parcel_alt_top().Display("z_t");
    //test.return_parcel_alt_bot().Display("z_b");
    //test.return_parcel_rad_top().Display("R_t");
    //test.return_parcel_rad_bot().Display("R_b");
    
    //test.return_parcel_conc().Display("C_ij");
    
    std::cout << "\nSaturation Time (s)     =\t";
    if (test.get_saturation_time() > 0.0)
        std::cout << test.get_saturation_time() << std::endl;
    else
        std::cout << "Unsaturated\n";
    std::cout << "Solidification Time (s) =\t";
    if (test.get_saturation_time() > 0.0)
        std::cout << test.get_solidification_time() << std::endl;
    else
        std::cout << "Unsolidified\n";
    
    time = clock() - time;
    std::cout << "\nTest Runtime: " << (time / CLOCKS_PER_SEC) << " seconds\n";
    
    if (file!= nullptr)
        fclose(file);
    if (cloud!=nullptr)
        fclose(cloud);
    
    return success;
}
