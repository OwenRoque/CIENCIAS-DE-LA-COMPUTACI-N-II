#include<iostream>
#include "persona.h"
using namespace std;
//3. Implemente un programa con clases que lea
//la fecha de nacimiento y la fecha de hoy; 
//y muestre por pantalla el nombre y 
//la edad de la persona.
int main (int argc, char *argv[]) {
	string name;
	int year, month;
	cout<<"Nombre de la persona: ";
	cin>>name;
	cout<<"Fecha Nacimiento:\n";
	cout<<"\tAnio: ";
	cin>>year;
	cout<<"\tMes: ";
	cin>>month;
	persona p(name,0);
	p.calculoEdad(year,month);
	p.mostrar();
	return 0;
}

