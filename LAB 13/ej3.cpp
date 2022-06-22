#include <iostream>
using namespace std;

const int N_PLAYERS = 10;
struct jugador{
	string nombre;
	int edad;
	float talla;
};
typedef struct jugador Jugador;

void leerDatos(Jugador * set){
	cout << "Ingrese los datos de los jugadores:\n\n";
	for (int i = 0; i < N_PLAYERS; i++){
		string _nombre;
		int _edad;
		float _talla;
		cout << "JUGADOR #" << i + 1 << endl;
		cout << "Nombre Completo: ";
		cin >> ws;
		getline(cin,_nombre);
		cout << "Edad: ";
		cin >> _edad;
		cout << "Talla: ";
		cin >> _talla;
		set[i] = {_nombre,_edad,_talla};
		cout<<endl;
	}
}

void filterEdad(Jugador set[], int e){
	cout << "Jugadores menores a " << e << "anios:\n";
	for (int i = 0; i < N_PLAYERS; i++)
		if (set[i].edad < e)
			cout << "- " << set[i].nombre << endl;
}

void filterTalla(Jugador set[], float t){
	cout << "Jugadores con talla mayor a " << t << "metros:\n";
	for (int i = 0; i < N_PLAYERS; i++)
		if (set[i].talla > t)
			cout << "- " << set[i].nombre << endl;	
}
	
int main(int argc, char *argv[]) {
	Jugador set[N_PLAYERS];
	//Jugador *aux = set;
	leerDatos(set);
	filterEdad(set, 20);
	filterTalla(set, 1.70);
	return 0;
}

