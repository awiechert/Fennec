[Mesh]
  file = cup-unv.unv
# file = cup-msh.msh
#boundary_id = '1 2'
   boundary_name = 'top bottom'
[]

[Variables]
  [./u]
  [../]
[]

[Kernels]
  [./diff]
    type = Diffusion
    variable = u
  [../]
[]

[BCs]
  [./top]
    type = DirichletBC
    variable = u
    boundary = 'top'
    value = 0
  [../]
  [./bottom]
    type = DirichletBC
    variable = u
    boundary = 'bottom'
    value = 1
  [../]
[]

[Executioner]
  type = Steady
  solve_type = 'PJFNK'
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
