//==============================
//    INCLUDES
//==============================
#include "CellB.h"
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
CellB::CellB(){
  genotype = 'b';
  phenotype[0]=5;
  phenotype[1]=5;
  phenotype[2]=5;
  fitness = phenotype[2];
}

//==============================
//    DESTRUCTOR
//==============================
CellB::~CellB(){

}

//==============================
//    PUBLIC METHODS
//==============================

void CellB::metabol_in(float R, float dt, float conc_out){
	phenotype[1] = phenotype[1] + dt * (conc_out * R - phenotype[1] * R);
	phenotype[2] = phenotype[2] + dt * (phenotype[1] * R);
}

void CellB::maj_fitness(){
	fitness = phenotype[2];
}
