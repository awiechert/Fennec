/*!
 *  \file ibis.h ibis.cpp
 *	\brief Implicit Branching Isotope System
 *  \author Austin Ladshaw
 *	\date 09/04/2018
 *	\copyright This software was designed and built at the Georgia Institute
 *             of Technology by Austin Ladshaw for research in the area
 *             of radioactive particle decay. Copyright (c) 2018, all
 *             rights reserved.
 */

#include "ibis.h"

/// Function to convert from a starting unit and value to and ending unit and value (returns converted value)
double time_conversion(time_units end_unit, double start_value, time_units start_unit)
{
    double end_value = 0.0;
    
    switch (end_unit)
    {
        case seconds:
            switch (start_unit)
        {
            case seconds:
                end_value = start_value;
                break;
                
            case minutes:
                end_value = start_value * 60.0;
                break;
                
            case hours:
                end_value = start_value * 60.0 * 60.0;
                break;
                
            case days:
                end_value = start_value * 60.0 * 60.0 * 24.0;
                break;
                
            case years:
                end_value = start_value * 60.0 * 60.0 * 24.0 * 365.25;
                break;
                
            default:
                end_value = start_value;
                break;
        }
            break;
            
        case minutes:
            switch (start_unit)
        {
            case seconds:
                end_value = start_value / 60.0;
                break;
                
            case minutes:
                end_value = start_value;
                break;
                
            case hours:
                end_value = start_value * 60.0;
                break;
                
            case days:
                end_value = start_value * 60.0 * 24.0;
                break;
                
            case years:
                end_value = start_value * 60.0 * 24.0 * 365.25;
                break;
                
            default:
                end_value = start_value;
                break;
        }
            break;
            
        case hours:
            switch (start_unit)
        {
            case seconds:
                end_value = start_value / 60.0 / 60.0;
                break;
                
            case minutes:
                end_value = start_value / 60.0;
                break;
                
            case hours:
                end_value = start_value;
                break;
                
            case days:
                end_value = start_value * 24.0;
                break;
                
            case years:
                end_value = start_value * 24.0 * 365.25;
                break;
                
            default:
                end_value = start_value;
                break;
        }
            break;
            
        case days:
            switch (start_unit)
        {
            case seconds:
                end_value = start_value / 60.0 / 60.0 / 24.0;
                break;
                
            case minutes:
                end_value = start_value / 60.0 / 24.0;
                break;
                
            case hours:
                end_value = start_value / 24.0;
                break;
                
            case days:
                end_value = start_value;
                break;
                
            case years:
                end_value = start_value * 365.25;
                break;
                
            default:
                end_value = start_value;
                break;
        }
            break;
            
        case years:
            switch (start_unit)
        {
            case seconds:
                end_value = start_value / 60.0 / 60.0 / 24.0 / 365.25;
                break;
                
            case minutes:
                end_value = start_value / 60.0 / 24.0 / 365.25;
                break;
                
            case hours:
                end_value = start_value / 24.0 / 365.25;
                break;
                
            case days:
                end_value = start_value / 365.25;
                break;
                
            case years:
                end_value = start_value;
                break;
                
            default:
                end_value = start_value;
                break;
        }
            break;
            
        default:
            end_value = start_value;
            break;
    }
    
    return end_value;
}

//Pick out time units
time_units timeunits_choice(std::string &choice)
{
    time_units units = seconds;
    
    std::string copy = choice;
    for (int i=0; i<copy.size(); i++)
        copy[i] = tolower(copy[i]);
    
    if (copy == "seconds" || copy == "s")
        units = seconds;
    else if (copy == "minutes" || copy == "min")
        units = minutes;
    else if (copy == "hours" || copy == "hr" || copy == "h")
        units = hours;
    else if (copy == "days" || copy == "d")
        units = days;
    else if (copy == "years" || copy == "yr" || copy == "y")
        units = years;
    else
        units = seconds;
    
    return units;
}

//Pick decay mode
decay_mode decaymode_choice(std::string &choice)
{
    decay_mode mode = stable;
    
    std::string copy = choice;
    for (int i=0; i<copy.size(); i++)
        copy[i] = tolower(copy[i]);
    
    if (copy == "stable")
        mode = stable;
    else if (copy == "alpha")
        mode = alpha;
    else if (copy == "spontaneous-fission")
        mode = spon_fiss;
    else if (copy == "beta+")
        mode = beta_plus;
    else if (copy == "beta-")
        mode = beta_min;
    else if (copy == "isomeric-transition")
        mode = iso_trans;
    else if (copy == "neutron-emission")
        mode = neutron_em;
    else if (copy == "beta-/neutron-emission")
        mode = beta_min_neutron_em;
    else if (copy == "beta+/proton-emission")
        mode = beta_plus_proton_em;
    else if (copy == "proton-emission")
        mode = proton_em;
    else if (copy == "beta+/alpha")
        mode = beta_plus_alpha;
    else if (copy == "beta+/beta+")
        mode = beta_plus_beta_plus;
    else if (copy == "beta-/beta-")
        mode = beta_min_beta_min;
    else if (copy == "beta-/neutron-emission/neutron-emission")
        mode = beta_min_2neutron_em;
    else if (copy == "beta-/alpha")
        mode = beta_min_alpha;
    else if (copy == "proton-emission/proton-emission")
        mode = proton_em_proton_em;
    else if (copy == "neutron-emission/neutron-emission")
        mode = neutron_em_neutron_em;
    else if (copy == "beta-/neutron-emission/neutron-emission/neutron-emission")
        mode = beta_min_3neutron_em;
    else if (copy == "beta-/neutron-emission/neutron-emission/neutron-emission/neutron-emission")
        mode = beta_min_4neutron_em;
    else if (copy == "beta+/proton-emission/proton-emission")
        mode = beta_plus_2proton_em;
    else if (copy == "beta+/proton-emission/proton-emission/proton-emission")
        mode = beta_plus_3proton_em;
    else if (copy == "specific-isotope")
        mode = specific_isotope;
    else if (copy == "undefined")
        mode = undefined;
    else
        mode = stable;
    
    return mode;
}

// Return name of mode
std::string decaymode_string(decay_mode mode)
{
    std::string name = "stable";
    
    switch (mode)
    {
        case stable:
            name = "stable";
            break;
            
        case alpha:
            name = "alpha";
            break;
            
        case spon_fiss:
            name = "spontaneous-fission";
            break;
            
        case beta_plus:
            name = "beta+";
            break;
            
        case beta_min:
            name = "beta-";
            break;
            
        case iso_trans:
            name = "isomeric-transition";
            break;
            
        case neutron_em:
            name = "neutron-emission";
            break;
            
        case beta_min_neutron_em:
            name = "beta-/neutron-emission";
            break;
            
        case beta_plus_proton_em:
            name = "beta+/proton-emission";
            break;
            
        case proton_em:
            name = "proton-emission";
            break;
            
        case beta_plus_alpha:
            name = "beta+/alpha";
            break;
            
        case beta_plus_beta_plus:
            name = "beta+/beta+";
            break;
            
        case beta_min_beta_min:
            name = "beta-/beta-";
            break;
            
        case beta_min_2neutron_em:
            name = "beta-/neutron-emission/neutron-emission";
            break;
            
        case beta_min_alpha:
            name = "beta-/alpha";
            break;
            
        case proton_em_proton_em:
            name = "proton-emission/proton-emission";
            break;
            
        case neutron_em_neutron_em:
            name = "neutron-emission/neutron-emission";
            break;
            
        case beta_min_3neutron_em:
            name = "beta-/neutron-emission/neutron-emission/neutron-emission";
            break;
            
        case beta_min_4neutron_em:
            name = "beta-/neutron-emission/neutron-emission/neutron-emission/neutron-emission";
            break;
            
        case beta_plus_2proton_em:
            name = "beta+/proton-emission/proton-emission";
            break;
            
        case beta_plus_3proton_em:
            name = "beta+/proton-emission/proton-emission/proton-emission";
            break;
            
        case specific_isotope:
            name = "specific-isotope";
            break;
            
        case undefined:
            name = "undefined";
            break;
            
        default:
            break;
    }
    
    return name;
}

// String of units
std::string timeunits_string(time_units units)
{
    std::string name = "seconds";
    
    switch (units)
    {
        case seconds:
            name = "seconds";
            break;
            
        case minutes:
            name = "minutes";
            break;
            
        case hours:
            name = "hours";
            break;
            
        case days:
            name = "days";
            break;
            
        case years:
            name = "years";
            break;
            
        default:
            break;
    }
    
    return name;
}

// Empirical formulation of the Fermi Function
double EmpFermi(int z, double W)
{
    double F = 0.0;
    double A = 0.0; double B = 0.0;
    
    if (z >= 16)
        A = 1.0 + 0.40456*exp(0.073184*(double)z);
    else
        A = 0.073*(double)z + 0.94;
    
    if (z > 56)
        B = 1.2277E-3*(double)z*exp(0.10122*(double)z);
    else
        B = 5.5465E-3*(double)z*exp(0.076929*(double)z);
    
    F = sqrt(A + (B/(W-1.0)));
    
    return F;
}

// Empirical formulation of the Shape Function
double EmpShape(int L, double W0, double W)
{
    if (L <= 0) L = 1;
    return pow((W0 - W),2.0*((double)L - 1.0));
}

// Distribution of beta energy function
double DistEnergy(int z, int L, double W0, double W)
{
    return sqrt(W*W-1.0)*W*(W0-W)*(W0-W)*EmpFermi(z, W)*EmpShape(L, W0, W);
}

// Stepwise integration for average energy
double MeanEnergy_Stepwise(int z, int L, double E0)
{
    if (E0 <= 0.0) return 0.0;
    double top = 0.0;
    double bot = 0.0;
    double dW = E0/10.0;
    double En = 0.0001;
    double Enp1 = 0.0001;
    double W0 = 1.0 + E0;
    
    for (int i=0; i<10; i++)
    {
        En = Enp1;
        Enp1 = En + dW;
        
        double Wn = En + 1.0;
        double Wnp1 = Enp1 + 1.0;
        
        top += 0.5*(En+Enp1)*0.5*(DistEnergy(z, L, W0, Wn)+DistEnergy(z, L, W0, Wnp1))*(Enp1-En);
        bot += 0.5*(DistEnergy(z, L, W0, Wn)+DistEnergy(z, L, W0, Wnp1))*(Enp1-En);
    }
    
    return top/bot;
}

// Auxillary Function for beta-
double aux_beta_minus(double beta, double eta, double tau)
{
    double sqbrack = 0.5*tau*tau*eta*eta + (2.0*tau + 1.0)*log(1.0-eta);
    double G = -1.0 - beta*beta + log(4.0*eta*(1.0-eta)) + (1.0/(1.0-eta)) - (1.0-beta*beta)*sqbrack;
    return G;
}

// Auxillary Function for beta+
double aux_beta_plus(double beta, double eta, double tau)
{
    double eps = (1.0/(tau + 2.0));
    double sqbrack = 1.0+(2.0-eps*eps)*eta - (3.0+eps*eps)*(0.5*tau*eps)*eta*eta + (1.0+tau*eps)*(tau*tau*eps*eps/3.0)*eta*eta - (tau*tau*tau*eps*eps*eps/4.0)*eta*eta*eta*eta;
    double G = log(4.0*eta) - beta*beta*sqbrack;
    return G;
}

// Mean Excitation energy (in eV)
double mean_excitation_energy(int atom_num)
{
    return 9.1*(double)atom_num*(1.0 + 1.9*pow((double)atom_num,-2.0/3.0));
}

/// Stopping power for beta minus
double stopping_power_beta_minus(double mean_energy, int Zj, double Aj, double delta)
{
    if (mean_energy <= 0.0) return 0.0;
    double mec = 0.511004; //MeV
    double re = 2.818E-13; //cm
    double u = 1.6605655E-24; //g
    double beta = sqrt( (1.0 - pow(1.0 + (mean_energy/mec),-2.0)) );
    double eta = delta/mean_energy;
    double tau = mean_energy/mec;
    double G = aux_beta_minus(beta, eta, tau);
    double Xj = mean_excitation_energy(Zj)/1E6;
    
    return (2.0*M_PI*re*re*mec/beta/beta)*((double)Zj/u/Aj)*( log(mean_energy*mean_energy/Xj/Xj) + log(1.0+tau/2.0) + G );
}

