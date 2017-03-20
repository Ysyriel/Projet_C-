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
  phenotype[0]=5;
  phenotype[1]=5;
  phenotype[2]=5;
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
	phenotype[0] = phenotype[0] + dt * (conc_out * R - phenotype[0] * R);
	phenotype[1] = phenotype[1] + dt * (phenotype[0] * R);
}
