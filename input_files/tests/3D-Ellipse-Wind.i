[GlobalParams]

 	diameters = '1.78e-9 5.62e-9 1.78e-8'
 	breakup_coefficient = 0.05
 	fragment_number = 5.0
    efficiency = 4.5e-8

[] #END GlobalParams

[Problem]

[] #END Problem

[Mesh]

    type = GeneratedMesh
    dim = 3
	nx = 100
	ny = 10
	nz = 10
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
 
    [./wx]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0.2
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
		initial_condition = 0.0
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

[] #END DGKernels

[AuxKernels]

	[./Total_Volume]
		type = VolumeBalanceCheck
		variable = V_total
		coupled_vars = 'N0 N1 N2'
        execute_on = 'initial timestep_end'
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
		particle_diameter = 1.78e-9
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
		particle_diameter = 1.78e-9
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
		particle_diameter = 1.78e-9
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
		particle_diameter = 5.62e-9
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
		particle_diameter = 5.62e-9
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
		particle_diameter = 5.62e-9
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
		particle_diameter = 1.78e-8
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
		particle_diameter = 1.78e-8
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
		particle_diameter = 1.78e-8
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
    nl_abs_tol = 5e-8
    nl_rel_step_tol = 1e-16
    nl_abs_step_tol = 1e-8
    l_tol = 1e-10
    l_max_its = 300
    nl_max_its = 50

    solve_type = NEWTON
    line_search = bt    # Options: default shell none basic l2 bt cp
    start_time = 0.0
	end_time = 30.0
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
