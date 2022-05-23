#include "Ave.h"
#include <iostream>
using namespace std;

Ave::Ave(string _tipo,int _mudaplumaje) {
	tipo = _tipo;
	mudaPlumajePorAnio = _mudaplumaje;
}

Ave::~Ave() {}

void Ave::mostrar(){
	cout<<"Clasificacion del ave: "<<tipo<<endl;
	cout<<"Muda de plumaje por anio: "<<mudaPlumajePorAnio<<endl;
}
