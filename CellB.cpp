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

//==============================
//    DESTRUCTOR
//==============================
CellB::~CellB(){

}

//==============================
//    PUBLIC METHODS
//==============================
