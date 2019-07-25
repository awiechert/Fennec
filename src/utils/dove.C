/*!
 *  \file dove.h
 *	\brief Dynamic Ode solver with Various Established methods
 *  \author Austin Ladshaw
 *	\date 09/25/2017
 *	\copyright This software was designed and built at the Georgia Institute
 *             of Technology by Austin Ladshaw for Post-Doc research in the area
 *             of adsorption and surface science. Copyright (c) 2017, all
 *             rights reserved.
 */

#include "dove.h"

/*
 *								Start: Dove Class Definitions
 *	-------------------------------------------------------------------------------------
 */

//solver opt
bool solver_choice(std::string &choice)
{
    bool Linear = false;
    
    std::string copy = choice;
    for (int i=0; i<copy.size(); i++)
        copy[i] = tolower(copy[i]);
    
    if (copy == "linear")
        Linear = true;
    else
        Linear = false;
    
    return Linear;
}

///Function to validate linesearch choice
linesearch_type linesearch_choice(std::string &choice)
{
    linesearch_type type = NO_LS;
    
    std::string copy = choice;
    for (int i=0; i<copy.size(); i++)
        copy[i] = tolower(copy[i]);
    
    if (copy == "none")
        type = NO_LS;
    else if (copy == "bt" || copy == "backtracking")
        type = BT;
    else if (copy == "abt" || copy == "adaptive-backtracking" || copy == "adaptive")
        type = ABT;
    else
        type = NO_LS;
    
    return type;
}

///Function to validate linear solver choice
krylov_method linearsolver_choice(std::string &choice)
{
    krylov_method type = QR;
    
    std::string copy = choice;
    for (int i=0; i<copy.size(); i++)
        copy[i] = tolower(copy[i]);
    
    if (copy == "gmreslp")
        type = GMRESLP;
    else if (copy == "pcg")
        type = PCG;
    else if (copy == "bicgstab")
        type = BiCGSTAB;
    else if (copy == "cgs")
        type = CGS;
    else if (copy == "fom")
        type = FOM;
    else if (copy == "gmresrp")
        type = GMRESRP;
    else if (copy == "gcr")
        type = GCR;
    else if (copy == "gmresr")
        type = GMRESR;
    else if (copy == "kms")
        type = KMS;
    else if (copy == "gmres")
        type = GMRESRP;
    else if (copy == "qr")
        type = QR;
    else
        type = GMRESRP;
    
    return type;
}

///Function to determine whether or not to precondition
bool use_preconditioning(std::string &choice)
{
    bool Precon = false;
    
    std::string copy = choice;
    for (int i=0; i<copy.size(); i++)
        copy[i] = tolower(copy[i]);
    
    if (copy == "none")
        Precon = false;
    else
        Precon = true;
    
    return Precon;
}

///Function to validate preconditioning choice
precond_type preconditioner_choice(std::string &choice)
{
    precond_type type = JACOBI;
    
    std::string copy = choice;
    for (int i=0; i<copy.size(); i++)
        copy[i] = tolower(copy[i]);
    
    if (copy == "jacobi")
        type = JACOBI;
    else if (copy == "tridiagonal" || copy == "tridiag")
        type = TRIDIAG;
    else if (copy == "ugs" || copy == "upper-gs")
        type = UGS;
    else if (copy == "lgs" || copy == "lower-gs")
        type = LGS;
    else if (copy == "sgs" || copy == "symmetric-gs")
        type = SGS;
    else
        type = JACOBI;
    
    return type;
}

///Function to validate timestepper choice
timestep_type timestepper_choice(std::string &choice)
{
    timestep_type type = CONSTANT;
    
    std::string copy = choice;
    for (int i=0; i<copy.size(); i++)
        copy[i] = tolower(copy[i]);
    
    if (copy == "constant")
        type = CONSTANT;
    else if (copy == "adaptive")
        type = ADAPTIVE;
    else if (copy == "fehlberg")
        type = FEHLBERG;
    else if (copy == "ratebased")
        type = RATEBASED;
    else
        type = CONSTANT;
    
    return type;
}

///Function to validate integration method choice
integrate_subtype integration_choice(std::string &choice)
{
    integrate_subtype type = BE;
    
    std::string copy = choice;
    for (int i=0; i<copy.size(); i++)
        copy[i] = tolower(copy[i]);
    
    if (copy == "be" || copy == "backwards-euler")
        type = BE;
    else if (copy == "fe" || copy == "forwards-euler")
        type = FE;
    else if (copy == "bdf2" || copy == "backwards-differentiation-formula-2")
        type = BDF2;
    else if (copy == "cn" || copy == "crank-nicholson")
        type = CN;
    else if (copy == "rk4" || copy == "runge-kutta")
        type = RK4;
    else if (copy == "rkf" || copy == "runge-kutta-fehlberg")
        type = RKF;
    else
        type = BE;
    
    return type;
}

//Default constructor
Dove::Dove()
{
    dt = 0.1;
    dt_old = 0.0;
    time_end = 1.0;
    time_start = 0.0;
    time = 0.0;
    time_old = 0.0;
    time_older = 0.0;
    dtmin = sqrt(DBL_EPSILON);
    dtmax = 100.0;
    tolerance = 1e-4;
    t_count = 0.0;
    t_out = 0.0;
    int_type = IMPLICIT;
    int_sub = BE;
    timestepper = CONSTANT;
    preconditioner = JACOBI;
    Output = nullptr;
    num_func = 1;
    Converged = true;
    user_data = NULL;
    residual = residual_BE;
    precon = NULL;
    newton_dat.LineSearch = true;
    line_type = BT;
    newton_dat.NL_Output = false;
    DoveOutput = false;
    DoveFileOutput = true;
    DoveHeader = false;
    Preconditioner = false;
    newton_dat.lin_tol_abs = 1e-4;
    newton_dat.lin_tol_rel = 0.01;
    newton_dat.nl_tol_abs = 1e-4;
    newton_dat.nl_tol_rel = 1e-6;
    newton_dat.kms_dat.max_level = 1;
    newton_dat.l_maxit = 100;
    linmax = 100;
    newton_dat.nl_maxit = 10;
    Linear = false;
    newton_dat.l_restart = 100;
    AllSteadyState = false;
    timesteps = 0;
}

//Default destructor
Dove::~Dove()
{
    this->user_jacobi.clear();
    this->var_names_hash.clear();
    if (this->Output != nullptr)
        fclose(Output);
}

//Set number of functions
void Dove::set_numfunc(int i)
{
    if (i < 1)
    {
        mError(invalid_size);
        this->un.set_size(1, 1);
        this->unp1.set_size(1, 1);
        this->unm1.set_size(1, 1);
        this->user_func.set_size(1, 1);
        this->user_coeff.set_size(1, 1);
        this->user_jacobi.resize(1);
        this->var_names.set_size(1, 1);
        this->var_names_hash.reserve(1);
        this->var_steady.set_size(1, 1);
        this->num_func = 1;
    }
    else
    {
        this->un.set_size(i, 1);
        this->unp1.set_size(i, 1);
        this->unm1.set_size(i, 1);
        this->user_func.set_size(i, 1);
        this->user_coeff.set_size(i, 1);
        this->user_jacobi.resize(i);
        this->var_names.set_size(i, 1);
        this->var_names_hash.reserve(i);
        this->var_steady.set_size(i, 1);
        this->num_func = i;
    }
    this->set_defaultNames();
    this->set_defaultCoeffs();
    this->set_defaultJacobis();
    this->set_defaultStates();
}

//Set time step to value
void Dove::set_timestep(double d)
{
    if (d <= sqrt(DBL_EPSILON))
        this->dt = sqrt(DBL_EPSILON);
    else
        this->dt = d;
    this->dtmin_con	= this->dt/10.0;
    if (this->dtmin_con <= sqrt(DBL_EPSILON))
        this->dtmin_con = sqrt(DBL_EPSILON);
}

//Set the min dt after convergence
void Dove::set_timestepmin_converged(double d)
{
    if (d <= sqrt(DBL_EPSILON))
        this->dtmin_con = sqrt(DBL_EPSILON);
    else
        this->dtmin_con = d;
}

//Set min dt
void Dove::set_timestepmin(double dmin)
{
    if (dmin <= sqrt(DBL_EPSILON))
        this->dtmin = sqrt(DBL_EPSILON);
    else
        this->dtmin = dmin;
}

//Set max dt
void Dove::set_timestepmax(double dmax)
{
    if (dmax <= sqrt(DBL_EPSILON))
        this->dtmax = sqrt(DBL_EPSILON);
    else
        this->dtmax = dmax;
}

//Set the end time
void Dove::set_endtime(double e)
{
    if (e <= sqrt(DBL_EPSILON))
        this->time_end = sqrt(DBL_EPSILON);
    else
        this->time_end = e;
}

//Set the start time
void Dove::set_starttime(double s)
{
    if (s <= 0.0)
        this->time_start = 0.0;
    else
        this->time_start = s;
}

//Set the type of integration scheme to use
void Dove::set_integrationtype(integrate_subtype type)
{
    this->int_sub = type;
    switch (type)
    {
        case BE:
            this->int_type = IMPLICIT;
            this->residual = residual_BE;
            break;
            
        case FE:
            this->int_type = EXPLICIT;
            this->residual = NULL;
            break;
            
        case CN:
            this->int_type = IMPLICIT;
            this->residual = residual_CN;
            break;
            
        case BDF2:
            this->int_type = IMPLICIT;
            this->residual = residual_BDF2;
            break;
            
        case RK4:
            this->int_type = EXPLICIT;
            this->residual = NULL;
            break;
            
        case RKF:
            this->int_type = EXPLICIT;
            this->residual = NULL;
            break;
            
        default:
            this->int_type = IMPLICIT;
            this->residual = residual_BE;
            break;
    }
}

//Set the type of time stepper
void Dove::set_timestepper(timestep_type type)
{
    this->timestepper = type;
}

//Set the preconditioner type
void Dove::set_preconditioner(precond_type type)
{
    this->preconditioner = type;
}

//Set the output file
void Dove::set_outputfile(FILE *file)
{
    this->Output = file;
}

//Set user data
void Dove::set_userdata(const void *data)
{
    this->user_data = data;
}

//Set the initial condition
void Dove::set_initialcondition(int i, double ic)
{
    this->un.edit(i, 0, ic);
    this->unp1.edit(i, 0, ic);
    this->unm1.edit(i, 0, ic);
}

//Set initial condition
void Dove::set_initialcondition(std::string name, double ic)
{
    this->set_initialcondition(this->getVariableIndex(name), ic);
}

//Set the name of the ith variable
void Dove::set_variableName(int i, std::string name)
{
    this->var_names.edit(i, 0, name);
    this->var_names_hash[name] = i;
}

//Set the ith variable to steady-state
void Dove::set_variableSteadyState(int i)
{
    this->var_steady.edit(i, 0, true);
    this->registerCoeff(i, default_func);
}

//Set variable to steady-state
void Dove::set_variableSteadyState(std::string name)
{
    this->set_variableSteadyState(this->getVariableIndex(name));
}

//Set all variables to steady-state
void Dove::set_variableSteadyStateAll()
{
    for (int i=0; i<this->num_func; i++)
        this->set_variableSteadyState(i);
    this->dt = this->time_end;
    this->AllSteadyState = true;
}

//Set output conditions for Dove
void Dove::set_output(bool choice)
{
    this->DoveOutput = choice;
}

//Set file output
void Dove::set_fileoutput(bool choice)
{
    this->DoveFileOutput = choice;
}

//Set header output
void Dove::set_headeroutput(bool choice)
{
    this->DoveHeader = choice;
}

//Set the tolerance
void Dove::set_tolerance(double tol)
{
    if (tol < MIN_TOL)
        tol = MIN_TOL;
    this->tolerance = tol;
    this->newton_dat.nl_tol_abs = tol;
}

//Set the t_out variable
void Dove::set_t_out(double v)
{
    if (v <= 0.0)
        v = 0.0;
    this->t_out = v;
}

//Set nl_abs_tol
void Dove::set_NonlinearAbsTol(double tol)
{
    this->newton_dat.nl_tol_abs = tol;
}

//Set nl_rel_tol
void Dove::set_NonlinearRelTol(double tol)
{
    this->newton_dat.nl_tol_rel	= tol;
}

//Set l_abs_tol
void Dove::set_LinearAbsTol(double tol)
{
    this->newton_dat.lin_tol_abs = tol;
}

//Set l_rel_tol
void Dove::set_LinearRelTol(double tol)
{
    this->newton_dat.lin_tol_rel = tol;
}

//Set default names
void Dove::set_defaultNames()
{
    char buff[10];
    for (int i=0; i<this->num_func; i++)
    {
        sprintf(buff, "u[%i]",i);
        std::string temp = buff;
        this->var_names.edit(i, 0, temp);
    }
}

