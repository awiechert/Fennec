[GlobalParams]

 	diameters = '1.78e-9 5.62e-9 1.78e-8'
 	breakup_coefficient = 0.01
 	fragment_number = 5.0
    efficiency = 4.5e-7

[] #END GlobalParams

[Problem]

[] #END Problem

[Mesh]

    type = GeneratedMesh
    dim = 3
	nx = 200
	ny = 20
	nz = 20
    xmin = 0.0
    xmax = 10.0
    ymin = 0.0
    ymax = 1.0
	zmin = 0.0
	zmax = 1.0

[] # END Mesh

[Variables]

    [./N0]
        order = FIRST
        family = MONOMIAL
    [../]
 
 	[./N1]
 		order = FIRST
 		family = MONOMIAL
 	[../]
 
 	[./N2]
 		order = FIRST
 		family = MONOMIAL
 	[../]
 
[] #END Variables

[AuxVariables]
 
	[./V_total]
 		order = FIRST
 		family = MONOMIAL
	[../]

[] #END AuxVariables

[ICs]

	[./N0_IC]
 		type = ConstantEllipsoidIC
        variable = N0
        value_inside = 2.87e6
        value_outside = 0.0
 		x_length = 0.25
 		y_length = 0.25
 		z_length = 0.25
        x_center = 0.5
        y_center = 0.5
        z_center = 0.5
        smoother_distance = 0.2
    [../]
 
 	[./N1_IC]
 		type = ConstantEllipsoidIC
        variable = N1
        value_inside = 1.66e6
        value_outside = 0.0
 		x_length = 0.25
 		y_length = 0.25
 		z_length = 0.25
        x_center = 0.5
        y_center = 0.5
        z_center = 0.5
        smoother_distance = 0.2
 	[../]
 
 	[./N2_IC]
 		type = ConstantEllipsoidIC
        variable = N2
        value_inside = 4.84e5
        value_outside = 0.0
 		x_length = 0.25
 		y_length = 0.25
 		z_length = 0.25
        x_center = 0.5
        y_center = 0.5
        z_center = 0.5
        smoother_distance = 0.2
 	[../]
 
[] #END ICs

[Kernels]

    [./N0_dot]
        type = CoefTimeDerivative
        variable = N0
        Coefficient = 1.0
    [../]

    [./N0_MPB_Agg]
        type = ConstMonoPB
        variable = N0
        main_variable = N0
        coupled_list = 'N0 N1 N2'
    [../]
 
 	[./N0_MPB_Break]
 		type = MultiFragLinearMonoPB
 		variable = N0
 		main_variable = N0
 		coupled_list = 'N0 N1 N2'
	[../]
 
 	[./N1_dot]
 		type = CoefTimeDerivative
 		variable = N1
 		Coefficient = 1.0
 	[../]
 
 	[./N1_MPB_Agg]
 		type = ConstMonoPB
 		variable = N1
        main_variable = N1
 		coupled_list = 'N0 N1 N2'
 	[../]
 
    [./N1_MPB_Break]
 		type = MultiFragLinearMonoPB
 		variable = N1
 		main_variable = N1
 		coupled_list = 'N0 N1 N2'
	[../]
 
 	[./N2_dot]
 		type = CoefTimeDerivative
 		variable = N2
 		Coefficient = 1.0
 	[../]
 
 	[./N2_MPB_Agg]
 		type = ConstMonoPB
 		variable = N2
 		main_variable = N2
 		coupled_list = 'N0 N1 N2'
    [../]
 
    [./N2_MPB_Break]
 		type = MultiFragLinearMonoPB
 		variable = N2
 		main_variable = N2
 		coupled_list = 'N0 N1 N2'
	[../]
 
[] #END Kernels

[DGKernels]

[] #END DGKernels

[AuxKernels]

	[./Total_Volume]
		type = VolumeBalanceCheck
		variable = V_total
		coupled_vars = 'N0 N1 N2'
        execute_on = 'initial timestep_end'
	[../]

[] #END AuxKernels

[BCs]

[] #END BCs

[Materials]

[] #END Materials

[UserObjects]
 
[] #END UserObjects

[Postprocessors]

    [./Total_Volume]
        type = ElementAverageValue
        variable = V_total
        execute_on = 'initial timestep_begin timestep_end'
    [../]
 
	[./N0]
		type = ElementAverageValue
		variable = N0
		execute_on = 'initial timestep_end'
	[../]
 
	[./N1]
		type = ElementAverageValue
		variable = N1
		execute_on = 'initial timestep_end'
	[../]
 
 	[./N2]
 		type = ElementAverageValue
 		variable = N2
		 execute_on = 'initial timestep_end'
	[../]
 
[] #END Postprocessors

[Executioner]

    type = Transient
	scheme = implicit-euler    #use: 'implicit-euler' or 'bdf2'
    automatic_scaling = false

    # NOTE: The default tolerances are far to strict and cause the program to crawl
    nl_rel_tol = 1e-18
    nl_abs_tol = 1e-8
    nl_rel_step_tol = 1e-16
    nl_abs_step_tol = 1e-8
    l_tol = 1e-10
    l_max_its = 200
    nl_max_its = 50

    solve_type = NEWTON
    line_search = bt    # Options: default shell none basic l2 bt cp
    start_time = 0.0
	end_time = 60.0
    dtmax = 1.0
    petsc_options_iname = '-pc_type -pc_hypre_type -ksp_gmres_restart'
    petsc_options_value = 'hypre boomeramg 100'

    [./TimeStepper]
#		type = SolutionTimeAdaptiveDT
		type = ConstantDT
        dt = 0.25
    [../]

[] #END Executioner

[Preconditioning]
 
	[./smp]
		type = SMP
		full = true
		petsc_options = '-snes_converged_reason'
		petsc_options_iname ='-pc_type -sub_pc_type -pc_hypre_type -pc_hypre_boomeramg_strong_threshold -ksp_gmres_restart -snes_max_funcs'
		petsc_options_value = 'hypre bjacobi boomeramg 0.7 2000 20000'
	[../]

[] #END Preconditioning
 
[Adaptivity]

[] #END Adaptivity

[Outputs]

    exodus = true
    csv = true
    print_linear_residuals = false

[] #END Outputs
