/*!
 *  \file dove.h
 *	\brief Dynamic ODE solver with Various Established methods
 *	\details This file creates objects and subroutines for solving systems of Ordinary Differential
 *			Equations using various established methods. The basic idea is that a user will create
 *			a function to calculate all the right-hand sides of a system of ODEs, then pass that
 *			function to the DOVE routine, which will seek a numerical solution to that system.
 *
 *			Methods for Integration
 *			-----------------------
 *			BE = Backwards-Euler
 *			FE = Forwards-Euler
 *			CN = Crank-Nicholson
 *			BDF2 = Backwards-Differentiation-Formula-2
 *			RK4 = Runge-Kutta-4
 *			RKF = Runge-Kutta-Fehlberg
 *
 *			References for Various Methods
 *			------------------------------
 *			BE and BDF2 => S. Eckert, H. Baaser, D. Gross, O. Scherf, "A BDF2 integration method with step
 *							size control for elasto-plasticity," Comp. Mech., 34, 377-386, 2004.
 *
 *			CN and FE => J.W. Thomas, Introduction to Numerical Methods for Partial Differential Equations, Springer,
 *							ISBN 0-387-97999-9
 *
 *			RK4 and RKF => B.S. Desale, N.R. Dasre, "Numerical Solution of the System of Six Coupled Nonlinear ODEs by
 *							Runge-Kutta Fourth Order Method," Applied Math. Sci., 7, 287 - 305, 2013.
 *
 *
 *  \author Austin Ladshaw
 *	\date 09/25/2017
 *	\copyright This software was designed and built at the Georgia Institute
 *             of Technology by Austin Ladshaw for Post-Doc research in the area
 *             of adsorption and surface science. Copyright (c) 2017, all
 *             rights reserved.
 */

#include "macaw.h"
#include "lark.h"
#include "yaml_wrapper.h"
//#include "gsta_opt.h"
#include <unordered_map>        //Line to allow use of unordered_map structure

#ifndef DOVE_HPP_
#define DOVE_HPP_

/// Enumeration for the list of valid time integration types
/** The only types that have been defined are for Implicit and Explicit methods.
	Sub-type enumeration is used to denote the specific methods.*/
typedef enum {IMPLICIT, EXPLICIT} integrate_type;

/// Enumeration for the list of valid time integration subtypes
/** Theses subtypes define the specific scheme to be used. The table below gives
	a brief description of each.
 
	\param BE Backwards-Euler: Standard implicit method.
	\param FE Forwards-Euler: Standard explicit method.
	\param CN Crank-Nicholson: Time averaged, 2nd order implicit scheme.
	\param BDF2 Backwards-Differentiation-Formula-2: 2nd order implicit method.
	\param RK4 Runge-Kutta-4: 4th order explicit method.
	\param RKF Runge-Kutta-Fehlberg: 4th order explicit method with 5th order error control. */
typedef enum {BE, FE, CN, BDF2, RK4, RKF} integrate_subtype;

/// Enumeration for the list of valid time stepper types
/** Type of time stepper to be used by Dove.
 
	\param CONSTANT time stepper will use a constant dt value for all time steps.
	\param ADAPTIVE time stepper will adjust the time step according to simulation success.
	\param FEHLBERG time stepper will adjust time step according to desired error tolerance.
	\param RATEBASED time stepper will adjust time step based on maximum rates of change. */
typedef enum {CONSTANT, ADAPTIVE, FEHLBERG, RATEBASED} timestep_type;

/// Enumeration for the list of valid line search methods
/** Type of line search method to be used by Dove.
 
	\param BT uses a basic backtracking linesearch algorithm.
	\param ABT uses an adaptive backtracking linesearch method.
	\param NO_LS no line searching will be used. */
typedef enum {BT, ABT, NO_LS} linesearch_type;

/// Enumeration for the list of valid preconditioning options
/** Type of preconditioner to apply to linear iterations.
 
	\param JACOBI uses a simple Jacobi iteration as preconditioning.
	\param TRIDIAG uses a Tridiagonal solve as preconditioning.
	\param UGS uses an Upper-Gauss-Seidel iteration as preconditioning.
	\param LGS uses a Lower-Gauss-Seidel iteration as preconditioning.
	\param SGS uses a Symmetric-Gauss-Seidel iteration as preconditioning.*/
typedef enum {JACOBI, TRIDIAG, UGS, LGS, SGS} precond_type;

///Function to validate solver choice
//** Returns true for Linear and false for Nonlinear */
bool solver_choice(std::string &choice);

///Function to validate linesearch choice
linesearch_type linesearch_choice(std::string &choice);

///Function to validate linear solver choice
krylov_method linearsolver_choice(std::string &choice);

///Function to determine whether or not to precondition
bool use_preconditioning(std::string &choice);

///Function to validate preconditioning choice
precond_type preconditioner_choice(std::string &choice);

///Function to validate timestepper choice
timestep_type timestepper_choice(std::string &choice);

///Function to validate integration method choice
integrate_subtype integration_choice(std::string &choice);


