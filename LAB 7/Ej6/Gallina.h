#ifndef GALLINA_H
#define GALLINA_H
#include "Ave.h"
#include <iostream>
using namespace std;

class Gallina : public Ave 	{
public:
	Gallina(string,int,int);
	~Gallina();
	void mostrarGallina();
private:
	int cantAnualHuevos;
};

#endif

