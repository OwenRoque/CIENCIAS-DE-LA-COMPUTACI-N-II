#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
using namespace std;

class alumno{
private:
    int CUI;
    string nombres;
    string apellidos;
    float* notas;
public:
    alumno(int,string,string,float*);
    ~alumno();
    void promedio_notas();
    void output();
};
#endif
