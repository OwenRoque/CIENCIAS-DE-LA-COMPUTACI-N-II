#include <iostream>
using namespace std;
// LAB 02 - Bucles
// 5. Elabore un programa que lea n n�meros y determine cu�l es el mayor, el menor y la media de los n�meros le�dos.
int main(int argc, char *argv[]) {
	int n, x, max=0, min, media=0;
	cout<<"N� numeros: ";
	cin>>n;
	for (int i=0;i<n;i++){
		cout<<"Numero"<<i+1<<": ";
		cin>>x;
		if (x>max) max=x;
		if (i==0)
			min=x;
		else 
			if (x<min)
				min=x;
		cout<<endl;
		media+=x;
	}
	cout <<"mayor= "<<max<<endl;
	cout <<"menor= "<<min<<endl;
	cout <<"promedio= "<<float(media/n);
	return 0;
}

