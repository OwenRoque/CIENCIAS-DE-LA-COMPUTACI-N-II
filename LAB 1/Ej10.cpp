#include <iostream>
using namespace std;
// LAB 01 - Condicionales
// 10. Escribir un programa que almacene la cadena de caracteres contraseña en una variable, 
// pregunte al usuario por la contraseña hasta que introduzca la contraseña correcta.
int main(int argc, char *argv[]) {
	string passw, pass2;
	cin>>passw;
	cout<<endl;
	do {
		cout<<"ingrese la contraseña nuevamente: ";
		cin>>pass2;
	}
	while(pass2 != passw);
	cout<<"Hecho.";
	return 0;
}

