[GlobalParams]

 	diameters = '1.0e-9 1.0e-8 1.0e-7 1.0e-6 1.0e-5'
 	frequency = 24000.0

 
[] #END GlobalParams

[Problem]

[] #END Problem

[Mesh]

    type = GeneratedMesh
    dim = 3
	nx = 20
	ny = 20
	nz = 20
    xmin = 0.0
    xmax = 6000.0
    ymin = 0.0
    ymax = 6000.0
	zmin = 0.0
	zmax = 6000.0

[] # END Mesh

[Variables]

    [./N0]
        order = CONSTANT
        family = MONOMIAL
    [../]
 
 	[./N1]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
 	[./N2]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
 	[./N3]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
	 [./N4]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
[] #END Variables

[AuxVariables]
 
	[./V_total]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
 	[./N_total]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
    [./wx]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 20.0
	[../]
 
	[./wy]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./wz]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp0x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 10.0
	[../]
 
	[./vp0y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp0z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp1x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 10.0
	[../]
 
	[./vp1y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp1z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp2x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 10.0
	[../]
 
	[./vp2y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp2z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
 	[./vp3x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 10.0
	[../]
 
	[./vp3y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp3z]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
 	[./vp4x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 10.0
	[../]
 
	[./vp4y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp4z]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./air_dens]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 1.225 #kg/m^3
	[../]
 
	[./air_visc]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 1.802e-5 #kg/m/s
	[../]
 
 	[./air_ions]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
    [./air_temp]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 298 #K
	[../]

[] #END AuxVariables

[ICs]

	[./N0_IC]
 		type = CARDINAL_CloudIC
        variable = N0
        x_center = 3000
        y_center = 3000
        local_size_index = 0
        cardinal_object = cardinal
    [../]
 
 	[./N1_IC]
 		type = CARDINAL_CloudIC
 		variable = N1
        x_center = 3000
        y_center = 3000
 		local_size_index = 1
 		cardinal_object = cardinal
 	[../]
 
 	[./N2_IC]
 		type = CARDINAL_CloudIC
 		variable = N2
        x_center = 3000
        y_center = 3000
 		local_size_index = 2
 		cardinal_object = cardinal
 	[../]
 
 	[./N3_IC]
 		type = CARDINAL_CloudIC
 		variable = N3
        x_center = 3000
        y_center = 3000
 		local_size_index = 3
 		cardinal_object = cardinal
 	[../]
 
 	[./N4_IC]
 		type = CARDINAL_CloudIC
 		variable = N4
        x_center = 3000
        y_center = 3000
 		local_size_index = 4
 		cardinal_object = cardinal
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
        coupled_list = 'N0 N1 N2 N3 N4'
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
        coupled_list = 'N0 N1 N2 N3 N4'
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
        coupled_list = 'N0 N1 N2 N3 N4'
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
 
 	[./N3_MPB_Agg]
        type = ConstMonoPB
        variable = N3
        main_variable = N3
        coupled_list = 'N0 N1 N2 N3 N4'
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
 
 	[./N4_MPB_Agg]
        type = ConstMonoPB
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

	[./Total_Volume]
		type = VolumeBalanceCheck
		variable = V_total
		coupled_vars = 'N0 N1 N2 N3 N4'
        execute_on = 'initial timestep_end'
	[../]
 
    [./N_accumulated]
 		type = AccumulatedMaterial
 		variable = N_total
 		coupled_vars = 'N0 N1 N2 N3 N4'
 		vxs = 'vp0x vp1x vp2x vp3x vp4x'
 		vys = 'vp0y vp1y vp2y vp3y vp4y'
 		vzs = 'vp0z vp1z vp2z vp3z vp4z'
 		execute_on = 'initial timestep_end'
	[../]
 
    [./ionization]
 		type = TotalAirIonization
        variable = air_ions
        coupled_list = 'N0 N1 N2 N3 N4'
        air_density = air_dens
        cardinal_object = cardinal
        background_ionization = 0.0
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
		particle_diameter = 1.0e-9
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
		particle_diameter = 1.0e-9
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
		particle_diameter = 1.0e-9
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
		particle_diameter = 1.0e-8
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
		particle_diameter = 1.0e-8
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
		particle_diameter = 1.0e-8
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
		particle_diameter = 1.0e-7
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
		particle_diameter = 1.0e-7
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
		particle_diameter = 1.0e-7
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
		particle_diameter = 1.0e-6
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
		particle_diameter = 1.0e-6
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
		particle_diameter = 1.0e-6
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
		particle_diameter = 1.0e-5
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
		particle_diameter = 1.0e-5
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
		particle_diameter = 1.0e-5
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

[UserObjects]

	[./cardinal]
 		type = CARDINAL_Object
 		execute_on = 'initial timestep_end'
 		input_file = 'input_files/cardinal/5-Bin-LowYield.txt'
 		atm_file = 'input_files/cardinal/DefaultAtmosphere.txt'
 		data_path = 'database/'
        mono_variate_population = true
 	[../]
 
[] #END UserObjects

[Postprocessors]

    [./Total_Volume]
        type = ElementAverageValue
        variable = V_total
        execute_on = 'initial timestep_begin timestep_end'
    [../]
 
    [./total_ionization]
 		type = ElementAverageValue
 		variable = air_ions
 		execute_on = 'initial timestep_end'
	[../]
 
    [./N_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N_total
		execute_on = 'initial timestep_end'
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
 
[] #END Postprocessors

[Executioner]

    type = Transient
	scheme = implicit-euler    #use: 'implicit-euler' or 'bdf2'
    automatic_scaling = false

    # NOTE: The default tolerances are far to strict and cause the program to crawl
    nl_rel_tol = 1e-18
    nl_abs_tol = 1e-6
    nl_rel_step_tol = 1e-16
    nl_abs_step_tol = 1e-6
    l_tol = 1e-10
    l_max_its = 100
    nl_max_its = 500

    solve_type = NEWTON
    line_search = bt    # Options: default shell none basic l2 bt cp
    start_time = 0.0
	end_time = 10.0
    dtmax = 1.0
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
    print_linear_residuals = false

[] #END Outputs
