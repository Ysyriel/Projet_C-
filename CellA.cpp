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
