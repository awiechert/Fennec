[GlobalParams]

 	vx = 0.0
	vy = 0.0
 	vz = 0.0

 	# Diameters are in um here. Kernels usually want units in m.
    diameters = '0.00178 0.00562 0.0178 0.0562 0.178 0.562 1.78 5.62 17.8 56.2'

[] #END GlobalParams

[Problem]

[] #END Problem

[Mesh]

    type = GeneratedMesh
    dim = 1
	  nx = 5
    xmin = 0.0
    xmax = 1.0

[] # END Mesh

[Variables]
# Units: GGp/m^3 (Billion-Billion particles per cubic meter)
# NOTE: Must be cautious of the units you use for the variables. Bad unit basis can make convergence difficult.
    [./N0]
        order = FIRST
        family = MONOMIAL
        initial_condition = 3.21004
    [../]

 	[./N1]
 		order = FIRST
 		family = MONOMIAL
        initial_condition = 1.86336
 	[../]

 	[./N2]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0.542688
 	[../]

 	[./N3]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0.0792995
 	[../]

 	[./N4]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0.00581376
    [../]

 	[./N5]
 		order = FIRST
 		family = MONOMIAL
        initial_condition = 213849e-9
 	[../]

 	[./N6]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 3946.3e-9
 	[../]

 	[./N7]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 36.512e-9
 	[../]

 	[./N8]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0.168333e-9
 	[../]

 	[./N9]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0.000365808e-9
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
        type = ConstMonoPB
        variable = N0
        main_variable = N0
        coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
    [../]

 	[./N1_dot]
 		type = CoefTimeDerivative
 		variable = N1
 		Coefficient = 1.0
 	[../]

 	[./N1_MPB]
 		type = ConstMonoPB
 		variable = N1
        main_variable = N1
 		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
 	[../]

 	[./N2_dot]
 		type = CoefTimeDerivative
 		variable = N2
 		Coefficient = 1.0
 	[../]

 	[./N2_MPB]
 		type = ConstMonoPB
 		variable = N2
 		main_variable = N2
 		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
    [../]

 	[./N3_dot]
 		type = CoefTimeDerivative
 		variable = N3
 		Coefficient = 1.0
 	[../]

 	[./N3_MPB]
 		type = ConstMonoPB
 		variable = N3
 		main_variable = N3
 		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
 	[../]

 	[./N4_dot]
 		type = CoefTimeDerivative
 		variable = N4
 		Coefficient = 1.0
 	[../]

    [./N4_MPB]
 		type = ConstMonoPB
 		variable = N4
 		main_variable = N4
 		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
 	[../]

 	[./N5_dot]
 		type = CoefTimeDerivative
 		variable = N5
 		Coefficient = 1.0
	 [../]

 	[./N5_MPB]
 		type = ConstMonoPB
 		variable = N5
 		main_variable = N5
 		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
 	[../]

 	[./N6_dot]
 		type = CoefTimeDerivative
 		variable = N6
 		Coefficient = 1.0
 	[../]

    [./N6_MPB]
 		type = ConstMonoPB
 		variable = N6
 		main_variable = N6
 		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
 	[../]

 	[./N7_dot]
 		type = CoefTimeDerivative
 		variable = N7
 		Coefficient = 1.0
 	[../]

 	[./N7_MPB]
 		type = ConstMonoPB
 		variable = N7
 		main_variable = N7
 		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
 	[../]

 	[./N8_dot]
 		type = CoefTimeDerivative
 		variable = N8
 		Coefficient = 1.0
 	[../]

 	[./N8_MPB]
 		type = ConstMonoPB
 		variable = N8
 		main_variable = N8
 		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
 	[../]

 	[./N9_dot]
 		type = CoefTimeDerivative
 		variable = N9
 		Coefficient = 1.0
 	[../]

 	[./N9_MPB]
 		type = ConstMonoPB
 		variable = N9
 		main_variable = N9
 		coupled_list = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
 	[../]

[] #END Kernels

[DGKernels]

[] #END DGKernels

[AuxKernels]

	[./Total_Volume]
		type = VolumeBalanceCheck
		variable = V_total
		coupled_vars = 'N0 N1 N2 N3 N4 N5 N6 N7 N8 N9'
        diameters = '0.00178 0.00562 0.0178 0.0562 0.178 0.562 1.78 5.62 17.8 56.2'
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

	[./V_total]
		type = ElementAverageValue
		variable = V_total
		execute_on = 'initial timestep_end'
	[../]

[] #END Postprocessors

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
                        -pc_factor_shift_type
                        -ksp_pc_factor_shift_type

                        -pc_asm_overlap

                        -snes_atol
                        -snes_rtol

                        -ksp_ksp_type
                        -ksp_pc_type'

  # snes_max_it = maximum non-linear steps


  ######## NOTE: Best convergence results with asm pc and lu sub-pc ##############
  ##      Issue may be caused by the terminal pc of the ksp pc method
  #       using MUMPS as the linear solver (which is an inefficient method)

  petsc_options_value = 'fgmres
                         gasm

                         ilu

                         20

                         NONZERO
                         NONZERO
                         NONZERO

                         10

                         1E-12
                         1E-12

                         fgmres
                         ilu'

  #NOTE: turning off line search can help converge for high Renolds number
  line_search = none
  nl_rel_tol = 1e-10
  nl_abs_tol = 1e-10
  nl_rel_step_tol = 1e-10
  nl_abs_step_tol = 1e-10
  nl_max_its = 20
  l_tol = 1e-6
  l_max_its = 20

  # Time in min
  start_time = 0.0
  end_time = 1
  dtmax = 2

  # NOTE: Maximum step size to start is 0.01
  [./TimeStepper]
     type = ConstantDT
     dt = 1
  [../]

[] #END Executioner

[Preconditioning]
    [./SMP_PJFNK]
      type = SMP
      full = true
      solve_type = pjfnk
    [../]

[] #END Preconditioning

[Outputs]

    exodus = true
    csv = true
    print_linear_residuals = true

[] #END Outputs
