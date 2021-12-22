#Incomplete Input File, Fully Update after text file for data is ready

[GlobalParams]

[] #END GlobalParams

[Problem]

[] #END Problem

[Mesh]

    [gen]
    	type = GeneratedMeshGenerator
    	dim = 3
		nx = 1
		ny = 1
		nz = 2
    	xmin = 0.0
    	xmax = 1.0
    	ymin = 0.0
    	ymax = 1.0
		zmin = 0.0
		zmax = 2.0
	[]

	[./subdomain1]
		input = gen
        type = SubdomainBoundingBoxGenerator
        bottom_left = '0 0 0'
        top_right = '1 1 1'
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
        initial_condition = 0.0
        block = 0
    [../]

    [./N0g]
        order = CONSTANT
        family = MONOMIAL
        initial_condition = 10000.0
        block = 1
    [../]

[] #END Variables

[AuxVariables]

	[./wx]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 46.60952
        block = 0
	[../]

	[./center_height]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.5
        block = 0
	[../]

	[./rough_height]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 0.001
        block = 0
	[../]

    [./air_dens]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 1.225
        block = 0
	[../]

	[./air_kin_visc]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 1.470e-5
        block = 0
	[../]

    [./asperity_lever]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 1.666666667e-8
        block = 0
	[../]

	[./friction_vel]
		order = CONSTANT
		family = MONOMIAL
        block = 0
	[../]

	[./res_frequency]
		order = CONSTANT
		family = MONOMIAL
        block = 0
	[../]

	[./N0_diam]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 5.0e-6
        block = 0
	[../]

    [./N0_act_adh_force]
		order = CONSTANT
		family = MONOMIAL
        initial_condition = 5.16e-7
		block = 0
	[../]

	[./N0_adh_std]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 1.18e-7
		block = 0
	[../]

	[./N0_dens]
		order = CONSTANT
		family = MONOMIAL
		initial_condition = 2500.0
        block = 0
	[../]

	[./N0_resus_rate]
		order = CONSTANT
		family = MONOMIAL
        block = 0
	[../]

	[./N0_aero_force]
		order = CONSTANT
		family = MONOMIAL
		block = 0
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

    [./N0g_dot]
        type = CoefTimeDerivative
        variable = N0g
        Coefficient = 1.0
        block = 1
    [../]

[] #END Kernels

[DGKernels]

[] #END DGKernels

[InterfaceKernels]

	[./interface_resuspension]
		type = InterfacialResuspension
		variable = N0
        neighbor_var = N0g
		boundary = master_interface
        lamda = N0_resus_rate
	[../]

[] #END InterfaceKernels

[AuxKernels]

	[./friction_velocity_semilog]
		type = SemilogFrictionVelocity
		variable = friction_vel
        centerline_velocity = 'wx'
        centerline_height = 'center_height'
        roughness_height = 'rough_height'
        execute_on = 'initial timestep_end'
	[../]

	[./mean_aerodynamic_force]
		type = HallAerodynamicForce
		variable = N0_aero_force
		air_density = 'air_dens'
        kinematic_viscosity = 'air_kin_visc'
		aerosol_diameter = 'N0_diam'
		friction_velocity = 'friction_vel'
        lever_arm = 'asperity_lever'
		execute_on = 'initial timestep_end'
	[../]

	[./typical_resonance_frequency]
		type = ReeksResonanceFrequency
		variable = res_frequency
		kinematic_viscosity = 'air_kin_visc'
        friction_velocity = 'friction_vel'
		execute_on = 'initial timestep_end'
	[../]

	[./resuspension_rate_N0]
		type = LogNormalAdhesionResuspension
		variable = N0_resus_rate
		resonance_frequency = 'res_frequency'
        mean_adhesion_force = 'N0_act_adh_force'
        std_adhesion = 'N0_adh_std'
		aerodynamic_force = 'N0_aero_force'
		aerosol_diameter = 'N0_diam'
        aerosol_density = 'N0_dens'
        adhesion_range = '10.0e-6'
        adhesion_bins = '1000'
		execute_on = 'initial timestep_end'
	[../]

[] #END AuxKernels

[Functions]

[] #END Functions

[BCs]

[] #END BCs

[Materials]

[] #END Materials

[UserObjects]

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

    [./N0_resuspension]
		type = ElementAverageValue
		variable = N0_resus_rate
		execute_on = 'initial timestep_end'
        block = 0
	[../]

    [./N0_pull_off_force]
		type = ElementAverageValue
		variable = N0_aero_force
		execute_on = 'initial timestep_end'
        block = 0
	[../]

    [./N0_friction_velocity]
		type = ElementAverageValue
		variable = friction_vel
		execute_on = 'initial timestep_end'
        block = 0
	[../]

    [./N0_resonance_frequency]
		type = ElementAverageValue
		variable = res_frequency
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
	end_time = 0.01
    dtmax = 1.0

    [./TimeStepper]
#		type = SolutionTimeAdaptiveDT
		type = ConstantDT
        dt = 1.0e-4
    [../]
[] #END Executioner
 
[Adaptivity]

[] #END Adaptivity

[Outputs]

    exodus = true
    csv = true
    print_linear_residuals = false

[] #END Outputs
 
