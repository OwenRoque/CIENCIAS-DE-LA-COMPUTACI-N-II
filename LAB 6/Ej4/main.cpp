#include<iostream>
#include "arreglo.h"
using namespace std;
//  4. Implemente una aplicación con clases donde una clase contiene un arreglo 
//	en el que se pueden almacenar como máximo 5 datos. Debe tener un nuevo dato 
//	para almacenarlo, debe existir un método que verifique que el arreglo tenga 
//	espacio disponible para guardar el dato. En caso contrario se debe mostrar 
//	un mensaje indicando que el arreglo está lleno. 
//  Asimismo, debe tener un método para retirar un dato del arreglo, este método
//  debe verificar que, si haya algo para sacar del arreglo, es decir que el 
//  arreglo no vaya a estar vacío, en cuyo caso debe desplegar un mensaje
//	diciendo que no hay nada para sacar de arreglo.
int main (int argc, char *argv[]) {
	arreglo Arr;
	char opt;
	int pos = 0;
	do {
		cout<<"*****************  Arreglo  ********************\n";
		cout<<"a| AgregarDato\n";
		cout<<"b| RetirarDato\n";
		cout<<"c| Mostrar Array\n";
		cout<<"d| Salir\n";
		cout<<"Ingrese su opcion: ";
		cin>>opt;
		switch (opt){
		case 'a':
			int v;
			cout<<"Valor a ingresar: ";
			cin>>v;
			Arr.agregarDato(v,pos);
			pos++;
			break;
		case 'b':
			int b;
			cout<<"Valor a retirar: ";
			cin>>b;
			Arr.removerDato(b);
			pos--;
			break;
		case 'c':
			Arr.mostrar();
			break;
		case 'd':
			break;
		}
	}
	while (opt!='d');
	cout<<"Array final: \n";
	Arr.mostrar();
	return 0;
}

