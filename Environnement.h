#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

//==============================
//    INCLUDES
//==============================

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
  Environnement(int x, int y); //Constructeur taille

//==============================
//    DESTRUCTOR
//==============================
  virtual ~Environnement();

//==============================
//    GETTERS
//==============================

//==============================
//    SETTERS
//==============================

//==============================
//    OPERATORS
//==============================

//==============================
//    PUBLIC METHODS
//==============================

protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================

	Case** grille;
	float fitness_min;

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
