#include "Ave.h"
#include "Ganso.h"
#include <iostream>
using namespace std;

Ganso::Ganso(string _tipo,int _mudaplumaje,float _plumaskg) : Ave(_tipo,_mudaplumaje) {
	PlumasKg = _plumaskg;
}

Ganso::~Ganso() {}

void Ganso::mostrarGanso(){
	Ave::mostrar();
	cout<<"Plumas de ganso importadas por Kg: "<<PlumasKg<<endl;
}
