[GlobalParams]

 	vx = 0.0
	vy = 0.0
 	vz = 0.0
 
 	diameters = '1 1.5 2'
 	total_nuclides = '1 2.5 4.5 7'

[] #END GlobalParams

[Problem]

[] #END Problem

[Mesh]

    type = GeneratedMesh
    dim = 1
	nx = 2
    xmin = 0.0
    xmax = 1.0

[] # END Mesh

[Variables]

 	[./Naa]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]

 	[./N01]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]

    [./N00]
        order = FIRST
        family = MONOMIAL
        initial_condition = 20
    [../]

 
 	[./N02]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N03]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N10]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 30
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
 
 	[./N20]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 20
 	[../]
 
 	[./N21]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N22]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
    [./N23]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]


[] #END Variables

[AuxVariables]
 
	[./N_total_vol]
		order = FIRST
		family = MONOMIAL
	[../]
 
 	[./N_total_nuc]
 		order = FIRST
 		family = MONOMIAL
	[../]

[] #END AuxVariables

[ICs]

[] #END ICs

[Kernels]

 	[./Naa_dot]
 		type = CoefTimeDerivative
 		variable = Naa
 		Coefficient = 0.0
 	[../]

    [./N00_dot]
        type = CoefTimeDerivative
        variable = N00
        Coefficient = 1.0
    [../]

    [./N00_MPB]
        type = ConstBiPB
        variable = N00
        main_variable = N00
        coupled_list = 'N00 N01 N02 N03 N10 N11 N12 N13 N20 N21 N22 N23'
    [../]
 
 	[./N01_dot]
 		type = CoefTimeDerivative
 		variable = N01
 		Coefficient = 1.0
 	[../]
 
 	[./N01_MPB]
 		type = ConstBiPB
 		variable = N01
        main_variable = N01
 		coupled_list = 'N00 N01 N02 N03 N10 N11 N12 N13 N20 N21 N22 N23'
 	[../]
 
 	[./N02_dot]
 		type = CoefTimeDerivative
 		variable = N02
 		Coefficient = 1.0
 	[../]
 
 	[./N02_MPB]
 		type = ConstBiPB
 		variable = N02
 		main_variable = N02
 		coupled_list = 'N00 N01 N02 N03 N10 N11 N12 N13 N20 N21 N22 N23'
    [../]
 
 	[./N10_dot]
 		type = CoefTimeDerivative
 		variable = N10
 		Coefficient = 1.0
 	[../]
 
 	[./N10_MPB]
 		type = ConstBiPB
 		variable = N10
 		main_variable = N10
 		coupled_list = 'N00 N01 N02 N03 N10 N11 N12 N13 N20 N21 N22 N23'
 	[../]
 
 	[./N11_dot]
 		type = CoefTimeDerivative
 		variable = N11
 		Coefficient = 1.0
 	[../]
 
 	[./N11_MPB]
 		type = ConstBiPB
 		variable = N11
 		main_variable = N11
 		coupled_list = 'N00 N01 N02 N03 N10 N11 N12 N13 N20 N21 N22 N23'
 	[../]
 
 	[./N12_dot]
 		type = CoefTimeDerivative
 		variable = N12
 		Coefficient = 1.0
    [../]
 
 	[./N12_MPB]
 		type = ConstBiPB
 		variable = N12
 		main_variable = N12
 		coupled_list = 'N00 N01 N02 N03 N10 N11 N12 N13 N20 N21 N22 N23'
	 [../]
 
 	[./N20_dot]
 		type = CoefTimeDerivative
 		variable = N20
 		Coefficient = 1.0
 	[../]
 
 	[./N20_MPB]
 		type = ConstBiPB
 		variable = N20
 		main_variable = N20
 		coupled_list = 'N00 N01 N02 N03 N10 N11 N12 N13 N20 N21 N22 N23'
 	[../]
 
 	[./N21_dot]
 		type = CoefTimeDerivative
 		variable = N21
 		Coefficient = 1.0
 	[../]
 
 	[./N21_MPB]
 		type = ConstBiPB
 		variable = N21
 		main_variable = N21
 		coupled_list = 'N00 N01 N02 N03 N10 N11 N12 N13 N20 N21 N22 N23'
 	[../]
 
 	[./N22_dot]
 		type = CoefTimeDerivative
 		variable = N22
 		Coefficient = 1.0
 	[../]
 
 	[./N22_MPB]
 		type = ConstBiPB
 		variable = N22
 		main_variable = N22
 		coupled_list = 'N00 N01 N02 N03 N10 N11 N12 N13 N20 N21 N22 N23'
 	[../]
 
 	[./N03_dot]
 		type = CoefTimeDerivative
 		variable = N03
 		Coefficient = 1.0
 	[../]
 
 	[./N03_MPB]
 		type = ConstBiPB
 		variable = N03
 		main_variable = N03
 		coupled_list = 'N00 N01 N02 N03 N10 N11 N12 N13 N20 N21 N22 N23'
 	[../]
 
 	[./N13_dot]
 		type = CoefTimeDerivative
 		variable = N13
 		Coefficient = 1.0
 	[../]
 
 	[./N13_MPB]
 		type = ConstBiPB
 		variable = N13
 		main_variable = N13
 		coupled_list = 'N00 N01 N02 N03 N10 N11 N12 N13 N20 N21 N22 N23'
 	[../]
 
 	[./N23_dot]
 		type = CoefTimeDerivative
 		variable = N23
 		Coefficient = 1.0
 	[../]
 
 	[./N23_MPB]
 		type = ConstBiPB
 		variable = N23
 		main_variable = N23
 		coupled_list = 'N00 N01 N02 N03 N10 N11 N12 N13 N20 N21 N22 N23'
 	[../]

