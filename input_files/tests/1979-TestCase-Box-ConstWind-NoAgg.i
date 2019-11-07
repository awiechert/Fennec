[GlobalParams]

 	Dxx = 10.0
 	Dyy = 10.0
	Dzz = 10.0
 
#    diameters = '0.00178 0.00562 0.0178 0.0562 0.178 0.562 1.78 5.62 17.8 56.2'

	#order of shape function for all variables (use: 'CONSTANT' or 'FIRST')
	order = FIRST

[] #END GlobalParams

[Problem]

[] #END Problem

[Mesh]

 	type = GeneratedMesh
 	dim = 3
    #NOTE: When NOT using mesh adaptivity, double or triple the nx, ny, and nz values
 	nx = 30
	ny = 12
	nz = 8
 	xmin = 0.0
 	xmax = 36000.0
 	ymin = 0.0
 	ymax = 12000.0
	zmin = 500.0
	zmax = 12000.0

[] # END Mesh

[Variables]
# Units: GGp/m^3 (Billion-Billion particles per cubic meter)
# NOTE: Must be cautious of the units you use for the variables. Bad unit basis can make convergence difficult.
    [./N0]
        family = MONOMIAL
    [../]
 
 	[./N1]
 		family = MONOMIAL
 	[../]
 
 	[./N2]
 		family = MONOMIAL
 	[../]
 
 	[./N3]
 		family = MONOMIAL
 	[../]
 
 	[./N4]
 		family = MONOMIAL
    [../]
 
 	[./N5]
 		family = MONOMIAL
 	[../]
 
 	[./N6]
 		family = MONOMIAL
 	[../]
 
 	[./N7]
 		family = MONOMIAL
 	[../]
 
 	[./N8]
 		family = MONOMIAL
 	[../]
 
 	[./N9]
 		family = MONOMIAL
 	[../]


[] #END Variables

[AuxVariables]
 
 	[./N_total]
 		family = MONOMIAL
	[../]
 
	[./N_avg]
 		family = MONOMIAL
	[../]
 
 	[./air_dens]
 		family = MONOMIAL
 		initial_condition = 1.225 #kg/m^3
	[../]
 
 	[./air_ions]
 		family = MONOMIAL
	[../]
 
 	[./air_visc]
 		family = MONOMIAL
 		initial_condition = 1.802e-5 #kg/m/s
	[../]
 
 	[./air_temp]
 		family = MONOMIAL
 		initial_condition = 298 #K
	[../]
 
 	[./wx]
 		family = MONOMIAL
	[../]
 
	[./wy]
 		family = MONOMIAL
	[../]
 
	[./wz]
 		family = MONOMIAL
 		initial_condition = -10.0
	[../]
 
 	[./vp0x]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp0y]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp0z]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
    [./vp1x]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp1y]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp1z]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
 	[./vp2x]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp2y]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp2z]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
 	[./vp3x]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp3y]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp3z]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
 	[./vp4x]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp4y]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp4z]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
 	[./vp5x]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp5y]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp5z]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
 	[./vp6x]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp6y]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp6z]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
 	[./vp7x]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp7y]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp7z]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
 	[./vp8x]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp8y]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp8z]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
 	[./vp9x]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp9y]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp9z]
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]

[] #END AuxVariables

