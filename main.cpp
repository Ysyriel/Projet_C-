//==============================
//    INCLUDES
//==============================

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;


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
	Case Test;
	cout << "Valeur de concentrations :" << Test.conc_A() << endl;
	return 0;
}
