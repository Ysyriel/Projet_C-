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
Case::~Case(){
	
}

//==============================
//    PUBLIC METHODS
//==============================

void Case::mort(float p){
	float r = (rand()/(float)RAND_MAX); //Genere un float aleatoire entre 0 et 1
	if (r<p){
		delete(cellule);
	}
}


//==============================
//    GETTERS
//==============================

float Case::conc_A(){
	return conc_ext[0];
}

float Case::conc_B(){
	return conc_ext[1];
}

float Case::conc_C(){
	return conc_ext[2];
}

Individu* Case::get_cellule(){
	return cellule;
}

//==============================
//    SETTERS
//==============================

void Case::set_concA(float A){
	if (A > 0)
		conc_ext[0] =  A;
}

void Case::set_concB(float B){
	if (B > 0)
		conc_ext[1] =  B;
}

void Case::set_concC(float C){
	if (C > 0)
		conc_ext[2] =  C;
}

void Case::set_cellule(Individu I){
	*cellule = I;
}
	
