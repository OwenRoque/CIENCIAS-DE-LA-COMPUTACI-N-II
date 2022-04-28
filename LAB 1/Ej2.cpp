#include <iostream>
using namespace std;
// LAB 01 - Condicionales
// 2. Escriba un código que solicite el primer nombre de una persona, el apellido paterno y el apellido materno.
// Retornar su correo UNSA generado, el cual consiste de la primera letra del nombre, el apellido paterno completo,
// y la primera letra del apellido materno. (se agrega el dominio de la universidad al final).

int main() {
	string pnombre, apat, amad, mail, dominio = "@unsa.edu.pe";
	cout << "Ingresa tu primer nombre, apellido paterno y materno EN ESE ORDEN.\n";
	cin >> pnombre;
	cin >> apat;
	cin >> amad;
	cout << "\n";
	mail = pnombre[0]+apat+amad[0]+dominio;
	cout << "Correo generado: " << mail;
	return 0;
}

