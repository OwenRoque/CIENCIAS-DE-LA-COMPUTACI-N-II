#include <iostream>
using namespace std;
// LAB 01 - Condicionales
// 3. Elabore un programa que solicite ingresar una hora del día (HH:MM en formato de cadena), 
// solicite un tiempo en minutos a agregar, y retorne la hora de finalización 
// (el formato de salida debe de estar en AM o PM según corresponda).
int main(int argc, char *argv[]) {
	string hora;
	int tiempo, hh, mm;
	cout<<"ingrese hora: HH:MM \n";
	cin>>hora;
	cout<<"cantidad de minutos a agregar: \n";
	cin>>tiempo;
	hh = stoi(tiempo[0]);
	mm = stoi(tiempo[2]);
	cout<<hh<<" "<<mm;
}

