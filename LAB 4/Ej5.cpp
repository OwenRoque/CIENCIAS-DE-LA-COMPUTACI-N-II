#include <iostream>
using namespace std;
// LAB 04 - ARRAY Y MATRICES
// 5. Implemente un programa que gestione los datos de stock de una tienda de abarrotes, 
// la información a recoger será: nombre del producto, precio, cantidad en stock. 
// La tienda dispone de 10 productos distintos. El programa debe ser capaz de:
//	a. Dar de alta un producto nuevo.
//	b. Buscar un producto por su nombre.
//	c. Modificar el stock y precio de un producto dado.
void menu(char opt, int &i,string nombre[],string precio[],string stock[]){
	switch (opt){
	case 'c':
		{
			cin.ignore();
			if (i>9){
				cout<<"Inventario lleno!";
				break;
			}
			cout<<"Ingrese el nombre del producto nuevo: ";
			getline(cin,nombre[i]);
			cout<<"Ingrese el precio del producto nuevo: ";
			getline(cin,precio[i]);
			cout<<"Ingrese el stock del producto nuevo: ";
			getline(cin,stock[i]);
			cout<<nombre[i]<<"\t"<<precio[i]<<"\t"<<stock[i]<<endl;
			i++;
			cout<<"Hecho!\n\n";
			break;
		}
	case 'm':
		{
			if (i==0){
				cout<<"Inventario vacio, ingrese productos para habilitar esta función!\n\n";
				break;
			}
			cin.ignore();
			string namesearch;
			bool state=false;
			cout<<"Ingrese el nombre del producto a modificar: ";
			getline(cin,namesearch);
			for(int j=0;j<i;j++){
				if (nombre[j]==namesearch){
					cout<<"Ingrese el nuevo nombre del producto: ";
					getline(cin,nombre[j]);
					cout<<"Ingrese el nuevo precio del producto: ";
					getline(cin,precio[j]);
					cout<<"Ingrese el nuevo stock del producto: ";
					getline(cin,stock[j]);
					cout<<nombre[i]<<"\t"<<precio[i]<<"\t"<<stock[i]<<endl;
					state=true;
					i++;
					cout<<"Hecho!\n\n";
					break;
				}
			}
			if (state==false)
				cout<<"Producto no registrado!!\n\n";
			break;
		}
	case 'b':
		{
			if (i==0){
				cout<<"Inventario vacio, ingrese productos para habilitar esta función!\n\n";
				break;
			}
			cin.ignore();
			string nsearch;
			bool state=false;
			cout<<"Ingrese el nombre del producto a buscar: ";
			getline(cin,nsearch);
			for(int j=0;j<i;j++){
				if (nombre[j]==nsearch){
					cout<<"Nombre producto: "<<nombre[j]<<endl;
					cout<<"Precio: "<<precio[j]<<endl;
					cout<<"Stock: "<<stock[j]<<endl<<endl;
					state=true;
					break;
				}
			}
			if (state==false)
				cout<<"Producto no registrado!!\n\n";
			break;
		}
	default:
		cout<<"No se reconoce el caracter.";
	}
}
int main(int argc, char *argv[]) {
	string nombre[10], precio[10], stock[10];
	int i=0;
	char opt;
	do {
		cout<<"**************BIENVENIDO AL GESTOR DE LA TIENDA DE ABARROTES*****************\n"<<
			"c. Dar de alta un producto nuevo.\n"<<
			"b. Buscar un producto por su nombre.\n"<<
			"m. Modificar el stock y precio de un producto dado.\n";
		cin>>opt;
		menu(opt,i,nombre, precio, stock);
	}
	while (true);
	return 0;
}

