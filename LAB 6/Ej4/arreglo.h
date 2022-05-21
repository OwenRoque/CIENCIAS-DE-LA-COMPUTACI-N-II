#ifndef ARREGLO_H
#define ARREGLO_H
class arreglo{
private:
	int arr[5]; 
public:
	arreglo();
	~arreglo();
	void agregarDato(int,int&);
	void removerDato(int);
	void mostrar();
};
#endif
