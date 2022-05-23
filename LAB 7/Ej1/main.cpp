#include<iostream>
#include "Persona.h"
#include "Alumno.h"
using namespace std;
//Crear una clase Persona del cual tendrá métodos asignar una edad y nombre. 
//Una segunda clase, alumno, tendrá que heredar este contenido y a través de
//esta clase poder asignar los datos de edad y nombre de los estudiantes.

int main (int argc, char *argv[]) {
	Alumno alu = Alumno(14, "Eduardo");
	alu.mostrar();
	alu.setEdad();
	alu.setNombre();
	alu.mostrar();
	return 0;
}

