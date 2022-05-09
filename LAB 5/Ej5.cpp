#include <iostream>
using namespace std;
// LAB 05 - PUNTEROS
// Implemente su propia función de concatenación de cadenas de texto especial 
// (¡no es la función ordinaria de concatenación!), 
// recibirá como parámetro dos punteros de caracteres y tendrá que asignar el contenido 
// del segundo puntero al INICIO del primer puntero. La función no retorna ningún valor.
void concat(char* a, char* b, int len1, int len2){
	string temp_a, temp_b, res;
	temp_a.append(a,len1);
	temp_b.append(b,len2);
	res=temp_b+temp_a;
	cout<<"Resultado de concatenacion: "<<res;
}
char* create(int l, string p){
	char* arr= new char[l];
	for(int i=0;i<l;i++){
		arr[i]=p[i];
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return arr;
}
int main(int argc, char *argv[]) {
	string a, b;
	cout<<"Ingrese contenido 1: ";
	getline(cin,a);
	int len1=a.length();
	cout<<"Ingrese contenido 2: ";
	getline(cin,b);
	int len2=b.length();
	char* primero=create(len1,a);
	char* segundo=create(len2,b);
	
	concat(primero,segundo,len1,len2);
	
	delete [] primero;
	delete [] segundo;
	primero = NULL;
	segundo = NULL;
	return 0;
}

