//==============================
//    INCLUDES
//==============================
#include "CellA.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================

//==============================
//    CONSTRUCTORS
//==============================
CellA::CellA(){
  genotype = 'a';
  phenotype[0]=0;
  phenotype[1]=0;
  phenotype[2]=0;
  fitness = phenotype[1];
}

//==============================
//    DESTRUCTOR
//==============================
CellA::~CellA(){

}

//==============================
//    PUBLIC METHODS
//==============================

void CellA::metabol_in(float R, float dt, float conc_out){
	float Aout = conc_out * R;
	phenotype[0] = phenotype[0] + dt * (Aout - phenotype[0] * R);
	phenotype[1] = phenotype[1] + dt * (phenotype[0] * R);
}

void CellA::maj_fitness(){
	fitness = phenotype[1];
}
