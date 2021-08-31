[GlobalParams]

 	diameters = '1.0e-8 1.27e-8 1.60e-8 2.02e-8 2.56e-8 3.24e-8 4.10e-8 5.18e-8 6.56e-8 8.29e-8 1.05e-7 1.33e-7 1.68e-7 2.12e-7 2.69e-7 3.40e-7 4.30e-7 5.44e-7 6.88e-7 8.70e-7 1.10e-6 1.39e-6 1.76e-6 2.23e-6 2.82e-6 3.57e-6 4.51e-6 5.71e-6 7.22e-6 9.13e-6 1.16e-5 1.46e-5 1.85e-5 2.34e-5 2.96e-5 3.74e-5 4.73e-5 5.99e-5 7.58e-5 9.58e-5 1.21e-4 1.53e-4 1.94e-4 2.45e-4 3.10e-4 3.93e-4 4.97e-4 6.28e-4 7.95e-4 1.01e-3'
 
 	packing_density = '0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75 0.75'
 
 	fractal_dimensions = '3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0 3.0'
 
 	breakup_constant = 1.0e-5
 
    dissipation = 0.175
 
    energy_dissipation = 0.175

 
[] #END GlobalParams

[Problem]

[] #END Problem

[Mesh]

    type = GeneratedMesh
    dim = 3
	nx = 1
	ny = 1
	nz = 1
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

    [./N40]
        order = CONSTANT
        family = MONOMIAL
    [../]
 
 	[./N41]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
 	[./N42]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
 	[./N43]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
    [./N44]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
    
    [./N45]
        order = CONSTANT
        family = MONOMIAL
    [../]
 
 	[./N46]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
 	[./N47]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
 	[./N48]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]
 
    [./N49]
 		order = CONSTANT
 		family = MONOMIAL
 	[../]

[] #END Variables

[AuxVariables]
 
	[./V_total]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
    [./wx]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 2.0
	[../]
 
	[./wy]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 2.0
	[../]
 
	[./wz]
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

	[./vp40x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp40y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp40z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp41x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp41y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp41z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp42x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp42y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp42z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
 	[./vp43x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp43y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp43z]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
 	[./vp44x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp44y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp44z]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
    [./vp45x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp45y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp45z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp46x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp46y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp46z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp47x]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp47y]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
	[./vp47z]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.0
	[../]
 
 	[./vp48x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp48y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp48z]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
 	[./vp49x]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp49y]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./vp49z]
 		order = CONSTANT
 		family = MONOMIAL
 		initial_condition = 0.0
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
 
	[./N40_IC]
 		type = CARDINAL_CloudIC
        variable = N40
        x_center = 5000
        y_center = 5000
        local_size_index = 40
        cardinal_object = cardinal
    [../]
 
 	[./N41_IC]
 		type = CARDINAL_CloudIC
 		variable = N41
        x_center = 5000
        y_center = 5000
 		local_size_index = 41
 		cardinal_object = cardinal
 	[../]
 
 	[./N42_IC]
 		type = CARDINAL_CloudIC
 		variable = N42
        x_center = 5000
        y_center = 5000
 		local_size_index = 42
 		cardinal_object = cardinal
 	[../]
 
 	[./N43_IC]
 		type = CARDINAL_CloudIC
 		variable = N43
        x_center = 5000
        y_center = 5000
 		local_size_index = 43
 		cardinal_object = cardinal
 	[../]
 
 	[./N44_IC]
 		type = CARDINAL_CloudIC
 		variable = N44
        x_center = 5000
        y_center = 5000
 		local_size_index = 44
 		cardinal_object = cardinal
 	[../]
 
    [./N45_IC]
 		type = CARDINAL_CloudIC
        variable = N45
        x_center = 5000
        y_center = 5000
        local_size_index = 45
        cardinal_object = cardinal
    [../]
 
 	[./N46_IC]
 		type = CARDINAL_CloudIC
 		variable = N46
        x_center = 5000
        y_center = 5000
 		local_size_index = 46
 		cardinal_object = cardinal
 	[../]
 
 	[./N47_IC]
 		type = CARDINAL_CloudIC
 		variable = N47
        x_center = 5000
        y_center = 5000
 		local_size_index = 47
 		cardinal_object = cardinal
 	[../]
 
 	[./N48_IC]
 		type = CARDINAL_CloudIC
 		variable = N48
        x_center = 5000
        y_center = 5000
 		local_size_index = 48
 		cardinal_object = cardinal
 	[../]
 
 	[./N49_IC]
 		type = CARDINAL_CloudIC
 		variable = N49
        x_center = 5000
        y_center = 5000
 		local_size_index = 49
 		cardinal_object = cardinal
 	[../]

