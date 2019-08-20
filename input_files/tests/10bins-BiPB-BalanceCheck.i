[GlobalParams]

 	vx = 0.0
	vy = 0.0
 	vz = 0.0
 
 	# Diameters are in um here. Kernels usually want units in m.
    diameters = '0.00178 0.00562 0.0178 0.0562 0.178 0.562 1.78 5.62 17.8 56.2'
 
 	# Numbers are in moles per GGp (Density of nuclides in each size bin)
    total_nuclides = '2.26861E-10 4.8822E-09 1.31471E-07 3.92829E-06 0.000121932 0.003832951 0.120990043 3.826762802 121.91908 4135.068287'

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
# Units: GGp/m^3 (Billion-Billion particles per cubic meter)
# NOTE: Must be cautious of the units you use for the variables. Bad unit basis can make convergence difficult.
    [./N00]
        order = FIRST
        family = MONOMIAL
        initial_condition = 3.21004
    [../]
 
 	[./N01]
 		order = FIRST
 		family = MONOMIAL
        initial_condition = 0
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
 
 	[./N04]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
    [../]
 
 	[./N05]
 		order = FIRST
 		family = MONOMIAL
        initial_condition = 0
 	[../]
 
 	[./N06]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N07]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N08]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N09]
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
 		initial_condition = 1.86336
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
 		initial_condition = 0
 	[../]
 
 	[./N15]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N16]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N17]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N18]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N19]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]

 
 	[./N20]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N21]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N22]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0.542688
 	[../]
 
 	[./N23]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N24]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N25]
 		order = FIRST
	 	family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N26]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N27]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N28]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N29]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
    [../]


 	[./N30]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N31]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N32]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N33]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0.0792995
 	[../]
 
 	[./N34]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N35]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N36]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N37]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N38]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N39]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]

 
 
 	[./N40]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N41]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N42]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N43]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N44]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0.00581376
 	[../]
 
 	[./N45]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N46]
        order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N47]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N48]
	 	order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N49]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 
 
 	[./N50]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N51]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N52]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N53]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N54]
 		order = FIRST
 		family = MONOMIAL
        initial_condition = 0
 	[../]
 
 	[./N55]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 213849e-9
    [../]
 
 	[./N56]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
    [../]
 
 	[./N57]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
    [../]
 
    [./N58]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N59]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 
 
 	[./N60]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N61]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N62]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N63]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N64]
        order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N65]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N66]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 3946.3e-9
 	[../]
 
 	[./N67]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N68]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N69]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 
 
 	[./N70]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N71]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N72]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N73]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N74]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N75]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N76]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N77]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 36.512e-9
 	[../]
 
 	[./N78]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
    [./N79]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 
 	[./N80]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N81]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N82]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N83]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N84]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N85]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N86]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N87]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
    [./N88]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0.168333e-9
 	[../]
 
 	[./N89]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 
 
 	[./N90]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N91]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N92]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N93]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N94]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N95]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N96]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N97]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N98]
 		order = FIRST
 		family = MONOMIAL
 		initial_condition = 0
 	[../]
 
 	[./N99]
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
 
 	[./Nuc_total]
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
        coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
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
 		coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
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
 		coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
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
 		coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 	[../]
 
 	[./N04_dot]
 		type = CoefTimeDerivative
 		variable = N04
 		Coefficient = 1.0
 	[../]
 
    [./N04_MPB]
 		type = ConstBiPB
 		variable = N04
 		main_variable = N04
 		coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 	[../]
 
 	[./N05_dot]
 		type = CoefTimeDerivative
 		variable = N05
 		Coefficient = 1.0
	 [../]
 
 	[./N05_MPB]
 		type = ConstBiPB
 		variable = N05
 		main_variable = N05
 		coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 	[../]
 
 	[./N06_dot]
 		type = CoefTimeDerivative
 		variable = N06
 		Coefficient = 1.0
 	[../]
 
    [./N06_MPB]
 		type = ConstBiPB
 		variable = N06
 		main_variable = N06
 		coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 	[../]
 
 	[./N07_dot]
 		type = CoefTimeDerivative
 		variable = N07
 		Coefficient = 1.0
 	[../]
 
 	[./N07_MPB]
 		type = ConstBiPB
 		variable = N07
 		main_variable = N07
 		coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 	[../]
 
 	[./N08_dot]
 		type = CoefTimeDerivative
 		variable = N08
 		Coefficient = 1.0
 	[../]
 
 	[./N08_MPB]
 		type = ConstBiPB
 		variable = N08
 		main_variable = N08
 		coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 	[../]
 
 	[./N09_dot]
 		type = CoefTimeDerivative
 		variable = N09
 		Coefficient = 1.0
 	[../]
 
 	[./N09_MPB]
 		type = ConstBiPB
 		variable = N09
 		main_variable = N09
 		coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
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
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
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
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
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
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
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
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N14_dot]
 type = CoefTimeDerivative
 variable = N14
 Coefficient = 1.0
 [../]
 
 [./N14_MPB]
 type = ConstBiPB
 variable = N14
 main_variable = N14
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N15_dot]
 type = CoefTimeDerivative
 variable = N15
 Coefficient = 1.0
 [../]
 
 [./N15_MPB]
 type = ConstBiPB
 variable = N15
 main_variable = N15
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N16_dot]
 type = CoefTimeDerivative
 variable = N16
 Coefficient = 1.0
 [../]
 
 [./N16_MPB]
 type = ConstBiPB
 variable = N16
 main_variable = N16
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N17_dot]
 type = CoefTimeDerivative
 variable = N17
 Coefficient = 1.0
 [../]
 
 [./N17_MPB]
 type = ConstBiPB
 variable = N17
 main_variable = N17
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N18_dot]
 type = CoefTimeDerivative
 variable = N18
 Coefficient = 1.0
 [../]
 
 [./N18_MPB]
 type = ConstBiPB
 variable = N18
 main_variable = N18
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N19_dot]
 type = CoefTimeDerivative
 variable = N19
 Coefficient = 1.0
 [../]
 
 	[./N19_MPB]
 		type = ConstBiPB
 		variable = N19
 		main_variable = N19
 		coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
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
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
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
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
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
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
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
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N24_dot]
 type = CoefTimeDerivative
 variable = N24
 Coefficient = 1.0
 [../]
 
 [./N24_MPB]
 type = ConstBiPB
 variable = N24
 main_variable = N24
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N25_dot]
 type = CoefTimeDerivative
 variable = N25
 Coefficient = 1.0
 [../]
 
 [./N25_MPB]
 type = ConstBiPB
 variable = N25
 main_variable = N25
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N26_dot]
 type = CoefTimeDerivative
 variable = N26
 Coefficient = 1.0
 [../]
 
 [./N26_MPB]
 type = ConstBiPB
 variable = N26
 main_variable = N26
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N27_dot]
 type = CoefTimeDerivative
 variable = N27
 Coefficient = 1.0
 [../]
 
 [./N27_MPB]
 type = ConstBiPB
 variable = N27
 main_variable = N27
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N28_dot]
 type = CoefTimeDerivative
 variable = N28
 Coefficient = 1.0
 [../]
 
 [./N28_MPB]
 type = ConstBiPB
 variable = N28
 main_variable = N28
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N29_dot]
 type = CoefTimeDerivative
 variable = N29
 Coefficient = 1.0
 [../]
 
 	[./N29_MPB]
 		type = ConstBiPB
 		variable = N29
 		main_variable = N29
 		coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 	[../]
 

 
 [./N30_dot]
 type = CoefTimeDerivative
 variable = N30
 Coefficient = 1.0
 [../]
 
 [./N30_MPB]
 type = ConstBiPB
 variable = N30
 main_variable = N30
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N31_dot]
 type = CoefTimeDerivative
 variable = N31
 Coefficient = 1.0
 [../]
 
 [./N31_MPB]
 type = ConstBiPB
 variable = N31
 main_variable = N31
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N32_dot]
 type = CoefTimeDerivative
 variable = N32
 Coefficient = 1.0
 [../]
 
 [./N32_MPB]
 type = ConstBiPB
 variable = N32
 main_variable = N32
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N33_dot]
 type = CoefTimeDerivative
 variable = N33
 Coefficient = 1.0
 [../]
 
 [./N33_MPB]
 type = ConstBiPB
 variable = N33
 main_variable = N33
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N34_dot]
 type = CoefTimeDerivative
 variable = N34
 Coefficient = 1.0
 [../]
 
 [./N34_MPB]
 type = ConstBiPB
 variable = N34
 main_variable = N34
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N35_dot]
 type = CoefTimeDerivative
 variable = N35
 Coefficient = 1.0
 [../]
 
 [./N35_MPB]
 type = ConstBiPB
 variable = N35
 main_variable = N35
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N36_dot]
 type = CoefTimeDerivative
 variable = N36
 Coefficient = 1.0
 [../]
 
 [./N36_MPB]
 type = ConstBiPB
 variable = N36
 main_variable = N36
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N37_dot]
 type = CoefTimeDerivative
 variable = N37
 Coefficient = 1.0
 [../]
 
 [./N37_MPB]
 type = ConstBiPB
 variable = N37
 main_variable = N37
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N38_dot]
 type = CoefTimeDerivative
 variable = N38
 Coefficient = 1.0
 [../]
 
 [./N38_MPB]
 type = ConstBiPB
 variable = N38
 main_variable = N38
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N39_dot]
 type = CoefTimeDerivative
 variable = N39
 Coefficient = 1.0
 [../]
 
 	[./N39_MPB]
 		type = ConstBiPB
 		variable = N39
 		main_variable = N39
 		coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 	[../]
 
 
 [./N40_dot]
 type = CoefTimeDerivative
 variable = N40
 Coefficient = 1.0
 [../]
 
 [./N40_MPB]
 type = ConstBiPB
 variable = N40
 main_variable = N40
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N41_dot]
 type = CoefTimeDerivative
 variable = N41
 Coefficient = 1.0
 [../]
 
 [./N41_MPB]
 type = ConstBiPB
 variable = N41
 main_variable = N41
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N42_dot]
 type = CoefTimeDerivative
 variable = N42
 Coefficient = 1.0
 [../]
 
 [./N42_MPB]
 type = ConstBiPB
 variable = N42
 main_variable = N42
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N43_dot]
 type = CoefTimeDerivative
 variable = N43
 Coefficient = 1.0
 [../]
 
 [./N43_MPB]
 type = ConstBiPB
 variable = N43
 main_variable = N43
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N44_dot]
 type = CoefTimeDerivative
 variable = N44
 Coefficient = 1.0
 [../]
 
 [./N44_MPB]
 type = ConstBiPB
 variable = N44
 main_variable = N44
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N45_dot]
 type = CoefTimeDerivative
 variable = N45
 Coefficient = 1.0
 [../]
 
 [./N45_MPB]
 type = ConstBiPB
 variable = N45
 main_variable = N45
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N46_dot]
 type = CoefTimeDerivative
 variable = N46
 Coefficient = 1.0
 [../]
 
 [./N46_MPB]
 type = ConstBiPB
 variable = N46
 main_variable = N46
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N47_dot]
 type = CoefTimeDerivative
 variable = N47
 Coefficient = 1.0
 [../]
 
 [./N47_MPB]
 type = ConstBiPB
 variable = N47
 main_variable = N47
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N48_dot]
 type = CoefTimeDerivative
 variable = N48
 Coefficient = 1.0
 [../]
 
 [./N48_MPB]
 type = ConstBiPB
 variable = N48
 main_variable = N48
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N49_dot]
 type = CoefTimeDerivative
 variable = N49
 Coefficient = 1.0
 [../]
 
 	[./N49_MPB]
 		type = ConstBiPB
 		variable = N49
 		main_variable = N49
 		coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 	[../]
 

 
 [./N50_dot]
 type = CoefTimeDerivative
 variable = N50
 Coefficient = 1.0
 [../]
 
 [./N50_MPB]
 type = ConstBiPB
 variable = N50
 main_variable = N50
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N51_dot]
 type = CoefTimeDerivative
 variable = N51
 Coefficient = 1.0
 [../]
 
 [./N51_MPB]
 type = ConstBiPB
 variable = N51
 main_variable = N51
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N52_dot]
 type = CoefTimeDerivative
 variable = N52
 Coefficient = 1.0
 [../]
 
 [./N52_MPB]
 type = ConstBiPB
 variable = N52
 main_variable = N52
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N53_dot]
 type = CoefTimeDerivative
 variable = N53
 Coefficient = 1.0
 [../]
 
 [./N53_MPB]
 type = ConstBiPB
 variable = N53
 main_variable = N53
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N54_dot]
 type = CoefTimeDerivative
 variable = N54
 Coefficient = 1.0
 [../]
 
 [./N54_MPB]
 type = ConstBiPB
 variable = N54
 main_variable = N54
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N55_dot]
 type = CoefTimeDerivative
 variable = N55
 Coefficient = 1.0
 [../]
 
 [./N55_MPB]
 type = ConstBiPB
 variable = N55
 main_variable = N55
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N56_dot]
 type = CoefTimeDerivative
 variable = N56
 Coefficient = 1.0
 [../]
 
 [./N56_MPB]
 type = ConstBiPB
 variable = N56
 main_variable = N56
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N57_dot]
 type = CoefTimeDerivative
 variable = N57
 Coefficient = 1.0
 [../]
 
 [./N57_MPB]
 type = ConstBiPB
 variable = N57
 main_variable = N57
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N58_dot]
 type = CoefTimeDerivative
 variable = N58
 Coefficient = 1.0
 [../]
 
 [./N58_MPB]
 type = ConstBiPB
 variable = N58
 main_variable = N58
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N59_dot]
 type = CoefTimeDerivative
 variable = N59
 Coefficient = 1.0
 [../]
 
 [./N59_MPB]
 type = ConstBiPB
 variable = N59
 main_variable = N59
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 
 
 [./N60_dot]
 type = CoefTimeDerivative
 variable = N60
 Coefficient = 1.0
 [../]
 
 [./N60_MPB]
 type = ConstBiPB
 variable = N60
 main_variable = N60
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N61_dot]
 type = CoefTimeDerivative
 variable = N61
 Coefficient = 1.0
 [../]
 
 [./N61_MPB]
 type = ConstBiPB
 variable = N61
 main_variable = N61
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N62_dot]
 type = CoefTimeDerivative
 variable = N62
 Coefficient = 1.0
 [../]
 
 [./N62_MPB]
 type = ConstBiPB
 variable = N62
 main_variable = N62
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N63_dot]
 type = CoefTimeDerivative
 variable = N63
 Coefficient = 1.0
 [../]
 
 [./N63_MPB]
 type = ConstBiPB
 variable = N63
 main_variable = N63
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N64_dot]
 type = CoefTimeDerivative
 variable = N64
 Coefficient = 1.0
 [../]
 
 [./N64_MPB]
 type = ConstBiPB
 variable = N64
 main_variable = N64
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N65_dot]
 type = CoefTimeDerivative
 variable = N65
 Coefficient = 1.0
 [../]
 
 [./N65_MPB]
 type = ConstBiPB
 variable = N65
 main_variable = N65
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N66_dot]
 type = CoefTimeDerivative
 variable = N66
 Coefficient = 1.0
 [../]
 
 [./N66_MPB]
 type = ConstBiPB
 variable = N66
 main_variable = N66
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N67_dot]
 type = CoefTimeDerivative
 variable = N67
 Coefficient = 1.0
 [../]
 
 [./N67_MPB]
 type = ConstBiPB
 variable = N67
 main_variable = N67
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N68_dot]
 type = CoefTimeDerivative
 variable = N68
 Coefficient = 1.0
 [../]
 
 [./N68_MPB]
 type = ConstBiPB
 variable = N68
 main_variable = N68
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N69_dot]
 type = CoefTimeDerivative
 variable = N69
 Coefficient = 1.0
 [../]
 
 [./N69_MPB]
 type = ConstBiPB
 variable = N69
 main_variable = N69
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 
 
 [./N70_dot]
 type = CoefTimeDerivative
 variable = N70
 Coefficient = 1.0
 [../]
 
 [./N70_MPB]
 type = ConstBiPB
 variable = N70
 main_variable = N70
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N71_dot]
 type = CoefTimeDerivative
 variable = N71
 Coefficient = 1.0
 [../]
 
 [./N71_MPB]
 type = ConstBiPB
 variable = N71
 main_variable = N71
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N72_dot]
 type = CoefTimeDerivative
 variable = N72
 Coefficient = 1.0
 [../]
 
 [./N72_MPB]
 type = ConstBiPB
 variable = N72
 main_variable = N72
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N73_dot]
 type = CoefTimeDerivative
 variable = N73
 Coefficient = 1.0
 [../]
 
 [./N73_MPB]
 type = ConstBiPB
 variable = N73
 main_variable = N73
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N74_dot]
 type = CoefTimeDerivative
 variable = N74
 Coefficient = 1.0
 [../]
 
 [./N74_MPB]
 type = ConstBiPB
 variable = N74
 main_variable = N74
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N75_dot]
 type = CoefTimeDerivative
 variable = N75
 Coefficient = 1.0
 [../]
 
 [./N75_MPB]
 type = ConstBiPB
 variable = N75
 main_variable = N75
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N76_dot]
 type = CoefTimeDerivative
 variable = N76
 Coefficient = 1.0
 [../]
 
 [./N76_MPB]
 type = ConstBiPB
 variable = N76
 main_variable = N76
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N77_dot]
 type = CoefTimeDerivative
 variable = N77
 Coefficient = 1.0
 [../]
 
 [./N77_MPB]
 type = ConstBiPB
 variable = N77
 main_variable = N77
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N78_dot]
 type = CoefTimeDerivative
 variable = N78
 Coefficient = 1.0
 [../]
 
 [./N78_MPB]
 type = ConstBiPB
 variable = N78
 main_variable = N78
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N79_dot]
 type = CoefTimeDerivative
 variable = N79
 Coefficient = 1.0
 [../]
 
 	[./N79_MPB]
 		type = ConstBiPB
 		variable = N79
 		main_variable = N79
 		coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 	[../]
 
 
 
 [./N80_dot]
 type = CoefTimeDerivative
 variable = N80
 Coefficient = 1.0
 [../]
 
 [./N80_MPB]
 type = ConstBiPB
 variable = N80
 main_variable = N80
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N81_dot]
 type = CoefTimeDerivative
 variable = N81
 Coefficient = 1.0
 [../]
 
 [./N81_MPB]
 type = ConstBiPB
 variable = N81
 main_variable = N81
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N82_dot]
 type = CoefTimeDerivative
 variable = N82
 Coefficient = 1.0
 [../]
 
 [./N82_MPB]
 type = ConstBiPB
 variable = N82
 main_variable = N82
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N83_dot]
 type = CoefTimeDerivative
 variable = N83
 Coefficient = 1.0
 [../]
 
 [./N83_MPB]
 type = ConstBiPB
 variable = N83
 main_variable = N83
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N84_dot]
 type = CoefTimeDerivative
 variable = N84
 Coefficient = 1.0
 [../]
 
 [./N84_MPB]
 type = ConstBiPB
 variable = N84
 main_variable = N84
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N85_dot]
 type = CoefTimeDerivative
 variable = N85
 Coefficient = 1.0
 [../]
 
 [./N85_MPB]
 type = ConstBiPB
 variable = N85
 main_variable = N85
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N86_dot]
 type = CoefTimeDerivative
 variable = N86
 Coefficient = 1.0
 [../]
 
 [./N86_MPB]
 type = ConstBiPB
 variable = N86
 main_variable = N86
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N87_dot]
 type = CoefTimeDerivative
 variable = N87
 Coefficient = 1.0
 [../]
 
 [./N87_MPB]
 type = ConstBiPB
 variable = N87
 main_variable = N87
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N88_dot]
 type = CoefTimeDerivative
 variable = N88
 Coefficient = 1.0
 [../]
 
 [./N88_MPB]
 type = ConstBiPB
 variable = N88
 main_variable = N88
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N89_dot]
 type = CoefTimeDerivative
 variable = N89
 Coefficient = 1.0
 [../]
 
 	[./N89_MPB]
 		type = ConstBiPB
 		variable = N89
 		main_variable = N89
 		coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 	[../]
 
 
 
 
 [./N90_dot]
 type = CoefTimeDerivative
 variable = N90
 Coefficient = 1.0
 [../]
 
 [./N90_MPB]
 type = ConstBiPB
 variable = N90
 main_variable = N90
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N91_dot]
 type = CoefTimeDerivative
 variable = N91
 Coefficient = 1.0
 [../]
 
 [./N91_MPB]
 type = ConstBiPB
 variable = N91
 main_variable = N91
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N92_dot]
 type = CoefTimeDerivative
 variable = N92
 Coefficient = 1.0
 [../]
 
 [./N92_MPB]
 type = ConstBiPB
 variable = N92
 main_variable = N92
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N93_dot]
 type = CoefTimeDerivative
 variable = N93
 Coefficient = 1.0
 [../]
 
 [./N93_MPB]
 type = ConstBiPB
 variable = N93
 main_variable = N93
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N94_dot]
 type = CoefTimeDerivative
 variable = N94
 Coefficient = 1.0
 [../]
 
 [./N94_MPB]
 type = ConstBiPB
 variable = N94
 main_variable = N94
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N95_dot]
 type = CoefTimeDerivative
 variable = N95
 Coefficient = 1.0
 [../]
 
 [./N95_MPB]
 type = ConstBiPB
 variable = N95
 main_variable = N95
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N96_dot]
 type = CoefTimeDerivative
 variable = N96
 Coefficient = 1.0
 [../]
 
 [./N96_MPB]
 type = ConstBiPB
 variable = N96
 main_variable = N96
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N97_dot]
 type = CoefTimeDerivative
 variable = N97
 Coefficient = 1.0
 [../]
 
 [./N97_MPB]
 type = ConstBiPB
 variable = N97
 main_variable = N97
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N98_dot]
 type = CoefTimeDerivative
 variable = N98
 Coefficient = 1.0
 [../]
 
 [./N98_MPB]
 type = ConstBiPB
 variable = N98
 main_variable = N98
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 [./N99_dot]
 type = CoefTimeDerivative
 variable = N99
 Coefficient = 1.0
 [../]
 
 [./N99_MPB]
 type = ConstBiPB
 variable = N99
 main_variable = N99
 coupled_list = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 [../]
 
 
 

