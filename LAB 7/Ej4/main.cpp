#include "claseMultimedia.h"
#include "claseDisco.h"
#include<iostream>
using namespace std;
//Escribe una clase de nombre ClaseDisco, que herede de la clase ClaseMultimedia los
//atributos y m�todos definidos por usted. La clase ClaseDisco tiene, aparte de los
//elementos heredados, un atributo m�s tambi�n definido por usted. Al momento de
//imprimir la informaci�n debe mostrase por pantalla toda la informaci�n.
int main (int argc, char *argv[]) {
	claseDisco DVD = claseDisco("Fisico",4.7);
	DVD.imprimir();
	return 0;
}

