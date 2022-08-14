#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class AbstractSumatorias {
public:
	virtual ~AbstractSumatorias() {};
	virtual int operator()(const vector<pair<int,int>>& data) const = 0;
};

class Context {
private:
	AbstractSumatorias *ptr_sumatoria;
public:
	Context(AbstractSumatorias *ptr = nullptr) : ptr_sumatoria(ptr) {}
	~Context(){ delete this->ptr_sumatoria;}
	void setSumatoria(AbstractSumatorias *sumatoria){
		delete this->ptr_sumatoria;
		this->ptr_sumatoria = sumatoria;
	}
	int ejecutarSumatoria(const vector<pair<int,int>>& data) {
		int result = this->ptr_sumatoria->operator()(data);	
		return result;
	}
};

class Sumatoria_x : public AbstractSumatorias {
public:
	int operator()(const vector<pair<int,int>>& v) const override {
		int Sumatoria = 0;
		for(std::size_t i = 0; i < v.size(); i++)
			Sumatoria += v[i].first;
		return Sumatoria;
	}
};

class Sumatoria_y : public AbstractSumatorias {
public:
	int operator()(const vector<pair<int,int>>& v) const override {
		int Sumatoria = 0;
		for(std::size_t i = 0; i < v.size(); i++)
			Sumatoria += v[i].second;
		return Sumatoria;
	}
};

class Sumatoria_xy : public AbstractSumatorias {
public:
	int operator()(const vector<pair<int,int>>& v) const override {
		int Sumatoria = 0;
		for(std::size_t i = 0; i < v.size(); i++){
			int multiply = v[i].first * v[i].second;
			Sumatoria += multiply;
		}
		return Sumatoria;
	}
};

class Sumatoria_x_square : public AbstractSumatorias {
public:
	int operator()(const vector<pair<int,int>>& v) const override {
		int Sumatoria = 0;
		for(std::size_t i = 0; i < v.size(); i++)
			Sumatoria += pow(v[i].first, 2);
		return Sumatoria;
	}
};

// https://youtu.be/4PiiSUxcalg
class RegLinSim {
// y = a + bx
public:
	double calcularParamA(int n, int sx, int sy, int sxy, int sxx){
		double a = ((n * sxy) - (sx * sy))/((n * sxx) - pow(sx, 2));
		return a;
	}
	double calcularParamB(int n, int sx, int sy, int sxy, int sxx){
		double a = this->calcularParamA(n, sx, sy, sxy, sxx);
		double b = double(sy)/n - a * double(sx)/n;
		return b;
	} 
};

int main(int argc, char *argv[]) {
	// <x, y>
	// https://youtu.be/4PiiSUxcalg
	vector<std::pair<int,int>> vector_pares = { 
		{1,2},
		{2,3},
		{2,4},
		{3,4},
		{4,4},
		{4,6},
		{5,5},
		{6,7}
	};
	int n, sum_x, sum_y, sum_xy, sum_x_square;
	// Obtencion de sumatorias a traves de 
	// functores y Patron de Disenho Strategy
	n = vector_pares.size();
	//cout << "n: " << n << endl;
	Context *context = new Context(new Sumatoria_x);
	sum_x = context->ejecutarSumatoria(vector_pares);
	//cout << "sx: " << sum_x << endl;
	context->setSumatoria(new Sumatoria_y);
	sum_y = context->ejecutarSumatoria(vector_pares);
	//cout << "sy: " << sum_y << endl;
	context->setSumatoria(new Sumatoria_xy);
	sum_xy = context->ejecutarSumatoria(vector_pares);
	//cout << "sxy: " << sum_xy << endl;
	context->setSumatoria(new Sumatoria_x_square);
	sum_x_square = context->ejecutarSumatoria(vector_pares);
	//cout << "sxx: " << sum_x_square << endl;
	delete context;	
	// Ecuacion de regresion lineal simple
	RegLinSim ec;
	cout << "y = a + bx" << endl;
	double param_a = ec.calcularParamA(n, sum_x, sum_y, sum_xy, sum_x_square);
	cout << "Parametro A: " << param_a << endl;
	double param_b = ec.calcularParamB(n, sum_x, sum_y, sum_xy, sum_x_square);
	cout << "Parametro B: " << param_b << endl;
	return 0;
}

