#ifndef COLA_H
#define COLA_H
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Cola;

template <class T>
class Nodo {
public:
	Nodo<T>(T, Nodo* =nullptr);
	friend class Cola<T>;
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
	void eliminar();	
	void imprimir();
	void search(T);
	unsigned int getSize();
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

template <class T>
unsigned int Cola<T>::getSize(){
	return size;
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

// ej 1
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

// ej 2
template <class T>
void Cola<T>::eliminar(){
	if (first == nullptr) { 
		cout << "No existen elementos en la Cola.\n";
		return;
	} 
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

// ej 3
template <class T>
void Cola<T>::search(T val){
	// lista de posiciones
	std::vector<int> res;
	unsigned int idx=0;
	Nodo<T> * aux = first;
	for (;idx < size; idx++){
		if (aux->value == val){
			res.push_back(idx);
		}
		// recorrer al siguiente nodo
		aux = aux->sig;
	}
	if (res.empty())	
		std::cout << "No se encontró el valor en la Cola.\n";
	else  {
		for (unsigned int i=0; i<res.size(); i++){
			std::cout << val << " encontrado en posicion ";
			std::cout << res.at(i) << "\n";
		}
		std::cout << std::endl;
	}
}
#endif
