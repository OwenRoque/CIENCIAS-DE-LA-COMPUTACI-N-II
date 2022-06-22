#include <iostream>
using namespace std;
struct empleado {
	string nombre;
	char sexo;
	float sueldo;
};
typedef struct empleado Empleado;


void leerDatos(Empleado* empleados, const int n){
	cout << "Ingrese los datos de los empleados:\n\n";
	for (int i = 0; i < n; i++){
		string _nombre;
		char _sexo;
		float _sueldo;
		cout << "EMPLEADO #" << i + 1 << endl;
		cout << "Nombre Completo: ";
		cin >> ws;
		getline(cin,_nombre);
		cout << "Sexo: (m=masculino | f=femenino | o=otro)";
		cin >> _sexo; 
		cout << "Sueldo que percibe: ";
		cin >> _sueldo;
		empleados[i] = {_nombre,_sexo,_sueldo};
		cout<<endl;
	}
}

void MaxMinSueldo(Empleado* empleados, const int n){
	float max = empleados[0].sueldo;
	float min = empleados[0].sueldo;
	for (int i=0; i < n; i++){
		if (empleados[i].sueldo > max){
			max = empleados[i].sueldo;
		}
		else if (empleados[i].sueldo < min){
			min = empleados[i].sueldo;
		}
	}
	cout << "Minimo sueldo percibido: " << min << endl;
	cout << "Maximo sueldo percibido: " << max << endl;
}

int main(int argc, char *argv[]) {
	int n;
	cout <<"n° empleados: ";
	cin>>n;
	Empleado* empleados = new Empleado[n];
	leerDatos(empleados, n);
	MaxMinSueldo(empleados, n);
	delete [] empleados;
	return 0;
}

