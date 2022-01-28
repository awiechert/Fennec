[GlobalParams]

    diameters = '2.00e-7 2.60e-7 3.38e-7 4.39e-7 5.71e-7 7.43e-7 9.65e-7 1.25e-6 1.63e-6 2.12e-6 2.76e-6 3.58e-6 4.66e-6 6.06e-6 7.87e-6 1.02e-5 1.33e-5 1.73e-5 2.25e-5 2.92e-5'
 
 	packing_density = '0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75'
 
 	fractal_dimensions = '3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0'
 
 	breakup_constant = 1.0e-5
 
    energy_dissipation = 0.3

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
 	xmax = 10000.0
 	ymin = 0.0
 	ymax = 10000.0
	zmin = 0.0
	zmax = 10000.0

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

	[./N10]
        order = CONSTANT
        family = MONOMIAL
        block = 0
    [../]
 
 	[./N11]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
 	[../]
 
 	[./N12]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
 	[../]
 
 	[./N13]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
 	[../]
 
    [./N14]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
 	[../]
    
    [./N15]
        order = CONSTANT
        family = MONOMIAL
        block = 0
    [../]
 
 	[./N16]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
 	[../]
 
 	[./N17]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
 	[../]
 
 	[./N18]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
 	[../]
 
    [./N19]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
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
        block = 0
	[../]
 
	[./wy]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
	[../]
 
	[./wz]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
        block = 0
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
        block = 0
	[../]
 
	[./air_visc]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 1.802e-5 #kg/m/s
        block = 0
	[../]
 
 	[./air_ions]
 		order = CONSTANT
 		family = MONOMIAL
        block = 0
	[../]
 
    [./air_temp]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 298 #K
        block = 0
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

	[./N10_IC]
 		type = CARDINAL_CloudIC
        variable = N10
        x_center = 5000
        y_center = 5000
        local_size_index = 10
        cardinal_object = cardinal
        block = 0
    [../]
 
 	[./N11_IC]
 		type = CARDINAL_CloudIC
 		variable = N11
        x_center = 5000
        y_center = 5000
 		local_size_index = 11
 		cardinal_object = cardinal
        block = 0
 	[../]
 
 	[./N12_IC]
 		type = CARDINAL_CloudIC
 		variable = N12
        x_center = 5000
        y_center = 5000
 		local_size_index = 12
 		cardinal_object = cardinal
        block = 0
 	[../]
 
 	[./N13_IC]
 		type = CARDINAL_CloudIC
 		variable = N13
        x_center = 5000
        y_center = 5000
 		local_size_index = 13
 		cardinal_object = cardinal
        block = 0
 	[../]
 
 	[./N14_IC]
 		type = CARDINAL_CloudIC
 		variable = N14
        x_center = 5000
        y_center = 5000
 		local_size_index = 14
 		cardinal_object = cardinal
        block = 0
 	[../]

	[./N15_IC]
 		type = CARDINAL_CloudIC
        variable = N15
        x_center = 5000
        y_center = 5000
        local_size_index = 15
        cardinal_object = cardinal
        block = 0
    [../]
 
 	[./N16_IC]
 		type = CARDINAL_CloudIC
 		variable = N16
        x_center = 5000
        y_center = 5000
 		local_size_index = 16
 		cardinal_object = cardinal
        block = 0
 	[../]
 
 	[./N17_IC]
 		type = CARDINAL_CloudIC
 		variable = N17
        x_center = 5000
        y_center = 5000
 		local_size_index = 17
 		cardinal_object = cardinal
        block = 0
 	[../]
 
 	[./N18_IC]
 		type = CARDINAL_CloudIC
 		variable = N18
        x_center = 5000
        y_center = 5000
 		local_size_index = 18
 		cardinal_object = cardinal
        block = 0
 	[../]
 
 	[./N19_IC]
 		type = CARDINAL_CloudIC
 		variable = N19
        x_center = 5000
        y_center = 5000
 		local_size_index = 19
 		cardinal_object = cardinal
        block = 0
 	[../]

[] #END ICs

