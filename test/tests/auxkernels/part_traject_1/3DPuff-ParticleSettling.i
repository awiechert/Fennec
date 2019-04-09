[GlobalParams]

    Dxx = 0.01
    Dyy = 0.01
	Dzz = 0.01

[] #END GlobalParams

[Problem]

[] #END Problem

[Mesh]

    type = GeneratedMesh
    dim = 3
	nx = 10
	ny = 10
	nz = 5
    xmin = 0.0
    xmax = 10.0
    ymin = 0.0
    ymax = 10.0
	zmin = 0.0
	zmax = 5.0

[] # END Mesh

[Variables]

    [./c]
        order = FIRST
        family = MONOMIAL
    [../]


[] #END Variables

[AuxVariables]
 
	[./c_total]
		order = FIRST
		family = MONOMIAL
	[../]
 
	[./wx]
		order = FIRST
		family = MONOMIAL
		initial_condition = 5.0
	[../]
 
	[./wy]
		order = FIRST
		family = MONOMIAL
		initial_condition = 5.0
	[../]
 
	[./wz]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vpx]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vpy]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vpz]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./air_dens]
		order = FIRST
		family = MONOMIAL
		initial_condition = 1.225 #kg/m^3
	[../]
 
	[./air_visc]
		order = FIRST
		family = MONOMIAL
		initial_condition = 1.802e-5 #kg/m/s
	[../]

[] #END AuxVariables

[ICs]
 
	[./c_ellipse]
		type = ConstantEllipsoidIC
		variable = c
		value_inside = 10.0
		value_outside = 0.0
		x_length = 2
		y_length = 1.5
		z_length = 1
		x_center = 2.5
		y_center = 2.5
		z_center = 3
	[../]

[] #END ICs

[Kernels]

    [./c_dot]
        type = CoefTimeDerivative
        variable = c
        Coefficient = 1.0
    [../]

    [./c_gadv]
        type = GConcentrationAdvection
        variable = c
		ux = vpx
		uy = vpy
		uz = vpz
    [../]

    [./c_gdiff]
        type = GAnisotropicDiffusion
        variable = c
    [../]

[] #END Kernels

[DGKernels]

    [./c_dgadv]
        type = DGConcentrationAdvection
        variable = c
		ux = vpx
		uy = vpy
		uz = vpz
    [../]

    [./c_dgdiff]
        type = DGAnisotropicDiffusion
        variable = c
    [../]

[] #END DGKernels

[AuxKernels]

	[./c_accumulated]
		type = AccumulatedMaterial
		variable = c_total
		coupled_vars = 'c'
	[../]
 
	[./part_vel_x]
		type = Trajectory1stOrder
		variable = vpx
		direction = 0
		wind = wx
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 0.001
		particle_density = 2600.0
	[../]
 
	[./part_vel_y]
		type = Trajectory1stOrder
		variable = vpy
		direction = 1
		wind = wy
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 0.001
		particle_density = 2600.0
	[../]
 
	[./part_vel_z]
		type = Trajectory1stOrder
		variable = vpz
		direction = 2
		wind = wz
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 0.001
		particle_density = 2600.0
	[../]

[] #END AuxKernels

[BCs]

    [./c_Flux_in_L]
        type = DGConcentrationFluxBC
        variable = c
        boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vpx
		uy = vpy
		uz = vpz
    [../]

[] #END BCs

[Materials]


[] #END Materials

[Postprocessors]

#May consider custom versions of these postprocessors to correct for negative mass ocsillations...
    [./c_exit]
        type = SideAverageValue
        boundary = 'right'
        variable = c
        execute_on = 'initial timestep_end'
    [../]

    [./c_enter]
        type = SideAverageValue
        boundary = 'left'
        variable = c
        execute_on = 'initial timestep_end'
    [../]

    [./c_avg]
        type = ElementAverageValue
        variable = c
        execute_on = 'initial timestep_end'
    [../]
 
	[./c_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = c_total
		execute_on = 'initial timestep_end'
	[../]
 
	[./vpz]
		type = ElementAverageValue
		variable = vpz
		execute_on = 'initial timestep_end'
	[../]
 
	[./vpx]
		type = ElementAverageValue
		variable = vpx
		execute_on = 'initial timestep_end'
	[../]
 
	[./vpy]
		type = ElementAverageValue
		variable = vpy
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
	end_time = 0.15
    dtmax = 1.0
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
		petsc_options_iname ='-pc_type -sub_pc_type -pc_hypre_type -pc_hypre_boomeramg_strong_threshold -ksp_gmres_restart -snes_max_funcs'
		petsc_options_value = 'hypre bjacobi boomeramg 0.7 2000 20000'
	[../]

[] #END Preconditioning
 
[Adaptivity]
#	marker = errorfrac
#
#	[./Indicators]
#		[./error]
#			type = GradientJumpIndicator
#			variable = c
#		[../]
#	[../]
#
#	[./Markers]
#		[./errorfrac]
#			type = ErrorFractionMarker
#			refine = 0.5
#			coarsen = 0.5
#			indicator = error
#		[../]
#	[../]
#
 [] #END Adaptivity

[Outputs]

    exodus = true
    csv = true
    print_linear_residuals = true

[] #END Outputs