/// Dynamic ODE-solver with Various Established methods (DOVE) object
/** This class structure creates a C++ object that can be used to solve coupled systems of
	Ordinary Differential Equations. A user will interface with this object by creating functions
	that evaluate the right-hand side of an ODE based on the given variable set. Those functions
	will collectively create the system to solve numerically using either explicit or implicit
	methods. The choice of methods can be set by the user, or the object will default to the
	Backwards-Euler implicit method for stability.
 
	User functions for the right-hand side are written as...
 
	du_i/dt = user_function_i(const eMatrix<double> &u, const void *data_struct)
 
	In some cases, there is a need to include a time coefficient on the left-hand side of the rate
	expression. For those cases, the user may also provide a time coefficient function...
 
	user_time_coeff_i(const eMatrix<double> &u, const void *data_struct) * du_i/dt = user_function_i(...)
 
	For most implicit problems, the ODE system must be solved iteratively using a Newton-style method. In
	these cases, the user may also provide functions for Jacobian matrix elements...
	
	user_jacobi_element_i_j(const eMatrix<double> &u, const void *data_struct)
 
	All of these above functions are to be put into Matrices inside of the Dove class object so that Dove
	will call those functions when it needs to be called. Data structures for all function calls are optional
	and are to be defined by the user to contain whatever parameter information is needed for their particular
	problem. */
class Dove
{
public:
	Dove();												///< Default constructor
	~Dove();											///< Default destructor
	
	//Set some Dove conditions
	void set_numfunc(int i);							///< Set the number of functions to solve and reserve necessary space
	void set_timestep(double d);						///< Set the value of the time step
	void set_timestepmin_converged(double d);			///< Set the value of the minimum time step after simulation converged
	void set_timestepmin(double dmin);					///< Set the value of the minimum time step
	void set_timestepmax(double dmax);					///< Set the value of the maximum time step
	void set_endtime(double e);							///< Set the value of the end time
	void set_starttime(double s);						///< Set the value of the starting time
	void set_integrationtype(integrate_subtype type);	///< Set the type of integration scheme to use
	void set_timestepper(timestep_type type);			///< Set the time stepper scheme type
	void set_preconditioner(precond_type type);			///< Set the type of preconditioner to use
	void set_outputfile(FILE *file);					///< Set the output file for simulation results
	void set_userdata(const void *data);				///< Set the user defined data structure
	void set_initialcondition(int i, double ic);		///< Set the initial condition of variable i to value ic
	void set_initialcondition(std::string name, double ic); ///< Set the initial condition of variable name to value ic
	void set_variableName(int i, std::string name);		///< Set the name of variable i to the given string (both i and name should be unique)
	void set_variableSteadyState(int i);				///< Set the ith variable to be steady-state (i.e., var_steady[i] = true)
	void set_variableSteadyState(std::string name);		///< Set the named varibale to steady-state (i.e., var_steady[i] = true)
	void set_variableSteadyStateAll();					///< Set all variables to be steady-state
	void set_output(bool choice);						///< Set the value of DoveOutput (True if you want console messages)
	void set_fileoutput(bool choice);					///< Set the value of DoveFileOuput (True if you want results printed to file)
	void set_headeroutput(bool choice);					///< Set the value of DoveHeader (True if you want header printed to file)
	void set_tolerance(double tol);						///< Set the value of residual/error tolerance desired
	void set_t_out(double v);							///< Set the value of the t_out parameter
	
	//Set some default conditions
	void set_defaultNames();							///< Set all the variable names to default values (does not set var_names_hash values)
	void set_defaultCoeffs();							///< Set all coeff functions to the default
	void set_defaultJacobis();							///< Set all Jacobians to the default (only does the diagonals!)
	void set_defaultStates();							///< Set all var_steady values to false for each variable (unsteady variables are default)
	
	// Set conditions for PJFNK
	void set_NonlinearAbsTol(double tol);				///< Set the value of nonlinear absolute tolerance
	void set_NonlinearRelTol(double tol);				///< Set the value of nonlinear relative tolerance
	void set_LinearAbsTol(double tol);					///< Set the value of linear absolute tolerance
	void set_LinearRelTol(double tol);					///< Set the value of linear relative tolerance
	void set_NonlinearOutput(bool choice);				///< Sets the non-linear output information according to user choice
	void set_LinearOutput(bool choice);					///< Sets the linear output information according to user choice
	void set_Preconditioning(bool choice);				///< Sets the boolean to determine whether or not to include preconditioning
	void set_LinearMethod(krylov_method choice);		///< Sets the linear solver method to user choice
	void set_LineSearchMethod(linesearch_type choice);	///< Sets the line search method to the user choice
	void set_MaxNonLinearIterations(int it);			///< Set the maximum number of non-linear iterations
	void set_MaxLinearIterations(int it);				///< Set the maximum number of linear iterations (or number of restarts)
	void set_RestartLimit(int it);						///< Sets the number of iterations before restarting
	void set_RecursionLevel(int level);					///< Sets the maximum level of recursion for the KMS method
	void set_LinearStatus(bool choice);					///< Sets the boolean to determine whether or not to treat as linear (true = Linear)
	
	/// Register the ith user function
	/** This function will register the ith user function into the object. That function must accept as arguments the function
		identifier i, a constant eMatrix for variables u, a double for time t, and a void data pointer. All of this information
		is required to be in the function parameters, but is not required to be used by the function. The indentifier i can be
		used to conveniently define coupling between nieghboring elements/variables in the system. In other words, the int i
		denotes not only the function being registered, but also the primary coupled variable for the function.
	 
		i.e., du_i/dt = Func(u_i all other u)
	 
		This will allow for this framework to also handle PDEs, whose coupling between ith and jth variables is usually done
		via nieghboring variables (i.e., u_i in a 1-D PDE couples with u_i-1 and u_i+1). A similar relational scheme is workable
		with multiple dimensions. Additional information about the coupling between the ith variable and other variables can be
		passed to the function via the void data pointer.
	 
		\note You are allowed to point to the same user function for all i, but you must make sure that the resulting system is
		non-singular (i.e., use argument i passed to the function to denote interally which function you are at). */
	void regFunction(int i, double (*func) (int i, const eMatrix<double> &u, double t, const void *data, const Dove &dove) );
	
