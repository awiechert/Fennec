/*!
 *  \file mola.cpp mola.h
 *	\brief Molecule Object Library from Atoms
 *  \author Austin Ladshaw
 *	\date 02/24/2014
 *	\copyright This software was designed and built at the Georgia Institute
 *             of Technology by Austin Ladshaw for PhD research in the area
 *             of adsorption and surface science. Copyright (c) 2015, all
 *             rights reserved.
 */

#include "mola.h"

//Default constructor
Molecule::Molecule()
:
atoms(0)
{
	registered = false;
	haveG = false;
	haveHS = false;
	Name = "Unregistered";
	Formula = Name;
	Phase = Name;
	charge = 0;
	molar_weight = 0;
	molar_volume = 0;
	molar_area = 0;
	formation_energy = 0;
	formation_enthalpy = 0;
	formation_entropy = 0;
	PhaseID = OTHER;
}

//Default destructor
Molecule::~Molecule()
{
	
}

//Forming a molecule from its information
Molecule::Molecule(int c,
				   double enthalpy,
				   double entropy,
				   double energy,
				   bool HS,
				   bool G,
				   std::string phase,
				   std::string name,
				   std::string formula,
				   std::string lin_form)
{
	charge = c;
	formation_enthalpy = enthalpy;
	formation_entropy = entropy;
	formation_energy = energy;
	haveHS = HS;
	haveG = G;
	Phase = phase;
	for (int i=0; i<phase.size(); i++)
		phase[i] = tolower(phase[i]);
	if (phase == "aqueous")
		PhaseID = AQUEOUS;
	else if (phase == "solid")
		PhaseID = SOLID;
	else if (phase == "liquid")
		PhaseID = LIQUID;
	else if (phase == "gas")
		PhaseID = GAS;
	else if (phase == "plasma")
		PhaseID = PLASMA;
	else if (phase == "adsorbed")
		PhaseID = ADSORBED;
	else
		PhaseID = OTHER;
	Name = name;
	Formula = formula;
	molar_weight = 0.0;
	registered = true;
	Atom temp;
	std::string c_atom_r, c_atom;
	char c_char;
	int c_num = 1;
	for (long int i=lin_form.length()-1; i>=0; i--)
	{
		c_char = lin_form[i];
		if (isdigit(c_char))
		{
			if (i==0) {mError(string_parse_error); break;}
			c_num = atoi(&c_char);
			int x = 1;
			int a_num;
			char a_char;
			for (long int j=i-1; j>=0; j--)
			{
				a_char = lin_form[j];
				if (!isdigit(a_char)) {break;}
				else
				{
					a_num = atoi(&a_char);
					c_num = c_num + a_num*pow(10,x);
					x++;
					i--;
				}
			}
		}
		else
		{
			c_atom_r+=c_char;
			if (isupper(c_char))
			{
				long int r = c_atom_r.length()-1;
				for (int n=0; n<c_atom_r.length(); n++)
				{
					c_atom.push_back(c_atom_r.at(r));
					r--;
				}
				temp.Register(c_atom);
				for (int j=0; j<c_num; j++)
					atoms.push_back(temp);
				c_num = 1;
				c_atom.clear();
				c_atom_r.clear();
			}
			else{/*No Action*/}
		}
	}
	for (int i=0; i<atoms.size(); i++)
		molar_weight+=atoms[i].AtomicWeight();
	calculateMolarArea();
	calculateMolarVolume();
}

//Register a molecule given all the necessary information
void Molecule::Register(int c,
						double enthalpy,
						double entropy,
						double energy,
						bool HS,
						bool G,
						std::string phase,
						std::string name,
						std::string formula,
						std::string lin_form)
{
	this->charge = c;
	this->formation_enthalpy = enthalpy;
	this->formation_entropy = entropy;
	this->formation_energy = energy;
	this->haveHS = HS;
	this->haveG = G;
	this->Phase = phase;
	for (int i=0; i<phase.size(); i++)
		phase[i] = tolower(phase[i]);
	if (phase == "aqueous")
		this->PhaseID = AQUEOUS;
	else if (phase == "solid")
		this->PhaseID = SOLID;
	else if (phase == "liquid")
		this->PhaseID = LIQUID;
	else if (phase == "gas")
		this->PhaseID = GAS;
	else if (phase == "plasma")
		this->PhaseID = PLASMA;
	else if (phase == "adsorbed")
		this->PhaseID = ADSORBED;
	else
		this->PhaseID = OTHER;
	this->Name = name;
	this->Formula = formula;
	this->molar_weight = 0.0;
	this->atoms.clear();
	this->registered = true;
	if (lin_form == "" || lin_form == " ")
		return;
	Atom temp;
	std::string c_atom_r, c_atom;
	char c_char;
	int c_num = 1;
	for (long int i=lin_form.length()-1; i>=0; i--)
	{
		c_char = lin_form[i];
		if (isdigit(c_char))
		{
			if (i==0) {mError(string_parse_error); return;}
			c_num = atoi(&c_char);
			int x = 1;
			int a_num;
			char a_char;
			for (long int j=i-1; j>=0; j--)
			{
				a_char = lin_form[j];
				if (!isdigit(a_char)) {break;}
				else
				{
					a_num = atoi(&a_char);
					c_num = c_num + a_num*pow(10,x);
					x++;
					i--;
				}
			}
		}
		else
		{
			c_atom_r+=c_char;
			if (isupper(c_char))
			{
				long int r = c_atom_r.length()-1;
				for (int n=0; n<c_atom_r.length(); n++)
				{
					c_atom.push_back(c_atom_r.at(r));
					r--;
				}
				temp.Register(c_atom);
				for (int j=0; j<c_num; j++)
					this->atoms.push_back(temp);
				c_num = 1;
				c_atom.clear();
				c_atom_r.clear();
			}
			else{/*No Action*/}
		}
	}
	for (int i=0; i<this->atoms.size(); i++)
		this->molar_weight+=this->atoms[i].AtomicWeight();
	this->calculateMolarVolume();
	this->calculateMolarArea();
}

