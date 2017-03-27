#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

//==============================
//    INCLUDES
//==============================
#include "Case.h"
#include <vector>   

/**
 * @class Environnement
 * @brief Creates an Environnement
 */

class Environnement
{
public:
//==============================
//    CONSTRUCTORS
//==============================
  Environnement(); //Constructeur par defaut
  Environnement(const int w,const int h, float A_init, float fit_min); //Constructeur taille

//==============================
//    DESTRUCTOR
//==============================
  virtual ~Environnement();

//==============================
//    GETTERS
//==============================
	int get_largeur();
	int get_hauteur();

//==============================
//    SETTERS
//==============================

//==============================
//    OPERATORS
//==============================

//==============================
//    PUBLIC METHODS
//==============================

	std::vector<Case*> Voisinage(int x, int y);
	Case* Best_cell(std::vector<Case*> voisins);
	void Maj_fitness();
	void Diffusion(int D); //Diffusion des concentrations
	void Reinitialisation(); //Reinitialise la grille
	void Competition();
	void Affichagrille();
	void metabol_all();
	void Affichconc();
	void Run();

protected:
//==============================
//    PROTECTED METHODS
//==============================
	int generer_aleaint(int min, int max); //Génère un entier aléatoire entre 2 valeurs données en paramètres

//==============================
//    ATTRIBUTES
//==============================

	Case** grille;
	float Ainit;
	float fitness_min;
	int largeur;
	int hauteur;
	float r;
};

//==============================
//    GETTER DEFINITION
//==============================


//==============================
//    SETTER DEFINITION
//==============================

//==============================
//    OPERATOR DEFINITION
//==============================


#endif // ENVIRONNEMENT_H
