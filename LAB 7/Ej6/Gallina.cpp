#include "Gallina.h"
#include "Ave.h"
using namespace std;

Gallina::Gallina(string _tipo,int _mudaplumaje,int _huevos) : Ave(_tipo,_mudaplumaje) {
	cantAnualHuevos= _huevos;
}
Gallina::~Gallina() {}

void Gallina::mostrarGallina(){
	Ave::mostrar();
	cout<<"Cantidad anual de huevos: "<<cantAnualHuevos<<endl;
}