//Register a molecule based on a hard-coded library of known molecules
void Molecule::Register(std::string formula)
{
	if (formula.length() == 0) {mError(unregistered_name); return;}
	char first = formula[0];
	
	//Check to see if the second character needs to be read instead
	if (first == '(')
		first = formula[1];
	
	//Searching is done in alphabetical order by first atom in formula for greater efficiency
	if (first == 'A')
	{
		//List of molecules starting with A
		if (formula == "Ag (s)")
		{
			this->Register(0, 0.0, 42.6, 0.0, true, true, "Solid", "Silver", formula, "Ag");
		}
		else if (formula == "Ag + (aq)")
		{
			this->Register(1, 105600.0, 73.4, 77120.0, true, true, "Aqueous", "Silver", formula, "Ag"); //Correct
		}
		else if (formula == "AgBr (s)")
		{
			this->Register(0, -100600.0, 107.0, -96900.0, true, true, "Solid", "Silver-bromide", formula, "AgBr");
		}
		else if (formula == "AgCl (s)")
		{
			this->Register(0, -127100.0, 96.0, -109800.0, true, true, "Solid", "Silver-chloride", formula, "AgCl");
		}
		else if (formula == "AgI (s)")
		{
			this->Register(0, -61840.0, 115.0, -66200.0, true, true, "Solid", "Silver-iodide", formula, "AgI");
		}
		else if (formula == "Ag2S (s)")
		{
			this->Register(0, -29400.0, 14.0, -40700.0, true, true, "Solid", "DiSilver-sulfide", formula, "Ag2S");
		}
		else if (formula == "AgOH (aq)")
		{
			this->Register(0, 0.0, 0.0, -92000.0, false, true, "Aqueous", "Silver-hydroxide", formula, "AgOH"); //Correct
		}
		else if (formula == "Ag(OH)2 - (aq)")
		{
			this->Register(-1, 0.0, 0.0, -260200.0, false, true, "Aqueous", "Silver-dihydroxide", formula, "AgO2H2"); //Correct
		}
		else if (formula == "AgCl (aq)")
		{
			this->Register(0, -72800.0, 154.0, -72800.0, true, true, "Aqueous", "Silver-chloride", formula, "AgCl");
		}
		else if (formula == "AgCl2 - (aq)")
		{
			this->Register(-1, -245200.0, 231.0, -215500.0, true, true, "Aqueous", "Silver-dichloride", formula, "AgCl2");
		}
		else if (formula == "Al (s)")
		{
			this->Register(0, 0.0, 28.3, 0.0, true, true, "Solid", "Aluminum", formula, "Al");
		}
		else if (formula == "Al 3+ (aq)")
		{
			this->Register(3, -531000.0, -308.0, -489400.0, true, true, "Aqueous", "Aluminum", formula, "Al"); //Correct
		}
		else if (formula == "AlOH 2+ (aq)")
		{
			this->Register(2, 0.0, 0.0, -698000.0, false, true, "Aqueous", "Aluminum-hydroxide", formula, "AlOH"); //Correct
		}
		else if (formula == "Al(OH)2 + (aq)")
		{
			this->Register(1, 0.0, 0.0, -906116.0, false, true, "Aqueous", "Aluminum-dihydroxide", formula, "AlO2H2"); //Correct
		}
		else if (formula == "Al(OH)3 (aq)")
		{
			this->Register(0, 0.0, 0.0, -1109625.0, false, true, "Aqueous", "Aluminum-trihydroxide", formula, "AlO3H3"); //Correct
		}
		else if (formula == "Al(OH)4 - (aq)")
		{
			this->Register(-1, 0.0, 0.0, -1306859.0, false, true, "Aqueous", "Aluminum-tetrahydroxide", formula, "AlO4H4"); //Correct
		}
		else if (formula == "Al2O3 (s)")
		{
			this->Register(0, -1676000.0, 50.9, -1582000.0, true, true, "Solid", "Corundum", formula, "Al2O3");
		}
		else if (formula == "AlOOH (s)")
		{
			this->Register(0, -1000000.0, 17.8, -922000.0, true, true, "Solid", "Boehmite", formula, "AlOOH");
		}
		else if (formula == "Al(OH)3 (s)")
		{
			this->Register(0, -1293000.0, 68.4, -1155000.0, true, true, "Solid", "Gibbsite", formula, "AlO3H3");
		}
		else if (formula == "Al2Si2(OH)4 (s)")
		{
			this->Register(0, -4120000.0, 203.0, -3799000.0, true, true, "Solid", "Kaolinite", formula, "Al2Si2O4H4");
		}
		else if (formula == "As (s)")
		{
			this->Register(0, 0.0, 35.1, 0.0, true, true, "Solid", "Arsenic", formula, "As");
		}
		else if (formula == "AsO4 3- (aq)")
		{
			this->Register(-3, -870300.0, -145.0, -636000.0, true, true, "Aqueous", "Arsenate", formula, "AsO4");
		}
		else
		{
			mError(unregistered_name); return;
		}
	}
	else if (first == 'B')
	{
		//List of molecules starting with B
		if (formula == "Ba 2+ (aq)")
		{
			this->Register(2, -537600.0, 9.6, -560700.0, true, true, "Aqueous", "Barium", formula, "Ba"); //Correct
		}
		else if (formula == "BaSO4 (s)")
		{
			this->Register(0, -1473000.0, 132.0, -1362000.0, true, true, "Solid", "Barite", formula, "BaSO4");
		}
		else if (formula == "BaCO3 (s)")
		{
			this->Register(0, -1211000.0, 112.0, -1132000.0, true, true, "Solid", "Witherite", formula, "BaCO3");
		}
		else if (formula == "Be 2+ (aq)")
		{
			this->Register(2, -382000.0, -130.0, -380000.0, true, true, "Aqueous", "Beryllium", formula, "Be");
		}
		else if (formula == "Be(OH)2 (s)")
		{
			this->Register(0, -902000.0, 51.9, -815000.0, true, true, "Solid", "Beryllium-dihydroxide", formula, "BeO2H2");
		}
		else if (formula == "Be3(OH)3 3+ (aq)")
		{
			this->Register(3, 0.0, 0.0, -1802000.0, false, true, "Aqueous", "TriBeryllium-trihydroxide", formula, "Be3O3H3");
		}
		else if (formula == "B(OH)4 - (aq)")
		{
			this->Register(-1, -1344000.0, 102.0, -1153300.0, true, true, "Aqueous", "Tetrahydroxy-borate", formula, "BO4H4"); //Correct
		}
		else if (formula == "B(OH)3 (aq)")
		{
			this->Register(0, -1072000.0, 162.0, -968700.0, true, true, "Aqueous", "Boric-Acid", formula, "H3BO3"); //Correct
		}
		else if (formula == "Br2 (l)")
		{
			this->Register(0, 0.0, 152.0, 0.0, true, true, "Liquid", "Bromide", formula, "Br2");
		}
		else if (formula == "Br2 (aq)")
		{
			this->Register(0, -2590.0, 130.5, 3930.0, true, true, "Aqueous", "Bromide", formula, "Br2");
		}
		else if (formula == "Br - (aq)")
		{
			this->Register(-1, -121500.0, 82.4, -104000.0, true, true, "Aqueous", "Bromine", formula, "Br"); //Correct
		}
		else if (formula == "BrO - (aq)")
		{
			this->Register(-1, -94100.0, 42.0, -33500.0, true, true, "Aqueous", "Hypobromite", formula, "BrO"); //Correct
		}
		else
		{
			mError(unregistered_name); return;
		}
	}
	else if (first == 'C')
	{
		//List of molecules starting with C
		if (formula == "CO3 2- (aq)")
		{
			this->Register(-2, -677100.0, -56.9, -527900.0, true, true, "Aqueous", "Carbonate", "CO3 2- (aq)", "CO3"); //Correct
		}
		else if (formula == "Cl - (aq)")
		{
			this->Register(-1, -167200.0, 56.5, -131300.0, true, true, "Aqueous", "Chloride", formula, "Cl"); //Correct
		}
		else if (formula == "CaCl2 (aq)")
		{
			this->Register(0, -795420.0, 108.4, -816050.0, true, true, "Aqueous", "Calcium-chloride", formula, "CaCl2"); //Correct
		}
		else if (formula == "CaAl2Si2O8 (s)")
		{
			this->Register(0, -4243000, 199.0, -4017300.0, true, true, "Solid", "Anorthite", formula, "CaAl2Si2O8");
		}
		else if (formula == "C (s)")
		{
			this->Register(0, 0.0, 152.0, 0.0, true, true, "Solid", "Graphite", formula, "C");
		}
		else if (formula == "CO2 (g)")
		{
			this->Register(0, -393500.0, 213.6, -394370.0, true, true, "Gas", "Carbon-dioxide", formula, "CO2");
		}
		else if (formula == "CH4 (g)")
		{
			this->Register(0, -74800.0, 186.0, -50750.0, true, true, "Gas", "Methane", formula, "CH4");
		}
		else if (formula == "CH4 (aq)")
		{
			this->Register(0, -89040.0, 83.7, -34390.0, true, true, "Aqueous", "Methane", formula, "CH4");
		}
		else if (formula == "CH3OH (aq)")
		{
			this->Register(0, -245900.0, 133.0, -175400.0, true, true, "Aqueous", "Methanol", formula, "CH3OH");
		}
		else if (formula == "CN - (aq)")
		{
			this->Register(-1, 150600.0, 94.1, 172400.0, true, true, "Aqueous", "Cyanide", formula, "CN"); //Correct
		}
		else if (formula == "CH3COOH (aq)")
		{
			this->Register(0, -485800.0, 179.0, -396600.0, true, true, "Aqueous", "Acetic-Acid", formula, "CH3COOH");
		}
		else if (formula == "CH3COO - (aq)")
		{
			this->Register(-1, -486000.0, 86.6, -369400.0, true, true, "Aqueous", "Acetate", formula, "CH3COO");
		}
		else if (formula == "C2H5OH (aq)")
		{
			this->Register(0, -288300.0, 149.0, -181800.0, true, true, "Aqueous", "Ethanol", formula, "C2H5OH");
		}
		else if (formula == "Ca 2+ (aq)")
		{
			this->Register(2, -542830.0, -53.0, -553540.0, true, true, "Aqueous", "Calcium", formula, "Ca"); //Correct
		}
		else if (formula == "CaOH + (aq)")
		{
			this->Register(1, 0.0, 0.0, -718400.0, false, true, "Aqueous", "Calcium-hydroxide", formula, "CaOH"); //Correct
		}
		else if (formula == "Ca(OH)2 (aq)")
		{
			this->Register(0, -1003000.0, -74.5, -868310.0, true, true, "Aqueous", "Calcium-dihydroxide", formula, "CaO2H2"); //Correct
		}
		else if (formula == "CaUO2(CO3)3 2- (aq)")
		{
			this->Register(-2, 0.0, 0.0, -3244677.0, false, true, "Aqueous", "Calcium-uranyl-tricarbonate", formula, "CaUO2C3O9"); //Correct
		}
		else if (formula == "Ca2UO2(CO3)3 (aq)")
		{
			this->Register(0, 0.0, 0.0, -3816643.0, false, true, "Aqueous", "DiCalcium-uranyl-tricarbonate", formula, "Ca2UO2C3O9"); //Correct
		}
		else if (formula == "Ca(OH)2 (s)")
		{
			this->Register(0, -986000.0, 83.0, -898400.0, true, true, "Solid", "Portlandite", formula, "CaO2H2");
		}
		else if (formula == "CaCO3 (s)")
		{
			this->Register(0, -1207400.0, 91.7, -1128800.0, true, true, "Solid", "Calcite", formula, "CaCO3");
		}
		else if (formula == "CaMg(CO3)2 (s)")
		{
			this->Register(0, -2324500.0, 155.2, -2161700.0, true, true, "Solid", "Dolomite", formula, "CaMgCO3CO3");
		}
		else if (formula == "CaSiO3 (s)")
		{
			this->Register(0, -1635200.0, 82.0, -1549900.0, true, true, "Solid", "Wollastonite", formula, "CaSiO3");
		}
		else if (formula == "CaSO4 (s)")
		{
			this->Register(0, -1434100.0, 106.7, -1321700.0, true, true, "Solid", "Anhydrite", formula, "CaSO4");
		}
		else if (formula == "CaSO4(H2O)2 (s)")
		{
			this->Register(0, -2022600.0, 194.1, -1797200.0, true, true, "Solid", "Gypsum", formula, "CaSO4H2OH2O");
		}
		else if (formula == "Ca5(PO4)3OH (s)")
		{
			this->Register(0, -6721600.0, 390.4, -6338400.0, true, true, "Solid", "Hydroxyapatite", formula, "Ca5P3O12OH");
		}
		else if (formula == "Cd 2+ (aq)")
		{
			this->Register(2, -75900.0, -73.2, -77580.0, true, true, "Aqueous", "Cadmium", formula, "Cd"); //Correct
		}
		else if (formula == "CdOH + (aq)")
		{
			this->Register(1, 0.0, 0.0, -257255.0, false, true, "Aqueous", "Cadmium-hydroxide", formula, "CdOH"); //Correct
		}
		else if (formula == "Cd(OH)3 - (aq)")
		{
			this->Register(-1, 0.0, 0.0, -599149.0, false, true, "Aqueous", "Cadmium-trihydroxide", formula, "CdO3H3"); //Correct
		}
		else if (formula == "Cd(OH)4 2- (aq)")
		{
			this->Register(-2, 0.0, 0.0, -756176.0, false, true, "Aqueous", "Cadmium-tetrahydroxide", formula, "CdO4H4"); //Correct
		}
		else if (formula == "Cd(OH)2 (aq)")
		{
			this->Register(0, 0.0, 0.0, -435846.0, false, true, "Aqueous", "Cadmium-dihydroxide", formula, "CdO2H2"); //Correct
		}
		else if (formula == "CdO (s)")
		{
			this->Register(0, -258100.0, 54.8, -228400.0, true, true, "Solid", "Cadmium-oxide", formula, "CdO");
		}
		else if (formula == "Cd(OH)2 (s)")
		{
			this->Register(0, -560600.0, 96.2, -473600.0, true, true, "Solid", "Cadmium-dihydroxide", formula, "CdO2H2");
		}
		else if (formula == "CdCl + (aq)")
		{
			this->Register(1, -240600.0, 43.5, -224400.0, true, true, "Aqueous", "Cadmium-chloride", formula, "CdCl");
		}
		else if (formula == "CdCl2 (aq)")
		{
			this->Register(0, -410200.0, 39.8, -340100.0, true, true, "Aqueous", "Cadmium-dichloride", formula, "CdCl2");
		}
		else if (formula == "CdCl3 - (aq)")
		{
			this->Register(-1, -561000.0, 203.0, -487000.0, true, true, "Aqueous", "Cadmium-trichloride", formula, "CdCl3");
		}
		else if (formula == "CdCO3 (s)")
		{
			this->Register(0, -750600.0, 92.5, -669400.0, true, true, "Solid", "Cadmium-carbonate", formula, "CdCO3");
		}
		else if (formula == "Cl2 (g)")
		{
			this->Register(0, 0.0, 223.0, 0.0, true, true, "Gas", "Chlorine", formula, "Cl2");
		}
		else if (formula == "Cl2 (aq)")
		{
			this->Register(0, -23400.0, 121.0, 6900.0, true, true, "Aqueous", "Chlorine", formula, "Cl2"); //Correct
		}
		else if (formula == "ClO - (aq)")
		{
			this->Register(-1, -107100.0, 42.0, -36800.0, true, true, "Aqueous", "Hypochlorite", formula, "ClO");
		}
		else if (formula == "ClO2 (aq)")
		{
			this->Register(0, 74900.0, 173.0, 117600.0, true, true, "Aqueous", "Chlorine-dioxide", formula, "ClO2");
		}
		else if (formula == "ClO2 - (aq)")
		{
			this->Register(-1, -66500.0, 101.0, 17100.0, true, true, "Aqueous", "Chlorine-dioxide", formula, "ClO2");
		}
		else if (formula == "ClO3 - (aq)")
		{
			this->Register(-1, -99200.0, 162.0, -3350.0, true, true, "Aqueous", "Chlorine-trioxide", formula, "ClO3");
		}
		else if (formula == "ClO4 (aq)")
		{
			this->Register(0, -129300.0, 182.0, -8620.0, true, true, "Aqueous", "Perchlorate", formula, "ClO4");
		}
		else if (formula == "Co (s)")
		{
			this->Register(0, 0.0, 0.0, 30040.0, true, true, "Solid", "Cobalt", formula, "Co");
		}
		else if (formula == "Co 2+ (aq)")
		{
			this->Register(2, -58200.0, -113.0, -54400.0, true, true, "Aqueous", "Cobalt(II)", formula, "Co"); //Correct
		}
		else if (formula == "Co 3+ (aq)")
		{
			this->Register(3, -92000.0, -305.0, -134000.0, true, true, "Aqueous", "Cobalt(III)", formula, "Co"); //Correct
		}
		else if (formula == "CoOH + (aq)")
		{
			this->Register(1, 0.0, 0.0, -239000.0, false, true, "Aqueous", "Cobalt(II)-hydroxide", formula, "CoOH"); //Correct
		}
		else if (formula == "Co(OH)2 (aq)")
		{
			this->Register(0, 0.0, 0.0, -424337.0, false, true, "Aqueous", "Cobalt(II)-dihydroxide", formula, "CoO2H2"); //Correct
		}
		else if (formula == "Co(OH)3 - (aq)")
		{
			this->Register(-1, 0.0, 0.0, -587912.0, false, true, "Aqueous", "Cobalt(II)-trihydroxide", formula, "CoO3H3"); //Correct
		}
		else if (formula == "Co(OH)2 (s)")
		{
			this->Register(0, 0.0, 0.0, -450000.0, false, true, "Solid", "Cobalt(II)-hydroxide", formula, "CoO2H2");
		}
		else if (formula == "CoO (s)")
		{
			this->Register(0, -237900.0, 53.0, -214200.0, true, true, "Solid", "Cobalt(II)-oxide", formula, "CoO");
		}
		else if (formula == "Co3O4 (s)")
		{
			this->Register(0, -891200.0, 102.5, -725500.0, true, true, "Solid", "Cobalt(1-II)(2-III)-oxide", formula, "Co3O4");
		}
		else if (formula == "Cr (s)")
		{
			this->Register(0, 0.0, 23.8, 0.0, true, true, "Solid", "Chromium", formula, "Cr");
		}
		else if (formula == "Cr 2+ (aq)")
		{
			this->Register(2, -143500.0, 0.0, 0.0, true, false, "Aqueous", "Chromium(II)", formula, "Cr");
		}
		else if (formula == "Cr 3+ (aq)")
		{
			this->Register(3, -256000.0, 308.0, -215500.0, true, true, "Aqueous", "Chromium(III)", formula, "Cr"); //Correct
		}
		else if (formula == "CrOH 2+ (aq)")
		{
			this->Register(2, 0.0, 0.0, -429848.0, false, true, "Aqueous", "Chromium(III)-hydroxide", formula, "CrOH"); //Correct
		}
		else if (formula == "Cr(OH)2 + (aq)")
		{
			this->Register(1, 0.0, 0.0, -634955.0, false, true, "Aqueous", "Chromium(III)-dihydroxide", formula, "CrO2H2"); //Correct
		}
		else if (formula == "Cr(OH)3 (aq)")
		{
			this->Register(0, 0.0, 0.0, -831447.0, false, true, "Aqueous", "Chromium(III)-trihydroxide", formula, "CrO3H3"); //Correct
		}
		else if (formula == "Cr(OH)4 - (aq)")
		{
			this->Register(-1, 0.0, 0.0, -1005747.0, false, true, "Aqueous", "Chromium(III)-tetrahydroxide", formula, "CrO4H4"); //Correct
		}
		else if (formula == "Cr2O3 (s)")
		{
			this->Register(0, -1153000.0, 81.0, -1053000.0, true, true, "Solid", "Eskolaite", formula, "Cr2O3");
		}
		else if (formula == "CrO4 2- (aq)")
		{
			this->Register(-2, -881100.0, 50.0, -727900.0, true, true, "Aqueous", "Chromate", formula, "CrO4");
		}
		else if (formula == "Cr2O7 2- (aq)")
		{
			this->Register(-2, -1490000.0, 262.0, -1301000.0, true, true, "Aqueous", "DiChromate", formula, "Cr2O7");
		}
		else if (formula == "Cu (s)")
		{
			this->Register(0, 0.0, 33.1, 0.0, true, true, "Solid", "Copper", formula, "Cu");
		}
		else if (formula == "Cu + (aq)")
		{
			this->Register(1, 71700.0, 40.6, 50000.0, true, true, "Aqueous", "Copper(I)", formula, "Cu");
		}
		else if (formula == "Cu 2+ (aq)")
		{
			this->Register(2, 64800.0, -99.6, 65500.0, true, true, "Aqueous", "Copper(II)", formula, "Cu"); //Correct
		}
		else if (formula == "CuOH + (aq)")
		{
			this->Register(1, 0.0, 0.0, -126029.0, false, true, "Aqueous", "Copper(II)-hydroxide", formula, "CuOH"); //Correct
		}
		else if (formula == "Cu(OH)2 (aq)")
		{
			this->Register(0, 0.0, 0.0, -330793.0, false, true, "Aqueous", "Copper(II)-dihydroxide", formula, "CuO2H2"); //Correct
		}
		else if (formula == "Cu(OH)3 - (aq)")
		{
			this->Register(-1, 0.0, 0.0, -492543.0, false, true, "Aqueous", "Copper(II)-trihydroxide", formula, "CuO3H3"); //Correct
		}
		else if (formula == "Cu(OH)4 2- (aq)")
		{
			this->Register(-2, 0.0, 0.0, -657259.0, false, true, "Aqueous", "Copper(II)-tetrahydroxide", formula, "CuO4H4"); //Correct
		}
		else if (formula == "CuS (s)")
		{
			this->Register(0, -53100.0, 66.5, -53600.0, true, true, "Solid", "Covellite", formula, "CuS");
		}
		else if (formula == "Cu2S (s)")
		{
			this->Register(0, -79500.0, 121.0, -86200.0, true, true, "Solid", "DiCopper(I)-Sulfide", formula, "Cu2S");
		}
		else if (formula == "CuO (s)")
		{
			this->Register(0, -157300.0, 43.0, -129700.0, true, true, "Solid", "Tenorite", formula, "CuO");
		}
		else if (formula == "CuCO3Cu(OH)2 (s)")
		{
			this->Register(0, -1051400.0, 186.0, -893700.0, true, true, "Solid", "Malachite", formula, "CuCO3CuO2H2");
		}
		else if (formula == "(CuCO3)2Cu(OH)2 (s)")
		{
			this->Register(0, -1632000.0, 0.0, 0.0, true, false, "Solid", "Azurite", formula, "CuCO3CuCO3CuO2H2");
		}
		else
		{
			mError(unregistered_name); return;
		}
	}
	else if (first == 'D')
	{
		//List of molecules starting with D
		mError(unregistered_name); return;
	}
	else if (first == 'E')
	{
		//List of molecules starting with E
		mError(unregistered_name); return;
	}
	else if (first == 'F')
	{
		//List of molecules starting with F
		if (formula == "F2 (g)")
		{
			this->Register(0, 0.0, 202.0, 0.0, true, true, "Gas", "Fluorine", formula, "F2");
		}
		else if (formula == "F - (aq)")
		{
			this->Register(-1, -332600.0, -13.8, -278800.0, true, true, "Aqueous", "Fluoride", formula, "F"); //Correct
		}
		else if (formula == "Fe (s)")
		{
			this->Register(0, 0.0, 27.3, 0.0, true, true, "Solid", "Iron", formula, "Fe");
		}
		else if (formula == "Fe 2+ (aq)")
		{
			this->Register(2, -89100.0, -138.0, -78870.0, true, true, "Aqueous", "Iron(II)", formula, "Fe"); //Correct
		}
		else if (formula == "FeOH + (aq)")
		{
			this->Register(1, 0.0, 0.0, -261842.0, false, true, "Aqueous", "Iron(II)-hydroxide", formula, "FeOH"); //Correct
		}
		else if (formula == "Fe(OH)2 (aq)")
		{
			this->Register(0, 0.0, 0.0, -436998.0, false, true, "Aqueous", "Iron(II)-dihydroxide", formula, "FeO2H2"); //Correct
		}
		else if (formula == "Fe(OH)3 - (aq)")
		{
			this->Register(-1, 0.0, 0.0, -613523.0, false, true, "Aqueous", "Iron(II)-trihydroxide", formula, "FeO3H3"); //Correct
		}
		else if (formula == "Fe 3+ (aq)")
		{
			this->Register(3, -48500.0, -316.0, -4600.0, true, true, "Aqueous", "Iron(III)", formula, "Fe"); //Correct
		}
		else if (formula == "FeOH 2+ (aq)")
		{
			this->Register(2, 0.0, 0.0, -229400.0, false, true, "Aqueous", "Iron(III)-hydroxide", formula, "FeOH"); //Correct
		}
		else if (formula == "Fe(OH)2 + (aq)")
		{
			this->Register(1, 0.0, 0.0, -446700.0, false, true, "Aqueous", "Iron(III)-dihydroxide", formula, "FeO2H2"); //Correct
		}
		else if (formula == "Fe(OH)3 (aq)")
		{
			this->Register(0, 0.0, 0.0, -638517.0, false, true, "Aqueous", "Iron(III)-trihydroxide", formula, "FeO3H3"); //Correct
		}
		else if (formula == "Fe(OH)4 - (aq)")
		{
			this->Register(-1, 0.0, 0.0, -830046.0, false, true, "Aqueous", "Iron(III)-tetrahydroxide", formula, "FeO4H4"); //Correct
		}
		else if (formula == "Fe2(OH)2 4+ (aq)")
		{
			this->Register(4, 0.0, 0.0, -467300.0, false, true, "Aqueous", "DiIron(III)-dihydroxide", formula, "Fe2O2H2"); //Correct
		}
		else if (formula == "FeS2 (s)")
		{
			this->Register(0, -171500.0, 52.9, -160200.0, true, true, "Solid", "Pyrite", formula, "FeS2");
		}
		else if (formula == "FeO (s)")
		{
			this->Register(0, -272000.0, 59.8, -251100.0, true, true, "Solid", "Iron(II)-oxide", formula, "FeO");
		}
		else if (formula == "Fe(OH)2 (s)")
		{
			this->Register(0, -569000.0, 87.9, -486600.0, true, true, "Solid", "Iron(II)-dihydroxide", formula, "FeO2H2");
		}
		else if (formula == "Fe2O3 (s)")
		{
			this->Register(0, -824600.0, 87.4, -742700.0, true, true, "Solid", "Hematite", formula, "Fe2O3");
		}
		else if (formula == "Fe3O4 (s)")
		{
			this->Register(0, -1115700.0, 146.0, -1012600.0, true, true, "Solid", "Magnetite", formula, "Fe3O4");
		}
		else if (formula == "FeOOH (s)")
		{
			this->Register(0, -559300.0, 60.5, -488600.0, true, true, "Solid", "Goethite", formula, "FeOOH");
		}
		else if (formula == "Fe(OH)3 (s)")
		{
			this->Register(0, 0.0, 0.0, -705500.0, false, true, "Solid", "Iron(III)-trihydroxide", formula, "FeO3H3");
		}
		else if (formula == "FeCO3 (s)")
		{
			this->Register(0, -737000.0, 105.0, -666700.0, true, true, "Solid", "Siderite", formula, "FeCO3");
		}
		else if (formula == "Fe2SiO4 (s)")
		{
			this->Register(0, -1479300.0, 148.0, -1379400.0, true, true, "Solid", "Fayalite", formula, "Fe2SiO4");
		}
		else
		{
			mError(unregistered_name); return;
		}
	}
	else if (first == 'G')
	{
		//List of molecules starting with G
		mError(unregistered_name); return;
	}
	else if (first == 'H')
	{
		//List of molecules starting with H
		if (formula == "H2O (l)")
		{
			this->Register(0,-285830.0,69.95,-237180.0,true,true,"Liquid","Water","H2O (l)","H2O"); //Correct
		}
		else if (formula == "H + (aq)")
		{
			this->Register(1,0.0,0.0,0.0,true,true,"Aqueous","Proton","H + (aq)","H"); //Correct
		}
		else if (formula == "H2CO3 (aq)")
		{
			this->Register(0, -699700.0, 187.0, -623200.0, true, true, "Aqueous", "Carbonic-Acid", "H2CO3 (aq)", "H2CO3"); //Correct
		}
		else if (formula == "HCO3 - (aq)")
		{
			this->Register(-1, -692000.0, 91.2, -586800.0, true, true, "Aqueous", "Bicarbonate", "HCO3 - (aq)", "HCO3"); //Correct
		}
		else if (formula == "HNO3 (aq)")
		{
			this->Register(0, -207300.0, 146.0, -111300.0, true, true, "Aqueous", "Nitric-Acid", formula, "HNO3"); //Correct
		}
		else if (formula == "HCl (aq)")
		{
			this->Register(0,-167160.0,56.48,-131300.0,true,true,"Aqueous","Hydrochloric-Acid","HCl (aq)","HCl"); //Correct
		}
		else if (formula == "H3AsO4 (aq)")
		{
			this->Register(0, -898700.0, 206.0, -766000.0, true, true, "Aqueous", "Arsenic-Acid", formula, "H3AsO4");
		}
		else if (formula == "H2AsO4 - (aq)")
		{
			this->Register(-1, -904500.0, 117.0, -748500.0, true, true, "Aqueous", "Dihydrogen-arsenate", formula, "H2AsO4");
		}
		else if (formula == "HAsO4 2- (aq)")
		{
			this->Register(-2, -898700.0, 3.8, -707100.0, true, true, "Aqueous", "Hydrogen-arsenate", formula, "HAsO4");
		}
		else if (formula == "H2AsO3 - (aq)")
		{
			this->Register(-1, 0.0, 0.0, -587400.0, false, true, "Aqueous", "Dihydrogen-arsenite", formula, "H2AsO3");
		}
		else if (formula == "HBrO (aq)")
		{
			this->Register(0, -113000.0, 147.0, -82200.0, true, true, "Aqueous", "Hypobromous-Acid", formula, "HBrO"); //Correct
		}
		else if (formula == "HCOOH (aq)")
		{
			this->Register(0, -425400.0, 163.0, -372300.0, true, true, "Aqueous", "Formic-Acid", formula, "HCOOH");
		}
		else if (formula == "HCOO - (aq)")
		{
			this->Register(-1, -425600.0, 92.0, -351000.0, true, true, "Aqueous", "Formate", formula, "HCOO");
		}
		else if (formula == "HCN (aq)")
		{
			this->Register(0, 107100.0, 124.6, 119700.0, true, true, "Aqueous", "Hydrogen-cyanide", formula, "HCN"); //Correct
		}
		else if (formula == "HClO (aq)")
		{
			this->Register(0, -120900.0, 142.0, -79900.0, true, true, "Aqueous", "Hypochlorous-Acid", formula, "HClO");
		}
		else if (formula == "HCoO2 - (aq)")
		{
			this->Register(-1, 0.0, 0.0, -407500.0, false, true, "Aqueous", "Hypocobalt-dioxide", formula, "HCoO2");
		}
		else if (formula == "HCrO4 - (aq)")
		{
			this->Register(-1, -878200.0, 184.0, -764800.0, true, true, "Aqueous", "Hydrogen-chromate", formula, "HCrO4");
		}
		else if (formula == "HCuO2 - (aq)")
		{
			this->Register(-1, 0.0, 0.0, -258000.0, false, true, "Aqueous", "Hydrogen-copper-dioxide", formula, "HCuO2");
		}
		else if (formula == "HF (aq)")
		{
			this->Register(0, -320000.0, 88.7, -296800.0, true, true, "Aqueous", "Hydrofluoric-Acid", formula, "HF"); //Correct
		}
		else if (formula == "HF2 - (aq)")
		{
			this->Register(-1, -650000.0, 92.5, -578100.0, true, true, "Aqueous", "BiFluoride", formula, "HFF"); //Correct
		}
		else if (formula == "H2 (g)")
		{
			this->Register(0, 0.0, 130.6, 0.0, true, true, "Gas", "Hydrogen", formula, "H2");
		}
		else if (formula == "H2 (aq)")
		{
			this->Register(0, -4180.0, 57.7, 17570.0, true, true, "Aqueous", "Hydrogen", formula, "H2");
		}
		else if (formula == "H2O2 (aq)")
		{
			this->Register(0, -191100.0, 144.0, -134100.0, true, true, "Aqueous", "Hydrogen-peroxide", formula, "H2O2");
		}
		else if (formula == "HO2 - (aq)")
		{
			this->Register(-1, -160300.0, 23.8, -67400.0, true, true, "Aqueous", "Peroxide", formula, "HO2");
		}
		else if (formula == "H2O (g)")
		{
			this->Register(0, -241800.0, 188.72, -228570.0, true, true, "Gas", "Water-vapor", formula, "H2O");
		}
		else if (formula == "Hg (l)")
		{
			this->Register(0, 0.0, 76.0, 0.0, true, true, "Liquid", "Mercury", formula, "Hg");
		}
		else if (formula == "Hg2 2+ (aq)")
		{
			this->Register(2, 172400.0, 84.5, 153600.0, true, true, "Aqueous", "Mercury(I)", formula, "Hg2");
		}
		else if (formula == "Hg 2+ (aq)")
		{
			this->Register(2, 171000.0, -32.2, 164400.0, true, true, "Aqueous", "Mercury(II)", formula, "Hg"); //Correct
		}
		else if (formula == "HgOH + (aq)")
		{
			this->Register(1, 0.0, 0.0, -53371.0, false, true, "Aqueous", "Mercury(II)-hydroxide", formula, "HgOH"); //Correct
		}
		else if (formula == "Hg(OH)2 (aq)")
		{
			this->Register(0, 0.0, 0.0, -275136.0, false, true, "Aqueous", "Mercury(II)-dihydroxide", formula, "HgO2H2"); //Correct
		}
		else if (formula == "Hg(OH)3 - (aq)")
		{
			this->Register(-1, 0.0, 0.0, -490967.0, false, true, "Aqueous", "Mercury(II)-trihydroxide", formula, "HgO3H3"); //Correct
		}
		else if (formula == "Hg2Cl2 (s)")
		{
			this->Register(0, 265200.0, 192.4, -210800.0, true, true, "Solid", "Calomel", formula, "Hg2Cl2");
		}
		else if (formula == "HgO (s)")
		{
			this->Register(0, -90800.0, 70.3, -58500.0, true, true, "Solid", "Mercury(II)-oxide", formula, "HgO");
		}
		else if (formula == "HgS (s)")
		{
			this->Register(0, -46700.0, 96.2, -43300.0, true, true, "Solid", "Metacinnabar", formula, "HgS");
		}
		else if (formula == "HgI2 (s)")
		{
			this->Register(0, -105400.0, 180.0, -101700.0, true, true, "Solid", "Mercury(II)-iodide", formula, "HgI2");
		}
		else if (formula == "HgCl + (aq)")
		{
			this->Register(1, -18800.0, 75.3, -5440.0, true, true, "Aqueous", "Mercury(II)-chloride", formula, "HgCl");
		}
		else if (formula == "HgCl2 (aq)")
		{
			this->Register(0, -216300.0, 155.0, -173200.0, true, true, "Aqueous", "Mercury(II)-dichloride", formula, "HgCl2");
		}
		else if (formula == "HgCl3 - (aq)")
		{
			this->Register(-1, -388700.0, 209.0, -309200.0, true, true, "Aqueous", "Mercury(II)-trichloride", formula, "HgCl3");
		}
		else if (formula == "HgCl4 2- (aq)")
		{
			this->Register(-2, -544000.0, 293.0, -446800.0, true, true, "Aqueous", "Mercury(II)-tetrachloride", formula, "HgCl4");
		}
		else if (formula == "HgOH + (aq)")
		{
			this->Register(1, -84500.0, 71.0, -52300.0, true, true, "Aqueous", "Mercury(II)-hydroxide", formula, "HgOH");
		}
		else if (formula == "Hg(OH)2 (aq)")
		{
			this->Register(0, -355200.0, 142.0, -274900.0, true, true, "Aqueous", "Mercury(II)-dihydroxide", formula, "HgO2H2");
		}
		else if (formula == "HgO2 - (aq)")
		{
			this->Register(-1, 0.0, 0.0, -190300.0, false, true, "Aqueous", "Mercury(II)-dioxide", formula, "HgO2");
		}
		else if (formula == "HIO (aq)")
		{
			this->Register(0, -138000.0, 95.4, -99200.0, true, true, "Aqueous", "Hypoiodous-Acid", formula, "HIO");
		}
		else if (formula == "HIO3 (aq)")
		{
			this->Register(0, -211300.0, 167.0, -132600.0, true, true, "Aqueous", "Iodic-Acid", formula, "HIO3");
		}
		else if (formula == "HNO2 (aq)")
		{
			this->Register(0, -119200.0, 153.0, -42970.0, true, true, "Aqueous", "Nitrous-Acid", formula, "HNO2");
		}
		else if (formula == "HPO4 2- (aq)")
		{
			this->Register(-2, -1292100.0, -33.4, -1089300.0, true, true, "Aqueous", "Hydrogen-phosphate", formula, "HPO4"); //Correct
		}
		else if (formula == "H2PO4 - (aq)")
		{
			this->Register(-1, -1296300.0, 90.4, -1130400.0, true, true, "Aqueous", "DiHydrogen-phosphate", formula, "H2PO4"); //Correct
		}
		else if (formula == "H3PO4 (aq)")
		{
			this->Register(0, -1288300.0, 158.0, -1142600.0, true, true, "Aqueous", "Phosphoric-Acid", formula, "H3PO4"); //Correct
		}
		else if (formula == "H2S (g)")
		{
			this->Register(0, -20630.0, 205.7, -33560.0, true, true, "Gas", "Hydrogen-sulfide", formula, "H2S");
		}
		else if (formula == "H2S (aq)")
		{
			this->Register(0, -39750.0, 121.3, -27870.0, true, true, "Aqueous", "Hydrogen-sulfide", formula, "H2S"); //Correct
		}
		else if (formula == "HS - (aq)")
		{
			this->Register(-1, -17600.0, 62.8, 12050.0, true, true, "Aqueous", "Bisulfide", formula, "HS"); //Correct
		}
		else if (formula == "HSO3 - (aq)")
		{
			this->Register(-1, -626200.0, 140.0, -527800.0, true, true, "Aqueous", "Hydrogen-sulfite", formula, "HSO3");
		}
		else if (formula == "H2SO3 (aq)")
		{
			this->Register(0, -608800.0, 232.0, -537900.0, true, true, "Aqueous", "Sulfurous-Acid", formula, "H2SO3");
		}
		else if (formula == "HSO4 - (aq)")
		{
			this->Register(-1, -887300.0, 132.0, -756000.0, true, true, "Aqueous", "Hydrogen-sulfate", formula, "HSO4"); //Correct
		}
		else if (formula == "H2SO4 (aq)")
		{
			this->Register(0, -814000.0, 157.0, -690394.0, true, true, "Aqueous", "Sulfuric-Acid", formula, "H2SO4"); //Correct
		}
		else if (formula == "HSeO3 - (aq)")
		{
			this->Register(-1, -514500.0, 135.0, -431500.0, true, true, "Aqueous", "Hydrogen-selenite", formula, "HSeO3");
		}
		else if (formula == "H2SeO3 (aq)")
		{
			this->Register(0, -507500.0, 208.0, -426200.0, true, true, "Aqueous", "Selenous-Acid", formula, "H2SeO3");
		}
		else if (formula == "HSeO4 - (aq)")
		{
			this->Register(-1, -581600.0, 149.0, -452300.0, true, true, "Aqueous", "Hydrogen-selenate", formula, "HSeO4");
		}
		else if (formula == "H4SiO4 (aq)")
		{
			this->Register(0, -1468600.0, 180.0, -1316700.0, true, true, "Aqueous", "Silicic-Acid", formula, "H4SiO4");
		}
		else if (formula == "HV2O5 - (aq)")
		{
			this->Register(-1, 0.0, 0.0, -1508960.0, false, true, "Aqueous", "Vanadium(IV)-oxide-Acid", formula, "HV2O5");
		}
		else if (formula == "H4VO4 + (aq)")
		{
			this->Register(1, 0.0, 0.0, -1030000.0, false, true, "Aqueous", "Vanadium(V)-oxide-Acid", formula, "H4VO4"); //Correct
		}
		else if (formula == "H3VO4 (aq)")
		{
			this->Register(0, 0.0, 0.0, -1040000.0, false, true, "Aqueous", "Trihydro-Vanadium(V)-oxide", formula, "H3VO4"); //Correct
		}
		else if (formula == "H2VO4 - (aq)")
		{
			this->Register(-1, 0.0, 0.0, -1020000.0, false, true, "Aqueous", "Dihydro-Vanadium(V)-oxide", formula, "H2VO4"); //Correct
		}
		else if (formula == "HVO4 2- (aq)")
		{
			this->Register(-2, 0.0, 0.0, -975000.0, false, true, "Aqueous", "Hydro-Vanadium(V)-oxide", formula, "HVO4"); //Correct
		}
		else if (formula == "H4VO4(C2O4)2 3- (aq)")
		{
			this->Register(-3, 0.0, 0.0, -2467000.0, false, true, "Aqueous", "Vanadium(V)-oxide-dioxalate", formula, "H4VO4C4O8");
		}
		else if (formula == "H4VO4C2O4 - (aq)")
		{
			this->Register(-1, 0.0, 0.0, -1774000.0, false, true, "Aqueous", "Vanadium(V)-oxide-oxalate", formula, "H4VO4C2O4");
		}
		else if (formula == "H2V10O28 4- (aq)")
		{
			this->Register(-4, 0.0, 0.0, -7729000.0, false, true, "Aqueous", "Vanadium(V)-oxide-Acid", formula, "H2V10O28");
		}
		else if (formula == "HV10O28 5- (aq)")
		{
			this->Register(-5, 0.0, 0.0, -7708000.0, false, true, "Aqueous", "Hydro-Vanadium(V)-oxide", formula, "HV10O28");
		}
		else if (formula == "HV2O7 3- (aq)")
		{
			this->Register(-3, 0.0, 0.0, -1792000.0, false, true, "Aqueous", "Hydro-Vanadium(V)-oxide", formula, "HV2O7"); //Correct
		}
		else
		{
			mError(unregistered_name); return;
		}
		
	}
	else if (first == 'I')
	{
		//List of molecules starting with I
		if (formula == "I2 (s)")
		{
			this->Register(0, 0.0, 116.0, 0.0, true, true, "Solid", "Iodine", formula, "I2");
		}
		else if (formula == "I2 (aq)")
		{
			this->Register(0, 22600.0, 137.0, 16400.0, true, true, "Aqueous", "Iodine", formula, "I2");
		}
		else if (formula == "I - (aq)")
		{
			this->Register(-1, -55190.0, 111.0, -51590.0, true, true, "Aqueous", "Iodide", formula, "I");
		}
		else if (formula == "I3 - (aq)")
		{
			this->Register(-1, -51500.0, 239.0, -51500.0, true, true, "Aqueous", "TriIodide", formula, "I3");
		}
		else if (formula == "IO - (aq)")
		{
			this->Register(-1, -107500.0, -5.4, -38500.0, true, true, "Aqueous", "Hypoiodite", formula, "IO");
		}
		else if (formula == "IO3 - (aq)")
		{
			this->Register(-1, -221300.0, 118.0, -128000.0, true, true, "Aqueous", "Iodite", formula, "IO3");
		}
		else
		{
			mError(unregistered_name); return;
		}
	}
	else if (first == 'J')
	{
		//List of molecules starting with J
		mError(unregistered_name); return;
	}
	else if (first == 'K')
	{
		//List of molecules starting with K
		if (formula == "KAl3Si3O10(OH)2 (s)")
		{
			this->Register(0, 0.0, 0.0, -1341000.0, false, true, "Solid", "Muscovite", formula, "KAl3Si3O12H2");
		}
		else if (formula == "K + (aq)")
		{
			this->Register(1, -252140.0, 102.5, 0.0, true, false, "Aqueous", "Potassium", formula, "K"); //Correct
		}
		else
		{
			mError(unregistered_name); return;
		}
	}
	else if (first == 'L')
	{
		//List of molecules starting with L
		mError(unregistered_name); return;
	}
	else if (first == 'M')
	{
		//List of molecules starting with M
		if (formula == "Mg(OH)2 (aq)")
		{
			this->Register(0, -923671.0, -149.0, -769400.0, true, true, "Aqueous", "Magnesium-dihydroxide", formula, "MgO2H2"); //Correct
		}
		else if (formula == "Mg5Al2Si3O10(OH)8 (s)")
		{
			this->Register(0, 0.0, 0.0, -1962000.0, false, true, "Solid", "Chlorite", formula, "Mg5Al2Si3O18H8");
		}
		else if (formula == "Mg (s)")
		{
			this->Register(0, 0.0, 32.7, 0.0, true, true, "Solid", "Magnesium", formula, "Mg");
		}
		else if (formula == "Mg 2+ (aq)")
		{
			this->Register(2, -466800.0, -138.0, -454800.0, true, true, "Aqueous", "Magnesium", formula, "Mg"); //Correct
		}
		else if (formula == "MgOH + (aq)")
		{
			this->Register(1, 0.0, 0.0, -626800.0, false, true, "Aqueous", "Magnesium-hydroxide", formula, "MgOH"); //Correct
		}
		else if (formula == "MgUO2(CO3)3 2- (aq)")
		{
			this->Register(-2, 0.0, 0.0, -3140517.0, false, true, "Aqueous", "Magnesium-uranyl-tricarbonate", formula, "MgUO2C3O9"); //Correct
		}
		else if (formula == "Mg(OH)2 (s)")
		{
			this->Register(0, -924500.0, 63.2, -833500.0, true, true, "Solid", "Brucite", formula, "MgO2H2");
		}
		else if (formula == "Mn (s)")
		{
			this->Register(0, 0.0, 32.0, 0.0, true, true, "Solid", "Manganese", formula, "Mn");
		}
		else if (formula == "Mn 2+ (aq)")
		{
			this->Register(2, -220700.0, -73.6, -228000.0, true, true, "Aqueous", "Manganese", formula, "Mn"); //Correct
		}
		else if (formula == "Mn(OH)2 (s)")
		{
			this->Register(0, 0.0, 0.0, -616000.0, false, true, "Solid", "Manganese-dihydroxide", formula, "MnO2H2");
		}
		else if (formula == "Mn3O4 (s)")
		{
			this->Register(0, 0.0, 0.0, -1281000.0, false, true, "Solid", "Hausmannite", formula, "Mn3O4");
		}
		else if (formula == "MnOOH (s)")
		{
			this->Register(0, 0.0, 0.0, -557700.0, false, true, "Solid", "Manganite", formula, "MnOOH");
		}
		else if (formula == "MnO2 (s)")
		{
			this->Register(0, -520000.0, 53.0, -465100.0, true, true, "Solid", "Pyrolusite", formula, "MnO2");
		}
		else if (formula == "MnCO3 (s)")
		{
			this->Register(0, -889300.0, 100.0, -816000.0, true, true, "Solid", "Rhodochrosite", formula, "MnCO3");
		}
		else if (formula == "MnS (s)")
		{
			this->Register(0, -213800.0, 87.0, -218100.0, true, true, "Solid", "Albandite", formula, "MnS");
		}
		else if (formula == "MnSiO3 (s)")
		{
			this->Register(0, -1319000.0, 131.0, -1243000.0, true, true, "Solid", "Rhodonite", formula, "MnSiO3");
		}
		else
		{
			mError(unregistered_name); return;
		}
	}
	else if (first == 'N')
	{
		//List of molecules starting with N
		if (formula == "NaHCO3 (aq)")
		{
			this->Register(0,-945530.0,100.0,-847328.0,true,true,"Aqueous","Sodium-Bicarbonate",formula,"NaHCO3"); //Correct
		}
		else if (formula == "NaCO3 - (aq)")
		{
			this->Register(-1,-937550.0,-41.85,-797049.0,true,true,"Aqueous","Sodium-Carbonate",formula,"NaCO3"); //Correct
		}
		else if (formula == "Na2CO3 (aq)")
		{
			this->Register(0,0.0,0.0,-1051600.0,false,true,"Aqueous","DiSodium-Carbonate",formula,"Na2CO3"); //Correct
		}
		else if (formula == "Na + (aq)")
		{
			this->Register(1,-240100.0,59.0,-261900.0,true,true,"Aqueous","Sodium",formula,"Na"); //Correct
		}
		else if (formula == "NaCl (aq)")
		{
			this->Register(0,-407300.0,115.5,-393170.0,true,true,"Aqueous","Sodium-Chloride",formula,"NaCl"); //Correct
		}
		else if (formula == "NaOH (aq)")
		{
			this->Register(0,-470110.0,48.1,-419200.0,true,true,"Aqueous","Sodium-Hydroxide",formula,"NaOH");  //Correct
		}
		else if (formula == "NaNO3 (aq)")
		{
			this->Register(0,0.0,0.0,-373210.0,false,true,"Aqueous","Sodium-Nitrate",formula,"NaNO3"); //Correct
		}
		else if (formula == "NO3 - (aq)")
		{
			this->Register(-1,-207300.0,146.4,-111300.0,true,true,"Aqueous","Nitrate",formula,"NO3"); //Correct
		}
		else if (formula == "NH3 (aq)")
		{
			this->Register(0, -80290.0, 111.0, -26570.0, true, true, "Aqueous", "Ammonia", formula, "NH3"); //Correct
		}
		else if (formula == "NaAlSiO3O8 (s)")
		{
			this->Register(0, -3935100, -749.7, -3711700.0, true, true, "Solid", "Albite", formula, "NaAlSiO3O8");
		}
		else if (formula == "NH2CH2COOH (aq)")
		{
			this->Register(0, -514000.0, 158.0, -370800.0, true, true, "Aqueous", "Glycine", formula, "NH2CH2COOH");
		}
		else if (formula == "NH2CH2COO - (aq)")
		{
			this->Register(-1, -469800.0, 119.0, -315000.0, true, true, "Aqueous", "Glycinate", formula, "NH2CH2COO");
		}
		else if (formula == "N2 (g)")
		{
			this->Register(0, 0.0, 191.5, 0.0, true, true, "Gas", "Nitrogen", formula, "N2");
		}
		else if (formula == "N2O (g)")
		{
			this->Register(0, 82000.0, 220.0, 104200.0, true, true, "Gas", "Nitrous-oxide", formula, "N2O");
		}
		else if (formula == "NH3 (g)")
		{
			this->Register(0, -46100.0, 192.0, -16480.0, true, true, "Gas", "Ammonia", formula, "NH3");
		}
		else if (formula == "NH4 + (aq)")
		{
			this->Register(1, -132500.0, 113.4, -79370.0, true, true, "Aqueous", "Ammonium", formula, "NH4"); //Correct
		}
		else if (formula == "NO2 - (aq)")
		{
			this->Register(-1, -104600.0, 140.0, -37200.0, true, true, "Aqueous", "Nitrite", formula, "NO2");
		}
		else if (formula == "Ni 2+ (aq)")
		{
			this->Register(2, -54000.0, -129.0, -45600.0, true, true, "Aqueous", "Nickel", formula, "Ni"); //Correct
		}
		else if (formula == "NiOH + (aq)")
		{
			this->Register(1, 0.0, 0.0, -226518.0, false, true, "Aqueous", "Nickel-hydroxide", formula, "NiOH"); //Correct
		}
		else if (formula == "Ni(OH)2 (aq)")
		{
			this->Register(0, 0.0, 0.0, -411543.0, false, true, "Aqueous", "Nickel-dihydroxide", formula, "NiO2H2"); //Correct
		}
		else if (formula == "Ni(OH)3 - (aq)")
		{
			this->Register(-1, 0.0, 0.0, -585958.0, false, true, "Aqueous", "Nickel-trihydroxide", formula, "NiO3H3"); //Correct
		}
		else if (formula == "NiO (s)")
		{
			this->Register(0, -239700.0, 38.0, -211600.0, true, true, "Solid", "Bunsenite", formula, "NiO");
		}
		else if (formula == "NiS (s)")
		{
			this->Register(0, -84900.0, 66.0, -86200.0, true, true, "Solid", "Millerite", formula, "NiS");
		}
		else
		{
			mError(unregistered_name); return;
		}
	}
	else if (first == 'O')
	{
		//List of molecules starting with O
		if (formula == "OH - (aq)")
		{
			this->Register(-1,-230000.0,-10.75,-157300.0,true,true,"Aqueous","Hydroxide","OH - (aq)","OH"); //Correct
		}
		else if (formula == "O2 (g)")
		{
			this->Register(0, 0.0, 205.0, -86200.0, true, true, "Gas", "Oxygen", formula, "O2");
		}
		else if (formula == "O2 (aq)")
		{
			this->Register(0, -11710.0, 111.0, 16320.0, true, true, "Aqueous", "Oxygen", formula, "O2");
		}
		else if (formula == "O3 (g)")
		{
			this->Register(0, 142700.0, 239.0, 163200.0, true, true, "Gas", "Ozone", formula, "O3");
		}
		else
		{
			mError(unregistered_name); return;
		}
	}
	else if (first == 'P')
	{
		//List of molecules starting with P
		if (formula == "P (s)")
		{
			this->Register(0, 0.0, 41.1, 0.0, true, true, "Solid", "Phosphorus", formula, "P");
		}
		else if (formula == "PO4 3- (aq)")
		{
			this->Register(-3, -1277400.0, -222.0, -1018800.0, true, true, "Aqueous", "Phosphate", formula, "PO4"); //Correct
		}
		else if (formula == "Pb (s)")
		{
			this->Register(0, 0.0, 64.8, 0.0, true, true, "Solid", "Lead", formula, "Pb");
		}
		else if (formula == "Pb 2+ (aq)")
		{
			this->Register(2, -1670.0, 10.5, -24390.0, true, true, "Aqueous", "Lead", formula, "Pb"); //Correct
		}
		else if (formula == "PbOH + (aq)")
		{
			this->Register(1, 0.0, 0.0, -216300.0, false, true, "Aqueous", "Lead-hydroxide", formula, "PbOH"); //Correct
		}
		else if (formula == "Pb(OH)2 (aq)")
		{
			this->Register(0, 0.0, 0.0, -401058.0, false, true, "Aqueous", "Lead-dihydroxide", formula, "PbO2H2"); //Correct
		}
		else if (formula == "Pb(OH)3 - (aq)")
		{
			this->Register(-1, 0.0, 0.0, -575700.0, false, true, "Aqueous", "Lead-trihydroxide", formula, "PbO3H3"); //Correct
		}
		else if (formula == "Pb(OH)4 2- (aq)")
		{
			this->Register(-2, 0.0, 0.0, -746579.0, false, true, "Aqueous", "Lead-tetrahydroxide", formula, "PbO4H4"); //Correct
		}
		else if (formula == "Pb(OH)2 (s)")
		{
			this->Register(0, 0.0, 0.0, -452200.0, false, true, "Solid", "Lead-dihydroxide", formula, "PbO2H2");
		}
		else if (formula == "PbO (s)")
		{
			this->Register(0, -217300.0, 68.7, -187900.0, true, true, "Solid", "Lead-oxide", formula, "PbO");
		}
		else if (formula == "PbO2 (s)")
		{
			this->Register(0, -277400.0, 68.6, -217400.0, true, true, "Solid", "Lead-dioxide", formula, "PbO2");
		}
		else if (formula == "Pb3O4 (s)")
		{
			this->Register(0, -718400.0, 211.0, -601200.0, true, true, "Solid", "Lead-oxide", formula, "Pb3O4");
		}
		else if (formula == "PbS (s)")
		{
			this->Register(0, -100400.0, 91.2, -98700.0, true, true, "Solid", "Lead-sulfide", formula, "PbS");
		}
		else if (formula == "PbSO4 (s)")
		{
			this->Register(0, -920000.0, 149.0, -813200.0, true, true, "Solid", "Lead-sulfate", formula, "PbSO4");
		}
		else if (formula == "PbCO3 (s)")
		{
			this->Register(0, -699100.0, 131.0, -625500.0, true, true, "Solid", "Cerussite", formula, "PbCO3");
		}
		else
		{
			mError(unregistered_name); return;
		}
	}
	else if (first == 'Q')
	{
		//List of molecules starting with Q
		mError(unregistered_name); return;
	}
	else if (first == 'R')
	{
		//List of molecules starting with R
		mError(unregistered_name); return;
	}
	else if (first == 'S')
	{
		//List of molecules starting with S
		if (formula == "S (s)")
		{
			this->Register(0, 0.0, 31.8, 0.0, true, true, "Solid", "Sulfur", formula, "S");
		}
		else if (formula == "SO2 (g)")
		{
			this->Register(0, -296800.0, 248.0, -300200.0, true, true, "Gas", "Sulfur-dioxide", formula, "SO2");
		}
		else if (formula == "SO3 (g)")
		{
			this->Register(0, -395700.0, 257.0, -371100.0, true, true, "Gas", "Sulfur-trioxide", formula, "SO3");
		}
		else if (formula == "S 2- (aq)")
		{
			this->Register(-2, 33000.0, -14.6, 85800.0, true, true, "Aqueous", "Sulfide", formula, "S"); //Correct
		}
		else if (formula == "SO3 2- (aq)")
		{
			this->Register(-2, -635500.0, -29.0, -486600.0, true, true, "Aqueous", "Sulfite", formula, "SO3");
		}
		else if (formula == "SO4 2- (aq)")
		{
			this->Register(-2, -909200.0, 20.1, -744600.0, true, true, "Aqueous", "Sulfate", formula, "SO4"); //Correct
		}
		else if (formula == "Se (s)")
		{
			this->Register(0, 0.0, 42.4, 0.0, true, true, "Solid", "Selenium", formula, "Se");
		}
		else if (formula == "SeO3 2- (aq)")
		{
			this->Register(-2, -509200.0, 12.6, -369900.0, true, true, "Aqueous", "Selenite", formula, "SeO3");
		}
		else if (formula == "SeO4 2- (aq)")
		{
			this->Register(-2, -599100.0, 54.0, -441400.0, true, true, "Aqueous", "Selenate", formula, "SeO4");
		}
		else if (formula == "Si (s)")
		{
			this->Register(0, 0.0, 18.8, 0.0, true, true, "Solid", "Silicon", formula, "Si");
		}
		else if (formula == "SiO2 (s)")
		{
			this->Register(0, -903490.0, 46.9, -850730.0, true, true, "Solid", "Silicon-dioxide", formula, "SiO2");
		}
		else if (formula == "Sr 2+ (aq)")
		{
			this->Register(2, -545800.0, -33.0, -559400.0, true, true, "Aqueous", "Strontium", formula, "Sr"); //Correct
		}
		else if (formula == "SrOH + (aq)")
		{
			this->Register(1, 0.0, 0.0, -721000.0, false, true, "Aqueous", "Strontium-hydroxide", formula, "SrOH"); //Correct
		}
		else if (formula == "SrCO3 (s)")
		{
			this->Register(0, -1218700.0, 97.0, -1137600.0, true, true, "Solid", "Strontianite", formula, "SrCO3");
		}
		else if (formula == "SrSO4 (s)")
		{
			this->Register(0, -1453200.0, 118.0, -1341000.0, true, true, "Solid", "Celestite", formula, "SrSO4");
		}
		else
		{
			mError(unregistered_name); return;
		}
	}
	else if (first == 'T')
	{
		//List of molecules starting with T
		mError(unregistered_name); return;
	}
	else if (first == 'U')
	{
		//List of molecules starting with U
		if (formula == "UO2 2+ (aq)")
		{
			this->Register(2,-1019000.0,-98.2,-952551.0,true,true,"Aqueous","Uranyl","UO2 2+ (aq)","UO2"); //Correct
		}
		else if (formula == "UO2NO3 + (aq)")
		{
			this->Register(1,0.0,0.0,-1065557.0,false,true,"Aqueous","Uranyl-nitrate",formula,"UO2NO3"); //Correct
		}
		else if (formula == "UO2(NO3)2 (aq)")
		{
			this->Register(0,0.0,0.0,-1105803.0,false,true,"Aqueous","Uranyl-dinitrate",formula,"UO2N2O6"); //Correct
		}
		else if (formula == "UO2OH + (aq)")
		{
			this->Register(1,-1261371.0,17.0,-1159724.0,true,true,"Aqueous","Uranyl-hydroxide",formula,"UO2OH"); //Correct
		}
		else if (formula == "UO2(OH)2 (aq)")
		{
			this->Register(0,0,0,-1357479.0,false,true,"Aqueous","Uranyl-dihydroxide",formula,"UO2O2H2"); //Correct
		}
		else if (formula == "UO2(OH)3 - (aq)")
		{
			this->Register(-1,0.0,0.0,-1546571.0,false,true,"Aqueous","Uranyl-trihydroxide",formula,"UO2O3H3"); //Correct
		}
		else if (formula == "UO2(OH)4 2- (aq)")
		{
			this->Register(-2,0.0,0.0,-1716171.0,false,true,"Aqueous","Uranyl-tetrahydroxide",formula,"UO2O4H4"); //Correct
		}
		else if (formula == "(UO2)2OH 3+ (aq)")
		{
			this->Register(3,0.0,0.0,-2126830.0,false,true,"Aqueous","Diuranyl-hydroxide",formula,"U2O4OH"); //Correct
		}
		else if (formula == "(UO2)2(OH)2 2+ (aq)")
		{
			this->Register(2,-2572065.0,-38.0,-2347303.0,true,true,"Aqueous","Diuranyl-dihydroxide",formula,"U2O4O2H2"); //Correct
		}
		else if (formula == "(UO2)3(OH)4 2+ (aq)")
		{
			this->Register(2,0.0,0.0,-3738288.0,false,true,"Aqueous","Triuranyl-tetrahydroxide",formula,"U3O6O4H4"); //Correct
		}
		else if (formula == "(UO2)3(OH)5 + (aq)")
		{
			this->Register(1,-4389086.0,83.0,-3954594.0,true,true,"Aqueous","Triuranyl-pentahydroxide",formula,"U3O6O5H5"); //Correct
		}
		else if (formula == "(UO2)3(OH)7 - (aq)")
		{
			this->Register(-1,0,0,-4333835.0,false,true,"Aqueous","Triuranyl-heptahydroxide",formula,"U3O6O7H7"); //Correct
		}
		else if (formula == "(UO2)4(OH)7 + (aq)")
		{
			this->Register(1,0,0,-5345179.0,false,true,"Aqueous","Tetrauranyl-heptahydroxide",formula,"U4O8O7H7"); //Correct
		}
		else if (formula == "UO2CO3 (aq)")
		{
			this->Register(0,-1689230.0,58.870,-1537188.0,true,true,"Aqueous","Uranyl-carbonate",formula,"UO2CO3"); //Correct
		}
		else if (formula == "UO2(CO3)2 2- (aq)")
		{
			this->Register(-2,-2350960.0,181.846,-2103161.0,true,true,"Aqueous","Uranyl-dicarbonate",formula,"UO2C2O6"); //Correct
		}
		else if (formula == "UO2(CO3)3 4- (aq)")
		{
			this->Register(-4,-3083890.0,38.446,-2660914.0,true,true,"Aqueous","Uranyl-tricarbonate","UO2(CO3)3 4- (aq)","UO2C3O9"); //Correct
		}
		else if (formula == "UO2Cl + (aq)")
		{
			this->Register(1, 0.0, 0.0, -1084821.0, false, true, "Aqueous", "Uranyl-chloride", formula, "UO2Cl"); //Correct
		}
		else if (formula == "UO2Cl2 (aq)")
		{
			this->Register(0, 0.0, 0.0, -1208876.0, false, true, "Aqueous", "Uranyl-dichloride", formula, "UO2Cl2"); //Correct
		}
		else if (formula == "UO2Cl3 - (aq)")
		{
			this->Register(-1, 0.0, 0.0, -1331618.0, false, true, "Aqueous", "Uranyl-trichloride", formula, "UO2Cl3"); //Correct
		}
		else if (formula == "UO2SO4 (aq)")
		{
			this->Register(0, 0.0, 0.0, -1706849.0, false, true, "Aqueous", "Uranyl-sulfate", formula, "UO2SO4"); //Correct
		}
		else if (formula == "UO2(SO4)2 2- (aq)")
		{
			this->Register(-2, 0.0, 0.0, -2456241.0, false, true, "Aqueous", "Uranyl-disulfate", formula, "UO2S2O8"); //Correct
		}
		else
		{
			mError(unregistered_name); return;
		}
	}
	else if (first == 'V')
	{
		//List of molecules starting with V
		if (formula == "VO 2+ (aq)")
		{
			this->Register(2, -486600.0, -133.9, -446400.0, true, true, "Aqueous", "Vanadyl(IV)", formula, "VO"); //Correct
		}
		else if (formula == "VOOH + (aq)")
		{
			this->Register(1, -717400.0, 12.0, -651200.0, true, true, "Aqueous", "Vanadyl(IV)-hydroxide", formula, "VOOH");
		}
		else if (formula == "VO(OH)2 (s)")
		{
			this->Register(0, 0.0, 0.0, -885800.0, false, true, "Solid", "Vanadyl(IV)-dihydroxide", formula, "VOO2H2");
		}
		else if (formula == "V2O4 (s)")
		{
			this->Register(0, 0.0, 0.0, -1318600.0, false, true, "Solid", "Vanadium(IV)-oxide", formula, "V2O4");
		}
		else if (formula == "(VO)2(OH)2 + (aq)")
		{
			this->Register(1, -1434000.0, 115.9, -1329000.0, true, true, "Aqueous", "DiVanadyl(IV)-dihydroxide", formula, "V2O2O2H2");
		}
		else if (formula == "VOF + (aq)")
		{
			this->Register(1, 0.0, 0.0, -745000.0, false, true, "Aqueous", "Vanadyl(IV)-fluoride", formula, "VOF");
		}
		else if (formula == "VOF2 (aq)")
		{
			this->Register(0, 0.0, 0.0, -1033000.0, false, true, "Aqueous", "Vanadyl(IV)-difluoride", formula, "VOF2");
		}
		else if (formula == "VOF3 - (aq)")
		{
			this->Register(-1, 0.0, 0.0, -1322000.0, false, true, "Aqueous", "Vanadyl(IV)-trifluoride", formula, "VOF3");
		}
		else if (formula == "VOF4 2- (aq)")
		{
			this->Register(-2, 0.0, 0.0, -1604000.0, false, true, "Aqueous", "Vanadyl(IV)-tetrafluoride", formula, "VOF4");
		}
		else if (formula == "VOCl + (aq)")
		{
			this->Register(1, 0.0, 0.0, -577000.0, false, true, "Aqueous", "Vanadyl(IV)-chloride", formula, "VOCl");
		}
		else if (formula == "VOSO4 (aq)")
		{
			this->Register(0, -1380000.0, -13.4, -1205000.0, true, true, "Aqueous", "Vanadyl(IV)-sulfate", formula, "VOSO4");
		}
		else if (formula == "VO(C2O4)2 2- (aq)")
		{
			this->Register(-2, 0.0, 0.0, -1868000.0, false, true, "Aqueous", "Vanadyl(IV)-dioxalate", formula, "VOC4O8");
		}
		else if (formula == "VOOHC2O4 - (aq)")
		{
			this->Register(-1, 0.0, 0.0, -1365000.0, false, true, "Aqueous", "Vanadyl(IV)-hydroxide-oxalate", formula, "VOOHC2O4");
		}
		else if (formula == "VOCH3COO + (aq)")
		{
			this->Register(1, 0.0, 0.0, -826400.0, false, true, "Aqueous", "Vanadyl(IV)-acetate", formula, "VOCH3COO");
		}
		else if (formula == "VO(CH3COO)2 (aq)")
		{
			this->Register(0, 0.0, 0.0, -1200000.0, false, true, "Aqueous", "Vanadyl(IV)-diacetate", formula, "VOC2H6C2O2O2");
		}
		else if (formula == "VOCO3 (aq)")
		{
			this->Register(0, -1150000.0, -65.9, -994000.0, true, true, "Aqueous", "Vanadyl(IV)-carbonate", formula, "VOCO3");
		}
		else if (formula == "VOOHCO3 - (aq)")
		{
			this->Register(-1, 0.0, 0.0, -1220000.0, false, true, "Aqueous", "Vanadyl(IV)-hydroxide-carbonate", formula, "VOOHCO3");
		}
		else if (formula == "V4O9 2- (aq)")
		{
			this->Register(-2, 0.0, 0.0, -2784000.0, false, true, "Aqueous", "Vanadium(IV)-oxide", formula, "V4O9");
		}
		else if (formula == "VO2 + (aq)")
		{
			this->Register(1, 0.0, 0.0, -587000.0, false, true, "Aqueous", "Vanadyl(V)", formula, "VO2"); //Correct
		}
		else if (formula == "VO4 3- (aq)")
		{
			this->Register(-3, 0.0, 0.0, -899000.0, false, true, "Aqueous", "Vanadium(V)-oxide", formula, "VO4"); //Correct
		}
		else if (formula == "V2O5 (s)")
		{
			this->Register(0, 0.0, 0.0, -1419400.0, false, true, "Solid", "Vanadium(V)-oxide", formula, "V2O5");
		}
		else if (formula == "V10O28 6- (aq)")
		{
			this->Register(-6, 0.0, 0.0, -7675000.0, false, true, "Aqueous", "Vanadium(V)-oxide", formula, "V10O28");
		}
		else if (formula == "V2O7 4- (aq)")
		{
			this->Register(-4, 0.0, 0.0, -1720000.0, false, true, "Aqueous", "Vanadium(V)-oxide", formula, "V2O7"); //Correct
		}
		else if (formula == "V4O12 4- (aq)")
		{
			this->Register(-4, 0.0, 0.0, -3202000.0, false, true, "Aqueous", "Vanadium(V)-oxide", formula, "V4O12");
		}
		else if (formula == "VO2SO4 - (aq)")
		{
			this->Register(-1, 0.0, 0.0, -1337000.0, false, true, "Aqueous", "Vanadyl(V)-sulfate", formula, "VO2SO4"); //Correct
		}
		else if (formula == "VO2OHCO3 2- (aq)")
		{
			this->Register(-2, 0.0, 0.0, -1375869.0, false, true, "Aqueous", "Vanadyl(V)-hydroxide-carbonate", formula, "VO2OHCO3"); //Correct
		}
		else if (formula == "VO2(CO3)2 3- (aq)")
		{
			this->Register(-3, 0.0, 0.0, -1720271.0, false, true, "Aqueous", "Vanadyl(V)-dicarbonate", formula, "VO2C2O6"); //Correct
		}
		else
		{
			mError(unregistered_name); return;
		}
	}
	else if (first == 'W')
	{
		//List of molecules starting with W
		mError(unregistered_name); return;
	}
	else if (first == 'X')
	{
		//List of molecules starting with X
		mError(unregistered_name); return;
	}
	else if (first == 'Y')
	{
		//List of molecules starting with Y
		mError(unregistered_name); return;
	}
	else if (first == 'Z')
	{
		//List of molecules starting with Z
		if (formula == "Zn (s)")
		{
			this->Register(0, 0.0, 29.3, 0.0, true, true, "Solid", "Zinc", formula, "Zn");
		}
		else if (formula == "Zn 2+ (aq)")
		{
			this->Register(2, -153900.0, 112.0, -147000.0, true, true, "Aqueous", "Zinc", formula, "Zn"); //Correct
		}
		else if (formula == "ZnOH + (aq)")
		{
			this->Register(1, 0.0, 0.0, -330100.0, false, true, "Aqueous", "Zinc-hydroxide", formula, "ZnOH"); //Correct
		}
		else if (formula == "Zn(OH)2 (aq)")
		{
			this->Register(0, 0.0, 0.0, -522300.0, false, true, "Aqueous", "Zinc-dihydroxide", formula, "ZnO2H2"); //Correct
		}
		else if (formula == "Zn(OH)3 - (aq)")
		{
			this->Register(-1, 0.0, 0.0, -694300.0, false, true, "Aqueous", "Zinc-trihydroxide", formula, "ZnO3H3"); //Correct
		}
		else if (formula == "Zn(OH)4 2- (aq)")
		{
			this->Register(-2, 0.0, 0.0, -858700.0, false, true, "Aqueous", "Zinc-tetrahydroxide", formula, "ZnO4H4"); //Correct
		}
		else if (formula == "Zn(OH)2 (s)")
		{
			this->Register(0, -641900.0, 81.2, -553200.0, true, true, "Solid", "Zinc-dihydroxide", formula, "ZnO2H2");
		}
		else if (formula == "ZnCl + (aq)")
		{
			this->Register(1, 0.0, 0.0, -275300.0, false, true, "Aqueous", "Zinc-chloride", formula, "ZnCl");
		}
		else if (formula == "ZnCl2 (aq)")
		{
			this->Register(0, 0.0, 0.0, -403800.0, false, true, "Aqueous", "Zinc-dichloride", formula, "ZnCl2");
		}
		else if (formula == "ZnCl3 - (aq)")
		{
			this->Register(-1, 0.0, 0.0, -540600.0, false, true, "Aqueous", "Zinc-trichloride", formula, "ZnCl3");
		}
		else if (formula == "ZnCl4 2- (aq)")
		{
			this->Register(-2, 0.0, 0.0, -666100.0, false, true, "Aqueous", "Zinc-tetrachloride", formula, "ZnCl4");
		}
		else if (formula == "ZnCO3 (s)")
		{
			this->Register(0, -812800.0, 82.4, -731600.0, true, true, "Solid", "Smithsonite", formula, "ZnCO3");
		}
		else
		{
			mError(unregistered_name); return;
		}
	}
	else {mError(unregistered_name); return;}
	this->registered = true;
}

