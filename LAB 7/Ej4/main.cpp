#include "claseMultimedia.h"
#include "claseDisco.h"
#include<iostream>
using namespace std;
//Escribe una clase de nombre ClaseDisco, que herede de la clase ClaseMultimedia los
//atributos y métodos definidos por usted. La clase ClaseDisco tiene, aparte de los
//elementos heredados, un atributo más también definido por usted. Al momento de
//imprimir la información debe mostrase por pantalla toda la información.
int main (int argc, char *argv[]) {
	claseDisco DVD = claseDisco("Fisico",4.7);
	DVD.imprimir();
	return 0;
}