/// Stopping power for beta plus
double stopping_power_beta_plus(double mean_energy, int Zj, double Aj, double delta)
{
    if (mean_energy <= 0.0) return 0.0;
    double mec = 0.511004; //MeV
    double re = 2.818E-13; //cm
    double u = 1.6605655E-24; //g
    double beta = sqrt( (1.0 - pow(1.0 + (mean_energy/mec),-2.0)) );
    double eta = delta/mean_energy;
    double tau = mean_energy/mec;
    double G = aux_beta_plus(beta, eta, tau);
    double Xj = mean_excitation_energy(Zj)/1E6;
    
    return (2.0*M_PI*re*re*mec/beta/beta)*((double)Zj/u/Aj)*( log(mean_energy*mean_energy/Xj/Xj) + log(1.0+tau/2.0) + G );
}

/// Stopping power for non-beta
double stopping_power_nonbeta(double mean_energy, int Zj, double Aj, double delta, double charge)
{
    if (mean_energy <= 0.0) return 0.0;
    double mec = 0.511004; //MeV
    double re = 2.818E-13; //cm
    double u = 1.6605655E-24; //g
    double beta = sqrt( (1.0 - pow(1.0 + (mean_energy/mec),-2.0)) );
    double Xj = mean_excitation_energy(Zj)/1E6;
    
    return (4.0*M_PI*re*re*mec/beta/beta)*((double)Zj/u/Aj)*charge*charge*( log(2.0*mec*beta*beta/Xj/(1.0-beta*beta)) - beta*beta );
}

// Mean path length for beta (cm)
double mean_path_beta(double mean_energy, double density)
{
    if (mean_energy <= 0.0) return 0.0;
    double power = 1.265 - 0.0954*log(mean_energy);
    return 0.412*pow(mean_energy,power)/density;
}

// Mean path length for non-beta (cm)
double mean_path_nonbeta(double mean_energy)
{
    if (mean_energy < 7.0)
        return 0.3*pow(mean_energy,3.0/2.0);
    else
        return (0.005*mean_energy + 0.285)*pow(mean_energy,3.0/2.0);
}

/*
 *								Start: Isotope Class Definitions
 *	-------------------------------------------------------------------------------------
 */

//Default constructor
Isotope::Isotope()
{
    IsoName = "No Name";
    decay_rate = 0.0;
    half_life = INFINITY;
    hl_threshold = 0.0;
    hl_units = years;
    isotope_number = 0;
    nuclides = nullptr;
    Stable = false;
    IsomericState = false;
    Warnings = false;
    initial_condition = 0.0;
    concentration = 0.0;
    inMoles = true;
    activity = 0.0;
    mass_excess = 0.0;
    spin_parity = 0.0;
    ionization_coeff = 0.0;
}

//Default destructor
Isotope::~Isotope()
{
    decay_modes.clear();
    branch_ratios.clear();
    particle_emitted.clear();
    num_particles.clear();
    daughter.clear();
    Q_values.clear();
    mean_radiation_energy.clear();
    spin_jump.clear();
    chain.clear();
}

//Load library
void Isotope::loadNuclides(yaml_cpp_class &data)
{
    this->nuclides = &data;
}

//Unload library
void Isotope::unloadNuclides()
{
    this->nuclides->DeleteContents();
}

//Clear chain
void Isotope::clearChain()
{
    this->chain.clear();
}

//Register via isotope name (e.g., H-2)
int Isotope::registerIsotope(std::string isotope_name)
{
    int success = 0;
    char *str;
    char iso[256];
    strcpy(iso, isotope_name.c_str());
    str = strtok(iso, "-");
    std::string sym;
    int iso_num;
    
    int i=0;
    while (str != NULL)
    {
        if (i == 0)
            sym = str;
        if (i == 1)
            iso_num = atoi(str);
        str = strtok(NULL, "-");
        i++;
    }
    
    success = this->registerIsotope(sym, iso_num);
    
    return success;
}

//Register via atomic symbol and isotope number
int Isotope::registerIsotope(std::string sym, int iso)
{
    int success = 0;
    this->Register(sym);
    this->isotope_number = iso;
    this->editNeutrons(iso - this->AtomicNumber());
    success = this->setConstants();
    success = this->calculateMeanEnergies();
    this->computeDecayRate();
    return success;
}

//Register via atomic number and isotope number
int Isotope::registerIsotope(int atom_num, int iso_num)
{
    int success = 0;
    this->Register(atom_num);
    this->isotope_number = iso_num;
    this->editNeutrons(iso_num - atom_num);
    success = this->setConstants();
    success = this->calculateMeanEnergies();
    this->computeDecayRate();
    return success;
}

