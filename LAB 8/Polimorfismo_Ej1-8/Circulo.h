#ifndef CIRCULO_H
#define CIRCULO_H

#include "Forma.h"
#include "Punto.h"
#include "Elipse.h"
#include <iostream>
using namespace std;

class Circulo {
friend class Elipse;
public:
	Circulo(float);
	~Circulo();
private:
	float radio;
};

#endif