[] #END ICs

[Kernels]

    [./N0_dot]
        type = CoefTimeDerivative
        variable = N0
        Coefficient = 1.0
    [../]
 
    [./N0_MPB_Agg]
        type = CoagulationMonoPB
        variable = N0
        main_variable = N0
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]
 
    [./N0_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N0
 		main_variable = N0
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]

 	[./N1_dot]
 		type = CoefTimeDerivative
 		variable = N1
 		Coefficient = 1.0
 	[../]
 
    [./N1_MPB_Agg]
        type = CoagulationMonoPB
        variable = N1
        main_variable = N1
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N1_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N1
 		main_variable = N1
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
    [./N2_dot]
 		type = CoefTimeDerivative
 		variable = N2
 		Coefficient = 1.0
 	[../]

    [./N2_MPB_Agg]
        type = CoagulationMonoPB
        variable = N2
        main_variable = N2
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N2_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N2
 		main_variable = N2
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N3_dot]
 		type = CoefTimeDerivative
 		variable = N3
 		Coefficient = 1.0
 	[../]

    [./N3_MPB_Agg]
        type = CoagulationMonoPB
        variable = N3
        main_variable = N3
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]
 
    [./N3_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N3
 		main_variable = N3
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N4_dot]
 		type = CoefTimeDerivative
 		variable = N4
 		Coefficient = 1.0
 	[../]

    [./N4_MPB_Agg]
        type = CoagulationMonoPB
        variable = N4
        main_variable = N4
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N4_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N4
 		main_variable = N4
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
    [./N5_dot]
        type = CoefTimeDerivative
        variable = N5
        Coefficient = 1.0
    [../]

    [./N5_MPB_Agg]
        type = CoagulationMonoPB
        variable = N5
        main_variable = N5
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N5_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N5
 		main_variable = N5
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N6_dot]
 		type = CoefTimeDerivative
 		variable = N6
 		Coefficient = 1.0
 	[../]

    [./N6_MPB_Agg]
        type = CoagulationMonoPB
        variable = N6
        main_variable = N6
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N6_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N6
 		main_variable = N6
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N7_dot]
 		type = CoefTimeDerivative
 		variable = N7
 		Coefficient = 1.0
 	[../]

    [./N7_MPB_Agg]
        type = CoagulationMonoPB
        variable = N7
        main_variable = N7
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N7_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N7
 		main_variable = N7
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N8_dot]
 		type = CoefTimeDerivative
 		variable = N8
 		Coefficient = 1.0
 	[../]

    [./N8_MPB_Agg]
        type = CoagulationMonoPB
        variable = N8
        main_variable = N8
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N8_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N8
 		main_variable = N8
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N9_dot]
 		type = CoefTimeDerivative
 		variable = N9
 		Coefficient = 1.0
 	[../]

    [./N9_MPB_Agg]
        type = CoagulationMonoPB
        variable = N9
        main_variable = N9
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N9_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N9
 		main_variable = N9
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
    [./N10_dot]
        type = CoefTimeDerivative
        variable = N10
        Coefficient = 1.0
    [../]

    [./N10_MPB_Agg]
        type = CoagulationMonoPB
        variable = N10
        main_variable = N10
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N10_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N10
 		main_variable = N10
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N11_dot]
 		type = CoefTimeDerivative
 		variable = N11
 		Coefficient = 1.0
 	[../]

    [./N11_MPB_Agg]
        type = CoagulationMonoPB
        variable = N11
        main_variable = N11
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N11_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N11
 		main_variable = N11
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N12_dot]
 		type = CoefTimeDerivative
 		variable = N12
 		Coefficient = 1.0
 	[../]

    [./N12_MPB_Agg]
        type = CoagulationMonoPB
        variable = N12
        main_variable = N12
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N12_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N12
 		main_variable = N12
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N13_dot]
 		type = CoefTimeDerivative
 		variable = N13
 		Coefficient = 1.0
 	[../]

    [./N13_MPB_Agg]
        type = CoagulationMonoPB
        variable = N13
        main_variable = N13
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N13_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N13
 		main_variable = N13
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N14_dot]
 		type = CoefTimeDerivative
 		variable = N14
 		Coefficient = 1.0
 	[../]

    [./N14_MPB_Agg]
        type = CoagulationMonoPB
        variable = N14
        main_variable = N14
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N14_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N14
 		main_variable = N14
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
    [./N15_dot]
        type = CoefTimeDerivative
        variable = N15
        Coefficient = 1.0
    [../]

    [./N15_MPB_Agg]
        type = CoagulationMonoPB
        variable = N15
        main_variable = N15
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N15_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N15
 		main_variable = N15
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N16_dot]
 		type = CoefTimeDerivative
 		variable = N16
 		Coefficient = 1.0
 	[../]

    [./N16_MPB_Agg]
        type = CoagulationMonoPB
        variable = N16
        main_variable = N16
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N16_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N16
 		main_variable = N16
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N17_dot]
 		type = CoefTimeDerivative
 		variable = N17
 		Coefficient = 1.0
 	[../]

    [./N17_MPB_Agg]
        type = CoagulationMonoPB
        variable = N17
        main_variable = N17
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N17_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N17
 		main_variable = N17
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N18_dot]
 		type = CoefTimeDerivative
 		variable = N18
 		Coefficient = 1.0
 	[../]

    [./N18_MPB_Agg]
        type = CoagulationMonoPB
        variable = N18
        main_variable = N18
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N18_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N18
 		main_variable = N18
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N19_dot]
 		type = CoefTimeDerivative
 		variable = N19
 		Coefficient = 1.0
 	[../]

    [./N19_MPB_Agg]
        type = CoagulationMonoPB
        variable = N19
        main_variable = N19
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N19_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N19
 		main_variable = N19
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]

    [./N20_dot]
        type = CoefTimeDerivative
        variable = N20
        Coefficient = 1.0
    [../]

    [./N20_MPB_Agg]
        type = CoagulationMonoPB
        variable = N20
        main_variable = N20
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N20_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N20
 		main_variable = N20
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]

 	[./N21_dot]
 		type = CoefTimeDerivative
 		variable = N21
 		Coefficient = 1.0
 	[../]

    [./N21_MPB_Agg]
        type = CoagulationMonoPB
        variable = N21
        main_variable = N21
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N21_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N21
 		main_variable = N21
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
    [./N22_dot]
 		type = CoefTimeDerivative
 		variable = N22
 		Coefficient = 1.0
 	[../]

    [./N22_MPB_Agg]
        type = CoagulationMonoPB
        variable = N22
        main_variable = N22
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N22_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N22
 		main_variable = N22
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N23_dot]
 		type = CoefTimeDerivative
 		variable = N23
 		Coefficient = 1.0
 	[../]

    [./N23_MPB_Agg]
        type = CoagulationMonoPB
        variable = N23
        main_variable = N23
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N23_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N23
 		main_variable = N23
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N24_dot]
 		type = CoefTimeDerivative
 		variable = N24
 		Coefficient = 1.0
 	[../]

    [./N24_MPB_Agg]
        type = CoagulationMonoPB
        variable = N24
        main_variable = N24
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N24_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N24
 		main_variable = N24
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
    [./N25_dot]
        type = CoefTimeDerivative
        variable = N25
        Coefficient = 1.0
    [../]

    [./N25_MPB_Agg]
        type = CoagulationMonoPB
        variable = N25
        main_variable = N25
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N25_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N25
 		main_variable = N25
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N26_dot]
 		type = CoefTimeDerivative
 		variable = N26
 		Coefficient = 1.0
 	[../]

    [./N26_MPB_Agg]
        type = CoagulationMonoPB
        variable = N26
        main_variable = N26
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N26_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N26
 		main_variable = N26
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N27_dot]
 		type = CoefTimeDerivative
 		variable = N27
 		Coefficient = 1.0
 	[../]
 
    [./N27_MPB_Agg]
        type = CoagulationMonoPB
        variable = N27
        main_variable = N27
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N27_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N27
 		main_variable = N27
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N28_dot]
 		type = CoefTimeDerivative
 		variable = N28
 		Coefficient = 1.0
 	[../]

    [./N28_MPB_Agg]
        type = CoagulationMonoPB
        variable = N28
        main_variable = N28
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N28_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N28
 		main_variable = N28
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N29_dot]
 		type = CoefTimeDerivative
 		variable = N29
 		Coefficient = 1.0
 	[../]

    [./N29_MPB_Agg]
        type = CoagulationMonoPB
        variable = N29
        main_variable = N29
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N29_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N29
 		main_variable = N29
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
    [./N30_dot]
        type = CoefTimeDerivative
        variable = N30
        Coefficient = 1.0
    [../]

    [./N30_MPB_Agg]
        type = CoagulationMonoPB
        variable = N30
        main_variable = N30
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N30_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N30
 		main_variable = N30
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]

 	[./N31_dot]
 		type = CoefTimeDerivative
 		variable = N31
 		Coefficient = 1.0
 	[../]

    [./N31_MPB_Agg]
        type = CoagulationMonoPB
        variable = N31
        main_variable = N31
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N31_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N31
 		main_variable = N31
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
    [./N32_dot]
 		type = CoefTimeDerivative
 		variable = N32
 		Coefficient = 1.0
 	[../]

    [./N32_MPB_Agg]
        type = CoagulationMonoPB
        variable = N32
        main_variable = N32
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N32_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N32
 		main_variable = N32
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N33_dot]
 		type = CoefTimeDerivative
 		variable = N33
 		Coefficient = 1.0
 	[../]

    [./N33_MPB_Agg]
        type = CoagulationMonoPB
        variable = N33
        main_variable = N33
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N33_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N33
 		main_variable = N33
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N34_dot]
 		type = CoefTimeDerivative
 		variable = N34
 		Coefficient = 1.0
 	[../]

    [./N34_MPB_Agg]
        type = CoagulationMonoPB
        variable = N34
        main_variable = N34
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]
 
    [./N34_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N34
 		main_variable = N34
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
    [./N35_dot]
        type = CoefTimeDerivative
        variable = N35
        Coefficient = 1.0
    [../]

    [./N35_MPB_Agg]
        type = CoagulationMonoPB
        variable = N35
        main_variable = N35
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N35_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N35
 		main_variable = N35
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N36_dot]
 		type = CoefTimeDerivative
 		variable = N36
 		Coefficient = 1.0
 	[../]

    [./N36_MPB_Agg]
        type = CoagulationMonoPB
        variable = N36
        main_variable = N36
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N36_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N36
 		main_variable = N36
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N37_dot]
 		type = CoefTimeDerivative
 		variable = N37
 		Coefficient = 1.0
 	[../]

    [./N37_MPB_Agg]
        type = CoagulationMonoPB
        variable = N37
        main_variable = N37
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N37_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N37
 		main_variable = N37
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N38_dot]
 		type = CoefTimeDerivative
 		variable = N38
 		Coefficient = 1.0
 	[../]

    [./N38_MPB_Agg]
        type = CoagulationMonoPB
        variable = N38
        main_variable = N38
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N38_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N38
 		main_variable = N38
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N39_dot]
 		type = CoefTimeDerivative
 		variable = N39
 		Coefficient = 1.0
 	[../]

    [./N39_MPB_Agg]
        type = CoagulationMonoPB
        variable = N39
        main_variable = N39
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N39_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N39
 		main_variable = N39
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
    [./N40_dot]
        type = CoefTimeDerivative
        variable = N40
        Coefficient = 1.0
    [../]

    [./N40_MPB_Agg]
        type = CoagulationMonoPB
        variable = N40
        main_variable = N40
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N40_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N40
 		main_variable = N40
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]

 	[./N41_dot]
 		type = CoefTimeDerivative
 		variable = N41
 		Coefficient = 1.0
 	[../]

    [./N41_MPB_Agg]
        type = CoagulationMonoPB
        variable = N41
        main_variable = N41
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N41_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N41
 		main_variable = N41
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
    [./N42_dot]
 		type = CoefTimeDerivative
 		variable = N42
 		Coefficient = 1.0
 	[../]

    [./N42_MPB_Agg]
        type = CoagulationMonoPB
        variable = N42
        main_variable = N42
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N42_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N42
 		main_variable = N42
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N43_dot]
 		type = CoefTimeDerivative
 		variable = N43
 		Coefficient = 1.0
 	[../]

    [./N43_MPB_Agg]
        type = CoagulationMonoPB
        variable = N43
        main_variable = N43
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N43_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N43
 		main_variable = N43
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N44_dot]
 		type = CoefTimeDerivative
 		variable = N44
 		Coefficient = 1.0
 	[../]

    [./N44_MPB_Agg]
        type = CoagulationMonoPB
        variable = N44
        main_variable = N44
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N44_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N44
 		main_variable = N44
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
    [./N45_dot]
        type = CoefTimeDerivative
        variable = N45
        Coefficient = 1.0
    [../]

    [./N45_MPB_Agg]
        type = CoagulationMonoPB
        variable = N45
        main_variable = N45
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N45_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N45
 		main_variable = N45
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N46_dot]
 		type = CoefTimeDerivative
 		variable = N46
 		Coefficient = 1.0
 	[../]

    [./N46_MPB_Agg]
        type = CoagulationMonoPB
        variable = N46
        main_variable = N46
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N46_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N46
 		main_variable = N46
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N47_dot]
 		type = CoefTimeDerivative
 		variable = N47
 		Coefficient = 1.0
 	[../]

    [./N47_MPB_Agg]
        type = CoagulationMonoPB
        variable = N47
        main_variable = N47
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N47_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N47
 		main_variable = N47
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N48_dot]
 		type = CoefTimeDerivative
 		variable = N48
 		Coefficient = 1.0
 	[../]

    [./N48_MPB_Agg]
        type = CoagulationMonoPB
        variable = N48
        main_variable = N48
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N48_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N48
 		main_variable = N48
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]
 
 	[./N49_dot]
 		type = CoefTimeDerivative
 		variable = N49
 		Coefficient = 1.0
 	[../]

    [./N49_MPB_Agg]
        type = CoagulationMonoPB
        variable = N49
        main_variable = N49
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
    [../]

    [./N49_MPB]
 		type = ShearMultiFragLinearMonoPB
 		variable = N49
 		main_variable = N49
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
	[../]