[ICs]

	[./N0_IC]
 		type = CARDINAL_CloudIC
 		variable = N0
 		x_center = 6000
 		y_center = 6000
 		local_size_index = 0
 		cardinal_object = cardinal
 	[../]
 
 	[./N1_IC]
 		type = CARDINAL_CloudIC
 		variable = N1
 		x_center = 6000
 		y_center = 6000
 		local_size_index = 1
 		cardinal_object = cardinal
 	[../]
 
 	[./N2_IC]
 		type = CARDINAL_CloudIC
 		variable = N2
 		x_center = 6000
 		y_center = 6000
 		local_size_index = 2
 		cardinal_object = cardinal
 	[../]
 
 	[./N3_IC]
 		type = CARDINAL_CloudIC
 		variable = N3
 		x_center = 6000
 		y_center = 6000
 		local_size_index = 3
 		cardinal_object = cardinal
 	[../]
 
 	[./N4_IC]
 		type = CARDINAL_CloudIC
 		variable = N4
 		x_center = 6000
 		y_center = 6000
 		local_size_index = 4
 		cardinal_object = cardinal
 	[../]
 
 	[./N5_IC]
 		type = CARDINAL_CloudIC
 		variable = N5
 		x_center = 6000
 		y_center = 6000
 		local_size_index = 5
 		cardinal_object = cardinal
 	[../]
 
 	[./N6_IC]
 		type = CARDINAL_CloudIC
 		variable = N6
 		x_center = 6000
 		y_center = 6000
 		local_size_index = 6
 		cardinal_object = cardinal
 	[../]
 
 	[./N7_IC]
 		type = CARDINAL_CloudIC
 		variable = N7
 		x_center = 6000
 		y_center = 6000
 		local_size_index = 7
 		cardinal_object = cardinal
 	[../]
 
 	[./N8_IC]
 		type = CARDINAL_CloudIC
 		variable = N8
 		x_center = 6000
 		y_center = 6000
 		local_size_index = 8
 		cardinal_object = cardinal
 	[../]
 
 	[./N9_IC]
 		type = CARDINAL_CloudIC
 		variable = N9
 		x_center = 6000
 		y_center = 6000
 		local_size_index = 9
 		cardinal_object = cardinal
 	[../]
 
 	[./wx_parabola]
 		type = ParabolicWindIC
 		variable = wx
 		max_velocity = 10.0
 		min_velocity = 0.0
 		max_altitude = 100.0
 		power_param = 0.5
	[../]
 
	[./wy_parabola]
 		type = ParabolicWindIC
 		variable = wy
 		max_velocity = 0.0
 		min_velocity = 0.0
 		max_altitude = 100.0
 		power_param = 0.5
	[../]

[] #END ICs

[Kernels]

#NOTE: The particle aggregation slows down the computations to a crawl

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
 
 	[./N5_dot]
 		type = CoefTimeDerivative
 		variable = N5
 		Coefficient = 1.0
	 [../]
 
 	[./N5_gadv]
 		type = GConcentrationAdvection
 		variable = N5
 		ux = vp5x
 		uy = vp5y
 		uz = vp5z
 	[../]
 
 	[./N5_gdiff]
 		type = GAnisotropicDiffusion
 		variable = N5
 	[../]
 
 	[./N6_dot]
 		type = CoefTimeDerivative
 		variable = N6
 		Coefficient = 1.0
 	[../]
 
 	[./N6_gadv]
 		type = GConcentrationAdvection
        variable = N6
		ux = vp6x
 		uy = vp6y
 		uz = vp6z
 	[../]
 
 	[./N6_gdiff]
 		type = GAnisotropicDiffusion
 		variable = N6
 	[../]
 
 	[./N7_dot]
 		type = CoefTimeDerivative
 		variable = N7
 		Coefficient = 1.0
 	[../]
 
 	[./N7_gadv]
 		type = GConcentrationAdvection
 		variable = N7
 		ux = vp7x
 		uy = vp7y
 		uz = vp7z
 	[../]
 
 	[./N7_gdiff]
 		type = GAnisotropicDiffusion
 		variable = N7
 	[../]
 
 	[./N8_dot]
 		type = CoefTimeDerivative
 		variable = N8
 		Coefficient = 1.0
 	[../]
 
 	[./N8_gadv]
 		type = GConcentrationAdvection
 		variable = N8
 		ux = vp8x
 		uy = vp8y
 		uz = vp8z
 	[../]
 
 	[./N8_gdiff]
 		type = GAnisotropicDiffusion
 		variable = N8
 	[../]
 
 	[./N9_dot]
 		type = CoefTimeDerivative
 		variable = N9
 		Coefficient = 1.0
 	[../]
 
 	[./N9_gadv]
 		type = GConcentrationAdvection
 		variable = N9
 		ux = vp9x
 		uy = vp9y
 		uz = vp9z
 	[../]
 
 	[./N9_gdiff]
 		type = GAnisotropicDiffusion
 		variable = N9
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
 
 	[./N5_dgadv]
 		type = DGConcentrationAdvection
 		variable = N5
 		ux = vp5x
 		uy = vp5y
 		uz = vp5z
 	[../]
 
 	[./N5_dgdiff]
 		type = DGAnisotropicDiffusion
 		variable = N5
 	[../]
 
 	[./N6_dgadv]
 		type = DGConcentrationAdvection
 		variable = N6
 		ux = vp6x
 		uy = vp6y
 		uz = vp6z
 	[../]
 
 	[./N6_dgdiff]
 		type = DGAnisotropicDiffusion
 		variable = N6
 	[../]
 
 	[./N7_dgadv]
 		type = DGConcentrationAdvection
 		variable = N7
 		ux = vp7x
 		uy = vp7y
 		uz = vp7z
 	[../]
 
 	[./N7_dgdiff]
 		type = DGAnisotropicDiffusion
 		variable = N7
 	[../]
 
 	[./N8_dgadv]
 		type = DGConcentrationAdvection
 		variable = N8
 		ux = vp8x
 		uy = vp8y
 		uz = vp8z
 	[../]
 
 	[./N8_dgdiff]
 		type = DGAnisotropicDiffusion
 		variable = N8
 	[../]
 
 	[./N9_dgadv]
 		type = DGConcentrationAdvection
 		variable = N9
 		ux = vp9x
 		uy = vp9y
 		uz = vp9z
 	[../]
 
 	[./N9_dgdiff]
 		type = DGAnisotropicDiffusion
 		variable = N9
 	[../]

