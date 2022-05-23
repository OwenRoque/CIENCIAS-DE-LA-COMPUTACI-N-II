#include "Clase_Base.h"
#include <iostream>
using namespace std;
Clase_Base::Clase_Base() {	
}

Clase_Base::~Clase_Base() {	
}

void Clase_Base::UnMetodoClaseBase(){
	int rpta = valor1 + valor2;
	cout<<"Ingreso un metodo Clase_Base "<<rpta<<endl;
}

