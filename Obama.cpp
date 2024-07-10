#include<iostream>
using namespace std;
int main(){
	int N, X, C;
	cout << "Dammi il numero" << endl;
	cin >> N;
	cout << "Dammi il numero che devo sotrarre" << endl;
	cin >> X;
	while (X>N){
		cout << "Il numero da sotrarre non e' valido, inserirne uno valido." << endl;
		cin >> X;
	}
	C = 0;
	while (N>=0){
		N = N-X;
		C = C+1;
		cout << N << endl;
	}
	cout << "Il numero di volte che devi sotrarre è " << C << " volte.";
	return 0;
}
