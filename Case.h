#ifndef CASE_H
#define CASE_H

//==============================
//    INCLUDES
//==============================

#include "Individu.h"


/**
 * @class Case
 * @brief Creates a Case
 */

class Case
{
public:
//==============================
//    CONSTRUCTORS
//==============================
	Case();

//==============================
//    DESTRUCTOR
//==============================
	virtual ~Case();

//==============================
//    GETTERS
//==============================
	float conc_A(); //Renvoie la concentration A
	float conc_B();
	float conc_C();
	Individu* get_cellule();
	int get_x();
	int get_y();

//==============================
//    SETTERS
//==============================

	void set_concA(float A);
	void set_concB(float B);
	void set_concC(float C);
	void set_cellule(Individu* I);
	void set_x(int x);
	void set_y(int y);

//==============================
//    OPERATORS
//==============================

//==============================
//    PUBLIC METHODS
//==============================
	void metabol_ext();
	void mort(float p);
	void metabolisme(float R, float dt);
	bool test_cellule();
	void Mutation(float p);

protected:
//==============================
//    PROTECTED METHODS
//==============================

	float gener_aleafloat(int min, int max);
//==============================
//    ATTRIBUTES
//==============================

	Individu* cellule;
	float conc_ext[3];
	int coord_x;
	int coord_y;

};

#endif // CASE_H