[] #END DGKernels

[AuxKernels]
 
 	[./N_accumulated]
 		type = AccumulatedMaterial
 		variable = N_total
 		coupled_vars = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
 		vxs = 'vp0x vp1x vp2x vp3x vp4x vp5x vp6x vp7x vp8x vp9x'
 		vys = 'vp0y vp1y vp2y vp3y vp4y vp5y vp6y vp7y vp8y vp9y'
 		vzs = 'vp0z vp1z vp2z vp3z vp4z vp5z vp6z vp7z vp8z vp9z'
 		execute_on = 'initial timestep_end'
	[../]
 
	[./N_average]
 		type = AverageMaterial
 		variable = N_avg
		coupled_vars = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
 		execute_on = 'initial timestep_begin timestep_end'
	[../]
 
    [./ionization]
 		type = TotalAirIonization
        variable = air_ions
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
        air_density = air_dens
        cardinal_object = cardinal
        background_ionization = 0.0
        execute_on = 'initial timestep_end'
    [../]
 
 # ------------ Need to create NEW trajectory kernels to use Cardinal data instead of manual inputs for diameter and density ------------ #
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
 		particle_diameter = 0.00178e-6
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
 		particle_diameter = 0.00178e-6
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
 		particle_diameter = 0.00178e-6
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
 		particle_diameter = 0.00562e-6
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
 		particle_diameter = 0.00562e-6
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
 		particle_diameter = 0.00562e-6
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
 		particle_diameter = 0.0178e-6
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
 		particle_diameter = 0.0178e-6
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
 		particle_diameter = 0.0178e-6
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
 		particle_diameter = 0.0562e-6
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
 		particle_diameter = 0.0562e-6
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
 		particle_diameter = 0.0562e-6
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
 		particle_diameter = 0.178e-6
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
 		particle_diameter = 0.178e-6
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
 		particle_diameter = 0.178e-6
 		particle_density = 2600.0
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./part_vel_5x]
 		type = Trajectory1stOrder
 		variable = vp5x
 		direction = 0
 		windx = wx
 		windy = wy
 		windz = wz
 		varx = vp5x
 		vary = vp5y
 		varz = vp5z
 		air_density = air_dens
 		air_viscosity = air_visc
 		particle_diameter = 0.562e-6
 		particle_density = 2600.0
 		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_5y]
 		type = Trajectory1stOrder
 		variable = vp5y
 		direction = 1
	 	windx = wx
 		windy = wy
 		windz = wz
 		varx = vp5x
 		vary = vp5y
 		varz = vp5z
 		air_density = air_dens
 		air_viscosity = air_visc
 		particle_diameter = 0.562e-6
 		particle_density = 2600.0
 		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_5z]
 		type = Trajectory1stOrder
 		variable = vp5z
 		direction = 2
 		windx = wx
 		windy = wy
 		windz = wz
 		varx = vp5x
 		vary = vp5y
 		varz = vp5z
 		air_density = air_dens
 		air_viscosity = air_visc
 		particle_diameter = 0.562e-6
 		particle_density = 2600.0
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./part_vel_6x]
 		type = Trajectory1stOrder
 		variable = vp6x
 		direction = 0
 		windx = wx
 		windy = wy
 		windz = wz
 		varx = vp6x
 		vary = vp6y
 		varz = vp6z
 		air_density = air_dens
 		air_viscosity = air_visc
 		particle_diameter = 1.78e-6
 		particle_density = 2600.0
 		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_6y]
 		type = Trajectory1stOrder
 		variable = vp6y
 		direction = 1
 		windx = wx
 		windy = wy
 		windz = wz
 		varx = vp6x
 		vary = vp6y
 		varz = vp6z
 		air_density = air_dens
 		air_viscosity = air_visc
 		particle_diameter = 1.78e-6
 		particle_density = 2600.0
 		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_6z]
 		type = Trajectory1stOrder
 		variable = vp6z
 		direction = 2
 		windx = wx
 		windy = wy
 		windz = wz
 		varx = vp6x
 		vary = vp6y
 		varz = vp6z
 		air_density = air_dens
        air_viscosity = air_visc
 		particle_diameter = 1.78e-6
 		particle_density = 2600.0
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./part_vel_7x]
 		type = Trajectory1stOrder
 		variable = vp7x
 		direction = 0
 		windx = wx
 		windy = wy
 		windz = wz
 		varx = vp7x
 		vary = vp7y
 		varz = vp7z
 		air_density = air_dens
 		air_viscosity = air_visc
 		particle_diameter = 5.62e-6
 		particle_density = 2600.0
 		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_7y]
 		type = Trajectory1stOrder
 		variable = vp7y
 		direction = 1
 		windx = wx
 		windy = wy
 		windz = wz
 		varx = vp7x
 		vary = vp7y
 		varz = vp7z
 		air_density = air_dens
 		air_viscosity = air_visc
 		particle_diameter = 5.62e-6
 		particle_density = 2600.0
 		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_7z]
 		type = Trajectory1stOrder
 		variable = vp7z
 		direction = 2
 		windx = wx
 		windy = wy
 		windz = wz
 		varx = vp7x
 		vary = vp7y
 		varz = vp7z
 		air_density = air_dens
 		air_viscosity = air_visc
 		particle_diameter = 5.62e-6
 		particle_density = 2600.0
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./part_vel_8x]
 		type = Trajectory1stOrder
 		variable = vp8x
 		direction = 0
 		windx = wx
 		windy = wy
 		windz = wz
 		varx = vp8x
 		vary = vp8y
 		varz = vp8z
 		air_density = air_dens
 		air_viscosity = air_visc
 		particle_diameter = 17.8e-6
 		particle_density = 2600.0
 		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_8y]
 		type = Trajectory1stOrder
 		variable = vp8y
 		direction = 1
 		windx = wx
 		windy = wy
 		windz = wz
 		varx = vp8x
 		vary = vp8y
 		varz = vp8z
 		air_density = air_dens
 		air_viscosity = air_visc
 		particle_diameter = 17.8e-6
 		particle_density = 2600.0
 		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_8z]
 		type = Trajectory1stOrder
 		variable = vp8z
 		direction = 2
 		windx = wx
 		windy = wy
 		windz = wz
 		varx = vp8x
 		vary = vp8y
 		varz = vp8z
 		air_density = air_dens
 		air_viscosity = air_visc
 		particle_diameter = 17.8e-6
 		particle_density = 2600.0
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./part_vel_9x]
 		type = Trajectory1stOrder
 		variable = vp9x
 		direction = 0
 		windx = wx
 		windy = wy
 		windz = wz
 		varx = vp9x
 		vary = vp9y
 		varz = vp9z
 		air_density = air_dens
 		air_viscosity = air_visc
 		particle_diameter = 56.2e-6
 		particle_density = 2600.0
 		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_9y]
 		type = Trajectory1stOrder
 		variable = vp9y
 		direction = 1
 		windx = wx
 		windy = wy
 		windz = wz
 		varx = vp9x
 		vary = vp9y
 		varz = vp9z
 		air_density = air_dens
 		air_viscosity = air_visc
 		particle_diameter = 56.2e-6
 		particle_density = 2600.0
 		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_9z]
 		type = Trajectory1stOrder
 		variable = vp9z
 		direction = 2
 		windx = wx
 		windy = wy
 		windz = wz
 		varx = vp9x
 		vary = vp9y
 		varz = vp9z
 		air_density = air_dens
 		air_viscosity = air_visc
 		particle_diameter = 56.2e-6
 		particle_density = 2600.0
 		execute_on = 'initial timestep_end'
	[../]