	/// Register the named user function
	/** This function will register the named user function into the object. That function must accept as arguments the function
		identifier i, a constant eMatrix for variables u, a double for time t, and a void data pointer. All of this information
		is required to be in the function parameters, but is not required to be used by the function. The indentifier i can be
		used to conveniently define coupling between nieghboring elements/variables in the system. In other words, the int i
		denotes not only the function being registered, but also the primary coupled variable for the function.
	 
		i.e., du_i/dt = Func(u_i all other u)
	 
		This will allow for this framework to also handle PDEs, whose coupling between ith and jth variables is usually done
		via nieghboring variables (i.e., u_i in a 1-D PDE couples with u_i-1 and u_i+1). A similar relational scheme is workable
		with multiple dimensions. Additional information about the coupling between the ith variable and other variables can be
		passed to the function via the void data pointer.
	 
		\note You are allowed to point to the same user function for all i, but you must make sure that the resulting system is
		non-singular (i.e., use argument i passed to the function to denote interally which function you are at). */
	void regFunction(std::string name, double (*func) (int i, const eMatrix<double> &u, double t, const void *data, const Dove &dove) );
	
	/// Register the ith time coeff function
	/** This function will register the ith coeff function into the object. That function must accept as arguments the coefficient
		identifier i, a constant eMatrix for variables u, a double for time t, and a void data pointer. All of this information
		is required to be in the function parameters, but is not required to be used by the function. The indentifier i can be
		used to conveniently define identify where the coefficient may be applied spatially. In other words, if solving a PDE,
		the time coefficient may be a function of location in space, which can be potentially identified by int i.
	 
		For example, in 1-D space, the distance x can be computed as x = dx*i for a regular grid. */
	void registerCoeff(int i, double (*coeff) (int i, const eMatrix<double> &u, double t, const void *data, const Dove &dove) );
	
	/// Register the named time coeff function
	/** This function will register the named coeff function into the object. That function must accept as arguments the coefficient
		identifier i, a constant eMatrix for variables u, a double for time t, and a void data pointer. All of this information
		is required to be in the function parameters, but is not required to be used by the function. The indentifier i can be
		used to conveniently define identify where the coefficient may be applied spatially. In other words, if solving a PDE,
		the time coefficient may be a function of location in space, which can be potentially identified by int i.
	 
		For example, in 1-D space, the distance x can be computed as x = dx*i for a regular grid. */
	void registerCoeff(std::string name, double (*coeff) (int i, const eMatrix<double> &u, double t, const void *data, const Dove &dove) );
	
	/// Register the i-jth element of jacobian
	/** This function will register the (i,j) jacobian function into the object. That function must accept as arguments the jacobi
		identifiers (i and j), a constant eMatrix for variables u, a double for time t, and a void data pointer. All of this information
		is required to be in the function parameters, but is not required to be used by the function. The indentifiers i and j can be
		used to determine which Jacobian function this should be, thus allowing a user to potentially reference the same function for
		all Jacobi elements, but return different results based on matrix location.
	 
		Jacobian elements are as follows:  J_ij = d(func_i)/d(u_j)   derivative of ith function with respect to jth variable.
	 
		\note The jacobian information is used only in preconditioning actions taken by DOVE. The type of preconditioning can
		be choosen by the user. There are standard types of preconditioning available. */
	void registerJacobi(int i, int j, double (*jac) (int i, int j, const eMatrix<double> &u, double t, const void *data, const Dove &dove) );
	
	/// Register the named element of jacobian
	/** This function will register the named jacobian function into the object. That function must accept as arguments the jacobi
		identifiers (i and j), a constant eMatrix for variables u, a double for time t, and a void data pointer. All of this information
		is required to be in the function parameters, but is not required to be used by the function. The indentifiers i and j can be
		used to determine which Jacobian function this should be, thus allowing a user to potentially reference the same function for
		all Jacobi elements, but return different results based on matrix location.
	 
		Jacobian elements are as follows:  J_ij = d(func_i)/d(u_j)   derivative of ith function with respect to jth variable.
	 
		\note The jacobian information is used only in preconditioning actions taken by DOVE. The type of preconditioning can
		be choosen by the user. There are standard types of preconditioning available. */
	void registerJacobi(std::string func_name, std::string var_name, double (*jac) (int i, int j, const eMatrix<double> &u, double t, const void *data, const Dove &dove) );
	
	void print_header(bool addNewLine);					///< Function to print out a header to output file
	void print_newresult(bool addNewLine);				///< Function to print out the new result of n+1 time level
	void print_result(bool addNewLine);					///< Function to print out the old result of n time level
	
	void createJacobian();                          ///< Function to create and store a numerical jacobian
	eMatrix<double>& getNumJacobian();               ///< Return reference to the numerical jacobian
	eMatrix<double>& getCurrentU();					///< Return reference to the n level solution
	eMatrix<double>& getOldU();						///< Return reference to the n-1 level solution
	eMatrix<double>& getNewU();						///< Return reference to the n+1 level solution
	int getVariableIndex(std::string name) const;	///< Return the index of the variable whose name matches the given string (checks hash table)
	std::string getVariableName(int i);				///< Return the name of the variable based on the given index
	double getMaxRate();							///< Returns the value of the maximum rate of change for all variables
	double getCurrentU(int i, const eMatrix<double> &u) const;	///< Return the value of the n level solution for variable i
	double getOldU(int i, const eMatrix<double> &u) const;		///< Return the value of the n-1 level solution for variable i
	double getNewU(int i, const eMatrix<double> &u) const;		///< Return the value of the n+1 level solution for variable i
	double getCurrentU(std::string name, const eMatrix<double> &u) const;///< Return the value of the n level solution for variable of given name
	double getOldU(std::string name, const eMatrix<double> &u) const;	///< Return the value of the n-1 level solution for variable of given name
	double getNewU(std::string name, const eMatrix<double> &u) const;	///< Return the value of the n+1 level solution for variable of given name
	double coupledTimeDerivative(int i, const eMatrix<double> &u) const;	///< Return the value of the ith variable's time derivative
	double coupledTimeDerivative(std::string name, const eMatrix<double> &u) const;		///< Return the value of the named variable's time derivative
	
