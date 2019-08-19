[GlobalParams]

 	vx = 0.0
	vy = 0.0
 	vz = 0.0

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

    [./N00]
        order = FIRST
        family = MONOMIAL
        initial_condition = 50
    [../]
 
 	[./N01]
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

    [./N00_dot]
        type = CoefTimeDerivative
        variable = N00
        Coefficient = 1.0
    [../]

    [./N00_MPB]
        type = ConstBiPB
        variable = N00
        main_variable = N00
        diameters = '1 1.25992105'
        total_nuclides = '1 2'
        coupled_list = 'N00 N01 N10 N11'
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
 		diameters = '1 1.25992105'
 		total_nuclides = '1 2'
 		coupled_list = 'N00 N01 N10 N11'
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
 		diameters = '1 1.25992105'
 		total_nuclides = '1 2'
 		coupled_list = 'N00 N01 N10 N11'
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
 		diameters = '1 1.25992105'
        total_nuclides = '1 2'
 		coupled_list = 'N00 N01 N10 N11'
 	[../]

[] #END Kernels

[DGKernels]

[] #END DGKernels

[AuxKernels]

	[./N_accumulated_vol]
		type = VolumeBalanceCheck
		variable = N_total_vol
		coupled_vars = 'N00 N01 N10 N11'
        diameters = '1 1 1.25992105 1.25992105'
        execute_on = 'initial timestep_end'
	[../]
 
 	[./N_accumulated_nuc]
 		type = NuclideBalanceCheck
 		variable = N_total_nuc
 		coupled_vars = 'N00 N01 N10 N11'
 		total_nuclides = '1 2 1 2'
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

[] #END BCs

[Materials]


[] #END Materials

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
    nl_rel_tol = 1e-6
    nl_abs_tol = 1e-6
    nl_rel_step_tol = 1e-10
    nl_abs_step_tol = 1e-10
    l_tol = 1e-6
    l_max_its = 20
    nl_max_its = 10

    solve_type = pjfnk
    line_search = bt    # Options: default shell none basic l2 bt cp
    start_time = 0.0
	end_time = 0.1
    dtmax = 0.5
    petsc_options_iname = '-pc_type -pc_hypre_type -ksp_gmres_restart'
    petsc_options_value = 'hypre boomeramg 100'

    [./TimeStepper]
#		type = SolutionTimeAdaptiveDT
		type = ConstantDT
        dt = 0.025
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