//Set the default coeffs
void Dove::set_defaultCoeffs()
{
    for (int i=0; i<this->num_func; i++)
        this->registerCoeff(i, default_coeff);
}

//Set the default jacobi
void Dove::set_defaultJacobis()
{
    for (int i=0; i<this->num_func; i++)
        this->registerJacobi(i, i, default_jacobi);
}

//Set the defaults for variable states
void Dove::set_defaultStates()
{
    for (int i=0; i<this->num_func; i++)
        this->var_steady.edit(i, 0, false);
}

//Set NL output
void Dove::set_NonlinearOutput(bool choice)
{
    this->newton_dat.NL_Output = choice;
}

//Set L output
void Dove::set_LinearOutput(bool choice)
{
    this->newton_dat.L_Output = choice;
}

//Set preconditioning
void Dove::set_Preconditioning(bool choice)
{
    this->Preconditioner = choice;
}

//Set linear method
void Dove::set_LinearMethod(krylov_method choice)
{
    this->newton_dat.linear_solver = choice;
}

//Set the line search method
void Dove::set_LineSearchMethod(linesearch_type choice)
{
    switch (choice)
    {
        case BT:
            this->newton_dat.LineSearch = true;
            this->newton_dat.Bounce = false;
            this->line_type = BT;
            break;
            
        case ABT:
            this->newton_dat.LineSearch = true;
            this->newton_dat.Bounce = true;
            this->line_type = ABT;
            break;
            
        case NO_LS:
            this->newton_dat.LineSearch = false;
            this->newton_dat.Bounce = false;
            this->line_type = NO_LS;
            break;
            
        default:
            this->newton_dat.LineSearch = false;
            this->newton_dat.Bounce = false;
            this->line_type = NO_LS;
            break;
    }
}

//Set number of iterations
void Dove::set_MaxNonLinearIterations(int it)
{
    this->newton_dat.nl_maxit = it;
}

//Set number of iterations
void Dove::set_MaxLinearIterations(int it)
{
    this->newton_dat.l_maxit = it;
    this->linmax = it;
}

//Set restarts
void Dove::set_RestartLimit(int it)
{
    this->newton_dat.l_restart = it;
}

//Set max level of recursion
void Dove::set_RecursionLevel(int level)
{
    this->newton_dat.kms_dat.max_level = level;
}

//Set Linear Status
void Dove::set_LinearStatus(bool choice)
{
    this->Linear = choice;
    if (choice == true)
    {
        this->newton_dat.nl_maxit = 5;
        this->newton_dat.lin_tol_rel = 1e-5;
        this->newton_dat.lin_tol_abs = 1e-4;
    }
}

//Register user function
void Dove::regFunction(int i, double (*func) (int i, const Matrix<double> &u, double t, const void *data, const Dove &dove) )
{
    if ((*func) == NULL)
    {
        mError(nullptr_func);
        this->user_func.edit(i, 0, default_func);
    }
    else
        this->user_func.edit(i, 0, func);
}

//Register name function
void Dove::regFunction(std::string name, double (*func) (int i, const Matrix<double> &u, double t, const void *data, const Dove &dove) )
{
    this->regFunction(this->getVariableIndex(name), func);
}

//Register time coeff functions
void Dove::registerCoeff(int i, double (*coeff) (int i, const Matrix<double> &u, double t, const void *data, const Dove &dove) )
{
    if ((*coeff) == NULL)
        this->user_coeff.edit(i, 0, default_coeff);
    else
    {
        if (this->isSteadyState(i) == true)
            this->user_coeff.edit(i, 0, default_func);
        else
            this->user_coeff.edit(i, 0, coeff);
    }
}

//Register name coeff func
void Dove::registerCoeff(std::string name, double (*func) (int i, const Matrix<double> &u, double t, const void *data, const Dove &dove) )
{
    this->registerCoeff(this->getVariableIndex(name), func);
}

//Register jacobians
void Dove::registerJacobi(int i, int j, double (*jac) (int i, int j, const Matrix<double> &u, double t, const void *data, const Dove &dove) )
{
    if ((*jac) == NULL)
    {
        this->user_jacobi[i][j] = default_jacobi;
    }
    else
    {
        this->user_jacobi[i][j] = jac;
    }
}

//Register jacobians by names
void Dove::registerJacobi(std::string func_name, std::string var_name, double (*jac) (int i, int j, const Matrix<double> &u, double t, const void *data, const Dove &dove) )
{
    int i = this->getVariableIndex(func_name);
    int j = this->getVariableIndex(var_name);
    this->registerJacobi(i, j, jac);
}

//Print out header info to output file
void Dove::print_header(bool addNewLine)
{
    if (this->Output == nullptr)
        this->Output = fopen("output/DOVE_Result.txt", "w+");
    if (this->Output == nullptr)
    {
        system("mkdir output");
        this->Output = fopen("output/DOVE_Result.txt", "w+");
    }
    if (this->DoveHeader == true)
    {
        fprintf(this->Output,"\nIntegration type =\t");
        switch (this->int_type)
        {
            case IMPLICIT:
                fprintf(this->Output,"IMPLICIT\n");
                break;
                
            case EXPLICIT:
                fprintf(this->Output,"EXPLICIT\n");
                break;
                
            default:
                fprintf(this->Output,"IMPLICIT\n");
                break;
        }
        fprintf(this->Output,"Integration scheme =\t");
        switch (this->int_sub)
        {
            case BE:
                fprintf(this->Output,"Backward-Euler\n");
                break;
                
            case FE:
                fprintf(this->Output,"Forward-Euler\n");
                break;
                
            case CN:
                fprintf(this->Output,"Crank-Nicholson\n");
                break;
                
            case BDF2:
                fprintf(this->Output,"Backward-Differentiation-Formula-2\n");
                break;
                
            case RK4:
                fprintf(this->Output,"Runge-Kutta-4\n");
                break;
                
            case RKF:
                fprintf(this->Output,"Runge-Kutta-Fehlberg\n");
                break;
                
            default:
                break;
        }
        fprintf(this->Output,"Timestepper scheme =\t");
        switch (this->timestepper)
        {
            case CONSTANT:
                fprintf(this->Output,"CONSTANT\n");
                break;
                
            case ADAPTIVE:
                fprintf(this->Output,"ADAPTIVE\n");
                break;
                
            case FEHLBERG:
                fprintf(this->Output,"FEHLBERG\n");
                break;
                
            case RATEBASED:
                fprintf(this->Output,"RATEBASED\n");
                break;
                
            default:
                break;
        }
        fprintf(this->Output,"Tolerance =\t%.6g\n", this->tolerance);
    }
    fprintf(this->Output,"Time");
    for (int i=0; i<this->num_func; i++)
        fprintf(this->Output,"\t%s",this->var_names(i,0).c_str());
    if (addNewLine == true)
        fprintf(this->Output,"\n");
}

//Print new result
void Dove::print_newresult(bool addNewLine)
{
    this->t_count = this->t_count + this->dt;
    if (this->t_count >= (this->t_out+sqrt(DBL_EPSILON))
        || this->t_count >= (this->t_out-sqrt(DBL_EPSILON))
        || this->time == this->time_end)
    {
        fprintf(this->Output,"%.6g",this->time);
        for (int i=0; i<this->num_func; i++)
            fprintf(this->Output,"\t%.6g",this->unp1(i,0));
        if (addNewLine == true)
            fprintf(this->Output,"\n");
        this->t_count = 0.0;
    }
}

//Print result
void Dove::print_result(bool addNewLine)
{
    fprintf(this->Output,"%.6g",this->time);
    for (int i=0; i<this->num_func; i++)
        fprintf(this->Output,"\t%.6g",this->un(i,0));
    if (addNewLine == true)
        fprintf(this->Output,"\n");
}

//Set numerical jacobian
void Dove::createJacobian()
{
    int success = NumericalJacobian(this->residual, this->unp1, this->Jacobian, this->num_func, this->num_func, &this->jac_dat, this);
    
    if (success != 0)
    {
        //error!
        std::cout << "error\n";
    }
}

//Return reference to Jacobian
Matrix<double>& Dove::getNumJacobian()
{
    return this->Jacobian;
}

//Return reference to un
Matrix<double>& Dove::getCurrentU()
{
    return this->un;
}

//Return reference to unm1
Matrix<double>& Dove::getOldU()
{
    return this->unm1;
}

//Return reference to unp1
Matrix<double>& Dove::getNewU()
{
    return this->unp1;
}

//Return variable index from given name
int Dove::getVariableIndex(std::string name) const
{
    std::unordered_map<std::string, int>::const_iterator it = this->var_names_hash.find(name);
    
    if (it == this->var_names_hash.end())
    {
        mError(key_not_found);
        return 0;
    }
    else
    {
        return it->second;
    }
}

//Return the variable name
std::string Dove::getVariableName(int i)
{
    return this->var_names(i,0);
}

//Return variable index of maximum rate of change
double Dove::getMaxRate()
{
    double rate = 0.0;
    for (int i=0; i<this->num_func; i++)
    {
        double temp = (this->unp1(i,0) - this->un(i,0))/this->dt;
        double coeff = fabs(this->Eval_Coeff(i, this->unp1, this->time));
        if (coeff > sqrt(DBL_EPSILON))
        {
            temp = temp/coeff;
            if (temp > rate)
                rate = temp;
        }
    }
    return rate;
}

//Return u_n for i
double Dove::getCurrentU(int i, const Matrix<double> &u) const
{
    return this->un(i,0);
}

//Return u_n-1 for i
double Dove::getOldU(int i, const Matrix<double> &u) const
{
    return this->unm1(i,0);
}

//Return u_n+1 for i
double Dove::getNewU(int i, const Matrix<double> &u) const
{
    return u(i,0);
}

//Return u_n for name
double Dove::getCurrentU(std::string name, const Matrix<double> &u) const
{
    return this->un(this->getVariableIndex(name),0);
}

//Return u_n-1 for name
double Dove::getOldU(std::string name, const Matrix<double> &u) const
{
    return this->unm1(this->getVariableIndex(name),0);
}

//Return u_n+1 for name
double Dove::getNewU(std::string name, const Matrix<double> &u) const
{
    return u(this->getVariableIndex(name),0);
}

//Return du_i/dt
double Dove::coupledTimeDerivative(int i, const Matrix<double> &u) const
{
    
    double rn = 0.0;
    if (this->getOldTime() > this->getStartTime())
        rn = this->getTimeStep()/this->getTimeStepOld();
        
        double an, bn, cn;
    an = (1.0 + (2.0*rn)) / (1.0 + rn);
    bn = (1.0 + rn);
    cn = (rn*rn)/(1.0+rn);
    
    //If all variables are steady-state OR if this variable is NOT steady-state, then use user function
    if (this->allSteadyState() == true || this->isSteadyState(i) == false)
        return this->user_func(i,0)(i,u,this->getCurrentTime(),this->user_data, *this);
    //Otherwise, perform a second-order approximation to the time derivative
    else
        return (an*u(i,0)-bn*this->un(i,0)+cn*this->unm1(i,0))/(this->dt);
}

//Return du_name/dt
double Dove::coupledTimeDerivative(std::string name, const Matrix<double> &u) const
{
    int i = this->getVariableIndex(name);
    return this->coupledTimeDerivative(i,u);
}

//Return d(du_i/dt)/du_j
double Dove::coupledDerivativeTimeDerivative(int i, int j, const Matrix<double> &u) const
{
    std::map<int, double (*) (int i, int j, const Matrix<double> &u, double t, const void *data, const Dove &dove)>::const_iterator it = this->user_jacobi[i].find(j);
    if (it == this->user_jacobi[i].end())
    {
        return default_jacobi(i,j,u,this->getCurrentTime(),this->user_data, *this);
    }
    else
    {
        if (this->allSteadyState() == true || this->isSteadyState(i) == false)
            return it->second(i,j,u,this->getCurrentTime(),this->user_data, *this);
        else
            return default_jacobi(i,j,u,this->getCurrentTime(),this->user_data, *this);
    }
}

//Return pointer to user data
const void* Dove::getUserData()
{
    return this->user_data;
}

//Return number of functions
int Dove::getNumFunc() const
{
    return this->num_func;
}

//Return dt
double Dove::getTimeStep() const
{
    return this->dt;
}

//Return dt_old
double Dove::getTimeStepOld() const
{
    return this->dt_old;
}

//Return end time
double Dove::getEndTime() const
{
    return this->time_end;
}

//Return time
double Dove::getCurrentTime() const
{
    return this->time;
}

//Return time old
double Dove::getOldTime() const
{
    return this->time_old;
}

//Return older time
double Dove::getOlderTime() const
{
    return this->time_older;
}

//Return start time
double Dove::getStartTime() const
{
    return this->time_start;
}

//Return dtmin
double Dove::getMinTimeStep()
{
    return this->dtmin;
}

//Return t_out
double Dove::getOutputTime()
{
    return this->t_out;
}

