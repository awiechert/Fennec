[GlobalParams]

    Dxx = 0.01
    Dyy = 0.01
	Dzz = 0.01

[] #END GlobalParams

[Problem]

[] #END Problem

[Mesh]

    file = Box-Valley-Converted.unv
    boundary_name = 'left right top bottom front back'

[] # END Mesh

[Variables]

    [./c1]
        order = FIRST
        family = MONOMIAL
    [../]
 
	[./c2]
		order = FIRST
		family = MONOMIAL
	[../]
 
	[./c3]
		order = FIRST
		family = MONOMIAL
	[../]


[] #END Variables

[AuxVariables]
 
	[./c_total]
		order = FIRST
		family = MONOMIAL
	[../]
 
	[./c_avg]
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
 
	[./vp1x]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp1y]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp1z]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp2x]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp2y]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp2z]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp3x]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp3y]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp3z]
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
 
	[./c1_ellipse]
		type = ConstantEllipsoidIC
		variable = c1
		value_inside = 100.0
		value_outside = 0.0
		x_length = 3
		y_length = 3
		z_length = 2
		x_center = 4
		y_center = 4
		z_center = 5
	[../]
 
	[./c2_ellipse]
		type = ConstantEllipsoidIC
		variable = c2
		value_inside = 200.0
		value_outside = 0.0
		x_length = 3
		y_length = 3
		z_length = 2
		x_center = 4
		y_center = 4
		z_center = 5
	[../]
 
	[./c3_ellipse]
		type = ConstantEllipsoidIC
		variable = c3
		value_inside = 100.0
		value_outside = 0.0
		x_length = 3
		y_length = 3
		z_length = 2
		x_center = 4
		y_center = 4
		z_center = 5
	[../]

[] #END ICs

[Kernels]

    [./c1_dot]
        type = CoefTimeDerivative
        variable = c1
        Coefficient = 1.0
    [../]

    [./c1_gadv]
        type = GConcentrationAdvection
        variable = c1
		ux = vp1x
		uy = vp1y
		uz = vp1z
    [../]

    [./c1_gdiff]
        type = GAnisotropicDiffusion
        variable = c1
    [../]
 
	[./c2_dot]
		type = CoefTimeDerivative
		variable = c2
		Coefficient = 1.0
	[../]
 
	[./c2_gadv]
		type = GConcentrationAdvection
		variable = c2
		ux = vp2x
		uy = vp2y
		uz = vp2z
	[../]
 
	[./c2_gdiff]
		type = GAnisotropicDiffusion
		variable = c2
	[../]
 
	[./c3_dot]
		type = CoefTimeDerivative
		variable = c3
		Coefficient = 1.0
	[../]
 
	[./c3_gadv]
		type = GConcentrationAdvection
		variable = c3
		ux = vp3x
		uy = vp3y
		uz = vp3z
	[../]
 
	[./c3_gdiff]
		type = GAnisotropicDiffusion
		variable = c3
	[../]

[] #END Kernels

[DGKernels]

    [./c1_dgadv]
        type = DGConcentrationAdvection
        variable = c1
		ux = vp1x
		uy = vp1y
		uz = vp1z
    [../]

    [./c1_dgdiff]
        type = DGAnisotropicDiffusion
        variable = c1
    [../]
 
	[./c2_dgadv]
		type = DGConcentrationAdvection
		variable = c2
		ux = vp2x
		uy = vp2y
		uz = vp2z
	[../]
 
	[./c2_dgdiff]
		type = DGAnisotropicDiffusion
		variable = c2
	[../]
 
	[./c3_dgadv]
		type = DGConcentrationAdvection
		variable = c3
		ux = vp3x
		uy = vp3y
		uz = vp3z
	[../]
 
	[./c3_dgdiff]
		type = DGAnisotropicDiffusion
		variable = c3
	[../]

[] #END DGKernels

[AuxKernels]

	[./c_accumulated]
		type = AccumulatedMaterial
		variable = c_total
		coupled_vars = 'c1 c2 c3'
		execute_on = 'initial timestep_begin timestep_end'
	[../]
 
	[./c_average]
		type = AverageMaterial
		variable = c_avg
		coupled_vars = 'c1 c2 c3'
		execute_on = 'initial timestep_begin timestep_end'
	[../]
 
	[./part_vel_1x]
		type = Trajectory1stOrder
		variable = vp1x
		direction = 0
		wind = wx
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 0.001
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_1y]
		type = Trajectory1stOrder
		variable = vp1y
		direction = 1
		wind = wy
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 0.001
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_1z]
		type = Trajectory1stOrder
		variable = vp1z
		direction = 2
		wind = wz
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 0.001
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_2x]
		type = Trajectory1stOrder
		variable = vp2x
		direction = 0
		wind = wx
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 0.0005
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_2y]
		type = Trajectory1stOrder
		variable = vp2y
		direction = 1
		wind = wy
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 0.0005
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_2z]
		type = Trajectory1stOrder
		variable = vp2z
		direction = 2
		wind = wz
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 0.0005
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_3x]
		type = Trajectory1stOrder
		variable = vp3x
		direction = 0
		wind = wx
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 0.00025
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_3y]
		type = Trajectory1stOrder
		variable = vp3y
		direction = 1
		wind = wy
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 0.00025
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_3z]
		type = Trajectory1stOrder
		variable = vp3z
		direction = 2
		wind = wz
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 0.00025
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

[] #END AuxKernels

[BCs]

    [./c1_Flux_in_L]
        type = DGConcentrationFluxBC
        variable = c1
        boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp1x
		uy = vp1y
		uz = vp1z
    [../]
 
	[./c2_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = c2
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp2x
		uy = vp2y
		uz = vp2z
	[../]
 
	[./c3_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = c3
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp3x
		uy = vp3y
		uz = vp3z
	[../]

[] #END BCs

[Materials]


[] #END Materials

[Postprocessors]

#May consider custom versions of these postprocessors to correct for negative mass ocsillations...
    [./c_avg]
        type = ElementAverageValue
        variable = c_avg
        execute_on = 'initial timestep_begin timestep_end'
    [../]
 
	[./c_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = c_total
		execute_on = 'initial timestep_end'
	[../]
 
	[./vp1z]
		type = ElementAverageValue
		variable = vp1z
		execute_on = 'initial timestep_end'
	[../]
 
	[./vp2z]
		type = ElementAverageValue
		variable = vp2z
		execute_on = 'initial timestep_end'
	[../]
 
	[./vp3z]
		type = ElementAverageValue
		variable = vp3z
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
	end_time = 0.05
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
# Adaptivity seems to create errors for the average auxkernel (and maybe the total)
	marker = errorfrac

	[./Indicators]
		[./error]
			type = GradientJumpIndicator
			variable = c_avg
		[../]
	[../]

	[./Markers]
		[./errorfrac]
			type = ErrorFractionMarker
			refine = 0.0
			coarsen = 0.0
#			refine = 0.5
#			coarsen = 0.5
			indicator = error
		[../]
	[../]

 [] #END Adaptivity

[Outputs]

    exodus = true
    csv = true
    print_linear_residuals = false

[] #END Outputs
