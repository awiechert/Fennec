[GlobalParams]

    diameters = '5.00e-5 1.00e-6 2.00e-6 4.00e-6 8.00e-6'
 
 	packing_density = '0.75 0.75 0.75 0.75 0.75'
 
 	fractal_dimensions = '3.0 3.0 3.0 3.0 3.0'
 
 	breakup_constant = 1.0e-5
 
    dissipation = 0.3
 
    energy_dissipation = 0.3

[] #END GlobalParams

[Problem]

[] #END Problem

[Mesh]

    [gen]
    	type = GeneratedMeshGenerator
    	dim = 3
		nx = 150
		ny = 150
		nz = 6
    	xmin = 0.0
    	xmax = 300000.0
    	ymin = 0.0
    	ymax = 300000.0
		zmin = 0.0
		zmax = 12000.0
	[]

	[./subdomain1]
		input = gen
        type = SubdomainBoundingBoxGenerator
        bottom_left = '0 0 0'
        top_right = '300000 300000 2000'
        block_id = 1
    [../]

	[./break_boundary]
		type = BreakBoundaryOnSubdomainGenerator
		input = subdomain1
	[../]

	[./interface]
		input = break_boundary
		type = SideSetsBetweenSubdomainsGenerator
		primary_block = '0'
		paired_block = '1'
		new_boundary = 'master_interface'
	[../]

[] # END Mesh

[Variables]

    [./N0]
        order = CONSTANT
        family = MONOMIAL
        block = 0
    [../]
 
 	[./N1]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
 	[../]
 
 	[./N2]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
 	[../]
 
 	[./N3]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
 	[../]
 
    [./N4]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
 	[../]
 
    [./N0d]
        order = CONSTANT
        family = MONOMIAL
        initial_condition = 0.0
        block = 1
    [../]
 
 	[./N1d]
 		order = CONSTANT
 		family = MONOMIAL
        initial_condition = 0.0
        block = 1
 	[../]
 
 	[./N2d]
 		order = CONSTANT
 		family = MONOMIAL
        initial_condition = 0.0
        block = 1
 	[../]
 
 	[./N3d]
 		order = CONSTANT
 		family = MONOMIAL
        initial_condition = 0.0
        block = 1
 	[../]
 
    [./N4d]
 		order = CONSTANT
 		family = MONOMIAL
        initial_condition = 0.0
        block = 1
 	[../]
 
[] #END Variables

