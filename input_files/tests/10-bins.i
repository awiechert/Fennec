[GlobalParams]

 	vx = 0.0
	vy = 0.0
 	vz = 0.0
 
    diameters = '1 2 4 8 16 32 64 128 256 512'
    gama_correction = false

[] #END GlobalParams

[Problem]

[] #END Problem

[Mesh]

    type = GeneratedMesh
    dim = 1
	nx = 1
    xmin = 0.0
    xmax = 1.0

[] # END Mesh

[Variables]

    [./N0]
        order = FIRST
        family = MONOMIAL
        initial_condition = 0.000001
    [../]
 
 	[./N1]
 		order = FIRST
 		family = MONOMIAL
        initial_condition = 0.00001
 	[../]
 
 	[./N2]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0.0001
 	[../]
 
 	[./N3]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0.001
 	[../]
 
 	[./N4]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0.01
 	[../]
 
 	[./N5]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0.1
 	[../]
 
 	[./N6]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 1
 	[../]
 
 	[./N7]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 5
 	[../]
 
 	[./N8]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 10
 	[../]
 
 	[./N9]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 5
 	[../]


[] #END Variables

[AuxVariables]
 
	[./vol_total]
		order = FIRST
		family = MONOMIAL
	[../]

[] #END AuxVariables

[ICs]

[] #END ICs

[Kernels]

    [./N0_dot]
        type = CoefTimeDerivative
        variable = N0
        Coefficient = 1.0
    [../]

    [./N0_MPB]
        type = ConstMonoPB
        variable = N0
        main_variable = N0
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
    [../]
 
 	[./N1_dot]
 		type = CoefTimeDerivative
 		variable = N1
 		Coefficient = 1.0
 	[../]
 
 	[./N1_MPB]
 		type = ConstMonoPB
 		variable = N1
        main_variable = N1
 		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
 	[../]
 
 	[./N2_dot]
 		type = CoefTimeDerivative
 		variable = N2
 		Coefficient = 1.0
 	[../]
 
 	[./N2_MPB]
 		type = ConstMonoPB
 		variable = N2
 		main_variable = N2
 		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
 	[../]
 
 	[./N3_dot]
 		type = CoefTimeDerivative
 		variable = N3
		 Coefficient = 1.0
 	[../]
 
 	[./N3_MPB]
 		type = ConstMonoPB
 		variable = N3
 		main_variable = N3
 		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
 	[../]
 
 	[./N4_dot]
 		type = CoefTimeDerivative
 		variable = N4
 		Coefficient = 1.0
 	[../]
 
 	[./N4_MPB]
 		type = ConstMonoPB
 		variable = N4
 		main_variable = N4
 		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
 	[../]
 
 [./N5_dot]
 type = CoefTimeDerivative
 variable = N5
 Coefficient = 1.0
 [../]
 
 [./N5_MPB]
 type = ConstMonoPB
 variable = N5
 main_variable = N5
 coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
 [../]
 
 [./N6_dot]
 type = CoefTimeDerivative
 variable = N6
 Coefficient = 1.0
 [../]
 
 [./N6_MPB]
 type = ConstMonoPB
 variable = N6
 main_variable = N6
 coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
 [../]
 
 [./N7_dot]
 type = CoefTimeDerivative
 variable = N7
 Coefficient = 1.0
 [../]
 
 [./N7_MPB]
 type = ConstMonoPB
 variable = N7
 main_variable = N7
 coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
 [../]
 
 [./N8_dot]
 type = CoefTimeDerivative
 variable = N8
 Coefficient = 1.0
 [../]
 
 [./N8_MPB]
 type = ConstMonoPB
 variable = N8
 main_variable = N8
 coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
 [../]
 
 [./N9_dot]
 type = CoefTimeDerivative
 variable = N9
 Coefficient = 1.0
 [../]
 
 [./N9_MPB]
 type = ConstMonoPB
 variable = N9
 main_variable = N9
 coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
 [../]

[] #END Kernels

[DGKernels]

[] #END DGKernels

[AuxKernels]

	[./N_accumulated]
		type = VolumeBalanceCheck
		variable = vol_total
		coupled_vars = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
        execute_on = 'initial timestep_end'
	[../]

[] #END AuxKernels

[BCs]

 	[./N0_Flux]
 		type = DGFluxBC
 		variable = N0
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
 	[./N1_Flux]
 		type = DGFluxBC
 		variable = N1
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
 	[./N2_Flux]
 		type = DGFluxBC
 		variable = N2
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
 	[./N3_Flux]
 		type = DGFluxBC
 		variable = N3
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
 	[./N4_Flux]
 		type = DGFluxBC
 		variable = N4
 		boundary = 'left right'
 		u_input = 0.0
    [../]
 
 [./N5_Flux]
 type = DGFluxBC
 variable = N5
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N6_Flux]
 type = DGFluxBC
 variable = N6
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N7_Flux]
 type = DGFluxBC
 variable = N7
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N8_Flux]
 type = DGFluxBC
 variable = N8
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N9_Flux]
 type = DGFluxBC
 variable = N9
 boundary = 'left right'
 u_input = 0.0
 [../]

[] #END BCs

[Materials]


[] #END Materials

[Postprocessors]

#May consider custom versions of these postprocessors to correct for negative mass ocsillations...
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
 
 [./N3]
 type = ElementAverageValue
 variable = N3
 execute_on = 'initial timestep_end'
	[../]
 
 [./N4]
 type = ElementAverageValue
 variable = N4
 execute_on = 'initial timestep_end'
	[../]
 
 [./N5]
 type = ElementAverageValue
 variable = N5
 execute_on = 'initial timestep_end'
	[../]
 
 [./N6]
 type = ElementAverageValue
 variable = N6
 execute_on = 'initial timestep_end'
	[../]
 
 [./N7]
 type = ElementAverageValue
 variable = N7
 execute_on = 'initial timestep_end'
	[../]
 
 [./N8]
 type = ElementAverageValue
 variable = N8
 execute_on = 'initial timestep_end'
	[../]
 
 [./N9]
 type = ElementAverageValue
 variable = N9
 execute_on = 'initial timestep_end'
	[../]
 
	[./vol_total]
		type = ElementAverageValue
		variable = vol_total
		execute_on = 'initial timestep_end'
	[../]

[] #END Postprocessors

[Executioner]

    type = Transient
	scheme = bdf2

    # NOTE: The default tolerances are far to strict and cause the program to crawl
    nl_rel_tol = 1e-6
    nl_abs_tol = 1e-6
    nl_rel_step_tol = 1e-10
    nl_abs_step_tol = 1e-10
    l_tol = 1e-6
    l_max_its = 20
    nl_max_its = 10

    solve_type = pjfnk
    line_search = bt    # Options: default shell none basic l2 bt cp
    start_time = 0.0
	end_time = 500.0
    dtmax = 0.5
    petsc_options_iname = '-pc_type -pc_hypre_type -ksp_gmres_restart'
    petsc_options_value = 'hypre boomeramg 100'

    [./TimeStepper]
		type = SolutionTimeAdaptiveDT
#		type = ConstantDT
        dt = 0.025
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
    print_linear_residuals = true

[] #END Outputs