//Set the formula for a given molecule (useful for working with unregistered molecules)
void Molecule::setFormula(std::string form)
{
	this->Formula = form;
}

//Function forces calculation of molar weight based on current atomic makeup
void Molecule::calculateMolarWeight()
{
	this->molar_weight = 0.0;
	for (int i=0; i<this->atoms.size(); i++)
	{
		this->molar_weight+=this->atoms[i].AtomicWeight();
	}
}

//Function to calculate van der Waals volume of molecule
void Molecule::calculateMolarVolume()
{
	this->molar_volume = 0.0;
	for (int i=0; i<this->atoms.size(); i++)
	{
		this->molar_volume+= SphereVolume(this->atoms[i].AtomicRadii()) ;
	}
}

//Function to calculate van der Waals area of molecule
void Molecule::calculateMolarArea()
{
	this->molar_area = 0.0;
	for (int i=0; i<this->atoms.size(); i++)
	{
		this->molar_area+= SphereArea(this->atoms[i].AtomicRadii()) ;
	}
}

//Set the molar weight of the molecule to a constant
void Molecule::setMolarWeigth(double mw)
{
	this->molar_weight = mw;
}

//Set the van der Waals volume of the molecule
void Molecule::setMolarVolume(double v)
{
	this->molar_volume = v;
}