[Kernels]

    [./N0_dot]
        type = ADTimeDerivative
        variable = N0
        block = 0
    [../]
 
    [./N0_gadv]
        type = ADGAdvection
        variable = N0
		ux = vp0x
		uy = vp0y
		uz = vp0z
        block = 0
    [../]

    [./N0_gdiff]
        type = ADGAnisotropicDiffusion
        variable = N0
        block = 0
    [../]
 
    [./N0_MPB_Break]
 		type = ADShearMultiFragLinearMPB
 		variable = N0
 		main_variable = N0
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]
 
 	[./N1_dot]
 		type = ADTimeDerivative
 		variable = N1
        block = 0
 	[../]
 
    [./N1_gadv]
        type = ADGAdvection
        variable = N1
		ux = vp1x
		uy = vp1y
		uz = vp1z
        block = 0
    [../]

    [./N1_gdiff]
        type = ADGAnisotropicDiffusion
        variable = N1
        block = 0
    [../]
 
    [./N1_MPB_Break]
 		type = ADShearMultiFragLinearMPB
 		variable = N1
 		main_variable = N1
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]
 
 	[./N2_dot]
 		type = ADTimeDerivative
 		variable = N2
        block = 0
 	[../]
 
    [./N2_gadv]
        type = ADGAdvection
        variable = N2
		ux = vp2x
		uy = vp2y
		uz = vp2z
        block = 0
    [../]

    [./N2_gdiff]
        type = ADGAnisotropicDiffusion
        variable = N2
        block = 0
    [../]
 
    [./N2_MPB_Break]
 		type = ADShearMultiFragLinearMPB
 		variable = N2
 		main_variable = N2
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]
 
 	[./N3_dot]
 		type = ADTimeDerivative
 		variable = N3
        block = 0
 	[../]
 
    [./N3_gadv]
        type = ADGAdvection
        variable = N3
		ux = vp3x
		uy = vp3y
		uz = vp3z
        block = 0
    [../]

    [./N3_gdiff]
        type = ADGAnisotropicDiffusion
        variable = N3
        block = 0
    [../]
 
    [./N3_MPB_Break]
 		type = ADShearMultiFragLinearMPB
 		variable = N3
 		main_variable = N3
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]
 
 	[./N4_dot]
 		type = ADTimeDerivative
 		variable = N4
        block = 0
 	[../]
 
    [./N4_gadv]
        type = ADGAdvection
        variable = N4
		ux = vp4x
		uy = vp4y
		uz = vp4z
        block = 0
    [../]

    [./N4_gdiff]
        type = ADGAnisotropicDiffusion
        variable = N4
        block = 0
    [../]
 
    [./N4_MPB_Break]
 		type = ADShearMultiFragLinearMPB
 		variable = N4
 		main_variable = N4
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]

    [./N5_dot]
        type = ADTimeDerivative
        variable = N5
        block = 0
    [../]
 
    [./N5_gadv]
        type = ADGAdvection
        variable = N5
		ux = vp5x
		uy = vp5y
		uz = vp5z
        block = 0
    [../]

    [./N5_gdiff]
        type = ADGAnisotropicDiffusion
        variable = N5
        block = 0
    [../]
 
    [./N5_MPB_Break]
 		type = ADShearMultiFragLinearMPB
 		variable = N5
 		main_variable = N5
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]
 
 	[./N6_dot]
 		type = ADTimeDerivative
 		variable = N6
        block = 0
 	[../]
 
    [./N6_gadv]
        type = ADGAdvection
        variable = N6
		ux = vp6x
		uy = vp6y
		uz = vp6z
        block = 0
    [../]

    [./N6_gdiff]
        type = ADGAnisotropicDiffusion
        variable = N6
        block = 0
    [../]
 
    [./N6_MPB_Break]
 		type = ADShearMultiFragLinearMPB
 		variable = N6
 		main_variable = N6
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]
 
 	[./N7_dot]
 		type = ADTimeDerivative
 		variable = N7
        block = 0
 	[../]
 
    [./N7_gadv]
        type = ADGAdvection
        variable = N7
		ux = vp7x
		uy = vp7y
		uz = vp7z
        block = 0
    [../]

    [./N7_gdiff]
        type = ADGAnisotropicDiffusion
        variable = N7
        block = 0
    [../]
 
    [./N7_MPB_Break]
 		type = ADShearMultiFragLinearMPB
 		variable = N7
 		main_variable = N7
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]
 
 	[./N8_dot]
 		type = ADTimeDerivative
 		variable = N8
        block = 0
 	[../]
 
    [./N8_gadv]
        type = ADGAdvection
        variable = N8
		ux = vp8x
		uy = vp8y
		uz = vp8z
        block = 0
    [../]

    [./N8_gdiff]
        type = ADGAnisotropicDiffusion
        variable = N8
        block = 0
    [../]
 
    [./N8_MPB_Break]
 		type = ADShearMultiFragLinearMPB
 		variable = N8
 		main_variable = N8
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]
 
 	[./N9_dot]
 		type = ADTimeDerivative
 		variable = N9
        block = 0
 	[../]
 
    [./N9_gadv]
        type = ADGAdvection
        variable = N9
		ux = vp9x
		uy = vp9y
		uz = vp9z
        block = 0
    [../]

    [./N9_gdiff]
        type = ADGAnisotropicDiffusion
        variable = N9
        block = 0
    [../]
 
    [./N9_MPB_Break]
 		type = ADShearMultiFragLinearMPB
 		variable = N9
 		main_variable = N9
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]
 
    [./N10_dot]
        type = ADTimeDerivative
        variable = N10
        block = 0
    [../]
 
    [./N10_gadv]
        type = ADGAdvection
        variable = N10
		ux = vp10x
		uy = vp10y
		uz = vp10z
        block = 0
    [../]

    [./N10_gdiff]
        type = ADGAnisotropicDiffusion
        variable = N10
        block = 0
    [../]
 
    [./N10_MPB_Break]
 		type = ADShearMultiFragLinearMPB
 		variable = N10
 		main_variable = N10
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]
 
 	[./N11_dot]
 		type = ADTimeDerivative
 		variable = N11
        block = 0
 	[../]
 
    [./N11_gadv]
        type = ADGAdvection
        variable = N11
		ux = vp11x
		uy = vp11y
		uz = vp11z
        block = 0
    [../]

    [./N11_gdiff]
        type = ADGAnisotropicDiffusion
        variable = N11
        block = 0
    [../]
 
    [./N11_MPB_Break]
 		type = ADShearMultiFragLinearMPB
 		variable = N11
 		main_variable = N11
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]
 
 	[./N12_dot]
 		type = ADTimeDerivative
 		variable = N12
        block = 0
 	[../]
 
    [./N12_gadv]
        type = ADGAdvection
        variable = N12
		ux = vp12x
		uy = vp12y
		uz = vp12z
        block = 0
    [../]

    [./N12_gdiff]
        type = ADGAnisotropicDiffusion
        variable = N12
        block = 0
    [../]
 
    [./N12_MPB_Break]
 		type = ADShearMultiFragLinearMPB
 		variable = N12
 		main_variable = N12
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]
 
 	[./N13_dot]
 		type = ADTimeDerivative
 		variable = N13
        block = 0
 	[../]
 
    [./N13_gadv]
        type = ADGAdvection
        variable = N13
		ux = vp13x
		uy = vp13y
		uz = vp13z
        block = 0
    [../]

    [./N13_gdiff]
        type = ADGAnisotropicDiffusion
        variable = N13
        block = 0
    [../]
 
    [./N13_MPB_Break]
 		type = ADShearMultiFragLinearMPB
 		variable = N13
 		main_variable = N13
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]
 
 	[./N14_dot]
 		type = ADTimeDerivative
 		variable = N14
        block = 0
 	[../]
 
    [./N14_gadv]
        type = ADGAdvection
        variable = N14
		ux = vp14x
		uy = vp14y
		uz = vp14z
        block = 0
    [../]

    [./N14_gdiff]
        type = ADGAnisotropicDiffusion
        variable = N14
        block = 0
    [../]
 
    [./N14_MPB_Break]
 		type = ADShearMultiFragLinearMPB
 		variable = N14
 		main_variable = N14
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]

    [./N15_dot]
        type = ADTimeDerivative
        variable = N15
        block = 0
    [../]
 
    [./N15_gadv]
        type = ADGAdvection
        variable = N15
		ux = vp15x
		uy = vp15y
		uz = vp15z
        block = 0
    [../]

    [./N15_gdiff]
        type = ADGAnisotropicDiffusion
        variable = N15
        block = 0
    [../]
 
    [./N15_MPB_Break]
 		type = ADShearMultiFragLinearMPB
 		variable = N15
 		main_variable = N15
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]
 
 	[./N16_dot]
 		type = ADTimeDerivative
 		variable = N16
        block = 0
 	[../]
 
    [./N16_gadv]
        type = ADGAdvection
        variable = N16
		ux = vp16x
		uy = vp16y
		uz = vp16z
        block = 0
    [../]

    [./N16_gdiff]
        type = ADGAnisotropicDiffusion
        variable = N16
        block = 0
    [../]
 
    [./N16_MPB_Break]
 		type = ADShearMultiFragLinearMPB
 		variable = N16
 		main_variable = N16
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]
 
 	[./N17_dot]
 		type = ADTimeDerivative
 		variable = N17
        block = 0
 	[../]
 
    [./N17_gadv]
        type = ADGAdvection
        variable = N17
		ux = vp17x
		uy = vp17y
		uz = vp17z
        block = 0
    [../]

    [./N17_gdiff]
        type = ADGAnisotropicDiffusion
        variable = N17
        block = 0
    [../]
 
    [./N17_MPB_Break]
 		type = ADShearMultiFragLinearMPB
 		variable = N17
 		main_variable = N17
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]
 
 	[./N18_dot]
 		type = ADTimeDerivative
 		variable = N18
        block = 0
 	[../]
 
    [./N18_gadv]
        type = ADGAdvection
        variable = N18
		ux = vp18x
		uy = vp18y
		uz = vp18z
        block = 0
    [../]

    [./N18_gdiff]
        type = ADGAnisotropicDiffusion
        variable = N18
        block = 0
    [../]
 
    [./N18_MPB_Break]
 		type = ADShearMultiFragLinearMPB
 		variable = N18
 		main_variable = N18
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]
 
 	[./N19_dot]
 		type = ADTimeDerivative
 		variable = N19
        block = 0
 	[../]
 
    [./N19_gadv]
        type = ADGAdvection
        variable = N19
		ux = vp19x
		uy = vp19y
		uz = vp19z
        block = 0
    [../]

    [./N19_gdiff]
        type = ADGAnisotropicDiffusion
        variable = N19
        block = 0
    [../]
 
    [./N19_MPB_Break]
 		type = ADShearMultiFragLinearMPB
 		variable = N19
 		main_variable = N19
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        block = 0
	[../]

