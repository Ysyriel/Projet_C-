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
	
	Environnement Envir;
	//Case* Test = Envir.Best_cell(Envir.Voisinage(2,2));
 
	Envir.Competition();
	
	Envir.Run();
 
  return EXIT_SUCCESS;
}
