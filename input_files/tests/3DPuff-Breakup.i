[GlobalParams]

    Dxx = 0.01
    Dyy = 0.01
	Dzz = 0.01

	diameters = '5.0e-6 1.0e-5 2.0e-5 4.0e-5 8.0e-5'
 	breakup_coefficient = 1.0
 	fragment_number = 5.0
 
[] #END GlobalParams

[Problem]

[] #END Problem

[Mesh]

    type = GeneratedMesh
    dim = 3
	nx = 75
	ny = 10
	nz = 5
    xmin = 0.0
    xmax = 150.0
    ymin = 0.0
    ymax = 20.0
	zmin = 0.0
	zmax = 10.0

[] # END Mesh

[Variables]

	[./N0]
		order = FIRST
		family = MONOMIAL
        initial_condition = 0
	[../]

	[./N1]
		order = FIRST
		family = MONOMIAL
        initial_condition = 0
	[../]
 
	[./N2]
 		order = FIRST
 		family = MONOMIAL
        initial_condition = 0
	[../]
 
 	[./N3]
 		order = FIRST
 		family = MONOMIAL
        initial_condition = 0
	[../]
 
	[./N4]
 		order = FIRST
 		family = MONOMIAL
	[../]

[] #END Variables

[AuxVariables]
 
	[./N0_total]
 		order = FIRST
 		family = MONOMIAL
	[../]
 
 	[./N4_total]
 		order = FIRST
 		family = MONOMIAL
	[../]
 
	[./wx]
		order = FIRST
		family = MONOMIAL
		initial_condition = 10.0
	[../]
 
	[./wy]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./wz]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp0x]
		order = FIRST
		family = MONOMIAL
		initial_condition = 1.0
	[../]
 
	[./vp0y]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp0z]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp1x]
		order = FIRST
		family = MONOMIAL
		initial_condition = 1.0
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
		initial_condition = 1.0
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
		initial_condition = 1.0
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
 
	[./vp4x]
		order = FIRST
		family = MONOMIAL
		initial_condition = 1.0
	[../]
 
	[./vp4y]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp4z]
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
 
 	[./N4_ellipse]
 		type = ConstantEllipsoidIC
 		variable = N4
 		value_inside = 100.0
 		value_outside = 0.0
 		x_length = 1
 		y_length = 1
 		z_length = 1
 		x_center = 4
 		y_center = 10
 		z_center = 7
        smoother_distance = 0.5
	[../]

[] #END ICs

[Kernels]

    [./N0_dot]
        type = CoefTimeDerivative
        variable = N0
        Coefficient = 1.0
    [../]

    [./N0_gadv]
        type = GConcentrationAdvection
        variable = N0
		ux = vp0x
		uy = vp0y
		uz = vp0z
    [../]

    [./N0_gdiff]
        type = GAnisotropicDiffusion
        variable = N0
    [../]

    [./N1_dot]
        type = CoefTimeDerivative
        variable = N1
        Coefficient = 1.0
    [../]

    [./N1_gadv]
        type = GConcentrationAdvection
        variable = N1
		ux = vp1x
		uy = vp1y
		uz = vp1z
    [../]

    [./N1_gdiff]
        type = GAnisotropicDiffusion
        variable = N1
    [../]

    [./N2_dot]
        type = CoefTimeDerivative
        variable = N2
        Coefficient = 1.0
    [../]

    [./N2_gadv]
        type = GConcentrationAdvection
        variable = N2
		ux = vp2x
		uy = vp2y
		uz = vp2z
    [../]

    [./N2_gdiff]
        type = GAnisotropicDiffusion
        variable = N2
    [../]

    [./N3_dot]
        type = CoefTimeDerivative
        variable = N3
        Coefficient = 1.0
    [../]

    [./N3_gadv]
        type = GConcentrationAdvection
        variable = N3
		ux = vp3x
		uy = vp3y
		uz = vp3z
    [../]

    [./N3_gdiff]
        type = GAnisotropicDiffusion
        variable = N3
    [../]
 
    [./N4_dot]
        type = CoefTimeDerivative
        variable = N4
        Coefficient = 1.0
    [../]

    [./N4_gadv]
        type = GConcentrationAdvection
        variable = N4
		ux = vp4x
		uy = vp4y
		uz = vp4z
    [../]

    [./N4_gdiff]
        type = GAnisotropicDiffusion
        variable = N4
    [../]

	[./N0_MPB]
		type = MultiFragLinearMonoPB
		variable = N0
		main_variable = N0
		coupled_list = 'N0 N1 N2 N3 N4'
	[../]

	[./N1_MPB]
		type = MultiFragLinearMonoPB
		variable = N1
		main_variable = N1
		coupled_list = 'N0 N1 N2 N3 N4'
	[../]
 
	[./N2_MPB]
 		type = MultiFragLinearMonoPB
 		variable = N2
		 main_variable = N2
 		coupled_list = 'N0 N1 N2 N3 N4'
	[../]

	[./N3_MPB]
		type = MultiFragLinearMonoPB
		variable = N3
		main_variable = N3
		coupled_list = 'N0 N1 N2 N3 N4'
	[../]

	[./N4_MPB]
		type = MultiFragLinearMonoPB
		variable = N4
		main_variable = N4
		coupled_list = 'N0 N1 N2 N3 N4'
	[../]
 
[] #END Kernels

