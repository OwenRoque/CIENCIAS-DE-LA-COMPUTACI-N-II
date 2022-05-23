#ifndef AVE_H
#define AVE_H
#include <iostream>
using namespace std;

class Ave {
public:
	Ave(string,int);
	~Ave();
	void mostrar();
private:
	string tipo; //terrestre o acuatica
	int mudaPlumajePorAnio;
};

#endif