//Set the van der Waals area of the molecule
void Molecule::setMolarArea(double a)
{
	this->molar_area = a;
}

//Function to change the ionic charge of a molecule
void Molecule::editCharge(int c)
{
	//Note: this is not particularly useful as we don't know which atom lost or gained electrons
	this->charge = c;
}

//Edit the oxidation state of one atom
void Molecule::editOneOxidationState(int state, std::string Symbol)
{
	bool changed = false;
	for (int i=0; i<this->atoms.size(); i++)
	{
		if (Symbol == this->atoms[i].AtomSymbol())
		{
			this->atoms[i].editOxidationState(state);
			changed = true;
			break;
		}
	}
	if (changed == false) {mError(invalid_atom);}
}

//Edit all oxidation states of a given atom
void Molecule::editAllOxidationStates(int state, std::string Symbol)
{
	bool changed = false;
	for (int i=0; i<this->atoms.size(); i++)
	{
		if (Symbol == this->atoms[i].AtomSymbol())
		{
			this->atoms[i].editOxidationState(state);
			changed = true;
		}
	}
	if (changed == false) {mError(invalid_atom);}
}

//Calculate the average oxidation state of the given atom based on charge and other atoms oxidation states
void Molecule::calculateAvgOxiState(std::string Symbol)
{
	//WARNING! This is an incomplete function! (see below)
	bool changed = false;
	int sum = 0;
	int count = 0;
	std::vector<int> indices;
	for (int i=0; i<this->atoms.size(); i++)
	{
		if (Symbol != this->atoms[i].AtomSymbol())
		{
			sum+=this->atoms[i].OxidationState();
		}
		else
		{
			changed = true;
			count++;
			indices.push_back(i);
		}
	}
	if (changed == false) {mError(invalid_atom); return;}
	int remaining = this->charge - sum;
	remaining = remaining / count;
	for (int i=0; i<indices.size(); i++)
	{
		//Note: Accuracy of this function may be bad if (remaining / count) is not a true int
		this->atoms[indices[i]].editOxidationState(remaining);
	}
}