	/// Return the value of the ith variable's time derivative's jth derivative
	double coupledDerivativeTimeDerivative(int i, int j, const eMatrix<double> &u) const;
	
	const void *getUserData();						///< Return pointer to user data
	int getNumFunc() const;							///< Return the number of functions
	double getTimeStep() const;						///< Return the current time step
	double getTimeStepOld() const;					///< Return the old time step
	double getEndTime() const;						///< Return value of end time
	double getCurrentTime() const;					///< Return the value of current time
	double getOldTime() const;						///< Return the value of the previous time
	double getOlderTime() const;					///< Return the value of the older previous time
	double getStartTime() const;					///< Return the value of the start time
	double getMinTimeStep();						///< Return the value of the minimum time step
	double getMaxTimeStep();						///< Return the value of the maximum time step
	double getOutputTime();							///< Return the time that output is printed on
	FILE *getFile();								///< Return the pointer to the output file
	bool hasConverged();							///< Returns state of convergence
	double getNonlinearResidual();					///< Returns the current value of the non-linear residual
	double getNonlinearRelativeRes();				///< Returns the current value of the non-linear relative residual
	bool allSteadyState() const;					///< Returns a boolean to determine whether or not all variables are steady (true = all steady)
	bool isSteadyState(int i) const;				///< Returns true if the ith variable is steady-state
	integrate_type getIntegrationType();			///< Returns the type of integration method in use
	integrate_subtype getIntegrationMethod();		///< Returns the method of time integration
	timestep_type getTimeStepper();					///< Returns the time stepper method
	precond_type getPreconditioner();				///< Returns the preconditioner type
	linesearch_type getLinesearchMethod();			///< Returns the method of line search
	krylov_method getLinearMethod();				///< Returns the linear method used
	bool isPreconditioned();						///< Returns true if using preconditioning
	double getLinearToleranceABS();					///< Returns the value of linear tolerance (absolute)
	double getLinearToleranceREL();					///< Returns the value of linear tolerance (relative)
	double getNonlinearToleranceABS();				///< Returns the value of nonlinear tolerance (absolute)
	double getNonlinearToleranceREL();				///< Returns the value of nonlinear tolerance (relative)
	int getMaxNonlinearIterations();				///< Returns the maximum allowable nonlinear iterations
	int getMaxLinearIterations();					///< Returns the maximum allowable linear iterations
	bool isLinear();								///< Returns true if the system is being treated as linear
	int getRestartLevel();							///< Returns the number of iterations allowed before restart for Krylov methods
	int getRecursionLevel();						///< Returns the number of recursion levels allow for Krylov preconditioning
	bool isValidName(std::string name);				///< Returns true if the given name is a variable in the DOVE system
	
	/// Function to return a reference to the Jacobian eMatrix map at the ith row of the matrix
	std::map<int, double (*) (int i, int j, const eMatrix<double> &u, double t, const void *data, const Dove &dove)> & getJacobiMap(int i);
	
	double ComputeTimeStep();											///< Returns a computed value for the next time step
	double Eval_Func(int i, const eMatrix<double>& u, double t);			///< Evaluate user function i at given u matrix and time t
	double Eval_Coeff(int i, const eMatrix<double>& u, double t);		///< Evaluate user time coefficient function i at given u matrix and time t
	double Eval_Jacobi(int i, int j, const eMatrix<double>& u, double t);///< Evaluate user jacobian function for (i,j) at given u matrix and time t
	
	int solve_timestep();							///< Function to solve a single time step
	void validate_precond();						///< Function to validate and set preconditioning pointer
	void validate_linearsteps();					///< Function to check and validate the number of linear iterations
	void validate_method();							///< Function to check and validate the time integration method
	void update_states();							///< Function to update the stateful information
	void update_timestep();							///< Function to update the timestep for the simulation
	void reset_all();								///< Reset all the states
	
	/// Function to solve the system of equations and print results to file (returns 0 on success)
	/** This function will iteratively go through and solve the system for all time steps until either failure occurs or
		the final time has been reached. Output will be placed into the user's output file or a default output file. This
		function will assume that the initial conditions have already been set for each variable by the user. */
	int solve_all();
	
	/// Solver function for explicit-FE method
	/** This function will solve the Dove system of equations using the standard Forward-Euler method. In this
	 function, DOVE will call the user defined rate functions and use that information at the previous time
	 level to solve for the next time level directly.
	 
	 unp1[i] = (Rn[i]*un[i] + dt*func[i](unp1)) / Rnp1[i]   */
	int solve_FE();
	
	/// Solver function for explicit-RK4 method
	/** This function will solve the Dove system of equations using the Runge-Kutta 4th order method. In this
		function, DOVE will call user defined rate functions as necessary and use that information at the previous
		time level to provide an estimate to the solution at the next time level. */
	int solve_RK4();
	
