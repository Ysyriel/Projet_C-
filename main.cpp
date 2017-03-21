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
  Environnement Envir(10,10,25,0.2);
  Envir.Affichagrille();
  Envir.Affichconc();
  Envir.metabol_all();
  
  Envir.Affichagrille();
  Envir.Affichconc();
  Envir.metabol_all();
  
  Envir.Affichagrille();
  Envir.Affichconc();
  Envir.metabol_all();
 
  return 0;

}
