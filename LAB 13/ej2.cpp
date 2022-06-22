#include <iostream>
#include <iomanip>
using namespace std;

struct alumno{
	string nombre;
	char grupo;
	float notaP1; // 15%
	float notaP2; // 20%
	float notaP3; // 25%
	float notaProjF; // 40%
	float notaFinal;
};
typedef struct alumno Alumno;

float promFinal(float p1, float p2 ,float p3, float pf){
	float _PF = (p1*0.15)+(p2*0.2)+(p3*0.25)+(pf*0.4);
	return _PF;
}

void leerDatos(Alumno* alumnos, const int n){
	cout << "Ingrese los datos de los alumnos:\n\n";
	for (int i = 0; i < n; i++){
		string _nombre;
		char _grupo;
		float _p1, _p2, _p3, _pf;
		cout << "ALUMNO #" << i + 1 << endl;
		cout << "Nombre Completo: ";
		cin >> ws;
		getline(cin,_nombre);
		cout << "Grupo: ";
		cin >> _grupo; toupper(_grupo);
		cout << "Notas en orden (P1 P2 P3 PF) ";
		cin >> _p1 >> _p2 >> _p3 >> _pf;
		float _NF = promFinal(_p1,_p2,_p3,_pf);
		alumnos[i] = {_nombre,_grupo,_p1,_p2,_p3,_pf,_NF};
		cout<<endl;
	}
}
	
void mostrarDatos(Alumno* alumnos, const int n){
	cout << left << setw(25) << "Nombre Completo"
		<< left << setw(15) << "NParcial 1"
		<< left << setw(15) << "NParcial 2"
		<< left << setw(15) << "NParcial 3"
		<< left << setw(18) << "NProyectoFinal"
		<< left << setw(18) << "Nota FINAL del Curso"
		<< endl;
	for(int i = 0; i < n; i++){
		cout << left << setw(25) << alumnos[i].nombre
			<< left << setw(15) << alumnos[i].notaP1
			<< left << setw(15) << alumnos[i].notaP2
			<< left << setw(15) << alumnos[i].notaP3
			<< left << setw(18) << alumnos[i].notaProjF
			<< left << setw(18) << alumnos[i].notaFinal
			<< endl;
	}
}

int main(int argc, char *argv[]) {
	int n;
	cout <<"n° alumnos: ";
	cin>>n;
	Alumno* alumnos = new Alumno[n];
	leerDatos(alumnos, n);
	mostrarDatos(alumnos, n);
	delete [] alumnos;
	return 0;
}

