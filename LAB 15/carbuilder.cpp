#include <iostream>
#include <vector>
using namespace std;

const vector<string> Direccion {"Direccion Mecanica","Direccion Hidraulica",
	"Direccion Electrohidraulica","Direccion  Electromecanica"};
const vector<string> Ventanas {"Vidrio Blindado","Vidrio Laminado",
	"Vidrio Polarizado"};
const vector<string> Carroceria {"Aleacion de Hierro","Aleacion de Aluminio",
	"Aleacion de Magnesio","Hierro con Acero Balistico"};
const vector<string> Combustible {"Gasolina","Diesel","Gas","Electrico"};
const vector<string> NCilindro {"Mono","Doble","Multiple"};

struct Motor {
	string combustible;
	string ncil;
}; 

class Auto {
public:
	vector<string> componentes;
	void ListaComp() const {
		cout << "----------------Componentes del automovil construido--------------\n\n";
		cout << "Color: " << componentes[0] << endl;
		cout << "Numero de asientos: " << componentes[1] << endl;
		cout << "\t -Material: " << componentes[5] << endl;
		cout << "Caracteristicas del Motor: \n";
		cout << "\t -Combustible: " << componentes[2] << endl;
		cout << "\t -Numero de Cilindros: " << componentes[3] << endl;
		cout << "Tipo de neumaticos: " << componentes[4] << endl;
		cout << "Tipo de direccion automotriz: " << componentes[6] << endl;
		cout << "Tipo de ventanas: " << componentes[7] << endl;
		cout << "Material de la Carrocería: " << componentes[8] << endl;
		cout << "\t -" << componentes[9] << endl;
		cout << "\n\n";
	}
};

class CarBuilder {
public:
	virtual ~CarBuilder() {}
	// color del auto
	virtual void setColor(string color) const = 0;
	// cantidad de asientos
	virtual void setAsientos(int asientos) const = 0;
	// Tipo del motor, deportivo, normal, etc.
	virtual void tipoMotor(Motor motor) const = 0;	
	// Tipo / modelo de los neumaticos
	virtual void tipoNeumaticos(string neumaticos) const = 0;
	// material de los asientos
	virtual void tipoAsientos(string mat_asientos) const = 0;
	// tipo de direccion automotriz, (timon)
	virtual void tipoDireccion(string timon) const = 0;
	// tipos de ventanas: Vidrio reforzado, laminado, polarizado 
	virtual void tipoVentanas(string ventanas) const = 0;
	// material de la carrorecia
	virtual void tipoCarroceria(string material) const = 0;
	// si el auto posee sistema de bolsas de aire
	virtual void hasAirBag(bool res) const = 0;
};

class BuilderEspecifico : public CarBuilder {
private:
	Auto* car;
public:
	BuilderEspecifico() {
		this->Reset();
	}
	~BuilderEspecifico() {
		delete car;
	}
	void Reset() {
		this->car = new Auto();
	}
	void setColor(string color) const override {
		this->car->componentes.push_back(color);
	}
	void setAsientos(int asientos) const override {
		this->car->componentes.push_back(to_string(asientos));
	}
	void tipoMotor(Motor motor) const override {
		this->car->componentes.push_back(motor.combustible);
		this->car->componentes.push_back(motor.ncil);
	}
	void tipoNeumaticos(string neumaticos) const override {
		this->car->componentes.push_back(neumaticos);
	}
	void tipoAsientos(string mat_asientos) const override {
		this->car->componentes.push_back(mat_asientos);
	}
	void tipoDireccion(string timon) const override {
		this->car->componentes.push_back(timon);
	}
	void tipoVentanas(string ventanas) const override {
		this->car->componentes.push_back(ventanas);
	}
	void tipoCarroceria(string material) const override {
		this->car->componentes.push_back(material);
	}
	void hasAirBag(bool res) const override {
		if (res)
			this->car->componentes.push_back("Posee sistema de Bolsas de Aire");
		else 
			this->car->componentes.push_back("NO Posee sistema de Bolsas de Aire");
	}
	Auto* GetAutomovil() {
		Auto* resultado = this->car;
		this->Reset();
		return resultado;
	}
};