[] #END Kernels

[DGKernels]

[] #END DGKernels

[AuxKernels]

	[./N_accumulated_vol]
		type = VolumeBalanceCheck
		variable = N_total_vol
		coupled_vars = 'N00 N01 N02 N03 N10 N11 N12 N13 N20 N21 N22 N23'
        diameters = '1 1 1 1 1.5 1.5 1.5 1.5 2 2 2 2'
        execute_on = 'initial timestep_end'
	[../]
 
 	[./N_accumulated_nuc]
 		type = NuclideBalanceCheck
 		variable = N_total_nuc
 		coupled_vars = 'N00 N01 N02 N03 N10 N11 N12 N13 N20 N21 N22 N23'
 		total_nuclides = '1 2.5 4.5 7 1 2.5 4.5 7 1 2.5 4.5 7'
 		execute_on = 'initial timestep_end'
	[../]

[] #END AuxKernels

[BCs]

 	[./N00_Flux]
 		type = DGFluxBC
 		variable = N00
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
 	[./N01_Flux]
 		type = DGFluxBC
 		variable = N01
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
 	[./N02_Flux]
 		type = DGFluxBC
 		variable = N02
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
 
 	[./N20_Flux]
 		type = DGFluxBC
 		variable = N20
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
 	[./N21_Flux]
 		type = DGFluxBC
 		variable = N21
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
 	[./N22_Flux]
 		type = DGFluxBC
 		variable = N22
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
 	[./N03_Flux]
 		type = DGFluxBC
 		variable = N03
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
    [./N13_Flux]
 		type = DGFluxBC
 		variable = N13
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
 	[./N23_Flux]
 		type = DGFluxBC
 		variable = N23
 		boundary = 'left right'
 		u_input = 0.0
 	[../]

[] #END BCs

[Materials]


[] #END Materials

[UserObjects]
 
	[./test]
 		type = CARDINAL_Object
 		execute_on = 'initial'
 		input_file = '../../../../input_files/cardinal/1979-Test-Case.txt'
 		atm_file = '../../../../input_files/cardinal/DefaultAtmosphere.txt'
 		data_path = '../../../../database/'
 	[../]
 
 [] #END UserObjects

[Postprocessors]

#May consider custom versions of these postprocessors to correct for negative mass ocsillations...
	[./N00]
		type = ElementAverageValue
		variable = N00
		execute_on = 'initial timestep_end'
	[../]
 
	[./N01]
		type = ElementAverageValue
		variable = N01
		execute_on = 'initial timestep_end'
	[../]
 
 	[./N02]
 		type = ElementAverageValue
 		variable = N02
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
 
 	[./N03]
 		type = ElementAverageValue
 		variable = N03
 		execute_on = 'initial timestep_end'
	[../]
 
	[./N13]
 		type = ElementAverageValue
 		variable = N13
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./N23]
 		type = ElementAverageValue
 		variable = N23
 		execute_on = 'initial timestep_end'
	[../]
 
	[./total_vol]
		type = ElementAverageValue
		variable = N_total_vol
		execute_on = 'initial timestep_end'
	[../]
 
 	[./total_nuc]
 		type = ElementAverageValue
 		variable = N_total_nuc
 		execute_on = 'initial timestep_end'
	[../]

[] #END Postprocessors

[Executioner]

    type = Transient
	scheme = bdf2

    # NOTE: The default tolerances are far to strict and cause the program to crawl
    nl_rel_tol = 1e-8
    nl_abs_tol = 1e-8
    nl_rel_step_tol = 1e-10
    nl_abs_step_tol = 1e-10
    l_tol = 1e-8
    l_max_its = 20
    nl_max_its = 10

    solve_type = pjfnk
    line_search = bt    # Options: default shell none basic l2 bt cp
    start_time = 0.0
	end_time = 0.2
    dtmax = 0.2
    petsc_options_iname = '-pc_type -pc_hypre_type -ksp_gmres_restart'
    petsc_options_value = 'hypre boomeramg 100'

    [./TimeStepper]
#		type = SolutionTimeAdaptiveDT
		type = ConstantDT
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
    print_linear_residuals = true

[] #END Outputs
