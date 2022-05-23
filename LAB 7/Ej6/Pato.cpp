#include "Ave.h"
#include "Pato.h"
#include <iostream>
using namespace std;

Pato::Pato(string _tipo,int _mudaplumaje,int _carneExp) : Ave(_tipo,_mudaplumaje) {
	carnePatoExported = _carneExp;
} 
	
Pato::~Pato() {}

void Pato::mostrarPato(){
	Ave::mostrar();
	cout<<"Cantidad de carne de pato exportada (Kg): "<<carnePatoExported<<endl;
}
