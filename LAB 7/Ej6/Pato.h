#ifndef PATO_H
#define PATO_H
#include "Ave.h"
#include <iostream>
using namespace std;

class Pato : public Ave {
public:
	Pato(string,int,int);
	~Pato();
	void mostrarPato();
private:
	int carnePatoExported;
};

#endif