//Edit the formation enthalpy of the molecule
void Molecule::editEnthalpy(double enthalpy)
{
	this->formation_enthalpy = enthalpy;
}

//Edit the formation enthalpy of the molecule
void Molecule::editEntropy(double entropy)
{
	this->formation_entropy = entropy;
}

//Edit both enthalpy and entropy
void Molecule::editHS(double H, double S)
{
	this->formation_enthalpy = H;
	this->formation_entropy = S;
	this->haveHS = true;
}

//Edit the Gibb's formation energy
void Molecule::editEnergy(double energy)
{
	this->formation_energy = energy;
	this->haveG = true;
}

//Function to remove one atom from the molecule (does not affect formula or name)
void Molecule::removeOneAtom(std::string Symbol)
{
	bool changed = false;
	for (int i=0; i<this->atoms.size(); i++)
	{
		if (Symbol == this->atoms[i].AtomSymbol())
		{
			this->atoms.erase(this->atoms.begin()+i);
			changed = true;
			break;
		}
	}
	if (changed == false) {mError(invalid_atom); return;}
	this->calculateMolarWeight();
	this->calculateMolarVolume();
	this->calculateMolarArea();
}

//Function to remove all atoms of symbol given (does not affect formula or name)
void Molecule::removeAllAtoms(std::string Symbol)
{
	bool changed = false;
	for (int i=0; i<this->atoms.size(); i++)
	{
		if (Symbol == this->atoms[i].AtomSymbol())
		{
			this->atoms.erase(this->atoms.begin()+i);
			i--;
			changed = true;
		}
	}
	if (changed == false) {mError(invalid_atom); return;}
	this->calculateMolarWeight();
	this->calculateMolarArea();
	this->calculateMolarVolume();
}

