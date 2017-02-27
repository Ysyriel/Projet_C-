//==============================
//    INCLUDES
//==============================
#include "Case.h"
#include <cstdio>
#include <cstdlib>
#include "Environnement.h"



//==============================
//    CONSTRUCTORS
//==============================
Environnement::Environnement()
{
	grille = new grille[32][32];
	fitness_min = 0.01;
}

Environnement::Environnement(const int x, const int y)
{
	grille = new grille[x][y];
	fitness_min= 0.01;
}

//==============================
//    DESTRUCTOR
//==============================


//==============================
//    PUBLIC METHODS
//==============================
