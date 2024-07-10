#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

void Scambio(int numeri[]){
	int i, s;
	for(i=0; i<=2; i++){
		if(numeri[0]>numeri[1]){
			s = numeri[0];
			numeri[0] = numeri[1];
			numeri[1] = s;
		}
		if(numeri[1]>numeri[2]){
			s = numeri[1];
			numeri[1] = numeri[2];
			numeri[2] = s;
		}
	}
}



int main(){
	int numeri[3], j;
	for(j=0; j<=2; j++){
	cout << "Inserire i numeri." << endl;
	cin >> numeri[j];
	cout << endl;
	}
	Scambio(numeri);
	cout << "Numeri ordinati. (crescente)" << endl;
	for(j=0; j<=2; j++){
		cout << numeri[j] << endl;
	}
}
