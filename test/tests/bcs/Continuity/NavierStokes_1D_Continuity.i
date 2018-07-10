[GlobalParams]

[] #END GlobalParams

[Problem]

[] #END Problem

[Mesh]

    type = GeneratedMesh
    dim = 2
#	nx = 50
#	ny = 10
	nx = 10
	ny = 5
    xmin = 0.0
    xmax = 10.0
    ymin = 0.0
    ymax = 5.0

[] # END Mesh

[Variables]
#velocity units: m/s
    [./ux]
        order = FIRST
        family = MONOMIAL
    [../]

[] #END Variables

[AuxVariables]
 
	[./uy]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0
	[../]
 
	[./uz]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0
	[../]
 
	[./dens]
		order = FIRST
		family = MONOMIAL
		initial_condition = 1000.0  #kg/m^3
	[../]
 
	[./vis]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0.001	#kg/m/s
	[../]

[] #END AuxVariables

[ICs]
 
	[./ux_ellipse]
		type = ConstantEllipsoidIC
		variable = ux
		value_inside = 1.0
		value_outside = 0.1
		x_length = 2
		y_length = 1
		x_center = 2.5
		y_center = 2.5
		smoother_distance = 0.25
	[../]

[] #END ICs

[Kernels]

    [./ux_dot]
        type = MomentumAccumulation
        variable = ux
        density = dens
    [../]

    [./ux_gadv]
        type = GMomentumAdvection
        variable = ux
		direction = 0
		ux = ux
		uy = uy
		uz = uz
		density = dens
    [../]

    [./ux_gdiff]
        type = GMomentumDiffusion
        variable = ux
		viscosity = vis
    [../]
 
	[./ux_stress]
		type = StressTensor
		variable = ux
		direction = 0
		ux = ux
		uy = uy
		uz = uz
		viscosity = vis
	[../]

[] #END Kernels

[DGKernels]

    [./ux_dgadv]
        type = DGMomentumAdvection
		variable = ux
		direction = 0
		ux = ux
		uy = uy
		uz = uz
		density = dens
    [../]

    [./ux_dgdiff]
        type = DGMomentumDiffusion
        variable = ux
		viscosity = vis
    [../]

[] #END DGKernels

[AuxKernels]


[] #END AuxKernels

[BCs]
 
    [./ux_Flux]
        type = DGContinuumBC
        variable = ux
        boundary = 'left right'
		direction = 0
		ux = ux
		uy = uy
		uz = uz
		density = dens
    [../]
 
[] #END BCs

[Materials]


[] #END Materials

[Postprocessors]

    [./ux_exit]
        type = SideAverageValue
        boundary = 'right'
        variable = ux
        execute_on = 'initial timestep_end'
    [../]

    [./ux_enter]
        type = SideAverageValue
        boundary = 'left'
        variable = ux
        execute_on = 'initial timestep_end'
    [../]

    [./ux_avg]
        type = ElementAverageValue
        variable = ux
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
#	end_time = 10.0
	end_time = 0.5
    dtmax = 0.1
    petsc_options_iname = '-pc_type -pc_hypre_type -ksp_gmres_restart'
    petsc_options_value = 'hypre boomeramg 100'

    [./TimeStepper]
#		type = SolutionTimeAdaptiveDT
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
