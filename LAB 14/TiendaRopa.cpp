#include <iostream>
#include <sstream>
#include <limits>
#include <vector>
#include <fstream>

using std::cout; using std::endl;
using std::cin; using std::numeric_limits;
using std::string; using std::istringstream;

// var. global para saber el idx/limite del array de articulos (<= a 10)
int idxfiller = 0;
// 0 = no se borro | 1 = se borro/está vacia
int accesorios_was_deleted = 1;

void fillItems(string ** accesorios, int tamanio){
	string codigo ,nombre;
	float precio;
	int stock, estado = 0; // 1 = Activo | 0 = Nulo
	int n;
	int rangoDisponible = tamanio-idxfiller;
	if (rangoDisponible == 0) {
		cout << "Lista de articulos LLENA!\n";
		system("pause");
		system("cls");
		return;
	}
	cout << "Cant. articulos a crear (<= a " << rangoDisponible << "): ";
	cin >> n;
	if (n >= rangoDisponible){
		cout << "Cant. debe ser <= a " << rangoDisponible << "!\n";
		cin.clear();
		system("pause");
		system("cls");
		return;
	}
	cout << "Por favor ingrese la siguiente información de los accesorios: \n";
	for(int i = 0; i < n; i++){
		// ncolumnas = nAtributos
		// codigo, nombre, precio
		// stock, estado
		const int cols = 5;
		accesorios[i] = new string[cols];
		cout << "\n******* Item #" << i + 1 << "********:\n";
		cin.ignore();
		cout << "Codigo: ";
		getline(cin,codigo);
		cout << "Nombre: ";
		getline(cin,nombre);
		cout << "Precio (S/): ";
		while(!(cin >> precio)){ // validar precio
			cout << "Formato incorrecto!\n";
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "Precio: ";
		}
		cout << "Stock: ";
		while(!(cin >> stock)){ // validar stock
			cout << "Formato incorrecto!\n";
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "Stock: ";
		}
		do { // validar estado
			cout << "Estado (0 = anulado | 1 = activo): ";
			cin >> estado;
		} while (estado != 0 && estado != 1);
		//cin.ignore();
		string _precio = std::to_string(precio);
		string _stock = std::to_string(stock);
		string _estado = std::to_string(estado);
		*(*(accesorios+i)+0) = codigo;
		*(*(accesorios+i)+1) = nombre;
		*(*(accesorios+i)+2) = _precio;
		*(*(accesorios+i)+3) = _stock;
		*(*(accesorios+i)+4) = _estado;
	}
	idxfiller+=n;
	accesorios_was_deleted = 0;
	cout << "HECHO!" << endl;
	system("pause");
	system("cls");
}

void deleteItems(string ** accesorios, int tamanio){
	// verificar
	if (accesorios_was_deleted == 1){
		cout << "La lista de articulos YA SE ELIMINO.\n";
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < idxfiller; ++i)
		delete [] accesorios[i]; 
	accesorios_was_deleted = 1;
	idxfiller = 0;
	cout << "HECHO!" << endl;
	system("pause");
	system("cls");
}	

void DarDeAlta(string ** accesorios, int tamanio){
	if (idxfiller == 10){
		cout << "Lista de articulos LLENA!\n";
		system("pause");
		system("cls");
		return;
	}
	else {
		string codigo ,nombre;
		float precio;
		int stock, estado = 0; // 1 = Activo | 0 = Nulo
		const int cols = 5;
		accesorios[idxfiller] = new string[cols];
		cout << "\n******* Item #" << idxfiller + 1 << "********:\n";
		cin.ignore();
		cout << "Codigo: ";
		getline(cin,codigo);
		cout << "Nombre: ";
		getline(cin,nombre);
		cout << "Precio (S/): ";
		while(!(cin >> precio)){
			cout << "Formato incorrecto!\n";
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "Precio: ";
		}
		cout << "Stock: ";
		while(!(cin >> stock)){
			cout << "Formato incorrecto!\n";
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "Stock: ";
		}
		do {
			cout << "Estado (0 = anulado | 1 = activo): ";
			cin >> estado;
		} while (estado != 0 && estado != 1);
		//cin.ignore();
		string _precio = std::to_string(precio);
		string _stock = std::to_string(stock);
		string _estado = std::to_string(estado);
		*(*(accesorios+idxfiller)+0) = codigo;
		*(*(accesorios+idxfiller)+1) = nombre;
		*(*(accesorios+idxfiller)+2) = _precio;
		*(*(accesorios+idxfiller)+3) = _stock;
		*(*(accesorios+idxfiller)+4) = _estado;
		idxfiller++;
		accesorios_was_deleted = 0;
		cout << "HECHO!" << endl;
		system("pause");
		system("cls");
	}
}

