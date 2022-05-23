#include "Persona.h"
using namespace std;

Persona::Persona(int _edad, string _nombre) {
	edad = _edad;
	nombre = _nombre;
}

Persona::~Persona() {}

void Persona::setNombre(){
	string _nombre;
	cout<<"Asignar Nombre: ";
	cin.ignore();
	getline(cin,_nombre);
	nombre = _nombre;
}

void Persona::setEdad(){
	int _edad;
	cout<<"Asignar Edad: ";
	cin>>_edad;
	edad = _edad;
}

void Persona::mostrar(){
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Edad: "<<edad<<endl;
}

