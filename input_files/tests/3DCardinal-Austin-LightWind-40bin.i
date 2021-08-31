[GlobalParams]

    diameters = '2.00e-8 2.39e-8 2.85e-8 3.40e-8 4.06e-8 4.85e-6 5.80e-8 6.92e-8 8.26e-8 9.86e-8 1.18e-7 1.41e-7 1.68e-7 2.00e-7 2.39e-7 2.86e-7 3.41e-7 4.07e-7 4.87e-7 5.81e-7 6.94e-7 8.28e-7 9.89e-7 1.18e-6 1.41e-6 1.68e-6 2.01e-6 2.40e-6 2.87e-6 3.42e-6 4.08e-6 4.88e-6 5.82e-6 6.95e-6 8.30e-6 9.91e-6 1.18e-5 1.41e-5 1.69e-5 2.01e-5'
 
 	packing_density = '0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75'
 
 	fractal_dimensions = '3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0'
 
 	breakup_constant = 1.0e-5
 
    dissipation = 0.3
 
    energy_dissipation = 0.3

[] #END GlobalParams

[Problem]

[] #END Problem

[Mesh]

    type = GeneratedMesh
    dim = 3
	nx = 10
	ny = 10
	nz = 10
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
 
 	[./N5]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
 	[./N6]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
 	[./N7]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
    [./N8]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]

    [./N9]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]

	[./N10]
        order = CONSTANT
        family = MONOMIAL
    [../]
 
 	[./N11]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
 	[./N12]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
 	[./N13]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
    [./N14]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
    
    [./N15]
        order = CONSTANT
        family = MONOMIAL
    [../]
 
 	[./N16]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
 	[./N17]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
 	[./N18]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
    [./N19]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]

    [./N20]
        order = CONSTANT
        family = MONOMIAL
    [../]
 
 	[./N21]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
 	[./N22]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
 	[./N23]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
    [./N24]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
 	[./N25]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
 	[./N26]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
 	[./N27]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
    [./N28]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]

    [./N29]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
    [./N30]
        order = CONSTANT
        family = MONOMIAL
    [../]
 
 	[./N31]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
 	[./N32]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
 	[./N33]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
    [./N34]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
 	[./N35]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
 	[./N36]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
 	[./N37]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
    [./N38]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]

    [./N39]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
[] #END Variables

