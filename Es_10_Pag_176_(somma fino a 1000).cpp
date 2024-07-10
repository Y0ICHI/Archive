#include<iostream>
using namespace std;
int main(){
	float N,N2,C=1;
	cout << "Inserisci il primo numero.\n";
	cin >> N;
	while (N<1000){
		cout << "Inserisci il numero con cui sommare.\n";
		cin >> N2;
		N=N+N2;
		C++;
	}
	cout << "Hai sommato " << C << " volte/a prima di raggiungere il numero 1000!";
	return 0;
}
