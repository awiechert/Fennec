[GlobalParams]

 	vx = 0.0
	vy = 0.0
 	vz = 0.0
 
 	# Diameters are in um here. Kernels usually want units in m.
    diameters = '0.001 0.1 10.0'

[] #END GlobalParams

[Problem]

[] #END Problem

[Mesh]

    type = GeneratedMesh
    dim = 3
 	nx = 1
	ny = 1
	nz = 1
 	xmin = -4000.0
 	xmax = 4000.0
 	ymin = -4000.0
 	ymax = 4000.0
	zmin = 7500.0
	zmax = 8500.0

[] # END Mesh

[Variables]
# Units: GGp/m^3 (Billion-Billion particles per cubic meter)
# NOTE: Must be cautious of the units you use for the variables. Bad unit basis can make convergence difficult.
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

 	[./CoTest]  #Variable is exclusively for testing purposes
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0.0
	[../]
 
	[./V_total]
		order = FIRST
		family = MONOMIAL
	[../]
 
 	[./N_total]
 		order = FIRST
 		family = MONOMIAL
	[../]
 
	[./N_avg]
 		order = FIRST
 		family = MONOMIAL
	[../]
 
 	[./air_dens]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 1.225 #kg/m^3
	[../]
 
 	[./air_ions]
 		order = FIRST
 		family = MONOMIAL
	[../]
 
 	[./air_visc]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 1.802e-5 #kg/m/s
	[../]
 
 	[./air_temp]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 298 #K
	[../]
 
 	[./wx]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0.0
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
 		initial_condition = -0.00045
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
 		initial_condition = -0.0025
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
 		initial_condition = -0.0045
	[../]
 
[] #END AuxVariables

[ICs]

	[./N0_IC]
 		type = CARDINAL_CloudIC
        variable = N0
        x_center = 0
        y_center = 0
        local_size_index = 0
        cardinal_object = cardinal
    [../]
 
 	[./N1_IC]
 		type = CARDINAL_CloudIC
 		variable = N1
 		x_center = 0
 		y_center = 0
 		local_size_index = 1
 		cardinal_object = cardinal
 	[../]
 
 	[./N2_IC]
 		type = CARDINAL_CloudIC
 		variable = N2
 		x_center = 0
 		y_center = 0
 		local_size_index = 2
 		cardinal_object = cardinal
 	[../]
 
[] #END ICs

[Kernels]

    [./N0_dot]
        type = CoefTimeDerivative
        variable = N0
        Coefficient = 1.0
    [../]

    [./N0_MPB]
        type = CoagulationMonoPB
        variable = N0
        main_variable = N0
        coupled_list = 'N0 N1 N2'
    [../]
 
 	[./N1_dot]
 		type = CoefTimeDerivative
 		variable = N1
 		Coefficient = 1.0
 	[../]
 
 	[./N1_MPB]
 		type = CoagulationMonoPB
 		variable = N1
        main_variable = N1
 		coupled_list = 'N0 N1 N2'
 	[../]
 
 	[./N2_dot]
 		type = CoefTimeDerivative
 		variable = N2
 		Coefficient = 1.0
 	[../]
 
 	[./N2_MPB]
 		type = CoagulationMonoPB
 		variable = N2
 		main_variable = N2
 		coupled_list = 'N0 N1 N2'
    [../]
 
[] #END Kernels

[DGKernels]

[] #END DGKernels

[AuxKernels]

	[./testing]
 		type = CollisionTesting
        variable = CoTest
        conc = N0
        conc_other = N2
        execute_on = 'initial timestep_end'
    [../]

	[./Total_Volume]
		type = VolumeBalanceCheck
		variable = V_total
		coupled_vars = 'N0 N1 N2'
        execute_on = 'initial timestep_end'
	[../]
 
 	[./N_accumulated]
 		type = AccumulatedMaterial
 		variable = N_total
 		coupled_vars = 'N0 N1 N2'
 		vxs = 'vp0x vp1x vp2x'
 		vys = 'vp0y vp1y vp2y'
 		vzs = 'vp0z vp1z vp2z'
 		execute_on = 'initial timestep_end'
	[../]
 
	[./N_average]
 		type = AverageMaterial
 		variable = N_avg
		coupled_vars = 'N0 N1 N2'
 		execute_on = 'initial timestep_begin timestep_end'
	[../]
 
    [./ionization]
 		type = TotalAirIonization
        variable = air_ions
        coupled_list = 'N0 N1 N2'
        air_density = air_dens
        cardinal_object = cardinal
        background_ionization = 0.0
        execute_on = 'initial timestep_end'
    [../]

[] #END AuxKernels

[BCs]

 	[./N0_Flux]
 		type = DGFluxBC
 		variable = N0
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
 	[./N1_Flux]
 		type = DGFluxBC
 		variable = N1
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
 	[./N2_Flux]
 		type = DGFluxBC
 		variable = N2
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
[] #END BCs

[Materials]

	[./CollisionParams]
 		type = CollisionParameters
        block = 0
        cardinal_object = cardinal
        coupled_conc = 'N0 N1 N2'
        air_density = air_dens
        air_viscosity = air_visc
        temperature = air_temp
        ionization = air_ions
        windx = wx
        windy = wy
        windz = wz
        coupled_vx = 'vp0x vp1x vp2x'
        coupled_vy = 'vp0y vp1y vp2y'
        coupled_vz = 'vp0z vp1z vp2z'
    [../]

[] #END Materials

 
[UserObjects]
 
	[./cardinal]
 		type = CARDINAL_Object
 		execute_on = 'initial timestep_end'
 		input_file = 'input_files/cardinal/3-Bin-MassTest.txt'
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
 
	[./V_total]
		type = ElementAverageValue
		variable = V_total
		execute_on = 'initial timestep_end'
	[../]

[] #END Postprocessors

[Executioner]

    type = Transient
	scheme = implicit-euler    #use: 'implicit-euler' or 'bdf2'

    # NOTE: The default tolerances are far to strict and cause the program to crawl
    nl_rel_tol = 1e-14
    nl_abs_tol = 1e-8
    nl_rel_step_tol = 1e-10
    nl_abs_step_tol = 1e-10
    l_tol = 1e-10
    l_max_its = 200
    nl_max_its = 20

    solve_type = pjfnk
    line_search = bt    # Options: default shell none basic l2 bt cp
    start_time = 0.0
	end_time = 100.0
    dtmax = 0.5
    petsc_options_iname = '-pc_type -pc_hypre_type -ksp_gmres_restart'
    petsc_options_value = 'hypre boomeramg 100'

    [./TimeStepper]
		type = SolutionTimeAdaptiveDT
#		type = ConstantDT
        dt = 0.05
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
