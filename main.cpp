//==============================
//    INCLUDES
//==============================

#include <cstdio>
#include <cstdlib>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


#include "CellA.h"
#include "CellB.h"
#include "Case.h"
#include "Individu.h"
#include "Environnement.h"

//==============================
//    FUNCTION DECLARATION
//==============================

//==============================
//    MAIN
//==============================

int main()
{
	Environnement Test;
	Environnement Envir(4,4,25,0.2);
	Envir.Affichagrille();
	cout << endl;
	Envir.Affichconc();
	Envir.Affichagrille();
	cout << endl;
	Envir.Affichconc();
	cout << endl;
	
	
	Envir.metabol_all();
	Envir.Affichconc();
	cout << endl;
	Envir.metabol_all();
	Envir.Affichconc();
	cout << endl;
	Envir.metabol_all();
	Envir.Affichconc();
	cout << endl;
	
	
	
	return 0;
}
