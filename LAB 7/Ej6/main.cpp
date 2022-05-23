#include "Ave.h"
#include "Ganso.h"
#include "Gallina.h"
#include "Pato.h"
#include<iostream>
using namespace std;

int main (int argc, char *argv[]) {
	Gallina g("Terrestre",1,41200);
	Ganso a("Acuatico",1,50);
	Pato p("Acuatico",2,1500);
	g.mostrarGallina();
	a.mostrarGanso();
	p.mostrarPato();
	return 0;
}

