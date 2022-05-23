#include "claseMultimedia.h"
#include "claseDisco.h"
#include <iostream>
using namespace std;

claseDisco::claseDisco(string _tipo, float _capacity) {
	tipo = _tipo;
	capacity = _capacity;
}

claseDisco::~claseDisco(){}


void claseDisco::imprimir(){
	cout<<"Tipo de multimedia: "<<tipo<<endl;
	cout<<"Capacidad: "<<capacity<<" GB"<<endl;
}
