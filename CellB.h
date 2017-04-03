#ifndef CELLB_H
#define CELLB_H 

//==============================
//    INCLUDES
//==============================
#include <stdio.h>
#include "Individu.h"
/**
 * @class CellB
 * @brief Créer une CellB
 */

class CellB : public Individu
{
public:
//==============================
//    CONSTRUCTORS
//==============================
  CellB();
  CellB(const Individu& cellule);

//==============================
//    DESTRUCTOR
//==============================
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
	void metabol_in(float R, float dt, float conc_out);
	void maj_fitness(float fit_min);

protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================

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


#endif // CELLB_H
