#include "Clase_Derivada.h"
#include <iostream>
using namespace std;
Clase_Derivada::Clase_Derivada(int _valor3, int _valor4) {
	valor3 = _valor3;
	valor4 = _valor4;
}

Clase_Derivada::~Clase_Derivada() {
	
}

void Clase_Derivada::UnMetodoClaseDerivada(){
	int rpta = valor3 + valor4 + valor1 + valor2;
	cout<<"Ingreso a metodo Clase_Derivada y respuesta es: "<<rpta<<endl;
}