//Return output file
FILE *Dove::getFile()
{
    return this->Output;
}

//Return dtmax
double Dove::getMaxTimeStep()
{
    return this->dtmax;
}

//Return bool for convergence
bool Dove::hasConverged()
{
    return this->Converged;
}

//Return non-linear res
double Dove::getNonlinearResidual()
{
    switch (this->int_sub)
    {
        case BE:
            return this->newton_dat.nl_res;
            break;
            
        case FE:
            return this->tolerance*pow((1.0/0.84),-4.0);
            break;
            
        case CN:
            return this->newton_dat.nl_res;
            break;
            
        case BDF2:
            return this->newton_dat.nl_res;
            break;
            
        case RK4:
            return this->tolerance*pow((1.0/0.84),-4.0);
            break;
            
        default:
            return this->newton_dat.nl_res;
            break;
    }
}

//Return map
std::map<int, double (*) (int i, int j, const Matrix<double> &u, double t, const void *data, const Dove &dove)> & Dove::getJacobiMap(int i)
{
    return this->user_jacobi[i];
}

//Return non-linear rel res
double Dove::getNonlinearRelativeRes()
{
    return this->newton_dat.nl_relres;
}

//Return true if all steady
bool Dove::allSteadyState() const
{
    return this->AllSteadyState;
}

//Return state of ith variable
bool Dove::isSteadyState(int i) const
{
    return this->var_steady(i,0);
}

//Return integrate type
integrate_type Dove::getIntegrationType()
{
    return this->int_type;
}

//Return integrate subtype
integrate_subtype Dove::getIntegrationMethod()
{
    return this->int_sub;
}

//Return time step type
timestep_type Dove::getTimeStepper()
{
    return this->timestepper;
}

//Return preconditioner type
precond_type Dove::getPreconditioner()
{
    return this->preconditioner;
}

//Return line search method
linesearch_type Dove::getLinesearchMethod()
{
    return this->line_type;
}

//Return linear method
krylov_method Dove::getLinearMethod()
{
    if (this->newton_dat.linear_solver == GMRESR)
        return GMRESR;
    else if (this->newton_dat.linear_solver == GMRESLP)
        return GMRESLP;
    else if (this->newton_dat.linear_solver == GMRESRP)
        return GMRESRP;
    else if (this->newton_dat.linear_solver == PCG)
        return PCG;
    else if (this->newton_dat.linear_solver == BiCGSTAB)
        return BiCGSTAB;
    else if (this->newton_dat.linear_solver == CGS)
        return CGS;
    else if (this->newton_dat.linear_solver == FOM)
        return FOM;
    else if (this->newton_dat.linear_solver == GCR)
        return GCR;
    else if (this->newton_dat.linear_solver == KMS)
        return KMS;
    else if (this->newton_dat.linear_solver == QR)
        return QR;
    else
        return QR;
}

//Return true if preconditioned
bool Dove::isPreconditioned()
{
    return this->Preconditioner;
}

//Return abs lin tol
double Dove::getLinearToleranceABS()
{
    return this->newton_dat.lin_tol_abs;
}

//Return rel lin tol
double Dove::getLinearToleranceREL()
{
    return this->newton_dat.lin_tol_rel;
}

//Return abs nl tol
double Dove::getNonlinearToleranceABS()
{
    return this->newton_dat.nl_tol_abs;
}

//Return rel nl tol
double Dove::getNonlinearToleranceREL()
{
    return this->newton_dat.nl_tol_rel;
}

//Max nl it
int Dove::getMaxNonlinearIterations()
{
    return this->newton_dat.nl_maxit;
}

//Max l it
int Dove::getMaxLinearIterations()
{
    return this->linmax;
}

//Return whether the system is linear
bool Dove::isLinear()
{
    return this->Linear;
}

//Return restarts
int Dove::getRestartLevel()
{
    int level = 0;
    switch (this->newton_dat.linear_solver)
    {
        case KMS:
            level = this->newton_dat.l_restart;
            break;
            
        case GMRESR:
            level = this->newton_dat.l_restart;
            break;
            
        case GMRESLP:
            level = this->newton_dat.l_restart;
            break;
            
        case GMRESRP:
            level = this->newton_dat.l_restart;
            break;
            
        case GCR:
            level = this->newton_dat.l_restart;
            break;
            
        default:
            level = this->linmax;
            break;
    }
    return level;
}

//Return recursion level
int Dove::getRecursionLevel()
{
    int level = 0;
    switch (this->newton_dat.linear_solver)
    {
        case KMS:
            level = this->newton_dat.kms_dat.max_level;
            break;
            
        case GMRESR:
            level = 1;
            break;
            
        default:
            level = 0;
            break;
    }
    return level;
}

//Is the name valid?
bool Dove::isValidName(std::string name)
{
    bool valid = false;
    std::unordered_map<std::string, int>::const_iterator it = this->var_names_hash.find(name);
    
    if (it == this->var_names_hash.end())
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    
    return valid;
}

//Compute next time step
double Dove::ComputeTimeStep()
{
    double step = 0.0;
    double rate = 0.0;
    if (this->time == this->time_start)
        return this->dt;
    if (this->Converged == true)
    {
        switch (this->timestepper)
        {
            case CONSTANT:
                step = this->dt;
                break;
                
            case ADAPTIVE:
                step = 1.5 * this->dt;
                if (step >= this->dtmax)
                    step = this->dtmax;
                break;
                
            case FEHLBERG:
                step = 0.84*pow((this->tolerance/this->getNonlinearResidual()),0.25)*this->dt;
                if (step >= this->dtmax)
                    step = this->dtmax;
                if (step <= this->dtmin)
                    step = this->dtmin;
                break;
                
            case RATEBASED:
                rate = this->getMaxRate();
                if (rate <= 1.0)
                    step = this->dt + 0.1*this->dt;
                else
                    step = this->dt - 0.1*this->dt;
                if (step >= this->dtmax)
                    step = this->dtmax;
                if (step <= this->dtmin_con)
                    step = this->dtmin_con;
                break;
                
            default:
                step = this->dt;
                break;
        }
    }
    else
    {
        switch (this->timestepper)
        {
            case CONSTANT:
                this->dtmax = this->dt;
                this->timestepper = ADAPTIVE;
                step = 0.5 * this->dt;
                if (step <= this->dtmin)
                    step = this->dtmin;
                break;
                
            case ADAPTIVE:
                step = 0.5 * this->dt;
                if (step <= this->dtmin)
                    step = this->dtmin;
                break;
                
            case FEHLBERG:
                step = 0.84*pow((this->tolerance/this->getNonlinearResidual()),0.25)*this->dt;
                if (step >= this->dtmax)
                    step = this->dtmax;
                if (step <= this->dtmin)
                    step = this->dtmin;
                break;
                
            case RATEBASED:
                step = 0.5 * this->dt;
                if (step <= this->dtmin)
                    step = this->dtmin;
                break;
                
            default:
                step = this->dt;
                break;
        }
    }
    
    if (this->time_end < step + this->time_old)
        step = this->time_end - this->time_old;
    
    return step;
}

//Eval user function i
double Dove::Eval_Func(int i, const Matrix<double>& u, double t)
{
    return this->user_func(i,0)(i,u,t,this->user_data, *this);
}

//Eval user time coefficient function i
double Dove::Eval_Coeff(int i, const Matrix<double>& u, double t)
{
    return this->user_coeff(i,0)(i,u,t,this->user_data, *this);
}

//Eval user time coefficient function i
double Dove::Eval_Jacobi(int i, int j, const Matrix<double>& u, double t)
{
    std::map<int, double (*) (int i, int j, const Matrix<double> &u, double t, const void *data, const Dove &dove)>::iterator it = this->user_jacobi[i].find(j);
    if (it == this->user_jacobi[i].end())
    {
        return default_jacobi(i,j,u,t,this->user_data, *this);
    }
    else
    {
        return it->second(i,j,u,t,this->user_data, *this);
    }
}

//Function to solve a single timestep
int Dove::solve_timestep()
{
    int success = 0;
    this->validate_method();
    if (this->int_type == IMPLICIT)
    {
        this->validate_linearsteps();
        this->validate_precond();
        success = pjfnk(this->residual, this->precon, this->unp1, &this->newton_dat, this, this);
        this->Converged = this->newton_dat.Converged;
    }
    else
    {
        if (this->allSteadyState() == true)
        {
            mError(explicit_invalid);
            return -1;
        }
        switch (this->int_sub)
        {
            case FE:
                success = this->solve_FE();
                break;
                
            case RK4:
                success = this->solve_RK4();
                break;
                
            case RKF:
                success = this->solve_RKF();
                break;
                
            default:
                success = this->solve_FE();
                break;
        }
    }
    
    //What to do on failure
    if (this->Converged == false)
    {
        if (this->dt == this->dtmin)
        {
            if (this->DoveOutput == true)
                std::cout << "Unable to further reduce time step. CRITICAL ERROR!!!\n";
            success = -1;
        }
        else if (this->dt > this->dtmin || this->allSteadyState() == false)
        {
            if (this->DoveOutput == true)
            {
                if (this->int_sub == RKF)
                    std::cout << "Failed to converge: Residual(" << this->newton_dat.nl_res << ") > Tolerance(" << this->tolerance << ")\n";
                else
                    std::cout << "Failed to converge: Residual(" << this->newton_dat.nl_res << ") > Tolerance(" << this->newton_dat.nl_tol_abs << ")\n";
            }
            if (this->DoveOutput == true)
                std::cout << "Retrying simulation with with new time step: dt_old(" << this->dt << ") --> dt_new(";
            this->dt = this->ComputeTimeStep();
            this->time = this->time_old + this->dt;
            if (this->DoveOutput == true)
                std::cout << this->dt << ") --> for time (" << this->time << ")\n\n";
            success = solve_timestep();
        }
        else
        {
            if (this->DoveOutput == true)
                std::cout << "Unable to further reduce time step. CRITICAL ERROR!!!\n";
            success = -1;
        }
        
    }
    else
        this->timesteps++;
    return success;
}

//Validate and set precond
void Dove::validate_precond()
{
    if (this->Preconditioner == true)
    {
        switch (this->preconditioner)
        {
            case JACOBI:
                switch (this->int_sub)
            {
                case BE:
                    this->precon = precond_Jac_BE;
                    break;
                    
                case FE:
                    this->precon = NULL;
                    break;
                    
                case CN:
                    this->precon = precond_Jac_CN;
                    break;
                    
                case BDF2:
                    this->precon = precond_Jac_BDF2;
                    break;
                    
                case RK4:
                    this->precon = NULL;
                    break;
                    
                case RKF:
                    this->precon = NULL;
                    break;
                    
                default:
                    this->precon = precond_Jac_BE;
                    break;
                    
            }
                break;
                
            case TRIDIAG:
                switch (this->int_sub)
            {
                case BE:
                    this->precon = precond_Tridiag_BE;
                    break;
                    
                case FE:
                    this->precon = NULL;
                    break;
                    
                case CN:
                    this->precon = precond_Tridiag_CN;
                    break;
                    
                case BDF2:
                    this->precon = precond_Tridiag_BDF2;
                    break;
                    
                case RK4:
                    this->precon = NULL;
                    break;
                    
                case RKF:
                    this->precon = NULL;
                    break;
                    
                default:
                    this->precon = NULL;
                    break;
                    
            }
                break;
                
            case UGS:
                switch (this->int_sub)
            {
                case BE:
                    this->precon = precond_UpperGS_BE;
                    break;
                    
                case FE:
                    this->precon = NULL;
                    break;
                    
                case CN:
                    this->precon = precond_UpperGS_CN;
                    break;
                    
                case BDF2:
                    this->precon = precond_UpperGS_BDF2;
                    break;
                    
                case RK4:
                    this->precon = NULL;
                    break;
                    
                case RKF:
                    this->precon = NULL;
                    break;
                    
                default:
                    this->precon = NULL;
                    break;
                    
            }
                break;
                
            case LGS:
                switch (this->int_sub)
            {
                case BE:
                    this->precon = precond_LowerGS_BE;
                    break;
                    
                case FE:
                    this->precon = NULL;
                    break;
                    
                case CN:
                    this->precon = precond_LowerGS_CN;
                    break;
                    
                case BDF2:
                    this->precon = precond_LowerGS_BDF2;
                    break;
                    
                case RK4:
                    this->precon = NULL;
                    break;
                    
                case RKF:
                    this->precon = NULL;
                    break;
                    
                default:
                    this->precon = NULL;
                    break;
                    
            }
                break;
                
            case SGS:
                switch (this->int_sub)
            {
                case BE:
                    this->precon = precond_SymmetricGS_BE;
                    break;
                    
                case FE:
                    this->precon = NULL;
                    break;
                    
                case CN:
                    this->precon = precond_SymmetricGS_CN;
                    break;
                    
                case BDF2:
                    this->precon = precond_SymmetricGS_BDF2;
                    break;
                    
                case RK4:
                    this->precon = NULL;
                    break;
                    
                case RKF:
                    this->precon = NULL;
                    break;
                    
                default:
                    this->precon = NULL;
                    break;
                    
            }
                break;
                
            default:
                switch (this->int_sub)
            {
                case BE:
                    this->precon = precond_Jac_BE;
                    break;
                    
                case FE:
                    this->precon = NULL;
                    break;
                    
                case CN:
                    this->precon = precond_Jac_CN;
                    break;
                    
                case BDF2:
                    this->precon = precond_Jac_BDF2;
                    break;
                    
                case RK4:
                    this->precon = NULL;
                    break;
                    
                case RKF:
                    this->precon = NULL;
                    break;
                    
                default:
                    this->precon = precond_Jac_BE;
                    break;
                    
            }
                break;
        }
    }
    else
        this->precon = NULL;
}

