[GlobalParams]

	vx = 0.0
	vy = 0.0
	vz = 0.0
 	# Diameters are in um here. Kernels usually want units in m.
	diameters = '0.005 0.01 0.02 0.04 0.08 0.16 0.32 0.64 1.28 2.56 5.12 10.24 20.48 40.96 81.92'
    breakup_coefficient = 0.1

[] #END GlobalParams

[Problem]

[] #END Problem

[Mesh]

	type = GeneratedMesh
	dim = 1
	nx = 1
	xmin = 0.0
	xmax = 1.0

[] # END Mesh

[Variables]

	[./N0]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0
	[../]

	[./N1]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0
	[../]
 
	[./N2]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
	[../]
 
 	[./N3]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
	[../]
 
	[./N4]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
	[../]
 
	[./N5]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0
	[../]

	[./N6]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0
	[../]
 
	[./N7]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
	[../]
 
 	[./N8]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
	[../]
 
	[./N9]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
	[../]
 
	[./N10]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0
	[../]

	[./N11]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0
	[../]
 
	[./N12]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
	[../]
 
 	[./N13]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
	[../]
 
	[./N14]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 10.0
	[../]
 
[] #END Variables

[AuxVariables]

	[./V_total]
 		order = FIRST
 		family = MONOMIAL
	[../]
	
[] #END AuxVariables

[ICs]

[] #END ICs

[Kernels]

	[./N0_dot]
		type = CoefTimeDerivative
		variable = N0
		Coefficient = 1.0
	[../]

	[./N0_MPB]
		type = UniformBinaryMonoPB
		variable = N0
		main_variable = N0
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14'
	[../]

	[./N1_dot]
		type = CoefTimeDerivative
		variable = N1
		Coefficient = 1.0
	[../]

	[./N1_MPB]
		type = UniformBinaryMonoPB
		variable = N1
		main_variable = N1
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14'
	[../]
 
	[./N2_dot]
 		type = CoefTimeDerivative
 		variable = N2
 		Coefficient = 1.0
	[../]
 
	[./N2_MPB]
 		type = UniformBinaryMonoPB
 		variable = N2
		 main_variable = N2
 		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14'
	[../]
 
 	[./N3_dot]
		type = CoefTimeDerivative
		variable = N3
		Coefficient = 1.0
	[../]

	[./N3_MPB]
		type = UniformBinaryMonoPB
		variable = N3
		main_variable = N3
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14'
	[../]

	[./N4_dot]
		type = CoefTimeDerivative
		variable = N4
		Coefficient = 1.0
	[../]

	[./N4_MPB]
		type = UniformBinaryMonoPB
		variable = N4
		main_variable = N4
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14'
	[../]
 
	[./N5_dot]
 		type = CoefTimeDerivative
 		variable = N5
 		Coefficient = 1.0
	[../]
 
	[./N5_MPB]
 		type = UniformBinaryMonoPB
 		variable = N5
		 main_variable = N5
 		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14'
	[../]

	[./N6_dot]
		type = CoefTimeDerivative
		variable = N6
		Coefficient = 1.0
	[../]

	[./N6_MPB]
		type = UniformBinaryMonoPB
		variable = N6
		main_variable = N6
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14'
	[../]

	[./N7_dot]
		type = CoefTimeDerivative
		variable = N7
		Coefficient = 1.0
	[../]

	[./N7_MPB]
		type = UniformBinaryMonoPB
		variable = N7
		main_variable = N7
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14'
	[../]
 
	[./N8_dot]
 		type = CoefTimeDerivative
 		variable = N8
 		Coefficient = 1.0
	[../]
 
	[./N8_MPB]
 		type = UniformBinaryMonoPB
 		variable = N8
		 main_variable = N8
 		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14'
	[../]
 
 	[./N9_dot]
		type = CoefTimeDerivative
		variable = N9
		Coefficient = 1.0
	[../]

	[./N9_MPB]
		type = UniformBinaryMonoPB
		variable = N9
		main_variable = N9
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14'
	[../]

	[./N10_dot]
		type = CoefTimeDerivative
		variable = N10
		Coefficient = 1.0
	[../]

	[./N10_MPB]
		type = UniformBinaryMonoPB
		variable = N10
		main_variable = N10
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14'
	[../]
 
	[./N11_dot]
 		type = CoefTimeDerivative
 		variable = N11
 		Coefficient = 1.0
	[../]
 
	[./N11_MPB]
 		type = UniformBinaryMonoPB
 		variable = N11
		 main_variable = N11
 		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14'
	[../]
 
 	[./N12_dot]
 		type = CoefTimeDerivative
 		variable = N12
 		Coefficient = 1.0
	[../]
 
	[./N12_MPB]
		type = UniformBinaryMonoPB
		variable = N12
		main_variable = N12
		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14'
	[../]
 
	[./N13_dot]
 		type = CoefTimeDerivative
 		variable = N13
 		Coefficient = 1.0
	[../]
 
	[./N13_MPB]
 		type = UniformBinaryMonoPB
 		variable = N13
		 main_variable = N13
 		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14'
	[../]
 
   	[./N14_dot]
 		type = CoefTimeDerivative
 		variable = N14
 		Coefficient = 1.0
	[../]
 
	[./N14_MPB]
 		type = UniformBinaryMonoPB
 		variable = N14
		 main_variable = N14
 		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14'
	[../]
 
