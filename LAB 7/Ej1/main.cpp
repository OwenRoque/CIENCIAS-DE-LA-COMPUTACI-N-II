#include<iostream>
#include "Persona.h"
#include "Alumno.h"
using namespace std;
//Crear una clase Persona del cual tendr� m�todos asignar una edad y nombre. 
//Una segunda clase, alumno, tendr� que heredar este contenido y a trav�s de
//esta clase poder asignar los datos de edad y nombre de los estudiantes.

int main (int argc, char *argv[]) {
	Alumno alu = Alumno(14, "Eduardo");
	alu.mostrar();
	alu.setEdad();
	alu.setNombre();
	alu.mostrar();
	return 0;
}