	/// Solver function for explicit-RKF method
	/** This function will solve the Dove system of equations using the Runge-Kutta-Fehlberg method. In this
		function, DOVE will call user defined rate runctions as necessary and use that information at the previous
		time level to provide an estimate to the solution at the next time level. */
	int solve_RKF();
	
protected:
	eMatrix<std::string> var_names;					///< eMatrix of variable names (access names by index in numerical order)
	std::unordered_map<std::string, int> var_names_hash;	///< Hash table of variable names and corresponding indices (access index by name)
	eMatrix<int> var_steady;							///< eMatrix of boolean args used to dictate which variables are considered steady-state (if any)
	eMatrix<double> un;								///< eMatrix for nth level solution vector
	eMatrix<double> unp1;							///< eMatrix for n+1 level solution vector
	eMatrix<double> unm1;							///< eMatrix for n-1 level solution vector
	double dt;										///< Time step between n and n+1 time levels
	double dt_old;									///< Time step between n and n-1 time levels
	double time_end;								///< Time on which to end the ODE simulations
	double time_start;								///< Time on which to start the ODE simulations
	double time;									///< Value of current time
	double time_old;								///< Value of previous time
	double time_older;								///< Value of older previous time
	double dtmin;									///< Minimum allowable time step
	double dtmin_con;								///< Minimum allowable time step if solution has converged
	double dtmax;									///< Maximum allowable time step
	double tolerance;								///< Residual tolerance desired (or level of accuracy desired)
	double t_count;									///< Counter designed to keep track of how often we print results
	double t_out;									///< Direct Dove to only print results after specific time increments
	integrate_type int_type;						///< Type of time integration to use
	integrate_subtype int_sub;						///< Subtype of time integration scheme to use
	timestep_type timestepper;						///< Type of time stepper to be used
	precond_type preconditioner;					///< Type of preconditioner to use
	linesearch_type line_type;						///< Type of linesearch method to use
	FILE *Output;									///< File to where simulation results will be place
	int num_func;									///< Number of functions in the system of ODEs
	bool Converged;									///< Boolean to hold information on whether or not last step converged
	bool DoveOutput;								///< Boolean to determine whether or not to print Dove messages to console
	bool DoveFileOutput;							///< Boolean to determine whether or not to print Dove ouput to the file
	bool DoveHeader;								///< Boolean to determine whether or not to print the Dove header to file
	bool Preconditioner;							///< Boolean to determine whether or not to use a preconditioner
	bool Linear;									///< Boolean to determine whether or not to treat problem as linear
	bool AllSteadyState;							///< Boolean to determine whether or not all variables are steady (true = all steady-state)
	int linmax;										///< Users requested maximum number of linear steps
	int timesteps;									///< Running count of number of time steps taken
	
	/// eMatrix object for user defined rate functions
	eMatrix<double (*) (int i, const eMatrix<double> &u, double t, const void *data, const Dove &dove)> user_func;
	/// eMatrix object for user defined time coefficients (optional)
	eMatrix<double (*) (int i, const eMatrix<double> &u, double t, const void *data, const Dove &dove)> user_coeff;
	/// A vector of Maps for user defined Jacobian elements (optional)
	/** This structure creates a Sparse eMatrix of functions whose sparcity pattern is unknown at creation.
		Each "vector" index denotes a row in the full matrix. In each row, there is a map of the non-zero
		elements. Doing the mapping in this way allows for the sparcity of the matrix to easily change
		while also allowing for relatively fast access to the non-zero elements.
	 */
	std::vector< std::map<int, double (*) (int i, int j, const eMatrix<double> &u, double t, const void *data, const Dove &dove)> > user_jacobi;
	const void *user_data;														///< Pointer for user defined data structure
	
	PJFNK_DATA newton_dat;							///< Data structure for the PJFNK iterative method
	/// Function pointer for the residual function of DOVE
	int (*residual) (const eMatrix<double> &x, eMatrix<double> &F, const void *res_data);
	/// Function pointer for the preconditioning operation of DOVE
	int (*precon) (const eMatrix<double> &r, eMatrix<double> &p, const void *precon_data);
	
	NUM_JAC_DATA jac_dat;                           ///< Data structure for making Numerical Jacobian Matrices
	eMatrix<double> Jacobian;                        ///< eMatrix to hold numerical jacobian
	
private:
	
};

/// Residual function for implicit-BE method
/** This function will be passed to PJFNK as the residual function for the Dove object. In this function,
	DOVE will call the user defined rate functions to create a vector of residuals at the current iterate. That
	information will be passed into the pjfnk function (see lark.h) to iteratively solve the system of equations
	at a single time step.
 
	Res[i] = Rnp1[i]*unp1[i] - Rn[i]*un[i] - dt*func[i](unp1)   */
int residual_BE(const eMatrix<double> &u, eMatrix<double> &Res, const void *data);

/// Preconditioning function for a Jacobi preconditioner on the implicit-BE method
/** This function will be passed to PJFNK as the preconditioning operation for the Dove object. In this function,
	DOVE will call user defined coefficient and Jacobi functions to apply a preconditioning operation on the linear
	system. Note that each implicit method in DOVE must have its own preconditioner because the residuals are different.
	Also, each type of preconditioning will have its own function.
 
	Jacobi preconditioning:  Solve  Dp=v for p using input vector v and the diagonals (D) of the full jacobian.
 
	Diagonals for BE are of the form: dR_i/du_i = Rnp1[i] - dt*jacobi[i][i](unp1)  */
int precond_Jac_BE(const eMatrix<double> &v, eMatrix<double> &p, const void *data);

