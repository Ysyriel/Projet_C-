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
  phenotype[0]=0;
  phenotype[1]=0;
  phenotype[2]=0;
  fitness = phenotype[2];
}

CellB::CellB(const CellB& cellule){  //Constructeur par copie
	genotype = cellule.genotype;
	phenotype[0]=cellule.phenotype[0];
	phenotype[1]=cellule.phenotype[1];
	phenotype[2]=cellule.phenotype[2];
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

void CellB::maj_fitness(float fit_min){
	fitness = phenotype[2];
	if (fitness < fit_min){
		fitness = fit_min;
	}
}
