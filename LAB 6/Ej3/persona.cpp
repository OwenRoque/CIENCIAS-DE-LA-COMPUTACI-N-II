#include<iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "persona.h"
using namespace std;

persona::persona(string _nombre,int _edad){
	nombre = _nombre;
	_edad = edad;
}

persona::~persona(){}

void persona::calculoEdad(int yy, int mm){
	//obtener año y mes actual
	auto t = time(nullptr);
	auto tm = *localtime(&t);
	ostringstream oss;
	oss << put_time(&tm, "%m-%Y");
	string time = oss.str();
	int pos = time.find("-");
	string m = time.substr(0,pos);
	int actmonth = stoi(m);
	string y = time.substr(pos+1);
	int actyear = stoi(y);
	//calculoEdad
	if (actmonth<mm)
		actyear-=1;
	edad = actyear-yy;
}

void persona::mostrar(){
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Edad: "<<edad<<endl;
}