[AuxVariables]
 
	[./V_total]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
	[../]
 
    [./wx]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.355
        block = '0 1'
	[../]
 
	[./wy]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.355
        block = '0 1'
	[../]
 
	[./wz]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = '0 1'
	[../]
 
	[./vp0x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]
 
	[./vp0y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]
 
	[./vp0z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]
 
	[./vp1x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]
 
	[./vp1y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]
 
	[./vp1z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]
 
	[./vp2x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]
 
	[./vp2y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]
 
	[./vp2z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]
 
 	[./vp3x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
        block = 0
	[../]
 
	[./vp3y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
        block = 0
	[../]
 
	[./vp3z]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
        block = 0
	[../]
 
 	[./vp4x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
        block = 0
	[../]
 
	[./vp4y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
        block = 0
	[../]
 
	[./vp4z]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
        block = 0
	[../]

	[./air_dens]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 1.225 #kg/m^3
        block = '0 1'
	[../]
 
	[./air_visc]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 1.802e-5 #kg/m/s
        block = '0 1'
	[../]
 
 	[./air_ions]
 		order = CONSTANT
 		family = MONOMIAL
        block = '0 1'
	[../]
 
    [./air_temp]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 298 #K
        block = '0 1'
	[../]

[] #END AuxVariables

[ICs]

	[./N0_IC]
 		type = CARDINAL_CloudIC
        variable = N0
        x_center = 5000
        y_center = 5000
        local_size_index = 0
        cardinal_object = cardinal
        block = 0
    [../]
 
 	[./N1_IC]
 		type = CARDINAL_CloudIC
 		variable = N1
        x_center = 5000
        y_center = 5000
 		local_size_index = 1
 		cardinal_object = cardinal
        block = 0
 	[../]
 
 	[./N2_IC]
 		type = CARDINAL_CloudIC
 		variable = N2
        x_center = 5000
        y_center = 5000
 		local_size_index = 2
 		cardinal_object = cardinal
        block = 0
 	[../]
 
 	[./N3_IC]
 		type = CARDINAL_CloudIC
 		variable = N3
        x_center = 5000
        y_center = 5000
 		local_size_index = 3
 		cardinal_object = cardinal
        block = 0
 	[../]
 
 	[./N4_IC]
 		type = CARDINAL_CloudIC
 		variable = N4
        x_center = 5000
        y_center = 5000
 		local_size_index = 4
 		cardinal_object = cardinal
        block = 0
 	[../]

[] #END ICs

[Kernels]

    [./N0_dot]
        type = CoefTimeDerivative
        variable = N0
        Coefficient = 1.0
        block = 0
    [../]
 
    [./N0_gadv]
        type = GConcentrationAdvection
        variable = N0
		ux = vp0x
		uy = vp0y
		uz = vp0z
        block = 0
    [../]

    [./N0_gdiff]
        type = GAnisotropicDiffusion
        variable = N0
        block = 0
    [../]

    [./N0_MPB_Agg]
        type = CoagulationMonoPB
        variable = N0
        main_variable = N0
        coupled_list = 'N0 N1 N2 N3 N4'
        block = 0
    [../]
 
    [./N0_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N0
 		main_variable = N0
		coupled_list = 'N0 N1 N2 N3 N4'
        block = 0
	[../]
 
 	[./N1_dot]
 		type = CoefTimeDerivative
 		variable = N1
 		Coefficient = 1.0
        block = 0
 	[../]
 
    [./N1_gadv]
        type = GConcentrationAdvection
        variable = N1
		ux = vp1x
		uy = vp1y
		uz = vp1z
        block = 0
    [../]

    [./N1_gdiff]
        type = GAnisotropicDiffusion
        variable = N1
        block = 0
    [../]

    [./N1_MPB_Agg]
        type = CoagulationMonoPB
        variable = N1
        main_variable = N1
        coupled_list = 'N0 N1 N2 N3 N4'
        block = 0
    [../]
 
    [./N1_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N1
 		main_variable = N1
		coupled_list = 'N0 N1 N2 N3 N4'
        block = 0
	[../]
 
 	[./N2_dot]
 		type = CoefTimeDerivative
 		variable = N2
 		Coefficient = 1.0
        block = 0
 	[../]
 
    [./N2_gadv]
        type = GConcentrationAdvection
        variable = N2
		ux = vp2x
		uy = vp2y
		uz = vp2z
        block = 0
    [../]

    [./N2_gdiff]
        type = GAnisotropicDiffusion
        variable = N2
        block = 0
    [../]

    [./N2_MPB_Agg]
        type = CoagulationMonoPB
        variable = N2
        main_variable = N2
        coupled_list = 'N0 N1 N2 N3 N4'
        block = 0
    [../]
 
    [./N2_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N2
 		main_variable = N2
		coupled_list = 'N0 N1 N2 N3 N4'
        block = 0
	[../]
 
 	[./N3_dot]
 		type = CoefTimeDerivative
 		variable = N3
 		Coefficient = 1.0
        block = 0
 	[../]
 
    [./N3_gadv]
        type = GConcentrationAdvection
        variable = N3
		ux = vp3x
		uy = vp3y
		uz = vp3z
        block = 0
    [../]

    [./N3_gdiff]
        type = GAnisotropicDiffusion
        variable = N3
        block = 0
    [../]

    [./N3_MPB_Agg]
        type = CoagulationMonoPB
        variable = N3
        main_variable = N3
        coupled_list = 'N0 N1 N2 N3 N4'
        block = 0
    [../]
 
    [./N3_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N3
 		main_variable = N3
		coupled_list = 'N0 N1 N2 N3 N4'
        block = 0
	[../]
 
 	[./N4_dot]
 		type = CoefTimeDerivative
 		variable = N4
 		Coefficient = 1.0
        block = 0
 	[../]
 
    [./N4_gadv]
        type = GConcentrationAdvection
        variable = N4
		ux = vp4x
		uy = vp4y
		uz = vp4z
        block = 0
    [../]

    [./N4_gdiff]
        type = GAnisotropicDiffusion
        variable = N4
        block = 0
    [../]

    [./N4_MPB_Agg]
        type = CoagulationMonoPB
        variable = N4
        main_variable = N4
        coupled_list = 'N0 N1 N2 N3 N4'
        block = 0
    [../]
 
    [./N4_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N4
 		main_variable = N4
		coupled_list = 'N0 N1 N2 N3 N4'
        block = 0
	[../]

    [./N0d_dot]
        type = CoefTimeDerivative
        variable = N0d
        Coefficient = 1.0
        block = 1
    [../]
 
 	[./N1d_dot]
 		type = CoefTimeDerivative
 		variable = N1d
 		Coefficient = 1.0
        block = 1
 	[../]
 
 	[./N2d_dot]
 		type = CoefTimeDerivative
 		variable = N2d
 		Coefficient = 1.0
        block = 1
 	[../]
 
 	[./N3d_dot]
 		type = CoefTimeDerivative
 		variable = N3d
 		Coefficient = 1.0
        block = 1
 	[../]
 
 	[./N4d_dot]
 		type = CoefTimeDerivative
 		variable = N4d
 		Coefficient = 1.0
        block = 1
 	[../]

[] #END Kernels

[DGKernels]

    [./N0_dgadv]
        type = DGConcentrationAdvection
        variable = N0
		ux = vp0x
		uy = vp0y
		uz = vp0z
        block = 0
    [../]

    [./N0_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N0
        block = 0
    [../]
 
    [./N1_dgadv]
        type = DGConcentrationAdvection
        variable = N1
		ux = vp1x
		uy = vp1y
		uz = vp1z
        block = 0
    [../]

    [./N1_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N1
        block = 0
    [../]

    [./N2_dgadv]
        type = DGConcentrationAdvection
        variable = N2
		ux = vp2x
		uy = vp2y
		uz = vp2z
        block = 0
    [../]

    [./N2_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N2
        block = 0
    [../]
 
    [./N3_dgadv]
        type = DGConcentrationAdvection
        variable = N3
		ux = vp3x
		uy = vp3y
		uz = vp3z
        block = 0
    [../]

    [./N3_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N3
        block = 0
    [../]

    [./N4_dgadv]
        type = DGConcentrationAdvection
        variable = N4
		ux = vp4x
		uy = vp4y
		uz = vp4z
        block = 0
    [../]

    [./N4_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N4
        block = 0
    [../]

[] #END DGKernels

[InterfaceKernels]

	[./N0_interface_diffusion]
		type = InterfacialAnisotropicDiffusion
		variable = N0
        neighbor_var = N0d
		boundary = master_interface
	[../]

	[./N0_interface_advection]
		type = InterfaceAdvection
		variable = N0
        neighbor_var = N0d
		boundary = master_interface
		ux = vp0x
		uy = vp0y
		uz = vp0z
	[../]

	[./N1_interface_diffusion]
		type = InterfacialAnisotropicDiffusion
		variable = N1
        neighbor_var = N1d
		boundary = master_interface
	[../]

	[./N1_interface_advection]
		type = InterfaceAdvection
		variable = N1
        neighbor_var = N1d
		boundary = master_interface
		ux = vp1x
		uy = vp1y
		uz = vp1z
	[../]

	[./N2_interface_diffusion]
		type = InterfacialAnisotropicDiffusion
		variable = N2
        neighbor_var = N2d
		boundary = master_interface
	[../]

	[./N2_interface_advection]
		type = InterfaceAdvection
		variable = N2
        neighbor_var = N2d
		boundary = master_interface
		ux = vp2x
		uy = vp2y
		uz = vp2z
	[../]

	[./N3_interface_diffusion]
		type = InterfacialAnisotropicDiffusion
		variable = N3
        neighbor_var = N3d
		boundary = master_interface
	[../]

	[./N3_interface_advection]
		type = InterfaceAdvection
		variable = N3
        neighbor_var = N3d
		boundary = master_interface
		ux = vp3x
		uy = vp3y
		uz = vp3z
	[../]

	[./N4_interface_diffusion]
		type = InterfacialAnisotropicDiffusion
		variable = N4
        neighbor_var = N4d
		boundary = master_interface
	[../]

	[./N4_interface_advection]
		type = InterfaceAdvection
		variable = N4
        neighbor_var = N4d
		boundary = master_interface
		ux = vp4x
		uy = vp4y
		uz = vp4z
	[../]

[] #END InterfaceKernels

[AuxKernels]

	[./Total_Volume]
		type = VolumeBalanceCheck
		variable = V_total
		coupled_vars = 'N0 N1 N2 N3 N4'
        execute_on = 'initial timestep_end'
        block = 0
	[../]
 
    [./ionization]
 		type = TotalAirIonization
        variable = air_ions
        coupled_list = 'N0 N1 N2 N3 N4'
        air_density = air_dens
        cardinal_object = cardinal
        background_ionization = 0.0
        execute_on = 'initial timestep_end'
        block = 0
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
		particle_diameter = 5.00e-7
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
		particle_diameter = 5.00e-7
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
		particle_diameter = 5.00e-7
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
		particle_diameter = 1.00e-6
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
		particle_diameter = 1.00e-6
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
		particle_diameter = 1.00e-6
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
		particle_diameter = 2.00e-6
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
		particle_diameter = 2.00e-6
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
		particle_diameter = 2.00e-6
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
		particle_diameter = 4.00e-6
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
		particle_diameter = 4.00e-6
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
		particle_diameter = 4.00e-6
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
		particle_diameter = 8.00e-6
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
		particle_diameter = 8.00e-6
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
		particle_diameter = 8.00e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

[] #END AuxKernels

[BCs]

    [./N0_Flux_in_L]
        type = DGConcentrationFluxBC
        variable = N0
        boundary = 'left_to_0 right_to_0 top_to_0 bottom_to_0 front_to_0'
		u_input = 0.0
		ux = vp0x
		uy = vp0y
		uz = vp0z
    [../]
 
	[./N1_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N1
		boundary = 'left_to_0 right_to_0 top_to_0 bottom_to_0 front_to_0'
		u_input = 0.0
		ux = vp1x
		uy = vp1y
		uz = vp1z
	[../]
 
	[./N2_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N2
		boundary = 'left_to_0 right_to_0 top_to_0 bottom_to_0 front_to_0'
		u_input = 0.0
		ux = vp2x
		uy = vp2y
		uz = vp2z
	[../]
 
    [./N3_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N3
		boundary = 'left_to_0 right_to_0 top_to_0 bottom_to_0 front_to_0'
		u_input = 0.0
		ux = vp3x
		uy = vp3y
		uz = vp3z
	[../]
 
	[./N4_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N4
		boundary = 'left_to_0 right_to_0 top_to_0 bottom_to_0 front_to_0'
		u_input = 0.0
		ux = vp4x
		uy = vp4y
		uz = vp4z
	[../]

[] #END BCs

[Materials]

	[./CollisionParams_Atm]
 		type = CollisionParameters
        block = 0
        cardinal_object = cardinal
        coupled_conc = 'N0 N1 N2 N3 N4'
        air_density = air_dens
        air_viscosity = air_visc
        temperature = air_temp
        ionization = air_ions
        windx = wx
        windy = wy
        windz = wz
        coupled_vx = 'vp0x vp1x vp2x vp3x vp4x'
        coupled_vy = 'vp0y vp1y vp2y vp3y vp4y'
        coupled_vz = 'vp0z vp1z vp2z vp3z vp4z'
    [../]

	[./CollisionParams_Surf]
 		type = CollisionParameters
        block = 1
        cardinal_object = cardinal
        coupled_conc = 'N0d N1d N2d N3d N4d'
        air_density = air_dens
        air_viscosity = air_visc
        temperature = air_temp
        ionization = air_ions
        windx = wx
        windy = wy
        windz = wz
        coupled_vx = '0.0 0.0 0.0 0.0 0.0'
        coupled_vy = '0.0 0.0 0.0 0.0 0.0'
        coupled_vz = '0.0 0.0 0.0 0.0 0.0'
    [../]

[] #END Materials

[UserObjects]

	[./cardinal]
 		type = CARDINAL_Object
 		execute_on = 'initial timestep_end'
 		input_file = 'input_files/cardinal/5-Bin-Test.txt'
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
        block = 0
    [../]
 
    [./N00_floor]
		type = ElementAverageValue
		variable = N0d
		execute_on = 'initial timestep_end'
     	block = 1
	[../]

    [./N01_floor]
		type = ElementAverageValue
		variable = N1d
		execute_on = 'initial timestep_end'
        block = 1
	[../]

    [./N02_floor]
		type = ElementAverageValue
		variable = N2d
		execute_on = 'initial timestep_end'
        block = 1
	[../]

    [./N03_floor]
		type = ElementAverageValue
		variable = N3d
		execute_on = 'initial timestep_end'
        block = 1
	[../]

    [./N04_floor]
		type = ElementAverageValue
		variable = N4d
		execute_on = 'initial timestep_end'
        block = 1
	[../]

	[./N00]
		type = ElementAverageValue
		variable = N0
		execute_on = 'initial timestep_end'
        block = 0
	[../]
 
	[./N01]
		type = ElementAverageValue
		variable = N1
		execute_on = 'initial timestep_end'
        block = 0
	[../]
 
 	[./N02]
 		type = ElementAverageValue
 		variable = N2
		 execute_on = 'initial timestep_end'
         block = 0
	[../]
 
 	[./N03]
 		type = ElementAverageValue
 		variable = N3
 		execute_on = 'initial timestep_end'
        block = 0
	[../]
 
 	[./N04]
 		type = ElementAverageValue
 		variable = N4
 		execute_on = 'initial timestep_end'
        block = 0
	[../]

[] #END Postprocessors

[Preconditioning]
 
    [./SMP_PJFNK]
      type = SMP
      full = true
      solve_type = pjfnk
    [../]
 
[] #END Preconditioning
 
[Executioner]

  	type = Transient
  	scheme = implicit-euler

  	# NOTE: Add arg -ksp_view to get info on methods used at linear steps
  	petsc_options = '-snes_converged_reason

                    -ksp_gmres_modifiedgramschmidt'

  	# NOTE: The sub_pc_type arg not used if pc_type is ksp,
  	#       Instead, set the ksp_ksp_type to the pc method
  	#       you want. Then, also set the ksp_pc_type to be
  	#       the terminal preconditioner.
  	#
 	# Good terminal precon options: lu, ilu, asm, gasm, pbjacobi
  	#                               bjacobi, redundant, telescope
  	petsc_options_iname ='-ksp_type
                        -pc_type

                        -sub_pc_type

                        -snes_max_it

                        -sub_pc_factor_shift_type
                        -pc_factor_shift_type
                        -ksp_pc_factor_shift_type

                        -pc_asm_overlap

                        -snes_atol
                        -snes_rtol

                        -ksp_ksp_type
                        -ksp_pc_type'

  	# snes_max_it = maximum non-linear steps


  	######## NOTE: Best convergence results with asm pc and lu sub-pc ##############
  	##      Issue may be caused by the terminal pc of the ksp pc method
  	#       using MUMPS as the linear solver (which is an inefficient method)

  	petsc_options_value = 'fgmres
                         gasm

                         ilu

                         20

                         NONZERO
                         NONZERO
                         NONZERO

                         10

                         1E-12
                         1E-12

                         fgmres
                         ilu'

  	#NOTE: turning off line search can help converge for high Renolds number
  	line_search = none
  	nl_rel_tol = 1e-10
  	nl_abs_tol = 1e-10
  	nl_rel_step_tol = 1e-10
  	nl_abs_step_tol = 1e-10
  	nl_max_its = 20
  	l_tol = 1e-6
  	l_max_its = 20
 
    start_time = 0.0
	end_time = 604800.0
    dtmax = 3600.0

    [./TimeStepper]
#		type = SolutionTimeAdaptiveDT
		type = ConstantDT
        dt = 360.0
    [../]
 
[] #END Executioner
 
[Adaptivity]

[] #END Adaptivity

[Outputs]

    exodus = true
    csv = true
    print_linear_residuals = true
    interval = 20

[] #END Outputs
