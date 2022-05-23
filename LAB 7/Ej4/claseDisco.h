#ifndef CLASEDISCO_H
#define CLASEDISCO_H
#include "claseMultimedia.h"
#include <iostream>
using namespace std;

class claseDisco : public claseMultimedia { 
public:
	claseDisco(string,float);
	~claseDisco();
	void imprimir();
private:
	float capacity;
};

#endif

