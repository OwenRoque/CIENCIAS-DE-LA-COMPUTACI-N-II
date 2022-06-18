#ifndef PILA_H
#define PILA_H
#include <iostream>
#include <iterator> 
#include <vector>
#include <iomanip>

// firmas de clases y funciones
template <class T>
class Pila;

template <class T>
void imprimirHanoi(Pila<T> &o, Pila<T> &d, Pila<T> &a);

template <class T>
void hanoi(unsigned int size,Pila<T> &o,Pila<T> &d,Pila<T> &a);

// fin firmas clases y funciones

template <class T>
class Nodo {
public:
	Nodo<T>(T, Nodo* =nullptr);
	friend class Pila<T>;
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
class Pila {
public:
	// constructor
	Pila<T>(){}
	// destructor
	~Pila<T>(){
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
	void insertar(T val){
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
	void eliminar(){
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
	void search(T val) const {
		// lista de posiciones
		std::vector<int> res;
		unsigned int idx=0;
		Nodo<T> * aux = first;
		for (idx; idx < size; idx++){
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
				std::cout << val << " encontrado en posicion " << res.at(i) << "\n";
			}
		}
	}
	void imprimir() const {
		Nodo<T> *aux = first;
		std::cout << "BaseTorre -> ";
		while(aux != nullptr) {
			std::cout << aux->value << " -> ";
			aux = aux->sig;
		}
		
		std::cout << '\n';
	}
	// solo para imprimir de forma vertical
	void imprimirTorre() const {
		char arrow='|';
		Nodo<T> *aux = first;
		while(aux != nullptr) {
			std::cout << aux->value << '\n';
			std::cout << arrow << '\n' ;
			aux = aux->sig;
		}
		std::cout << '\n';
	}
	unsigned int getSize() const {
		return size;
	}
	Nodo<T>* getfirst(){
		return first;
	}
	friend void imprimirHanoi<>(Pila<T> &o, Pila<T> &d, Pila<T> &a);
	friend void hanoi<>(unsigned int size,Pila<T> &o,Pila<T> &d,Pila<T> &a);
private:
	Nodo<T> * first = nullptr;
	unsigned int size = 0;
};

template <class T>
void imprimirHanoi(Pila<T> &o, Pila<T> &d, Pila<T> &a){
	std::cout << "Estado de torres \n";
	std::cout << std::setw(20) << std::left << "Origen";
	o.imprimir();
	std::cout << std::setw(20) << std::left << "Auxiliar";
	a.imprimir();
	std::cout << std::setw(20) << std::left << "Destino";
	d.imprimir();
	std::cout<<'\n';
}

template <class T>
void hanoi(unsigned int size, Pila<T> &o, Pila<T> &d, Pila<T> &a){
	if (size == 1){
		Nodo<T> *origin_first = o.getfirst();
		T temp = origin_first->getValue();
		d.insertar(temp);
		o.eliminar();
		delete origin_first;
		return;
	} 
	else {
		hanoi(size-1,o,a,d);
		Nodo<T> *origin_first = o.getfirst();
		T temp = origin_first->getValue();
		d.insertar(temp);
		o.eliminar();
		delete origin_first;
		hanoi(size-1,a,d,o);
	}
	
}


#endif

