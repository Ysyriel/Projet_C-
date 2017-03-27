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
	virtual ~Individu();

//==============================
//    GETTERS
//==============================
	float phenotype_A(); //Renvoie la concentration A
	float phenotype_B();
	float phenotype_C();
	float get_fitness();
	char type();

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
	virtual void metabol_in(float R, float dt, float conc_out) = 0;
	virtual void maj_fitness() = 0;
	

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