[] #END AuxKernels

[BCs]

 	[./N0_Flux]
 		type = DGConcentrationFluxBC
 		variable = N0
 		boundary = 'left right top bottom front back'
 		u_input = 0.0
 		ux = vp0x
 		uy = vp0y
 		uz = vp0z
 	[../]
 
 	[./N1_Flux]
 		type = DGConcentrationFluxBC
 		variable = N1
 		boundary = 'left right top bottom front back'
 		u_input = 0.0
 		ux = vp1x
 		uy = vp1y
 		uz = vp1z
 	[../]
 
 	[./N2_Flux]
 		type = DGConcentrationFluxBC
 		variable = N2
 		boundary = 'left right top bottom front back'
 		u_input = 0.0
 		ux = vp2x
 		uy = vp2y
 		uz = vp2z
 	[../]
 
 	[./N3_Flux]
 		type = DGConcentrationFluxBC
 		variable = N3
 		boundary = 'left right top bottom front back'
 		u_input = 0.0
 		ux = vp3x
 		uy = vp3y
 		uz = vp3z
    [../]
 
 	[./N4_Flux]
 		type = DGConcentrationFluxBC
 		variable = N4
 		boundary = 'left right top bottom front back'
 		u_input = 0.0
 		ux = vp4x
 		uy = vp4y
 		uz = vp4z
 	[../]
 
 	[./N5_Flux]
 		type = DGConcentrationFluxBC
 		variable = N5
 		boundary = 'left right top bottom front back'
 		u_input = 0.0
 		ux = vp5x
 		uy = vp5y
 		uz = vp5z
 	[../]
 
 	[./N6_Flux]
 		type = DGConcentrationFluxBC
 		variable = N6
 		boundary = 'left right top bottom front back'
 		u_input = 0.0
 		ux = vp6x
 		uy = vp6y
 		uz = vp6z
 	[../]
 
 	[./N7_Flux]
 		type = DGConcentrationFluxBC
 		variable = N7
 		boundary = 'left right top bottom front back'
 		u_input = 0.0
 		ux = vp7x
 		uy = vp7y
 		uz = vp7z
 	[../]
 
 	[./N8_Flux]
 		type = DGConcentrationFluxBC
 		variable = N8
 		boundary = 'left right top bottom front back'
 		u_input = 0.0
 		ux = vp8x
 		uy = vp8y
 		uz = vp8z
 	[../]
 
 	[./N9_Flux]
 		type = DGConcentrationFluxBC
 		variable = N9
 		boundary = 'left right top bottom front back'
 		u_input = 0.0
 		ux = vp9x
 		uy = vp9y
 		uz = vp9z
 	[../]

