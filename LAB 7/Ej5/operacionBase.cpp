#include "operacionBase.h"

operacionBase::operacionBase() {}

operacionBase::~operacionBase() {}

void operacionBase::setOperador(int _op){
	operador = _op;
}

int operacionBase::getOperador(){
	return operador;
}

