//==============================
//    INCLUDES
//==============================
#include "Individu.h"
#include <iostream>
using std::cout;
using std::endl;

//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================

//==============================
//    CONSTRUCTORS
//==============================

//==============================
//    DESTRUCTOR
//==============================

//==============================
//    GETTERS
//==============================

float Individu::phenotype_A(){
	return phenotype[0];
}

float Individu::phenotype_B(){
	return phenotype[1];
}

float Individu::phenotype_C(){
	return phenotype[2];
}

char Individu::type(){
	return genotype;
}

//==============================
//    SETTERS
//==============================
void Individu::set_phenotypeA(float A){
	if (A > 0)
		phenotype[0] =  A;
}

void Individu::set_phenotypeB(float B){
	if (B > 0)
		phenotype[1] =  B;
}

void Individu::set_phenotypeC(float C){
	if (C > 0)
		phenotype[2] =  C;
}

//==============================
//    PUBLIC METHODS
//==============================
