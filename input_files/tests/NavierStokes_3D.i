[GlobalParams]

[] #END GlobalParams

[Problem]

[] #END Problem

[Mesh]

    type = GeneratedMesh
    dim = 3
	nx = 10
	ny = 10
	nz = 10
#	nx = 5
#	ny = 5
#	nz = 5
    xmin = 0.0
    xmax = 5.0
    ymin = 0.0
    ymax = 5.0
	zmin = 0.0
	zmax = 10.0

[] # END Mesh

[Variables]
#velocity units: m/s
    [./ux]
        order = FIRST
        family = MONOMIAL
    [../]
 
	[./uy]
		order = FIRST
		family = MONOMIAL
	[../]
 
	[./uz]
		order = FIRST
		family = MONOMIAL
	[../]

[] #END Variables

[AuxVariables]
 
	[./dens]
		order = FIRST
		family = MONOMIAL
	[../]
 
	[./vis]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0.001	#kg/m/s
	[../]
 
	[./grav]
		order = FIRST
		family = MONOMIAL
		initial_condition = -9.8	#m/s/s
	[../]

[] #END AuxVariables

[ICs]
 
	[./ux_ellipse]
		type = ConstantEllipsoidIC
		variable = ux
		value_inside = 0.0
		value_outside = 0.0
		x_length = 2
		y_length = 2
		z_length = 2
		x_center = 2.5
		y_center = 2.5
		z_center = 10
		smoother_distance = 0.5
	[../]
 
	[./uy_ellipse]
		type = ConstantEllipsoidIC
		variable = uy
		value_inside = 0.0
		value_outside = 0.0
		x_length = 2
		y_length = 2
		z_length = 2
		x_center = 2.5
		y_center = 2.5
		z_center = 10
		smoother_distance = 0.5
	[../]
 
	[./uz_ellipse]
		type = ConstantEllipsoidIC
		variable = uz
		value_inside = 0.0
		value_outside = 0.0
		x_length = 2
		y_length = 2
		z_length = 2
		x_center = 2.5
		y_center = 2.5
		z_center = 10
		smoother_distance = 0.5
	[../]
 
	[./dens_ellipse]
		type = ConstantEllipsoidIC
		variable = dens
		value_inside = 2000.0
		value_outside = 1000.0
		x_length = 2
		y_length = 2
		z_length = 2
		x_center = 2.5
		y_center = 2.5
		z_center = 10
		smoother_distance = 0.5
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
 
	[./uy_dot]
		type = MomentumAccumulation
		variable = uy
		density = dens
	[../]
 
	[./uy_gadv]
		type = GMomentumAdvection
		variable = uy
		direction = 1
		ux = ux
		uy = uy
		uz = uz
		density = dens
	[../]
 
	[./uy_gdiff]
		type = GMomentumDiffusion
		variable = uy
		viscosity = vis
	[../]
 
	[./uy_stress]
		type = StressTensor
		variable = uy
		direction = 1
		ux = ux
		uy = uy
		uz = uz
		viscosity = vis
	[../]
 
	[./uz_dot]
		type = MomentumAccumulation
		variable = uz
		density = dens
	[../]
 
	[./uz_gadv]
		type = GMomentumAdvection
		variable = uz
		direction = 2
		ux = ux
		uy = uy
		uz = uz
		density = dens
	[../]
 
	[./uz_gdiff]
		type = GMomentumDiffusion
		variable = uz
		viscosity = vis
	[../]
 
	[./uz_stress]
		type = StressTensor
		variable = uz
		direction = 2
		ux = ux
		uy = uy
		uz = uz
		viscosity = vis
	[../]
 
	[./uz_accel]
		type = MomentumAcceleration
		variable = uz
		density = dens
		acceleration = grav
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
 
	[./uy_dgadv]
		type = DGMomentumAdvection
		variable = uy
		direction = 1
		ux = ux
		uy = uy
		uz = uz
		density = dens
	[../]
 
	[./uy_dgdiff]
		type = DGMomentumDiffusion
		variable = uy
		viscosity = vis
	[../]
 
	[./uz_dgadv]
		type = DGMomentumAdvection
		variable = uz
		direction = 2
		ux = ux
		uy = uy
		uz = uz
		density = dens
	[../]
 
	[./uz_dgdiff]
		type = DGMomentumDiffusion
		variable = uz
		viscosity = vis
	[../]

[] #END DGKernels

[AuxKernels]


[] #END AuxKernels

[BCs]
 
    [./ux_Flux]
        type = DGContinuumBC
        variable = ux
        boundary = 'left right top bottom front back'
		direction = 0
		ux = ux
		uy = uy
		uz = uz
		density = dens
    [../]
 
	[./uy_Flux]
		type = DGContinuumBC
		variable = uy
		boundary = 'left right top bottom front back'
		direction = 1
		ux = ux
		uy = uy
		uz = uz
		density = dens
	[../]
 
	[./uz_Flux]
		type = DGContinuumBC
		variable = uz
		boundary = 'left right top bottom front back'
		direction = 2
		ux = ux
		uy = uy
		uz = uz
		density = dens
	[../]
 
[] #END BCs

[Materials]


[] #END Materials

[Postprocessors]

    [./uz_top]
        type = SideAverageValue
        boundary = 'top'
        variable = uz
        execute_on = 'initial timestep_end'
    [../]

    [./uz_bottom]
        type = SideAverageValue
        boundary = 'bottom'
        variable = uz
        execute_on = 'initial timestep_end'
    [../]

    [./ux_avg]
        type = ElementAverageValue
        variable = ux
        execute_on = 'initial timestep_end'
    [../]
 
	[./uy_avg]
		type = ElementAverageValue
		variable = uy
		execute_on = 'initial timestep_end'
	[../]
 
	[./uz_avg]
		type = ElementAverageValue
		variable = uz
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
	end_time = 10.0
#	end_time = 0.3
    dtmax = 0.1
    petsc_options_iname = '-pc_type -pc_hypre_type -ksp_gmres_restart'
    petsc_options_value = 'hypre boomeramg 100'

    [./TimeStepper]
		type = SolutionTimeAdaptiveDT
#		type = ConstantDT
        dt = 0.05
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
#NOTE: ONLY seems to work is using a single marker...
	marker = errorfrac
 
	[./Indicators]
		[./error]
			type = GradientJumpIndicator
			variable = uz
		[../]
	[../]
 
	[./Markers]
		[./errorfrac]
			type = ErrorFractionMarker
			refine = 0.2
			coarsen = 0.2
			indicator = error
		[../]
	[../]
 
 [] #END Adaptivity

[Outputs]

    exodus = true
    csv = true
    print_linear_residuals = false

[] #END Outputs
