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

Individu::~Individu(){

}


//==============================
//    GETTERS
//==============================

float Individu::phenotype_A() const{
	return phenotype[0];
}

float Individu::phenotype_B() const{
	return phenotype[1];
}

float Individu::phenotype_C() const{
	return phenotype[2];
}

char Individu::type() const{
	return genotype;
}

float Individu::get_fitness() const{
	return fitness;
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