[] #END Kernels

[DGKernels]

[] #END DGKernels

[AuxKernels]

	[./Total_Volume]
		type = VolumeBalanceCheck
		variable = V_total
		coupled_vars = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
        execute_on = 'initial timestep_end'
	[../]
 
    [./ionization]
 		type = TotalAirIonization
        variable = air_ions
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
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
		particle_diameter = 1.0e-8
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
		particle_diameter = 1.0e-8
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
		particle_diameter = 1.0e-8
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
		particle_diameter = 1.27e-8
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
		particle_diameter = 1.27e-8
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
		particle_diameter = 1.27e-8
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
		particle_diameter = 1.60e-8
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
		particle_diameter = 1.60e-8
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
		particle_diameter = 1.60e-8
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
		particle_diameter = 2.02e-8
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
		particle_diameter = 2.02e-8
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
		particle_diameter = 2.02e-8
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
		particle_diameter = 2.56e-8
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
		particle_diameter = 2.56e-8
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
		particle_diameter = 2.56e-8
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
		particle_diameter = 3.24e-8
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
		particle_diameter = 3.24e-8
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
		particle_diameter = 3.24e-8
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
		particle_diameter = 4.10e-8
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
		particle_diameter = 4.10e-8
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
		particle_diameter = 4.10e-8
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
		particle_diameter = 5.18e-8
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
		particle_diameter = 5.18e-8
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
		particle_diameter = 5.18e-8
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
		particle_diameter = 6.56e-8
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
		particle_diameter = 6.56e-8
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
		particle_diameter = 6.56e-8
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
		particle_diameter = 8.29e-8
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
		particle_diameter = 8.29e-8
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
		particle_diameter = 8.29e-8
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
		particle_diameter = 1.05e-7
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
		particle_diameter = 1.05e-7
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
		particle_diameter = 1.05e-7
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
		particle_diameter = 1.33e-7
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
		particle_diameter = 1.33e-7
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
		particle_diameter = 1.33e-7
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
		particle_diameter = 2.12e-7
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
		particle_diameter = 2.12e-7
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
		particle_diameter = 2.12e-7
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
		particle_diameter = 2.69e-7
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
		particle_diameter = 2.69e-7
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
		particle_diameter = 2.69e-7
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
		particle_diameter = 3.40e-7
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
		particle_diameter = 3.40e-7
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
		particle_diameter = 3.40e-7
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
		particle_diameter = 4.30e-7
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
		particle_diameter = 4.30e-7
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
		particle_diameter = 4.30e-7
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
		particle_diameter = 5.44e-7
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
		particle_diameter = 5.44e-7
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
		particle_diameter = 5.44e-7
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
		particle_diameter = 6.88e-7
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
		particle_diameter = 6.88e-7
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
		particle_diameter = 6.88e-7
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
		particle_diameter = 8.70e-7
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
		particle_diameter = 8.70e-7
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
		particle_diameter = 8.70e-7
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
		particle_diameter = 1.10e-6
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
		particle_diameter = 1.10e-6
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
		particle_diameter = 1.10e-6
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
		particle_diameter = 1.39e-6
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
		particle_diameter = 1.39e-6
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
		particle_diameter = 1.39e-6
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
		particle_diameter = 1.76e-6
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
		particle_diameter = 1.76e-6
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
		particle_diameter = 1.76e-6
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
		particle_diameter = 2.23e-6
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
		particle_diameter = 2.23e-6
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
		particle_diameter = 2.23e-6
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
		particle_diameter = 2.82e-6
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
		particle_diameter = 2.82e-6
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
		particle_diameter = 2.82e-6
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
		particle_diameter = 3.57e-6
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
		particle_diameter = 3.57e-6
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
		particle_diameter = 3.57e-6
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
		particle_diameter = 4.51e-6
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
		particle_diameter = 4.51e-6
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
		particle_diameter = 4.51e-6
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
		particle_diameter = 5.71e-6
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
		particle_diameter = 5.71e-6
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
		particle_diameter = 5.71e-6
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
		particle_diameter = 7.22e-6
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
		particle_diameter = 7.22e-6
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
		particle_diameter = 7.22e-6
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
		particle_diameter = 9.13e-6
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
		particle_diameter = 9.13e-6
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
		particle_diameter = 9.13e-6
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
		particle_diameter = 1.16e-5
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
		particle_diameter = 1.16e-5
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
		particle_diameter = 1.16e-5
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
		particle_diameter = 1.46e-5
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
		particle_diameter = 1.46e-5
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
		particle_diameter = 1.46e-5
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
		particle_diameter = 1.85e-5
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
		particle_diameter = 1.85e-5
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
		particle_diameter = 1.85e-5
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
		particle_diameter = 2.34e-5
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
		particle_diameter = 2.34e-5
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
		particle_diameter = 2.34e-5
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
		particle_diameter = 2.96e-5
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
		particle_diameter = 2.96e-5
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
		particle_diameter = 2.96e-5
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
		particle_diameter = 3.74e-5
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
		particle_diameter = 3.74e-5
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
		particle_diameter = 3.74e-5
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
		particle_diameter = 4.73e-5
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
		particle_diameter = 4.73e-5
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
		particle_diameter = 4.73e-5
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
		particle_diameter = 5.99e-5
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
		particle_diameter = 5.99e-5
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
		particle_diameter = 5.99e-5
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
		particle_diameter = 7.58e-5
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
		particle_diameter = 7.58e-5
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
		particle_diameter = 7.58e-5
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
		particle_diameter = 9.58e-5
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
		particle_diameter = 9.58e-5
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
		particle_diameter = 9.58e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
    [./part_vel_40x]
		type = Trajectory1stOrder
		variable = vp40x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp40x
		vary = vp40y
		varz = vp40z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.21e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_40y]
		type = Trajectory1stOrder
		variable = vp40y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp40x
		vary = vp40y
		varz = vp40z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.21e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_40z]
		type = Trajectory1stOrder
		variable = vp40z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp40x
		vary = vp40y
		varz = vp40z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.21e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_41x]
		type = Trajectory1stOrder
		variable = vp41x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp41x
		vary = vp41y
		varz = vp41z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.53e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_41y]
		type = Trajectory1stOrder
		variable = vp41y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp41x
		vary = vp41y
		varz = vp41z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.53e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_41z]
		type = Trajectory1stOrder
		variable = vp41z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp41x
		vary = vp41y
		varz = vp41z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.53e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_42x]
		type = Trajectory1stOrder
		variable = vp42x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp42x
		vary = vp42y
		varz = vp42z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.94e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_42y]
		type = Trajectory1stOrder
		variable = vp42y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp42x
		vary = vp42y
		varz = vp42z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.94e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_42z]
		type = Trajectory1stOrder
		variable = vp42z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp42x
		vary = vp42y
		varz = vp42z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.94e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_43x]
		type = Trajectory1stOrder
		variable = vp43x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp43x
		vary = vp43y
		varz = vp43z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.45e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_43y]
		type = Trajectory1stOrder
		variable = vp43y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp43x
		vary = vp43y
		varz = vp43z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.45e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_43z]
		type = Trajectory1stOrder
		variable = vp43z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp43x
		vary = vp43y
		varz = vp43z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 2.45e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_44x]
		type = Trajectory1stOrder
		variable = vp44x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp44x
		vary = vp44y
		varz = vp44z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 3.10e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_44y]
		type = Trajectory1stOrder
		variable = vp44y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp44x
		vary = vp44y
		varz = vp44z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 3.10e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_44z]
		type = Trajectory1stOrder
		variable = vp44z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp44x
		vary = vp44y
		varz = vp44z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 3.10e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
    [./part_vel_45x]
		type = Trajectory1stOrder
		variable = vp45x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp45x
		vary = vp45y
		varz = vp45z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 3.93e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_45y]
		type = Trajectory1stOrder
		variable = vp45y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp45x
		vary = vp45y
		varz = vp45z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 3.93e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_45z]
		type = Trajectory1stOrder
		variable = vp45z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp45x
		vary = vp45y
		varz = vp45z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 3.93e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_46x]
		type = Trajectory1stOrder
		variable = vp46x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp46x
		vary = vp46y
		varz = vp46z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 4.97e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_46y]
		type = Trajectory1stOrder
		variable = vp6y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp46x
		vary = vp46y
		varz = vp46z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 4.97e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_46z]
		type = Trajectory1stOrder
		variable = vp46z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp46x
		vary = vp46y
		varz = vp46z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 4.97e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_47x]
		type = Trajectory1stOrder
		variable = vp47x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp47x
		vary = vp47y
		varz = vp47z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 6.28e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_47y]
		type = Trajectory1stOrder
		variable = vp47y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp47x
		vary = vp47y
		varz = vp47z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 6.28e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_47z]
		type = Trajectory1stOrder
		variable = vp47z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp47x
		vary = vp47y
		varz = vp47z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 6.28e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_48x]
		type = Trajectory1stOrder
		variable = vp48x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp48x
		vary = vp48y
		varz = vp48z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 7.95e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_48y]
		type = Trajectory1stOrder
		variable = vp48y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp48x
		vary = vp48y
		varz = vp48z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 7.95e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_48z]
		type = Trajectory1stOrder
		variable = vp48z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp48x
		vary = vp48y
		varz = vp48z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 7.95e-4
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

	[./part_vel_49x]
		type = Trajectory1stOrder
		variable = vp49x
		direction = 0
		windx = wx
		windy = wy
		windz = wz
		varx = vp49x
		vary = vp49y
		varz = vp49z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.01e-3
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_49y]
		type = Trajectory1stOrder
		variable = vp49y
		direction = 1
		windx = wx
		windy = wy
		windz = wz
		varx = vp49x
		vary = vp49y
		varz = vp49z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.01e-3
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
	[./part_vel_49z]
		type = Trajectory1stOrder
		variable = vp49z
		direction = 2
		windx = wx
		windy = wy
		windz = wz
		varx = vp49x
		vary = vp49y
		varz = vp49z
		air_density = air_dens
		air_viscosity = air_visc
		particle_diameter = 1.01e-3
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]
 
