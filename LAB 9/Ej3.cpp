#include <iostream>
using namespace std;
template <class N, class A>
class Email{
	N nomb;
	A ap;
public:
	Email(N _nomb, A _ap){
		nomb = _nomb;
		ap = _ap;
	}
	A output(){
		A res = nomb + ap + "@unsa.edu.pe";
		return res;
	}
};

int main(int argc, char *argv[]) {
	Email<char,string> nombre1('o',"roque");
	Email<char,string> nombre2('y',"ramos");
	cout<<"Resultado nombre1: "<<nombre1.output();
	cout<<endl;
	cout<<"Resultado nombre2: "<<nombre2.output();
	return 0;
}

