#include <iostream>
using namespace std;
// LAB 03 - FUNCIONES
// 3. Hacer un programa que lee por teclado la fecha actual y la fecha de nacimiento
// de una persona y por medio de una función calcule su edad en años, meses y días.
void calculoEdad(int dd,int mm,int yy,int db,int mb,int yb){
	int anio, mes, dia;
	if (mm<mb){
		yy=yy-1;
		mm=mm+12;
	}
	if (dd<db){
		dd=dd+30;	// tomo 30 como la cantidad promedio de dias en un mes
		mm=mm-1;
	}
	anio = yy - yb;
	mes = mm - mb;
	dia= dd-db;
	cout<<"Años: "<< anio <<"\n"
		<<"Meses: "<< mes <<"\n"
		<<"Dias: "<< dia ;
}
int main(int argc, char *argv[]) {
	int dd, mm ,yy;//fecha actual
	cout<<"Ingrese dia, mes y anio actual: ";
	cin>>dd>>mm>>yy;
	int db, mb ,yb;//fecha nacimiento
	cout<<"Ingrese fecha nacimiento: ";
	cin>>db>>mb>>yb;
	calculoEdad(dd,mm,yy,db,mb,yb);
	return 0;
}