//Return the current ionic charge
int Molecule::Charge()
{
	return this->charge;
}

//Return the current molecular weight
double Molecule::MolarWeight()
{
	return this->molar_weight;
}

//Return the current molecular volume
double Molecule::MolarVolume()
{
	return this->molar_volume;
}

//Return the current molecular area
double Molecule::MolarArea()
{
	return this->molar_area;
}

//Return whether or not enthalpy and entropy are known
bool Molecule::HaveHS()
{
	return this->haveHS;
}

//Return whether or not Gibb's energy is known
bool Molecule::HaveEnergy()
{
	return this->haveG;
}

//Return whether or not the molecule was registered
bool Molecule::isRegistered()
{
	return this->registered;
}

//Return the enthalpy
double Molecule::Enthalpy()
{
	return this->formation_enthalpy;
}

//Return the entropy
double Molecule::Entropy()
{
	return this->formation_entropy;
}

//Return the Gibb's energy
double Molecule::Energy()
{
	return this->formation_energy;
}

//Return molecule common name
std::string Molecule::MoleculeName()
{
	return this->Name;
}

//Return the molecular formula
std::string Molecule::MolecularFormula()
{
	return this->Formula;
}

//Return the molecule's phase
std::string Molecule::MoleculePhase()
{
	return this->Phase;
}