[] #END BCs

[Materials]

	[./CollisionParams]
 		type = CollisionParameters
        block = 0
        cardinal_object = cardinal
        coupled_conc = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
        air_density = air_dens
        air_viscosity = air_visc
        temperature = air_temp
        ionization = air_ions
        windx = wx
        windy = wy
        windz = wz
        coupled_vx = 'vp0x vp1x vp2x vp3x vp4x vp5x vp6x vp7x vp8x vp9x'
        coupled_vy = 'vp0y vp1y vp2y vp3y vp4y vp5y vp6y vp7y vp8y vp9y'
        coupled_vz = 'vp0z vp1z vp2z vp3z vp4z vp5z vp6z vp7z vp8z vp9z'
    [../]

[] #END Materials

 
[UserObjects]
 
	[./cardinal]
 		type = CARDINAL_Object
 		execute_on = 'initial timestep_end'
 		input_file = 'input_files/cardinal/1979-Test-Case.txt'
 		atm_file = 'input_files/cardinal/DefaultAtmosphere.txt'
 		data_path = 'database/'
        mono_variate_population = true
 	[../]
 
 [] #END UserObjects

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
 
 	[./N5]
 		type = ElementAverageValue
 		variable = N5
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./N6]
 		type = ElementAverageValue
 		variable = N6
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./N7]
 		type = ElementAverageValue
 		variable = N7
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./N8]
 		type = ElementAverageValue
 		variable = N8
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./N9]
 		type = ElementAverageValue
 		variable = N9
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./total_ionization]
 		type = ElementAverageValue
 		variable = air_ions
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./vp0z]
 		type = ElementAverageValue
 		variable = vp0z
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
 
 	[./vp4z]
        type = ElementAverageValue
 		variable = vp4z
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./vp5z]
 		type = ElementAverageValue
 		variable = vp5z
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./vp6z]
 		type = ElementAverageValue
 		variable = vp6z
 		execute_on = 'initial timestep_end'
	[../]

 	[./vp7z]
 		type = ElementAverageValue
 		variable = vp7z
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./vp8z]
 		type = ElementAverageValue
 		variable = vp8z
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./vp9z]
 		type = ElementAverageValue
 		variable = vp9z
 		execute_on = 'initial timestep_end'
	[../]

