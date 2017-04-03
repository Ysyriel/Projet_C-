//==============================
//    INCLUDES
//==============================
#include "CellA.h"
#include "Individu.h"
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
  phenotype[1]=5;
  phenotype[2]=0;
  fitness = phenotype[1];
}

CellA::CellA(const Individu& cellule){  //Constructeur par copie
	genotype = cellule.type();
	phenotype[0]=cellule.phenotype_A();
	phenotype[1]=cellule.phenotype_B();
	phenotype[2]=cellule.phenotype_C();
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

void CellA::maj_fitness(float fit_min){
	fitness = phenotype[1];
	if (fitness < fit_min){
		fitness = 0;
	}
}
