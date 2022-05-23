#ifndef GANSO_H
#define GANSO_H
#include "Ave.h"
#include <iostream>
using namespace std;

class Ganso : public Ave {
public:
	Ganso(string,int,float);
	~Ganso();
	void mostrarGanso();
private:
	float PlumasKg;
};

#endif