[] #END Kernels

[DGKernels]

[] #END DGKernels

[AuxKernels]

	[./Total_Volume]
 		type = VolumeBalanceCheck
 		variable = V_total
 		coupled_vars = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14'
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
 
    [./N3_Flux]
		type = DGFluxBC
		variable = N3
		boundary = 'left right'
		u_input = 0.0
	[../]

	[./N4_Flux]
		type = DGFluxBC
		variable = N4
		boundary = 'left right'
		u_input = 0.0
	[../]

	[./N5_Flux]
 		type = DGFluxBC
 		variable = N5
        boundary = 'left right'
 		u_input = 0.0
 	[../]
 
    [./N6_Flux]
		type = DGFluxBC
		variable = N6
		boundary = 'left right'
		u_input = 0.0
	[../]

	[./N7_Flux]
		type = DGFluxBC
		variable = N7
		boundary = 'left right'
		u_input = 0.0
	[../]

	[./N8_Flux]
 		type = DGFluxBC
 		variable = N8
        boundary = 'left right'
 		u_input = 0.0
 	[../]
 
    [./N9_Flux]
		type = DGFluxBC
		variable = N9
		boundary = 'left right'
		u_input = 0.0
	[../]

	[./N10_Flux]
		type = DGFluxBC
		variable = N10
		boundary = 'left right'
		u_input = 0.0
	[../]

	[./N11_Flux]
 		type = DGFluxBC
 		variable = N11
        boundary = 'left right'
 		u_input = 0.0
 	[../]
 
    [./N12_Flux]
		type = DGFluxBC
		variable = N12
		boundary = 'left right'
		u_input = 0.0
	[../]

	[./N13_Flux]
		type = DGFluxBC
		variable = N13
		boundary = 'left right'
		u_input = 0.0
	[../]

	[./N14_Flux]
 		type = DGFluxBC
 		variable = N14
        boundary = 'left right'
 		u_input = 0.0
 	[../]

[] #END BCs

[Materials]


[] #END Materials

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
 
	[./V_total]
 		type = ElementAverageValue
 		variable = V_total
 		execute_on = 'initial timestep_end'
	[../]

[] #END Postprocessors

[Executioner]

	type = Transient
	scheme = bdf2

	# NOTE: The default tolerances are far to strict and cause the program to crawl
 	nl_rel_tol = 1e-10
 	nl_abs_tol = 1e-8
 	nl_rel_step_tol = 1e-10
 	nl_abs_step_tol = 1e-10
 	l_tol = 1e-10
 	l_max_its = 200
 	nl_max_its = 20

	solve_type = pjfnk
	line_search = bt    # Options: default shell none basic l2 bt cp
	start_time = 0.0
	end_time = 60.0
	dtmax = 0.5
	petsc_options_iname = '-pc_type -pc_hypre_type -ksp_gmres_restart'
	petsc_options_value = 'hypre boomeramg 100'

	[./TimeStepper]
		#		type = SolutionTimeAdaptiveDT
		type = ConstantDT
		dt = 0.25
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
	print_linear_residuals = true

[] #END Outputs
