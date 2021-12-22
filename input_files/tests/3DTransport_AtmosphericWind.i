#Incomplete Input File, Fully Update after text file for data is ready

[GlobalParams]

	diameters = '1.0e-5'

[] #END GlobalParams

[Problem]

[] #END Problem

[Mesh]

    type = GeneratedMesh
    dim = 3
	nx = 200
	ny = 200
	nz = 10
    xmin = 0.0
    xmax = 200000.0
    ymin = 0.0
    ymax = 200000.0
	zmin = 0.0
	zmax = 10000.0

[] # END Mesh

[Variables]

    [./N0]
        order = CONSTANT
        family = MONOMIAL
    [../]
 
[] #END Variables

[AuxVariables]
 
	[./V_total]
 		order = CONSTANT
 		family = MONOMIAL
	[../]

    [./N_total]
 		order = CONSTANT
 		family = MONOMIAL
	[../]
 
    [./wx]
		order = CONSTANT
		family = MONOMIAL
	[../]
 
	[./wy]
		order = CONSTANT
		family = MONOMIAL
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

[] #END AuxVariables

[ICs]

	[./N0_IC]
		type = CARDINAL_CloudIC
		variable = N0
		x_center = 10000
		y_center = 150000
		local_size_index = 0
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
 
[] #END DGKernels

[AuxKernels]

	[./Total_Volume]
		type = VolumeBalanceCheck
		variable = V_total
		coupled_vars = 'N0'
        execute_on = 'initial timestep_end'
	[../]

    [./N_accumulated]
 		type = AccumulatedMaterial
 		variable = N_total
 		coupled_vars = 'N0'
 		vxs = 'vp0x'
 		vys = 'vp0y'
 		vzs = 'vp0z'
 		execute_on = 'initial timestep_end'
	[../]

	[./wx_aux]
		type = FunctionAux
        function = wx_vel
		variable = wx
	[../]

	[./wy_aux]
		type = FunctionAux
		function = wy_vel
		variable = wy
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
		particle_diameter = 1.0e-5
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
		particle_diameter = 1.0e-5
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
		particle_diameter = 1.0e-5
		particle_density = 2600.0
		execute_on = 'initial timestep_end'
	[../]

[] #END AuxKernels

[Functions]

    [./wx_vel]
    	type = PiecewiseMultilinear
        data_file = XWindProfileTest_Original.txt
    [../]

    [./wy_vel]
    	type = PiecewiseMultilinear
        data_file = YWindProfileTest_Original.txt
    [../]

[] #END Functions

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

    [./Total_Volume]
        type = ElementAverageValue
        variable = V_total
        execute_on = 'initial timestep_begin timestep_end'
    [../]
 
	[./N0]
		type = ElementAverageValue
		variable = N0
		execute_on = 'initial timestep_end'
	[../]

    [./N_floor]
		type = SideAverageValue
		boundary = 'bottom'
		variable = N_total
		execute_on = 'initial timestep_end'
	[../]
 
[] #END Postprocessors

[Preconditioning]
  [./SMP_PJFNK]
    type = SMP
    full = true
    solve_type = pjfnk   #default to newton, but use pjfnk if newton too slow
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
                        -pc_asm_overlap

                        -snes_atol
                        -snes_rtol

                        -ksp_ksp_type
                        -ksp_pc_type'

  	# snes_max_it = maximum non-linear steps
  	petsc_options_value = 'fgmres
                         ksp

                         lu

                         10
                         NONZERO
                         10
                         1E-8
                         1E-10

                         gmres
                         ilu'

  	#NOTE: turning off line search can help converge for high Renolds number
  	line_search = bt
  	nl_rel_tol = 1e-10
  	nl_abs_tol = 1e-8
  	nl_rel_step_tol = 1e-10
  	nl_abs_step_tol = 1e-8
  	nl_max_its = 10
  	l_tol = 1e-6
  	l_max_its = 100

	start_time = 0.0
	end_time = 10000.0
	dtmax = 500.0

  	[./TimeStepper]
		type = SolutionTimeAdaptiveDT
#		type = ConstantDT
		dt = 500.0
  	[../]
[] #END Executioner

[Outputs]
  print_linear_residuals = true
  exodus = true
  csv = true
[] #END Outputs