[] #END AuxKernels

[BCs]

[] #END BCs

[Materials]

	[./CollisionParams]
 		type = CollisionParameters
        block = 0
        cardinal_object = cardinal
        coupled_conc = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49'
        air_density = air_dens
        air_viscosity = air_visc
        temperature = air_temp
        ionization = air_ions
        windx = wx
        windy = wy
        windz = wz
        coupled_vx = 'vp0x vp1x vp2x vp3x vp4x vp5x vp6x vp7x vp8x vp9x vp10x vp11x vp12x vp13x vp14x vp15x vp16x vp17x vp18x vp19x vp20x vp21x vp22x vp23x vp24x vp25x vp26x vp27x vp28x vp29x vp30x vp31x vp32x vp33x vp34x vp35x vp36x vp37x vp38x vp39x vp40x vp41x vp42x vp43x vp44x vp45x vp46x vp47x vp48x vp49x'
        coupled_vy = 'vp0y vp1y vp2y vp3y vp4y vp5y vp6y vp7y vp8y vp9y vp10y vp11y vp12y vp13y vp14y vp15y vp16y vp17y vp18y vp19y vp20y vp21y vp22y vp23y vp24y vp25y vp26y vp27y vp28y vp29y vp30y vp31y vp32y vp33y vp34y vp35y vp36y vp37y vp38y vp39y vp40y vp41y vp42y vp43y vp44y vp45y vp46y vp47y vp48y vp49y'
        coupled_vz = 'vp0z vp1z vp2z vp3z vp4z vp5z vp6z vp7z vp8z vp9z vp10z vp11z vp12z vp13z vp14z vp15z vp16z vp17z vp18z vp19z vp20z vp21z vp22z vp23z vp24z vp25z vp26z vp27z vp28z vp29z vp30z vp31z vp32z vp33z vp34z vp35z vp36z vp37z vp38z vp39z vp40z vp41z vp42z vp43z vp44z vp45z vp46z vp47z vp48z vp49z'
    [../]

