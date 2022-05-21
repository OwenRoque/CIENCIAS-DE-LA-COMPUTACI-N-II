#include <iostream>
#include "alumno.h"
using namespace std;
//Se conoce de un alumno de la Universidad Nacional de San Agustín: CUI, nombre
//completo y tres notas parciales (nota1, nota2, nota3). El programa con clases
//debe imprimir: CUI, el primer nombre, el promedio de las tres notas e indique 
//con un mensaje si el alumno aprobó (nota final >= 10.5) o no aprobó 
//(nota final < 10.5) la asignatura de Ciencias de la Computación II.
int main()
{
	float n[3], cui;
	string nombres, apellidos;
	cout<<"CUI del alumno: ";
	cin>>cui;
	cin.ignore();
	cout<<"Nombres: ";
	getline(cin,nombres);
	cout<<"Apellidos: ";
	getline(cin,apellidos);
	
	float* nPtr;
	nPtr = n;
	cout<<"Ingrese las notas del alumno: \n";
	for (int i=0;i<3;i++){
		int x;
		cout<<"\tNota "<<i+1<<": ";
		cin>>x;
		n[i]=x;
	}
	
	alumno Alumno(cui,nombres,apellidos,nPtr);
	Alumno.output();
	return 0;
}