[AuxVariables]
 
	[./V_total]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
  	[./N0_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
 	[./N1_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]

 	[./N2_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
 	[./N3_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
 	[./N4_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
 	[./N5_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
    [./N6_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
  	[./N7_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
    [./N8_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
    [./N9_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
    [./N10_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
 	[./N11_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]

 	[./N12_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
 	[./N13_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
 	[./N14_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
 	[./N15_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
    [./N16_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
  	[./N17_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
    [./N18_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
    [./N19_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]

  	[./N20_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
 	[./N21_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]

 	[./N22_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
 	[./N23_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
 	[./N24_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
 	[./N25_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
    [./N26_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
  	[./N27_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
    [./N28_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
    [./N29_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
    [./N30_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
 	[./N31_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]

 	[./N32_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
 	[./N33_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
 	[./N34_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
 	[./N35_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
    [./N36_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
  	[./N37_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
    [./N38_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
    [./N39_accum]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
    [./wx]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
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
		initial_condition = 0.0
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
		initial_condition = 0.0
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
		initial_condition = 0.0
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
 		initial_condition = 0.0
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
 		initial_condition = 0.0
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

	[./vp5x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp5y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp5z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp6x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp6y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp6z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp7x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp7y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp7z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
 	[./vp8x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp8y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp8z]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
 	[./vp9x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp9y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp9z]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]

	[./vp10x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp10y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp10z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp11x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp11y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp11z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp12x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp12y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp12z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
 	[./vp13x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp13y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp13z]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
 	[./vp14x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp14y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp14z]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]

	[./vp15x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp15y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp15z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp16x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp16y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp16z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp17x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp17y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp17z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
 	[./vp18x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp18y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp18z]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
 	[./vp19x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp19y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp19z]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]

	[./vp20x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp20y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp20z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp21x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp21y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp21z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp22x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp22y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp22z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
 	[./vp23x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp23y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp23z]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
 	[./vp24x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp24y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp24z]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]

	[./vp25x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp25y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp25z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp26x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp26y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp26z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp27x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp27y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp27z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
 	[./vp28x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp28y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp28z]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
 	[./vp29x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp29y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp29z]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
    [./vp30x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp30y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp30z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp31x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp31y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp31z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp32x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp32y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp32z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
 	[./vp33x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp33y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp33z]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
 	[./vp34x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp34y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp34z]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]

	[./vp35x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp35y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp35z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp36x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp36y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp36z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp37x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp37y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp37z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
 	[./vp38x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp38y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp38z]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
 	[./vp39x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp39y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp39z]
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
        x_center = 5000
        y_center = 5000
        local_size_index = 0
        cardinal_object = cardinal
    [../]
 
 	[./N1_IC]
 		type = CARDINAL_CloudIC
 		variable = N1
        x_center = 5000
        y_center = 5000
 		local_size_index = 1
 		cardinal_object = cardinal
 	[../]
 
 	[./N2_IC]
 		type = CARDINAL_CloudIC
 		variable = N2
        x_center = 5000
        y_center = 5000
 		local_size_index = 2
 		cardinal_object = cardinal
 	[../]
 
 	[./N3_IC]
 		type = CARDINAL_CloudIC
 		variable = N3
        x_center = 5000
        y_center = 5000
 		local_size_index = 3
 		cardinal_object = cardinal
 	[../]
 
 	[./N4_IC]
 		type = CARDINAL_CloudIC
 		variable = N4
        x_center = 5000
        y_center = 5000
 		local_size_index = 4
 		cardinal_object = cardinal
 	[../]

	[./N5_IC]
 		type = CARDINAL_CloudIC
        variable = N5
        x_center = 5000
        y_center = 5000
        local_size_index = 5
        cardinal_object = cardinal
    [../]
 
 	[./N6_IC]
 		type = CARDINAL_CloudIC
 		variable = N6
        x_center = 5000
        y_center = 5000
 		local_size_index = 6
 		cardinal_object = cardinal
 	[../]
 
 	[./N7_IC]
 		type = CARDINAL_CloudIC
 		variable = N7
        x_center = 5000
        y_center = 5000
 		local_size_index = 7
 		cardinal_object = cardinal
 	[../]
 
 	[./N8_IC]
 		type = CARDINAL_CloudIC
 		variable = N8
        x_center = 5000
        y_center = 5000
 		local_size_index = 8
 		cardinal_object = cardinal
 	[../]
 
 	[./N9_IC]
 		type = CARDINAL_CloudIC
 		variable = N9
        x_center = 5000
        y_center = 5000
 		local_size_index = 9
 		cardinal_object = cardinal
 	[../]

	[./N10_IC]
 		type = CARDINAL_CloudIC
        variable = N10
        x_center = 5000
        y_center = 5000
        local_size_index = 10
        cardinal_object = cardinal
    [../]
 
 	[./N11_IC]
 		type = CARDINAL_CloudIC
 		variable = N11
        x_center = 5000
        y_center = 5000
 		local_size_index = 11
 		cardinal_object = cardinal
 	[../]
 
 	[./N12_IC]
 		type = CARDINAL_CloudIC
 		variable = N12
        x_center = 5000
        y_center = 5000
 		local_size_index = 12
 		cardinal_object = cardinal
 	[../]
 
 	[./N13_IC]
 		type = CARDINAL_CloudIC
 		variable = N13
        x_center = 5000
        y_center = 5000
 		local_size_index = 13
 		cardinal_object = cardinal
 	[../]
 
 	[./N14_IC]
 		type = CARDINAL_CloudIC
 		variable = N14
        x_center = 5000
        y_center = 5000
 		local_size_index = 14
 		cardinal_object = cardinal
 	[../]

	[./N15_IC]
 		type = CARDINAL_CloudIC
        variable = N15
        x_center = 5000
        y_center = 5000
        local_size_index = 15
        cardinal_object = cardinal
    [../]
 
 	[./N16_IC]
 		type = CARDINAL_CloudIC
 		variable = N16
        x_center = 5000
        y_center = 5000
 		local_size_index = 16
 		cardinal_object = cardinal
 	[../]
 
 	[./N17_IC]
 		type = CARDINAL_CloudIC
 		variable = N17
        x_center = 5000
        y_center = 5000
 		local_size_index = 17
 		cardinal_object = cardinal
 	[../]
 
 	[./N18_IC]
 		type = CARDINAL_CloudIC
 		variable = N18
        x_center = 5000
        y_center = 5000
 		local_size_index = 18
 		cardinal_object = cardinal
 	[../]
 
 	[./N19_IC]
 		type = CARDINAL_CloudIC
 		variable = N19
        x_center = 5000
        y_center = 5000
 		local_size_index = 19
 		cardinal_object = cardinal
 	[../]

	[./N20_IC]
 		type = CARDINAL_CloudIC
        variable = N20
        x_center = 5000
        y_center = 5000
        local_size_index = 20
        cardinal_object = cardinal
    [../]
 
 	[./N21_IC]
 		type = CARDINAL_CloudIC
 		variable = N21
        x_center = 5000
        y_center = 5000
 		local_size_index = 21
 		cardinal_object = cardinal
 	[../]
 
 	[./N22_IC]
 		type = CARDINAL_CloudIC
 		variable = N22
        x_center = 5000
        y_center = 5000
 		local_size_index = 22
 		cardinal_object = cardinal
 	[../]
 
 	[./N23_IC]
 		type = CARDINAL_CloudIC
 		variable = N23
        x_center = 5000
        y_center = 5000
 		local_size_index = 23
 		cardinal_object = cardinal
 	[../]
 
 	[./N24_IC]
 		type = CARDINAL_CloudIC
 		variable = N24
        x_center = 5000
        y_center = 5000
 		local_size_index = 24
 		cardinal_object = cardinal
 	[../]

	[./N25_IC]
 		type = CARDINAL_CloudIC
        variable = N25
        x_center = 5000
        y_center = 5000
        local_size_index = 25
        cardinal_object = cardinal
    [../]
 
 	[./N26_IC]
 		type = CARDINAL_CloudIC
 		variable = N26
        x_center = 5000
        y_center = 5000
 		local_size_index = 26
 		cardinal_object = cardinal
 	[../]
 
 	[./N27_IC]
 		type = CARDINAL_CloudIC
 		variable = N27
        x_center = 5000
        y_center = 5000
 		local_size_index = 27
 		cardinal_object = cardinal
 	[../]
 
 	[./N28_IC]
 		type = CARDINAL_CloudIC
 		variable = N28
        x_center = 5000
        y_center = 5000
 		local_size_index = 28
 		cardinal_object = cardinal
 	[../]
 
 	[./N29_IC]
 		type = CARDINAL_CloudIC
 		variable = N29
        x_center = 5000
        y_center = 5000
 		local_size_index = 29
 		cardinal_object = cardinal
 	[../]
 
    [./N30_IC]
 		type = CARDINAL_CloudIC
        variable = N30
        x_center = 5000
        y_center = 5000
        local_size_index = 30
        cardinal_object = cardinal
    [../]
 
 	[./N31_IC]
 		type = CARDINAL_CloudIC
 		variable = N31
        x_center = 5000
        y_center = 5000
 		local_size_index = 31
 		cardinal_object = cardinal
 	[../]
 
 	[./N32_IC]
 		type = CARDINAL_CloudIC
 		variable = N32
        x_center = 5000
        y_center = 5000
 		local_size_index = 32
 		cardinal_object = cardinal
 	[../]
 
 	[./N33_IC]
 		type = CARDINAL_CloudIC
 		variable = N33
        x_center = 5000
        y_center = 5000
 		local_size_index = 33
 		cardinal_object = cardinal
 	[../]
 
 	[./N34_IC]
 		type = CARDINAL_CloudIC
 		variable = N34
        x_center = 5000
        y_center = 5000
 		local_size_index = 34
 		cardinal_object = cardinal
 	[../]

	[./N35_IC]
 		type = CARDINAL_CloudIC
        variable = N35
        x_center = 5000
        y_center = 5000
        local_size_index = 35
        cardinal_object = cardinal
    [../]
 
 	[./N36_IC]
 		type = CARDINAL_CloudIC
 		variable = N36
        x_center = 5000
        y_center = 5000
 		local_size_index = 36
 		cardinal_object = cardinal
 	[../]
 
 	[./N37_IC]
 		type = CARDINAL_CloudIC
 		variable = N37
        x_center = 5000
        y_center = 5000
 		local_size_index = 37
 		cardinal_object = cardinal
 	[../]
 
 	[./N38_IC]
 		type = CARDINAL_CloudIC
 		variable = N38
        x_center = 5000
        y_center = 5000
 		local_size_index = 38
 		cardinal_object = cardinal
 	[../]
 
 	[./N39_IC]
 		type = CARDINAL_CloudIC
 		variable = N39
        x_center = 5000
        y_center = 5000
 		local_size_index = 39
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
        type = CoagulationMonoPB
        variable = N0
        main_variable = N0
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N0_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N0
 		main_variable = N0
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
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
        type = CoagulationMonoPB
        variable = N1
        main_variable = N1
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N1_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N1
 		main_variable = N1
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
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
        type = CoagulationMonoPB
        variable = N2
        main_variable = N2
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N2_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N2
 		main_variable = N2
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
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
        type = CoagulationMonoPB
        variable = N3
        main_variable = N3
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N3_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N3
 		main_variable = N3
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
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
        type = CoagulationMonoPB
        variable = N4
        main_variable = N4
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N4_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N4
 		main_variable = N4
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
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

    [./N5_MPB_Agg]
        type = CoagulationMonoPB
        variable = N5
        main_variable = N5
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N5_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N5
 		main_variable = N5
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
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

    [./N6_MPB_Agg]
        type = CoagulationMonoPB
        variable = N6
        main_variable = N6
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N6_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N6
 		main_variable = N6
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
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

    [./N7_MPB_Agg]
        type = CoagulationMonoPB
        variable = N7
        main_variable = N7
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N7_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N7
 		main_variable = N7
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
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

    [./N8_MPB_Agg]
        type = CoagulationMonoPB
        variable = N8
        main_variable = N8
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N8_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N8
 		main_variable = N8
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
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

    [./N9_MPB_Agg]
        type = CoagulationMonoPB
        variable = N9
        main_variable = N9
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N9_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N9
 		main_variable = N9
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
    [./N10_dot]
        type = CoefTimeDerivative
        variable = N10
        Coefficient = 1.0
    [../]
 
    [./N10_gadv]
        type = GConcentrationAdvection
        variable = N10
		ux = vp10x
		uy = vp10y
		uz = vp10z
    [../]

    [./N10_gdiff]
        type = GAnisotropicDiffusion
        variable = N10
    [../]

    [./N10_MPB_Agg]
        type = CoagulationMonoPB
        variable = N10
        main_variable = N10
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N10_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N10
 		main_variable = N10
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
 	[./N11_dot]
 		type = CoefTimeDerivative
 		variable = N11
 		Coefficient = 1.0
 	[../]
 
    [./N11_gadv]
        type = GConcentrationAdvection
        variable = N11
		ux = vp11x
		uy = vp11y
		uz = vp11z
    [../]

    [./N11_gdiff]
        type = GAnisotropicDiffusion
        variable = N11
    [../]

    [./N11_MPB_Agg]
        type = CoagulationMonoPB
        variable = N11
        main_variable = N11
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N11_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N11
 		main_variable = N11
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
 	[./N12_dot]
 		type = CoefTimeDerivative
 		variable = N12
 		Coefficient = 1.0
 	[../]
 
    [./N12_gadv]
        type = GConcentrationAdvection
        variable = N12
		ux = vp12x
		uy = vp12y
		uz = vp12z
    [../]

    [./N12_gdiff]
        type = GAnisotropicDiffusion
        variable = N12
    [../]

    [./N12_MPB_Agg]
        type = CoagulationMonoPB
        variable = N12
        main_variable = N12
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N12_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N12
 		main_variable = N12
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
 	[./N13_dot]
 		type = CoefTimeDerivative
 		variable = N13
 		Coefficient = 1.0
 	[../]
 
    [./N13_gadv]
        type = GConcentrationAdvection
        variable = N13
		ux = vp13x
		uy = vp13y
		uz = vp13z
    [../]

    [./N13_gdiff]
        type = GAnisotropicDiffusion
        variable = N13
    [../]

    [./N13_MPB_Agg]
        type = CoagulationMonoPB
        variable = N13
        main_variable = N13
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N13_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N13
 		main_variable = N13
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
 	[./N14_dot]
 		type = CoefTimeDerivative
 		variable = N14
 		Coefficient = 1.0
 	[../]
 
    [./N14_gadv]
        type = GConcentrationAdvection
        variable = N14
		ux = vp14x
		uy = vp14y
		uz = vp14z
    [../]

    [./N14_gdiff]
        type = GAnisotropicDiffusion
        variable = N14
    [../]

    [./N14_MPB_Agg]
        type = CoagulationMonoPB
        variable = N14
        main_variable = N14
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N14_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N14
 		main_variable = N14
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]

    [./N15_dot]
        type = CoefTimeDerivative
        variable = N15
        Coefficient = 1.0
    [../]
 
    [./N15_gadv]
        type = GConcentrationAdvection
        variable = N15
		ux = vp15x
		uy = vp15y
		uz = vp15z
    [../]

    [./N15_gdiff]
        type = GAnisotropicDiffusion
        variable = N15
    [../]

    [./N15_MPB_Agg]
        type = CoagulationMonoPB
        variable = N15
        main_variable = N15
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N15_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N15
 		main_variable = N15
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
 	[./N16_dot]
 		type = CoefTimeDerivative
 		variable = N16
 		Coefficient = 1.0
 	[../]
 
    [./N16_gadv]
        type = GConcentrationAdvection
        variable = N16
		ux = vp16x
		uy = vp16y
		uz = vp16z
    [../]

    [./N16_gdiff]
        type = GAnisotropicDiffusion
        variable = N16
    [../]

    [./N16_MPB_Agg]
        type = CoagulationMonoPB
        variable = N16
        main_variable = N16
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N16_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N16
 		main_variable = N16
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
 	[./N17_dot]
 		type = CoefTimeDerivative
 		variable = N17
 		Coefficient = 1.0
 	[../]
 
    [./N17_gadv]
        type = GConcentrationAdvection
        variable = N17
		ux = vp17x
		uy = vp17y
		uz = vp17z
    [../]

    [./N17_gdiff]
        type = GAnisotropicDiffusion
        variable = N17
    [../]

    [./N17_MPB_Agg]
        type = CoagulationMonoPB
        variable = N17
        main_variable = N17
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N17_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N17
 		main_variable = N17
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
 	[./N18_dot]
 		type = CoefTimeDerivative
 		variable = N18
 		Coefficient = 1.0
 	[../]
 
    [./N18_gadv]
        type = GConcentrationAdvection
        variable = N18
		ux = vp18x
		uy = vp18y
		uz = vp18z
    [../]

    [./N18_gdiff]
        type = GAnisotropicDiffusion
        variable = N18
    [../]

    [./N18_MPB_Agg]
        type = CoagulationMonoPB
        variable = N18
        main_variable = N18
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N18_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N18
 		main_variable = N18
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
 	[./N19_dot]
 		type = CoefTimeDerivative
 		variable = N19
 		Coefficient = 1.0
 	[../]
 
    [./N19_gadv]
        type = GConcentrationAdvection
        variable = N19
		ux = vp19x
		uy = vp19y
		uz = vp19z
    [../]

    [./N19_gdiff]
        type = GAnisotropicDiffusion
        variable = N19
    [../]

    [./N19_MPB_Agg]
        type = CoagulationMonoPB
        variable = N19
        main_variable = N19
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N19_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N19
 		main_variable = N19
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]

    [./N20_dot]
        type = CoefTimeDerivative
        variable = N20
        Coefficient = 1.0
    [../]
 
    [./N20_gadv]
        type = GConcentrationAdvection
        variable = N20
		ux = vp20x
		uy = vp20y
		uz = vp20z
    [../]

    [./N20_gdiff]
        type = GAnisotropicDiffusion
        variable = N20
    [../]

    [./N20_MPB_Agg]
        type = CoagulationMonoPB
        variable = N20
        main_variable = N20
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N20_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N20
 		main_variable = N20
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
 	[./N21_dot]
 		type = CoefTimeDerivative
 		variable = N21
 		Coefficient = 1.0
 	[../]
 
    [./N21_gadv]
        type = GConcentrationAdvection
        variable = N21
		ux = vp21x
		uy = vp21y
		uz = vp21z
    [../]

    [./N21_gdiff]
        type = GAnisotropicDiffusion
        variable = N21
    [../]

    [./N21_MPB_Agg]
        type = CoagulationMonoPB
        variable = N21
        main_variable = N21
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N21_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N21
 		main_variable = N21
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
 	[./N22_dot]
 		type = CoefTimeDerivative
 		variable = N22
 		Coefficient = 1.0
 	[../]
 
    [./N22_gadv]
        type = GConcentrationAdvection
        variable = N22
		ux = vp22x
		uy = vp22y
		uz = vp22z
    [../]

    [./N22_gdiff]
        type = GAnisotropicDiffusion
        variable = N22
    [../]

    [./N22_MPB_Agg]
        type = CoagulationMonoPB
        variable = N22
        main_variable = N22
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N22_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N22
 		main_variable = N22
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
 	[./N23_dot]
 		type = CoefTimeDerivative
 		variable = N23
 		Coefficient = 1.0
 	[../]
 
    [./N23_gadv]
        type = GConcentrationAdvection
        variable = N23
		ux = vp23x
		uy = vp23y
		uz = vp23z
    [../]

    [./N23_gdiff]
        type = GAnisotropicDiffusion
        variable = N23
    [../]

    [./N23_MPB_Agg]
        type = CoagulationMonoPB
        variable = N23
        main_variable = N23
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N23_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N23
 		main_variable = N23
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
 	[./N24_dot]
 		type = CoefTimeDerivative
 		variable = N24
 		Coefficient = 1.0
 	[../]
 
    [./N24_gadv]
        type = GConcentrationAdvection
        variable = N24
		ux = vp24x
		uy = vp24y
		uz = vp24z
    [../]

    [./N24_gdiff]
        type = GAnisotropicDiffusion
        variable = N24
    [../]

    [./N24_MPB_Agg]
        type = CoagulationMonoPB
        variable = N24
        main_variable = N24
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N24_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N24
 		main_variable = N24
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]

    [./N25_dot]
        type = CoefTimeDerivative
        variable = N25
        Coefficient = 1.0
    [../]
 
    [./N25_gadv]
        type = GConcentrationAdvection
        variable = N25
		ux = vp25x
		uy = vp25y
		uz = vp25z
    [../]

    [./N25_gdiff]
        type = GAnisotropicDiffusion
        variable = N25
    [../]

    [./N25_MPB_Agg]
        type = CoagulationMonoPB
        variable = N25
        main_variable = N25
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N25_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N25
 		main_variable = N25
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
 	[./N26_dot]
 		type = CoefTimeDerivative
 		variable = N26
 		Coefficient = 1.0
 	[../]
 
    [./N26_gadv]
        type = GConcentrationAdvection
        variable = N26
		ux = vp26x
		uy = vp26y
		uz = vp26z
    [../]

    [./N26_gdiff]
        type = GAnisotropicDiffusion
        variable = N26
    [../]

    [./N26_MPB_Agg]
        type = CoagulationMonoPB
        variable = N26
        main_variable = N26
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N26_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N26
 		main_variable = N26
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
 	[./N27_dot]
 		type = CoefTimeDerivative
 		variable = N27
 		Coefficient = 1.0
 	[../]
 
    [./N27_gadv]
        type = GConcentrationAdvection
        variable = N27
		ux = vp27x
		uy = vp27y
		uz = vp27z
    [../]

    [./N27_gdiff]
        type = GAnisotropicDiffusion
        variable = N27
    [../]

    [./N27_MPB_Agg]
        type = CoagulationMonoPB
        variable = N27
        main_variable = N27
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N27_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N27
 		main_variable = N27
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
 	[./N28_dot]
 		type = CoefTimeDerivative
 		variable = N28
 		Coefficient = 1.0
 	[../]
 
    [./N28_gadv]
        type = GConcentrationAdvection
        variable = N28
		ux = vp28x
		uy = vp28y
		uz = vp28z
    [../]

    [./N28_gdiff]
        type = GAnisotropicDiffusion
        variable = N28
    [../]

    [./N28_MPB_Agg]
        type = CoagulationMonoPB
        variable = N28
        main_variable = N28
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N28_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N28
 		main_variable = N28
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
 	[./N29_dot]
 		type = CoefTimeDerivative
 		variable = N29
 		Coefficient = 1.0
 	[../]
 
    [./N29_gadv]
        type = GConcentrationAdvection
        variable = N29
		ux = vp29x
		uy = vp29y
		uz = vp29z
    [../]

    [./N29_gdiff]
        type = GAnisotropicDiffusion
        variable = N29
    [../]

    [./N29_MPB_Agg]
        type = CoagulationMonoPB
        variable = N29
        main_variable = N29
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N29_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N29
 		main_variable = N29
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
    [./N30_dot]
        type = CoefTimeDerivative
        variable = N30
        Coefficient = 1.0
    [../]
 
    [./N30_gadv]
        type = GConcentrationAdvection
        variable = N30
		ux = vp30x
		uy = vp30y
		uz = vp30z
    [../]

    [./N30_gdiff]
        type = GAnisotropicDiffusion
        variable = N30
    [../]

    [./N30_MPB_Agg]
        type = CoagulationMonoPB
        variable = N30
        main_variable = N30
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N30_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N30
 		main_variable = N30
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
 	[./N31_dot]
 		type = CoefTimeDerivative
 		variable = N31
 		Coefficient = 1.0
 	[../]
 
    [./N31_gadv]
        type = GConcentrationAdvection
        variable = N31
		ux = vp31x
		uy = vp31y
		uz = vp31z
    [../]

    [./N31_gdiff]
        type = GAnisotropicDiffusion
        variable = N31
    [../]

    [./N31_MPB_Agg]
        type = CoagulationMonoPB
        variable = N31
        main_variable = N31
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N31_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N31
 		main_variable = N31
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
 	[./N32_dot]
 		type = CoefTimeDerivative
 		variable = N32
 		Coefficient = 1.0
 	[../]
 
    [./N32_gadv]
        type = GConcentrationAdvection
        variable = N32
		ux = vp32x
		uy = vp32y
		uz = vp32z
    [../]

    [./N32_gdiff]
        type = GAnisotropicDiffusion
        variable = N32
    [../]

    [./N32_MPB_Agg]
        type = CoagulationMonoPB
        variable = N32
        main_variable = N32
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N32_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N32
 		main_variable = N32
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
 	[./N33_dot]
 		type = CoefTimeDerivative
 		variable = N33
 		Coefficient = 1.0
 	[../]
 
    [./N33_gadv]
        type = GConcentrationAdvection
        variable = N33
		ux = vp33x
		uy = vp33y
		uz = vp33z
    [../]

    [./N33_gdiff]
        type = GAnisotropicDiffusion
        variable = N33
    [../]

    [./N33_MPB_Agg]
        type = CoagulationMonoPB
        variable = N33
        main_variable = N33
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N33_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N33
 		main_variable = N33
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
 	[./N34_dot]
 		type = CoefTimeDerivative
 		variable = N34
 		Coefficient = 1.0
 	[../]
 
    [./N34_gadv]
        type = GConcentrationAdvection
        variable = N34
		ux = vp34x
		uy = vp34y
		uz = vp34z
    [../]

    [./N34_gdiff]
        type = GAnisotropicDiffusion
        variable = N34
    [../]

    [./N34_MPB_Agg]
        type = CoagulationMonoPB
        variable = N34
        main_variable = N34
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N34_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N34
 		main_variable = N34
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]

    [./N35_dot]
        type = CoefTimeDerivative
        variable = N35
        Coefficient = 1.0
    [../]
 
    [./N35_gadv]
        type = GConcentrationAdvection
        variable = N35
		ux = vp35x
		uy = vp35y
		uz = vp35z
    [../]

    [./N35_gdiff]
        type = GAnisotropicDiffusion
        variable = N35
    [../]

    [./N35_MPB_Agg]
        type = CoagulationMonoPB
        variable = N35
        main_variable = N35
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N35_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N35
 		main_variable = N35
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
 	[./N36_dot]
 		type = CoefTimeDerivative
 		variable = N36
 		Coefficient = 1.0
 	[../]
 
    [./N36_gadv]
        type = GConcentrationAdvection
        variable = N36
		ux = vp36x
		uy = vp36y
		uz = vp36z
    [../]

    [./N36_gdiff]
        type = GAnisotropicDiffusion
        variable = N36
    [../]

    [./N36_MPB_Agg]
        type = CoagulationMonoPB
        variable = N36
        main_variable = N36
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N36_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N36
 		main_variable = N36
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
 	[./N37_dot]
 		type = CoefTimeDerivative
 		variable = N37
 		Coefficient = 1.0
 	[../]
 
    [./N37_gadv]
        type = GConcentrationAdvection
        variable = N37
		ux = vp37x
		uy = vp37y
		uz = vp37z
    [../]

    [./N37_gdiff]
        type = GAnisotropicDiffusion
        variable = N37
    [../]

    [./N37_MPB_Agg]
        type = CoagulationMonoPB
        variable = N37
        main_variable = N37
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N37_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N37
 		main_variable = N37
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
 	[./N38_dot]
 		type = CoefTimeDerivative
 		variable = N38
 		Coefficient = 1.0
 	[../]
 
    [./N38_gadv]
        type = GConcentrationAdvection
        variable = N38
		ux = vp38x
		uy = vp38y
		uz = vp38z
    [../]

    [./N38_gdiff]
        type = GAnisotropicDiffusion
        variable = N38
    [../]

    [./N38_MPB_Agg]
        type = CoagulationMonoPB
        variable = N38
        main_variable = N38
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N38_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N38
 		main_variable = N38
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
	[../]
 
 	[./N39_dot]
 		type = CoefTimeDerivative
 		variable = N39
 		Coefficient = 1.0
 	[../]
 
    [./N39_gadv]
        type = GConcentrationAdvection
        variable = N39
		ux = vp39x
		uy = vp39y
		uz = vp39z
    [../]

    [./N39_gdiff]
        type = GAnisotropicDiffusion
        variable = N39
    [../]

    [./N39_MPB_Agg]
        type = CoagulationMonoPB
        variable = N39
        main_variable = N39
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
    [../]
 
    [./N39_MPB_Break]
 		type = ShearMultiFragLinearMonoPB
 		variable = N39
 		main_variable = N39
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
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

    [./N10_dgadv]
        type = DGConcentrationAdvection
        variable = N10
		ux = vp10x
		uy = vp10y
		uz = vp10z
    [../]

    [./N10_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N10
    [../]
 
    [./N11_dgadv]
        type = DGConcentrationAdvection
        variable = N11
		ux = vp11x
		uy = vp11y
		uz = vp11z
    [../]

    [./N11_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N11
    [../]

    [./N12_dgadv]
        type = DGConcentrationAdvection
        variable = N12
		ux = vp12x
		uy = vp12y
		uz = vp12z
    [../]

    [./N12_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N12
    [../]
 
    [./N13_dgadv]
        type = DGConcentrationAdvection
        variable = N13
		ux = vp13x
		uy = vp13y
		uz = vp13z
    [../]

    [./N13_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N13
    [../]

    [./N14_dgadv]
        type = DGConcentrationAdvection
        variable = N14
		ux = vp14x
		uy = vp14y
		uz = vp14z
    [../]

    [./N14_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N14
    [../]

    [./N15_dgadv]
        type = DGConcentrationAdvection
        variable = N15
		ux = vp15x
		uy = vp15y
		uz = vp15z
    [../]

    [./N15_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N15
    [../]
 
    [./N16_dgadv]
        type = DGConcentrationAdvection
        variable = N16
		ux = vp16x
		uy = vp16y
		uz = vp16z
    [../]

    [./N16_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N16
    [../]

    [./N17_dgadv]
        type = DGConcentrationAdvection
        variable = N17
		ux = vp17x
		uy = vp17y
		uz = vp17z
    [../]

    [./N17_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N17
    [../]
 
    [./N18_dgadv]
        type = DGConcentrationAdvection
        variable = N18
		ux = vp18x
		uy = vp18y
		uz = vp18z
    [../]

    [./N18_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N18
    [../]

    [./N19_dgadv]
        type = DGConcentrationAdvection
        variable = N19
		ux = vp19x
		uy = vp19y
		uz = vp19z
    [../]

    [./N19_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N19
    [../]

    [./N20_dgadv]
        type = DGConcentrationAdvection
        variable = N20
		ux = vp20x
		uy = vp20y
		uz = vp20z
    [../]

    [./N20_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N20
    [../]
 
    [./N21_dgadv]
        type = DGConcentrationAdvection
        variable = N21
		ux = vp21x
		uy = vp21y
		uz = vp21z
    [../]

    [./N21_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N21
    [../]

    [./N22_dgadv]
        type = DGConcentrationAdvection
        variable = N22
		ux = vp22x
		uy = vp22y
		uz = vp22z
    [../]

    [./N22_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N22
    [../]
 
    [./N23_dgadv]
        type = DGConcentrationAdvection
        variable = N23
		ux = vp23x
		uy = vp23y
		uz = vp23z
    [../]

    [./N23_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N23
    [../]

    [./N24_dgadv]
        type = DGConcentrationAdvection
        variable = N24
		ux = vp24x
		uy = vp24y
		uz = vp24z
    [../]

    [./N24_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N24
    [../]

    [./N25_dgadv]
        type = DGConcentrationAdvection
        variable = N25
		ux = vp25x
		uy = vp25y
		uz = vp25z
    [../]

    [./N25_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N25
    [../]
 
    [./N26_dgadv]
        type = DGConcentrationAdvection
        variable = N26
		ux = vp26x
		uy = vp26y
		uz = vp26z
    [../]

    [./N26_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N26
    [../]

    [./N27_dgadv]
        type = DGConcentrationAdvection
        variable = N27
		ux = vp27x
		uy = vp27y
		uz = vp27z
    [../]

    [./N27_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N27
    [../]
 
    [./N28_dgadv]
        type = DGConcentrationAdvection
        variable = N28
		ux = vp28x
		uy = vp28y
		uz = vp28z
    [../]

    [./N28_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N28
    [../]

    [./N29_dgadv]
        type = DGConcentrationAdvection
        variable = N29
		ux = vp29x
		uy = vp29y
		uz = vp29z
    [../]

    [./N29_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N29
    [../]
 
    [./N30_dgadv]
        type = DGConcentrationAdvection
        variable = N30
		ux = vp30x
		uy = vp30y
		uz = vp30z
    [../]

    [./N30_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N30
    [../]
 
    [./N31_dgadv]
        type = DGConcentrationAdvection
        variable = N31
		ux = vp31x
		uy = vp31y
		uz = vp31z
    [../]

    [./N31_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N31
    [../]

    [./N32_dgadv]
        type = DGConcentrationAdvection
        variable = N32
		ux = vp32x
		uy = vp32y
		uz = vp32z
    [../]

    [./N32_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N32
    [../]
 
    [./N33_dgadv]
        type = DGConcentrationAdvection
        variable = N33
		ux = vp33x
		uy = vp33y
		uz = vp33z
    [../]

    [./N33_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N33
    [../]

    [./N34_dgadv]
        type = DGConcentrationAdvection
        variable = N34
		ux = vp34x
		uy = vp34y
		uz = vp34z
    [../]

    [./N34_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N34
    [../]

    [./N35_dgadv]
        type = DGConcentrationAdvection
        variable = N35
		ux = vp35x
		uy = vp35y
		uz = vp35z
    [../]

    [./N35_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N35
    [../]
 
    [./N36_dgadv]
        type = DGConcentrationAdvection
        variable = N36
		ux = vp36x
		uy = vp36y
		uz = vp36z
    [../]

    [./N36_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N36
    [../]

    [./N37_dgadv]
        type = DGConcentrationAdvection
        variable = N37
		ux = vp37x
		uy = vp37y
		uz = vp37z
    [../]

    [./N37_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N37
    [../]
 
    [./N38_dgadv]
        type = DGConcentrationAdvection
        variable = N38
		ux = vp38x
		uy = vp38y
		uz = vp38z
    [../]

    [./N38_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N38
    [../]

    [./N39_dgadv]
        type = DGConcentrationAdvection
        variable = N39
		ux = vp39x
		uy = vp39y
		uz = vp39z
    [../]

    [./N39_dgdiff]
        type = DGAnisotropicDiffusion
        variable = N39
    [../]
 
[] #END DGKernels

[AuxKernels]

	[./Total_Volume]
		type = VolumeBalanceCheck
		variable = V_total
		coupled_vars = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
        execute_on = 'initial timestep_end'
	[../]
 
    [./N0_accumulated]
 		type = AccumulatedMaterial
 		variable = N0_accum
 		coupled_vars = 'N0'
 		vxs = 'vp0x'
 		vys = 'vp0y'
 		vzs = 'vp0z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N1_accumulated]
 		type = AccumulatedMaterial
 		variable = N1_accum
 		coupled_vars = 'N1'
 		vxs = 'vp1x'
 		vys = 'vp1y'
 		vzs = 'vp1z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N2_accumulated]
 		type = AccumulatedMaterial
 		variable = N2_accum
 		coupled_vars = 'N2'
 		vxs = 'vp2x'
 		vys = 'vp2y'
 		vzs = 'vp2z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N3_accumulated]
 		type = AccumulatedMaterial
 		variable = N3_accum
 		coupled_vars = 'N3'
 		vxs = 'vp3x'
 		vys = 'vp3y'
 		vzs = 'vp3z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N4_accumulated]
 		type = AccumulatedMaterial
 		variable = N4_accum
 		coupled_vars = 'N4'
 		vxs = 'vp4x'
 		vys = 'vp4y'
 		vzs = 'vp4z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N5_accumulated]
 		type = AccumulatedMaterial
 		variable = N5_accum
 		coupled_vars = 'N5'
 		vxs = 'vp5x'
 		vys = 'vp5y'
 		vzs = 'vp5z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N6_accumulated]
 		type = AccumulatedMaterial
 		variable = N6_accum
 		coupled_vars = 'N6'
 		vxs = 'vp6x'
 		vys = 'vp6y'
 		vzs = 'vp6z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N7_accumulated]
 		type = AccumulatedMaterial
 		variable = N7_accum
 		coupled_vars = 'N7'
 		vxs = 'vp7x'
 		vys = 'vp7y'
 		vzs = 'vp7z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N8_accumulated]
 		type = AccumulatedMaterial
 		variable = N8_accum
 		coupled_vars = 'N8'
 		vxs = 'vp8x'
 		vys = 'vp8y'
 		vzs = 'vp8z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N9_accumulated]
 		type = AccumulatedMaterial
 		variable = N9_accum
 		coupled_vars = 'N9'
 		vxs = 'vp9x'
 		vys = 'vp9y'
 		vzs = 'vp9z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N10_accumulated]
 		type = AccumulatedMaterial
 		variable = N10_accum
 		coupled_vars = 'N10'
 		vxs = 'vp10x'
 		vys = 'vp10y'
 		vzs = 'vp10z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N11_accumulated]
 		type = AccumulatedMaterial
 		variable = N11_accum
 		coupled_vars = 'N11'
 		vxs = 'vp11x'
 		vys = 'vp11y'
 		vzs = 'vp11z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N12_accumulated]
 		type = AccumulatedMaterial
 		variable = N12_accum
 		coupled_vars = 'N12'
 		vxs = 'vp12x'
 		vys = 'vp12y'
 		vzs = 'vp12z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N13_accumulated]
 		type = AccumulatedMaterial
 		variable = N13_accum
 		coupled_vars = 'N13'
 		vxs = 'vp13x'
 		vys = 'vp13y'
 		vzs = 'vp13z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N14_accumulated]
 		type = AccumulatedMaterial
 		variable = N14_accum
 		coupled_vars = 'N14'
 		vxs = 'vp14x'
 		vys = 'vp14y'
 		vzs = 'vp14z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N15_accumulated]
 		type = AccumulatedMaterial
 		variable = N15_accum
 		coupled_vars = 'N15'
 		vxs = 'vp15x'
 		vys = 'vp15y'
 		vzs = 'vp15z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N16_accumulated]
 		type = AccumulatedMaterial
 		variable = N16_accum
 		coupled_vars = 'N16'
 		vxs = 'vp16x'
 		vys = 'vp16y'
 		vzs = 'vp16z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N17_accumulated]
 		type = AccumulatedMaterial
 		variable = N17_accum
 		coupled_vars = 'N17'
 		vxs = 'vp17x'
 		vys = 'vp17y'
 		vzs = 'vp17z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N18_accumulated]
 		type = AccumulatedMaterial
 		variable = N18_accum
 		coupled_vars = 'N18'
 		vxs = 'vp18x'
 		vys = 'vp18y'
 		vzs = 'vp18z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N19_accumulated]
 		type = AccumulatedMaterial
 		variable = N19_accum
 		coupled_vars = 'N19'
 		vxs = 'vp19x'
 		vys = 'vp19y'
 		vzs = 'vp19z'
 		execute_on = 'initial timestep_end'
	[../]
 
    [./N20_accumulated]
 		type = AccumulatedMaterial
 		variable = N20_accum
 		coupled_vars = 'N20'
 		vxs = 'vp20x'
 		vys = 'vp20y'
 		vzs = 'vp20z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N21_accumulated]
 		type = AccumulatedMaterial
 		variable = N21_accum
 		coupled_vars = 'N21'
 		vxs = 'vp21x'
 		vys = 'vp21y'
 		vzs = 'vp21z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N22_accumulated]
 		type = AccumulatedMaterial
 		variable = N22_accum
 		coupled_vars = 'N22'
 		vxs = 'vp22x'
 		vys = 'vp22y'
 		vzs = 'vp22z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N23_accumulated]
 		type = AccumulatedMaterial
 		variable = N23_accum
 		coupled_vars = 'N23'
 		vxs = 'vp23x'
 		vys = 'vp23y'
 		vzs = 'vp23z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N24_accumulated]
 		type = AccumulatedMaterial
 		variable = N24_accum
 		coupled_vars = 'N24'
 		vxs = 'vp24x'
 		vys = 'vp24y'
 		vzs = 'vp24z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N25_accumulated]
 		type = AccumulatedMaterial
 		variable = N25_accum
 		coupled_vars = 'N25'
 		vxs = 'vp25x'
 		vys = 'vp25y'
 		vzs = 'vp25z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N26_accumulated]
 		type = AccumulatedMaterial
 		variable = N26_accum
 		coupled_vars = 'N26'
 		vxs = 'vp26x'
 		vys = 'vp26y'
 		vzs = 'vp26z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N27_accumulated]
 		type = AccumulatedMaterial
 		variable = N27_accum
 		coupled_vars = 'N27'
 		vxs = 'vp27x'
 		vys = 'vp27y'
 		vzs = 'vp27z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N28_accumulated]
 		type = AccumulatedMaterial
 		variable = N28_accum
 		coupled_vars = 'N28'
 		vxs = 'vp28x'
 		vys = 'vp28y'
 		vzs = 'vp28z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N29_accumulated]
 		type = AccumulatedMaterial
 		variable = N29_accum
 		coupled_vars = 'N29'
 		vxs = 'vp29x'
 		vys = 'vp29y'
 		vzs = 'vp29z'
 		execute_on = 'initial timestep_end'
	[../]
 
    [./N30_accumulated]
 		type = AccumulatedMaterial
 		variable = N30_accum
 		coupled_vars = 'N30'
 		vxs = 'vp30x'
 		vys = 'vp30y'
 		vzs = 'vp30z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N31_accumulated]
 		type = AccumulatedMaterial
 		variable = N31_accum
 		coupled_vars = 'N31'
 		vxs = 'vp31x'
 		vys = 'vp31y'
 		vzs = 'vp31z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N32_accumulated]
 		type = AccumulatedMaterial
 		variable = N32_accum
 		coupled_vars = 'N32'
 		vxs = 'vp32x'
 		vys = 'vp32y'
 		vzs = 'vp32z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N33_accumulated]
 		type = AccumulatedMaterial
 		variable = N33_accum
 		coupled_vars = 'N33'
 		vxs = 'vp33x'
 		vys = 'vp33y'
 		vzs = 'vp33z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N34_accumulated]
 		type = AccumulatedMaterial
 		variable = N34_accum
 		coupled_vars = 'N34'
 		vxs = 'vp34x'
 		vys = 'vp34y'
 		vzs = 'vp34z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N35_accumulated]
 		type = AccumulatedMaterial
 		variable = N35_accum
 		coupled_vars = 'N35'
 		vxs = 'vp35x'
 		vys = 'vp35y'
 		vzs = 'vp35z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N36_accumulated]
 		type = AccumulatedMaterial
 		variable = N36_accum
 		coupled_vars = 'N36'
 		vxs = 'vp36x'
 		vys = 'vp36y'
 		vzs = 'vp36z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N37_accumulated]
 		type = AccumulatedMaterial
 		variable = N37_accum
 		coupled_vars = 'N37'
 		vxs = 'vp37x'
 		vys = 'vp37y'
 		vzs = 'vp37z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N38_accumulated]
 		type = AccumulatedMaterial
 		variable = N38_accum
 		coupled_vars = 'N38'
 		vxs = 'vp38x'
 		vys = 'vp38y'
 		vzs = 'vp38z'
 		execute_on = 'initial timestep_end'
	[../]

    [./N39_accumulated]
 		type = AccumulatedMaterial
 		variable = N39_accum
 		coupled_vars = 'N39'
 		vxs = 'vp39x'
 		vys = 'vp39y'
 		vzs = 'vp39z'
 		execute_on = 'initial timestep_end'
	[../]
 
    [./ionization]
 		type = TotalAirIonization
        variable = air_ions
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
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
		particle_diameter = 2.0e-8
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
		particle_diameter = 2.0e-8
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
		particle_diameter = 2.0e-8
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
		particle_diameter = 2.39e-8
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
		particle_diameter = 2.39e-8
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
		particle_diameter = 2.39e-8
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
		particle_diameter = 2.85e-8
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
		particle_diameter = 2.85e-8
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
		particle_diameter = 2.85e-8
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
		particle_diameter = 3.40e-8
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
		particle_diameter = 3.40e-8
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
		particle_diameter = 3.40e-8
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
		particle_diameter = 4.06e-8
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
		particle_diameter = 4.06e-8
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
		particle_diameter = 4.06e-8
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
		particle_diameter = 4.85e-8
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
		particle_diameter = 4.85e-8
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
		particle_diameter = 4.85e-8
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
		particle_diameter = 5.80e-8
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
		particle_diameter = 5.80e-8
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
		particle_diameter = 5.80e-8
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
		particle_diameter = 6.92e-8
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
		particle_diameter = 6.92e-8
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
		particle_diameter = 6.92e-8
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
		particle_diameter = 8.26e-8
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
		particle_diameter = 8.26e-8
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
		particle_diameter = 8.26e-8
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
		particle_diameter = 9.86e-8
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
		particle_diameter = 9.86e-8
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
		particle_diameter = 9.86e-8
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
		particle_diameter = 1.18e-7
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
		particle_diameter = 1.18e-7
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
		particle_diameter = 1.18e-7
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
		particle_diameter = 1.41e-7
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
		particle_diameter = 1.41e-7
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
		particle_diameter = 1.41e-7
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
		particle_diameter = 1.68e-7
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
		particle_diameter = 1.68e-7
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
		particle_diameter = 1.68e-7
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
		particle_diameter = 2.0e-7
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
		particle_diameter = 2.0e-7
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
		particle_diameter = 2.0e-7
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
		particle_diameter = 2.39e-7
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
		particle_diameter = 2.39e-7
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
		particle_diameter = 2.39e-7
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
		particle_diameter = 2.86e-7
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
		particle_diameter = 2.86e-7
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
		particle_diameter = 2.86e-7
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
		particle_diameter = 3.41e-7
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
		particle_diameter = 3.41e-7
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
		particle_diameter = 3.41e-7
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
		particle_diameter = 4.07e-7
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
		particle_diameter = 4.07e-7
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
		particle_diameter = 4.07e-7
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
		particle_diameter = 4.87e-7
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
		particle_diameter = 4.87e-7
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
		particle_diameter = 4.87e-7
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
		particle_diameter = 5.81e-7
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
		particle_diameter = 5.81e-7
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
		particle_diameter = 5.81e-7
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

    [./part_vel_20x]
		type = Trajectory1stOrder
		variable = vp20x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp20x
		vary = vp20y
		varz = vp20z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 6.94e-7
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_20y]
		type = Trajectory1stOrder
		variable = vp20y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp20x
		vary = vp20y
		varz = vp20z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 6.94e-7
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_20z]
		type = Trajectory1stOrder
		variable = vp20z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp20x
		vary = vp20y
		varz = vp20z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 6.94e-7
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_21x]
		type = Trajectory1stOrder
		variable = vp21x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp21x
		vary = vp21y
		varz = vp21z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 8.28e-7
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_21y]
		type = Trajectory1stOrder
		variable = vp21y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp21x
		vary = vp21y
		varz = vp21z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 8.28e-7
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_21z]
		type = Trajectory1stOrder
		variable = vp21z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp21x
		vary = vp21y
		varz = vp21z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 8.28e-7
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_22x]
		type = Trajectory1stOrder
		variable = vp22x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp22x
		vary = vp22y
		varz = vp22z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 9.89e-7
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_22y]
		type = Trajectory1stOrder
		variable = vp22y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp22x
		vary = vp22y
		varz = vp22z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 9.89e-7
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_22z]
		type = Trajectory1stOrder
		variable = vp22z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp22x
		vary = vp22y
		varz = vp22z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 9.89e-7
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_23x]
		type = Trajectory1stOrder
		variable = vp23x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp23x
		vary = vp23y
		varz = vp23z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.18e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_23y]
		type = Trajectory1stOrder
		variable = vp23y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp23x
		vary = vp23y
		varz = vp23z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.18e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_23z]
		type = Trajectory1stOrder
		variable = vp23z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp23x
		vary = vp23y
		varz = vp23z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.18e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_24x]
		type = Trajectory1stOrder
		variable = vp24x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp24x
		vary = vp24y
		varz = vp24z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.41e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_24y]
		type = Trajectory1stOrder
		variable = vp24y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp24x
		vary = vp24y
		varz = vp24z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.41e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_24z]
		type = Trajectory1stOrder
		variable = vp24z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp24x
		vary = vp24y
		varz = vp24z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.41e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

    [./part_vel_25x]
		type = Trajectory1stOrder
		variable = vp25x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp25x
		vary = vp25y
		varz = vp25z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.68e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_25y]
		type = Trajectory1stOrder
		variable = vp25y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp25x
		vary = vp25y
		varz = vp25z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.68e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_25z]
		type = Trajectory1stOrder
		variable = vp25z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp25x
		vary = vp25y
		varz = vp25z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.68e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_26x]
		type = Trajectory1stOrder
		variable = vp26x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp26x
		vary = vp26y
		varz = vp26z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.01e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_26y]
		type = Trajectory1stOrder
		variable = vp26y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp26x
		vary = vp26y
		varz = vp26z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.01e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_26z]
		type = Trajectory1stOrder
		variable = vp26z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp26x
		vary = vp26y
		varz = vp26z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.01e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_27x]
		type = Trajectory1stOrder
		variable = vp27x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp27x
		vary = vp27y
		varz = vp27z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.40e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_27y]
		type = Trajectory1stOrder
		variable = vp27y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp27x
		vary = vp27y
		varz = vp27z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.40e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_27z]
		type = Trajectory1stOrder
		variable = vp27z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp27x
		vary = vp27y
		varz = vp27z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.40e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_28x]
		type = Trajectory1stOrder
		variable = vp28x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp28x
		vary = vp28y
		varz = vp28z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.87e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_28y]
		type = Trajectory1stOrder
		variable = vp28y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp28x
		vary = vp28y
		varz = vp28z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.87e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_28z]
		type = Trajectory1stOrder
		variable = vp28z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp28x
		vary = vp28y
		varz = vp28z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.87e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_29x]
		type = Trajectory1stOrder
		variable = vp29x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp29x
		vary = vp29y
		varz = vp29z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 3.42e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_29y]
		type = Trajectory1stOrder
		variable = vp29y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp29x
		vary = vp29y
		varz = vp29z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 3.42e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_29z]
		type = Trajectory1stOrder
		variable = vp29z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp29x
		vary = vp29y
		varz = vp29z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 3.42e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
    [./part_vel_30x]
		type = Trajectory1stOrder
		variable = vp30x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp30x
		vary = vp30y
		varz = vp30z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 4.08e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_30y]
		type = Trajectory1stOrder
		variable = vp30y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp30x
		vary = vp30y
		varz = vp30z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 4.08e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_30z]
		type = Trajectory1stOrder
		variable = vp30z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp30x
		vary = vp30y
		varz = vp30z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 4.08e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_31x]
		type = Trajectory1stOrder
		variable = vp31x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp31x
		vary = vp31y
		varz = vp31z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 4.88e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_31y]
		type = Trajectory1stOrder
		variable = vp31y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp31x
		vary = vp31y
		varz = vp31z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 4.88e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_31z]
		type = Trajectory1stOrder
		variable = vp31z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp31x
		vary = vp31y
		varz = vp31z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 4.88e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_32x]
		type = Trajectory1stOrder
		variable = vp32x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp32x
		vary = vp32y
		varz = vp32z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 5.82e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_32y]
		type = Trajectory1stOrder
		variable = vp32y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp32x
		vary = vp32y
		varz = vp32z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 5.82e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_32z]
		type = Trajectory1stOrder
		variable = vp32z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp32x
		vary = vp32y
		varz = vp32z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 5.82e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_33x]
		type = Trajectory1stOrder
		variable = vp33x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp33x
		vary = vp33y
		varz = vp33z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 6.95e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_33y]
		type = Trajectory1stOrder
		variable = vp33y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp33x
		vary = vp33y
		varz = vp33z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 6.95e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_33z]
		type = Trajectory1stOrder
		variable = vp33z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp33x
		vary = vp33y
		varz = vp33z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 6.95e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_34x]
		type = Trajectory1stOrder
		variable = vp34x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp34x
		vary = vp34y
		varz = vp34z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 8.30e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_34y]
		type = Trajectory1stOrder
		variable = vp34y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp34x
		vary = vp34y
		varz = vp34z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 8.30e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_34z]
		type = Trajectory1stOrder
		variable = vp34z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp34x
		vary = vp34y
		varz = vp34z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 8.30e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

    [./part_vel_35x]
		type = Trajectory1stOrder
		variable = vp35x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp35x
		vary = vp35y
		varz = vp35z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 9.91e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_35y]
		type = Trajectory1stOrder
		variable = vp35y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp35x
		vary = vp35y
		varz = vp35z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 9.91e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_35z]
		type = Trajectory1stOrder
		variable = vp35z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp35x
		vary = vp35y
		varz = vp35z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 9.91e-6
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_36x]
		type = Trajectory1stOrder
		variable = vp36x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp36x
		vary = vp36y
		varz = vp36z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.18e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_36y]
		type = Trajectory1stOrder
		variable = vp36y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp36x
		vary = vp36y
		varz = vp36z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.18e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_36z]
		type = Trajectory1stOrder
		variable = vp36z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp36x
		vary = vp36y
		varz = vp36z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.18e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_37x]
		type = Trajectory1stOrder
		variable = vp37x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp37x
		vary = vp37y
		varz = vp37z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.41e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_37y]
		type = Trajectory1stOrder
		variable = vp37y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp37x
		vary = vp37y
		varz = vp37z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.41e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_37z]
		type = Trajectory1stOrder
		variable = vp37z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp37x
		vary = vp37y
		varz = vp37z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.41e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_38x]
		type = Trajectory1stOrder
		variable = vp38x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp38x
		vary = vp38y
		varz = vp38z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.69e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_38y]
		type = Trajectory1stOrder
		variable = vp38y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp38x
		vary = vp38y
		varz = vp38z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.69e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_38z]
		type = Trajectory1stOrder
		variable = vp38z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp38x
		vary = vp38y
		varz = vp38z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.69e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_39x]
		type = Trajectory1stOrder
		variable = vp39x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp39x
		vary = vp39y
		varz = vp39z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.01e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_39y]
		type = Trajectory1stOrder
		variable = vp39y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp39x
		vary = vp39y
		varz = vp39z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.01e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_39z]
		type = Trajectory1stOrder
		variable = vp39z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp39x
		vary = vp39y
		varz = vp39z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.01e-5
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

    [./N20_Flux_in_L]
        type = DGConcentrationFluxBC
        variable = N20
        boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp20x
		uy = vp20y
		uz = vp20z
    [../]
 
	[./N21_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N21
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp21x
		uy = vp21y
		uz = vp21z
	[../]
 
	[./N22_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N22
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp22x
		uy = vp22y
		uz = vp22z
	[../]
 
    [./N23_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N23
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp23x
		uy = vp23y
		uz = vp23z
	[../]
 
	[./N24_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N24
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp24x
		uy = vp24y
		uz = vp24z
	[../]

    [./N25_Flux_in_L]
        type = DGConcentrationFluxBC
        variable = N25
        boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp25x
		uy = vp25y
		uz = vp25z
    [../]
 
	[./N26_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N26
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp26x
		uy = vp26y
		uz = vp26z
	[../]
 
	[./N27_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N27
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp27x
		uy = vp27y
		uz = vp27z
	[../]
 
    [./N28_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N28
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp28x
		uy = vp28y
		uz = vp28z
	[../]
 
	[./N29_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N29
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp29x
		uy = vp29y
		uz = vp29z
	[../]
 
    [./N30_Flux_in_L]
        type = DGConcentrationFluxBC
        variable = N30
        boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp30x
		uy = vp30y
		uz = vp30z
    [../]
 
	[./N31_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N31
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp31x
		uy = vp31y
		uz = vp31z
	[../]
 
	[./N32_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N32
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp32x
		uy = vp32y
		uz = vp32z
	[../]
 
    [./N33_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N33
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp33x
		uy = vp33y
		uz = vp33z
	[../]
 
	[./N34_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N34
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp34x
		uy = vp34y
		uz = vp34z
	[../]

    [./N35_Flux_in_L]
        type = DGConcentrationFluxBC
        variable = N35
        boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp35x
		uy = vp35y
		uz = vp35z
    [../]
 
	[./N36_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N36
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp36x
		uy = vp36y
		uz = vp36z
	[../]
 
	[./N37_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N37
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp37x
		uy = vp37y
		uz = vp37z
	[../]
 
    [./N38_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N38
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp38x
		uy = vp38y
		uz = vp38z
	[../]
 
	[./N39_Flux_in_L]
		type = DGConcentrationFluxBC
		variable = N39
		boundary = 'left right top bottom front back'
		u_input = 0.0
		ux = vp39x
		uy = vp39y
		uz = vp39z
	[../]

[] #END BCs

[Materials]

	[./CollisionParams]
 		type = CollisionParameters
        block = 0
        cardinal_object = cardinal
        coupled_conc = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39'
        air_density = air_dens
        air_viscosity = air_visc
        temperature = air_temp
        ionization = air_ions
        windx = wx
        windy = wy
        windz = wz
        coupled_vx = 'vp0x vp1x vp2x vp3x vp4x vp5x vp6x vp7x vp8x vp9x vp10x vp11x vp12x vp13x vp14x vp15x vp16x vp17x vp18x vp19x vp20x vp21x vp22x vp23x vp24x vp25x vp26x vp27x vp28x vp29x vp30x vp31x vp32x vp33x vp34x vp35x vp36x vp37x vp38x vp39x'
        coupled_vy = 'vp0y vp1y vp2y vp3y vp4y vp5y vp6y vp7y vp8y vp9y vp10y vp11y vp12y vp13y vp14y vp15y vp16y vp17y vp18y vp19y vp20y vp21y vp22y vp23y vp24y vp25y vp26y vp27y vp28y vp29y vp30y vp31y vp32y vp33y vp34y vp35y vp36y vp37y vp38y vp39y'
        coupled_vz = 'vp0z vp1z vp2z vp3z vp4z vp5z vp6z vp7z vp8z vp9z vp10z vp11z vp12z vp13z vp14z vp15z vp16z vp17z vp18z vp19z vp20z vp21z vp22z vp23z vp24z vp25z vp26z vp27z vp28z vp29z vp30z vp31z vp32z vp33z vp34z vp35z vp36z vp37z vp38z vp39z'
    [../]

[] #END Materials

[UserObjects]

	[./cardinal]
 		type = CARDINAL_Object
 		execute_on = 'initial timestep_end'
 		input_file = 'input_files/cardinal/40-Bin-Standard.txt'
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
 
    [./N00_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N0_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N01_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N1_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N02_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N2_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N03_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N3_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N04_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N4_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N05_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N5_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N06_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N6_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N07_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N7_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N08_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N8_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N09_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N9_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N10_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N10_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N11_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N11_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N12_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N12_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N13_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N13_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N14_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N14_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N15_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N15_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N16_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N16_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N17_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N17_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N18_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N18_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N19_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N19_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N20_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N20_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N21_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N21_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N22_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N22_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N23_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N23_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N24_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N24_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N25_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N25_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N26_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N26_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N27_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N27_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N28_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N28_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N29_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N29_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N30_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N30_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N31_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N31_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N32_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N32_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N33_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N33_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N34_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N34_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N35_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N35_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N36_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N36_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N37_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N37_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N38_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N38_accum
		execute_on = 'initial timestep_end'
	[../]

    [./N39_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N39_accum
		execute_on = 'initial timestep_end'
	[../]
 
	[./N00]
		type = ElementAverageValue
		variable = N0
		execute_on = 'initial timestep_end'
	[../]
 
	[./N01]
		type = ElementAverageValue
		variable = N1
		execute_on = 'initial timestep_end'
	[../]
 
 	[./N02]
 		type = ElementAverageValue
 		variable = N2
		 execute_on = 'initial timestep_end'
	[../]
 
 	[./N03]
 		type = ElementAverageValue
 		variable = N3
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./N04]
 		type = ElementAverageValue
 		variable = N4
 		execute_on = 'initial timestep_end'
	[../]

	[./N05]
		type = ElementAverageValue
		variable = N5
		execute_on = 'initial timestep_end'
	[../]
 
	[./N06]
		type = ElementAverageValue
		variable = N6
		execute_on = 'initial timestep_end'
	[../]
 
 	[./N07]
 		type = ElementAverageValue
 		variable = N7
		 execute_on = 'initial timestep_end'
	[../]
 
 	[./N08]
 		type = ElementAverageValue
 		variable = N8
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./N09]
 		type = ElementAverageValue
 		variable = N9
 		execute_on = 'initial timestep_end'
	[../]

	[./N10]
		type = ElementAverageValue
		variable = N10
		execute_on = 'initial timestep_end'
	[../]
 
	[./N11]
		type = ElementAverageValue
		variable = N11
		execute_on = 'initial timestep_end'
	[../]
 
 	[./N12]
 		type = ElementAverageValue
 		variable = N12
		 execute_on = 'initial timestep_end'
	[../]
 
 	[./N13]
 		type = ElementAverageValue
 		variable = N13
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./N14]
 		type = ElementAverageValue
 		variable = N14
 		execute_on = 'initial timestep_end'
	[../]

	[./N15]
		type = ElementAverageValue
		variable = N15
		execute_on = 'initial timestep_end'
	[../]
 
	[./N16]
		type = ElementAverageValue
		variable = N16
		execute_on = 'initial timestep_end'
	[../]
 
 	[./N17]
 		type = ElementAverageValue
 		variable = N17
		 execute_on = 'initial timestep_end'
	[../]
 
 	[./N18]
 		type = ElementAverageValue
 		variable = N18
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./N19]
 		type = ElementAverageValue
 		variable = N19
 		execute_on = 'initial timestep_end'
	[../]

	[./N20]
		type = ElementAverageValue
		variable = N20
		execute_on = 'initial timestep_end'
	[../]
 
	[./N21]
		type = ElementAverageValue
		variable = N21
		execute_on = 'initial timestep_end'
	[../]
 
 	[./N22]
 		type = ElementAverageValue
 		variable = N22
		 execute_on = 'initial timestep_end'
	[../]
 
 	[./N23]
 		type = ElementAverageValue
 		variable = N23
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./N24]
 		type = ElementAverageValue
 		variable = N24
 		execute_on = 'initial timestep_end'
	[../]

	[./N25]
		type = ElementAverageValue
		variable = N25
		execute_on = 'initial timestep_end'
	[../]
 
	[./N26]
		type = ElementAverageValue
		variable = N26
		execute_on = 'initial timestep_end'
	[../]
 
 	[./N27]
 		type = ElementAverageValue
 		variable = N27
		 execute_on = 'initial timestep_end'
	[../]
 
 	[./N28]
 		type = ElementAverageValue
 		variable = N28
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./N29]
 		type = ElementAverageValue
 		variable = N29
 		execute_on = 'initial timestep_end'
	[../]

	[./N30]
		type = ElementAverageValue
		variable = N30
		execute_on = 'initial timestep_end'
	[../]
 
	[./N31]
		type = ElementAverageValue
		variable = N31
		execute_on = 'initial timestep_end'
	[../]
 
 	[./N32]
 		type = ElementAverageValue
 		variable = N32
		 execute_on = 'initial timestep_end'
	[../]
 
 	[./N33]
 		type = ElementAverageValue
 		variable = N33
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./N34]
 		type = ElementAverageValue
 		variable = N34
 		execute_on = 'initial timestep_end'
	[../]

	[./N35]
		type = ElementAverageValue
		variable = N35
		execute_on = 'initial timestep_end'
	[../]
 
	[./N36]
		type = ElementAverageValue
		variable = N36
		execute_on = 'initial timestep_end'
	[../]
 
 	[./N37]
 		type = ElementAverageValue
 		variable = N37
		 execute_on = 'initial timestep_end'
	[../]
 
 	[./N38]
 		type = ElementAverageValue
 		variable = N38
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./N39]
 		type = ElementAverageValue
 		variable = N39
 		execute_on = 'initial timestep_end'
	[../]
 
[] #END Postprocessors

[Preconditioning]
 
	[./smp]
 		type = SMP
 		full = true
 		solve_type = pjfnk
	[../]
 
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
	end_time = 1296000.0
    dtmax = 24000.0

    [./TimeStepper]
		type = SolutionTimeAdaptiveDT
#		type = ConstantDT
        dt = 100.0
    [../]
[] #END Executioner
 
[Adaptivity]

[] #END Adaptivity

[Outputs]

    exodus = true
    csv = true
    print_linear_residuals = false

[] #END Outputs