void DarDeBaja(string ** accesorios, int tamanio){
	string _codigo; int search_status = 0;
	cout << "Ingrese codigo del articulo a dar de baja: ";
	cin.ignore();
	getline(cin,_codigo);
	for (int i = 0; i < idxfiller; ++i){
		if (*(*(accesorios+i)+0) == _codigo){
			*(*(accesorios+i)+3) = "0"; // no hay stock
			*(*(accesorios+i)+4) = "0"; // anulado
			cout << "HECHO!";
			search_status = 1;
			break;
		}
	}
	if (search_status == 0){
		cout << "No se encontro el codigo ingresado.\n";
		cout << "Intente Nuevamente.\n";
	}
	system("pause");
	system("cls");
}

void searchItem(string ** accesorios, int tamanio){
	string _valor; int search_status = 0;
	cout << "Ingrese codigo o nombre del articulo a buscar: ";
	cin.ignore();
	getline(cin,_valor);
	for (int i = 0; i < idxfiller; ++i){
		if ((*(*(accesorios+i)+0) == _valor) || (*(*(accesorios+i)+1) == _valor)){
			// mostrar informacion del articulo
			cout << "Articulo # " << i+1 << ":\n";
			cout << "Nombre: " << *(*(accesorios+i)+0) << endl;
			cout << "Codigo: " << *(*(accesorios+i)+1) << endl;
			cout << "Precio: S/ " << *(*(accesorios+i)+2) << endl;
			cout << "Stock: " << *(*(accesorios+i)+3) << endl;
			// comparacion con op. ternario
			string _estado = (*(*(accesorios+i)+4) == "0") ? "Anulado" : "Activo";
			cout << "Estado: " << _estado << endl;
			search_status = 1;
			break;
		}
	}
	if (search_status == 0){
		cout << "No se encontro ningun resultado.\n";
		cout << "Intente Nuevamente.\n";
	}
	cout << "HECHO!\n";
	system("pause");
	system("cls");
}	

void modifyItem(string ** accesorios, int tamanio){
	string _valor; int search_status = 0; int was_modified = 0; int was_cancelled = 0;
	cout << "Ingrese codigo o nombre del articulo a buscar: ";
	cin.ignore();
	getline(cin,_valor);
	for (int i = 0; i < idxfiller; ++i){
		if ((*(*(accesorios+i)+0) == _valor) || (*(*(accesorios+i)+1) == _valor)){
			// modificar campos
			cout << "\n******* Articulo a modificar => Item #" << i + 1 << "********:\n";
			cout << "Nombre: " << *(*(accesorios+i)+0) << endl;
			cout << "Codigo: " << *(*(accesorios+i)+1) << endl;
			cout << "Precio: S/ " << *(*(accesorios+i)+2) << endl;
			cout << "Stock: " << *(*(accesorios+i)+3) << endl;
			// comparacion con op. ternario
			string _estado = (*(*(accesorios+i)+4) == "0") ? "Anulado" : "Activo";
			cout << "Estado: " << _estado << endl;
			cout << endl;
			search_status = 1;
			cout << "Escoja los campos que desea modificar: \n";
			cout << "(Solo puede escoger uno a la vez) \n";
			cout << " ->codigo (c)\n";
			cout << " ->nombre (n)\n";
			cout << " ->precio (p)\n";
			cout << " ->stock  (s)\n";
			cout << " ->estado (e)\n";
			cout << " ->cancelar (x)\n";
			char opt;
			cout << "Ingrese una opcion: ";
			cin >> opt;
			switch (opt){
			case 'c':
			{
				string ncodigo;
				cin.ignore();
				cout << "Nuevo Codigo: ";
				getline(cin,ncodigo);
				*(*(accesorios+i)+0) = ncodigo;
				was_modified = 1;
				break;
			}
			case 'n':
			{
				string nnombre;
				cin.ignore();
				cout << "Nuevo Nombre: ";
				getline(cin,nnombre);
				*(*(accesorios+i)+1) = nnombre;
				was_modified = 1;
				break;
			}
			case 'p':
			{
				float nprecio;
				cout << "Nuevo Precio: ";
				while(!(cin >> nprecio)){
					cout << "Formato incorrecto!\n";
					cin.clear();
					cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
					cout << "Nuevo Precio: ";
				}
				string n_precio = std::to_string(nprecio);
				*(*(accesorios+i)+2) = n_precio;
				was_modified = 1;
				break;
			}
			case 's':
			{
				int nstock;
				cout << "Nuevo Stock: ";
				while(!(cin >> nstock)){
					cout << "Formato incorrecto!\n";
					cin.clear();
					cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
					cout << "Nuevo Stock: ";
				}
				string n_stock = std::to_string(nstock);
				*(*(accesorios+i)+3) = n_stock;
				was_modified = 1;
				break;
			}
			case 'e':
			{
				int nestado;
				do {
					cout << "Nuevo Estado (0 = anulado | 1 = activo): ";
					cin >> nestado;
				} while (nestado != 0 && nestado != 1);
				//cin.ignore();
				string n_estado = std::to_string(nestado);
				*(*(accesorios+i)+4) = n_estado;
				was_modified = 1;
				break;
			}
			case 'x':
			{
				was_cancelled = 1;
				break;
			}
			default:
			{
				cout << "Campo no Valido!\n";
			}
			}
		}
	}
	if (search_status == 0){
		cout << "No se encontro ningun resultado.\n";
		cout << "Intente Nuevamente.\n";
		system("pause");
		system("cls");
		return;
	}
	else if (was_modified == 0){
		if (was_cancelled == 1){
			cout << "Modificacion Cancelada!\n";
		} else {
			cout << "No se logró modificar el articulo.\n";
			cout << "Intente Nuevamente.\n";
		}
		system("pause");
		system("cls");
		return;
	}
	else {
		cout << "HECHO!\n";
		system("pause");
		system("cls");
		return;
	}
}	

