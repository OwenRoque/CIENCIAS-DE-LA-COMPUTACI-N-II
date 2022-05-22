#include "Punto.h"
#include "Forma.h"
#include "Rectangulo.h"
#include "Elipse.h"
#include "Cuadrado.h"
#include "Circulo.h"
#include <iostream>
using namespace std;

//globales
const int nFIG = 20;
int idx = 0;	//Numero de figuras disponibles a crear	= 20
Forma *Formas[nFIG]; 

void crearForma(){
	char *nombreForma = new char[20]; 
	char figOpt;
	string colorForma;
	float a,b;
	
	cout<<"Nombre de la figura: ";
	cin>>nombreForma;	cin.ignore();
	cout<<"Color Forma: ";
	cin>>colorForma;	cin.ignore();
	cout<<"Coordenadas del centro de la figura: ";
	cin>>a>>b;
	Punto *center=new Punto(a,b);
	//Definicion del objeto
	cout<<"Rectangulo o Elipse: R|E\t";
	cin>>figOpt;
	while ((figOpt != 'R') && (figOpt != 'E')){
		cout<<"Opcion no Valida. Ingrese nuevamente: ";
		cin>>figOpt;
	}
	switch (figOpt){
	case 'R':
		float x, y;
		cout<<"Ingrese valores de los lados: ";
		cin>>x>>y;
		if (x > y)
			Formas[idx] = new Rectangulo(nombreForma,center,colorForma,y,x);
		else if (x == y)
			Formas[idx] = new Rectangulo(nombreForma,center,colorForma,x,x);
		else 
			Formas[idx] = new Rectangulo(nombreForma,center,colorForma,x,y);
		Formas[idx]->imprimir();
		idx++;
		break;
	case 'E':
		float r1, r2;
		cout<<"Ingrese valores de los radios: ";
		cin>>r1>>r2;
		if (r1 > r2)
			Formas[idx] = new Elipse(nombreForma,center,colorForma,r2,r1);
		else if (r1 == r2)
			Formas[idx] = new Elipse(nombreForma,center,colorForma,r1,r1);
		else 
			Formas[idx] = new Elipse(nombreForma,center,colorForma,r1,r2);
		Formas[idx]->imprimir();
		idx++;
		break;
	}
}
	
void funcionesForma(){
	int i;
	char FunctOpt;
	cout<<"Indice de Forma a acceder: ";
	cin>>i;
	cout<<"\tI| Imprimir Datos Figura.\n";
	cout<<"\tC| Cambiar Color Figura.\n";
	cout<<"\tM| Mover Figura (centro).\n";
	cout<<"\tA| Calcular Area.\n";
	cout<<"\tP| Calcular Perimetro\n";
	cout<<"\tR| Re-escalar.\n";
	cout<<"\tX| Salir\n";
	cout<<"Ingrese Opcion: ";
	cin>>FunctOpt;
	while (FunctOpt != 'X'){
		switch (FunctOpt){
		case 'I':
			Formas[i]->imprimir();
			break;
		case 'C':
			Formas[i]->cambiarColor();
			break;
		case 'M':
			Formas[i]->moverForma();
			break;
		case 'A':
			cout<<"Area: "<<Formas[i]->area();
			break;
		case 'P':
			cout<<"Perimetro: "<<Formas[i]->perimetro();
			break;
		case 'R':
			float factor;
			cout<<"Factor de escala: ";
			cin>>factor;
			Formas[i]->resize(factor);
			break;
		default:
			cout<<"Opcion no valida.";
		}
		cin.ignore();
		cout<<"\nIngrese Opcion: ";
		cin>>FunctOpt;
	}
}

void changeColorPosition4All(){
	float a, b;
	string inputcolor;
	cout<<"Color a asignar a todos: ";
	cin.ignore();
	getline(cin,inputcolor);
	cout<<"Coordenadas de posicion central de todos: ";
	cin>>a>>b;
	for(int i=0;i<idx;i++){
		Formas[i]->cambiarColor(inputcolor);
		Formas[i]->moverForma(a,b);
	}
	cout<<"Hecho!\n";
}

void maxAreaofAll(){
	int indx;
	float max = 0;
	for(int i=0;i<idx;i++){
		float area = Formas[i]->area();
		if (area > max){
			max = area;
			indx = i;
		}
	}
	cout<<"Area maxima: "<<Formas[indx]->area();
	cout<<"\nInformacion de la figura:\n";
	Formas[indx]->imprimir();
}
	
void ShowInfo_AreaofAll(){
	for(int i=0;i<idx;i++){
		Formas[i]->imprimir();
		cout<<"Area de Figura "<<i+1<<": "<<Formas[i]->area();
	}
}
	
void menu(char menuOpt) {
	switch (menuOpt) {
	case 'a':	//crear figura
		crearForma();
		break;
	case 'b':	//Acceder a figura, con idx, acceder a las funciones del objeto especifico
		funcionesForma();
		break;
	case 'c':	//Ejercicio 5
		changeColorPosition4All();
		break;
	case 'd':	//Ejercicio 8
		maxAreaofAll();
		break;
	case 'e':	// Ejercicio 6
		ShowInfo_AreaofAll();
		break;
	case 'f': 	//Salir
		break;
	default:
		cout<<"Opción no válida.";
	}
}

int main (int argc, char *argv[]) {
	char menuOpt;
	while (menuOpt != 'f'){
		cout<<"********************MENU DE NAVEGACION********************\n";
		cout<<"\ta| Crear nueva Figura.\n";
		cout<<"\tb| Acceder a metodos de una Figura.\n";
		cout<<"\tc| Ejercicio 5: Cambiar color y mover todas las formas.\n";
		cout<<"\td| Ejercicio 8: Calcular el area maxima de todas las formas.\n";
		cout<<"\te| Ejercicio 6: Imprimir info y area de todas las formas.\n";
		cout<<"\tf| Salir\n";
		cin>>menuOpt;
		menu(menuOpt);
	}
	cout<<"Programa Terminado\n";
	delete [] Formas;	
	return 0;
}