//Return the enum flag of the phase
int Molecule::MoleculePhaseID()
{
	return this->PhaseID;
}

//Return atoms
std::vector<Atom> & Molecule::getAtoms()
{
	return this->atoms;
}

//Display molecule information
void Molecule::DisplayInfo()
{	
	std::cout << "\nCommon Name: " << this->Name << "\tFormula: " << this->Formula << std::endl;
	std::cout << "-------------------------------------------------\n";
	std::cout << "Molar Weight (g/mol): " << this->MolarWeight() << std::endl;
	std::cout << "Phase: " << this->Phase << "\tIonic Charge: " << this->charge << std::endl;
	std::cout << "van der Waals Volume (cubic angstroms): " << this->MolarVolume() << std::endl;
	std::cout << "van der Waals Area (square angstroms): " << this->MolarArea() << std::endl;
	std::cout << "STP Formation Energy (J/mol): ";
	if (this->haveG == true) std::cout << this->formation_energy << "\n";
	else std::cout << "Unknown\n";
	std::cout << "STP Formation Enthalpy (J/mol): ";
	if (this->haveHS) std::cout << this->formation_enthalpy << "\t";
	else std::cout << "Unknown\t";
	std::cout << "\nSTP Formation Entropy (J/K/mol): ";
	if (this->haveHS) std::cout << this->formation_entropy << std::endl;
	else std::cout << "Unknown\n\n";
}

