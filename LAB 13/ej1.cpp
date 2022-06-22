#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
using namespace std;

struct alumno{
	string nombre;
	int dia;
	int mes;
	int anio;
};
typedef struct alumno Alumno;

void leerDatos(Alumno* alumnos, const int n){
	cout << "Ingrese los datos de los alumnos:\n\n";
	for (int i = 0; i < n; i++){
		string _nombre;
		int _dia, _mes, _anio;
		cout << "ALUMNO #" << i + 1 << endl;
		cout << "Nombre Completo: ";
		cin >> ws;
		getline(cin,_nombre);
		cout << "Fecha de nacimiento (formato dd mm yyyy) ";
		cin >> _dia >> _mes >> _anio;
		alumnos[i] = {_nombre,_dia,_mes,_anio};
		cout<<endl;
	}
}
	
void mostrarDatos(Alumno* alumnos, const int n){
	for(int i = 0; i < n; i++){
		cout << "ALUMNO #" << i + 1 << endl;
		cout << "Nombre: " << alumnos[i].nombre << endl;
		cout << "FecNac: " << alumnos[i].dia << "/"
						   << alumnos[i].mes << "/" 
						   << alumnos[i].anio << endl;
		cout<<endl;
	}
}

void monthlyBday(Alumno* alumnos, const int n){
	// obtener solo mes actual
	auto t = time(nullptr);
	auto tm = *localtime(&t);
	ostringstream oss;
	//almacenado en oss
	oss << put_time(&tm, "%m");
	// convertirlo a str
	string time = oss.str();
	//convertirlo a int
	int actmonth = stoi(time);
	cout << "CUMPLEAÑEROS DEL MES " << endl;
	for (int i=0; i< n; i++){
		if (alumnos[i].mes == actmonth)
			cout << "- " << alumnos[i].nombre << endl;
	}
}
	
int main(int argc, char *argv[]) {
	int n;
	cout <<"n° alumnos: ";
	cin>>n;
	Alumno* alumnos = new Alumno[n];
	leerDatos(alumnos, n);
	mostrarDatos(alumnos, n);
	monthlyBday(alumnos, n);
	delete [] alumnos;
	return 0;
}

