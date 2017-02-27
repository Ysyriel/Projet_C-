//==============================
//    INCLUDES
//==============================
#include "Case.h"
#include <cstdio>
#include <cstdlib>


//==============================
//    CONSTRUCTORS
//==============================
Environnement::Environnement()
{
	grille = new Case[32][32];
	fitness_min = 0.01;
}

Environnement::Environnement(int x, int y)
{
	grille = new Case[x][y];
	fitness_min= 0.01;
}

//==============================
//    DESTRUCTOR
//==============================
Character::~Character(){
	
}

//==============================
//    PUBLIC METHODS
//==============================
