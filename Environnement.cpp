//==============================
//    INCLUDES
//==============================
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include "Environnement.h"
#include "Case.h"
#include "CellA.h"
#include "CellB.h"
#include "Individu.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int generer_alea(int min, int max)
{
  srand(time(NULL));
  return rand()%(max-min+1)+ min;
}

//==============================
//    CONSTRUCTORS
//==============================
Environnement::Environnement()
{
  Case** grille = new Case*[32];
  for(int i = 0; i<32; i++)
  	grille[i] = new Case[32];
	fitness_min = 0.01;
	
	
	
	for(int i=0; i<(32*32)/2; i++)
	{
		int x=generer_alea(0,32);
		int y=generer_alea(0,32);
		
		if (grille[x][y].get_cellule() == NULL)
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
			if (grille[x][y].get_cellule() == NULL)
			{
				CellB* B = new CellB();
				grille[x][y].set_cellule(B);
			}	
		}
	}

}

Environnement::Environnement(const int w,const int h)
{
	Case** grille = new Case*[w];
	for(int i = 0; i<w; i++)
		grille[i] = new Case[h];
	fitness_min= 0.01;
	
	for(int i=0; i<(w*h)/2; i++)
	{
		int x=generer_alea(0,w);
		int y=generer_alea(0,h);
		
		if (grille[x][y].get_cellule() == NULL)
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
			if (grille[x][y].get_cellule() == NULL)
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
			grille[x][y].set_concA((rand()/(float)RAND_MAX) * 50);
			grille[x][y].set_concB(0);
			grille[x][y].set_concC(0);
		}
	}
}


