[GlobalParams]

    vx = 2.0
    vy = -1.0

    Dxx = 0.1
    Dyy = 0.01

[] #END GlobalParams

[Problem]

[] #END Problem

[Mesh]

    type = GeneratedMesh
    dim = 2
#nx = 50
#ny = 20
	nx = 10
	ny = 5
    xmin = 0.0
    xmax = 10.0
    ymin = 0.0
    ymax = 5.0

[] # END Mesh

[Variables]

    [./u]
        order = FIRST
        family = MONOMIAL
    [../]


[] #END Variables

[AuxVariables]


[] #END AuxVariables

[ICs]

	[./u_ellipse]
		type = ConstantEllipsoidIC
		variable = u
		value_inside = 1.0
		value_outside = 0.0
		x_length = 2
		y_length = 1
		x_center = 2.5
		y_center = 2.5
		smoother_distance = 0.25
	[../]
 
[] #END ICs

[Kernels]

    [./u_dot]
        type = CoefTimeDerivative
        variable = u
        Coefficient = 1.0
    [../]

    [./u_gadv]
        type = GAdvection
        variable = u

    [../]

    [./u_gdiff]
        type = GAnisotropicDiffusion
        variable = u
    [../]

[] #END Kernels

[DGKernels]

    [./u_dgadv]
        type = DGAdvection
        variable = u
    [../]

    [./u_dgdiff]
        type = DGAnisotropicDiffusion
        variable = u
    [../]

[] #END DGKernels

[AuxKernels]


[] #END AuxKernels

[BCs]

    [./u_Flux_in_L]
        type = DGFluxBC
        variable = u
        boundary = 'left'
		u_input = 0.0
		vx = 2.0
    [../]
 
	[./u_Flux_out_R]
		type = DGFluxBC
		variable = u
		boundary = 'right'
		vx = 2.0
	[../]
 
	[./u_Flux_in_T]
		type = DGFluxBC
		variable = u
		boundary = 'top'
		u_input = 0.0
		vy = -1.0
	[../]
 
	[./u_Flux_out_B]
		type = DGFluxBC
		variable = u
		boundary = 'bottom'
		vy = -1.0
	[../]


[] #END BCs

[Materials]


[] #END Materials

[Postprocessors]

    [./u_exit]
        type = SideAverageValue
        boundary = 'right'
        variable = u
        execute_on = 'initial timestep_end'
    [../]

    [./u_enter]
        type = SideAverageValue
        boundary = 'left'
        variable = u
        execute_on = 'initial timestep_end'
    [../]

    [./u_avg]
        type = ElementAverageValue
        variable = u
        execute_on = 'initial timestep_end'
    [../]
 
	[./u_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = u
		execute_on = 'initial timestep_end'
	[../]

[] #END Postprocessors

[Executioner]

    type = Transient
	scheme = implicit-euler

    # NOTE: The default tolerances are far to strict and cause the program to crawl
    nl_rel_tol = 1e-6
    nl_abs_tol = 1e-6
    nl_rel_step_tol = 1e-10
    nl_abs_step_tol = 1e-10
    l_tol = 1e-6
    l_max_its = 100
    nl_max_its = 10

    solve_type = pjfnk
    line_search = bt    # Options: default shell none basic l2 bt cp
    start_time = 0.0
#end_time = 10.0
	end_time = 0.5
    dtmax = 0.1
    petsc_options_iname = '-pc_type -pc_hypre_type -ksp_gmres_restart'
    petsc_options_value = 'hypre boomeramg 100'

    [./TimeStepper]
#type = SolutionTimeAdaptiveDT
		type = ConstantDT
        dt = 0.05
    [../]

[] #END Executioner

[Preconditioning]
 
	[./smp]
		type = SMP
		full = true
		petsc_options = '-snes_converged_reason'
		petsc_options_iname = '-pc_type -sub_pc_type -pc_hypre_type -ksp_gmres_restart  -snes_max_funcs'
		petsc_options_value = 'lu ilu boomeramg 2000 20000'
	[../]

[] #END Preconditioning

[Outputs]

    exodus = true
    csv = true
    print_linear_residuals = false

[] #END Outputs