//Validate linear iterations
void Dove::validate_linearsteps()
{
    //Check the method requested and set max iterations appropriately
    switch (this->newton_dat.linear_solver)
    {
        case KMS:
            this->newton_dat.l_maxit = this->linmax/this->newton_dat.l_restart/(1+this->newton_dat.kms_dat.max_level);
            break;
            
        case GMRESRP:
            this->newton_dat.l_maxit = this->linmax/this->newton_dat.l_restart;
            break;
            
        case GMRESLP:
            this->newton_dat.l_maxit = this->linmax/this->newton_dat.l_restart;
            break;
            
        case GCR:
            this->newton_dat.l_maxit = this->linmax/this->newton_dat.l_restart;
            break;
            
        case GMRESR:
            this->newton_dat.l_maxit = this->linmax/this->newton_dat.l_restart/2;
            break;
            
        default:
            break;
    }
    
}

//Validate time integration method
void Dove::validate_method()
{
    if (this->allSteadyState() == true)
    {
        this->set_integrationtype(BE);
        this->dt = this->time_end;
        this->time = this->time_end;
        return;
    }
    for (int i=0; i<this->num_func; i++)
    {
        if (this->isSteadyState(i) == true)
        {
            //Check the method that was set and use BE or BDF2 for level of accuracy
            switch (this->int_sub)
            {
                case BE:
                    this->set_integrationtype(BE);
                    break;
                    
                case FE:
                    this->set_integrationtype(BE);
                    break;
                    
                case CN:
                    this->set_integrationtype(BDF2);
                    break;
                    
                case BDF2:
                    this->set_integrationtype(BDF2);
                    break;
                    
                case RK4:
                    this->set_integrationtype(BDF2);
                    break;
                    
                case RKF:
                    this->set_integrationtype(BDF2);
                    break;
                    
                default:
                    this->set_integrationtype(BE);
                    break;
            }
            
            return;
        }
    }
}

//Update solution states
void Dove::update_states()
{
    this->unm1 = this->un;
    this->un = this->unp1;
    this->dt_old = this->dt;
    this->time_older = this->time_old;
    this->time_old = this->time;
    if (this->Linear == true)
        this->unp1.zeros();
    else
        this->unp1 = this->un*1.5 - this->unm1*0.5;
}

//Update the time step
void Dove::update_timestep()
{
    this->dt = this->ComputeTimeStep();
    this->time = this->time_old + this->dt;
}

//Reset all states
void Dove::reset_all()
{
    this->time = this->time_start;
    this->time_old = this->time_start;
    this->time_older = this->time_start;
    this->dt_old = 0.0;
    this->Converged = true;
}

