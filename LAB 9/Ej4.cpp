#include <iostream>
using namespace std;

template <typename S>
S minValue(S arr[5]){
	S min = arr[0];
	for(int i=0;i<5;i++){
		if (arr[i]<min)
			min=arr[i];
	}
	return min;
}
template <typename S>
S maxValue(S arr[5]){
	S max = arr[0];
	for(int i=0;i<5;i++){
		if (arr[i]>max)
			max=arr[i];
	}
	return max;
}

int main(int argc, char *argv[]) {
	int ArrayEntero [5] = {10,7,2, 8, 6};
	float ArrayFloat [5] = {12.1, 8.7, 5.6, 8.4, 1.2};
	cout<<"Max ArrayEntero: "<<maxValue(ArrayEntero)<<endl;
	cout<<"Min ArrayEntero: "<<minValue(ArrayEntero)<<endl;
	cout<<"Max ArrayFloat: "<<maxValue(ArrayFloat)<<endl;
	cout<<"Min ArrayFloat: "<<minValue(ArrayFloat)<<endl;
	return 0;
}

