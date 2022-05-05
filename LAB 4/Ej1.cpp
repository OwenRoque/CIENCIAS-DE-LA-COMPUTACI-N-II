#include "iostream"
using namespace std;
// LAB 04 - ARRAY Y MATRICES
// 1. Escribir un programa donde se pueda ingresar los datos de tres personas,
// como el nombre, apellido, edad y DNI y luego lo muestre por pantalla.
int main()
{
	string nombres[3];
	string apellidos[3];
	string edad[3];
	string dni[3];
	cout << "Ingresar la información de 3 personas: \n";
	for(int i = 0; i < 3; i++)
	{
		cout << "\n******* Persona " << i + 1 <<"********:\n";
		cout << "Nombres: ";
		getline(cin, nombres[i]);
		cout << "Apellidos: ";
		getline(cin, apellidos[i]);
		cout << "Edad: ";
		getline(cin, edad[i]);
		cout << "DNI: ";
		getline(cin, dni[i]);
	}
	cout << "\n******* Datos Recopilados "<<"********:\n";
	for (int j=0;j<3;j++){
		cout<<"Persona "<<j+1<<":\n";
		cout<<"Nombres: "<<nombres[j]<<endl;
		cout<<"Apellidos: "<<apellidos[j]<<endl;
		cout<<"Edad: "<<edad[j]<<endl;
		cout<<"DNI: "<<dni[j]<<endl;
		cout<<endl;
	}
}