//Display isotope information
void Isotope::DisplayInfo()
{
    std::cout << std::endl;
    
    std::cout << "                    Isotope: " << this->IsotopeName() << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "Atomic Number: " << this->AtomicNumber() << std::endl;
    std::cout << "Mass Number: " << this->IsotopeNumber() << std::endl;
    std::cout << "Weight (g/mol): " << this->AtomicWeight() << std::endl;
    std::cout << "Isomeric: ";
    if (this->isIsomericState() == true)
        std::cout << "True\n";
    else
        std::cout << "False\n";
    std::cout << "Stable: ";
    if (this->isStable() == true)
        std::cout << "True\n";
    else
        std::cout << "False\n";
    
    if (this->isStable() == false)
    {
        std::cout << "Half-life (" << timeunits_string(this->HalfLifeUnits()) << "): " << this->HalfLife(this->HalfLifeUnits()) << std::endl;
        std::cout << "Decay Rate (s): " << this->DecayRate() << std::endl;
        std::cout << "Decay Modes:\n";
        std::cout << "------------\n";
        std::cout << "\tMode : Fraction : Emission : Number Emitted : Daughter \n";
        std::cout << "\t------------------------------------------------------\n";
        for (int i=0; i<this->DecayModes(); i++)
        {
            std::cout << "\t" << decaymode_string(this->DecayMode(i)) << " : " << this->BranchFraction(i);
            std::cout << " : " << this->ParticleEmitted(i) << " : " << this->NumberParticlesEmitted(i) << " : " << this->Daughter(i);
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
}

//Display chain
void Isotope::DisplayChain()
{
    //Level loop
    for (int i=0; i<this->chain.size(); i++)
    {
        std::cout << "Level " << i << ":\n";
        std::cout << "------------\n";
        //Daughters loop
        for (int j=0; j<this->chain[i].size(); j++)
        {
            std::cout << this->chain[i][j].first << " ---> " << this->chain[i][j].second << std::endl;
        }
        std::cout << std::endl;
    }
}

//Create branching decay chain
void Isotope::createChain()
{
    bool all_stable = true;
    int success = 0;
    std::vector< std::pair<std::string,std::string> > temp;
    int i = 0;
    do
    {
        all_stable = true;
        try
        {
            if (i == 0)
            {
                all_stable = this->isStable();
                
                if (all_stable == true) break;
                else
                {
                    this->chain.push_back(temp);
                    success = this->addPairs(i, this->IsotopeName());
                    if (success != 0) {mError(read_error); all_stable = true; break;}
                }
            }
            else
            {
                for (int j=0; j<this->chain[i-1].size(); j++)
                {
                    if (this->chain[i-1][j].second == "stable")
                    {
                        this->chain[i-1].erase(this->chain[i-1].begin()+j);
                        all_stable = true;
                    }
                    else
                        all_stable = this->getNuclideLibrary()(this->chain[i-1][j].second)["stable"].getBool();
                    
                    if (all_stable == false) break;
                }
                if (all_stable == true)
                {
                    //No Action
                }
                else
                {
                    this->chain.push_back(temp);
                    
                    for (int j=0; j<this->chain[i-1].size(); j++)
                    {
                        if (this->chain[i-1][j].second == "stable")
                        {
                            this->chain[i-1].erase(this->chain[i-1].begin()+j);
                        }
                        else
                        {
                            if (this->getNuclideLibrary()(this->chain[i-1][j].second)["stable"].getBool() == true)
                            {
                                //Only push_back is daughter for next level in chain is not stable
                            }
                            else
                            {
                                success = this->addPairs(i, this->chain[i-1][j].second);
                            }
                        }
                        if (success != 0) {mError(read_error); all_stable = true; break;}
                    }
                }
            }
        }
        catch (std::out_of_range)
        {
            mError(invalid_isotope);
            all_stable = true;
        }
        
        i++;
    } while (all_stable == false);
}

//set initial cond
void Isotope::setInitialCondition(double ic)
{
    if (ic < 0.0)
        ic = 0.0;
    this->initial_condition = ic;
}

//set concentration
void Isotope::setConcentration(double c)
{
    if (this->isMolar() == true)
        this->activity = c*6.0221409e23*this->decay_rate;
    else
        this->activity = c*this->decay_rate;
    this->concentration = c;
}

//set activity
void Isotope::setActivity(double a)
{
    this->activity = a;
}

//set units
void Isotope::setUnits2Moles(bool opt)
{
    this->inMoles = opt;
}

//set warnings
void Isotope::setWarnings(bool opt)
{
    this->Warnings = opt;
}

//set threshold
void Isotope::setThreshold(double val)
{
    if (val < 0.0)
        val = 0.0;
    this->hl_threshold = val;
}

//update decay rate
void Isotope::updateDecayRate()
{
    this->decay_rate = this->decay_rate*1.001;
}

// Calculate ionization coefficient
int Isotope::calculateIonization(std::vector<Atom> &atoms, std::vector<double> &mass_fracs, double density, double potential)
{
    int success = 0;
    
    double Ion = 0.0;
    
    //Loop through all decay modes
    for (int i=0; i<this->DecayModes(); i++)
    {
        double Ii = 0.0;
        double path = 0.0;
        
        switch (this->decay_modes[i])
        {
            case stable:
                path = 0.0;
                break;
                
            case alpha:
                path = mean_path_nonbeta(this->mean_radiation_energy[i]);
                break;
                
            case spon_fiss:
                path = mean_path_nonbeta(this->mean_radiation_energy[i]);
                break;
                
            case beta_plus:
                path = mean_path_beta(this->mean_radiation_energy[i], density);
                break;
                
            case beta_min:
                path = mean_path_beta(this->mean_radiation_energy[i], density);
                break;
                
            case iso_trans:
                path = 0.0;
                break;
                
            case neutron_em:
                path = mean_path_nonbeta(this->mean_radiation_energy[i]);
                break;
                
            case beta_min_neutron_em:
                path = mean_path_beta(this->mean_radiation_energy[i], density);
                break;
                
            case beta_plus_proton_em:
                path = mean_path_beta(this->mean_radiation_energy[i], density);
                break;
                
            case proton_em:
                path = mean_path_nonbeta(this->mean_radiation_energy[i]);
                break;
                
            case beta_plus_alpha:
                path = mean_path_beta(this->mean_radiation_energy[i], density);
                break;
                
            case beta_plus_beta_plus:
                path = mean_path_beta(this->mean_radiation_energy[i], density);
                break;
                
            case beta_min_beta_min:
                path = mean_path_beta(this->mean_radiation_energy[i], density);
                break;
                
            case beta_min_2neutron_em:
                path = mean_path_beta(this->mean_radiation_energy[i], density);
                break;
                
            case beta_min_alpha:
                path = mean_path_beta(this->mean_radiation_energy[i], density);
                break;
                
            case proton_em_proton_em:
                path = mean_path_nonbeta(this->mean_radiation_energy[i]);
                break;
                
            case neutron_em_neutron_em:
                path = mean_path_nonbeta(this->mean_radiation_energy[i]);
                break;
                
            case beta_min_3neutron_em:
                path = mean_path_beta(this->mean_radiation_energy[i], density);
                break;
                
            case beta_min_4neutron_em:
                path = mean_path_beta(this->mean_radiation_energy[i], density);
                break;
                
            case beta_plus_2proton_em:
                path = mean_path_beta(this->mean_radiation_energy[i], density);
                break;
                
            case beta_plus_3proton_em:
                path = mean_path_beta(this->mean_radiation_energy[i], density);
                break;
                
            case specific_isotope:
                path = mean_path_nonbeta(this->mean_radiation_energy[i]);
                break;
                
            case undefined:
                path = 0.0;
                break;
                
            default:
                path = 0.0;
                break;
        }
        
        //Loop through the atoms in the media
        for (int j=0; j<atoms.size(); j++)
        {
            double delta = pow(10.0,(double)orderMag(atoms[j].KShellEnergy())+1.0)/1000.0;
            double stpow = 0.0;
            
            switch (this->decay_modes[i])
            {
                case stable:
                    stpow = 0.0;
                    break;
                    
                case alpha:
                    stpow = stopping_power_nonbeta(this->mean_radiation_energy[i], atoms[j].AtomicNumber(), atoms[j].AtomicWeight(), delta, 2.0);
                    break;
                    
                case spon_fiss:
                    stpow = stopping_power_nonbeta(this->mean_radiation_energy[i], atoms[j].AtomicNumber(), atoms[j].AtomicWeight(), delta, (double)this->AtomicNumber()/2.0);
                    break;
                    
                case beta_plus:
                    stpow = stopping_power_beta_plus(this->mean_radiation_energy[i], atoms[j].AtomicNumber(), atoms[j].AtomicWeight(), delta);
                    break;
                    
                case beta_min:
                    stpow = stopping_power_beta_minus(this->mean_radiation_energy[i], atoms[j].AtomicNumber(), atoms[j].AtomicWeight(), delta);
                    break;
                    
                case iso_trans:
                    stpow = 0.0;
                    break;
                    
                case neutron_em:
                    stpow = stopping_power_nonbeta(this->mean_radiation_energy[i], atoms[j].AtomicNumber(), atoms[j].AtomicWeight(), delta, 0.0);
                    break;
                    
                case beta_min_neutron_em:
                    stpow = stopping_power_beta_minus(this->mean_radiation_energy[i], atoms[j].AtomicNumber(), atoms[j].AtomicWeight(), delta);
                    break;
                    
                case beta_plus_proton_em:
                    stpow = stopping_power_beta_plus(this->mean_radiation_energy[i], atoms[j].AtomicNumber(), atoms[j].AtomicWeight(), delta);
                    break;
                    
                case proton_em:
                    stpow = stopping_power_nonbeta(this->mean_radiation_energy[i], atoms[j].AtomicNumber(), atoms[j].AtomicWeight(), delta, 1.0);
                    break;
                    
                case beta_plus_alpha:
                    stpow = stopping_power_beta_plus(this->mean_radiation_energy[i], atoms[j].AtomicNumber(), atoms[j].AtomicWeight(), delta);
                    break;
                    
                case beta_plus_beta_plus:
                    stpow = stopping_power_beta_plus(this->mean_radiation_energy[i], atoms[j].AtomicNumber(), atoms[j].AtomicWeight(), delta);
                    break;
                    
                case beta_min_beta_min:
                    stpow = stopping_power_beta_minus(this->mean_radiation_energy[i], atoms[j].AtomicNumber(), atoms[j].AtomicWeight(), delta);
                    break;
                    
                case beta_min_2neutron_em:
                    stpow = stopping_power_beta_minus(this->mean_radiation_energy[i], atoms[j].AtomicNumber(), atoms[j].AtomicWeight(), delta);
                    break;
                    
                case beta_min_alpha:
                    stpow = stopping_power_beta_minus(this->mean_radiation_energy[i], atoms[j].AtomicNumber(), atoms[j].AtomicWeight(), delta);
                    break;
                    
                case proton_em_proton_em:
                    stpow = stopping_power_nonbeta(this->mean_radiation_energy[i], atoms[j].AtomicNumber(), atoms[j].AtomicWeight(), delta, 1.0);
                    break;
                    
                case neutron_em_neutron_em:
                    stpow = stopping_power_nonbeta(this->mean_radiation_energy[i], atoms[j].AtomicNumber(), atoms[j].AtomicWeight(), delta, 0.0);
                    break;
                    
                case beta_min_3neutron_em:
                    stpow = stopping_power_beta_minus(this->mean_radiation_energy[i], atoms[j].AtomicNumber(), atoms[j].AtomicWeight(), delta);
                    break;
                    
                case beta_min_4neutron_em:
                    stpow = stopping_power_beta_minus(this->mean_radiation_energy[i], atoms[j].AtomicNumber(), atoms[j].AtomicWeight(), delta);
                    break;
                    
                case beta_plus_2proton_em:
                    stpow = stopping_power_beta_plus(this->mean_radiation_energy[i], atoms[j].AtomicNumber(), atoms[j].AtomicWeight(), delta);
                    break;
                    
                case beta_plus_3proton_em:
                    stpow = stopping_power_beta_plus(this->mean_radiation_energy[i], atoms[j].AtomicNumber(), atoms[j].AtomicWeight(), delta);
                    break;
                    
                case specific_isotope:
                    stpow = stopping_power_nonbeta(this->mean_radiation_energy[i], atoms[j].AtomicNumber(), atoms[j].AtomicWeight(), delta, 4.0);
                    break;
                    
                case undefined:
                    stpow = 0.0;
                    break;
                    
                default:
                    stpow = 0.0;
                    break;
            }
            
            Ii += mass_fracs[j]*stpow*density;
        }
        Ii = Ii*path/potential*1E6;
        Ion += Ii*this->BranchFraction(i);
    }
    
    this->ionization_coeff = Ion;
    
    return success;
}

//Return isotope number
int Isotope::IsotopeNumber()
{
    return this->isotope_number;
}

//Return decay rate
double Isotope::DecayRate()
{
    return this->decay_rate;
}

//Return half-life
double Isotope::HalfLife(time_units units)
{
    return time_conversion(units, this->half_life, this->hl_units);
}

//Return units
time_units Isotope::HalfLifeUnits()
{
    return this->hl_units;
}

//Return name
std::string Isotope::IsotopeName()
{
    return this->IsoName;
}

//Return stability
bool Isotope::isStable()
{
    return this->Stable;
}

//Return isomeric state
bool Isotope::isIsomericState()
{
    return this->IsomericState;
}

//Return True if units are moles
bool Isotope::isMolar()
{
    return this->inMoles;
}

//Return number of decay modes
int Isotope::DecayModes()
{
    return (int)this->decay_modes.size();
}

//Return initial cond
double Isotope::getInitialCondition()
{
    return this->initial_condition;
}

//Return concentration
double Isotope::getConcentration()
{
    return this->concentration;
}

//Return activity
double Isotope::getActivity()
{
    return this->activity;
}

//Return weight
double Isotope::AtomicWeight()
{
    return this->Atom::AtomicWeight();
}

double Isotope::MeltingPoint()
{
    return this->Atom::MeltingPoint();
}

double Isotope::BoilingPoint()
{
    return this->Atom::BoilingPoint();
}

double Isotope::ThermalXSection()
{
    return this->Atom::ThermalXSection();
}

double Isotope::ScatterXSection()
{
    return this->Atom::ScatterXSection();
}

double Isotope::MassExcess()
{
    return this->mass_excess;
}

double Isotope::Jpi()
{
    return this->spin_parity;
}

double Isotope::IonizationCoeff()
{
    return this->ionization_coeff;
}

//return decay mode
decay_mode Isotope::DecayMode(int i)
{
    if (i < 0 || i >= this->DecayModes())
        return stable;
    else
        return this->decay_modes[i];
    
}

//return branch fraction
double Isotope::BranchFraction(int i)
{
    if (i < 0 || i >= this->DecayModes())
        return 0.0;
    else
        return this->branch_ratios[i];
    
}

//return isotope emission
std::string Isotope::ParticleEmitted(int i)
{
    if (i < 0 || i >= this->DecayModes())
        return "None";
    else
        return this->particle_emitted[i];
    
}

//return the number of particles emitted
int Isotope::NumberParticlesEmitted(int i)
{
    if (i < 0 || i >= this->DecayModes())
        return 0;
    else
        return this->num_particles[i];
}

//return name of daughter
std::string Isotope::Daughter(int i)
{
    if (i < 0 || i >= this->DecayModes())
        return "None";
    else
        return this->daughter[i];
    
}

double Isotope::QValue(int i)
{
    if (i < 0 || i >= this->DecayModes())
        return 0.0;
    else
        return this->Q_values[i];
    
}

int Isotope::deltaJ(int i)
{
    if (i < 0 || i >= this->DecayModes())
        return 0.0;
    else
        return this->spin_jump[i];
    
}

double Isotope::MeanEnergy(int i)
{
    if (i < 0 || i >= this->DecayModes())
        return 0.0;
    else
        return this->mean_radiation_energy[i];
    
}

//return list of decay mode indices that form this isotope
std::vector<int> Isotope::DaughterIndices(std::string parent)
{
    std::vector<int> indices;
    
    //Read from the library to find the isotope
    try
    {
        //Loop through the decay_modes header
        int i = 0;
        for (auto &x: this->getNuclideLibrary()(parent)("decay_modes").getSubMap())
        {
            std::string dau = this->getNuclideLibrary()(parent)("decay_modes")(x.first)["daughter"].getString();
            
            if (dau == this->IsotopeName())
                indices.push_back(i);
            else
                indices.push_back(-1);
            
            i++;
        }
    }
    catch (std::out_of_range)
    {
        //Parent not found
        indices.clear();
    }
    
    return indices;
}

//return list of decay mode indices that form this isotope
std::vector<int> Isotope::EmissionIndices(std::string parent)
{
    std::vector<int> indices;
    
    //Read from the library to find the isotope
    try
    {
        //Loop through the decay_modes header
        int i = 0;
        for (auto &x: this->getNuclideLibrary()(parent)("decay_modes").getSubMap())
        {
            std::string part = this->getNuclideLibrary()(parent)("decay_modes")(x.first)["part_emitted"].getString();
            
            if (part == this->IsotopeName())
                indices.push_back(i);
            else
                indices.push_back(-1);
            
            i++;
        }
    }
    catch (std::out_of_range)
    {
        //Parent not found
        indices.clear();
    }
    
    return indices;
}

//Set the decay information based on a registered atomic number and isotope number
int Isotope::setConstants()
{
    //Set the name of the isotope
    int success = 0;
    char buff[10];
    sprintf(buff, "-%i", this->IsotopeNumber());
    std::string name = this->Atom::AtomSymbol();
    name.append(buff);
    this->IsoName = name;
    
    this->decay_modes.clear();
    this->branch_ratios.clear();
    this->particle_emitted.clear();
    this->num_particles.clear();
    this->daughter.clear();
    this->Q_values.clear();
    this->mean_radiation_energy.clear();
    this->spin_jump.clear();
    
    //Read from the library to find the isotope
    try
    {
        bool reg = true;
        std::string daughter_reg;
        double frac = 0.0;
        this->editAtomicWeight( this->getNuclideLibrary()(this->IsotopeName())["atom_weight"].getDouble() );
        this->IsomericState = this->getNuclideLibrary()(this->IsotopeName())["isomeric"].getBool();
        this->Stable = this->getNuclideLibrary()(this->IsotopeName())["stable"].getBool();
        if (this->Stable == false)
            this->half_life = this->getNuclideLibrary()(this->IsotopeName())["half_life"].getDouble();
        else
            this->half_life = INFINITY;
        std::string read_units = this->getNuclideLibrary()(this->IsotopeName())["hl_units"].getString();
        this->hl_units = timeunits_choice( read_units );
        if (this->HalfLife(seconds) < this->hl_threshold)
            reg = false;
        
        this->mass_excess = this->getNuclideLibrary()(this->IsotopeName())["mass-excess"].getDouble();
        this->spin_parity = this->getNuclideLibrary()(this->IsotopeName())["Jpi"].getDouble();
        
        //Loop through the decay_modes header
        int i = 0;
        for (auto &x: this->getNuclideLibrary()(this->IsotopeName())("decay_modes").getSubMap())
        {
            std::string read_decay = this->getNuclideLibrary()(this->IsotopeName())("decay_modes")(x.first)["type"].getString();
            this->decay_modes.push_back( decaymode_choice(read_decay) );
            if (this->getNuclideLibrary()(this->IsotopeName())("decay_modes")(x.first)["branch_frac"].getDouble() > frac)
            {
                frac = this->getNuclideLibrary()(this->IsotopeName())("decay_modes")(x.first)["branch_frac"].getDouble();
                daughter_reg = this->getNuclideLibrary()(this->IsotopeName())("decay_modes")(x.first)["daughter"].getString();
            }
            this->branch_ratios.push_back(this->getNuclideLibrary()(this->IsotopeName())("decay_modes")(x.first)["branch_frac"].getDouble());
            this->particle_emitted.push_back( this->getNuclideLibrary()(this->IsotopeName())("decay_modes")(x.first)["part_emitted"].getString() );
            this->num_particles.push_back(this->getNuclideLibrary()(this->IsotopeName())("decay_modes")(x.first)["num_parts"].getInt());
            this->daughter.push_back( this->getNuclideLibrary()(this->IsotopeName())("decay_modes")(x.first)["daughter"].getString() );
            this->Q_values.push_back(this->getNuclideLibrary()(this->IsotopeName())("decay_modes")(x.first)["Q-value"].getDouble());
            this->mean_radiation_energy.push_back(0.0);
            double dau_spin = this->getNuclideLibrary()(this->getNuclideLibrary()(this->IsotopeName())("decay_modes")(x.first)["daughter"].getString())["Jpi"].getDouble();
            this->spin_jump.push_back((int)fabs(this->spin_parity-dau_spin));
            i++;
        }
        
        if (reg == false)
            this->registerIsotope(daughter_reg);
    }
    //If isotope is not found, assume it is stable and set default values
    catch (std::out_of_range)
    {
        if (this->Warnings == true)
        {
            mError(invalid_isotope);
            std::cout << std::endl << this->IsoName << std::endl;
            std::cout << "Setting some default values...\n\n";
        }
        
        this->editAtomicWeight(this->IsotopeNumber());
        this->IsomericState = false;
        this->Stable = true;
        this->half_life = INFINITY;
        this->hl_units = years;
        
        this->decay_modes.push_back(stable);
        this->branch_ratios.push_back(0.0);
        this->particle_emitted.push_back("None");
        this->num_particles.push_back(0);
        this->daughter.push_back("None");
        this->Q_values.push_back(0.0);
        this->mean_radiation_energy.push_back(0.0);
        this->spin_jump.push_back(0);
        success = -1;
    }
    return success;
}

//Calculate the mean energies
int Isotope::calculateMeanEnergies()
{
    int success = 0;
    
    // Loop through all decay modes for this isotope
    for (int i=0; i<this->DecayModes(); i++)
    {
        // If the current decay mode is NOT a form of beta decay, set mean energy to Q-value
        // If it is a form of beta decay, then form the integral average
        switch (this->decay_modes[i])
        {
            case stable:
                this->mean_radiation_energy[i] = this->Q_values[i];
                break;
                
            case alpha:
                this->mean_radiation_energy[i] = this->Q_values[i];
                break;
                
            case spon_fiss:
                this->mean_radiation_energy[i] = this->Q_values[i];
                break;
                
            case beta_plus:
                this->mean_radiation_energy[i] = MeanEnergy_Stepwise(this->AtomicNumber(), this->spin_jump[i], this->Q_values[i]);
                break;
                
            case beta_min:
                this->mean_radiation_energy[i] = MeanEnergy_Stepwise(this->AtomicNumber(), this->spin_jump[i], this->Q_values[i]);
                break;
                
            case iso_trans:
                this->mean_radiation_energy[i] = this->Q_values[i];
                break;
                
            case neutron_em:
                this->mean_radiation_energy[i] = this->Q_values[i];
                break;
                
            case beta_min_neutron_em:
                this->mean_radiation_energy[i] = MeanEnergy_Stepwise(this->AtomicNumber(), this->spin_jump[i], this->Q_values[i]);
                break;
                
            case beta_plus_proton_em:
                this->mean_radiation_energy[i] = MeanEnergy_Stepwise(this->AtomicNumber(), this->spin_jump[i], this->Q_values[i]);
                break;
                
            case proton_em:
                this->mean_radiation_energy[i] = this->Q_values[i];
                break;
                
            case beta_plus_alpha:
                this->mean_radiation_energy[i] = MeanEnergy_Stepwise(this->AtomicNumber(), this->spin_jump[i], this->Q_values[i]);
                break;
                
            case beta_plus_beta_plus:
                this->mean_radiation_energy[i] = MeanEnergy_Stepwise(this->AtomicNumber(), this->spin_jump[i], this->Q_values[i]);
                break;
                
            case beta_min_beta_min:
                this->mean_radiation_energy[i] = MeanEnergy_Stepwise(this->AtomicNumber(), this->spin_jump[i], this->Q_values[i]);
                break;
                
            case beta_min_2neutron_em:
                this->mean_radiation_energy[i] = MeanEnergy_Stepwise(this->AtomicNumber(), this->spin_jump[i], this->Q_values[i]);
                break;
                
            case beta_min_alpha:
                this->mean_radiation_energy[i] = MeanEnergy_Stepwise(this->AtomicNumber(), this->spin_jump[i], this->Q_values[i]);
                break;
                
            case proton_em_proton_em:
                this->mean_radiation_energy[i] = this->Q_values[i];
                break;
                
            case neutron_em_neutron_em:
                this->mean_radiation_energy[i] = this->Q_values[i];
                break;
                
            case beta_min_3neutron_em:
                this->mean_radiation_energy[i] = MeanEnergy_Stepwise(this->AtomicNumber(), this->spin_jump[i], this->Q_values[i]);
                break;
                
            case beta_min_4neutron_em:
                this->mean_radiation_energy[i] = MeanEnergy_Stepwise(this->AtomicNumber(), this->spin_jump[i], this->Q_values[i]);
                break;
                
            case beta_plus_2proton_em:
                this->mean_radiation_energy[i] = MeanEnergy_Stepwise(this->AtomicNumber(), this->spin_jump[i], this->Q_values[i]);
                break;
                
            case beta_plus_3proton_em:
                this->mean_radiation_energy[i] = MeanEnergy_Stepwise(this->AtomicNumber(), this->spin_jump[i], this->Q_values[i]);
                break;
                
            case specific_isotope:
                this->mean_radiation_energy[i] = this->Q_values[i];
                break;
                
            case undefined:
                this->mean_radiation_energy[i] = this->Q_values[i];
                break;
                
            default:
                this->mean_radiation_energy[i] = this->Q_values[i];
                break;
        }
    }
    
    return success;
}

//Compute decay rate
void Isotope::computeDecayRate()
{
    double hl_sec = time_conversion(seconds, this->half_life, this->hl_units);
    this->decay_rate = log(2.0)/hl_sec;
    if (this->isStable() == true)
        this->decay_rate = 0.0;
}

//Append pairs to end of vectors
int Isotope::addPairs(int i, std::string parent)
{
    int success = 0;
    std::pair<std::string, std::string> temp = std::make_pair(parent, "stable");
    
    try
    {
        if (this->getNuclideLibrary()(parent)["stable"].getBool() == true)
        {
            this->chain[i].push_back(temp);
        }
        else
        {
            //Loop through the decay_modes header
            int m = 0;
            for (auto &x: this->getNuclideLibrary()(parent)("decay_modes").getSubMap())
            {
                std::string read_decay = this->getNuclideLibrary()(parent)("decay_modes")(x.first)["type"].getString();
                decay_mode read_mode = decaymode_choice(read_decay);
                std::string dau = this->getNuclideLibrary()(parent)("decay_modes")(x.first)["daughter"].getString();
                std::string part = this->getNuclideLibrary()(parent)("decay_modes")(x.first)["part_emitted"].getString();
                if (read_mode == stable || read_mode == undefined || read_mode == iso_trans)
                {
                    //If stable, don't push back
                }
                else
                {
                    temp = std::make_pair(parent, part);
                    if (part != "None")
                    {
                        this->chain[i].push_back(temp);
                    }
                    temp = std::make_pair(parent, dau);
                    this->chain[i].push_back(temp);
                }
                m++;
            }
        }
    }
    catch (std::out_of_range)
    {
        mError(invalid_isotope);
        return -1;
    }
    
    return success;
}

//Return library
YamlWrapper& Isotope::getNuclideLibrary()
{
    return this->nuclides->getYamlWrapper();
}

/*
 *	-------------------------------------------------------------------------------------
 *								End: Isotope Class Definitions
 */

/*
 *								Start: DecayChain Class Definitions
 *	-------------------------------------------------------------------------------------
 */

//Default constructor
DecayChain::DecayChain()
{
    time_steps = 10;
    end_time = 3600;
    t_units = hours;
    VerifyEigen = false;
    PrintChain = false;
    PrintSparsity = false;
    PrintResults = true;
    Warnings = false;
    avg_eig_error = 0.0;
    hl_threshold = 0.0;
    ConsoleOut = false;
    ionization_rate = 0.0;
}

//Default destructor
DecayChain::~DecayChain()
{
    nuc_list.clear();
    nuc_map.clear();
    stable_list.clear();
    stable_map.clear();
    parents.clear();
    branches.clear();
    CoefMap.clear();
    stable_parents.clear();
    stable_branches.clear();
    stable_CoefMap.clear();
    EigenMap.clear();
}

//Display list
void DecayChain::DisplayList()
{
    std::cout << "List of Nuclides:\n";
    std::cout << "-----------------\n";
    
    for (int i=0; i<this->nuc_list.size(); i++)
    {
        std::cout << this->nuc_list[i].IsotopeName() << std::endl;
    }
    std::cout << std::endl;
}

//Display stable list
void DecayChain::DisplayStableList()
{
    std::cout << "List of Stable Nuclides:\n";
    std::cout << "------------------------\n";
    
    for (int i=0; i<this->stable_list.size(); i++)
    {
        std::cout << this->stable_list[i].IsotopeName() << std::endl;
    }
    std::cout << std::endl;
}

//Display all stable nuclide and decay chain information
void DecayChain::DisplayStableInfo()
{
    std::cout << "List of Stable Nuclide Information:\n";
    std::cout << "-----------------------------------\n";
    std::cout << "-----------------------------------\n";
    
    for (int i=0; i<this->stable_list.size(); i++)
    {
        std::cout << "Stable Nuc Index: " << i << "\tName: " << this->getStableIsotope(i).IsotopeName() << std::endl;
        for (int j=0; j<this->getStableParentList(i).size(); j++)
        {
            if (j == 0) std::cout << "----------------------- List of Parents ------------------------\n";
            std::cout << "\t" << this->getIsotope( this->getStableParentList(i)[j] ).IsotopeName() << "\tDecay Const = " << this->getIsotope( this->getStableParentList(i)[j] ).DecayRate() << "\tFraction(s): ";
            for (int k=0; k<this->getStableBranchList(i, j).size(); k++)
            {
                std::cout << this->getIsotope( this->getStableParentList(i)[j] ).BranchFraction( this->getStableBranchList(i, j)[k] ) << "\t";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

//Display all nuclide and decay chain information
void DecayChain::DisplayInfo()
{
    std::cout << "List of Nuclide Information:\n";
    std::cout << "----------------------------\n";
    std::cout << "----------------------------\n";
    
    for (int i=0; i<this->nuc_list.size(); i++)
    {
        std::cout << "Nuclide Index: " << i << "\tName: " << this->getIsotope(i).IsotopeName() << "\tDecay Const = " << this->getIsotope(i).DecayRate() << std::endl;
        for (int j=0; j<this->getParentList(i).size(); j++)
        {
            if (j == 0) std::cout << "----------------------- List of Parents ------------------------\n";
            std::cout << "\t" << this->getIsotope( this->getParentList(i)[j] ).IsotopeName() << "\tDecay Const = " << this->getIsotope( this->getParentList(i)[j] ).DecayRate()	<< "\tFraction(s): ";
            for (int k=0; k<this->getBranchList(i, j).size(); k++)
            {
                std::cout << this->getIsotope( this->getParentList(i)[j] ).BranchFraction( this->getBranchList(i, j)[k] ) << "\t";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

//Display map
void DecayChain::DisplayMap()
{
    std::cout << "Coefficient Map:\n";
    std::cout << "----------------\n";
    
    for (int i=0; i<this->nuc_list.size(); i++)
    {
        for (int j=0; j<this->nuc_list.size(); j++)
        {
            try
            {
                double val = this->CoefMap[i].at(j);
                if (val < 0 && i!=j)
                {
                    std::cout << "Error!\n";
                    break;
                }
                std::cout << "X ";
            }
            catch (std::out_of_range)
            {
                std::cout << "O ";
            }
        }
        std::cout << std::endl;
    }
}

//Display eigen map
void DecayChain::DisplayEigenMap()
{
    std::cout << "EigenVector Map:\n";
    std::cout << "----------------\n";
    
    for (int i=0; i<this->nuc_list.size(); i++)
    {
        for (int j=0; j<this->nuc_list.size(); j++)
        {
            try
            {
                double val = this->EigenMap[i].at(j);
                if (val == 0.0)
                {
                    std::cout << "Error!\n";
                    break;
                }
                std::cout << "X ";
            }
            catch (std::out_of_range)
            {
                std::cout << "O ";
            }
        }
        std::cout << std::endl;
    }
}

//Load library
void DecayChain::loadNuclides(yaml_cpp_class &data)
{
    this->nuclides = &data;
}

//Unload library
void DecayChain::unloadNuclides()
{
    this->nuclides->DeleteContents();
}

//Register initial nuclide
int DecayChain::registerInitialNuclide(std::string isotope_name)
{
    Isotope temp;
    temp.loadNuclides(*this->nuclides);
    temp.setThreshold(this->hl_threshold);
    int success = temp.registerIsotope(isotope_name);
    if (success == 0)
        this->roughInsertSort(temp);
    return success;
}

//Register initial nuclide
int DecayChain::registerInitialNuclide(std::string symb, int iso)
{
    Isotope temp;
    temp.loadNuclides(*this->nuclides);
    temp.setThreshold(this->hl_threshold);
    int success = temp.registerIsotope(symb, iso);
    if (success == 0)
        this->roughInsertSort(temp);
    return success;
}

//Register initial nuclide
int DecayChain::registerInitialNuclide(int atom_num, int iso_num)
{
    Isotope temp;
    temp.loadNuclides(*this->nuclides);
    temp.setThreshold(this->hl_threshold);
    int success = temp.registerIsotope(atom_num, iso_num);
    if (success == 0)
        this->roughInsertSort(temp);
    return success;
}

//Register initial nuclide
int DecayChain::registerInitialNuclide(std::string isotope_name, double ic)
{
    Isotope temp;
    temp.loadNuclides(*this->nuclides);
    temp.setThreshold(this->hl_threshold);
    int success = temp.registerIsotope(isotope_name);
    temp.setInitialCondition(ic);
    if (success == 0)
        this->roughInsertSort(temp);
    return success;
}

//Register initial nuclide
int DecayChain::registerInitialNuclide(std::string symb, int iso, double ic)
{
    Isotope temp;
    temp.loadNuclides(*this->nuclides);
    temp.setThreshold(this->hl_threshold);
    int success = temp.registerIsotope(symb, iso);
    temp.setInitialCondition(ic);
    if (success == 0)
        this->roughInsertSort(temp);
    return success;
}

//Register initial nuclide
int DecayChain::registerInitialNuclide(int atom_num, int iso_num, double ic)
{
    Isotope temp;
    temp.loadNuclides(*this->nuclides);
    temp.setThreshold(this->hl_threshold);
    int success = temp.registerIsotope(atom_num, iso_num);
    temp.setInitialCondition(ic);
    if (success == 0)
        this->roughInsertSort(temp);
    return success;
}

//set warnings
void DecayChain::setWarnings(bool opt)
{
    this->Warnings = opt;
    for (int i=0; i<this->nuc_list.size(); i++)
        this->nuc_list[i].setWarnings(opt);
    for (int i=0; i<this->stable_list.size(); i++)
        this->stable_list[i].setWarnings(opt);
}

//set console out
void DecayChain::setConsoleOut(bool op)
{
    this->ConsoleOut = op;
}

//set threshold
void DecayChain::setThreshold(double val)
{
    if (val < 0.0)
        val = 0.0;
    this->hl_threshold = val;
}

//Create the decay chains and list of final nuclides
void DecayChain::createChains()
{
    std::string name;
    for (int i=0; i<this->nuc_list.size(); i++)
    {
        for (int j=0; j<this->nuc_list[i].DecayModes(); j++)
        {
            name = this->nuc_list[i].Daughter(j);
            if (name != "None" && name != "none")
                this->registerInitialNuclide(name);
            name = this->nuc_list[i].ParticleEmitted(j);
            if (name != "None" && name != "none")
                this->registerInitialNuclide(name);
        }//End decay_mode loop
        
    }//End nuc_list loop
    
    this->finalSort();
    this->parents.resize(this->nuc_list.size());
    this->branches.resize(this->nuc_list.size());
    this->stable_parents.resize(this->stable_list.size());
    this->stable_branches.resize(this->stable_list.size());
    this->fillOutBranchData();
    this->CoefMap.resize(this->nuc_list.size());
    this->stable_CoefMap.resize(this->stable_list.size());
    this->fillOutCoefMap();
    
    //Unload library to save memory
    this->unloadNuclides();
    
}

//Form eigenvectors
void DecayChain::formEigenvectors()
{
    if (this->CoefMap.size() != this->nuc_list.size())
    {
        mError(empty_matrix);
        std::cout << "Call the 'createChains() function first...\n";
        return;
    }
    
    this->EigenMap.resize((int)this->CoefMap.size());
    
    Matrix<double> temp;
    temp.set_size((int)this->CoefMap.size(), 1);
    //Loop for the kth eigenvector
    for (int k=0; k<this->nuc_list.size(); k++)
    {
        double eigenvalue = -this->nuc_list[k].DecayRate();
        double sum = 0.0;
        temp.edit(k, 0, 1.0);
        this->EigenMap[k][k] = 1.0;
        
        //Loop over the ith elements of the kth eigenvector
        for (int i=k+1; i<this->nuc_list.size(); i++)
        {
            sum = 0.0;
            //Iterate through the map (loop over j columns)
            for (std::map<int,double>::iterator jt=this->CoefMap[i].begin(); jt!=this->CoefMap[i].end(); jt++)
            {
                sum = sum + temp(jt->first,0)*jt->second;
            }
            double diff = -this->nuc_list[i].DecayRate()-eigenvalue;
            if (diff == 0.0)
            {
                if (this->Warnings == true)
                {
                    mError(unstable_matrix);
                    std::cout << "\nNon-unique eigenvalues!\n";
                    std::cout << "Problem Isotopes:\t" << this->nuc_list[k].IsotopeName() << "\t" << this->nuc_list[i].IsotopeName() << std::endl;
                    std::cout << "Adjusting eigenvalue by 0.1% to remove redundancy..." << std::endl;
                }
                //Fix with small adjustment to the kth eigenvalue
                this->nuc_list[k].updateDecayRate();
                eigenvalue = -this->nuc_list[k].DecayRate();
                diff = -this->nuc_list[i].DecayRate()-eigenvalue;
            }
            if (sum != 0.0)
                this->EigenMap[i][k] = -sum/diff;
            temp.edit(i, 0, -sum/diff);
        }
        temp.zeros();
        
    }
    
    //Loop for the kth eigenvector
    temp.zeros();
    for (int k=0; k<this->nuc_list.size(); k++)
    {
        temp.edit(k, 0, 1.0);
        double sum = 0.0;
        //Loop over the ith elements of the kth eigenvector
        for (int i=k+1; i<this->nuc_list.size(); i++)
        {
            sum = 0.0;
            
            //Iterate through the map (j loop)
            for (std::map<int,double>::iterator ij=this->EigenMap[i].begin(); ij!=this->EigenMap[i].end(); ij++)
            {
                sum = sum + temp(ij->first,0)*ij->second;
            }
            temp.edit(i, 0, -sum);
            if (sum != 0.0)
                this->EigenMap[k][i] = -sum;
        }
        temp.zeros();
    }
}

//verfiy eigenvectors and eigenvalues
int DecayChain::verifyEigenSoln()
{
    if (this->EigenMap.size() != this->nuc_list.size())
    {
        mError(empty_matrix);
        std::cout << "Call the 'formEigenvectors() function first...\n";
        return -1;
    }
    
    if (this->ConsoleOut == true)
    {
        std::cout << "\nVerifying Eigen Solution...\n";
        std::cout << "---------------------------\n";
    }
    
    Matrix<double> zero((int)this->CoefMap.size(),1);
    
    //Loop over kth eigenvector and eigenvalue pair
    int errors = 0;
    this->avg_eig_error = 0.0;
    for (int k=0; k<this->nuc_list.size(); k++)
    {
        double eigenvalue = -this->nuc_list[k].DecayRate();
        double sum = 0.0;
        
        //Loop over the ith elements of the kth eigenvector
        for (int i=0; i<this->nuc_list.size(); i++)
        {
            sum = 0.0;
            
            //Iterate through the map (loop over j columns)
            for (std::map<int,double>::iterator jt=this->CoefMap[i].begin(); jt!=this->CoefMap[i].end(); jt++)
            {
                if (jt->first >= k)
                {
                    std::map<int,double>::iterator it = this->EigenMap[jt->first].find(k);
                    if (it != this->EigenMap[jt->first].end())
                    {
                        sum = sum + it->second*jt->second;
                    }
                }
            }
            //Use relative error for comparison because machine precicision is based on relative error
            if (i >= k)
            {
                std::map<int,double>::iterator it = this->EigenMap[i].find(k);
                if (it != this->EigenMap[i].end())
                    zero.edit(i, 0, (sum - eigenvalue*it->second)/sum);
                else
                    zero.edit(i, 0, (sum - eigenvalue*0.0)/sum);
            }
            else
                zero.edit(i, 0, 0.0);
        }
        double error = zero.norm();
        if (error > MIN_TOL)
        {
            if (this->ConsoleOut == true)
            {
                std::cout << "Eigen Solution NOT within tolerance (" << MIN_TOL << ") at " << k << "-th eigen pair!\n";
                std::cout << "\tNorm = " << error << std::endl;
            }
            this->avg_eig_error += error;
            errors++;
        }
        else
        {
            //std::cout << "Eigen Solution is within tolerance (" << MIN_TOL << ") at " << k << "-th eigen pair!\n";
        }
    }
    if (errors > 0)
    {
        if (this->ConsoleOut == true)
            std::cout << "\nEigen Solution outside of prescribed tolerance (" << MIN_TOL << "). ";
        this->avg_eig_error = this->avg_eig_error/(double)errors;
        if (this->ConsoleOut == true)
            std::cout << "Average Error = " << this->avg_eig_error << " with " << errors << " errors.\n\n";
    }
    else
    {
        this->avg_eig_error = MIN_TOL;
        if (this->ConsoleOut == true)
            std::cout << "Eigenvector Solution Verified! No Errors Present\n\n";
    }
    return errors;
}

//Estimate fractionation
void DecayChain::calculateFractionation(double t)
{
    
    if (this->EigenMap.size() != this->nuc_list.size())
    {
        mError(empty_matrix);
        std::cout << "Call the 'formEigenvectors() function first...\n";
        return;
    }
    
    //Loop over all ith isotopes
    for (int i=0; i<this->nuc_list.size(); i++)
    {
        double sum_outer = 0.0;
        //loop over j columns
        for (int j=0; j<=i; j++)
        {
            double sum_inner = 0.0;
            //Iterate through the map (loop over k eigenvalues)
            for (std::map<int,double>::iterator jk=this->EigenMap[j].begin(); jk!=this->EigenMap[j].end(); jk++)
            {
                if (jk->first > i)
                    break;
                if (jk->first >= j)
                {
                    for (std::map<int,double>::iterator ik=this->EigenMap[i].begin(); ik!=this->EigenMap[i].end(); ik++)
                    {
                        if (ik->first == jk->first)
                            sum_inner = sum_inner + ik->second*jk->second*exp(-this->nuc_list[jk->first].DecayRate()*t);
                    }
                }
            }
            sum_outer = sum_outer + sum_inner*this->nuc_list[j].getInitialCondition();
        }
        this->nuc_list[i].setConcentration(sum_outer);
    }
    
    //Loop over all ith stable isotopes
    for (int i=0; i<this->stable_list.size(); i++)
    {
        //Iterate through the map (loop over j columns)
        double j_sum = 0.0;
        for (std::map<int,double>::iterator jt=this->stable_CoefMap[i].begin(); jt!=this->stable_CoefMap[i].end(); jt++)
        {
            int j = jt->first;
            double k_sum = 0.0;
            //Loop over k
            for (int k=0; k<=j; k++)
            {
                double l_sum = 0.0;
                //Iterate through the map (loop over l eigenvalues)
                for (std::map<int,double>::iterator kl=this->EigenMap[k].begin(); kl!=this->EigenMap[k].end(); kl++)
                {
                    if (kl->first > j)
                        break;
                    if (kl->first >= k)
                    {
                        for (std::map<int,double>::iterator jl=this->EigenMap[j].begin(); jl!=this->EigenMap[j].end(); jl++)
                        {
                            if (jl->first == kl->first)
                                l_sum = l_sum + ( jl->second*kl->second*(1.0-exp(-this->nuc_list[kl->first].DecayRate()*t))/this->nuc_list[kl->first].DecayRate() );
                        }
                    }
                }
                k_sum = k_sum + this->nuc_list[k].getInitialCondition()*l_sum;
            }
            j_sum = j_sum + k_sum*jt->second;
        }
        this->stable_list[i].setConcentration( this->stable_list[i].getInitialCondition() + j_sum );
    }
}

//Calculate the ionization rate
void DecayChain::calculateIonizationRate(std::vector<Atom> &atoms, std::vector<double> &mass_fracs, double density, double potential)
{
    this->ionization_rate = 0.0;
    for (int i=0; i<this->nuc_list.size(); i++)
    {
        this->nuc_list[i].calculateIonization(atoms, mass_fracs, density, potential);
        this->ionization_rate += this->nuc_list[i].IonizationCoeff()*this->nuc_list[i].getActivity();
    }
}

//Print results to a file
void DecayChain::print_results(FILE *file, time_units units, double end_time, int points)
{
    //Stable v Unstable Header
    for (int i=0; i<this->getNumberNuclides(); i++)
    {
        if (i==0)
            fprintf(file, "\tUnstable");
        else
            fprintf(file, "\t***");
    }
    for (int i=0; i<this->getNumberStableNuclides(); i++)
    {
        if (i==0)
            fprintf(file, "\tStable");
        else
            fprintf(file, "\t###");
    }
    fprintf(file, "\n");
    
    //Header
    fprintf(file, "Time");
    switch (units)
    {
        case seconds:
            fprintf(file, "(s)");
            break;
            
        case minutes:
            fprintf(file, "(min)");
            break;
            
        case hours:
            fprintf(file, "(hr)");
            break;
            
        case days:
            fprintf(file, "(day)");
            break;
            
        case years:
            fprintf(file, "(yr)");
            break;
            
        default:
            fprintf(file, "(s)");
            break;
    }
    for (int i=0; i<this->getNumberNuclides(); i++)
        fprintf(file, "\t%s", this->getIsotope(i).IsotopeName().c_str());
    for (int i=0; i<this->getNumberStableNuclides(); i++)
        fprintf(file, "\t%s", this->getStableIsotope(i).IsotopeName().c_str());
    fprintf(file, "\n");
    
    //IC
    fprintf(file, "0");
    for (int i=0; i<this->getNumberNuclides(); i++)
        fprintf(file, "\t%.6g", this->getIsotope(i).getInitialCondition());
    for (int i=0; i<this->getNumberStableNuclides(); i++)
        fprintf(file, "\t%.6g", this->getStableIsotope(i).getInitialCondition());
    fprintf(file, "\n");
    
    //Simulations
    double dt = time_conversion(seconds, end_time, units)/(double)points;
    double pdt = end_time/(double)points;
    double time = 0.0;
    double ptime = 0.0;
    double percent_comp = 0.0;
    double print_comp = 0.0;
    if (this->ConsoleOut == true)
        std::cout << "Running Fractionation Simulation\nPercent Completion...\n";
    for (int n=0; n<points; n++)
    {
        percent_comp = (double)(n) / (double)points;
        if ( (percent_comp - print_comp) >= 0.0)
        {
            print_comp = print_comp + 0.1;
            
            if (this->ConsoleOut == true)
                std::cout << "\t[" << (int)(percent_comp*100.0) << " %]\n";
        }
        
        time = time + dt;
        ptime = ptime + pdt;
        this->calculateFractionation(time);
        
        fprintf(file, "%.6g", ptime);
        for (int i=0; i<this->getNumberNuclides(); i++)
            fprintf(file, "\t%.6g", this->getIsotope(i).getConcentration());
        for (int i=0; i<this->getNumberStableNuclides(); i++)
            fprintf(file, "\t%.6g", this->getStableIsotope(i).getConcentration());
        fprintf(file, "\n");
    }
    if (this->ConsoleOut == true)
        std::cout << "\t[100 %]\n\n";
    
    //Close the open file
    if (file != nullptr)
        fclose(file);
}

//Read Runtime block
int DecayChain::read_conditions(yaml_cpp_class &yaml)
{
    int success = 0;
    
    std::string opt;
    try
    {
        opt = yaml.getYamlWrapper()("Runtime")["time_units"].getString();
    }
    catch (std::out_of_range)
    {
        opt = "seconds";
    }
    this->t_units = timeunits_choice(opt);
    try
    {
        this->end_time = yaml.getYamlWrapper()("Runtime")["end_time"].getDouble();
    }
    catch (std::out_of_range)
    {
        this->end_time = 0.0;
    }
    try
    {
        this->time_steps = yaml.getYamlWrapper()("Runtime")["time_steps"].getInt();
    }
    catch (std::out_of_range)
    {
        this->time_steps = 1;
    }
    
    try
    {
        this->VerifyEigen = yaml.getYamlWrapper()("Runtime")["verify"].getBool();
    }
    catch (std::out_of_range)
    {
        this->VerifyEigen = true;
    }
    try
    {
        this->PrintSparsity = yaml.getYamlWrapper()("Runtime")["print_sparsity"].getBool();
    }
    catch (std::out_of_range)
    {
        this->PrintSparsity = true;
    }
    try
    {
        this->PrintChain = yaml.getYamlWrapper()("Runtime")["print_chain"].getBool();
    }
    catch (std::out_of_range)
    {
        this->PrintChain = true;
    }
    try
    {
        this->PrintResults = yaml.getYamlWrapper()("Runtime")["print_results"].getBool();
    }
    catch (std::out_of_range)
    {
        this->PrintResults = true;
    }
    
    return success;
}

//Read Isotopes block
int DecayChain::read_isotopes(yaml_cpp_class &yaml)
{
    int success = 0;
    
    int num_iso;
    try
    {
        num_iso = (int)yaml.getYamlWrapper()("Isotopes").getHeadMap().size();
    }
    catch (std::out_of_range)
    {
        mError(read_error);
        std::cout << "Could not find 'Isotopes' block...\n";
        return -1;
    }
    if (num_iso < 1) {mError(missing_information); std::cout << "No starting isotopes given...\n"; return -1;}
    
    //Register all initial nuclides
    for (auto &x: yaml.getYamlWrapper()("Isotopes").getHeadMap())
    {
        //Check for existance of the isotope (if no exception is thrown, the isotope is valid)
        std::string sym;
        try
        {
            sym = this->nuclides->getYamlWrapper()(x.first)["symbol"].getString();
        }
        catch (std::out_of_range)
        {
            mError(invalid_isotope);
            return -1;
        }
        
        this->registerInitialNuclide(x.first);
    }
    
    //Create chains and form eigenvectors after registering all nuclides
    this->createChains();
    this->formEigenvectors();
    
    for (auto &x: yaml.getYamlWrapper()("Isotopes").getHeadMap())
    {
        try
        {
            this->getIsotope(x.first).setInitialCondition( x.second["initial_cond"].getDouble() );
        }
        catch (std::out_of_range)
        {
            this->getIsotope(x.first).setInitialCondition(0.0);
        }
    }
    
    return success;
}

//Run simulation
int DecayChain::run_simulation(std::string file_name)
{
    int success = 0;
    
    //Open a file to print results to
    FILE *file;
    file = fopen(file_name.c_str(), "w+");
    if (file == nullptr)
    {
        system("mkdir output");
        file = fopen(file_name.c_str(), "w+");
    }
    
    if (this->VerifyEigen == true)
    {
        int errors = this->verifyEigenSoln();
        if (errors < 0) {return -1;}
        else if (errors == 0)
        {
            fprintf(file, "Eigenvector Solution Verified! No Errors Present\n\n");
        }
        else
        {
            fprintf(file, "Eigenvector Solution outside of prescribed tolerance (%.6g). Average Error =\t%.6g\t for \t%i\t errors.\n\n", MIN_TOL, this->avg_eig_error, errors);
        }
        
    }
    
    if (this->PrintSparsity == true)
    {
        fprintf(file, "Sparsity Pattern in Coefficient Matrix:\n------------------------------\n\n");
        for (int i=0; i<this->nuc_list.size(); i++)
        {
            fprintf(file, "| ");
            for (int j=0; j<this->nuc_list.size(); j++)
            {
                try
                {
                    double val = this->CoefMap[i].at(j);
                    if (val < 0 && i!=j)
                    {
                        mError(simulation_fail);
                        return -1;
                    }
                    fprintf(file, "X ");
                }
                catch (std::out_of_range)
                {
                    fprintf(file, "- ");
                }
            }
            fprintf(file, "|\n");
        }
        fprintf(file, "\n");
    }
    
    if (this->PrintChain == true)
    {
        fprintf(file, "List of Nuclide Information:\n");
        fprintf(file, "----------------------------\n");
        fprintf(file, "----------------------------\n");
        
        for (int i=0; i<this->nuc_list.size(); i++)
        {
            fprintf(file, "Nuclide Index: %i\tName: %s\tDecay Const = %.6g per sec\n", i, this->getIsotope(i).IsotopeName().c_str(), this->getIsotope(i).DecayRate());
            for (int j=0; j<this->getParentList(i).size(); j++)
            {
                if (j == 0) fprintf(file, "----------------------- List of Parents ------------------------\n");
                fprintf(file, "\t%s\tDecay Const = %.6g per sec\tFraction(s): ", this->getIsotope( this->getParentList(i)[j] ).IsotopeName().c_str(), this->getIsotope( this->getParentList(i)[j] ).DecayRate());
                for (int k=0; k<this->getBranchList(i, j).size(); k++)
                {
                    fprintf(file, "%.6g\t", this->getIsotope( this->getParentList(i)[j] ).BranchFraction( this->getBranchList(i, j)[k] ));
                }
                fprintf(file, "\n");
            }
            fprintf(file, "\n");
        }
        fprintf(file, "\n");
        
        
        fprintf(file, "List of Stable Nuclide Information:\n");
        fprintf(file, "-----------------------------------\n");
        fprintf(file, "-----------------------------------\n");
        
        for (int i=0; i<this->stable_list.size(); i++)
        {
            fprintf(file, "Stable Nuc Index: %i\tName: %s\n", i, this->getStableIsotope(i).IsotopeName().c_str());
            for (int j=0; j<this->getStableParentList(i).size(); j++)
            {
                if (j == 0) fprintf(file, "----------------------- List of Parents ------------------------\n");
                fprintf(file, "\t%s\tDecay Const = %.6g per sec\tFraction(s): ", this->getIsotope( this->getStableParentList(i)[j] ).IsotopeName().c_str(), this->getIsotope( this->getStableParentList(i)[j] ).DecayRate());
                for (int k=0; k<this->getStableBranchList(i, j).size(); k++)
                {
                    fprintf(file, "%.6g\t", this->getIsotope( this->getStableParentList(i)[j] ).BranchFraction( this->getStableBranchList(i, j)[k] ));
                }
                fprintf(file, "\n");
            }
            fprintf(file, "\n");
        }
        fprintf(file, "\n");
        
    }
    
    if (this->PrintResults == true)
    {
        this->print_results(file, this->t_units, this->end_time, this->time_steps);
    }
    
    //Close the open file
    if (file != nullptr)
        fclose(file);
    
    return success;
}

//Return unstable frac at t
double DecayChain::returnUnstableFractionation(int i, double t)
{
    if (i >= (int)this->nuc_list.size() || i < 0)
    {
        i = 0;
        mError(out_of_bounds);
    }
    
    double sum_outer = 0.0;
    
    //loop over j columns
    for (int j=0; j<=i; j++)
    {
        double sum_inner = 0.0;
        //Iterate through the map (loop over k eigenvalues)
        for (std::map<int,double>::iterator jk=this->EigenMap[j].begin(); jk!=this->EigenMap[j].end(); jk++)
        {
            if (jk->first > i)
                break;
            if (jk->first >= j)
            {
                for (std::map<int,double>::iterator ik=this->EigenMap[i].begin(); ik!=this->EigenMap[i].end(); ik++)
                {
                    if (ik->first == jk->first)
                        sum_inner = sum_inner + ik->second*jk->second*exp(-this->nuc_list[jk->first].DecayRate()*t);
                }
            }
        }
        sum_outer = sum_outer + sum_inner*this->nuc_list[j].getInitialCondition();
    }
    this->nuc_list[i].setConcentration(sum_outer);
    
    return this->nuc_list[i].getConcentration();
}

//Return stable frac at t
double DecayChain::returnStableFractionation(int i, double t)
{
    if (i >= (int)this->stable_list.size() || i < 0)
    {
        i = 0;
        mError(out_of_bounds);
    }
    
    //Iterate through the map (loop over j columns)
    double j_sum = 0.0;
    for (std::map<int,double>::iterator jt=this->stable_CoefMap[i].begin(); jt!=this->stable_CoefMap[i].end(); jt++)
    {
        int j = jt->first;
        double k_sum = 0.0;
        //Loop over k
        for (int k=0; k<=j; k++)
        {
            double l_sum = 0.0;
            //Iterate through the map (loop over l eigenvalues)
            for (std::map<int,double>::iterator kl=this->EigenMap[k].begin(); kl!=this->EigenMap[k].end(); kl++)
            {
                if (kl->first > j)
                    break;
                if (kl->first >= k)
                {
                    for (std::map<int,double>::iterator jl=this->EigenMap[j].begin(); jl!=this->EigenMap[j].end(); jl++)
                    {
                        if (jl->first == kl->first)
                            l_sum = l_sum + ( jl->second*kl->second*(1.0-exp(-this->nuc_list[kl->first].DecayRate()*t))/this->nuc_list[kl->first].DecayRate() );
                    }
                }
            }
            k_sum = k_sum + this->nuc_list[k].getInitialCondition()*l_sum;
        }
        j_sum = j_sum + k_sum*jt->second;
    }
    this->stable_list[i].setConcentration( this->stable_list[i].getInitialCondition() + j_sum );
    
    
    return this->stable_list[i].getConcentration();
}

//Return fractionation of given isotope
double DecayChain::returnFractionation(std::string iso_name, double t)
{
    try
    {
        return this->returnUnstableFractionation(this->nuc_map.at(iso_name), t);
    }
    catch (std::out_of_range)
    {
        //Test for stable isotope
    }
    try
    {
        return this->returnStableFractionation(this->stable_map.at(iso_name), t);
    }
    catch (std::out_of_range)
    {
        mError(out_of_bounds);
        return 0.0;
    }
}

//Return num nuc
int DecayChain::getNumberNuclides()
{
    return (int)this->nuc_list.size();
}

//Return num stable nuc
int DecayChain::getNumberStableNuclides()
{
    return (int)this->stable_list.size();
}

//Return ionization rate
double DecayChain::getIonizationRate()
{
    return this->ionization_rate;
}

//Return unstable index
int DecayChain::getIsotopeIndex(std::string iso_name)
{
    try
    {
        return  this->nuc_map.at(iso_name);
    }
    catch (std::out_of_range)
    {
        mError(out_of_bounds);
        return 0;
    }
}

//Return stable index
int DecayChain::getStableIsotopeIndex(std::string iso_name)
{
    try
    {
        return  this->stable_map.at(iso_name);
    }
    catch (std::out_of_range)
    {
        mError(out_of_bounds);
        return 0;
    }
}

//Return parents
std::vector<int>& DecayChain::getParentList(int i)
{
    if (i >= (int)this->nuc_list.size() || i < 0)
    {
        i = 0;
        mError(out_of_bounds);
    }
    return this->parents[i];
}

//Return stable parents
std::vector<int>& DecayChain::getStableParentList(int i)
{
    if (i >= (int)this->stable_list.size() || i < 0)
    {
        i = 0;
        mError(out_of_bounds);
    }
    return this->stable_parents[i];
}

//Return branches
std::vector<int>& DecayChain::getBranchList(int i, int j)
{
    if (i >= (int)this->nuc_list.size() || i < 0)
    {
        i = 0;
        mError(out_of_bounds);
    }
    if (j >= (int)this->parents[i].size() || j < 0)
    {
        j = 0;
        mError(out_of_bounds);
    }
    return this->branches[i][j];
}

//Return stable branches
std::vector<int>& DecayChain::getStableBranchList(int i, int j)
{
    if (i >= (int)this->stable_list.size() || i < 0)
    {
        i = 0;
        mError(out_of_bounds);
    }
    if (j >= (int)this->stable_parents[i].size() || j < 0)
    {
        j = 0;
        mError(out_of_bounds);
    }
    return this->stable_branches[i][j];
}

//Return isotope
Isotope& DecayChain::getIsotope(int i)
{
    if (i >= (int)this->nuc_list.size() || i < 0)
    {
        i = 0;
        mError(out_of_bounds);
    }
    return this->nuc_list[i];
}

//Return stable isotope
Isotope& DecayChain::getStableIsotope(int i)
{
    if (i >= (int)this->stable_list.size() || i < 0)
    {
        i = 0;
        mError(out_of_bounds);
    }
    return this->stable_list[i];
}

//Return stable or unstable isotope
Isotope& DecayChain::getIsotope(std::string iso_name)
{
    try
    {
        return this->nuc_list[ this->nuc_map.at(iso_name) ];
    }
    catch (std::out_of_range)
    {
        //Test for stable isotope
    }
    try
    {
        return this->stable_list[ this->stable_map.at(iso_name) ];
    }
    catch (std::out_of_range)
    {
        mError(out_of_bounds);
        return this->nuc_list[0];
    }
}

//Insert an isotope to the initial list
void DecayChain::roughInsertSort(Isotope iso)
{
    //If iso is stable, do not insert
    if (iso.isStable() == true)
    {
        Isotope pivot;
        pivot = iso;
        int i = 0;
        for (i=0; i<this->stable_list.size(); i++)
        {
            //Check is temp == ith stable nuclide
            if (iso.IsotopeName() == this->stable_list[i].IsotopeName())
            {
                //Add initial conditions
                this->stable_list[i].setInitialCondition( this->stable_list[i].getInitialCondition()+iso.getInitialCondition() );
                return;	//Don't add a redundant isotope
            }
            
            //Check temp vs ith stable nuclide
            if (iso.IsotopeNumber() > this->stable_list[i].IsotopeNumber())
            {
                //Replace ith nuclide with temp and push all other nuclides downward
                pivot = this->stable_list[i];
                this->stable_list[i] = iso;
                iso = pivot;
            }
        }
        this->stable_list.push_back(iso);
        return;
    }
    
    Isotope pivot;
    pivot = iso;
    int i = 0;
    for (i=0; i<this->nuc_list.size(); i++)
    {
        //Check is temp == ith nuclide
        if (iso.IsotopeName() == this->nuc_list[i].IsotopeName())
        {
            //Add initial conditions
            this->nuc_list[i].setInitialCondition( this->nuc_list[i].getInitialCondition()+iso.getInitialCondition() );
            return;	//Don't add a redundant isotope
        }
        
        //Check temp vs ith nuclide
        if (iso.IsotopeNumber() > this->nuc_list[i].IsotopeNumber())
        {
            //Replace ith nuclide with temp and push all other nuclides downward
            pivot = this->nuc_list[i];
            this->nuc_list[i] = iso;
            iso = pivot;
        }
    }
    this->nuc_list.push_back(iso);
}

//Perform final sort
void DecayChain::finalSort()
{
    std::vector<int> common_iso;
    std::vector<Isotope> iso_list;
    std::vector<Isotope> sorted_list;
    
    for (int i=0; i<this->nuc_list.size(); i++)
    {
        common_iso.push_back(i);
        iso_list.push_back(this->nuc_list[i]);
        //Look ahead
        for (int j=i+1; j<this->nuc_list.size(); j++)
        {
            if (this->nuc_list[i].IsotopeNumber() == this->nuc_list[j].IsotopeNumber())
            {
                common_iso.push_back(j);
                iso_list.push_back(this->nuc_list[j]);
            }
            else
                break;
        }//End look ahead
        
        //Check common_iso size
        if (common_iso.size() < 2)
        {
            common_iso.clear();
            iso_list.clear();
        }
        else
        {
            sorted_list = this->sameIsoNumSort(iso_list);
            for (int j=0; j<common_iso.size(); j++)
                this->nuc_list[common_iso[j]] = sorted_list[j];
            
            i = i + (int)common_iso.size() - 1;
            common_iso.clear();
            iso_list.clear();
        }
        
    }//End nuc_list loop
}

std::vector<Isotope> DecayChain::sameIsoNumSort(std::vector<Isotope> &list)
{
    std::vector<Isotope> sorted;
    int size = (int)list.size();
    bool daughter = false;
    
    //Loop through all isotopes
    for (int i=0; i<size; i++)
    {
        //Loop through the current list to check j
        for (int j=0; j<list.size(); j++)
        {
            daughter = false;
            
            //Loop through list to check k against j
            for (int k=0; k<list.size(); k++)
            {
                //Check only if we are looking at a different isotope
                if (k!=j && daughter == false)
                {
                    //check daughters of k against j
                    for (int d=0; d<list[k].DecayModes(); d++)
                    {
                        if (list[k].Daughter(d) == list[j].IsotopeName())
                        {
                            daughter = true;
                            break;
                        }
                    }
                }
                
                if (daughter == true)
                    break;
            }
            
            if (daughter == false)
            {
                sorted.push_back(list[j]);
                list.erase(list.begin()+j);
                break;
            }
            
        }
        
    }
    
    return sorted;
}

// Fill out all data
void DecayChain::fillOutBranchData()
{
    std::vector<int> temp;
    //Loop over all i nuclides (daughters)
    for (int i=(int)this->nuc_list.size()-1; i>=0; i--)
    {
        //Loop over all j nuclides for j<i
        for (int j=i-1; j>=0; j--)
        {
            bool hasPushed = false;
            //Check daughters and particles emitted from j
            for (int d=0; d<this->nuc_list[j].DecayModes(); d++)
            {
                if (this->nuc_list[j].Daughter(d) == this->nuc_list[i].IsotopeName() ||
                    this->nuc_list[j].ParticleEmitted(d) == this->nuc_list[i].IsotopeName())
                {
                    if (hasPushed == false)
                    {
                        this->parents[i].push_back(j);
                        hasPushed = true;
                    }
                    temp.push_back(d);
                    
                }
            }
            if (hasPushed == true)
                this->branches[i].push_back(temp);
            temp.clear();
        }
    }
    
    temp.clear();
    //Loop over all i stable nuclides (daughters)
    for (int i=0; i<(int)this->stable_list.size(); i++)
    {
        //Loop over all j unstable nuclides (potential parents)
        for (int j=0; j<(int)this->nuc_list.size(); j++)
        {
            bool hasPushed = false;
            //Check daughters and particles emitted from j
            for (int d=0; d<this->nuc_list[j].DecayModes(); d++)
            {
                if (this->nuc_list[j].Daughter(d) == this->stable_list[i].IsotopeName() ||
                    this->nuc_list[j].ParticleEmitted(d) == this->stable_list[i].IsotopeName())
                {
                    if (hasPushed == false)
                    {
                        this->stable_parents[i].push_back(j);
                        hasPushed = true;
                    }
                    temp.push_back(d);
                    
                }
            }
            if (hasPushed == true)
                this->stable_branches[i].push_back(temp);
            temp.clear();
        }
    }
}

//Fill out coef map
void DecayChain::fillOutCoefMap()
{
    //Loop over all nuclides (daughters)
    for (int i=0; i<this->nuc_list.size(); i++)
    {
        this->nuc_map[this->nuc_list[i].IsotopeName()] = i;
        
        //Element [i][i] == -DecayConst
        this->CoefMap[i][i] = -this->nuc_list[i].DecayRate();
        
        //Loop over all parents
        for (int j=0; j<this->getParentList(i).size(); j++)
        {
            int J = this->getParentList(i)[j]; //Index in 'Matrix'
            double coef = 0.0;
            double decay = this->getIsotope( this->getParentList(i)[j] ).DecayRate();
            
            //Loop over branches of parent that forms daughter
            for (int k=0; k<this->getBranchList(i, j).size(); k++)
            {
                coef = coef + decay*this->getIsotope( this->getParentList(i)[j] ).BranchFraction( this->getBranchList(i, j)[k] );
            }
            
            //Fill out off-diags
            this->CoefMap[i][J] = coef;
        }
    }
    
    //Loop over all stable nuclides (daughters)
    for (int i=0; i<this->stable_list.size(); i++)
    {
        this->stable_map[this->stable_list[i].IsotopeName()] = i;
        
        //Loop over all parents
        for (int j=0; j<this->getStableParentList(i).size(); j++)
        {
            int J = this->getStableParentList(i)[j]; //Index in 'Matrix'
            double coef = 0.0;
            double decay = this->getIsotope( this->getStableParentList(i)[j] ).DecayRate();
            
            //Loop over branches of parent that forms daughter
            for (int k=0; k<this->getStableBranchList(i, j).size(); k++)
            {
                coef = coef + decay*this->getIsotope( this->getStableParentList(i)[j] ).BranchFraction( this->getStableBranchList(i, j)[k] );
            }
            
            //Fill out map
            this->stable_CoefMap[i][J] = coef;
        }
    }
}

/*
 *	-------------------------------------------------------------------------------------
 *								End: DecayChain Class Definitions
 */

//Executable
int IBIS_SCENARIO(const char *yaml_input)
{
    int success = 0;
    double time;
    yaml_cpp_class nuc_data;
    yaml_cpp_class input_data;
    DecayChain decay;
    
    //Read in the library and set the clock
    time = clock();
    nuc_data.executeYamlRead("database/NuclideLibrary.yml");
    decay.loadNuclides(nuc_data);
    
    //Execule yaml read of input file
    success = input_data.executeYamlRead(yaml_input);
    if (success != 0) {mError(file_dne); return -1;}
    
    //Read the Runtime block
    success = decay.read_conditions(input_data);
    if (success != 0) {mError(read_error); return -1;}
    
    //Read the Isotopes block
    success = decay.read_isotopes(input_data);
    if (success != 0) {mError(read_error); return -1;}
    
    //Run simulations
    success = decay.run_simulation("output/IBIS_Results.txt");
    if (success != 0) {mError(simulation_fail); return -1;}
    
    //End the timer and print final information to screen
    time = clock() - time;
    std::cout << "\nSimulation Runtime: " << (time / CLOCKS_PER_SEC) << " seconds for " << decay.getNumberNuclides()+decay.getNumberStableNuclides() << " isotopes \n";
    
    return success;
}

//Test function
int IBIS_TESTS()
{
    int success = 0;
    double time;
    yaml_cpp_class nuc_data;
    
    //Read in the library (uses ~ 7.3 MB to hold)
    time = clock();
    nuc_data.executeYamlRead("database/NuclideLibrary.yml");
    
    //Test decay chain object
    DecayChain test;
    test.loadNuclides(nuc_data);
    
    //Open a file to print results to
    FILE *file;
    file = fopen("output/IBIS_Results.txt", "w+");
    if (file == nullptr)
    {
        system("mkdir output");
        file = fopen("output/IBIS_Results.txt", "w+");
    }
    fprintf(file, "This is the header\n\n");
    
    //test.registerInitialNuclide("Ba-114");
    //test.registerInitialNuclide("U-235");
    //test.registerInitialNuclide("U-238");
    //test.registerInitialNuclide("U-235");		//Not added to list because it is redundant
    //test.registerInitialNuclide("H-1");		//Not added to list because it is stable
    //test.registerInitialNuclide("O-20");
    //test.registerInitialNuclide("F-20");
    //test.registerInitialNuclide("Na-20");
    //test.registerInitialNuclide("N-20");
    //test.registerInitialNuclide("O-19");
    //test.registerInitialNuclide("N-19");
    //test.registerInitialNuclide("Th-234");
    //test.registerInitialNuclide("He-5");
    //test.registerInitialNuclide("Be-8");
    //test.registerInitialNuclide("Rn-222");
    //test.registerInitialNuclide("n-1");
    
    //test.registerInitialNuclide("Te-132");
    //test.registerInitialNuclide("Xe-132");
    
    //test.registerInitialNuclide("Cf-252");
    //test.registerInitialNuclide("H-3");
    //test.registerInitialNuclide("Tm-172");
    
    //test.registerInitialNuclide("Cd-121");
    //test.registerInitialNuclide("O-20");
    
    /*
     test.registerInitialNuclide("H-3");
     test.registerInitialNuclide("He-6");
     test.registerInitialNuclide("Be-7");
     test.registerInitialNuclide("Be-10");
     test.registerInitialNuclide("Be-11");
     test.registerInitialNuclide("B-12");
     
     test.registerInitialNuclide("N-13");
     test.registerInitialNuclide("C-14");
     test.registerInitialNuclide("C-15");
     test.registerInitialNuclide("N-16");
     test.registerInitialNuclide("Ne-23");
     test.registerInitialNuclide("Na-22");
     
     test.registerInitialNuclide("Na-24");
     test.registerInitialNuclide("Mg-27");
     test.registerInitialNuclide("Al-28");
     test.registerInitialNuclide("Al-26");
     test.registerInitialNuclide("Si-31");
     test.registerInitialNuclide("P-32");
     
     test.registerInitialNuclide("P-33");
     test.registerInitialNuclide("P-34");
     test.registerInitialNuclide("S-35");
     test.registerInitialNuclide("S-37");
     test.registerInitialNuclide("Cl-36");
     test.registerInitialNuclide("Cl-38");
     
     test.registerInitialNuclide("Ar-37");
     test.registerInitialNuclide("Ar-39");
     test.registerInitialNuclide("Ar-41");
     test.registerInitialNuclide("Ar-42");
     test.registerInitialNuclide("K-40");
     test.registerInitialNuclide("K-42");
     
     test.registerInitialNuclide("K-43");
     test.registerInitialNuclide("Ca-41");
     test.registerInitialNuclide("Ca-45");
     test.registerInitialNuclide("Ca-47");
     test.registerInitialNuclide("Ca-48");
     test.registerInitialNuclide("Ca-49");
     test.registerInitialNuclide("Sc-44");
     test.registerInitialNuclide("Sc-46");
     test.registerInitialNuclide("Sc-47");
     test.registerInitialNuclide("Sc-48");
     test.registerInitialNuclide("Sc-49");
     test.registerInitialNuclide("Sc-50");
     
     test.registerInitialNuclide("Ti-45");
     test.registerInitialNuclide("Ti-44");
     test.registerInitialNuclide("Ti-51");
     test.registerInitialNuclide("V-50");
     test.registerInitialNuclide("V-49");
     test.registerInitialNuclide("V-48");
     test.registerInitialNuclide("V-52");
     test.registerInitialNuclide("V-53");
     test.registerInitialNuclide("V-54");
     test.registerInitialNuclide("Cr-51");
     test.registerInitialNuclide("Cr-50");
     test.registerInitialNuclide("Cr-49");
     */
    //test.registerInitialNuclide("Mn-54");
    //test.registerInitialNuclide("Mn-53");
    //test.registerInitialNuclide("Mn-52");
    //test.registerInitialNuclide("Mn-56");
    //test.registerInitialNuclide("Mn-57");
    //test.registerInitialNuclide("Mn-58");
    //test.registerInitialNuclide("Fe-55");
    //test.registerInitialNuclide("Fe-59");
    //test.registerInitialNuclide("Fe-60");
    //test.registerInitialNuclide("Co-58");
    //test.registerInitialNuclide("Co-57");
    //test.registerInitialNuclide("Co-56");
    //test.registerInitialNuclide("Co-55");
    //test.registerInitialNuclide("Co-60");
    //test.registerInitialNuclide("Co-61");
    //test.registerInitialNuclide("Co-62");
    //test.registerInitialNuclide("Ni-57");
    //test.registerInitialNuclide("Ni-59");
    
    //test.registerInitialNuclide("U-238", 10.0); ///NOTE: Must give decimals or state as doubles
    //test.registerInitialNuclide("U-235", 45.0);
    //test.registerInitialNuclide("U-235", 45.0);
    
    //test.registerInitialNuclide("H-3", 1.0);
    //test.registerInitialNuclide("Be-7", 1.0);
    //test.registerInitialNuclide("U-235", 45.0);
    //test.registerInitialNuclide("U-238", 10.0);
    
    std::string nuc = "B-12";
    test.registerInitialNuclide("He-5");
    test.registerInitialNuclide("He-8");
    test.registerInitialNuclide("Li-5");
    test.registerInitialNuclide("Li-9");
    test.registerInitialNuclide("Li-11");
    test.registerInitialNuclide("Be-14");
    test.registerInitialNuclide(nuc);
    
    test.setConsoleOut(true);
    test.createChains();					//Creates list of nuclides and sorts the list from parent to daughter
    test.formEigenvectors();				//Mandatory before solving
    test.verifyEigenSoln();					//Completely optional
    test.setWarnings(true);
    
    //test.getEigenvectors().Display("V");
    test.DisplayEigenMap();
    
    //test.getIsotope( "Te-132" ).setInitialCondition(100.0);
    
    //test.getIsotope("Cf-252").setInitialCondition(1.0);
    //test.getIsotope("Tm-172").setInitialCondition(2.0);
    //test.getIsotope("H-3").setInitialCondition(0.5);
    
    //test.getIsotope("Cd-121").setInitialCondition(1.0);
    //test.getIsotope("O-20").setInitialCondition(2.0);
    
    //test.getIsotope("U-235").setInitialCondition(90);
    //test.getIsotope("U-238").setInitialCondition(10);
    
    for (int i=0; i<test.getNumberNuclides(); i++)
    {
        test.getIsotope(i).setInitialCondition(1.0);
    }
    
    test.print_results(file, seconds, 0.1, 10);			//Print results to file
    
    test.DisplayEigenMap();
    
    std::vector<Atom> air;
    air.resize(4);
    air[0].Register("C");
    air[1].Register("N");
    air[2].Register("O");
    air[3].Register("Ar");
    double density = 0.0012; //g/ccm
    double Wair = 34.0; //eV
    std::vector<double> frac;
    frac.resize(4);
    frac[0] = 0.000124;
    frac[1] = 0.755267;
    frac[2] = 0.231781;
    frac[3] = 0.012827;
    
    //test.getIsotope(nuc).calculateIonization(air, frac, density, Wair);
    
    test.calculateIonizationRate(air, frac, density, Wair);
    
    /**
     std::cout << "\nNuclide Beta Energy Test for " << nuc << " ...\n";
     for (int i=0; i<test.getIsotope(nuc).DecayModes(); i++)
     {
    	std::cout << "Q-value\t" << test.getIsotope(nuc).QValue(i) << std::endl;
     std::cout << "L\t" << test.getIsotope(nuc).deltaJ(i) << std::endl;
    	std::cout << "MeanEnergy\t" << test.getIsotope(nuc).MeanEnergy(i) << std::endl;
     }
     std::cout << "Ion Coeff\t" << test.getIsotope(nuc).IonizationCoeff() << std::endl;
     */
    /**
     for (int i=0; i<test.getNumberNuclides(); i++)
     {
     std::cout << test.getIsotope(i).IsotopeName() << std::endl;
     std::cout << "I (pairs/decay) =\t" << test.getIsotope(i).IonizationCoeff() << std::endl;
     std::cout << "Eta (decays/sec) =\t" << test.getIsotope(i).getActivity() << std::endl;
     std::cout << std::endl;
     }
     */
    std::cout << "\nIon Rate\t" << test.getIonizationRate() << std::endl;
    
    time = clock() - time;
    std::cout << "\nSimulation Runtime: " << (time / CLOCKS_PER_SEC) << " seconds for " << test.getNumberNuclides()+test.getNumberStableNuclides() << " isotopes \n";
    
    //Close the open file
    if (file != nullptr)
        fclose(file);
    
    return success;
}
