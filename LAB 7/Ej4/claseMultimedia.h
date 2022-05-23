#ifndef CLASEMULTIMEDIA_H
#define CLASEMULTIMEDIA_H
#include <iostream>
using namespace std;

class claseMultimedia {
public:
	claseMultimedia();
	~claseMultimedia();
	void setTipo(string);
protected:
	string tipo;	//fisico o digital
};

#endif

