#ifndef LISTA_H
#define LISTA_H
#include <iostream>
using namespace std;

template <class T>
class Lista;

template <class T>
class Nodo {
public:
	Nodo<T>(T, Nodo* =nullptr);
	friend class Lista<T>;
private:
	T value;
	Nodo* sig; 
};

template <class T>
Nodo<T>::Nodo(T _value, Nodo* _sig) {
	sig = _sig;
	value = _value;
}

template <class T>
class Lista {
public:
	Lista<T>();
	~Lista<T>();
	void insertarInicio(T);
	void insertarFinal(T);
	void insertar(T,unsigned int);
	void eliminarInicio();
	void eliminarFinal();
	void eliminar(unsigned int);	
	void imprimir();
	void imprimir(Lista<T>*);
	void ordenamiento(); 
	unsigned int getSize();
	
private:
	Nodo<T> * first = nullptr;
	unsigned int size = 0;
	
};

//constructor
template <class T>
Lista<T>::Lista(){}

//destructor
template <class T>
Lista<T>::~Lista() {
	Nodo<T> *aux = first;
	Nodo<T> *delete_node;
	while(aux != nullptr) {
		delete_node = aux;
		aux = aux->sig;
		delete delete_node;
	}
	first = nullptr;
	size = 0;
}

//ej 1
template <class T>
	void Lista<T>::insertarFinal(T val){
	Nodo<T> *nuevo = new Nodo<T>(val);
	nuevo->sig = nullptr;
	if (first == nullptr) { // si es el primer elemento 
		first = nuevo;	// a añadir a la lista
	}
	else {
		Nodo<T> * aux = first;
		while(aux->sig!=nullptr){ // recorre actualizando  
			aux = aux->sig; // el valor de aux hasta llegar 
		} // al ultimo valor, que apunta a nullptr por defecto
		aux->sig = nuevo;
	}
	size++;
}

//ej 2
template <class T>
void Lista<T>::insertarInicio(T val){
	Nodo<T> *nuevo = new Nodo<T>(val);
	if (first == nullptr) { // si es el primer elemento 
		nuevo->sig = nullptr; // a añadir a la lista
		first = nuevo;
	}
	else { // si hay elementos en la lista, agrega 
		nuevo->sig = first; //en primera posicion (first)
		first = nuevo;
	}
	size++;
}

//ej 3
template <class T>
void Lista<T>::insertar(T val, unsigned int idx){
	//validar
	if (idx == 0){
		Lista<T>::insertarInicio(val);
		return;
	} 
	if (idx == size) {
		Lista<T>::insertarFinal(val);
		return;
	}
	else if (idx > size){
		cout << "Indice fuera de rango.\n";
		return;
	}
	Nodo<T> * aux = first;
	for (unsigned int i = 0; i < idx-1 ; i++){ //recorremos 
		aux=aux->sig; // hasta llegar al idx-1 indicado
	}
	Nodo<T> *nuevo = new Nodo<T>(val,aux->sig);
	aux->sig = nuevo;
	size++;
}

// ej4
template <class T>
void Lista<T>::eliminarFinal(){
	if (first == nullptr) { 
		cout << "No existen elementos en la lista.\n";
		return;
	} // si es el primer elemento a añadir a la lista
	else {
		Nodo<T> * delete_node = first; // asigno delete a first
		for(unsigned int idx = 0; idx < size-2; idx++){ // recorre 
			delete_node = delete_node->sig; // hasta el penultimo
		}
		delete_node->sig = nullptr; // establece que es el ultimo, apunta a nada
		delete delete_node->sig;
	}
	size--;
}

//ej 5
template <class T>
void Lista<T>::eliminarInicio(){
	if (first == nullptr) { 
		cout << "No existen elementos en la lista.\n";
		return;
	} // si es el primer elemento a añadir a la lista
	else {
		Nodo<T> * delete_node = first; // asigno delete a first
		first = first->sig; // first recorre al siguiente
		delete delete_node;
	}
	size--;
}

// ej 6
template <class T>
void Lista<T>::eliminar(unsigned int idx){
	//validar
	if (idx == 0){
		Lista<T>::eliminarInicio();
		return;
	} 
	if (idx == size) {
		Lista<T>::eliminarFinal();
		return;
	}
	else if (idx > size){
		cout << "Indice fuera de rango.\n";
		return;
	}
	Nodo<T> * prev_node = first;
	//recorremos hasta llegar al idx-1 indicado
	//prev_node = nodo anterior al eliminar
	for (unsigned int i = 0; i < idx-1 ; i++){ 
		prev_node=prev_node->sig;
	}
	//nodo siguiente al eliminar
	Nodo<T> * next_node = prev_node->sig->sig;
	//elimino el nodo
	delete prev_node->sig;
	// asigno el nuevo siguiente
	prev_node->sig = next_node;
	size--;
}

template <class T>
unsigned int Lista<T>::getSize(){
	return size;
}

template <class T>
void Lista<T>::ordenamiento(){
	// lista copia a ordenar
	Lista<T>* ord_list = new Lista<T>;
	Nodo<T> * aux = first;
	for (unsigned int idx = 0; idx < size; idx++){
		ord_list->insertar(aux->value,idx);
		aux = aux->sig;
	}
	Nodo<T> * act = ord_list->first; 
	// nodo actual = head/primero
	T auxi;
	char opt;
	cout << "Ascendente o Descendente\t a|d: ";
	cin >> opt;
	switch (opt) {
	case 'a':
		while (act->sig != nullptr){
			Nodo<T> * next = act->sig;
			while (next!=nullptr){
				if(act->value > next->value){ 
					//switch valores
					auxi = next->value;
					next->value = act->value;
					act->value=auxi;
				}
				next=next->sig; // actualizar el valor de next
			} // ya que while no lo hará
			// recorrer actual y siguiente
			act = act->sig;
			next = act->sig;
		}
		Lista<T>::imprimir(ord_list);
		break;
	case 'd':
		while (act->sig != nullptr){
			Nodo<T> * next = act->sig;
			while (next!=nullptr){
				if(act->value < next->value){ //switch valores
					auxi = next->value;
					next->value = act->value;
					act->value=auxi;
				}
				next=next->sig; // actualizar el valor de next, ya que while no lo hará
			}
			act = act->sig;
			next = act->sig;
		}
		Lista<T>::imprimir(ord_list);
		break;
	default:
		cout<<"Char No valido.\n";
		ord_list->~Lista();
	}
}

// mostrar lista
template <class T>
void Lista<T>::imprimir(){
	Nodo<T> *aux = first;
	while(aux != nullptr) {
		cout << aux->value << " -> ";
		aux = aux->sig;
	}
	cout << endl;
}

template <class T>
void Lista<T>::imprimir(Lista<T>* ord_list){
	Nodo<T> *aux = ord_list->first;
	while(aux != nullptr) {
		cout << aux->value << " -> ";
		aux = aux->sig;
	}
	cout << endl;
	ord_list->~Lista(); // eliminar lista ordenada
}

#endif

