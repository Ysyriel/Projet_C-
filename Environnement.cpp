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
	Case** grille = new Case*[32];
	for(int i = 0; i<32; i++)
		grille[i] = new Case[32];
	fitness_min = 0.01;
}

Environnement::Environnement(const int x,const int y)
{
	Case** grille = new Case*[x];
	for(int i = 0; i<x; i++)
		grille[i] = new Case[y];
	fitness_min= 0.01;
}

//==============================
//    DESTRUCTOR
//==============================

Environnement::~Environnement(){
	
}


//==============================
//    PUBLIC METHODS
//==============================
