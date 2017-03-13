#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

//==============================
//    INCLUDES
//==============================
#include "Case.h"

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
  Environnement(const int x,const int y, float A_init); //Constructeur taille

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

	void Diffusion(int D); //Diffusion des concentrations
	void Reinitialisation(); //Reinitialise la grille
	void Competition();

protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================

	Case** grille;
	float Ainit;
	float fitness_min;
	int largeur;
	int hauteur;

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