//Function to solve all states and print output to file
int Dove::solve_all()
{
    int success = 0;
    this->reset_all();
    if (this->DoveFileOutput == true)
    {
        this->print_header(true);
        this->print_result(true);
    }
    if (this->DoveOutput == true)
    {
        std::cout << "Dove Scheme: ";
        switch (this->int_sub)
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
    do
    {
        this->update_timestep();
        if (this->DoveOutput == true)
        {
            std::cout << "\nSolving (" << this->getNumFunc() << ") equation(s) at time (" << this->time << ") with time step (" << this->dt << "). Please wait...\n";
        }
        success = this->solve_timestep();
        if (success != 0)
        {
            mError(simulation_fail);
            return -1;
        }
        if (this->DoveFileOutput == true)
            this->print_newresult(true);
        this->update_states();
    } while (this->time_end > (this->time+this->dtmin));
    if (this->DoveOutput == true)
        std::cout << "------------------------------------------------------\n\n";
    
    return success;
}

//Function to solve with Forward-Euler
int Dove::solve_FE()
{
    int success = 0;
    
    for (int i=0; i<this->num_func; i++)
    {
        double value = ( (this->Eval_Coeff(i, this->un, this->time_old)*this->un(i,0)) + (this->getTimeStep()*this->Eval_Func(i, this->un, this->time_old)) )/this->Eval_Coeff(i, this->un, this->time);
        this->unp1.edit(i, 0, value );
        
        if (isinf(value) || isnan(value))
        {
            std::cout << "Equation for variable " << this->getVariableName(i) << " failed and produced " << value << std::endl;
            std::cout << "Rate expression produced " << this->Eval_Func(i, this->un, this->time_old) << std::endl;
            std::cout << "Variable List \n";
            this->un.Display("un");
            this->Converged = false;
            return -1;
        }
    }
    this->Converged = true;
    return success;
}

//Function to solve with Runge-Kutta-4
int Dove::solve_RK4()
{
    int success = 0;
    Matrix<double> temp;
    temp.set_size(this->num_func, 1);
    for (int i=0; i<this->num_func; i++)
    {
        double k1,k2,k3,k4;
        temp = this->un;
        k1 = this->dt*this->Eval_Func(i, temp, this->time_old);
        temp(i,0) = this->un(i,0) + (k1/2.0);
        k2 = this->dt*this->Eval_Func(i, temp, this->time_old+(this->dt/2.0));
        temp(i,0) = this->un(i,0) + (k2/2.0);
        k3 = this->dt*this->Eval_Func(i, temp, this->time_old+(this->dt/2.0));
        temp(i,0) = this->un(i,0) + k3;
        k4 = this->dt*this->Eval_Func(i, temp, this->time);
        
        double value = ( (this->Eval_Coeff(i, this->un, this->time_old)*this->un(i,0)) + ((k1+(2.0*(k2+k3))+k4)/6.0) )/this->Eval_Coeff(i, this->un, this->time_old);
        
        this->unp1.edit(i, 0, value );
        
        if (isinf(value) || isnan(value))
        {
            std::cout << "Equation for variable " << this->getVariableName(i) << " failed and produced " << value << std::endl;
            std::cout << "Rate expression produced " << this->Eval_Func(i, this->un, this->time_old) << std::endl;
            std::cout << "Variable List \n";
            this->un.Display("un");
            this->Converged = false;
            return -1;
        }
    }
    this->Converged = true;
    return success;
}

//Function to solve with Runge-Kutta-Fehlberg
int Dove::solve_RKF()
{
    int success = 0;
    double res = 0.0;
    Matrix<double> temp;
    temp.set_size(this->num_func, 1);
    for (int i=0; i<this->num_func; i++)
    {
        double k1,k2,k3,k4,k5,k6;
        temp = this->un;
        k1 = this->dt*this->Eval_Func(i, temp, this->time_old);
        temp(i,0) = this->un(i,0) + (k1/4.0);
        k2 = this->dt*this->Eval_Func(i, temp, this->time_old+(this->dt/4.0));
        temp(i,0) = this->un(i,0) + (3.0*k1/32.0) + (9.0*k2/32.0);
        k3 = this->dt*this->Eval_Func(i, temp, this->time_old+(3.0*this->dt/8.0));
        temp(i,0) = this->un(i,0) + (1932.0*k1/2197.0) - (7200.0*k2/2197.0) + (7296.0*k3/2197.0);
        k4 = this->dt*this->Eval_Func(i, temp, this->time_old+(12.0*this->dt/13.0));
        temp(i,0) = this->un(i,0) + (439.0*k1/216.0) - (8.0*k2) + (3680.0*k3/513.0) - (845.0*k4/4104.0);
        k5 = this->dt*this->Eval_Func(i, temp, this->time);
        temp(i,0) = this->un(i,0) - (8.0*k1/27.0) + (2.0*k2) - (3544.0*k3/2565.0) + (1859.0*k4/4104.0) - (11.0*k5/40.0);
        k6 = this->dt*this->Eval_Func(i, temp, this->time_old+(this->dt/2.0));
        
        double value = ( (this->Eval_Coeff(i, this->un, this->time_old)*this->un(i,0)) + ( (25.0*k1/216.0)+(1408.0*k3/2565.0)+(2197.0*k4/4104.0)-(k5/5.0) ) )/this->Eval_Coeff(i, this->un, this->time_old);
        double value_til = ( (this->Eval_Coeff(i, this->un, this->time_old)*this->un(i,0)) + ( (16.0*k1/135.0)+(6656.0*k3/12825.0)+(28561.0*k4/56430.0)-(9.0*k5/50.0)+(2.0*k6/55.0) ) )/this->Eval_Coeff(i, this->un, this->time_old);
        
        this->unp1.edit(i, 0, value );
        if (fabs(value_til - value)/this->dt > res)
            res = fabs(value_til - value)/this->dt;
        
        if (isinf(value) || isnan(value))
        {
            std::cout << "Equation for variable " << this->getVariableName(i) << " failed and produced " << value << std::endl;
            std::cout << "Rate expression produced " << this->Eval_Func(i, this->un, this->time_old) << std::endl;
            std::cout << "Variable List \n";
            this->un.Display("un");
            this->Converged = false;
            return -1;
        }
    }
    this->newton_dat.nl_res = res;
    if (res > this->tolerance)
        this->Converged = false;
    else
        this->Converged = true;
    return success;
}

/*
 *	-------------------------------------------------------------------------------------
 *								End: Dove Class Definitions
 */

//Function for implicit-BE method residual
int residual_BE(const Matrix<double> &u, Matrix<double> &Res, const void *data)
{
    int success = 0;
    Dove *dat = (Dove *) data;
    
    for (int i=0; i<dat->getNumFunc(); i++)
    {
        Res(i,0) = (dat->Eval_Coeff(i, u, dat->getCurrentTime())*u(i,0)) - (dat->Eval_Coeff(i, dat->getCurrentU(),dat->getOldTime())*dat->getCurrentU()(i,0)) - (dat->getTimeStep()*dat->Eval_Func(i, u,dat->getCurrentTime()));
    }
    
    return success;
}

//Jacobi preconditioning for BE
int precond_Jac_BE(const Matrix<double> &v, Matrix<double> &p, const void *data)
{
    int success = 0;
    Dove *dat = (Dove *) data;
    for (int i=0; i<dat->getNumFunc(); i++)
    {
        double Dii = (dat->Eval_Coeff(i, dat->getNewU(), dat->getCurrentTime()) - (dat->getTimeStep()*dat->Eval_Jacobi(i,i, dat->getNewU(),dat->getCurrentTime())));
        if (fabs(Dii) <= MIN_TOL)
            Dii = 1.0;
        p.edit(i, 0, v(i,0) / Dii);
    }
    return success;
}

//Tridiagonal preconditioning for BE
int precond_Tridiag_BE(const Matrix<double> &v, Matrix<double> &p, const void *data)
{
    int success = 0;
    Dove *dat = (Dove *) data;
    double d[dat->getNumFunc()], a[dat->getNumFunc()], c[dat->getNumFunc()];
    double dp[dat->getNumFunc()], ap[dat->getNumFunc()];
    
    //Forward Sweep
    for (int i=0; i<dat->getNumFunc(); i++)
    {
        double Dii = (dat->Eval_Coeff(i, dat->getNewU(), dat->getCurrentTime()) - (dat->getTimeStep()*dat->Eval_Jacobi(i,i, dat->getNewU(),dat->getCurrentTime())));
        d[i] = v(i,0) / Dii;
        if (i == 0)
        {
            a[i] = 0.0;
            c[i] = -(dat->getTimeStep()*dat->Eval_Jacobi(i,i+1, dat->getNewU(),dat->getCurrentTime()))/Dii;
        }
        else if (i == dat->getNumFunc()-1)
        {
            c[i] = 0.0;
            a[i] = -(dat->getTimeStep()*dat->Eval_Jacobi(i,i-1, dat->getNewU(),dat->getCurrentTime()))/Dii;
        }
        else
        {
            a[i] = -(dat->getTimeStep()*dat->Eval_Jacobi(i,i-1, dat->getNewU(),dat->getCurrentTime()))/Dii;
            c[i] = -(dat->getTimeStep()*dat->Eval_Jacobi(i,i+1, dat->getNewU(),dat->getCurrentTime()))/Dii;
        }
    }
    
    //Reverse Sweep
    for (int i=(dat->getNumFunc()-1); i>=0; i--)
    {
        if (i==(dat->getNumFunc()-1))
        {
            dp[i] = d[i];
            ap[i] = a[i];
        }
        else if (i==0)
        {
            dp[i] = (d[i] - (c[i]*dp[(i+1)])) / (1 - (c[i]*ap[(i+1)]));
            ap[i] = 0;
        }
        else
        {
            dp[i] = (d[i] - (c[i]*dp[(i+1)])) / (1 - (c[i]*ap[(i+1)]));
            ap[i] = a[i] / (1 - (c[i]*ap[(i+1)]));
        }
    }
    
    //Final Forward Sweep
    for (int i=0; i<dat->getNumFunc(); i++)
    {
        if (i==0)
            p.edit(i, 0, dp[i]);
        else
            p.edit(i, 0, dp[i] - (ap[i] * p(i-1,0)));
    }
    
    return success;
}

//Upper Gauss Seidel Preconditioner (solve Up=v)
int precond_UpperGS_BE(const Matrix<double> &v, Matrix<double> &p, const void *data)
{
    int success = 0;
    Dove *dat = (Dove *) data;
    
    double sum_upper = 0.0, sum_lower = 0.0;
    std::map<int, double (*) (int i, int j, const Matrix<double> &u, double t, const void *data, const Dove &dove)>::reverse_iterator rit;
    std::map<int, double (*) (int i, int j, const Matrix<double> &u, double t, const void *data, const Dove &dove)>::iterator it;
    
    //Loop over rows
    for (int i=dat->getNumFunc()-1; i>=0; i--)
    {
        sum_upper = 0.0;
        sum_lower = 0.0;
        
        //Forward iterator
        for (it = dat->getJacobiMap(i).begin(); it->first<i; it++)
        {
            sum_lower = sum_lower + (-dat->getTimeStep()*it->second(i, it->first, dat->getNewU(), dat->getCurrentTime(),dat->getUserData(),*dat)*p(it->first,0));
        }
        
        //Iterate through the Jacobian map for the ith row (reverse iterator)
        for (rit = dat->getJacobiMap(i).rbegin(); rit->first>i; rit++)
        {
            sum_upper = sum_upper + (-dat->getTimeStep()*rit->second(i, rit->first, dat->getNewU(), dat->getCurrentTime(),dat->getUserData(),*dat)*p(rit->first,0));
        }
        double value = dat->Eval_Coeff(i, dat->getNewU(), dat->getCurrentTime());
        if (rit->first == i)
            value += -(dat->getTimeStep()*rit->second(i,rit->first, dat->getNewU(),dat->getCurrentTime(), dat->getUserData(),*dat));
        p.edit(i, 0, (v(i,0)-sum_upper-sum_lower)/value);
    }
    
    return success;
}

//Lower Gauss Seidel Preconditioner (Lp=v)
int precond_LowerGS_BE(const Matrix<double> &v, Matrix<double> &p, const void *data)
{
    int success = 0;
    Dove *dat = (Dove *) data;
    double sum_lower = 0.0, sum_upper = 0.0;
    std::map<int, double (*) (int i, int j, const Matrix<double> &u, double t, const void *data, const Dove &dove)>::iterator it;
    std::map<int, double (*) (int i, int j, const Matrix<double> &u, double t, const void *data, const Dove &dove)>::reverse_iterator rit;
    
    //Loop over rows
    for (int i=0; i<dat->getNumFunc(); i++)
    {
        sum_lower = 0.0;
        sum_upper = 0.0;
        
        //Reverse iterator
        for (rit = dat->getJacobiMap(i).rbegin(); rit->first>i; rit++)
        {
            sum_upper = sum_upper + (-dat->getTimeStep()*rit->second(i, rit->first, dat->getNewU(), dat->getCurrentTime(),dat->getUserData(),*dat)*p(rit->first,0));
        }
        
        //Iterate through the Jacobian map for the ith row (forward iterator)
        for (it = dat->getJacobiMap(i).begin(); it->first<i; it++)
        {
            sum_lower = sum_lower + (-dat->getTimeStep()*it->second(i, it->first, dat->getNewU(), dat->getCurrentTime(),dat->getUserData(),*dat)*p(it->first,0));
        }
        double value = dat->Eval_Coeff(i, dat->getNewU(), dat->getCurrentTime());
        if (it->first == i)
            value += -(dat->getTimeStep()*it->second(i,it->first, dat->getNewU(),dat->getCurrentTime(), dat->getUserData(),*dat));
        p.edit(i, 0, (v(i,0)-sum_lower-sum_upper)/value);
    }
    
    return success;
}

//Symmetric Gauss Seidel Preconditioner
int precond_SymmetricGS_BE(const Matrix<double> &v, Matrix<double> &p, const void *data)
{
    int success = 0;
    
    success = precond_UpperGS_BE(v, p, data);
    success = precond_LowerGS_BE(v, p, data);
    
    return success;
}

//Function for implicit-CN method residual
int residual_CN(const Matrix<double> &u, Matrix<double> &Res, const void *data)
{
    int success = 0;
    Dove *dat = (Dove *) data;
    
    for (int i=0; i<dat->getNumFunc(); i++)
    {
        Res(i,0) = (dat->Eval_Coeff(i, u, dat->getCurrentTime())*u(i,0)) - (dat->Eval_Coeff(i, dat->getCurrentU(), dat->getOldTime())*dat->getCurrentU()(i,0)) - (0.5*dat->getTimeStep()*dat->Eval_Func(i, u, dat->getCurrentTime())) - (0.5*dat->getTimeStep()*dat->Eval_Func(i, dat->getCurrentU(), dat->getOldTime()));
    }
    
    return success;
}

//Jacobi preconditioning for CN
int precond_Jac_CN(const Matrix<double> &v, Matrix<double> &p, const void *data)
{
    int success = 0;
    Dove *dat = (Dove *) data;
    for (int i=0; i<dat->getNumFunc(); i++)
    {
        double Dii = (dat->Eval_Coeff(i, dat->getNewU(), dat->getCurrentTime()) - (0.5*dat->getTimeStep()*dat->Eval_Jacobi(i,i, dat->getNewU(),dat->getCurrentTime())));
        if (fabs(Dii) <= MIN_TOL)
            Dii = 1.0;
        p.edit(i, 0, v(i,0) / Dii);
    }
    return success;
}

//Tridiagonal preconditioning for CN
int precond_Tridiag_CN(const Matrix<double> &v, Matrix<double> &p, const void *data)
{
    int success = 0;
    Dove *dat = (Dove *) data;
    double d[dat->getNumFunc()], a[dat->getNumFunc()], c[dat->getNumFunc()];
    double dp[dat->getNumFunc()], ap[dat->getNumFunc()];
    
    //Forward Sweep
    for (int i=0; i<dat->getNumFunc(); i++)
    {
        double Dii = (dat->Eval_Coeff(i, dat->getNewU(), dat->getCurrentTime()) - (0.5*dat->getTimeStep()*dat->Eval_Jacobi(i,i, dat->getNewU(),dat->getCurrentTime())));
        d[i] = v(i,0) / Dii;
        if (i == 0)
        {
            a[i] = 0.0;
            c[i] = -(0.5*dat->getTimeStep()*dat->Eval_Jacobi(i,i+1, dat->getNewU(),dat->getCurrentTime()))/Dii;
        }
        else if (i == dat->getNumFunc()-1)
        {
            c[i] = 0.0;
            a[i] = -(0.5*dat->getTimeStep()*dat->Eval_Jacobi(i,i-1, dat->getNewU(),dat->getCurrentTime()))/Dii;
        }
        else
        {
            a[i] = -(0.5*dat->getTimeStep()*dat->Eval_Jacobi(i,i-1, dat->getNewU(),dat->getCurrentTime()))/Dii;
            c[i] = -(0.5*dat->getTimeStep()*dat->Eval_Jacobi(i,i+1, dat->getNewU(),dat->getCurrentTime()))/Dii;
        }
    }
    
    //Reverse Sweep
    for (int i=(dat->getNumFunc()-1); i>=0; i--)
    {
        if (i==(dat->getNumFunc()-1))
        {
            dp[i] = d[i];
            ap[i] = a[i];
        }
        else if (i==0)
        {
            dp[i] = (d[i] - (c[i]*dp[(i+1)])) / (1 - (c[i]*ap[(i+1)]));
            ap[i] = 0;
        }
        else
        {
            dp[i] = (d[i] - (c[i]*dp[(i+1)])) / (1 - (c[i]*ap[(i+1)]));
            ap[i] = a[i] / (1 - (c[i]*ap[(i+1)]));
        }
    }
    
    //Final Forward Sweep
    for (int i=0; i<dat->getNumFunc(); i++)
    {
        if (i==0)
            p.edit(i, 0, dp[i]);
        else
            p.edit(i, 0, dp[i] - (ap[i] * p(i-1,0)));
    }
    
    return success;
}

//Upper Gauss Seidel Preconditioner (solve Up=v)
int precond_UpperGS_CN(const Matrix<double> &v, Matrix<double> &p, const void *data)
{
    int success = 0;
    Dove *dat = (Dove *) data;
    
    double sum_upper = 0.0, sum_lower = 0.0;
    std::map<int, double (*) (int i, int j, const Matrix<double> &u, double t, const void *data, const Dove &dove)>::reverse_iterator rit;
    std::map<int, double (*) (int i, int j, const Matrix<double> &u, double t, const void *data, const Dove &dove)>::iterator it;
    
    //Loop over rows
    for (int i=dat->getNumFunc()-1; i>=0; i--)
    {
        sum_upper = 0.0;
        sum_lower = 0.0;
        
        //Forward iterator
        for (it = dat->getJacobiMap(i).begin(); it->first<i; it++)
        {
            sum_lower = sum_lower + (-0.5*dat->getTimeStep()*it->second(i, it->first, dat->getNewU(), dat->getCurrentTime(),dat->getUserData(),*dat)*p(it->first,0));
        }
        
        //Iterate through the Jacobian map for the ith row (reverse iterator)
        for (rit = dat->getJacobiMap(i).rbegin(); rit->first>i; rit++)
        {
            sum_upper = sum_upper + (-0.5*dat->getTimeStep()*rit->second(i, rit->first, dat->getNewU(), dat->getCurrentTime(),dat->getUserData(),*dat)*p(rit->first,0));
        }
        double value = dat->Eval_Coeff(i, dat->getNewU(), dat->getCurrentTime());
        if (rit->first == i)
            value += -(0.5*dat->getTimeStep()*rit->second(i,rit->first, dat->getNewU(),dat->getCurrentTime(), dat->getUserData(),*dat));
        p.edit(i, 0, (v(i,0)-sum_upper-sum_lower)/value);
    }
    
    return success;
}

//Lower Gauss Seidel Preconditioner (Lp=v)
int precond_LowerGS_CN(const Matrix<double> &v, Matrix<double> &p, const void *data)
{
    int success = 0;
    Dove *dat = (Dove *) data;
    double sum_lower = 0.0, sum_upper = 0.0;
    std::map<int, double (*) (int i, int j, const Matrix<double> &u, double t, const void *data, const Dove &dove)>::iterator it;
    std::map<int, double (*) (int i, int j, const Matrix<double> &u, double t, const void *data, const Dove &dove)>::reverse_iterator rit;
    
    //Loop over rows
    for (int i=0; i<dat->getNumFunc(); i++)
    {
        sum_lower = 0.0;
        sum_upper = 0.0;
        
        //Reverse iterator
        for (rit = dat->getJacobiMap(i).rbegin(); rit->first>i; rit++)
        {
            sum_upper = sum_upper + (-0.5*dat->getTimeStep()*rit->second(i, rit->first, dat->getNewU(), dat->getCurrentTime(),dat->getUserData(),*dat)*p(rit->first,0));
        }
        
        //Iterate through the Jacobian map for the ith row (forward iterator)
        for (it = dat->getJacobiMap(i).begin(); it->first<i; it++)
        {
            sum_lower = sum_lower + (-0.5*dat->getTimeStep()*it->second(i, it->first, dat->getNewU(), dat->getCurrentTime(),dat->getUserData(),*dat)*p(it->first,0));
        }
        double value = dat->Eval_Coeff(i, dat->getNewU(), dat->getCurrentTime());
        if (it->first == i)
            value += -(0.5*dat->getTimeStep()*it->second(i,it->first, dat->getNewU(),dat->getCurrentTime(), dat->getUserData(),*dat));
        p.edit(i, 0, (v(i,0)-sum_lower-sum_upper)/value);
    }
    
    return success;
}

//Symmetric Gauss Seidel Preconditioner
int precond_SymmetricGS_CN(const Matrix<double> &v, Matrix<double> &p, const void *data)
{
    int success = 0;
    
    success = precond_UpperGS_CN(v, p, data);
    success = precond_LowerGS_CN(v, p, data);
    
    return success;
}

//Function for implicit-BDF2 method residual
int residual_BDF2(const Matrix<double> &u, Matrix<double> &Res, const void *data)
{
    int success = 0;
    Dove *dat = (Dove *) data;
    
    double rn = 0.0;
    if (dat->getOldTime() > dat->getStartTime())
        rn = dat->getTimeStep()/dat->getTimeStepOld();
    
    double an, bn, cn;
    an = (1.0 + (2.0*rn)) / (1.0 + rn);
    bn = (1.0 + rn);
    cn = (rn*rn)/(1.0+rn);
    
    for (int i=0; i<dat->getNumFunc(); i++)
    {
        Res(i,0) = (an*dat->Eval_Coeff(i, u, dat->getCurrentTime())*u(i,0)) - (bn*dat->Eval_Coeff(i, dat->getCurrentU(), dat->getOldTime())*dat->getCurrentU()(i,0)) + (cn*dat->Eval_Coeff(i, dat->getOldU(), dat->getOlderTime())*dat->getOldU()(i,0)) - (dat->getTimeStep()*dat->Eval_Func(i, u, dat->getCurrentTime()));
    }
    
    return success;
}

//Jacobi preconditioning for BDF2
int precond_Jac_BDF2(const Matrix<double> &v, Matrix<double> &p, const void *data)
{
    int success = 0;
    Dove *dat = (Dove *) data;
    
    double rn = 0.0;
    if (dat->getOldTime() > 0.0)
        rn = dat->getTimeStep()/dat->getTimeStepOld();
    
    double an;
    an = (1.0 + (2.0*rn)) / (1.0 + rn);
    
    for (int i=0; i<dat->getNumFunc(); i++)
    {
        double Dii = (an*dat->Eval_Coeff(i, dat->getNewU(), dat->getCurrentTime()) - (dat->getTimeStep()*dat->Eval_Jacobi(i,i, dat->getNewU(),dat->getCurrentTime())));
        if (fabs(Dii) <= MIN_TOL)
            Dii = 1.0;
        p.edit(i, 0, v(i,0) / Dii);
    }
    return success;
}

//Tridiagonal preconditioning for BDF2
int precond_Tridiag_BDF2(const Matrix<double> &v, Matrix<double> &p, const void *data)
{
    int success = 0;
    Dove *dat = (Dove *) data;
    double d[dat->getNumFunc()], a[dat->getNumFunc()], c[dat->getNumFunc()];
    double dp[dat->getNumFunc()], ap[dat->getNumFunc()];
    
    double rn = 0.0;
    if (dat->getOldTime() > 0.0)
        rn = dat->getTimeStep()/dat->getTimeStepOld();
    
    double an;
    an = (1.0 + (2.0*rn)) / (1.0 + rn);
    
    //Forward Sweep
    for (int i=0; i<dat->getNumFunc(); i++)
    {
        double Dii = (an*dat->Eval_Coeff(i, dat->getNewU(), dat->getCurrentTime()) - (dat->getTimeStep()*dat->Eval_Jacobi(i,i, dat->getNewU(),dat->getCurrentTime())));
        d[i] = v(i,0) / Dii;
        if (i == 0)
        {
            a[i] = 0.0;
            c[i] = -(dat->getTimeStep()*dat->Eval_Jacobi(i,i+1, dat->getNewU(),dat->getCurrentTime()))/Dii;
        }
        else if (i == dat->getNumFunc()-1)
        {
            c[i] = 0.0;
            a[i] = -(dat->getTimeStep()*dat->Eval_Jacobi(i,i-1, dat->getNewU(),dat->getCurrentTime()))/Dii;
        }
        else
        {
            a[i] = -(dat->getTimeStep()*dat->Eval_Jacobi(i,i-1, dat->getNewU(),dat->getCurrentTime()))/Dii;
            c[i] = -(dat->getTimeStep()*dat->Eval_Jacobi(i,i+1, dat->getNewU(),dat->getCurrentTime()))/Dii;
        }
    }
    
    //Reverse Sweep
    for (int i=(dat->getNumFunc()-1); i>=0; i--)
    {
        if (i==(dat->getNumFunc()-1))
        {
            dp[i] = d[i];
            ap[i] = a[i];
        }
        else if (i==0)
        {
            dp[i] = (d[i] - (c[i]*dp[(i+1)])) / (1 - (c[i]*ap[(i+1)]));
            ap[i] = 0;
        }
        else
        {
            dp[i] = (d[i] - (c[i]*dp[(i+1)])) / (1 - (c[i]*ap[(i+1)]));
            ap[i] = a[i] / (1 - (c[i]*ap[(i+1)]));
        }
    }
    
    //Final Forward Sweep
    for (int i=0; i<dat->getNumFunc(); i++)
    {
        if (i==0)
            p.edit(i, 0, dp[i]);
        else
            p.edit(i, 0, dp[i] - (ap[i] * p(i-1,0)));
    }
    
    return success;
}

//Upper Gauss Seidel Preconditioner (solve Up=v)
int precond_UpperGS_BDF2(const Matrix<double> &v, Matrix<double> &p, const void *data)
{
    int success = 0;
    Dove *dat = (Dove *) data;
    
    double rn = 0.0;
    if (dat->getOldTime() > 0.0)
        rn = dat->getTimeStep()/dat->getTimeStepOld();
    
    double an;
    an = (1.0 + (2.0*rn)) / (1.0 + rn);
    
    double sum_upper = 0.0, sum_lower = 0.0;
    std::map<int, double (*) (int i, int j, const Matrix<double> &u, double t, const void *data, const Dove &dove)>::reverse_iterator rit;
    std::map<int, double (*) (int i, int j, const Matrix<double> &u, double t, const void *data, const Dove &dove)>::iterator it;
    
    //Loop over rows
    for (int i=dat->getNumFunc()-1; i>=0; i--)
    {
        sum_upper = 0.0;
        sum_lower = 0.0;
        
        //Forward iterator
        for (it = dat->getJacobiMap(i).begin(); it->first<i; it++)
        {
            sum_lower = sum_lower + (-dat->getTimeStep()*it->second(i, it->first, dat->getNewU(), dat->getCurrentTime(), dat->getUserData(),*dat)*p(it->first,0));
        }
        
        //Iterate through the Jacobian map for the ith row (reverse iterator)
        for (rit = dat->getJacobiMap(i).rbegin(); rit->first>i; rit++)
        {
            sum_upper = sum_upper + (-dat->getTimeStep()*rit->second(i, rit->first, dat->getNewU(), dat->getCurrentTime(),dat->getUserData(),*dat)*p(rit->first,0));
        }
        double value = an*dat->Eval_Coeff(i, dat->getNewU(), dat->getCurrentTime());
        if (rit->first == i)
            value += -(dat->getTimeStep()*rit->second(i,rit->first, dat->getNewU(),dat->getCurrentTime(), dat->getUserData(),*dat));
        p.edit(i, 0, (v(i,0)-sum_upper-sum_lower)/value);
    }
    
    return success;
}

//Lower Gauss Seidel Preconditioner (Lp=v)
int precond_LowerGS_BDF2(const Matrix<double> &v, Matrix<double> &p, const void *data)
{
    int success = 0;
    Dove *dat = (Dove *) data;
    double sum_lower = 0.0, sum_upper = 0.0;
    std::map<int, double (*) (int i, int j, const Matrix<double> &u, double t, const void *data, const Dove &dove)>::iterator it;
    std::map<int, double (*) (int i, int j, const Matrix<double> &u, double t, const void *data, const Dove &dove)>::reverse_iterator rit;
    
    double rn = 0.0;
    if (dat->getOldTime() > 0.0)
        rn = dat->getTimeStep()/dat->getTimeStepOld();
    
    double an;
    an = (1.0 + (2.0*rn)) / (1.0 + rn);
    
    //Loop over rows
    for (int i=0; i<dat->getNumFunc(); i++)
    {
        sum_lower = 0.0;
        sum_upper = 0.0;
        
        //Reverse iterator
        for (rit = dat->getJacobiMap(i).rbegin(); rit->first>i; rit++)
        {
            sum_upper = sum_upper + (-dat->getTimeStep()*rit->second(i, rit->first, dat->getNewU(), dat->getCurrentTime(), dat->getUserData(),*dat)*p(rit->first,0));
        }
        
        //Iterate through the Jacobian map for the ith row (forward iterator)
        for (it = dat->getJacobiMap(i).begin(); it->first<i; it++)
        {
            sum_lower = sum_lower + (-dat->getTimeStep()*it->second(i, it->first, dat->getNewU(), dat->getCurrentTime(), dat->getUserData(),*dat)*p(it->first, 0));
        }
        double value = an*dat->Eval_Coeff(i, dat->getNewU(), dat->getCurrentTime());
        if (it->first == i)
            value += -(dat->getTimeStep()*it->second(i,it->first, dat->getNewU(),dat->getCurrentTime(), dat->getUserData(),*dat));
        p.edit(i, 0, (v(i,0)-sum_lower-sum_upper)/value);
    }
    
    return success;
}

//Symmetric Gauss Seidel Preconditioner
int precond_SymmetricGS_BDF2(const Matrix<double> &v, Matrix<double> &p, const void *data)
{
    int success = 0;
    
    success = precond_UpperGS_BDF2(v, p, data);
    success = precond_LowerGS_BDF2(v, p, data);
    
    return success;
}

/// Default  function
double default_func(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    return 0.0;
}

/// Default time coefficient function
double default_coeff(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    return 1.0;
}

/// Default Jacobian element function
double default_jacobi(int i, int j, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    return 0.0;
}


// -------------------- Begin temporary testing --------------------------
double f0(int i, const Matrix<double> &x, double t, const void *res_data, const Dove &dove)
{
    return x(0,0) + 1;
}

double f1(int i, const Matrix<double> &x, double t, const void *res_data, const Dove &dove)
{
    return x(1,0) - x(0,0);
}

int test_matvec(const Matrix<double> &x, Matrix<double> &Mx, const void *data)
{
    Mx(0,0) = 5*x(0,0);
    return 0;
}

int test_res(const Matrix<double> &x, Matrix<double> &Mx, const void *data)
{
    Mx(0,0) = 5.0*x(0,0)*x(0,0) - 1.0;
    return 0;
}

double first_order_decay(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    return -u(i,0);
}

double nonlinear_first_order_decay(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    return u(0,0)*u(1,0);
}

typedef struct
{
    int N;
    double L;
    double dx;
    double D;
    double uo;
}Test03_data;

double Lap1D_BC0(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    return 0.0;
}

double Lap1D_Jac_BC0(int i, int j, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    return 0.0;
}

double Lap1D_BC1(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    Test03_data *dat = (Test03_data *) data;
    return (dat->D/dat->dx/dat->dx)*(u(i+1,0) - 2*u(i,0) + dat->uo);
}

double Lap1D_Jac_BC1(int i, int j, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    Test03_data *dat = (Test03_data *) data;
    if (i == j)
        return -2.0*(dat->D/dat->dx/dat->dx);
    else if (i+1==j)
        return (dat->D/dat->dx/dat->dx);
    else
        return 0.0;
}

double Lap1D_Interior(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    Test03_data *dat = (Test03_data *) data;
    return (dat->D/dat->dx/dat->dx)*(u(i+1,0) - 2*u(i,0) + u(i-1,0));
}

double Lap1D_Jac_Interior(int i, int j, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    Test03_data *dat = (Test03_data *) data;
    if (i == j)
        return -2.0*(dat->D/dat->dx/dat->dx);
    else if (i+1==j)
        return (dat->D/dat->dx/dat->dx);
    else if (i-1==j)
        return (dat->D/dat->dx/dat->dx);
    else
        return 0.0;
}

double Lap1D_BCN(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    Test03_data *dat = (Test03_data *) data;
    return (dat->D/dat->dx/dat->dx)*(u(i-1,0) - 2*u(i,0) + u(i-1,0));
}

double Lap1D_Jac_BCN(int i, int j, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    Test03_data *dat = (Test03_data *) data;
    if (i == j)
        return -2.0*(dat->D/dat->dx/dat->dx);
    else if (i-1==j)
        return 2.0*(dat->D/dat->dx/dat->dx);
    else
        return 0.0;
}

typedef struct
{
    int m;
    int N;
}Test05_data;

double Lap2D_Nonlinear(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    Test05_data *dat = (Test05_data *) data;
    
    int upper = i+dat->m;
    int lower = i-dat->m;
    
    if (upper >= dat->N)
        upper = dat->N-1;
    if (lower < 0)
        lower = 0;
    
    int ub = i+1;
    int lb = i-1;
    
    if (ub >= dat->N)
        ub = dat->N-1;
    if (lb < 0)
        lb = 0;
    
    return u(i,0)*u(upper,0) + u(i,0)*u(ub,0) - 4.0*u(i,0)*u(i,0) + u(i,0)*u(lb,0) + u(i,0)*u(lower,0);
}

double Lap2D_NonlinearJac(int i, int j, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    Test05_data *dat = (Test05_data *) data;
    
    int upper_i = i+dat->m;
    int lower_i = i-dat->m;
    
    if (upper_i >= dat->N)
        upper_i = dat->N-1;
    if (lower_i < 0)
        lower_i = 0;
    
    int ub_i = i+1;
    int lb_i = i-1;
    
    if (ub_i >= dat->N)
        ub_i = dat->N-1;
    if (lb_i < 0)
        lb_i = 0;
    
    int upper_j = j+dat->m;
    int lower_j = j-dat->m;
    
    if (upper_j >= dat->N)
        upper_j = dat->N-1;
    if (lower_j < 0)
        lower_j = 0;
    
    int ub_j = j+1;
    int lb_j = j-1;
    
    if (ub_j >= dat->N)
        ub_j = dat->N-1;
    if (lb_j < 0)
        lb_j = 0;
    
    double jac = 0.0;
    if (i == 0)
    {
        if (j == i)
        {
            jac = u(upper_i,0) + u(ub_i,0) - 4.0*u(i,0);
        }
        else if (j == upper_i)
        {
            jac = u(i,0);
        }
        else if (j == ub_i)
        {
            jac = u(i,0);
        }
        else
            jac = 0.0;
    }
    else if (i == 1)
    {
        if (j == 0)
        {
            jac = 2*u(i,0);
        }
        else if (j == i)
        {
            jac = u(upper_i,0) + u(ub_i,0) - 8.0*u(i,0) + u(lb_i,0) + u(lower_i,0);
        }
        else if (j == upper_i)
        {
            jac = u(i,0);
        }
        else if (j == ub_i)
        {
            jac = u(i,0);
        }
        else if (j == lb_i)
        {
            jac = u(i,0);
        }
        else
            jac = 0.0;
    }
    else if (i < dat->m)
    {
        if (j == i)
        {
            jac = u(upper_i,0) + u(ub_i,0) - 8.0*u(i,0) + u(lb_i,0) + u(lower_i,0);
        }
        else if (j == upper_i)
        {
            jac = u(i,0);
        }
        else if (j == ub_i)
        {
            jac = u(i,0);
        }
        else if (j == lb_i)
        {
            jac = u(i,0);
        }
        else if (j == 0)
        {
            jac = u(i,0);
        }
        else
            jac = 0.0;
    }
    else if (i >= dat->m && i < (dat->N-dat->m))
    {
        if (j == i)
        {
            jac = u(upper_i,0) + u(ub_i,0) - 8.0*u(i,0) + u(lb_i,0) + u(lower_i,0);
        }
        else if (j == upper_i)
        {
            jac = u(i,0);
        }
        else if (j == ub_i)
        {
            jac = u(i,0);
        }
        else if (j == lb_i)
        {
            jac = u(i,0);
        }
        else if (j == lower_i)
        {
            jac = u(i,0);
        }
        else
            jac = 0.0;
    }
    else if (i >= (dat->N-dat->m) && i < (dat->N-2))
    {
        if (j == i)
        {
            jac = u(upper_i,0) + u(ub_i,0) - 8.0*u(i,0) + u(lb_i,0) + u(lower_i,0);
        }
        else if (j == upper_i)
        {
            jac = u(i,0);
        }
        else if (j == ub_i)
        {
            jac = u(i,0);
        }
        else if (j == lb_i)
        {
            jac = u(i,0);
        }
        else if (j == lower_i)
        {
            jac = u(i,0);
        }
        else
            jac = 0.0;
        
    }
    else if (i == (dat->N-2))
    {
        if (j == (dat->N-1))
        {
            jac = 2*u(i,0);
        }
        else if (j == i)
        {
            jac = u(lower_i,0) + u(lb_i,0) - 8.0*u(i,0) + u(ub_i,0) + u(upper_i,0);
        }
        else if (j == lower_i)
        {
            jac = u(i,0);
        }
        else if (j == lb_i)
        {
            jac = u(i,0);
        }
        else if (j == ub_i)
        {
            jac = u(i,0);
        }
        else
            jac = 0.0;
    }
    else if (i == (dat->N-1))
    {
        if (j == i)
        {
            jac = u(lower_i,0) + u(lb_i,0) - 4.0*u(i,0);
        }
        else if (j == lower_i)
        {
            jac = u(i,0);
        }
        else if (j == lb_i)
        {
            jac = u(i,0);
        }
        else
            jac = 0.0;
    }
    else
    {
        jac = 0.0;
    }
    
    return jac;
}

typedef struct
{
    double kldf;
    double K;
    double co;
    double Q;
    double eps;
    double rho;
} Test06_data;

double ldf_kinetics(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    Test06_data *dat = (Test06_data *) data;
    double rate = dat->kldf*(dat->K*u(dove.getVariableIndex("c"),0) - u(dove.getVariableIndex("q"),0));
    //std::cout << i << " = " << rate << std::endl;
    return rate;
}

double mb_timecoef(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    Test06_data *dat = (Test06_data *) data;
    return dat->eps;
}

double mb_cstr(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    Test06_data *dat = (Test06_data *) data;
    double rate = dat->Q*dat->co - dat->Q*u(dove.getVariableIndex("c"),0) - dat->rho*dove.coupledTimeDerivative("q",u);
    //std::cout << i << " = " << dove.coupledTimeDerivative("q",u) << std::endl;
    return rate;
}

typedef struct
{
    double C_h2o_in = 5.30E-5; //mol/L
    double C_i2_in = 3.3E-7; //mol/L
    double T_in = 298; //K
    double C_h2o_0 = 0; //mol/L
    double C_i2_0 = 0; //mol/L
    double T_0 = 298; //K
    double Q = 1000.0; //L/hr
    double rg = 0.008314; //kJ/K/mol
    double cg = 1.01; //kJ/kg/K
    double cs = 1.2; //kJ/kg/K
    double rhog = 0.001293; //kg/L
    double T_b = 298; //K
    double rhob = 0.73; //kg/L
    double V = 20; //L
    double eps = 0.45; //-
    double k = 3.5; //hr^-1
    double A = 6.0*pow(V*1000.0,0.67)/1000.0; //m^2
    double h = 0.01; //kJ/hr/m^2/K
    double dH_h2o = -64.8; //kJ/mol
    double dS_h2o = -0.1; //kJ/mol/K
    double dH_i2 = -24; //kJ/mol
    double dS_i2 = -0.01; //kJ/mol/K
    double qmax_h2o = 12.5; //mol/kg
    double qmax_i2 = 0.5; //mol/kg
} Test07_data;

double meb_mass_timecoef(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    Test07_data *dat = (Test07_data *) data;
    return dat->eps*dat->V;
}

double meb_energy_timecoef(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    Test07_data *dat = (Test07_data *) data;
    return (dat->eps*dat->V*dat->cg*dat->rhog) + (dat->cs*dat->rhob*dat->V);
}

double h2o_ldf_kinetics(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    Test07_data *dat = (Test07_data *) data;
    
    double T = dove.getNewU("T",u);
    double C_h2o = dove.getNewU("C_h2o", u);
    double C_i2 = dove.getNewU("C_i2", u);
    double q_h2o = dove.getNewU("q_h2o", u);
    
    double K_h2o = exp((-dat->dH_h2o/dat->rg/T) + (dat->dS_h2o/dat->rg));
    double K_i2 = exp((-dat->dH_i2/dat->rg/T) + (dat->dS_i2/dat->rg));
    
    double qe_h2o = (dat->qmax_h2o*K_h2o*C_h2o)/(1.0 + K_h2o*C_h2o + K_i2*C_i2);
    
    double rate = dat->k*(qe_h2o - q_h2o);
    
    return rate;
}

double i2_ldf_kinetics(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    Test07_data *dat = (Test07_data *) data;
    
    double T = dove.getNewU("T",u);
    double C_h2o = dove.getNewU("C_h2o", u);
    double C_i2 = dove.getNewU("C_i2", u);
    double q_i2 = dove.getNewU("q_i2", u);
    
    double K_h2o = exp((-dat->dH_h2o/dat->rg/T) + (dat->dS_h2o/dat->rg));
    double K_i2 = exp((-dat->dH_i2/dat->rg/T) + (dat->dS_i2/dat->rg));
    
    double qe_i2 = (dat->qmax_h2o*K_i2*C_i2)/(1.0 + K_h2o*C_h2o + K_i2*C_i2);
    
    double rate = dat->k*(qe_i2 - q_i2);
    
    return rate;
}

double h2o_mb(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    Test07_data *dat = (Test07_data *) data;
    
    double C_h2o = dove.getNewU("C_h2o", u);
    double dq_dt = dove.coupledTimeDerivative("q_h2o",u);
    
    double rate = dat->Q*dat->C_h2o_in - dat->Q*C_h2o - dat->rhob*dat->V*dq_dt;
    
    return rate;
}

double i2_mb(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    Test07_data *dat = (Test07_data *) data;
    
    double C_i2 = dove.getNewU("C_i2", u);
    double dq_dt = dove.coupledTimeDerivative("q_i2",u);
    
    double rate = dat->Q*dat->C_i2_in - dat->Q*C_i2 - dat->rhob*dat->V*dq_dt;
    
    return rate;
}

double T_eb(int i, const Matrix<double> &u, double t, const void *data, const Dove &dove)
{
    Test07_data *dat = (Test07_data *) data;
    
    double T = dove.getNewU("T", u);
    double dq_h2o_dt = dove.coupledTimeDerivative("q_h2o",u);
    double dq_i2_dt = dove.coupledTimeDerivative("q_i2",u);
    
    double dq_dt_energy = -(dat->dH_h2o*dq_h2o_dt + dat->dH_i2*dq_i2_dt);
    
    double rate = dat->Q*dat->rhog*dat->cg*dat->T_in - dat->Q*dat->rhog*dat->cg*T + dat->rhob*dat->V*dq_dt_energy + dat->h*dat->A*(dat->T_b-T);
    
    return rate;
}

// -------------------- End temporary testing --------------------------

//Test function
int DOVE_TESTS()
{
    int success = 0;
    //double time;
    
    FILE *file;
    file = fopen("output/DOVE_Tests.txt", "w+");
    if (file == nullptr)
    {
        system("mkdir output");
        file = fopen("output/DOVE_Tests.txt", "w+");
    }
    
    //  ---------    Test 01: Various methods for First Order Decay (No Coupling) --------------
    
    /**
     Dove test01;
     test01.set_outputfile(file);
     
     fprintf(file,"Test01: Single variable 1st Order Decay\n---------------------------------\ndu/dt = -u\n");
     
     test01.set_numfunc(1);
     test01.regFunction(0, first_order_decay);
     test01.set_endtime(1.0);
     test01.set_timestepper(CONSTANT);
     test01.set_NonlinearOutput(false);
     test01.set_headeroutput(true);
     test01.set_output(true);
     
     test01.set_initialcondition(0, 1);
     test01.set_variableName(0, "conc");
     test01.set_timestep(0.05);
     test01.set_integrationtype(BE);
     test01.solve_all();
     
     test01.set_initialcondition(0, 1);
     test01.set_timestep(0.05);
     test01.set_integrationtype(FE);
     test01.solve_all();
     
     test01.set_initialcondition(0, 1);
     test01.set_timestep(0.05);
     test01.set_integrationtype(CN);
     test01.solve_all();
     
     test01.set_initialcondition(0, 1);
     test01.set_timestep(0.05);
     test01.set_integrationtype(BDF2);
     test01.solve_all();
     
     test01.set_initialcondition(0, 1);
     test01.set_timestep(0.05);
     test01.set_integrationtype(RK4);
     test01.solve_all();
     
     test01.set_initialcondition(0, 1);
     test01.set_timestep(0.05);
     test01.set_integrationtype(RKF);
     test01.solve_all();
     
     fprintf(file,"\n --------------- End of Test01 ---------------- \n\n");
     
     //  ------------------------------    END Test01   ----------------------------------
     
     //  ---------    Test 02: Various methods for Nonlinear Coupled ODEs--------------
     
     Dove test02;
     test02.set_outputfile(file);
     fprintf(file,"Test02: Two variable Nonlinear Decay\n---------------------------------\ndu1/dt = -u1\ndu2/dt = u1*u2\n");
     
     test02.set_numfunc(2);
     test02.regFunction(0, first_order_decay);
     test02.regFunction(1, nonlinear_first_order_decay);
     test02.set_endtime(4.0);
     test02.set_timestepper(ADAPTIVE);
     test02.set_timestepmax(0.2);
     test02.set_NonlinearOutput(true);
     test02.set_headeroutput(true);
     test02.set_output(true);
     
     test02.set_initialcondition(0, 1);
     test02.set_initialcondition(1, 1);
     test02.set_timestep(0.01);
     test02.set_integrationtype(BE);
     test02.solve_all();
     
     test02.set_initialcondition(0, 1);
     test02.set_initialcondition(1, 1);
     test02.set_timestep(0.1);
     test02.set_integrationtype(FE);
     test02.solve_all();
     
     test02.set_initialcondition(0, 1);
     test02.set_initialcondition(1, 1);
     test02.set_timestep(0.1);
     test02.set_integrationtype(CN);
     test02.solve_all();
     
     test02.set_initialcondition(0, 1);
     test02.set_initialcondition(1, 1);
     test02.set_timestep(0.1);
     test02.set_integrationtype(BDF2);
     test02.solve_all();
     
     test02.set_initialcondition(0, 1);
     test02.set_initialcondition(1, 1);
     test02.set_timestep(0.1);
     test02.set_integrationtype(RK4);
     test02.solve_all();
     
     test02.set_initialcondition(0, 1);
     test02.set_initialcondition(1, 1);
     test02.set_timestep(0.1);
     test02.set_integrationtype(RKF);
     test02.solve_all();
     
     fprintf(file,"\n --------------- End of Test02 ---------------- \n\n");
     
     //  ------------------------------    END Test02   ----------------------------------
     
     //  ---------    Test 03: Various methods for Linear Coupled ODEs as a PDE --------------
     
     Dove test03;
     test03.set_outputfile(file);
     fprintf(file,"Test03: Single Variable Linear PDE\n---------------------------------\ndu/dt = D*d^2u/dx^2\n");
     
     Test03_data data03;
     data03.N = 11;
     data03.L = 1.0;
     data03.uo = 1.0;
     data03.D = 2.0;
     data03.dx = data03.L/(data03.N-1);
     test03.set_userdata((void*)&data03);
     
     test03.set_numfunc(data03.N);
     test03.regFunction(0, Lap1D_BC0);
     test03.regFunction(1, Lap1D_BC1);
     for (int i=2; i<data03.N-1; i++)
     test03.regFunction(i, Lap1D_Interior);
     test03.regFunction(data03.N-1, Lap1D_BCN);
     test03.set_endtime(1.0);
     test03.set_timestepper(CONSTANT);
     test03.set_timestepmax(0.2);
     test03.set_NonlinearOutput(true);
     test03.set_headeroutput(true);
     test03.set_LinearOutput(false);
     test03.set_LinearMethod(QR);
     test03.set_output(true);
     
     test03.set_initialcondition(0, 1);
     for (int i=1; i<data03.N; i++)
     test03.set_initialcondition(i, 0);
     test03.set_timestep(0.05);
     test03.set_integrationtype(BE);
     test03.solve_all();
     
     //NOTE: CN is only L2 stable!!! Timestep control aids stability.
     test03.set_initialcondition(0, 1);
     for (int i=1; i<data03.N; i++)
     test03.set_initialcondition(i, 0);
     test03.set_timestep(0.01);
     test03.set_integrationtype(CN);
     test03.solve_all();
     
     //NOTE: BDF2 has very good stability, but can have some instability (especially when accelerating the time step)
     test03.set_initialcondition(0, 1);
     for (int i=1; i<data03.N; i++)
     test03.set_initialcondition(i, 0);
     test03.set_timestep(0.05);
     test03.set_integrationtype(BDF2);
     test03.solve_all();
     
     fprintf(file,"\n --------------- End of Test03 ---------------- \n\n");
     
     //  ------------------------------    END Test03   ----------------------------------
     
     //  ---------    Test 04: Preconditioning for Linear Coupled ODEs as a PDE --------------
     
     Dove test04;
     test04.set_outputfile(file);
     fprintf(file,"Test04: Single Variable Linear PDE with Preconditioning\n---------------------------------\ndu/dt = D*d^2u/dx^2\n");
     
     Test03_data data04;
     data04.N = 101;
     data04.L = 1.0;
     data04.uo = 1.0;
     data04.D = 2.0;
     data04.dx = data04.L/(data04.N-1);
     test04.set_userdata((void*)&data04);
     
     test04.set_numfunc(data04.N);
     test04.regFunction(0, Lap1D_BC0);
     test04.regFunction(1, Lap1D_BC1);
     for (int i=2; i<data04.N-1; i++)
     test04.regFunction(i, Lap1D_Interior);
     test04.regFunction(data04.N-1, Lap1D_BCN);
     test04.set_endtime(1.0);
     test04.set_timestepper(ADAPTIVE);
     test04.set_timestepmax(0.2);
     test04.set_NonlinearOutput(true);
     test04.set_headeroutput(true);
     test04.set_LinearOutput(false);
     test04.set_LineSearchMethod(BT);
     test04.set_LinearStatus(true);
     test04.set_MaxLinearIterations(1); //Need to do something about the restarts. They are adding to iteration count!
     test04.set_RestartLimit(100);
     test04.set_RecursionLevel(2);
     
     test04.registerJacobi(0, 0, Lap1D_Jac_BC0);
     test04.registerJacobi(1, 0, Lap1D_Jac_BC1);
     test04.registerJacobi(1, 1, Lap1D_Jac_BC1);
     test04.registerJacobi(1, 2, Lap1D_Jac_BC1);
     for (int i=2; i<data04.N-1; i++)
     for (int j=i-1; j<=i+1; j++)
     test04.registerJacobi(i, j, Lap1D_Jac_Interior);
     test04.registerJacobi(data04.N-1, data04.N-2, Lap1D_Jac_BCN);
     test04.registerJacobi(data04.N-1, data04.N-1, Lap1D_Jac_BCN);
     
     test04.set_LinearMethod(GMRESRP);
     test04.set_preconditioner(TRIDIAG);
     test04.set_Preconditioning(true);
     test04.set_output(true);
     
     test04.set_initialcondition(0, 1);
     for (int i=1; i<data04.N; i++)
     test04.set_initialcondition(i, 0);
     test04.set_timestep(0.05);
     test04.set_integrationtype(BE);
     test04.solve_all();
     
     fprintf(file,"\n --------------- End of Test04 ---------------- \n\n");
     
     //  ------------------------------    END Test04   ----------------------------------
     
     //  ---------    Test 05: Preconditioning for NonLinear Coupled ODEs --------------
     
     Dove test05;
     test05.set_outputfile(file);
     fprintf(file,"Test05: Single Variable Non-Linear 2D PDE with Preconditioning\n---------------------------------\ndu/dt = u*Lap(u)\n");
     
     Test05_data data05;
     data05.N = 2000;
     data05.m = 80;	//NOTE: for this test, m should be between 2 and N-2
     test05.set_userdata((void*)&data05);
     test05.set_output(true);
     test05.set_numfunc(data05.N);
     for (int i=0; i<data05.N; i++)
     test05.regFunction(i, Lap2D_Nonlinear);
     test05.set_endtime(1.0);
     test05.set_timestepper(CONSTANT);
     test05.set_timestepmax(0.2);
     test05.set_NonlinearOutput(true);
     test05.set_headeroutput(true);
     test05.set_LinearOutput(true);
     test05.set_LineSearchMethod(BT);
     test05.set_LinearStatus(false);
     test05.set_LinearRelTol(1e-6);
     test05.set_LinearAbsTol(1e-6);
     test05.set_MaxLinearIterations(100);  //May want to tie MaxLinearIterations with RestartLimit somehow
     test05.set_RestartLimit(100);
     test05.set_RecursionLevel(2);
     if (data05.N > 1000)
     {
     test05.set_fileoutput(false);
     fprintf(file,"Test results to large to print to file\n");
     }
     
     //Register only the jacobian elements in the bandwidth (this still contains many zeros)
     for (int i=0; i<data05.N; i++)
     for (int j=i-data05.m; j<=i+data05.m; j++)
     if (j >= 0 && j < data05.N)
     {
     //Register only the Non-zero jacobian elements in the bandwidth (should be fully sparse)
     if (j==i-data05.m || j==i+data05.m || j==i+1 || j==i-1 || j == i || j == 0 || j == data05.N-1)
					test05.registerJacobi(i, j, Lap2D_NonlinearJac);
     }
     
     test05.set_LinearMethod(GMRESRP);
     test05.set_preconditioner(SGS);
     test05.set_Preconditioning(true);
     
     for (int i=0; i<data05.N; i++)
     test05.set_initialcondition(i, (double)(i+1)/(double)data05.N*10.0);
     test05.set_timestep(0.05);
     test05.set_integrationtype(BDF2);
     time = clock();
     test05.solve_all();
     
     time = clock() - time;
     std::cout << "\nSimulation Runtime: " << (time / CLOCKS_PER_SEC) << " seconds\n";
     
     fprintf(file,"\n --------------- End of Test05 ---------------- \n\n");
     
     //  ------------------------------    END Test05   ----------------------------------
     
     //  ---------    Test 06: Coupled Time Derivatives --------------
     Dove test06;
     test06.set_outputfile(file);
     fprintf(file,"Test06: Multi-variable test for coupled Time Derivatives\n---------------------------------\n(eps)*dc/dt = Q*co - Q*c - (rho)*dq/dt\ndq/dt=k*(K*c-q)\n");
     
     Test06_data data06;
     data06.kldf = 10.0;
     data06.K = 5.0;
     data06.co = 1.0;
     data06.rho = 2.0;
     data06.Q = 1.0;
     data06.eps = 0.5;
     test06.set_userdata((void*)&data06);
     test06.set_output(true);
     test06.set_numfunc(2);
     test06.set_variableName(1, "c");
     test06.set_variableName(0, "q");
     
     test06.regFunction("c", mb_cstr);
     test06.regFunction("q", ldf_kinetics);
     test06.registerCoeff("c", mb_timecoef);
     
     test06.set_variableSteadyState("q");
     //test06.set_variableSteadyState("c");
     //test06.set_variableSteadyStateAll();
     
     test06.set_starttime(1.0);
     test06.set_endtime(10.0);
     test06.set_timestepper(RATEBASED);
     test06.set_timestepmax(0.5);
     test06.set_NonlinearOutput(true);
     test06.set_headeroutput(true);
     test06.set_LinearOutput(false);
     test06.set_LineSearchMethod(BT);
     test06.set_LinearStatus(false);
     test06.set_MaxNonLinearIterations(10);
     test06.set_tolerance(1e-6);
     
     test06.set_LinearMethod(QR);
     
     test06.set_initialcondition("c", 0);
     test06.set_initialcondition("q", 0);
     test06.set_timestep(0.05);
     test06.set_integrationtype(CN);
     test06.solve_all();
     
     fprintf(file,"\n --------------- End of Test06 ---------------- \n\n");
     //  ------------------------------    END Test06   ----------------------------------
     
     */
    
    //  ---------    Test 07: Coupled Mass and Energy Balances --------------
    Dove test07;
    test07.set_outputfile(file);
    fprintf(file,"Test07: 2nd Multi-variable test for coupled Time Derivatives\n---------------------------------\n");
    
    Test07_data data07;
    test07.set_userdata((void*)&data07);
    test07.set_output(true);
    test07.set_numfunc(5);
    test07.set_variableName(0, "C_h2o");
    test07.set_variableName(1, "C_i2");
    test07.set_variableName(2, "q_h2o");
    test07.set_variableName(3, "q_i2");
    test07.set_variableName(4, "T");
    
    test07.regFunction("q_h2o", h2o_ldf_kinetics);
    test07.regFunction("q_i2", i2_ldf_kinetics);
    test07.regFunction("C_h2o", h2o_mb);
    test07.regFunction("C_i2", i2_mb);
    test07.regFunction("T", T_eb);
    
    test07.registerCoeff("C_h2o", meb_mass_timecoef);
    test07.registerCoeff("C_i2", meb_mass_timecoef);
    test07.registerCoeff("T", meb_energy_timecoef);
    
    test07.set_starttime(0.0);
    test07.set_endtime(5000.0);
    test07.set_timestepper(RATEBASED);
    test07.set_timestepmax(5.0);
    test07.set_NonlinearOutput(false);
    test07.set_output(true);
    test07.set_headeroutput(true);
    test07.set_LinearOutput(false);
    test07.set_LineSearchMethod(BT);
    test07.set_LinearStatus(false);
    test07.set_MaxNonLinearIterations(10);
    test07.set_tolerance(1e-8);
    
    test07.set_LinearMethod(QR);
    
    test07.set_initialcondition("C_h2o", data07.C_h2o_0);
    test07.set_initialcondition("C_i2", data07.C_i2_0);
    test07.set_initialcondition("q_h2o", data07.C_h2o_0);
    test07.set_initialcondition("q_i2", data07.C_i2_0);
    test07.set_initialcondition("T", data07.T_0);
    test07.set_timestep(0.05);
    test07.set_t_out(8.0);
    test07.set_integrationtype(BDF2);
    test07.solve_all();
    
    //fprintf(file,"\n --------------- End of Test06 ---------------- \n\n");
    //  ------------------------------    END Test06   ----------------------------------
    
    return success;
}