void showAllItems(string ** accesorios, int tamanio){
	if (idxfiller == 0){
		cout << "Lista de ariculos VACIA!\n";
	}
	else {
		for (int i = 0; i < idxfiller; ++i){
			// mostrar informacion del articulo
			cout << "Articulo # " << i+1 << ":\n";
			cout << "Codigo: " << *(*(accesorios+i)+0) << endl;
			cout << "Nombre: " << *(*(accesorios+i)+1) << endl;
			cout << "Precio: S/ " << *(*(accesorios+i)+2) << endl;
			cout << "Stock: " << *(*(accesorios+i)+3) << endl;
			// comparacion con op. ternario
			string _estado = (*(*(accesorios+i)+4) == "0") ? "Anulado" : "Activo";
			cout << "Estado: " << _estado << endl;
			cout << "-----------------------------------\n\n";
		}
		cout << "HECHO!\n";
	}
	system("pause");
	system("cls");
}	
	
void menu(string ** accesorios, int tamanio){
	char opt;
	while (opt != 'h'){
		void (*fptr)(string**, int) = nullptr;
		cout << "Slots disponibles = " << tamanio - idxfiller << endl;
		cout << "***********ACCIONES DISPONIBLES***********\n";
		cout << " - fillItems 	   (a)\n";
		if (accesorios_was_deleted == 0){
			cout << " - deleteItems     (b)\n";
		}
		cout << " - DarDeAlta       (c)\n";
		cout << " - DarDeBaja       (d)\n";
		cout << " - searchItem      (e)\n";
		cout << " - modifyItem      (f)\n";
		cout << " - showAllItems    (g)\n";
		cout << " - Exit            (h)\n";
		cin >> opt;
		switch (opt) {
		case 'a':
			fptr = fillItems;
			fptr(accesorios, tamanio);
			break;
		case 'b':
			fptr = deleteItems;
			fptr(accesorios, tamanio);
			break;
		case 'c':
			fptr = DarDeAlta;
			fptr(accesorios, tamanio);
			break;
		case 'd':
			fptr = DarDeBaja;
			fptr(accesorios, tamanio);
			break;		case 'e':
			fptr = searchItem;
			fptr(accesorios, tamanio);
			break;
		case 'f':
			fptr = modifyItem;
			fptr(accesorios, tamanio);
			break;
		case 'g':
			fptr = showAllItems;
			fptr(accesorios, tamanio);
			break;
		case 'h':
			// en caso cree los items y salga directamente del programa
			// sin liberar memoria (no elegi la opcion b antes)
			for (int i = 0; i < idxfiller; ++i)
				delete [] accesorios[i]; 
			delete [] accesorios;
			cout << "Saliendo del programa...\n";
			break;
		default:
			cout << "Opcion no valida!\n";
			system("pause");
			system("cls");
		}
	}
	cout << "Fin del Programa.\n";
}

int main() {
	// matriz (punteros de punteros)
	string** accesorios; 
	const int tamanio = 10; // 10 tamanio maximo
	// tamanio = nfilas = nItems
	// se crea accesorios por default
	// se eliminará de todas formas al 
	// terminar la function menu()
	accesorios = new string*[tamanio];
	menu(accesorios,tamanio);
	return 0;
}
