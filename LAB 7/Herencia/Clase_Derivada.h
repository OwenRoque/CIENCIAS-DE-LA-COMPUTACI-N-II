#ifndef CLASE_DERIVADA_H
#define CLASE_DERIVADA_H
#include "Clase_Base.h"
class Clase_Derivada : public Clase_Base {
public:
	Clase_Derivada(int,int);
	~Clase_Derivada();
	void UnMetodoClaseDerivada();
private:
	int valor3;
	int valor4;
};

#endif