/// Preconditioning function for a Tridiagonal preconditioner on the implicit-BE method
/** This function will be passed to PJFNK as the preconditioning operation for the Dove object. In this function,
	DOVE will call user defined coefficient and Jacobi functions to apply a preconditioning operation on the linear
	system. Note that each implicit method in DOVE must have its own preconditioner because the residuals are different.
	Also, each type of preconditioning will have its own function.
 
	Tridiagonal preconditioning:  Solve  (TD)p=v for p using input vector v and a Tridiagonal (TD) of the full jacobian.
 
	Diagonals for BE are of the form: dR_i/du_i = Rnp1[i] - dt*jacobi[i][i](unp1)
	Off-Diagonals for BE are of form: dR_i/du_j = Rnp1[i] - dt*jacobi[i][j](unp1) for i==j
 and	  dR_i/du_j = -dt*jacobi[i][j](unp1)          for i!=j*/
int precond_Tridiag_BE(const eMatrix<double> &v, eMatrix<double> &p, const void *data);

/// Preconditioning function for an Upper-Gauss-Seidel preconditioner on the implicit-BE method
/** This function will be passed to PJFNK as the preconditioning operation for the Dove object. In this function,
	DOVE will call user defined coefficient and Jacobi functions to apply a preconditioning operation on the linear
	system. Note that each implicit method in DOVE must have its own preconditioner because the residuals are different.
	Also, each type of preconditioning will have its own function.
 
	UGS preconditioning:  Solve  (U*)p=v+Lp for p using input vector v with an Upper Triangular (U*) of the full jacobian
 and a strict lower triangular (L) of the full jacobian.
 
	Diagonals for BE are of the form: dR_i/du_i = Rnp1[i] - dt*jacobi[i][i](unp1)
	Off-Diagonals for BE are of form: dR_i/du_j = Rnp1[i] - dt*jacobi[i][j](unp1) for i==j
 and	  dR_i/du_j = -dt*jacobi[i][j](unp1)          for i!=j*/
int precond_UpperGS_BE(const eMatrix<double> &v, eMatrix<double> &p, const void *data);

/// Preconditioning function for a Lower-Gauss-Seidel preconditioner on the implicit-BE method
/** This function will be passed to PJFNK as the preconditioning operation for the Dove object. In this function,
	DOVE will call user defined coefficient and Jacobi functions to apply a preconditioning operation on the linear
	system. Note that each implicit method in DOVE must have its own preconditioner because the residuals are different.
	Also, each type of preconditioning will have its own function.
 
	LGS preconditioning:  Solve  (L*)p=v+Up for p using input vector v and a Lower Triangular (L*) of the full jacobian.
 and a strict upper triangular (U) of the full jacobian.
 
	Diagonals for BE are of the form: dR_i/du_i = Rnp1[i] - dt*jacobi[i][i](unp1)
	Off-Diagonals for BE are of form: dR_i/du_j = Rnp1[i] - dt*jacobi[i][j](unp1) for i==j
 and	  dR_i/du_j = -dt*jacobi[i][j](unp1)          for i!=j*/
int precond_LowerGS_BE(const eMatrix<double> &v, eMatrix<double> &p, const void *data);

/// Preconditioning function for a Symmetric-Gauss-Seidel preconditioner on the implicit-BE method
/** This function will be passed to PJFNK as the preconditioning operation for the Dove object. In this function,
	DOVE will call user defined coefficient and Jacobi functions to apply a preconditioning operation on the linear
	system. Note that each implicit method in DOVE must have its own preconditioner because the residuals are different.
	Also, each type of preconditioning will have its own function.
 
	SGS preconditioning:  Solve  (J)p=v for p using input vector v with the Jacobian matrix (J) approximately by first
 solving as an Upper-Gauss-Seidel, then as a Lower-Gauss-Seidel.
 
	Diagonals for BE are of the form: dR_i/du_i = Rnp1[i] - dt*jacobi[i][i](unp1)
	Off-Diagonals for BE are of form: dR_i/du_j = Rnp1[i] - dt*jacobi[i][j](unp1) for i==j
 and	  dR_i/du_j = -dt*jacobi[i][j](unp1)          for i!=j*/
int precond_SymmetricGS_BE(const eMatrix<double> &v, eMatrix<double> &p, const void *data);

/// Residual function for implicit-CN method
/** This function will be passed to PJFNK as the residual function for the Dove object. In this function,
	DOVE will call the user defined rate functions to create a vector of residuals at the current iterate. That
	information will be passed into the pjfnk function (see lark.h) to iteratively solve the system of equations
	at a single time step.
 
	Res[i] = Rnp1[i]*unp1[i] - Rn[i]*un[i] - 0.5*dt*func[i](unp1) - 0.5*dt*func[i](un)   */
int residual_CN(const eMatrix<double> &u, eMatrix<double> &Res, const void *data);

/// Preconditioning function for a Jacobi preconditioner on the implicit-CN method
/** This function will be passed to PJFNK as the preconditioning operation for the Dove object. In this function,
	DOVE will call user defined coefficient and Jacobi functions to apply a preconditioning operation on the linear
	system. Note that each implicit method in DOVE must have its own preconditioner because the residuals are different.
	Also, each type of preconditioning will have its own function.
 
	Jacobi preconditioning:  Solve  Dp=v for p using input vector v and the diagonals (D) of the full jacobian.
 
	Diagonals for CN are of the form: dR_i/du_i = Rnp1[i] - 0.5*dt*jacobi[i][i](unp1)  */
int precond_Jac_CN(const eMatrix<double> &v, eMatrix<double> &p, const void *data);

