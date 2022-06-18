#ifndef PILA_H
#define PILA_H
#include <iostream>
#include <iterator> 
#include <vector>

template <class T>
class Pila;

template <class T>
class Nodo {
public:
	Nodo<T>(T, Nodo* =nullptr);
	friend class Pila<T>;
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
class Pila {
public:
	Pila<T>();
	~Pila<T>();
	void insertar(T);
	void eliminar();
	void search(T);
	void imprimir();
private:
	Nodo<T> * first = nullptr;
	unsigned int size = 0;
};

//constructor
template <class T>
Pila<T>::Pila(){}

//destructor
template <class T>
Pila<T>::~Pila() {
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
void Pila<T>::insertar(T val){
	Nodo<T> * nuevo = new Nodo<T>(val);
	if (first == nullptr){
		nuevo->sig=nullptr;
		first = nuevo;
	} else {
		nuevo->sig=first;
		first = nuevo;
	}
	size++;
}

template <class T>
void Pila<T>::eliminar(){
	if (first == nullptr) { 
		std::cout << "No existen elementos en la lista.\n";
		return;
	} // si es el primer elemento a eliminar a la lista
	else {
		Nodo<T> * delete_node = first; // asigno delete a first
		first = first->sig; // first recorre al siguiente
		delete delete_node;
	}
	size--;
}

template <class T>
void Pila<T>::search(T val){
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
		std::cout << "No se encontró el valor en la pila.\n";
	else  {
		for (unsigned int i=0; i<res.size(); i++){
			std::cout << val << " encontrado en posicion ";
			std::cout << res.at(i) << "\n";
		}
		std::cout << std::endl;
	}
}

template <class T>
void Pila<T>::imprimir(){
	Nodo<T> *aux = first;
	while(aux != nullptr) {
		std::cout << aux->value << " -> ";
		aux = aux->sig;
	}
	std::cout << '\n';
}

#endif