[] #END Kernels

[DGKernels]

    [./N0_dgadv]
        type = ADDGAdvection
        variable = N0
		ux = vp0x
		uy = vp0y
		uz = vp0z
        block = 0
    [../]

    [./N0_dgdiff]
        type = ADDGAnisotropicDiffusion
        variable = N0
        block = 0
    [../]
 
    [./N1_dgadv]
        type = ADDGAdvection
        variable = N1
		ux = vp1x
		uy = vp1y
		uz = vp1z
        block = 0
    [../]

    [./N1_dgdiff]
        type = ADDGAnisotropicDiffusion
        variable = N1
        block = 0
    [../]

    [./N2_dgadv]
        type = ADDGAdvection
        variable = N2
		ux = vp2x
		uy = vp2y
		uz = vp2z
        block = 0
    [../]

    [./N2_dgdiff]
        type = ADDGAnisotropicDiffusion
        variable = N2
        block = 0
    [../]
 
    [./N3_dgadv]
        type = ADDGAdvection
        variable = N3
		ux = vp3x
		uy = vp3y
		uz = vp3z
        block = 0
    [../]

    [./N3_dgdiff]
        type = ADDGAnisotropicDiffusion
        variable = N3
        block = 0
    [../]

    [./N4_dgadv]
        type = ADDGAdvection
        variable = N4
		ux = vp4x
		uy = vp4y
		uz = vp4z
        block = 0
    [../]

    [./N4_dgdiff]
        type = ADDGAnisotropicDiffusion
        variable = N4
        block = 0
    [../]

    [./N5_dgadv]
        type = ADDGAdvection
        variable = N5
		ux = vp5x
		uy = vp5y
		uz = vp5z
        block = 0
    [../]

    [./N5_dgdiff]
        type = ADDGAnisotropicDiffusion
        variable = N5
        block = 0
    [../]
 
    [./N6_dgadv]
        type = ADDGAdvection
        variable = N6
		ux = vp6x
		uy = vp6y
		uz = vp6z
        block = 0
    [../]

    [./N6_dgdiff]
        type = ADDGAnisotropicDiffusion
        variable = N6
        block = 0
    [../]

    [./N7_dgadv]
        type = ADDGAdvection
        variable = N7
		ux = vp7x
		uy = vp7y
		uz = vp7z
        block = 0
    [../]

    [./N7_dgdiff]
        type = ADDGAnisotropicDiffusion
        variable = N7
        block = 0
    [../]
 
    [./N8_dgadv]
        type = ADDGAdvection
        variable = N8
		ux = vp8x
		uy = vp8y
		uz = vp8z
        block = 0
    [../]

    [./N8_dgdiff]
        type = ADDGAnisotropicDiffusion
        variable = N8
        block = 0
    [../]

    [./N9_dgadv]
        type = ADDGAdvection
        variable = N9
		ux = vp9x
		uy = vp9y
		uz = vp9z
        block = 0
    [../]

    [./N9_dgdiff]
        type = ADDGAnisotropicDiffusion
        variable = N9
        block = 0
    [../]

    [./N10_dgadv]
        type = ADDGAdvection
        variable = N10
		ux = vp10x
		uy = vp10y
		uz = vp10z
        block = 0
    [../]

    [./N10_dgdiff]
        type = ADDGAnisotropicDiffusion
        variable = N10
        block = 0
    [../]
 
    [./N11_dgadv]
        type = ADDGAdvection
        variable = N11
		ux = vp11x
		uy = vp11y
		uz = vp11z
        block = 0
    [../]

    [./N11_dgdiff]
        type = ADDGAnisotropicDiffusion
        variable = N11
        block = 0
    [../]

    [./N12_dgadv]
        type = ADDGAdvection
        variable = N12
		ux = vp12x
		uy = vp12y
		uz = vp12z
        block = 0
    [../]

    [./N12_dgdiff]
        type = ADDGAnisotropicDiffusion
        variable = N12
        block = 0
    [../]
 
    [./N13_dgadv]
        type = ADDGAdvection
        variable = N13
		ux = vp13x
		uy = vp13y
		uz = vp13z
        block = 0
    [../]

    [./N13_dgdiff]
        type = ADDGAnisotropicDiffusion
        variable = N13
        block = 0
    [../]

    [./N14_dgadv]
        type = ADDGAdvection
        variable = N14
		ux = vp14x
		uy = vp14y
		uz = vp14z
        block = 0
    [../]

    [./N14_dgdiff]
        type = ADDGAnisotropicDiffusion
        variable = N14
        block = 0
    [../]

    [./N15_dgadv]
        type = ADDGAdvection
        variable = N15
		ux = vp15x
		uy = vp15y
		uz = vp15z
        block = 0
    [../]

    [./N15_dgdiff]
        type = ADDGAnisotropicDiffusion
        variable = N15
        block = 0
    [../]
 
    [./N16_dgadv]
        type = ADDGAdvection
        variable = N16
		ux = vp16x
		uy = vp16y
		uz = vp16z
        block = 0
    [../]

    [./N16_dgdiff]
        type = ADDGAnisotropicDiffusion
        variable = N16
        block = 0
    [../]

    [./N17_dgadv]
        type = ADDGAdvection
        variable = N17
		ux = vp17x
		uy = vp17y
		uz = vp17z
        block = 0
    [../]

    [./N17_dgdiff]
        type = ADDGAnisotropicDiffusion
        variable = N17
        block = 0
    [../]
 
    [./N18_dgadv]
        type = ADDGAdvection
        variable = N18
		ux = vp18x
		uy = vp18y
		uz = vp18z
        block = 0
    [../]

    [./N18_dgdiff]
        type = ADDGAnisotropicDiffusion
        variable = N18
        block = 0
    [../]

    [./N19_dgadv]
        type = ADDGAdvection
        variable = N19
		ux = vp19x
		uy = vp19y
		uz = vp19z
        block = 0
    [../]

    [./N19_dgdiff]
        type = ADDGAnisotropicDiffusion
        variable = N19
        block = 0
    [../]