/// Preconditioning function for a Tridiagonal preconditioner on the implicit-CN method
/** This function will be passed to PJFNK as the preconditioning operation for the Dove object. In this function,
	DOVE will call user defined coefficient and Jacobi functions to apply a preconditioning operation on the linear
	system. Note that each implicit method in DOVE must have its own preconditioner because the residuals are different.
	Also, each type of preconditioning will have its own function.
 
	Tridiagonal preconditioning:  Solve  (TD)p=v for p using input vector v and a Tridiagonal (TD) of the full jacobian.
 
	Diagonals for CN are of the form: dR_i/du_i = Rnp1[i] - 0.5*dt*jacobi[i][i](unp1)
	Off-Diagonals for CN are of form: dR_i/du_j = Rnp1[i] - 0.5*dt*jacobi[i][j](unp1) for i==j
 and	  dR_i/du_j = -0.5*dt*jacobi[i][j](unp1)          for i!=j*/
int precond_Tridiag_CN(const eMatrix<double> &v, eMatrix<double> &p, const void *data);

/// Preconditioning function for an Upper-Gauss-Seidel preconditioner on the implicit-CN method
/** This function will be passed to PJFNK as the preconditioning operation for the Dove object. In this function,
	DOVE will call user defined coefficient and Jacobi functions to apply a preconditioning operation on the linear
	system. Note that each implicit method in DOVE must have its own preconditioner because the residuals are different.
	Also, each type of preconditioning will have its own function.
 
	UGS preconditioning:  Solve  (U*)p=v+Lp for p using input vector v with an Upper Triangular (U*) of the full jacobian
 and a strict lower triangular (L) of the full jacobian.
 
	Diagonals for CN are of the form: dR_i/du_i = Rnp1[i] - 0.5*dt*jacobi[i][i](unp1)
	Off-Diagonals for CN are of form: dR_i/du_j = Rnp1[i] - 0.5*dt*jacobi[i][j](unp1) for i==j
 and	  dR_i/du_j = -0.5*dt*jacobi[i][j](unp1)          for i!=j*/
int precond_UpperGS_CN(const eMatrix<double> &v, eMatrix<double> &p, const void *data);

/// Preconditioning function for a Lower-Gauss-Seidel preconditioner on the implicit-CN method
/** This function will be passed to PJFNK as the preconditioning operation for the Dove object. In this function,
	DOVE will call user defined coefficient and Jacobi functions to apply a preconditioning operation on the linear
	system. Note that each implicit method in DOVE must have its own preconditioner because the residuals are different.
	Also, each type of preconditioning will have its own function.
 
	LGS preconditioning:  Solve  (L*)p=v+Up for p using input vector v and a Lower Triangular (L*) of the full jacobian.
 and a strict upper triangular (U) of the full jacobian.
 
	Diagonals for CN are of the form: dR_i/du_i = Rnp1[i] - 0.5*dt*jacobi[i][i](unp1)
	Off-Diagonals for CN are of form: dR_i/du_j = Rnp1[i] - 0.5*dt*jacobi[i][j](unp1) for i==j
 and	  dR_i/du_j = -0.5*dt*jacobi[i][j](unp1)          for i!=j*/
int precond_LowerGS_CN(const eMatrix<double> &v, eMatrix<double> &p, const void *data);

/// Preconditioning function for a Symmetric-Gauss-Seidel preconditioner on the implicit-CN method
/** This function will be passed to PJFNK as the preconditioning operation for the Dove object. In this function,
	DOVE will call user defined coefficient and Jacobi functions to apply a preconditioning operation on the linear
	system. Note that each implicit method in DOVE must have its own preconditioner because the residuals are different.
	Also, each type of preconditioning will have its own function.
 
	SGS preconditioning:  Solve  (J)p=v for p using input vector v with the Jacobian matrix (J) approximately by first
 solving as an Upper-Gauss-Seidel, then as a Lower-Gauss-Seidel.
 
	Diagonals for CN are of the form: dR_i/du_i = Rnp1[i] - 0.5*dt*jacobi[i][i](unp1)
	Off-Diagonals for CN are of form: dR_i/du_j = Rnp1[i] - 0.5*dt*jacobi[i][j](unp1) for i==j
 and	  dR_i/du_j = -0.5*dt*jacobi[i][j](unp1)          for i!=j*/
int precond_SymmetricGS_CN(const eMatrix<double> &v, eMatrix<double> &p, const void *data);

/// Residual function for implicit-BDF2 method
/** This function will be passed to PJFNK as the residual function for the Dove object. In this function,
	DOVE will call the user defined rate functions to create a vector of residuals at the current iterate. That
	information will be passed into the pjfnk function (see lark.h) to iteratively solve the system of equations
	at a single time step. Note that the first time step will be the same as the BE method, then each subsequent
	time step will be made as a function of un+1, un, and un-1 time levels.
 
	Res[i] = an*Rnp1[i]*unp1[i] - bn*Rn[i]*un[i] + cn*Rnnm1[i]*unm1[i] - dt*func[i](unp1)
 
	where an = (1+2*rn)/(1+rn) ; bn = (1+rn) ; cn = (rn*rn)/(1+rn)
	and where rn = dt/dt_old
 
	\note if rn = 0 (i.e. for first step) then this is same as BE method*/
int residual_BDF2(const eMatrix<double> &u, eMatrix<double> &Res, const void *data);

