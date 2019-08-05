[GlobalParams]

 	vx = 0.0
	vy = 0.0
 	vz = 0.0

[] #END GlobalParams

[Problem]

[] #END Problem

[Mesh]

    type = GeneratedMesh
    dim = 1
	nx = 5
    xmin = 0.0
    xmax = 1.0

[] # END Mesh

[Variables]

    [./N0]
        order = FIRST
        family = MONOMIAL
        initial_condition = 50
    [../]
 
 	[./N1]
 		order = FIRST
 		family = MONOMIAL
        initial_condition = 0
 	[../]


[] #END Variables

[AuxVariables]
 
	[./N_total]
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
        Coefficient = -1.0  #NOTE: This is a negative to account for the rearrangement of the kernel into a residual
    [../]

    [./N0_MPB]
        type = ConstMonoPB
        variable = N0
        main_variable = N0
        diameters = '1 1.25992105'
        coupled_list = 'N0 N1'
    [../]
 
 	[./N1_dot]
 		type = CoefTimeDerivative
 		variable = N1
 		Coefficient = -1.0	#NOTE: This is a negative to account for the rearrangement of the kernel into a residual
 	[../]
 
 	[./N1_MPB]
 		type = ConstMonoPB
 		variable = N1
        main_variable = N1
 		diameters = '1 1.25992105'
 		coupled_list = 'N0 N1'
 	[../]

[] #END Kernels

[DGKernels]

[] #END DGKernels

[AuxKernels]

	[./N_accumulated]
		type = AccumulatedMaterial
		variable = N_total
		coupled_vars = 'N0 N1'
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
 
	[./N_total]
		type = ElementAverageValue
		variable = N_total
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
	end_time = 0.5
    dtmax = 0.5
    petsc_options_iname = '-pc_type -pc_hypre_type -ksp_gmres_restart'
    petsc_options_value = 'hypre boomeramg 100'

    [./TimeStepper]
#		type = SolutionTimeAdaptiveDT
		type = ConstantDT
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