//Testing for MOLA
int MOLA_TESTS()
{
	int success = 0;
	double time = clock();
	
	//------------- Testing of the Molecule Object---------------------------------------
	Molecule H2O(0,-285830.0,69.95,-23780.0,true,true,"Liquid","Water","H2O (l)","H2O");
	Molecule HHe(0,0,0,0,false,false,"N/A","N/A","H10He22","H10He22");
	
	HHe = H2O;
	HHe.Register(0,0,0,0,false,false,"N/A","N/A","H10He22","H10He22");
	
	H2O.DisplayInfo();
	HHe.DisplayInfo();
	
	Molecule NewH2O;
	
	NewH2O.Register("H2O (l)"); //Example of registering molecule information based on just the formula
	NewH2O.DisplayInfo();
	
	Molecule H,OH;
	H.Register("H + (aq)");		//Note: Registration must follow the standard naming convention
	OH.Register("OH - (aq)");	//		formula \space charge \space phase
	H.DisplayInfo();
	OH.DisplayInfo();
	
	Molecule Uranyltricarb;
	Uranyltricarb.Register("UO2(CO3)3 4- (aq)");
	Uranyltricarb.editOneOxidationState(4, "U"); //Set the oxidation state of U to 4+
	Uranyltricarb.editAllOxidationStates(-2, "O");//Set all oxidation states of O to -2
	Uranyltricarb.calculateAvgOxiState("C");		//Set all oxidation states of C based on prior info
	Uranyltricarb.editEnergy(555);					//Edits the formation energy (note: this is not correct info)
	Uranyltricarb.removeOneAtom("U");				//Removes the U atom from the molecule
	std::cout << "\n\nTesting of atom removals and other edits to the molecule\n";
	Uranyltricarb.removeAllAtoms("O");				//Removes all O atoms from the molecule
	Uranyltricarb.DisplayInfo();
	//-------------- END molecule testing ----------------------------------------------
	
	Molecule NaHCO3;
	NaHCO3.Register("NaHCO3 (aq)");
	NaHCO3.DisplayInfo();
	
	Molecule Mus;
	Mus.Register("KAl3Si3O10(OH)2 (s)");
	Mus.DisplayInfo();
	
	Molecule Azu;
	Azu.Register("(CuCO3)2Cu(OH)2 (s)");
	Azu.DisplayInfo();
	
	time = clock() - time;
	std::cout << "\nRuntime (s): " << (time/CLOCKS_PER_SEC) << std::endl;
	return success;
}
