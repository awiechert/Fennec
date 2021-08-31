#Incomplete Input File, Fully Update after text file for data is ready

[GlobalParams]

	Dxx = 0.01
    Dyy = 0.01
    Dzz = 0.01

[] #END GlobalParams

[Problem]

[] #END Problem

[Mesh]

    [gen]
    	type = GeneratedMeshGenerator
    	dim = 3
		nx = 40
		ny = 40
		nz = 41
    	xmin = 0.0
    	xmax = 10000.0
    	ymin = 0.0
    	ymax = 10000.0
		zmin = 0.0
		zmax = 10250.0
	[]

	[./subdomain1]
		input = gen
        type = SubdomainBoundingBoxGenerator
        bottom_left = '0 0 0'
        top_right = '10000 10000 250'
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

    [./N0g]
        order = CONSTANT
        family = MONOMIAL
        initial_condition = 0.0
        block = 1
    [../]

[] #END Variables

[AuxVariables]

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
		initial_condition = -0.1
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

    [./N0g_dot]
        type = CoefTimeDerivative
        variable = N0g
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

[] #END DGKernels

[InterfaceKernels]

	[./interface_diffusion]
		type = InterfacialAnisotropicDiffusion
		variable = N0
        neighbor_var = N0g
		boundary = master_interface
	[../]

	[./interface_advection]
		type = InterfaceAdvection
		variable = N0
        neighbor_var = N0g
		boundary = master_interface
		ux = vp0x
		uy = vp0y
		uz = vp0z
	[../]

[] #END InterfaceKernels

[AuxKernels]

[] #END AuxKernels

[Functions]

[] #END Functions

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

[] #END BCs

[Materials]

[] #END Materials

[UserObjects]

	[./cardinal]
 		type = CARDINAL_Object
 		execute_on = 'initial timestep_end'
 		input_file = 'input_files/cardinal/HartsfieldJackson-SingleBin.txt'
 		atm_file = 'input_files/cardinal/HartsfieldJacksonAtm.txt'
 		data_path = 'database/'
        mono_variate_population = true
 	[../]

[] #END UserObjects

[Postprocessors]
 
	[./N0]
		type = ElementAverageValue
		variable = N0
		execute_on = 'initial timestep_end'
        block = 0
	[../]

	[./N0g]
		type = ElementAverageValue
		variable = N0g
		execute_on = 'initial timestep_end'
        block = 1
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
    dtmax = 1000.0

    [./TimeStepper]
		type = SolutionTimeAdaptiveDT
#		type = ConstantDT
        dt = 50.0
    [../]
[] #END Executioner
 
[Adaptivity]

[] #END Adaptivity

[Outputs]

    exodus = true
    csv = true
    print_linear_residuals = false

[] #END Outputs
 