/// Preconditioning function for a Jacobi preconditioner on the implicit-BDF2 method
/** This function will be passed to PJFNK as the preconditioning operation for the Dove object. In this function,
	DOVE will call user defined coefficient and Jacobi functions to apply a preconditioning operation on the linear
	system. Note that each implicit method in DOVE must have its own preconditioner because the residuals are different.
	Also, each type of preconditioning will have its own function.
 
	Jacobi preconditioning:  Solve  Dp=v for p using input vector v and the diagonals (D) of the full jacobian.
 
	Diagonals for BDF2 are of the form: dR_i/du_i = an*Rnp1[i] - dt*jacobi[i][i](unp1)  */
int precond_Jac_BDF2(const eMatrix<double> &v, eMatrix<double> &p, const void *data);

/// Preconditioning function for a Tridiagonal preconditioner on the implicit-BDF2 method
/** This function will be passed to PJFNK as the preconditioning operation for the Dove object. In this function,
	DOVE will call user defined coefficient and Jacobi functions to apply a preconditioning operation on the linear
	system. Note that each implicit method in DOVE must have its own preconditioner because the residuals are different.
	Also, each type of preconditioning will have its own function.
 
	Tridiagonal preconditioning:  Solve  (TD)p=v for p using input vector v and a Tridiagonal (TD) of the full jacobian.
 
	Diagonals for BDF2 are of the form: dR_i/du_i = an*Rnp1[i] - dt*jacobi[i][i](unp1)
	Off-Diagonals for BDF2 are of form: dR_i/du_j = an*Rnp1[i] - dt*jacobi[i][j](unp1) for i==j
 and	  dR_i/du_j = -dt*jacobi[i][j](unp1)          for i!=j*/
int precond_Tridiag_BDF2(const eMatrix<double> &v, eMatrix<double> &p, const void *data);

/// Preconditioning function for an Upper-Gauss-Seidel preconditioner on the implicit-BDF2 method
/** This function will be passed to PJFNK as the preconditioning operation for the Dove object. In this function,
	DOVE will call user defined coefficient and Jacobi functions to apply a preconditioning operation on the linear
	system. Note that each implicit method in DOVE must have its own preconditioner because the residuals are different.
	Also, each type of preconditioning will have its own function.
 
	UGS preconditioning:  Solve  (U*)p=v+Lp for p using input vector v with an Upper Triangular (U*) of the full jacobian
 and a strict lower triangular (L) of the full jacobian.
 
	Diagonals for BDF2 are of the form: dR_i/du_i = an*Rnp1[i] - dt*jacobi[i][i](unp1)
	Off-Diagonals for BDF2 are of form: dR_i/du_j = an*Rnp1[i] - dt*jacobi[i][j](unp1) for i==j
 and	dR_i/du_j = -dt*jacobi[i][j](unp1)          for i!=j*/
int precond_UpperGS_BDF2(const eMatrix<double> &v, eMatrix<double> &p, const void *data);

/// Preconditioning function for a Lower-Gauss-Seidel preconditioner on the implicit-BDF2 method
/** This function will be passed to PJFNK as the preconditioning operation for the Dove object. In this function,
	DOVE will call user defined coefficient and Jacobi functions to apply a preconditioning operation on the linear
	system. Note that each implicit method in DOVE must have its own preconditioner because the residuals are different.
	Also, each type of preconditioning will have its own function.
 
	LGS preconditioning:  Solve  (L*)p=v+Up for p using input vector v and a Lower Triangular (L*) of the full jacobian.
 and a strict upper triangular (U) of the full jacobian.
 
	Diagonals for BDF2 are of the form: dR_i/du_i = an*Rnp1[i] - dt*jacobi[i][i](unp1)
	Off-Diagonals for BDF2 are of form: dR_i/du_j = an*Rnp1[i] - dt*jacobi[i][j](unp1) for i==j
 and	dR_i/du_j = -dt*jacobi[i][j](unp1)          for i!=j*/
int precond_LowerGS_BDF2(const eMatrix<double> &v, eMatrix<double> &p, const void *data);

/// Preconditioning function for a Symmetric-Gauss-Seidel preconditioner on the implicit-BDF2 method
/** This function will be passed to PJFNK as the preconditioning operation for the Dove object. In this function,
	DOVE will call user defined coefficient and Jacobi functions to apply a preconditioning operation on the linear
	system. Note that each implicit method in DOVE must have its own preconditioner because the residuals are different.
	Also, each type of preconditioning will have its own function.
 
	SGS preconditioning:  Solve  (J)p=v for p using input vector v with the Jacobian matrix (J) approximately by first
 solving as an Upper-Gauss-Seidel, then as a Lower-Gauss-Seidel.
 
	Diagonals for BDF2 are of the form: dR_i/du_i = an*Rnp1[i] - dt*jacobi[i][i](unp1)
	Off-Diagonals for BDF2 are of form: dR_i/du_j = an*Rnp1[i] - dt*jacobi[i][j](unp1) for i==j
 and	dR_i/du_j = -dt*jacobi[i][j](unp1)          for i!=j*/
int precond_SymmetricGS_BDF2(const eMatrix<double> &v, eMatrix<double> &p, const void *data);

/// Default function
double default_func(int i, const eMatrix<double> &u, double t, const void *data, const Dove &dove);

/// Default time coefficient function
double default_coeff(int i, const eMatrix<double> &u, double t, const void *data, const Dove &dove);

/// Default Jacobian element function
double default_jacobi(int i, int j, const eMatrix<double> &u, double t, const void *data, const Dove &dove);

/// Test function for DOVE kernel
/** This function sets up and solves a test problem for DOVE. It is callable from the UI. */
int DOVE_TESTS();

#endif /* DOVE_HPP_ */
