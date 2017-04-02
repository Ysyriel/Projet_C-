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
	
	//Environnement Test(12,12,20,1);
	//Test.Run();
	Environnement Test(32,32,20,0.001);
	Test.Run();

	//Case* Test = Envir.Best_cell(Envir.Voisinage(2,2));
  
	//Environnement Envir;
	//Envir.Run();
 
  return EXIT_SUCCESS;
}
