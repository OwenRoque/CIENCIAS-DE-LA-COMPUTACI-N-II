#include "Forma.h"
#include <iostream>
using namespace std;

Forma::Forma(char* _nombre, Punto *_centro, string _color) 
	: nombre(_nombre), coord_centro(_centro), color(_color){
	
} 
//solo constructores pueden usar member initializer list

Forma::~Forma(){
	delete coord_centro;    // Eliminar la asignación de memoria asignada a punteros Punto/nombre
	delete nombre;			// mas sigue almacenada en la clase principal Forma
}
	
void Forma::imprimir(){
	cout<<"Color: "<<color<<endl;
	cout<<"Coordenadas Centro: ";
	cout<<"("<<coord_centro->getX()<<"; "<<coord_centro->getY()<<")"<<endl;
	cout<<"Nombre: "<<nombre<<endl;
	cout<<endl;
}

void Forma::cambiarColor(){
	string ncolor;
	cout<<"Nuevo color: ";
	cin.ignore();
	getline(cin,ncolor);
	color = ncolor;
	cout<<"Hecho!\n";
}
void Forma::cambiarColor(string _inputcolor){
	color = _inputcolor;
}

void Forma::moverForma(){ 
	float a, b;
	cout<<"Nuevo valor x,y: ";
	cin>>a>>b;
	coord_centro->x = a;
	coord_centro->y = b;
	cout<<"Hecho!\n";
}

void Forma::moverForma(float _x, float _y){
	coord_centro->x = _x;
	coord_centro->y = _y;
}
