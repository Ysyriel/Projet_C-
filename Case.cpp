//==============================
//    INCLUDES
//==============================
#include "Case.h"
#include <cstdio>
#include <cstdlib>
#include <time.h>

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

using namespace std;



float generer_aleafloat(int min, int max)
{
	return (min + (rand()/(double)RAND_MAX)*(max-min));
}


//==============================
//    CONSTRUCTORS
//==============================
Case::Case()
{
	cellule = nullptr;
	conc_ext[0] = 0;
	conc_ext[1] = 20;
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


void Case::mort(float p){
	float r = generer_aleafloat(0,1); 
	if (r<p){
		set_concA(conc_A()+cellule -> phenotype_A());
		set_concB(conc_B()+cellule -> phenotype_B());
		set_concC(conc_C()+cellule -> phenotype_C());
		delete cellule;
		cellule = nullptr;
	}
}

void Case::metabolisme(float R, float dt){ //Metabolisme des cellules
	if (cellule->type() == 'a'){
		cellule->metabol_in(R, dt, conc_ext[0]);
		set_concA(conc_ext[0] + dt * (-conc_ext[0] * R));
	} 
	if (cellule->type() == 'b'){
		cellule->metabol_in(R, dt, conc_ext[1]);
		set_concB(conc_ext[1] + dt * (-conc_ext[1] * R));
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

float Case::conc_A(){
	return conc_ext[0];
}

float Case::conc_B(){
	return conc_ext[1];
}

float Case::conc_C(){
	return conc_ext[2];
}

Individu* Case::get_cellule(){
	return cellule;
}

int Case::get_x(){
	return coord_x;
}

int Case::get_y(){
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
