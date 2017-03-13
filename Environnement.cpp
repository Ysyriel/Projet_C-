//==============================
//    INCLUDES
//==============================
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "Environnement.h"
#include "Case.h"
#include "CellA.h"
#include "CellB.h"
#include "Individu.h"

#include <vector>
#include <algorithm>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

using namespace std;


int generer_alea(int a, int b)
{
	return rand()%(b-a) +a;
}

//==============================
//    CONSTRUCTORS
//==============================
Environnement::Environnement() //Constructeur par défaut
{
	Ainit = generer_alea(1,50);
	largeur = 32;
	hauteur = 32;
	
  Case** grille = new Case*[32]; //Cree la grille des cases
  for(int i = 0; i<32; i++)
  	grille[i] = new Case[32];
	fitness_min = 0.01;
	
	
	
	for(int i=0; i<(32*32)/2; i++) //Remplit la grille de cellules
	{
		int x=generer_alea(0,32);
		int y=generer_alea(0,32);
		
		if (grille[x][y].test_cellule() == false)
		{
			CellA* A = new CellA();
			grille[x][y].set_cellule(A);
		}
		else i--;
	}
	
	
	for(int x=0; x<32; x++)
	{
		for(int y=0; y<32; y++)
		{
			grille[x][y].set_concA(Ainit); //Met la concentration initiale de A dans chaque case
			grille[x][y].set_x(x); //Donne les attributs de coordonnes aux cases
			grille[x][y].set_y(y);
			if (grille[x][y].test_cellule() == false)
			{
				CellB* B = new CellB();
				grille[x][y].set_cellule(B);
			}	
		}
	}
	
	

}

Environnement::Environnement(const int w,const int h, float A_init)
{
	Ainit = A_init;
	largeur = w;
	hauteur = h;
	Case** grille = new Case*[w];
	for(int i = 0; i<w; i++)
		grille[i] = new Case[h];
	fitness_min= 0.01;
	
	for(int i=0; i<(w*h)/2; i++)
	{
		int x=generer_alea(0,w);
		int y=generer_alea(0,h);
		
		if (grille[x][y].get_cellule() == nullptr)
		{
			CellA* A = new CellA();
			grille[x][y].set_cellule(A);
		}
		else i--;
	}
	for(int x=0; x<w; x++)
	{
		for(int y=0; y<h; y++)
		{
			grille[x][y].set_concA(Ainit); //Met la concentration initiale de A dans chaque case
			if (grille[x][y].get_cellule() == nullptr)
			{
				CellB* B = new CellB();
				grille[x][y].set_cellule(B);
			}	
		}
	}


}
//==============================
//    DESTRUCTOR
//==============================

Environnement::~Environnement(){
	
}


//==============================
//    GETTERS
//==============================

int Environnement::get_largeur(){
	return largeur;
}

int Environnement::get_hauteur(){
	return hauteur;
}


//==============================
//    PUBLIC METHODS
//==============================

void Environnement::Diffusion(int D){
	
	for (int x = 0 ; x < 32 ; x++){
		for (int y = 0 ; y < 32 ; y++){
			float A = grille[x][y].conc_A();
			float B = grille[x][y].conc_B();
			float C = grille[x][y].conc_C();
			for (int i =-1 ; i < 2 ; i++){
				for (int j = -1 ; j < 2 ; j++){
					grille[x][y].set_concA(grille[x][y].conc_A() + D*grille[(x+i)%32][(y+j)%32].conc_A());
					grille[x][y].set_concB(grille[x][y].conc_B() + D*grille[(x+i)%32][(y+j)%32].conc_B());
					grille[x][y].set_concC(grille[x][y].conc_C() + D*grille[(x+i)%32][(y+j)%32].conc_C());			
				}
			}
			grille[x][y].set_concA(grille[x][y].conc_A() - (9 * D * A));
			grille[x][y].set_concB(grille[x][y].conc_B() - (9 * D * B));
			grille[x][y].set_concC(grille[x][y].conc_C() - (9 * D * C));
		}
	}

}


void Environnement::Reinitialisation(){
	for (int x = 0 ; x < 32 ; x++){
		for (int y = 0 ; y < 32 ; y++){
			grille[x][y].set_concA(Ainit);
			grille[x][y].set_concB(0);
			grille[x][y].set_concC(0);
		}
	}
}


void Environnement::Competition(){
	vector<Case*> gaps;
	for (int x = 0 ; x < get_largeur() ; x++){ //Remplit un vector de pointeur des cases vides
		for (int y = 0 ; y < get_hauteur() ; y++){
			if (grille[x][y].get_cellule() == NULL){
				gaps.push_back(&grille[x][y]);
			}
		}
	}
	random_shuffle (gaps.begin(), gaps.end()); //Range aleatoirement le vector
	
	
	
	
}


