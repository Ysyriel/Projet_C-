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
	srand (time (NULL)); 
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
			grille[x][y].set_x(x); //Donne les attributs de coordonnes aux cases
			grille[x][y].set_y(y);
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
	for (int x = 0 ; x < largeur ; x++){
		for (int y = 0 ; y < hauteur ; y++){
			grille[x][y].get_cellule()->maj_fitness(fitness_min);
		}
	}
}



//A CORRIGER
void Environnement::Diffusion(int D){
	
	for (int x = 0 ; x < largeur ; x++){
		for (int y = 0 ; y < hauteur ; y++){
			float A = grille[x][y].conc_A();
			float B = grille[x][y].conc_B();
			float C = grille[x][y].conc_C(); 
			for (int i = -1 ; i < 2 ; i++){
				for (int j = -1 ; j < 2 ; j++){
					if ((x+i)%largeur == -1){
						grille[x][y].set_concA(grille[x][y].conc_A() + D*grille[largeur-1][(y+j)%hauteur].conc_A());
						grille[x][y].set_concB(grille[x][y].conc_B() + D*grille[largeur-1][(y+j)%hauteur].conc_B());
						grille[x][y].set_concC(grille[x][y].conc_C() + D*grille[largeur-1][(y+j)%hauteur].conc_C());
					}
					else if ((y+i)%hauteur == -1){
						grille[x][y].set_concA(grille[x][y].conc_A() + D*grille[(x+i)%largeur][hauteur-1].conc_A());
						grille[x][y].set_concB(grille[x][y].conc_B() + D*grille[(x+i)%largeur][hauteur-1].conc_B());
						grille[x][y].set_concC(grille[x][y].conc_C() + D*grille[(x+i)%largeur][hauteur-1].conc_C());
					}
					else if ((y+i)%hauteur == -1 && (x+i)%largeur == -1){
						grille[x][y].set_concA(grille[x][y].conc_A() + D*grille[largeur-1][hauteur-1].conc_A());
						grille[x][y].set_concB(grille[x][y].conc_B() + D*grille[largeur-1][hauteur-1].conc_B());
						grille[x][y].set_concC(grille[x][y].conc_C() + D*grille[largeur-1][hauteur-1].conc_C());
					}
					else {
						grille[x][y].set_concA(grille[x][y].conc_A() + D*grille[(x+i)%largeur][(y+j)%hauteur].conc_A());
						grille[x][y].set_concB(grille[x][y].conc_B() + D*grille[(x+i)%largeur][(y+j)%hauteur].conc_B());
						grille[x][y].set_concC(grille[x][y].conc_C() + D*grille[(x+i)%largeur][(y+j)%hauteur].conc_C());
					} 
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
	cout << endl;
	couleur("0");
}


void Environnement::Affichconc(){
	for (int j = 0 ; j < get_hauteur() ; j++){
		for (int i = 0 ; i < get_largeur() ; i++){
			cout << "[" << grille[i][j].conc_A() << ","<< grille[i][j].conc_B() << ","  << grille[i][j].conc_C() << "] ";
			}
		cout <<  endl;
		}
		cout << endl;
}


std::vector<Case*> Environnement::Voisinage(int x, int y){ //Donnent les cases autour de la case ayant pour coordonnees x et y
	std::vector<Case*> Voisins;
	Voisins.push_back(&(grille[(x+1)%largeur][y]));
	Voisins.push_back(&(grille[(x+1)%largeur][(y+1)%hauteur]));
	Voisins.push_back(&(grille[x][(y+1)%hauteur]));
	
	if (y == 0){
		Voisins.push_back(&(grille[(x+1)%largeur][hauteur-1]));
		Voisins.push_back(&(grille[x%largeur][hauteur-1]));
	} else {
		Voisins.push_back(&(grille[(x+1)%largeur][y-1]));
		Voisins.push_back(&(grille[x%largeur][y-1]));
	}
	

	if (x == 0){
		Voisins.push_back(&(grille[largeur-1][(y+1)%hauteur]));
		Voisins.push_back(&(grille[largeur-1][y%hauteur]));
	} 
	else {
		Voisins.push_back(&(grille[x-1][(y+1)%hauteur]));
		Voisins.push_back(&(grille[x-1][y%hauteur]));
	}
	if (x == 0 && y == 0){
		Voisins.push_back(&(grille[largeur-1][hauteur-1]));
	} 
	else {
		Voisins.push_back(&(grille[x-1][y-1]));
	}
	
	unsigned int compteur;
	for(unsigned int i = 0; i < Voisins.size(); i++){
		if (&Voisins[i] == 0x00000000) compteur++;
	}
	if(compteur == Voisins.size()) return std::vector<Case*>();
	
	return Voisins;
}


Case* Environnement::Best_cell(std::vector<Case*> voisins){ //Retourne la case contenant la cellule avec la plus haute fitness parmi un vecteur de cases
	unsigned int i = 0;  
	if(voisins.size() == 0) return nullptr;
	while ((voisins[i]->test_cellule() == 0) && (i < voisins.size())) {
		i++;
	}

	if (i == voisins.size()){
		return nullptr;
	}
	
	float fitmax = voisins[i]->get_cellule()->get_fitness();
	unsigned int indmax = i;
	
	for (unsigned int i = 0; i < voisins.size()-1; i++){
		if (voisins[i]->test_cellule() != false){
			if (voisins[i]->get_cellule()->get_fitness() > fitmax){
				fitmax = voisins[i]->get_cellule()->get_fitness();
				indmax = i ;
			}
		}	
	}
	return voisins[indmax];
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
	//CONDITION SUR POINTEUR NULL SANS DOUTE
			Best_cell(Voisinage(gaps[i]->get_x(), gaps[i]->get_y()))->get_cellule()->set_phenotypeA(Best_cell(Voisinage(gaps[i]->get_x(), gaps[i]->get_y()))->get_cellule()->phenotype_A() / 2); //On divise les concentration de la cellule par 2
			Best_cell(Voisinage(gaps[i]->get_x(), gaps[i]->get_y()))->get_cellule()->set_phenotypeB(Best_cell(Voisinage(gaps[i]->get_x(), gaps[i]->get_y()))->get_cellule()->phenotype_B() / 2);
			Best_cell(Voisinage(gaps[i]->get_x(), gaps[i]->get_y()))->get_cellule()->set_phenotypeC(Best_cell(Voisinage(gaps[i]->get_x(), gaps[i]->get_y()))->get_cellule()->phenotype_C() / 2);

			if ( Best_cell(Voisinage(gaps[i]->get_x(), gaps[i]->get_y()))->get_cellule()->type() == 'a' ){
				CellA* divise = new CellA(*Best_cell(Voisinage(gaps[i]->get_x(), gaps[i]->get_y()))->get_cellule());
				gaps[i]->set_cellule(divise);
			}
			else {
				CellB* divise = new CellB(*Best_cell(Voisinage(gaps[i]->get_x(), gaps[i]->get_y()))->get_cellule());
				gaps[i]->set_cellule(divise); 
		} 
	}
}
	



void Environnement::Run(){
	Affichagrille();
	int pas = 0;
	while(pas<10000){
		Diffusion(0.1);
		for(int j = 0 ; j < hauteur; j++){
			for(int i = 0 ; i < largeur ; i++){
				if(grille[i][j].test_cellule() == true){
					grille[i][j].mort(0.02);
				}
			}
		}
		cout <<"Pas : " << pas << " " << endl;
		Competition();
		//metabol_all();
		pas++;
	}
		Affichagrille();
}


//==============================
//    PROTECTED METHODS
//==============================

int Environnement::generer_aleaint(int min, int max)
{
	return (min+(rand()%(max-min+1)));
}
