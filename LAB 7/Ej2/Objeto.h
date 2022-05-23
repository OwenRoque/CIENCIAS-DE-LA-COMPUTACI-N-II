#ifndef OBJETO_H
#define OBJETO_H
#include "Color.h"
#include "Material.h"
#include <iostream>
using namespace std;

class Objeto : public Color, public Material {
public:
	Objeto(string,int,int,int,string);
	~Objeto();
	void describirObj();
private:
	string obj;
};

#endif

