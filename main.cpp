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
	Environnement Test(32,32,25,0.001);
	Test.Run(2000);



	//Case* Test = Envir.Best_cell(Envir.Voisinage(2,2));
  
	//Environnement Envir;
	//Envir.Run(2000);
 
  return EXIT_SUCCESS;
}
