#ifndef CELLA_H
#define CELLA_H 

//==============================
//    INCLUDES
//==============================
#include <stdio.h>
#include "Individu.h"
/**
 * @class CellA
 * @brief Créer une CellA
 */

class CellA : public Individu
{
public:
//==============================
//    CONSTRUCTORS
//==============================
  CellA();
  CellA(const CellA& cellule)

//==============================
//    DESTRUCTOR
//==============================
  virtual ~CellA();

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


#endif // CELLA_H