[DGKernels]

    [./N0_dgadv]
        type = DGConcentrationAdvection
        variable = N0
		ux = vp0x
		uy = vp0y
		uz = vp0z
    [../]

    [./N0_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N0
    [../]
 
    [./N1_dgadv]
        type = DGConcentrationAdvection
        variable = N1
		ux = vp1x
		uy = vp1y
		uz = vp1z
    [../]

    [./N1_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N1
    [../]

    [./N2_dgadv]
        type = DGConcentrationAdvection
        variable = N2
		ux = vp2x
		uy = vp2y
		uz = vp2z
    [../]

    [./N2_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N2
    [../]
 
    [./N3_dgadv]
        type = DGConcentrationAdvection
        variable = N3
		ux = vp3x
		uy = vp3y
		uz = vp3z
    [../]

    [./N3_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N3
    [../]
 
    [./N4_dgadv]
        type = DGConcentrationAdvection
        variable = N4
		ux = vp4x
		uy = vp4y
		uz = vp4z
    [../]

    [./N4_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N4
    [../]

[] #END DGKernels

[AuxKernels]

	[./N0_accumulated]
		type = AccumulatedMaterial
		variable = N0_total
		coupled_vars = 'N0'
 		vxs = 'vp0x'
 		vys = 'vp0y'
 		vzs = 'vp0z'
	[../]

	[./N4_accumulated]
		type = AccumulatedMaterial
		variable = N4_total
		coupled_vars = 'N4'
 		vxs = 'vp4x'
 		vys = 'vp4y'
 		vzs = 'vp4z'
	[../]
 
	[./part_vel_0x]
		type = Trajectory1stOrder
		variable = vp0x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp0x
		vary = vp0y
		varz = vp0z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 5.0e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_0y]
		type = Trajectory1stOrder
		variable = vp0y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp0x
		vary = vp0y
		varz = vp0z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 5.0e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_0z]
		type = Trajectory1stOrder
		variable = vp0z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp0x
		vary = vp0y
		varz = vp0z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 5.0e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_1x]
		type = Trajectory1stOrder
		variable = vp1x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp1x
		vary = vp1y
		varz = vp1z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.0e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_1y]
		type = Trajectory1stOrder
		variable = vp1y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp1x
		vary = vp1y
		varz = vp1z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.0e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_1z]
		type = Trajectory1stOrder
		variable = vp1z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp1x
		vary = vp1y
		varz = vp1z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.0e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_2x]
		type = Trajectory1stOrder
		variable = vp2x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp2x
		vary = vp2y
		varz = vp2z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.0e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_2y]
		type = Trajectory1stOrder
		variable = vp2y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp2x
		vary = vp2y
		varz = vp2z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.0e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_2z]
		type = Trajectory1stOrder
		variable = vp2z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp2x
		vary = vp2y
		varz = vp2z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.0e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_3x]
		type = Trajectory1stOrder
		variable = vp3x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp3x
		vary = vp3y
		varz = vp3z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 4.0e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_3y]
		type = Trajectory1stOrder
		variable = vp3y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp3x
		vary = vp3y
		varz = vp3z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 4.0e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_3z]
		type = Trajectory1stOrder
		variable = vp3z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp3x
		vary = vp3y
		varz = vp3z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 4.0e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_4x]
		type = Trajectory1stOrder
		variable = vp4x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp4x
		vary = vp4y
		varz = vp4z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 8.0e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_4y]
		type = Trajectory1stOrder
		variable = vp4y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp4x
		vary = vp4y
		varz = vp4z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 8.0e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_4z]
		type = Trajectory1stOrder
		variable = vp4z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp4x
		vary = vp4y
		varz = vp4z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 8.0e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

[] #END AuxKernels

[BCs]

    [./N0_Flux_in_L]
        type = DGConcentrationFluxBC
        variable = N0
        boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp0x
		uy = vp0y
		uz = vp0z
    [../]
 
	[./N1_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N1
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp1x
		uy = vp1y
		uz = vp1z
	[../]
 
	[./N2_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N2
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp2x
		uy = vp2y
		uz = vp2z
	[../]

	[./N3_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N3
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp3x
		uy = vp3y
		uz = vp3z
	[../]
 
	[./N4_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N4
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp4x
		uy = vp4y
		uz = vp4z
	[../]

[] #END BCs

[Materials]


[] #END Materials

[Postprocessors]

    [./N0_avg]
        type = ElementAverageValue
        variable = N0
        execute_on = 'initial timestep_end'
    [../]
 
    [./N1_avg]
        type = ElementAverageValue
        variable = N1
        execute_on = 'initial timestep_end'
    [../]

    [./N2_avg]
        type = ElementAverageValue
        variable = N2
        execute_on = 'initial timestep_end'
    [../]

    [./N3_avg]
        type = ElementAverageValue
        variable = N3
        execute_on = 'initial timestep_end'
    [../]

    [./N4_avg]
        type = ElementAverageValue
        variable = N4
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
    l_max_its = 40
    nl_max_its = 10

    solve_type = pjfnk
    line_search = bt    # Options: default shell none basic l2 bt cp
    start_time = 0.0
	end_time = 20.0
    dtmax = 1.0
    petsc_options_iname = '-pc_type -pc_hypre_type -ksp_gmres_restart'
    petsc_options_value = 'hypre boomeramg 100'

    [./TimeStepper]
#		type = SolutionTimeAdaptiveDT
		type = ConstantDT
        dt = 0.2
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

[Outputs]

    exodus = true
    csv = true
    print_linear_residuals = false

[] #END Outputs