class Director {
private:
	CarBuilder* builder;
public:
	void set_builder(CarBuilder* builder) {
		this->builder = builder;
	}
	void BuildNormalCar() {
		this->builder->setColor("Blanco");
		this->builder->setAsientos(4);
		Motor motorNormalCar = {
			Combustible[1],
			NCilindro[2]
		};
		this->builder->tipoMotor(motorNormalCar);
		this->builder->tipoNeumaticos("Neumaticos Todo Tiempo");
		this->builder->tipoAsientos("Cuero");
		this->builder->tipoDireccion(Direccion[0]);
		this->builder->tipoVentanas(Ventanas[1]);
		this->builder->tipoCarroceria(Carroceria[0]);
		this->builder->hasAirBag(false);
	}
	void BuildBulletProofCar() {
		this->builder->setColor("Negro");
		this->builder->setAsientos(6);
		Motor motorBpCar = {
			Combustible[1],
			NCilindro[2]
		};
		this->builder->tipoMotor(motorBpCar);
		this->builder->tipoNeumaticos("Neumatico Todo Terreno");
		this->builder->tipoAsientos("Aramida");
		this->builder->tipoDireccion(Direccion[1]);
		this->builder->tipoVentanas(Ventanas[0]);
		this->builder->tipoCarroceria(Carroceria[3]);
		this->builder->hasAirBag(true);
	}
};


void ClienteCode(Director& director)
{
	BuilderEspecifico* builder = new BuilderEspecifico();
	director.set_builder(builder);
	Auto* p;
	cout << "-------------FABRICACION DE AUTOMOVILES--------------\n";
	cout << "C.- Construir Automovil Comun" << endl;
	cout << "B.- Construir Automovil Blindado" << endl;
	cout << "P.- Construir Automovil Personalizado" << endl;
	cout << "X.- Salir" << endl;
	char opt;
	cin >> opt;
	switch (opt) {
	case 'C': // A. Comun
		{
		std::cout << "Automovil Comun:\n";
		director.BuildNormalCar();
		Auto* p = builder->GetAutomovil();
		p->ListaComp();
		delete p;
		break;
		}
	case 'B': // A. Blindado
		{
		std::cout << "Automovil Blindado:\n";
		director.BuildBulletProofCar();
		p = builder->GetAutomovil();
		p->ListaComp();
		delete p;
		break;
		}
	case 'P': // A. Personalizado
		{
		int nasientos, comb, cil, dir, vent, carr;
		string col, neum, matseats;
		char airb; 
		cout << "Color: ";
		cin.ignore();
		getline(cin, col);
		cout << "N° Asientos: ";
		cin >> nasientos;
		cout << "Material de los asientos: ";
		cin.ignore();
		getline(cin, matseats);
		cout << "Aspectos del motor: \n";
		cout << "Tipo de combustible: " << endl;
		for (size_t i = 0; i < Combustible.size(); i++)
			cout << "\t [" << i << "]->" << Combustible[i] << endl;
		cin >> comb;
		cout << "N° de cilindros: " << endl;
		for (size_t i = 0; i < NCilindro.size(); i++)
			cout << "\t [" << i << "]->" << NCilindro[i] << endl;
		cin >> cil;
		
		Motor motorCustomCar = {
			Combustible[comb],
			NCilindro[cil]
		};
		cout << "Tipo neumaticos: ";
		cin.ignore();
		getline(cin, neum);
		cout << "Direccion automotriz: " << endl;
		for (size_t i = 0; i < Direccion.size(); i++)
			cout << "\t [" << i << "]->" << Direccion[i] << endl;
		cin >> dir;
		cout << "Tipo de Ventanas: " << endl;
		for (size_t i = 0; i < Ventanas.size(); i++)
			cout << "\t [" << i << "]->" << Ventanas[i] << endl;
		cin >> vent;
		cout << "Material de la Carroceria: " << endl;
		for (size_t i = 0; i < Carroceria.size(); i++)
			cout << "\t [" << i << "]->" << Carroceria[i] << endl;
		cin >> carr;
		cout << "Bolsas de Aire?\ty/n" << endl;
		cin >> airb;
		bool AirB = (airb == 'y') ? true : false;
		system("pause");
		system("CLS");
		builder->setColor(col);
		builder->setAsientos(nasientos);
		builder->tipoMotor(motorCustomCar);
		builder->tipoNeumaticos(neum);
		builder->tipoAsientos(matseats);
		builder->tipoDireccion(Direccion[0]);
		builder->tipoVentanas(Ventanas[1]);
		builder->tipoCarroceria(Carroceria[0]);
		builder->hasAirBag(AirB);
		p = builder->GetAutomovil();
		p->ListaComp();
		delete p;
		break;
		}
	case 'X':
		break;
	}
	delete builder;
}
int main() {
	Director* director = new Director();
	ClienteCode(*director);
	delete director;
	return 0;
}
