[GlobalParams]

[] #END GlobalParams

[Problem]

[] #END Problem

[Mesh]

 	file = 2D-Flow-Converted.unv
 	boundary_name = 'inlet outlet top bottom object'

[] # END Mesh

[Variables]
#velocity units: m/s
    [./ux]
        order = FIRST
        family = MONOMIAL
        initial_condition = 0
    [../]
 
	[./uy]
		order = FIRST
		family = MONOMIAL
        initial_condition = 0
	[../]

[] #END Variables

[AuxVariables]
 
	[./uz]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0
	[../]
 
	[./dens]
		order = FIRST
		family = MONOMIAL
		initial_condition = 1000.0  #kg/m^3
	[../]
 
	[./vis]
		order = FIRST
		family = MONOMIAL
		initial_condition = 0.001	#kg/m/s
	[../]

[] #END AuxVariables

[ICs]

[] #END ICs

[Kernels]

    [./ux_dot]
        type = MomentumAccumulation
        variable = ux
        density = dens
    [../]

    [./ux_gadv]
        type = GMomentumAdvection
        variable = ux
		direction = 0
		ux = ux
		uy = uy
		uz = uz
		density = dens
    [../]

    [./ux_gdiff]
        type = GMomentumDiffusion
        variable = ux
		viscosity = vis
    [../]
 
	[./ux_stress]
		type = StressTensor
		variable = ux
		direction = 0
		ux = ux
		uy = uy
		uz = uz
		viscosity = vis
	[../]
 
	[./uy_dot]
		type = MomentumAccumulation
		variable = uy
		density = dens
	[../]
 
	[./uy_gadv]
		type = GMomentumAdvection
		variable = uy
		direction = 1
		ux = ux
		uy = uy
		uz = uz
		density = dens
	[../]
 
	[./uy_gdiff]
		type = GMomentumDiffusion
		variable = uy
		viscosity = vis
	[../]
 
	[./uy_stress]
		type = StressTensor
		variable = uy
		direction = 1
		ux = ux
		uy = uy
		uz = uz
		viscosity = vis
	[../]

[] #END Kernels

[DGKernels]

    [./ux_dgadv]
        type = DGMomentumAdvection
		variable = ux
		direction = 0
		ux = ux
		uy = uy
		uz = uz
		density = dens
    [../]

    [./ux_dgdiff]
        type = DGMomentumDiffusion
        variable = ux
		viscosity = vis
    [../]
 
	[./uy_dgadv]
		type = DGMomentumAdvection
		variable = uy
		direction = 1
		ux = ux
		uy = uy
		uz = uz
		density = dens
	[../]
 
	[./uy_dgdiff]
		type = DGMomentumDiffusion
		variable = uy
		viscosity = vis
	[../]

[] #END DGKernels

[AuxKernels]


[] #END AuxKernels

[BCs]
 
 	[./ux_Flux_in]
 		type = DGFluxBC
 		variable = ux
 		boundary = 'inlet'
 		u_input = 1.0
        vx = 1.0
 	[../]
 
    [./ux_Flux]
        type = DGContinuumBC
        variable = ux
        boundary = 'outlet top bottom object'
		direction = 0
		ux = ux
		uy = uy
		uz = uz
		density = dens
    [../]
 
 	[./uy_Flux_in]
 		type = DGFluxBC
 		variable = uy
 		boundary = 'inlet'
 		u_input = 0.0
 		vy = 0.0
 	[../]
 
	[./uy_Flux]
		type = DGContinuumBC
		variable = uy
		boundary = 'outlet top bottom object'
		direction = 1
		ux = ux
		uy = uy
		uz = uz
		density = dens
	[../]
 
[] #END BCs

[Materials]


[] #END Materials

[Postprocessors]

    [./ux_exit]
        type = SideAverageValue
        boundary = 'outlet'
        variable = ux
        execute_on = 'initial timestep_end'
    [../]

    [./ux_enter]
        type = SideAverageValue
        boundary = 'inlet'
        variable = ux
        execute_on = 'initial timestep_end'
    [../]

    [./ux_avg]
        type = ElementAverageValue
        variable = ux
        execute_on = 'initial timestep_end'
    [../]
 
	[./uy_avg]
		type = ElementAverageValue
		variable = uy
		execute_on = 'initial timestep_end'
	[../]

[] #END Postprocessors

[Executioner]

    type = Transient
	scheme = implicit-euler

    # NOTE: The default tolerances are far to strict and cause the program to crawl
    nl_rel_tol = 1e-6
    nl_abs_tol = 1e-6
    nl_rel_step_tol = 1e-10
    nl_abs_step_tol = 1e-10
    l_tol = 1e-6
    l_max_its = 100
    nl_max_its = 10

    solve_type = pjfnk
    line_search = bt    # Options: default shell none basic l2 bt cp
    start_time = 0.0
	end_time = 400.0
#	end_time = 0.3
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
