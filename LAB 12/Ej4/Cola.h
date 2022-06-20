#ifndef COLA_H
#define COLA_H
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Cola;

template <class T>
void fill(Cola<T> &col, int tam);

template <class T>
class Nodo {
public:
	Nodo<T>(T, Nodo* =nullptr);
	friend class Cola<T>;
	T getValue(){
		return value;
	}
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
class Cola {
public:
	Cola<T>();
	~Cola<T>();
	void insertar(T);
	void reset(); // cambio	
	void imprimir();
	void insertarFinal(T);
	void eliminarInicio();
	T getFirstValue(){
		return first->value;
	}
	friend void fill<>(Cola<T> &col,int tam);
private:
	Nodo<T> * first = nullptr;
	unsigned int size = 0;
};

//constructor
template <class T>
Cola<T>::Cola(){}

//destructor
template <class T>
Cola<T>::~Cola() {
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

// imprimir Cola
template <class T>
void Cola<T>::imprimir(){
	Nodo<T> *aux = first;
	while(aux != nullptr) {
		cout << aux->value << " -> ";
		aux = aux->sig;
	}
	cout << endl;
}

template <class T>
void Cola<T>::insertar(T val){
	Nodo<T> *nuevo = new Nodo<T>(val);
	if (first == nullptr) { // si es el primer elemento 
		nuevo->sig = nullptr; // a añadir a la cola
		first = nuevo;
	}
	else { // si hay elementos en la cola, agrega 
		nuevo->sig = first; //en primera posicion (first)
		first = nuevo;
	}
	size++;
}

template <class T>
void Cola<T>::insertarFinal(T val){
	Nodo<T> *nuevo = new Nodo<T>(val);
	nuevo->sig = nullptr;
	Nodo<T> * aux = first;
	while(aux->sig!=nullptr){ // recorre actualizando  
		aux = aux->sig; // el valor de aux hasta llegar 
	} // al ultimo valor, que apunta a nullptr por defecto
	aux->sig = nuevo;
}

template <class T>
void Cola<T>::eliminarInicio(){
	Nodo<T> * delete_node = first; // asigno delete a first
	first = first->sig; // first recorre al siguiente
	delete delete_node;
}	

// cambios segun al ej 4
template <class T>
void Cola<T>::reset(){ // envia el first al ultimo, recorre first
	Cola<T>::insertarFinal(first->value);
	Cola<T>::eliminarInicio();
}

template <class T>
void fill(Cola<T> &col, int tam){
	for (int i=0; i<tam; i++){
		T v;
		cout << "Valor " << i+1<<": ";
		cin >> v;
		col.insertar(v);
	}
}

#endif