[] #END Kernels

[DGKernels]

[] #END DGKernels

[AuxKernels]

	[./Total_Volume]
		type = VolumeBalanceCheck
		variable = V_total
		coupled_vars = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
        diameters = '0.00178 0.00178 0.00178 0.00178 0.00178 0.00178 0.00178 0.00178 0.00178 0.00178 0.00562 0.00562 0.00562 0.00562 0.00562 0.00562 0.00562 0.00562 0.00562 0.00562 0.0178 0.0178 0.0178 0.0178 0.0178 0.0178 0.0178 0.0178 0.0178 0.0178 0.0562 0.0562 0.0562 0.0562 0.0562 0.0562 0.0562 0.0562 0.0562 0.0562 0.178 0.178 0.178 0.178 0.178 0.178 0.178 0.178 0.178 0.178 0.562 0.562 0.562 0.562 0.562 0.562 0.562 0.562 0.562 0.562 1.78 1.78 1.78 1.78 1.78 1.78 1.78 1.78 1.78 1.78 5.62 5.62 5.62 5.62 5.62 5.62 5.62 5.62 5.62 5.62 17.8 17.8 17.8 17.8 17.8 17.8 17.8 17.8 17.8 17.8 56.2 56.2 56.2 56.2 56.2 56.2 56.2 56.2 56.2 56.2'
        execute_on = 'initial timestep_end'
	[../]
 
 	[./Total_Nuc]
 		type = NuclideBalanceCheck
 		variable = Nuc_total
 		coupled_vars = 'N00 N01 N02 N03 N04 N05 N06 N07 N08 N09 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 N22 N23 N24 N25 N26 N27 N28 N29 N30 N31 N32 N33 N34 N35 N36 N37 N38 N39 N40 N41 N42 N43 N44 N45 N46 N47 N48 N49 N50 N51 N52 N53 N54 N55 N56 N57 N58 N59 N60 N61 N62 N63 N64 N65 N66 N67 N68 N69 N70 N71 N72 N73 N74 N75 N76 N77 N78 N79 N80 N81 N82 N83 N84 N85 N86 N87 N88 N89 N90 N91 N92 N93 N94 N95 N96 N97 N98 N99'
 		total_nuclides = '2.26861E-10 4.8822E-09 1.31471E-07 3.92829E-06 0.000121932 0.003832951 0.120990043 3.826762802 121.91908 4135.068287 2.26861E-10 4.8822E-09 1.31471E-07 3.92829E-06 0.000121932 0.003832951 0.120990043 3.826762802 121.91908 4135.068287 2.26861E-10 4.8822E-09 1.31471E-07 3.92829E-06 0.000121932 0.003832951 0.120990043 3.826762802 121.91908 4135.068287 2.26861E-10 4.8822E-09 1.31471E-07 3.92829E-06 0.000121932 0.003832951 0.120990043 3.826762802 121.91908 4135.068287 2.26861E-10 4.8822E-09 1.31471E-07 3.92829E-06 0.000121932 0.003832951 0.120990043 3.826762802 121.91908 4135.068287 2.26861E-10 4.8822E-09 1.31471E-07 3.92829E-06 0.000121932 0.003832951 0.120990043 3.826762802 121.91908 4135.068287 2.26861E-10 4.8822E-09 1.31471E-07 3.92829E-06 0.000121932 0.003832951 0.120990043 3.826762802 121.91908 4135.068287 2.26861E-10 4.8822E-09 1.31471E-07 3.92829E-06 0.000121932 0.003832951 0.120990043 3.826762802 121.91908 4135.068287 2.26861E-10 4.8822E-09 1.31471E-07 3.92829E-06 0.000121932 0.003832951 0.120990043 3.826762802 121.91908 4135.068287 2.26861E-10 4.8822E-09 1.31471E-07 3.92829E-06 0.000121932 0.003832951 0.120990043 3.826762802 121.91908 4135.068287'
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
 
 	[./N03_Flux]
 		type = DGFluxBC
 		variable = N03
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
 	[./N04_Flux]
 		type = DGFluxBC
 		variable = N04
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
 	[./N05_Flux]
 		type = DGFluxBC
 		variable = N05
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
 	[./N06_Flux]
 		type = DGFluxBC
 		variable = N06
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
 	[./N07_Flux]
 		type = DGFluxBC
 		variable = N07
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
 	[./N08_Flux]
 		type = DGFluxBC
 		variable = N08
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
 	[./N09_Flux]
 		type = DGFluxBC
 		variable = N09
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
 
 [./N15_Flux]
 type = DGFluxBC
 variable = N15
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N16_Flux]
 type = DGFluxBC
 variable = N16
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N17_Flux]
 type = DGFluxBC
 variable = N17
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N18_Flux]
 type = DGFluxBC
 variable = N18
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 	[./N19_Flux]
 		type = DGFluxBC
 		variable = N19
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
 
 [./N23_Flux]
 type = DGFluxBC
 variable = N23
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N24_Flux]
 type = DGFluxBC
 variable = N24
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N25_Flux]
 type = DGFluxBC
 variable = N25
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N26_Flux]
 type = DGFluxBC
 variable = N26
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N27_Flux]
 type = DGFluxBC
 variable = N27
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N28_Flux]
 type = DGFluxBC
 variable = N28
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 	[./N29_Flux]
 		type = DGFluxBC
 		variable = N29
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
 
 [./N30_Flux]
 type = DGFluxBC
 variable = N30
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N31_Flux]
 type = DGFluxBC
 variable = N31
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N32_Flux]
 type = DGFluxBC
 variable = N32
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N33_Flux]
 type = DGFluxBC
 variable = N33
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N34_Flux]
 type = DGFluxBC
 variable = N34
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N35_Flux]
 type = DGFluxBC
 variable = N35
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N36_Flux]
 type = DGFluxBC
 variable = N36
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N37_Flux]
 type = DGFluxBC
 variable = N37
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N38_Flux]
 type = DGFluxBC
 variable = N38
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 	[./N39_Flux]
 		type = DGFluxBC
 		variable = N39
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
 
 [./N40_Flux]
 type = DGFluxBC
 variable = N40
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N41_Flux]
 type = DGFluxBC
 variable = N41
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N42_Flux]
 type = DGFluxBC
 variable = N42
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N43_Flux]
 type = DGFluxBC
 variable = N43
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N44_Flux]
 type = DGFluxBC
 variable = N44
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N45_Flux]
 type = DGFluxBC
 variable = N45
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N46_Flux]
 type = DGFluxBC
 variable = N46
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N47_Flux]
 type = DGFluxBC
 variable = N47
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N48_Flux]
 type = DGFluxBC
 variable = N48
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 	[./N49_Flux]
 		type = DGFluxBC
 		variable = N49
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
 
 [./N50_Flux]
 type = DGFluxBC
 variable = N50
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N51_Flux]
 type = DGFluxBC
 variable = N51
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N52_Flux]
 type = DGFluxBC
 variable = N52
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N53_Flux]
 type = DGFluxBC
 variable = N53
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N54_Flux]
 type = DGFluxBC
 variable = N54
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N55_Flux]
 type = DGFluxBC
 variable = N55
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N56_Flux]
 type = DGFluxBC
 variable = N56
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N57_Flux]
 type = DGFluxBC
 variable = N57
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N58_Flux]
 type = DGFluxBC
 variable = N58
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 	[./N59_Flux]
 		type = DGFluxBC
 		variable = N59
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
 
 [./N60_Flux]
 type = DGFluxBC
 variable = N60
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N61_Flux]
 type = DGFluxBC
 variable = N61
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N62_Flux]
 type = DGFluxBC
 variable = N62
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N63_Flux]
 type = DGFluxBC
 variable = N63
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N64_Flux]
 type = DGFluxBC
 variable = N64
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N65_Flux]
 type = DGFluxBC
 variable = N65
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N66_Flux]
 type = DGFluxBC
 variable = N66
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N67_Flux]
 type = DGFluxBC
 variable = N67
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N68_Flux]
 type = DGFluxBC
 variable = N68
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 	[./N69_Flux]
 		type = DGFluxBC
 		variable = N69
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
 
 [./N70_Flux]
 type = DGFluxBC
 variable = N70
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N71_Flux]
 type = DGFluxBC
 variable = N71
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N72_Flux]
 type = DGFluxBC
 variable = N72
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N73_Flux]
 type = DGFluxBC
 variable = N73
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N74_Flux]
 type = DGFluxBC
 variable = N74
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N75_Flux]
 type = DGFluxBC
 variable = N75
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N76_Flux]
 type = DGFluxBC
 variable = N76
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N77_Flux]
 type = DGFluxBC
 variable = N77
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N78_Flux]
 type = DGFluxBC
 variable = N78
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 	[./N79_Flux]
 		type = DGFluxBC
 		variable = N79
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
 
 [./N80_Flux]
 type = DGFluxBC
 variable = N80
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N81_Flux]
 type = DGFluxBC
 variable = N81
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N82_Flux]
 type = DGFluxBC
 variable = N82
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N83_Flux]
 type = DGFluxBC
 variable = N83
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N84_Flux]
 type = DGFluxBC
 variable = N84
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N85_Flux]
 type = DGFluxBC
 variable = N85
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N86_Flux]
 type = DGFluxBC
 variable = N86
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N87_Flux]
 type = DGFluxBC
 variable = N87
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N88_Flux]
 type = DGFluxBC
 variable = N88
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 	[./N89_Flux]
 		type = DGFluxBC
 		variable = N89
 		boundary = 'left right'
 		u_input = 0.0
 	[../]
 
 
 [./N90_Flux]
 type = DGFluxBC
 variable = N90
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N91_Flux]
 type = DGFluxBC
 variable = N91
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N92_Flux]
 type = DGFluxBC
 variable = N92
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N93_Flux]
 type = DGFluxBC
 variable = N93
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N94_Flux]
 type = DGFluxBC
 variable = N94
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N95_Flux]
 type = DGFluxBC
 variable = N95
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N96_Flux]
 type = DGFluxBC
 variable = N96
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N97_Flux]
 type = DGFluxBC
 variable = N97
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N98_Flux]
 type = DGFluxBC
 variable = N98
 boundary = 'left right'
 u_input = 0.0
 [../]
 
 [./N99_Flux]
 type = DGFluxBC
 variable = N99
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
 
 	[./N02]
 		type = ElementAverageValue
 		variable = N02
		 execute_on = 'initial timestep_end'
	[../]
 
 	[./N03]
 		type = ElementAverageValue
 		variable = N03
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./N04]
 		type = ElementAverageValue
 		variable = N04
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./N05]
 		type = ElementAverageValue
 		variable = N05
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./N06]
 		type = ElementAverageValue
 		variable = N06
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./N07]
 		type = ElementAverageValue
 		variable = N07
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./N08]
 		type = ElementAverageValue
 		variable = N08
 		execute_on = 'initial timestep_end'
	[../]
 
 	[./N09]
 		type = ElementAverageValue
 		variable = N09
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
 
 [./N15]
 type = ElementAverageValue
 variable = N15
 execute_on = 'initial timestep_end'
	[../]
 
 [./N16]
 type = ElementAverageValue
 variable = N16
 execute_on = 'initial timestep_end'
	[../]
 
 [./N17]
 type = ElementAverageValue
 variable = N17
 execute_on = 'initial timestep_end'
	[../]
 
 [./N18]
 type = ElementAverageValue
 variable = N18
 execute_on = 'initial timestep_end'
	[../]
 
 	[./N19]
 		type = ElementAverageValue
 		variable = N19
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
 
 [./N23]
 type = ElementAverageValue
 variable = N23
 execute_on = 'initial timestep_end'
	[../]
 
 [./N24]
 type = ElementAverageValue
 variable = N24
 execute_on = 'initial timestep_end'
	[../]
 
 [./N25]
 type = ElementAverageValue
 variable = N25
 execute_on = 'initial timestep_end'
	[../]
 
 [./N26]
 type = ElementAverageValue
 variable = N26
 execute_on = 'initial timestep_end'
	[../]
 
 [./N27]
 type = ElementAverageValue
 variable = N27
 execute_on = 'initial timestep_end'
	[../]
 
 [./N28]
 type = ElementAverageValue
 variable = N28
 execute_on = 'initial timestep_end'
	[../]
 
 	[./N29]
 		type = ElementAverageValue
 		variable = N29
 		execute_on = 'initial timestep_end'
    [../]
 
 [./N30]
 type = ElementAverageValue
 variable = N30
 execute_on = 'initial timestep_end'
	[../]
 
	[./N31]
 type = ElementAverageValue
 variable = N31
 execute_on = 'initial timestep_end'
	[../]
 
 [./N32]
 type = ElementAverageValue
 variable = N32
 execute_on = 'initial timestep_end'
	[../]
 
 [./N33]
 type = ElementAverageValue
 variable = N33
 execute_on = 'initial timestep_end'
	[../]
 
 [./N34]
 type = ElementAverageValue
 variable = N34
 execute_on = 'initial timestep_end'
	[../]
 
 [./N35]
 type = ElementAverageValue
 variable = N35
 execute_on = 'initial timestep_end'
	[../]
 
 [./N36]
 type = ElementAverageValue
 variable = N36
 execute_on = 'initial timestep_end'
	[../]
 
 [./N37]
 type = ElementAverageValue
 variable = N37
 execute_on = 'initial timestep_end'
	[../]
 
 [./N38]
 type = ElementAverageValue
 variable = N38
 execute_on = 'initial timestep_end'
	[../]
 
 	[./N39]
 		type = ElementAverageValue
 		variable = N39
 		execute_on = 'initial timestep_end'
	[../]
 
 
 [./N40]
 type = ElementAverageValue
 variable = N40
 execute_on = 'initial timestep_end'
	[../]
 
	[./N41]
 type = ElementAverageValue
 variable = N41
 execute_on = 'initial timestep_end'
	[../]
 
 [./N42]
 type = ElementAverageValue
 variable = N42
 execute_on = 'initial timestep_end'
	[../]
 
 [./N43]
 type = ElementAverageValue
 variable = N43
 execute_on = 'initial timestep_end'
	[../]
 
 [./N44]
 type = ElementAverageValue
 variable = N44
 execute_on = 'initial timestep_end'
	[../]
 
 [./N45]
 type = ElementAverageValue
 variable = N45
 execute_on = 'initial timestep_end'
	[../]
 
 [./N46]
 type = ElementAverageValue
 variable = N46
 execute_on = 'initial timestep_end'
	[../]
 
 [./N47]
 type = ElementAverageValue
 variable = N47
 execute_on = 'initial timestep_end'
	[../]
 
 [./N48]
 type = ElementAverageValue
 variable = N48
 execute_on = 'initial timestep_end'
	[../]
 
 	[./N49]
 		type = ElementAverageValue
 		variable = N49
 		execute_on = 'initial timestep_end'
	[../]
 
 
 [./N50]
 type = ElementAverageValue
 variable = N50
 execute_on = 'initial timestep_end'
	[../]
 
	[./N51]
 type = ElementAverageValue
 variable = N51
 execute_on = 'initial timestep_end'
	[../]
 
 [./N52]
 type = ElementAverageValue
 variable = N52
 execute_on = 'initial timestep_end'
	[../]
 
 [./N53]
 type = ElementAverageValue
 variable = N53
 execute_on = 'initial timestep_end'
	[../]
 
 [./N54]
 type = ElementAverageValue
 variable = N54
 execute_on = 'initial timestep_end'
	[../]
 
 [./N55]
 type = ElementAverageValue
 variable = N55
 execute_on = 'initial timestep_end'
	[../]
 
 [./N56]
 type = ElementAverageValue
 variable = N56
 execute_on = 'initial timestep_end'
	[../]
 
 [./N57]
 type = ElementAverageValue
 variable = N57
 execute_on = 'initial timestep_end'
	[../]
 
 [./N58]
 type = ElementAverageValue
 variable = N58
 execute_on = 'initial timestep_end'
	[../]
 
 	[./N59]
 		type = ElementAverageValue
 		variable = N59
 		execute_on = 'initial timestep_end'
	[../]
 
 
 [./N60]
 type = ElementAverageValue
 variable = N60
 execute_on = 'initial timestep_end'
	[../]
 
	[./N61]
 type = ElementAverageValue
 variable = N61
 execute_on = 'initial timestep_end'
	[../]
 
 [./N62]
 type = ElementAverageValue
 variable = N62
 execute_on = 'initial timestep_end'
	[../]
 
 [./N63]
 type = ElementAverageValue
 variable = N63
 execute_on = 'initial timestep_end'
	[../]
 
 [./N64]
 type = ElementAverageValue
 variable = N64
 execute_on = 'initial timestep_end'
	[../]
 
 [./N65]
 type = ElementAverageValue
 variable = N65
 execute_on = 'initial timestep_end'
	[../]
 
 [./N66]
 type = ElementAverageValue
 variable = N66
 execute_on = 'initial timestep_end'
	[../]
 
 [./N67]
 type = ElementAverageValue
 variable = N67
 execute_on = 'initial timestep_end'
	[../]
 
 [./N68]
 type = ElementAverageValue
 variable = N68
 execute_on = 'initial timestep_end'
	[../]
 
 	[./N69]
 		type = ElementAverageValue
 		variable = N69
 		execute_on = 'initial timestep_end'
	[../]
 
 
 [./N70]
 type = ElementAverageValue
 variable = N70
 execute_on = 'initial timestep_end'
	[../]
 
	[./N71]
 type = ElementAverageValue
 variable = N71
 execute_on = 'initial timestep_end'
	[../]
 
 [./N72]
 type = ElementAverageValue
 variable = N72
 execute_on = 'initial timestep_end'
	[../]
 
 [./N73]
 type = ElementAverageValue
 variable = N73
 execute_on = 'initial timestep_end'
	[../]
 
 [./N74]
 type = ElementAverageValue
 variable = N74
 execute_on = 'initial timestep_end'
	[../]
 
 [./N75]
 type = ElementAverageValue
 variable = N75
 execute_on = 'initial timestep_end'
	[../]
 
 [./N76]
 type = ElementAverageValue
 variable = N76
 execute_on = 'initial timestep_end'
	[../]
 
 [./N77]
 type = ElementAverageValue
 variable = N77
 execute_on = 'initial timestep_end'
	[../]
 
 [./N78]
 type = ElementAverageValue
 variable = N78
 execute_on = 'initial timestep_end'
	[../]
 
 	[./N79]
 		type = ElementAverageValue
 		variable = N79
 		execute_on = 'initial timestep_end'
	[../]
 
 
 [./N80]
 type = ElementAverageValue
 variable = N80
 execute_on = 'initial timestep_end'
	[../]
 
	[./N81]
 type = ElementAverageValue
 variable = N81
 execute_on = 'initial timestep_end'
	[../]
 
 [./N82]
 type = ElementAverageValue
 variable = N82
 execute_on = 'initial timestep_end'
	[../]
 
 [./N83]
 type = ElementAverageValue
 variable = N83
 execute_on = 'initial timestep_end'
	[../]
 
 [./N84]
 type = ElementAverageValue
 variable = N84
 execute_on = 'initial timestep_end'
	[../]
 
 [./N85]
 type = ElementAverageValue
 variable = N85
 execute_on = 'initial timestep_end'
	[../]
 
 [./N86]
 type = ElementAverageValue
 variable = N86
 execute_on = 'initial timestep_end'
	[../]
 
 [./N87]
 type = ElementAverageValue
 variable = N87
 execute_on = 'initial timestep_end'
	[../]
 
 [./N88]
 type = ElementAverageValue
 variable = N88
 execute_on = 'initial timestep_end'
	[../]
 
 	[./N89]
 		type = ElementAverageValue
 		variable = N89
 		execute_on = 'initial timestep_end'
	[../]
 
 
 [./N90]
 type = ElementAverageValue
 variable = N90
 execute_on = 'initial timestep_end'
	[../]
 
	[./N91]
 type = ElementAverageValue
 variable = N91
 execute_on = 'initial timestep_end'
	[../]
 
 [./N92]
 type = ElementAverageValue
 variable = N92
 execute_on = 'initial timestep_end'
	[../]
 
 [./N93]
 type = ElementAverageValue
 variable = N93
 execute_on = 'initial timestep_end'
	[../]
 
 [./N94]
 type = ElementAverageValue
 variable = N94
 execute_on = 'initial timestep_end'
	[../]
 
 [./N95]
 type = ElementAverageValue
 variable = N95
 execute_on = 'initial timestep_end'
	[../]
 
 [./N96]
 type = ElementAverageValue
 variable = N96
 execute_on = 'initial timestep_end'
	[../]
 
 [./N97]
 type = ElementAverageValue
 variable = N97
 execute_on = 'initial timestep_end'
	[../]
 
 [./N98]
 type = ElementAverageValue
 variable = N98
 execute_on = 'initial timestep_end'
	[../]
 
 [./N99]
 type = ElementAverageValue
 variable = N99
 execute_on = 'initial timestep_end'
	[../]
 
 
 
	[./total_vol]
		type = ElementAverageValue
		variable = V_total
		execute_on = 'initial timestep_end'
	[../]
 
 	[./total_nuc]
 		type = ElementAverageValue
 		variable = Nuc_total
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
	end_time = 2000.0
    dtmax = 5.0
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
