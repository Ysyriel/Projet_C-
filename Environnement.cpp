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
#include "couleurs.h"
#include "stdio.h"

#include <vector>       // std::vector
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

#include <iostream>
using std::cout;
using std::cin;
using std::endl;




//==============================
//    CONSTRUCTORS
//==============================
Environnement::Environnement() //Constructeur par défaut
{
	srand (time (NULL)); 
	Ainit = generer_aleaint(1,50);
	largeur = 32;
	hauteur = 32;
	
  grille = new Case*[32]; //Cree la grille des cases
  for(int i = 0; i<32; i++)
  	grille[i] = new Case[32];
	fitness_min = 0.01;
	r = 0.1;
	
	
	
	for(int i=0; i<(32*32)/2; i++) //Remplit la grille de cellules A
	{
		int x=generer_aleaint(0,31);
		int y=generer_aleaint(0,31);
		
		if (grille[x][y].test_cellule() == false)
		{
			CellA* A = new CellA();
			grille[x][y].set_cellule(A);
		}
		else i--;
	}
	
	
	for(int x=0; x<32; x++) //Remplit la grille de cellules B
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

Environnement::Environnement(const int w,const int h, float A_init, float fit_min)
{
	Ainit = A_init;
	largeur = w;
	hauteur = h;
	
	grille = new Case*[w];
	for(int i = 0; i<w; i++)
		grille[i] = new Case[h];
	fitness_min = fit_min;
	r = 0.1;
	
	for(int i=0; i<(w*h)/2; i++)
	{
		int x=generer_aleaint(0,w-1);
		int y=generer_aleaint(0,h-1);
		
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


void Environnement::metabol_all(){
	for (int x = 0 ; x < largeur ; x++){
		for (int y = 0 ; y < hauteur ; y++){
			grille[x][y].metabolisme(r, 0.1);
			
		}
	}	
}


void Environnement::Maj_fitness(){
	for (int x = 0 ; x < 32 ; x++){
		for (int y = 0 ; y < 32 ; y++){
			grille[x][y].get_cellule()->maj_fitness(fitness_min);
		}
	}
}




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


void Environnement::Affichagrille(){
	for (int j = 0 ; j < get_hauteur() ; j++){
		for (int i = 0 ; i < get_largeur() ; i++){
			if (grille[i][j].get_cellule() == nullptr){
				printf("  ");
			}
			else if (grille[i][j].get_cellule()->type() == 'a'){
				couleur("31");
				printf("A ");
			}
			else if (grille[i][j].get_cellule()->type() == 'b')
			{
				couleur("36");
				printf("B ");
			}
		}
		cout <<  endl;
	}
	
	couleur("0");
}

void Environnement::Affichconc(){
	for (int j = 0 ; j < get_hauteur() ; j++){
		for (int i = 0 ; i < get_largeur() ; i++){
			cout << "[" ;
			cout << grille[i][j].conc_A() << "," ;
			cout << grille[i][j].conc_B() << "," ;
			cout << grille[i][j].conc_C() << "] " ;
			}
		cout <<  endl;
		}
}


// CONDITIONS SUR LES CASES VIDES A FAIRE
std::vector<Case*> Environnement::Voisinage(int x, int y){ //Donnent les cases autour de la case ayant pour coordonnees x et y
	std::vector<Case*> Voisins;
	Voisins.push_back(&grille[x+1%32][y]);
	Voisins.push_back(&grille[x+1%32][y+1%32]);
	Voisins.push_back(&grille[x][y+1%32]);
	
	if (y == 0){
		Voisins.push_back(&grille[x+1%32][31]);
		Voisins.push_back(&grille[x%32][31]);
	} else {
		Voisins.push_back(&grille[x+1%32][y-1]);
		Voisins.push_back(&grille[x%32][y-1]);
	}
	
	//A faire
	if (x == 0){
		Voisins.push_back(&grille[31][y+1%32]);
		Voisins.push_back(&grille[31][y%32]);
	} 
	else {
		Voisins.push_back(&grille[x-1][y+1%32]);
		Voisins.push_back(&grille[x-1][y%32]);
	}
	if (x==0 and y==0){
		Voisins.push_back(&grille[31][31]);
	} 
	else {
		Voisins.push_back(&grille[x-1][y-1]);
	}
	return Voisins;
}


Case* Environnement::Best_cell(std::vector<Case*> voisins){ //Retourne la case contenant la cellule avec la plus haute fitness parmi un vecteur de cases
	Case* CASE = voisins[0];
	for (unsigned int i = 1; i < voisins.size(); i++){
		if (voisins[i]->get_cellule() != nullptr){
			if (voisins[i]->get_cellule()->get_fitness() > CASE->get_cellule()->get_fitness()){
				CASE = voisins[i];
			}
		}	
	}
	return CASE;
}


void Environnement::Competition(){
	std::vector<Case*> gaps;
	for (int j = 0 ; j < get_hauteur() ; j++){   //Remplit un vecteur de cases vides
		for (int i = 0 ; i < get_largeur() ; i++){ 
			if (grille[i][j].get_cellule() == nullptr){
				gaps.push_back(&grille[i][j]);
			}
		}
	}	
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  shuffle (gaps.begin(), gaps.end(), std::default_random_engine(seed));
  for(unsigned int i = 0; i < gaps.size() ; i++){
		Best_cell(Voisinage(gaps[i].get_x(), gaps[i].get_y())).set_phenotypeA(Best_cell(Voisinage(gaps[i].get_x(), gaps[i].get_y())).phenotype_A / 2);
		Best_cell(Voisinage(gaps[i].get_x(), gaps[i].get_y())).set_phenotypeB(Best_cell(Voisinage(gaps[i].get_x(), gaps[i].get_y())).phenotype_B / 2);
		Best_cell(Voisinage(gaps[i].get_x(), gaps[i].get_y())).set_phenotypeC(Best_cell(Voisinage(gaps[i].get_x(), gaps[i].get_y())).phenotype_C / 2);
		if ( Best_cell(Voisinage(gaps[i].get_x(), gaps[i].get_y())).type() == 'a' ){
			CellA divise = new CellA(Best_cell(Voisinage(gaps[i].get_x(), gaps[i].get_y())));
		}
		else {
			CellB divise = new CellB(Best_cell(Voisinage(gaps[i].get_x(), gaps[i].get_y())));
		}
		gaps[i]->set_cellule(divise);
	}
}	



void Environnement::Run(){
	Affichagrille();
	cout << endl;
	Affichconc();
	cout << endl;
	int pas = 0;
	while(pas<3){
		for (int j = 0 ; j < get_hauteur() ; j++){
			for (int i = 0 ; i < get_largeur() ; i++){
				if(grille[i][j].get_cellule() != nullptr){
					grille[i][j].mort(0.5);
				}
			}
		}
		Affichagrille();
		cout << endl;
		Affichconc();
		cout << endl;
		Competition();
		pas++;
	}
}


//==============================
//    PROTECTED METHODS
//==============================

int Environnement::generer_aleaint(int min, int max)
{
	return (min+(rand()%(max-min+1)));
}
