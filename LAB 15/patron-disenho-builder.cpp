#include "iostream"
#include "vector"
using namespace std;
class Producto1 {
public:
	std::vector<std::string> componentes;
	void ListaComp() const {
		std::cout << "Componentes : ";
		for (size_t i = 0; i < componentes.size(); i++) {
			if (componentes[i] == componentes.back()) {
				std::cout << componentes[i];
			}
			else {
				std::cout << componentes[i] << ", ";
			}
		}
		std::cout << "\n\n";
	}
};
/* La interfaz de Builder especifica métodos para crear las diferentes partes
de los objetos Product. */
class IBuilder {
public:
	virtual ~IBuilder() {}
	virtual void ProducirParteA() const = 0;
	virtual void ProducirParteB() const = 0;
	virtual void ProducirParteC() const = 0;
};
/* Las clases de BuilderEspecifico siguen la interfaz de Builder y proporcionan
implementaciones específicas de los pasos de construcción. El programa puede
tener varias variaciones de Builders, implementadas de manera diferente. */
class BuilderEspecifico : public IBuilder {
private:
	Producto1* product;
public:
	BuilderEspecifico() {
		this->Reset();
	}
	~BuilderEspecifico() {
		delete product;
	}
	void Reset() {
		this->product = new Producto1();
	}
	void ProducirParteA()const override {
		this->product->componentes.push_back("ParteA1");
	}
	void ProducirParteB()const override {
		this->product->componentes.push_back("ParteB1");
	}
	void ProducirParteC()const override {
		this->product->componentes.push_back("ParteC1");
	}
	Producto1* GetProducto() {
		Producto1* resultado = this->product;
		this->Reset();
		return resultado;
	}
};
/*El Director solo es responsable de ejecutar los pasos de construcción en una
secuencia particular. Es útil cuando se fabrican productos de acuerdo con un
pedido o configuración específicos. Estrictamente hablando, la clase Director
es opcional, ya que el cliente puede controlar directamente a los
constructores.*/
class Director {
private:
	IBuilder* builder;
public:
	void set_builder(IBuilder* builder) {
		this->builder = builder;
	}
	void BuildProductoMin() {
		this->builder->ProducirParteA();
	}
	void BuildProductoCompleto() {
		this->builder->ProducirParteA();
		this->builder->ProducirParteB();
		this->builder->ProducirParteC();
	}
};
/* El código del cliente crea un objeto constructor, se lo pasa al director y
luego inicia el proceso de construcción. El resultado final se recupera del
objeto constructor. */
void ClienteCode(Director& director)
{
	BuilderEspecifico* builder = new BuilderEspecifico();
	director.set_builder(builder);
	std::cout << "Producto Basico:\n";
	director.BuildProductoMin();
	Producto1* p = builder->GetProducto();
	p->ListaComp();
	delete p;
	std::cout << "Producto Completo:\n";
	director.BuildProductoCompleto();
	p = builder->GetProducto();
	p->ListaComp();
	delete p;
	std::cout << "Producto basico:\n";
	builder->ProducirParteA();
	builder->ProducirParteC();
	p = builder->GetProducto();
	p->ListaComp();
	delete p;
	delete builder;
}
int main() {
	Director* director = new Director();
	ClienteCode(*director);
	delete director;
	return 0;
}