[] #END Materials

[UserObjects]

	[./cardinal]
 		type = CARDINAL_Object
 		execute_on = 'initial timestep_end'
 		input_file = 'input_files/cardinal/50-Bin-StandardYield.txt'
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

	[./N40]
		type = ElementAverageValue
		variable = N40
		execute_on = 'initial timestep_end'
	[../]
 
	[./N41]
		type = ElementAverageValue
		variable = N41
		execute_on = 'initial timestep_end'
	[../]
 
 	[./N42]
 		type = ElementAverageValue
 		variable = N42
		 execute_on = 'initial timestep_end'
	[../]
 
 	[./N43]
 		type = ElementAverageValue
 		variable = N43
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./N44]
 		type = ElementAverageValue
 		variable = N44
 		execute_on = 'initial timestep_end'
	[../]
 
    [./N45]
		type = ElementAverageValue
		variable = N45
		execute_on = 'initial timestep_end'
	[../]
 
	[./N46]
		type = ElementAverageValue
		variable = N46
		execute_on = 'initial timestep_end'
	[../]
 
 	[./N47]
 		type = ElementAverageValue
 		variable = N47
        execute_on = 'initial timestep_end'
	[../]
 
 	[./N48]
 		type = ElementAverageValue
 		variable = N48
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./N49]
 		type = ElementAverageValue
 		variable = N49
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
	end_time = 120000.0
    dtmax = 200.0

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
