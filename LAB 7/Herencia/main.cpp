#include<iostream>
//#include "Clase_Base.h"
#include "Clase_Derivada.h"
using namespace std;

int main (int argc, char *argv[]) {
//	Clase_Base obj = Clase_Base();
//	obj.UnMetodoClaseBase();
	Clase_Derivada obj = Clase_Derivada(3,4);
	obj.UnMetodoClaseDerivada();
	obj.UnMetodoClaseBase();
	return 0;
}

