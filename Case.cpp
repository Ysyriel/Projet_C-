//==============================
//    INCLUDES
//==============================
#include "Case.h"
#include <cstdio>
#include <cstdlib>


//==============================
//    CONSTRUCTORS
//==============================
Case::Case()
{
	cellule = NULL;
	conc_ext[0] = (rand()/(double)RAND_MAX) * 50;
	conc_ext[1] = 0;
	conc_ext[2] = 0;
}

//==============================
//    DESTRUCTOR
//==============================
Character::~Character(){
	
}

//==============================
//    PUBLIC METHODS
//==============================