[] #END DGKernels

[InterfaceKernels]

[] #END InterfaceKernels

[AuxKernels]

	[./Total_Volume]
		type = VolumeBalanceCheck
		variable = V_total
		coupled_vars = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
        execute_on = 'initial timestep_end'
        block = 0
	[../]
 
    [./ionization]
 		type = TotalAirIonization
        variable = air_ions
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19'
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

    [./N5_Flux_in_L]
        type = DGConcentrationFluxBC
        variable = N5
        boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp5x
		uy = vp5y
		uz = vp5z
    [../]
 
	[./N6_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N6
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp6x
		uy = vp6y
		uz = vp6z
	[../]
 
	[./N7_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N7
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp7x
		uy = vp7y
		uz = vp7z
	[../]
 
    [./N8_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N8
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp8x
		uy = vp8y
		uz = vp8z
	[../]
 
	[./N9_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N9
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp9x
		uy = vp9y
		uz = vp9z
	[../]

    [./N10_Flux_in_L]
        type = DGConcentrationFluxBC
        variable = N10
        boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp10x
		uy = vp10y
		uz = vp10z
    [../]
 
	[./N11_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N11
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp11x
		uy = vp11y
		uz = vp11z
	[../]
 
	[./N12_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N12
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp12x
		uy = vp12y
		uz = vp12z
	[../]
 
    [./N13_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N13
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp13x
		uy = vp13y
		uz = vp13z
	[../]
 
	[./N14_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N14
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp14x
		uy = vp14y
		uz = vp14z
	[../]

    [./N15_Flux_in_L]
        type = DGConcentrationFluxBC
        variable = N15
        boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp15x
		uy = vp15y
		uz = vp15z
    [../]
 
	[./N16_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N16
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp16x
		uy = vp16y
		uz = vp16z
	[../]
 
	[./N17_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N17
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp17x
		uy = vp17y
		uz = vp17z
	[../]
 
    [./N18_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N18
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp18x
		uy = vp18y
		uz = vp18z
	[../]
 
	[./N19_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N19
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp19x
		uy = vp19y
		uz = vp19z
	[../]

[] #END BCs

[Materials]

[] #END Materials

[UserObjects]

	[./cardinal]
 		type = CARDINAL_Object
 		execute_on = 'initial timestep_end'
 		input_file = 'input_files/cardinal/20-Bin-TestingYield.txt'
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
 
 	petsc_options = '-snes_converged_reason'
 	petsc_options_iname = '-ksp_type -pc_type -sub_pc_type -snes_max_it -sub_pc_factor_shift_type -pc_asm_overlap -snes_atol -snes_rtol'
    petsc_options_value = 'gmres asm ilu 100 NONZERO 2 1E-14 1E-12'

	line_search = bt    # Options: default shell none basic l2 bt cp
    nl_rel_tol = 1e-10
    nl_abs_tol = 1e-6
    nl_rel_step_tol = 1e-10
    nl_abs_step_tol = 1e-10
    l_tol = 1e-4
    l_max_its = 100
    nl_max_its = 50
 
    start_time = 0.0
	end_time = 10800.0
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
    interval = 1

[] #END Outputs
