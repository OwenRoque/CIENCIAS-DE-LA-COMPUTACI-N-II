#include <iostream>
#include "alumno.h"

using namespace std;

alumno::alumno(int _cui, string _n, string _ap, float* _notas){
	CUI = _cui;
	nombres = _n;
	apellidos = _ap;
	notas = _notas;
}

alumno::~alumno(){}

void alumno::promedio_notas(){
	float res=0;
	for(int i=0;i<3;i++)
		res+=notas[i];
	res=(float)res/3;
	cout<<res<<endl;
	if (res>=10.5) {
		cout<<"El alumno aprobo la asignatura de Ciencias de la Computacion II."<<endl;
	}
	else {
		cout<<"El alumno reprobo la asignatura de Ciencias de la Computacion II."<<endl;
	}
}

void alumno::output(){
	//primer nombre
	int pos = nombres.find(" ");
	string pnombre = nombres.substr(0,pos);
	cout<<"Nota promedio del alumno "<<pnombre<<": ";
	//promedio
	promedio_notas();
}
