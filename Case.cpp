//==============================
//    INCLUDES
//==============================
#include "Case.h"
#include "CellA.h"
#include "CellB.h"
#include <cstdio>
#include <cstdlib>
#include <time.h>

#include <iostream>
using std::cout;
using std::cin;
using std::endl;



//==============================
//    CONSTRUCTORS
//==============================
Case::Case()
{
	cellule = nullptr;
	conc_ext[0] = 0;
	conc_ext[1] = 0;
	conc_ext[2] = 0;
}

//==============================
//    DESTRUCTOR
//==============================
Case::~Case(){
	delete cellule;
}

//==============================
//    PUBLIC METHODS
//==============================



void Case::Mutation(float p){ //Mute la cellule contenue dans la case avec une probabilité p
	srand (time (NULL));
	float r = gener_aleafloat(0,1);
	if (r < p){
		if (cellule->type() == 'a'){
			CellB* B = new CellB;
			B->set_phenotypeA(cellule->phenotype_A());
			B->set_phenotypeB(cellule->phenotype_B());
			B->set_phenotypeC(cellule->phenotype_C());
			delete cellule;
			cellule = B;
			
		}
		else if (cellule->type() == 'b'){
			CellA* A = new CellA;
			A->set_phenotypeA(cellule->phenotype_A());
			A->set_phenotypeB(cellule->phenotype_B());
			A->set_phenotypeC(cellule->phenotype_C());
			delete cellule;
			cellule = A;
			
		}
	}
	
	
}


void Case::mort(float p){
	float r = gener_aleafloat(0,1); 
	if (r<p){
		set_concA(conc_A()+cellule->phenotype_A());
		set_concB(conc_B()+cellule->phenotype_B());
		set_concC(conc_C()+cellule->phenotype_C());
		delete cellule;
		cellule = nullptr; 
	}
}

void Case::metabolisme(float R, float dt){ //Metabolisme des cellules
	if (cellule != nullptr){
		if (cellule->type() == 'a'){
			set_concA(conc_ext[0] + dt * (-conc_ext[0] * R));
			cellule->metabol_in(R, dt, conc_ext[0]);
		} 
		if (cellule->type() == 'b'){
			set_concB(conc_ext[1] + dt * (-conc_ext[1] * R));
			cellule->metabol_in(R, dt, conc_ext[1]);
		}
		cellule->maj_fitness(0.001);
	}
}

bool Case::test_cellule(){
	if (cellule == nullptr){
		return false;
	}
	else return true;
}


//==============================
//    GETTERS
//==============================

float Case::conc_A() const{
	return conc_ext[0];
}

float Case::conc_B() const{
	return conc_ext[1];
}

float Case::conc_C() const{
	return conc_ext[2];
}

Individu* Case::get_cellule() const{
	return cellule;
}

int Case::get_x() const{
	return coord_x;
}

int Case::get_y() const{
	return coord_y;
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

void Case::set_cellule(Individu* I){
	cellule = I;
}

void Case::set_x(int x){
	coord_x = x;
}

void Case::set_y(int y){
	coord_y = y;
}

//==============================
//    PROTECTED METHODS
//==============================

float Case::gener_aleafloat(int min, int max)
{
	return (min + (rand()/(double)RAND_MAX)*(max-min));
}
