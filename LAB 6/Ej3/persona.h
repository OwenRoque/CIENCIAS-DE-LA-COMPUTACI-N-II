#ifndef PERSONA_H
#define PERSONA_H
using namespace std;
class persona{
private:
	string nombre;
	int edad;
	
public:
	persona(string,int);
	~persona();
	void calculoEdad(int,int);
	void mostrar();
};
#endif
