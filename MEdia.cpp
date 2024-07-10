#include<iostream>
using namespace std;
int main(){
int C,N2;
float S,N,M;
cout << "Quanti sono i numeri per cui vuoi fare la media?" << endl;
cin >> N2;
do {
		cout << "Inserisci il numero con cui vuoi fare la media." << endl;
		cin >> N;
		S=S+N;
		C=C+1;
	} while (N2>C);
		M=S/N2;
		cout << "La media e' " << M;
		return 0;
}