[] #END Postprocessors

[Executioner]

    type = Transient
	scheme = bdf2    #use: 'implicit-euler' or 'bdf2'
    # All options: "implicit-euler explicit-euler crank-nicolson bdf2 explicit-midpoint dirk explicit-tvd-rk-2 newmark-beta"

    # NOTE: The default tolerances are far to strict and cause the program to crawl
    nl_rel_tol = 1e-14
    nl_abs_tol = 1e-6
    nl_rel_step_tol = 1e-10
    nl_abs_step_tol = 1e-10
    l_tol = 1e-6
    l_abs_tol = 1e-10
    l_max_its = 200
    nl_max_its = 40

    solve_type = jfnk   # Use: pjfnk (with SMP) and jfnk (with PBP) [PJFNK NOT WORKING!!!]
 
 	# WARNING!  pjfnk solver may be slow and inefficient. JFNK is converging faster!
 
    line_search = bt    # Options: default shell none basic l2 bt cp
    start_time = 0.0
	end_time = 5000.0
    dtmax = 60.0

    [./TimeStepper]
#		type = SolutionTimeAdaptiveDT
#		type = ConstantDT
		type = AccelDT
        dt_multiplier = 1.5
        dt = 0.1
    [../]

[] #END Executioner

[Preconditioning]
	[./smp]
		type = SMP
		full = true
		petsc_options = '-snes_converged_reason'
 
		petsc_options_iname ='-pc_type -sub_pc_type -pc_hypre_type -pc_hypre_boomeramg_strong_threshold -ksp_gmres_restart -snes_max_funcs'
		petsc_options_value = 'hypre bjacobi boomeramg 0.7 2000 20000'
 
    	#petsc_options_iname ='-ksp_type -pc_type -sub_pc_type -snes_max_it -sub_pc_factor_shift_type -pc_asm_overlap -snes_atol -snes_rtol'
 		#petsc_options_value = 'gmres asm lu 100 NONZERO 2 1E-14 1E-12'
 
 		#petsc_options_iname ='-ksp_type -pc_type -sub_pc_type -ksp_gmres_restart -snes_max_funcs'
 		#petsc_options_value = 'gmres bjacobi ilu 2000 20000'
	[../]
	
[] #END Preconditioning
 
[Adaptivity]

# Adaptivity seems to create errors for the average auxkernel (and maybe the total)
	marker = errorfrac
 
	[./Indicators]
 		[./error]
 			type = GradientJumpIndicator
 			variable = N_avg
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
