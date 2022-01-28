[GlobalParams]

    diameters = '2.00e-7 2.60e-7 3.38e-7 4.39e-7 5.71e-7 7.43e-7 9.65e-7 1.25e-6 1.63e-6 2.12e-6 2.76e-6 3.58e-6 4.66e-6 6.06e-6 7.87e-6 1.02e-5 1.33e-5 1.73e-5 2.25e-5 2.92e-5'

 	packing_density = '0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75'

 	fractal_dimensions = '3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0'

 	breakup_constant = 1.0e-5

    dissipation = 0.3

    energy_dissipation = 0.3

    efficiency = 1
    frequency = 2000

[] #END GlobalParams

[Problem]

[] #END Problem

[Mesh]


    [gen]
    	type = GeneratedMeshGenerator
    	dim = 3
		nx = 12
		ny = 12
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
        initial_condition = 0.1e-15
    [../]

 	[./N1]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
        initial_condition = 0.1e-15
 	[../]

 	[./N2]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
        initial_condition = 0.1e-15
 	[../]

 	[./N3]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
        initial_condition = 0.1e-15
 	[../]

    [./N4]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
        initial_condition = 0.1e-15
 	[../]

 	[./N5]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
        initial_condition = 0.1e-15
 	[../]

 	[./N6]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
        initial_condition = 0.1e-15
 	[../]

 	[./N7]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
        initial_condition = 1.0e-15
 	[../]

    [./N8]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
        initial_condition = 2.0e-15
 	[../]

    [./N9]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
        initial_condition = 4.0e-15
 	[../]

	[./N10]
        order = CONSTANT
        family = MONOMIAL
        block = 0
        initial_condition = 8.0e-15
    [../]

 	[./N11]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
        initial_condition = 10.0e-15
 	[../]

 	[./N12]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
        initial_condition = 8.0e-15
 	[../]

 	[./N13]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
        initial_condition = 4.0e-15
 	[../]

    [./N14]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
        initial_condition = 2.0e-15
 	[../]

    [./N15]
        order = CONSTANT
        family = MONOMIAL
        block = 0
        initial_condition = 1.0e-15
    [../]

 	[./N16]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
        initial_condition = 0.8e-15
 	[../]

 	[./N17]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
        initial_condition = 0.4e-15
 	[../]

 	[./N18]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
        initial_condition = 0.2e-15
 	[../]

    [./N19]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
        initial_condition = 0.0
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

	[./N10d]
        order = CONSTANT
        family = MONOMIAL
        initial_condition = 0.0
        block = 1
    [../]

 	[./N11d]
 		order = CONSTANT
 		family = MONOMIAL
        initial_condition = 0.0
        block = 1
 	[../]

 	[./N12d]
 		order = CONSTANT
 		family = MONOMIAL
        initial_condition = 0.0
        block = 1
 	[../]

 	[./N13d]
 		order = CONSTANT
 		family = MONOMIAL
        initial_condition = 0.0
        block = 1
 	[../]

    [./N14d]
 		order = CONSTANT
 		family = MONOMIAL
        initial_condition = 0.0
        block = 1
 	[../]

    [./N15d]
        order = CONSTANT
        family = MONOMIAL
        initial_condition = 0.0
        block = 1
    [../]

 	[./N16d]
 		order = CONSTANT
 		family = MONOMIAL
        initial_condition = 0.0
        block = 1
 	[../]

 	[./N17d]
 		order = CONSTANT
 		family = MONOMIAL
        initial_condition = 0.0
        block = 1
 	[../]

 	[./N18d]
 		order = CONSTANT
 		family = MONOMIAL
        initial_condition = 0.0
        block = 1
 	[../]

    [./N19d]
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

	[./vp10x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

	[./vp10y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

	[./vp10z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

	[./vp11x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

	[./vp11y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

	[./vp11z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

	[./vp12x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

	[./vp12y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

	[./vp12z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

 	[./vp13x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
        block = 0
	[../]

	[./vp13y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
        block = 0
	[../]

	[./vp13z]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
        block = 0
	[../]

 	[./vp14x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
        block = 0
	[../]

	[./vp14y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
        block = 0
	[../]

	[./vp14z]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
        block = 0
	[../]

	[./vp15x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

	[./vp15y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

	[./vp15z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

	[./vp16x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

	[./vp16y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

	[./vp16z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

	[./vp17x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

	[./vp17y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

	[./vp17z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]

 	[./vp18x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
        block = 0
	[../]

	[./vp18y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
        block = 0
	[../]

	[./vp18z]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
        block = 0
	[../]

 	[./vp19x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
        block = 0
	[../]

	[./vp19y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
        block = 0
	[../]

	[./vp19z]
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
        type = ConstMonoPB
        variable = N0
        main_variable = N0
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
    [../]

    [./N0_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N0
 		main_variable = N0
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
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
        type = ConstMonoPB
        variable = N1
        main_variable = N1
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
    [../]

    [./N1_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N1
 		main_variable = N1
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
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
        type = ConstMonoPB
        variable = N2
        main_variable = N2
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
    [../]

    [./N2_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N2
 		main_variable = N2
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
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
        type = ConstMonoPB
        variable = N3
        main_variable = N3
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
    [../]

    [./N3_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N3
 		main_variable = N3
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
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
        type = ConstMonoPB
        variable = N4
        main_variable = N4
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
    [../]

    [./N4_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N4
 		main_variable = N4
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
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
        type = ConstMonoPB
        variable = N5
        main_variable = N5
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
    [../]

    [./N5_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N5
 		main_variable = N5
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
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
        type = ConstMonoPB
        variable = N6
        main_variable = N6
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
    [../]

    [./N6_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N6
 		main_variable = N6
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
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
        type = ConstMonoPB
        variable = N7
        main_variable = N7
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
    [../]

    [./N7_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N7
 		main_variable = N7
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
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
        type = ConstMonoPB
        variable = N8
        main_variable = N8
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
    [../]

    [./N8_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N8
 		main_variable = N8
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
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
        type = ConstMonoPB
        variable = N9
        main_variable = N9
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
    [../]

    [./N9_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N9
 		main_variable = N9
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]

    [./N10_dot]
        type = CoefTimeDerivative
        variable = N10
        Coefficient = 1.0
        block = 0
    [../]

    [./N10_gadv]
        type = GConcentrationAdvection
        variable = N10
		ux = vp10x
		uy = vp10y
		uz = vp10z
        block = 0
    [../]

    [./N10_gdiff]
        type = GAnisotropicDiffusion
        variable = N10
        block = 0
    [../]

    [./N10_MPB_Agg]
        type = ConstMonoPB
        variable = N10
        main_variable = N10
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
    [../]

    [./N10_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N10
 		main_variable = N10
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]

 	[./N11_dot]
 		type = CoefTimeDerivative
 		variable = N11
 		Coefficient = 1.0
        block = 0
 	[../]

    [./N11_gadv]
        type = GConcentrationAdvection
        variable = N11
		ux = vp11x
		uy = vp11y
		uz = vp11z
        block = 0
    [../]

    [./N11_gdiff]
        type = GAnisotropicDiffusion
        variable = N11
        block = 0
    [../]

    [./N11_MPB_Agg]
        type = ConstMonoPB
        variable = N11
        main_variable = N11
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
    [../]

    [./N11_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N11
 		main_variable = N11
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]

 	[./N12_dot]
 		type = CoefTimeDerivative
 		variable = N12
 		Coefficient = 1.0
        block = 0
 	[../]

    [./N12_gadv]
        type = GConcentrationAdvection
        variable = N12
		ux = vp12x
		uy = vp12y
		uz = vp12z
        block = 0
    [../]

    [./N12_gdiff]
        type = GAnisotropicDiffusion
        variable = N12
        block = 0
    [../]

    [./N12_MPB_Agg]
        type = ConstMonoPB
        variable = N12
        main_variable = N12
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
    [../]

    [./N12_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N12
 		main_variable = N12
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]

 	[./N13_dot]
 		type = CoefTimeDerivative
 		variable = N13
 		Coefficient = 1.0
        block = 0
 	[../]

    [./N13_gadv]
        type = GConcentrationAdvection
        variable = N13
		ux = vp13x
		uy = vp13y
		uz = vp13z
        block = 0
    [../]

    [./N13_gdiff]
        type = GAnisotropicDiffusion
        variable = N13
        block = 0
    [../]

    [./N13_MPB_Agg]
        type = ConstMonoPB
        variable = N13
        main_variable = N13
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
    [../]

    [./N13_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N13
 		main_variable = N13
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]

 	[./N14_dot]
 		type = CoefTimeDerivative
 		variable = N14
 		Coefficient = 1.0
        block = 0
 	[../]

    [./N14_gadv]
        type = GConcentrationAdvection
        variable = N14
		ux = vp14x
		uy = vp14y
		uz = vp14z
        block = 0
    [../]

    [./N14_gdiff]
        type = GAnisotropicDiffusion
        variable = N14
        block = 0
    [../]

    [./N14_MPB_Agg]
        type = ConstMonoPB
        variable = N14
        main_variable = N14
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
    [../]

    [./N14_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N14
 		main_variable = N14
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]

    [./N15_dot]
        type = CoefTimeDerivative
        variable = N15
        Coefficient = 1.0
        block = 0
    [../]

    [./N15_gadv]
        type = GConcentrationAdvection
        variable = N15
		ux = vp15x
		uy = vp15y
		uz = vp15z
        block = 0
    [../]

    [./N15_gdiff]
        type = GAnisotropicDiffusion
        variable = N15
        block = 0
    [../]

    [./N15_MPB_Agg]
        type = ConstMonoPB
        variable = N15
        main_variable = N15
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
    [../]

    [./N15_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N15
 		main_variable = N15
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]

 	[./N16_dot]
 		type = CoefTimeDerivative
 		variable = N16
 		Coefficient = 1.0
        block = 0
 	[../]

    [./N16_gadv]
        type = GConcentrationAdvection
        variable = N16
		ux = vp16x
		uy = vp16y
		uz = vp16z
        block = 0
    [../]

    [./N16_gdiff]
        type = GAnisotropicDiffusion
        variable = N16
        block = 0
    [../]

    [./N16_MPB_Agg]
        type = ConstMonoPB
        variable = N16
        main_variable = N16
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
    [../]

    [./N16_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N16
 		main_variable = N16
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]

 	[./N17_dot]
 		type = CoefTimeDerivative
 		variable = N17
 		Coefficient = 1.0
        block = 0
 	[../]

    [./N17_gadv]
        type = GConcentrationAdvection
        variable = N17
		ux = vp17x
		uy = vp17y
		uz = vp17z
        block = 0
    [../]

    [./N17_gdiff]
        type = GAnisotropicDiffusion
        variable = N17
        block = 0
    [../]

    [./N17_MPB_Agg]
        type = ConstMonoPB
        variable = N17
        main_variable = N17
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
    [../]

    [./N17_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N17
 		main_variable = N17
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]

 	[./N18_dot]
 		type = CoefTimeDerivative
 		variable = N18
 		Coefficient = 1.0
        block = 0
 	[../]

    [./N18_gadv]
        type = GConcentrationAdvection
        variable = N18
		ux = vp18x
		uy = vp18y
		uz = vp18z
        block = 0
    [../]

    [./N18_gdiff]
        type = GAnisotropicDiffusion
        variable = N18
        block = 0
    [../]

    [./N18_MPB_Agg]
        type = ConstMonoPB
        variable = N18
        main_variable = N18
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
    [../]

    [./N18_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N18
 		main_variable = N18
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]

 	[./N19_dot]
 		type = CoefTimeDerivative
 		variable = N19
 		Coefficient = 1.0
        block = 0
 	[../]

    [./N19_gadv]
        type = GConcentrationAdvection
        variable = N19
		ux = vp19x
		uy = vp19y
		uz = vp19z
        block = 0
    [../]

    [./N19_gdiff]
        type = GAnisotropicDiffusion
        variable = N19
        block = 0
    [../]

    [./N19_MPB_Agg]
        type = ConstMonoPB
        variable = N19
        main_variable = N19
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
    [../]

    [./N19_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N19
 		main_variable = N19
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
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

    [./N10d_dot]
        type = CoefTimeDerivative
        variable = N10d
        Coefficient = 1.0
        block = 1
    [../]

 	[./N11d_dot]
 		type = CoefTimeDerivative
 		variable = N11d
 		Coefficient = 1.0
        block = 1
 	[../]

 	[./N12d_dot]
 		type = CoefTimeDerivative
 		variable = N12d
 		Coefficient = 1.0
        block = 1
 	[../]

 	[./N13d_dot]
 		type = CoefTimeDerivative
 		variable = N13d
 		Coefficient = 1.0
        block = 1
 	[../]

 	[./N14d_dot]
 		type = CoefTimeDerivative
 		variable = N14d
 		Coefficient = 1.0
        block = 1
 	[../]

    [./N15d_dot]
        type = CoefTimeDerivative
        variable = N15d
        Coefficient = 1.0
        block = 1
    [../]

 	[./N16d_dot]
 		type = CoefTimeDerivative
 		variable = N16d
 		Coefficient = 1.0
        block = 1
 	[../]

 	[./N17d_dot]
 		type = CoefTimeDerivative
 		variable = N17d
 		Coefficient = 1.0
        block = 1
 	[../]

 	[./N18d_dot]
 		type = CoefTimeDerivative
 		variable = N18d
 		Coefficient = 1.0
        block = 1
 	[../]

 	[./N19d_dot]
 		type = CoefTimeDerivative
 		variable = N19d
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

    [./N10_dgadv]
        type = DGConcentrationAdvection
        variable = N10
		ux = vp10x
		uy = vp10y
		uz = vp10z
        block = 0
    [../]

    [./N10_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N10
        block = 0
    [../]

    [./N11_dgadv]
        type = DGConcentrationAdvection
        variable = N11
		ux = vp11x
		uy = vp11y
		uz = vp11z
        block = 0
    [../]

    [./N11_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N11
        block = 0
    [../]

    [./N12_dgadv]
        type = DGConcentrationAdvection
        variable = N12
		ux = vp12x
		uy = vp12y
		uz = vp12z
        block = 0
    [../]

    [./N12_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N12
        block = 0
    [../]

    [./N13_dgadv]
        type = DGConcentrationAdvection
        variable = N13
		ux = vp13x
		uy = vp13y
		uz = vp13z
        block = 0
    [../]

    [./N13_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N13
        block = 0
    [../]

    [./N14_dgadv]
        type = DGConcentrationAdvection
        variable = N14
		ux = vp14x
		uy = vp14y
		uz = vp14z
        block = 0
    [../]

    [./N14_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N14
        block = 0
    [../]

    [./N15_dgadv]
        type = DGConcentrationAdvection
        variable = N15
		ux = vp15x
		uy = vp15y
		uz = vp15z
        block = 0
    [../]

    [./N15_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N15
        block = 0
    [../]

    [./N16_dgadv]
        type = DGConcentrationAdvection
        variable = N16
		ux = vp16x
		uy = vp16y
		uz = vp16z
        block = 0
    [../]

    [./N16_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N16
        block = 0
    [../]

    [./N17_dgadv]
        type = DGConcentrationAdvection
        variable = N17
		ux = vp17x
		uy = vp17y
		uz = vp17z
        block = 0
    [../]

    [./N17_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N17
        block = 0
    [../]

    [./N18_dgadv]
        type = DGConcentrationAdvection
        variable = N18
		ux = vp18x
		uy = vp18y
		uz = vp18z
        block = 0
    [../]

    [./N18_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N18
        block = 0
    [../]

    [./N19_dgadv]
        type = DGConcentrationAdvection
        variable = N19
		ux = vp19x
		uy = vp19y
		uz = vp19z
        block = 0
    [../]

    [./N19_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N19
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

	[./N10_interface_diffusion]
		type = InterfacialAnisotropicDiffusion
		variable = N10
        neighbor_var = N10d
		boundary = master_interface
	[../]

	[./N10_interface_advection]
		type = InterfaceAdvection
		variable = N10
        neighbor_var = N10d
		boundary = master_interface
		ux = vp10x
		uy = vp10y
		uz = vp10z
	[../]

	[./N11_interface_diffusion]
		type = InterfacialAnisotropicDiffusion
		variable = N11
        neighbor_var = N11d
		boundary = master_interface
	[../]

	[./N11_interface_advection]
		type = InterfaceAdvection
		variable = N11
        neighbor_var = N11d
		boundary = master_interface
		ux = vp11x
		uy = vp11y
		uz = vp11z
	[../]

	[./N12_interface_diffusion]
		type = InterfacialAnisotropicDiffusion
		variable = N12
        neighbor_var = N12d
		boundary = master_interface
	[../]

	[./N12_interface_advection]
		type = InterfaceAdvection
		variable = N12
        neighbor_var = N12d
		boundary = master_interface
		ux = vp12x
		uy = vp12y
		uz = vp12z
	[../]

	[./N13_interface_diffusion]
		type = InterfacialAnisotropicDiffusion
		variable = N13
        neighbor_var = N13d
		boundary = master_interface
	[../]

	[./N13_interface_advection]
		type = InterfaceAdvection
		variable = N13
        neighbor_var = N13d
		boundary = master_interface
		ux = vp13x
		uy = vp13y
		uz = vp13z
	[../]

	[./N14_interface_diffusion]
		type = InterfacialAnisotropicDiffusion
		variable = N14
        neighbor_var = N14d
		boundary = master_interface
	[../]

	[./N14_interface_advection]
		type = InterfaceAdvection
		variable = N14
        neighbor_var = N14d
		boundary = master_interface
		ux = vp14x
		uy = vp14y
		uz = vp14z
	[../]

	[./N15_interface_diffusion]
		type = InterfacialAnisotropicDiffusion
		variable = N15
        neighbor_var = N15d
		boundary = master_interface
	[../]

	[./N15_interface_advection]
		type = InterfaceAdvection
		variable = N15
        neighbor_var = N15d
		boundary = master_interface
		ux = vp15x
		uy = vp15y
		uz = vp15z
	[../]

	[./N16_interface_diffusion]
		type = InterfacialAnisotropicDiffusion
		variable = N16
        neighbor_var = N16d
		boundary = master_interface
	[../]

	[./N16_interface_advection]
		type = InterfaceAdvection
		variable = N16
        neighbor_var = N16d
		boundary = master_interface
		ux = vp16x
		uy = vp16y
		uz = vp16z
	[../]

	[./N17_interface_diffusion]
		type = InterfacialAnisotropicDiffusion
		variable = N17
        neighbor_var = N17d
		boundary = master_interface
	[../]

	[./N17_interface_advection]
		type = InterfaceAdvection
		variable = N17
        neighbor_var = N17d
		boundary = master_interface
		ux = vp17x
		uy = vp17y
		uz = vp17z
	[../]

	[./N18_interface_diffusion]
		type = InterfacialAnisotropicDiffusion
		variable = N18
        neighbor_var = N18d
		boundary = master_interface
	[../]

	[./N18_interface_advection]
		type = InterfaceAdvection
		variable = N18
        neighbor_var = N18d
		boundary = master_interface
		ux = vp18x
		uy = vp18y
		uz = vp18z
	[../]

	[./N19_interface_diffusion]
		type = InterfacialAnisotropicDiffusion
		variable = N19
        neighbor_var = N19d
		boundary = master_interface
	[../]

	[./N19_interface_advection]
		type = InterfaceAdvection
		variable = N19
        neighbor_var = N19d
		boundary = master_interface
		ux = vp19x
		uy = vp19y
		uz = vp19z
	[../]

[] #END InterfaceKernels

[AuxKernels]

	[./Total_Volume]
		type = VolumeBalanceCheck
		variable = V_total
		coupled_vars = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
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

    [./part_vel_10x]
		type = Trajectory1stOrder
		variable = vp10x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp10x
		vary = vp10y
		varz = vp10z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.76e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_10y]
		type = Trajectory1stOrder
		variable = vp10y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp10x
		vary = vp10y
		varz = vp10z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.76e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_10z]
		type = Trajectory1stOrder
		variable = vp10z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp10x
		vary = vp10y
		varz = vp10z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.76e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_11x]
		type = Trajectory1stOrder
		variable = vp11x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp11x
		vary = vp11y
		varz = vp11z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 3.58e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_11y]
		type = Trajectory1stOrder
		variable = vp11y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp11x
		vary = vp11y
		varz = vp11z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 3.58e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_11z]
		type = Trajectory1stOrder
		variable = vp11z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp11x
		vary = vp11y
		varz = vp11z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 3.58e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_12x]
		type = Trajectory1stOrder
		variable = vp12x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp12x
		vary = vp12y
		varz = vp12z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 4.66e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_12y]
		type = Trajectory1stOrder
		variable = vp12y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp12x
		vary = vp12y
		varz = vp12z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 4.66e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_12z]
		type = Trajectory1stOrder
		variable = vp12z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp12x
		vary = vp12y
		varz = vp12z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 4.66e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_13x]
		type = Trajectory1stOrder
		variable = vp13x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp13x
		vary = vp13y
		varz = vp13z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 6.06e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_13y]
		type = Trajectory1stOrder
		variable = vp13y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp13x
		vary = vp13y
		varz = vp13z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 6.06e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_13z]
		type = Trajectory1stOrder
		variable = vp13z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp13x
		vary = vp13y
		varz = vp13z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 6.06e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_14x]
		type = Trajectory1stOrder
		variable = vp14x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp14x
		vary = vp14y
		varz = vp14z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 7.87e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_14y]
		type = Trajectory1stOrder
		variable = vp14y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp14x
		vary = vp14y
		varz = vp14z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 7.87e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_14z]
		type = Trajectory1stOrder
		variable = vp14z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp14x
		vary = vp14y
		varz = vp14z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 7.87e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

    [./part_vel_15x]
		type = Trajectory1stOrder
		variable = vp15x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp15x
		vary = vp15y
		varz = vp15z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.02e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_15y]
		type = Trajectory1stOrder
		variable = vp15y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp15x
		vary = vp15y
		varz = vp15z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.02e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_15z]
		type = Trajectory1stOrder
		variable = vp15z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp15x
		vary = vp15y
		varz = vp15z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.02e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_16x]
		type = Trajectory1stOrder
		variable = vp16x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp16x
		vary = vp16y
		varz = vp16z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.33e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_16y]
		type = Trajectory1stOrder
		variable = vp16y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp16x
		vary = vp16y
		varz = vp16z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.33e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_16z]
		type = Trajectory1stOrder
		variable = vp16z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp16x
		vary = vp16y
		varz = vp16z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.33e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_17x]
		type = Trajectory1stOrder
		variable = vp17x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp17x
		vary = vp17y
		varz = vp17z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.73e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_17y]
		type = Trajectory1stOrder
		variable = vp17y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp17x
		vary = vp17y
		varz = vp17z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.73e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_17z]
		type = Trajectory1stOrder
		variable = vp17z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp17x
		vary = vp17y
		varz = vp17z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.73e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_18x]
		type = Trajectory1stOrder
		variable = vp18x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp18x
		vary = vp18y
		varz = vp18z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.25e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_18y]
		type = Trajectory1stOrder
		variable = vp18y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp18x
		vary = vp18y
		varz = vp18z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.25e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_18z]
		type = Trajectory1stOrder
		variable = vp18z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp18x
		vary = vp18y
		varz = vp18z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.25e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_19x]
		type = Trajectory1stOrder
		variable = vp19x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp19x
		vary = vp19y
		varz = vp19z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.92e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_19y]
		type = Trajectory1stOrder
		variable = vp19y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp19x
		vary = vp19y
		varz = vp19z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.92e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_19z]
		type = Trajectory1stOrder
		variable = vp19z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp19x
		vary = vp19y
		varz = vp19z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.92e-5
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

    [./N10_Flux_in_L]
        type = DGConcentrationFluxBC
        variable = N10
        boundary = 'left_to_0 right_to_0 top_to_0 bottom_to_0 front_to_0'
		u_input = 0.0
		ux = vp10x
		uy = vp10y
		uz = vp10z
    [../]

	[./N11_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N11
		boundary = 'left_to_0 right_to_0 top_to_0 bottom_to_0 front_to_0'
		u_input = 0.0
		ux = vp11x
		uy = vp11y
		uz = vp11z
	[../]

	[./N12_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N12
		boundary = 'left_to_0 right_to_0 top_to_0 bottom_to_0 front_to_0'
		u_input = 0.0
		ux = vp12x
		uy = vp12y
		uz = vp12z
	[../]

    [./N13_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N13
		boundary = 'left_to_0 right_to_0 top_to_0 bottom_to_0 front_to_0'
		u_input = 0.0
		ux = vp13x
		uy = vp13y
		uz = vp13z
	[../]

	[./N14_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N14
		boundary = 'left_to_0 right_to_0 top_to_0 bottom_to_0 front_to_0'
		u_input = 0.0
		ux = vp14x
		uy = vp14y
		uz = vp14z
	[../]

    [./N15_Flux_in_L]
        type = DGConcentrationFluxBC
        variable = N15
        boundary = 'left_to_0 right_to_0 top_to_0 bottom_to_0 front_to_0'
		u_input = 0.0
		ux = vp15x
		uy = vp15y
		uz = vp15z
    [../]

	[./N16_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N16
		boundary = 'left_to_0 right_to_0 top_to_0 bottom_to_0 front_to_0'
		u_input = 0.0
		ux = vp16x
		uy = vp16y
		uz = vp16z
	[../]

	[./N17_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N17
		boundary = 'left_to_0 right_to_0 top_to_0 bottom_to_0 front_to_0'
		u_input = 0.0
		ux = vp17x
		uy = vp17y
		uz = vp17z
	[../]

    [./N18_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N18
		boundary = 'left_to_0 right_to_0 top_to_0 bottom_to_0 front_to_0'
		u_input = 0.0
		ux = vp18x
		uy = vp18y
		uz = vp18z
	[../]

	[./N19_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N19
		boundary = 'left_to_0 right_to_0 top_to_0 bottom_to_0 front_to_0'
		u_input = 0.00000001
		ux = vp19x
		uy = .1
		uz = vp19z
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

    [./N10_floor]
		type = ElementAverageValue
		variable = N10d
		execute_on = 'initial timestep_end'
        block = 1
	[../]

    [./N11_floor]
		type = ElementAverageValue
		variable = N11d
		execute_on = 'initial timestep_end'
        block = 1
	[../]

    [./N12_floor]
		type = ElementAverageValue
		variable = N12d
		execute_on = 'initial timestep_end'
        block = 1
	[../]

    [./N13_floor]
		type = ElementAverageValue
		variable = N13d
		execute_on = 'initial timestep_end'
        block = 1
	[../]

    [./N14_floor]
		type = ElementAverageValue
		variable = N14d
		execute_on = 'initial timestep_end'
        block = 1
	[../]

    [./N15_floor]
		type = ElementAverageValue
		variable = N15d
		execute_on = 'initial timestep_end'
        block = 1
	[../]

    [./N16_floor]
		type = ElementAverageValue
		variable = N16d
		execute_on = 'initial timestep_end'
        block = 1
	[../]

    [./N17_floor]
		type = ElementAverageValue
		variable = N17d
		execute_on = 'initial timestep_end'
        block = 1
	[../]

    [./N18_floor]
		type = ElementAverageValue
		variable = N18d
		execute_on = 'initial timestep_end'
        block = 1
	[../]

    [./N19_floor]
		type = ElementAverageValue
		variable = N19d
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

	[./N10]
		type = ElementAverageValue
		variable = N10
		execute_on = 'initial timestep_end'
        block = 0
	[../]

	[./N11]
		type = ElementAverageValue
		variable = N11
		execute_on = 'initial timestep_end'
        block = 0
	[../]

 	[./N12]
 		type = ElementAverageValue
 		variable = N12
		 execute_on = 'initial timestep_end'
         block = 0
	[../]

 	[./N13]
 		type = ElementAverageValue
 		variable = N13
 		execute_on = 'initial timestep_end'
        block = 0
	[../]

 	[./N14]
 		type = ElementAverageValue
 		variable = N14
 		execute_on = 'initial timestep_end'
        block = 0
	[../]

	[./N15]
		type = ElementAverageValue
		variable = N15
		execute_on = 'initial timestep_end'
        block = 0
	[../]

	[./N16]
		type = ElementAverageValue
		variable = N16
		execute_on = 'initial timestep_end'
        block = 0
	[../]

 	[./N17]
 		type = ElementAverageValue
 		variable = N17
		 execute_on = 'initial timestep_end'
         block = 0
	[../]

 	[./N18]
 		type = ElementAverageValue
 		variable = N18
 		execute_on = 'initial timestep_end'
        block = 0
	[../]

 	[./N19]
 		type = ElementAverageValue
 		variable = N19
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
  marker = error_frac
  steps = 2
  [./Indicators]
    [./jump_indicator]
      type = ValueJumpIndicator
      variable = N19
    [../]
  [../]
  [./Markers]
    [./error_frac]
      type = ErrorFractionMarker
      indicator = jump_indicator
      refine = 0.7
      coarsen = 0.3
    [../]
  [../]
[] #END Adaptivity

[Outputs]

    exodus = true
    csv = true
    print_linear_residuals = true
    interval = 1

[] #END Outputs
