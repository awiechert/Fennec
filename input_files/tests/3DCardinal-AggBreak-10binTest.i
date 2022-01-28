[GlobalParams]

    diameters = '2.00e-7 2.60e-7 3.38e-7 4.39e-7 5.71e-7 7.43e-7 9.65e-7 1.25e-6 1.63e-6 2.12e-6'

 	packing_density = '0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75'

 	fractal_dimensions = '3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0'

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
		nx = 25
		ny = 25
		nz = 26
    	xmin = 0.0
    	xmax = 10000.0
    	ymin = 0.0
    	ymax = 10000.0
		zmin = 0.0
		zmax = 10200.0
	[]

	[./subdomain1]
		input = gen
        type = SubdomainBoundingBoxGenerator
        bottom_left = '0 0 0'
        top_right = '10000 10000 200'
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

 	[./N5]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
 	[../]

 	[./N6]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
 	[../]

 	[./N7]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
 	[../]

    [./N8]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
 	[../]

    [./N9]
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

 	[./N5d]
 		order = CONSTANT
 		family = MONOMIAL
        initial_condition = 0.0
        block = 1
 	[../]

 	[./N6d]
 		order = CONSTANT
 		family = MONOMIAL
        initial_condition = 0.0
        block = 1
 	[../]

 	[./N7d]
 		order = CONSTANT
 		family = MONOMIAL
        initial_condition = 0.0
        block = 1
 	[../]

    [./N8d]
 		order = CONSTANT
 		family = MONOMIAL
        initial_condition = 0.0
        block = 1
 	[../]

    [./N9d]
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
		initial_condition = 0.0
        block = '0 1'
	[../]

	[./wy]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
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

	[./vp5x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

	[./vp5y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

	[./vp5z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

	[./vp6x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

	[./vp6y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

	[./vp6z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

	[./vp7x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

	[./vp7y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

	[./vp7z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

 	[./vp8x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
        block = 0
	[../]

	[./vp8y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
        block = 0
	[../]

	[./vp8z]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
        block = 0
	[../]

 	[./vp9x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
        block = 0
	[../]

	[./vp9y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
        block = 0
	[../]

	[./vp9z]
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

	[./N5_IC]
 		type = CARDINAL_CloudIC
        variable = N5
        x_center = 5000
        y_center = 5000
        local_size_index = 5
        cardinal_object = cardinal
        block = 0
    [../]

 	[./N6_IC]
 		type = CARDINAL_CloudIC
 		variable = N6
        x_center = 5000
        y_center = 5000
 		local_size_index = 6
 		cardinal_object = cardinal
        block = 0
 	[../]

 	[./N7_IC]
 		type = CARDINAL_CloudIC
 		variable = N7
        x_center = 5000
        y_center = 5000
 		local_size_index = 7
 		cardinal_object = cardinal
        block = 0
 	[../]

 	[./N8_IC]
 		type = CARDINAL_CloudIC
 		variable = N8
        x_center = 5000
        y_center = 5000
 		local_size_index = 8
 		cardinal_object = cardinal
        block = 0
 	[../]

 	[./N9_IC]
 		type = CARDINAL_CloudIC
 		variable = N9
        x_center = 5000
        y_center = 5000
 		local_size_index = 9
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
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
        block = 0
    [../]

    [./N0_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N0
 		main_variable = N0
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
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
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
        block = 0
    [../]

    [./N1_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N1
 		main_variable = N1
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
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
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
        block = 0
    [../]

    [./N2_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N2
 		main_variable = N2
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
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
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
        block = 0
    [../]

    [./N3_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N3
 		main_variable = N3
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
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
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
        block = 0
    [../]

    [./N4_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N4
 		main_variable = N4
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
        block = 0
	[../]

    [./N5_dot]
        type = CoefTimeDerivative
        variable = N5
        Coefficient = 1.0
        block = 0
    [../]

    [./N5_gadv]
        type = GConcentrationAdvection
        variable = N5
		ux = vp5x
		uy = vp5y
		uz = vp5z
        block = 0
    [../]

    [./N5_gdiff]
        type = GAnisotropicDiffusion
        variable = N5
        block = 0
    [../]

    [./N5_MPB_Agg]
        type = CoagulationMonoPB
        variable = N5
        main_variable = N5
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
        block = 0
    [../]

    [./N5_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N5
 		main_variable = N5
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
        block = 0
	[../]

 	[./N6_dot]
 		type = CoefTimeDerivative
 		variable = N6
 		Coefficient = 1.0
        block = 0
 	[../]

    [./N6_gadv]
        type = GConcentrationAdvection
        variable = N6
		ux = vp6x
		uy = vp6y
		uz = vp6z
        block = 0
    [../]

    [./N6_gdiff]
        type = GAnisotropicDiffusion
        variable = N6
        block = 0
    [../]

    [./N6_MPB_Agg]
        type = CoagulationMonoPB
        variable = N6
        main_variable = N6
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
        block = 0
    [../]

    [./N6_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N6
 		main_variable = N6
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
        block = 0
	[../]

 	[./N7_dot]
 		type = CoefTimeDerivative
 		variable = N7
 		Coefficient = 1.0
        block = 0
 	[../]

    [./N7_gadv]
        type = GConcentrationAdvection
        variable = N7
		ux = vp7x
		uy = vp7y
		uz = vp7z
        block = 0
    [../]

    [./N7_gdiff]
        type = GAnisotropicDiffusion
        variable = N7
        block = 0
    [../]

    [./N7_MPB_Agg]
        type = CoagulationMonoPB
        variable = N7
        main_variable = N7
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
        block = 0
    [../]

    [./N7_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N7
 		main_variable = N7
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
        block = 0
	[../]

 	[./N8_dot]
 		type = CoefTimeDerivative
 		variable = N8
 		Coefficient = 1.0
        block = 0
 	[../]

    [./N8_gadv]
        type = GConcentrationAdvection
        variable = N8
		ux = vp8x
		uy = vp8y
		uz = vp8z
        block = 0
    [../]

    [./N8_gdiff]
        type = GAnisotropicDiffusion
        variable = N8
        block = 0
    [../]

    [./N8_MPB_Agg]
        type = CoagulationMonoPB
        variable = N8
        main_variable = N8
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
        block = 0
    [../]

    [./N8_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N8
 		main_variable = N8
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
        block = 0
	[../]

 	[./N9_dot]
 		type = CoefTimeDerivative
 		variable = N9
 		Coefficient = 1.0
        block = 0
 	[../]

    [./N9_gadv]
        type = GConcentrationAdvection
        variable = N9
		ux = vp9x
		uy = vp9y
		uz = vp9z
        block = 0
    [../]

    [./N9_gdiff]
        type = GAnisotropicDiffusion
        variable = N9
        block = 0
    [../]

    [./N9_MPB_Agg]
        type = CoagulationMonoPB
        variable = N9
        main_variable = N9
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
        block = 0
    [../]

    [./N9_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N9
 		main_variable = N9
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
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

    [./N5d_dot]
        type = CoefTimeDerivative
        variable = N5d
        Coefficient = 1.0
        block = 1
    [../]

 	[./N6d_dot]
 		type = CoefTimeDerivative
 		variable = N6d
 		Coefficient = 1.0
        block = 1
 	[../]

 	[./N7d_dot]
 		type = CoefTimeDerivative
 		variable = N7d
 		Coefficient = 1.0
        block = 1
 	[../]

 	[./N8d_dot]
 		type = CoefTimeDerivative
 		variable = N8d
 		Coefficient = 1.0
        block = 1
 	[../]

 	[./N9d_dot]
 		type = CoefTimeDerivative
 		variable = N9d
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

    [./N5_dgadv]
        type = DGConcentrationAdvection
        variable = N5
		ux = vp5x
		uy = vp5y
		uz = vp5z
        block = 0
    [../]

    [./N5_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N5
        block = 0
    [../]

    [./N6_dgadv]
        type = DGConcentrationAdvection
        variable = N6
		ux = vp6x
		uy = vp6y
		uz = vp6z
        block = 0
    [../]

    [./N6_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N6
        block = 0
    [../]

    [./N7_dgadv]
        type = DGConcentrationAdvection
        variable = N7
		ux = vp7x
		uy = vp7y
		uz = vp7z
        block = 0
    [../]

    [./N7_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N7
        block = 0
    [../]

    [./N8_dgadv]
        type = DGConcentrationAdvection
        variable = N8
		ux = vp8x
		uy = vp8y
		uz = vp8z
        block = 0
    [../]

    [./N8_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N8
        block = 0
    [../]

    [./N9_dgadv]
        type = DGConcentrationAdvection
        variable = N9
		ux = vp9x
		uy = vp9y
		uz = vp9z
        block = 0
    [../]

    [./N9_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N9
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

	[./N5_interface_diffusion]
		type = InterfacialAnisotropicDiffusion
		variable = N5
        neighbor_var = N5d
		boundary = master_interface
	[../]

	[./N5_interface_advection]
		type = InterfaceAdvection
		variable = N5
        neighbor_var = N5d
		boundary = master_interface
		ux = vp5x
		uy = vp5y
		uz = vp5z
	[../]

	[./N6_interface_diffusion]
		type = InterfacialAnisotropicDiffusion
		variable = N6
        neighbor_var = N6d
		boundary = master_interface
	[../]

	[./N6_interface_advection]
		type = InterfaceAdvection
		variable = N6
        neighbor_var = N6d
		boundary = master_interface
		ux = vp6x
		uy = vp6y
		uz = vp6z
	[../]

	[./N7_interface_diffusion]
		type = InterfacialAnisotropicDiffusion
		variable = N7
        neighbor_var = N7d
		boundary = master_interface
	[../]

	[./N7_interface_advection]
		type = InterfaceAdvection
		variable = N7
        neighbor_var = N7d
		boundary = master_interface
		ux = vp7x
		uy = vp7y
		uz = vp7z
	[../]

	[./N8_interface_diffusion]
		type = InterfacialAnisotropicDiffusion
		variable = N8
        neighbor_var = N8d
		boundary = master_interface
	[../]

	[./N8_interface_advection]
		type = InterfaceAdvection
		variable = N8
        neighbor_var = N8d
		boundary = master_interface
		ux = vp8x
		uy = vp8y
		uz = vp8z
	[../]

	[./N9_interface_diffusion]
		type = InterfacialAnisotropicDiffusion
		variable = N9
        neighbor_var = N9d
		boundary = master_interface
	[../]

	[./N9_interface_advection]
		type = InterfaceAdvection
		variable = N9
        neighbor_var = N9d
		boundary = master_interface
		ux = vp9x
		uy = vp9y
		uz = vp9z
	[../]


[] #END InterfaceKernels

[AuxKernels]

	[./Total_Volume]
		type = VolumeBalanceCheck
		variable = V_total
		coupled_vars = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
        execute_on = 'initial timestep_end'
        block = 0
	[../]

    [./ionization]
 		type = TotalAirIonization
        variable = air_ions
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
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
		particle_diameter = 2.00e-7
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
		particle_diameter = 2.00e-7
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
		particle_diameter = 2.00e-7
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
		particle_diameter = 2.60e-7
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
		particle_diameter = 2.60e-7
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
		particle_diameter = 2.60e-7
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
		particle_diameter = 3.38e-7
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
		particle_diameter = 3.38e-7
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
		particle_diameter = 3.38e-7
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
		particle_diameter = 4.39e-7
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
		particle_diameter = 4.39e-7
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
		particle_diameter = 4.39e-7
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
		particle_diameter = 5.71e-7
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
		particle_diameter = 5.71e-7
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
		particle_diameter = 5.71e-7
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
		particle_diameter = 7.43e-7
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
		particle_diameter = 7.43e-7
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
		particle_diameter = 7.43e-7
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
		particle_diameter = 9.65e-7
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
		particle_diameter = 9.65e-7
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
		particle_diameter = 9.65e-7
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
		particle_diameter = 1.25e-6
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
		particle_diameter = 1.25e-6
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
		particle_diameter = 1.25e-6
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
		particle_diameter = 1.63e-6
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
		particle_diameter = 1.63e-6
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
		particle_diameter = 1.63e-6
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
		particle_diameter = 2.12e-6
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
		particle_diameter = 2.12e-6
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
		particle_diameter = 2.12e-6
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

    [./N5_Flux_in_L]
        type = DGConcentrationFluxBC
        variable = N5
        boundary = 'left_to_0 right_to_0 top_to_0 bottom_to_0 front_to_0'
		u_input = 0.0
		ux = vp5x
		uy = vp5y
		uz = vp5z
    [../]

	[./N6_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N6
		boundary = 'left_to_0 right_to_0 top_to_0 bottom_to_0 front_to_0'
		u_input = 0.0
		ux = vp6x
		uy = vp6y
		uz = vp6z
	[../]

	[./N7_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N7
		boundary = 'left_to_0 right_to_0 top_to_0 bottom_to_0 front_to_0'
		u_input = 0.0
		ux = vp7x
		uy = vp7y
		uz = vp7z
	[../]

    [./N8_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N8
		boundary = 'left_to_0 right_to_0 top_to_0 bottom_to_0 front_to_0'
		u_input = 0.0
		ux = vp8x
		uy = vp8y
		uz = vp8z
	[../]

	[./N9_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N9
		boundary = 'left_to_0 right_to_0 top_to_0 bottom_to_0 front_to_0'
		u_input = 0.0
		ux = vp9x
		uy = vp9y
		uz = vp9z
	[../]


[] #END BCs

[Materials]

	[./CollisionParams_Atm]
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

	[./CollisionParams_Surf]
 		type = CollisionParameters
        block = 1
        cardinal_object = cardinal
        coupled_conc = 'N0d N1d N2d N3d N4d N5d N6d N7d N8d N9d'
        air_density = air_dens
        air_viscosity = air_visc
        temperature = air_temp
        ionization = air_ions
        windx = wx
        windy = wy
        windz = wz
        coupled_vx = '0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0'
        coupled_vy = '0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0'
        coupled_vz = '0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0'
    [../]

[] #END Materials

[UserObjects]

	[./cardinal]
 		type = CARDINAL_Object
 		execute_on = 'initial timestep_end'
 		input_file = 'input_files/cardinal/10-Bin-TestingYield.txt'
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

    [./N05_floor]
		type = ElementAverageValue
		variable = N5d
		execute_on = 'initial timestep_end'
        block = 1
	[../]

    [./N06_floor]
		type = ElementAverageValue
		variable = N6d
		execute_on = 'initial timestep_end'
        block = 1
	[../]

    [./N07_floor]
		type = ElementAverageValue
		variable = N7d
		execute_on = 'initial timestep_end'
        block = 1
	[../]

    [./N08_floor]
		type = ElementAverageValue
		variable = N8d
		execute_on = 'initial timestep_end'
        block = 1
	[../]

    [./N09_floor]
		type = ElementAverageValue
		variable = N9d
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

	[./N05]
		type = ElementAverageValue
		variable = N5
		execute_on = 'initial timestep_end'
        block = 0
	[../]

	[./N06]
		type = ElementAverageValue
		variable = N6
		execute_on = 'initial timestep_end'
        block = 0
	[../]

 	[./N07]
 		type = ElementAverageValue
 		variable = N7
		 execute_on = 'initial timestep_end'
         block = 0
	[../]

 	[./N08]
 		type = ElementAverageValue
 		variable = N8
 		execute_on = 'initial timestep_end'
        block = 0
	[../]

 	[./N09]
 		type = ElementAverageValue
 		variable = N9
 		execute_on = 'initial timestep_end'
        block = 0
	[../]

[] #END Postprocessors

[Preconditioning]

	[./smp]
 		type = SMP
 		full = true
 		solve_type = pjfnk
	[../]

# 	[./FDP_jfnk]
# 		type = FDP
#  		full = true
# 		solve_type = 'PJFNK'
# 	[../]

[] #END Preconditioning

[Executioner]

    type = Transient
	scheme = implicit-euler    #use: 'implicit-euler' or 'bdf2'
    automatic_scaling = false

    # NOTE: Add arg -ksp_view to get info on methods used at linear steps
    petsc_options = '-snes_converged_reason

                      -ksp_gmres_modifiedgramschmidt
                      -ksp_ksp_gmres_modifiedgramschmidt'

    # NOTE: The sub_pc_type arg not used if pc_type is ksp,
    #       Instead, set the ksp_ksp_type to the pc method
    #       you want. Then, also set the ksp_pc_type to be
    #       the terminal preconditioner.
    #
    # Good terminal precon options: lu, ilu, asm, gasm, pbjacobi
    #                               bjacobi, redundant, telescope
    #
    # NOTE: -ksp_pc_factor_mat_solver_type == (mumps or superlu_dist)
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
                          -ksp_pc_type

                          -ksp_gmres_restart
                          -ksp_ksp_gmres_restart

                          -ksp_max_it
                          -ksp_ksp_max_it'

    ### NOTE:
    #   -mat_mumps_cntl_1  = Relative Pivot Tolerance (accepts column entry as pivot if value >= Tolerance)
    #   -mat_mumps_cntl_3  = Absolute Pivot Tolerance
    #   -mat_mumps_icntl_23 = Max Factorization Memory for Pivoting (MB)

    ## NOTE: May be best to just use lu as pc_type instead of ksp
    petsc_options_value = 'fgmres
                           bjacobi

                           ilu

                           50

                           NONZERO
                           NONZERO
                           NONZERO

                           10

                           1E-8
                           1E-8

                           fgmres
                           ilu

                           30
                           30

                           30
                           30'

    #NOTE: turning off line search can help converge for high Renolds number
    line_search = none
    nl_rel_tol = 1e-8
    nl_abs_tol = 1e-8
    nl_rel_step_tol = 1e-8
    nl_abs_step_tol = 1e-8
    nl_max_its = 50
    l_tol = 1e-6
    l_max_its = 30

    start_time = 0.0
	end_time = 864000.0
    dtmax = 3600.0

    [./TimeStepper]
#		type = SolutionTimeAdaptiveDT
		type = ConstantDT
        dt = 360.0
    [../]

[] #END Executioner

[Adaptivity]
#  marker = error_frac
#  steps = 2
#  [./Indicators]
#    [./jump_indicator]
#      type = ValueJumpIndicator
#      variable = N9
#    [../]
#  [../]
#  [./Markers]
#    [./error_frac]
#      type = ErrorFractionMarker
#      indicator = jump_indicator
#      refine = 0.7
#      coarsen = 0.3
#    [../]
#  [../]
[] #END Adaptivity

[Outputs]

    exodus = true
    csv = true
    print_linear_residuals = true
    interval = 1

[] #END Outputs
