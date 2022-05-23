#ifndef OPERACIONBASE_H
#define OPERACIONBASE_H
#include <iostream>
using namespace std;

class operacionBase {
public:
	operacionBase();
	~operacionBase();
	void setOperador(int);
	int getOperador();
protected:
	int operador;
};

#endif

