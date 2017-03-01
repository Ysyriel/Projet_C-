#ifndef INDIVIDU_H
#define INDIVIDU_H 

//==============================
//    INCLUDES
//==============================

/**
 * @class Individu
 * @brief Crée un Individu
 */

class Individu
{
public:
//==============================
//    CONSTRUCTORS
//==============================

//==============================
//    DESTRUCTOR
//==============================

//==============================
//    GETTERS
//==============================
	float phenotype_A(); //Renvoie la concentration A
	float phenotype_B();
	float phenotype_C();

//==============================
//    SETTERS
//==============================
	void set_phenotypeA(float A);
	void set_phenotypeB(float B);
	void set_phenotypeC(float C);
	
//==============================
//    OPERATORS
//==============================

//==============================
//    PUBLIC METHODS
//==============================

protected:
//==============================
//    ATTRIBUTES
//==============================
  char genotype;
  float phenotype[3];
  float fitness;
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    SETTER
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


#endif // INDIVIDU_H
