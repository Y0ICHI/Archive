#include<iostream>
using namespace std;
int main(){
	int B,E,S,C;
	cout << "Inserire il numero." << endl;
	cin >> B;
	cout << "Inserire la potenza" << endl;
	cin >> E;
	if (B>0 && E>0) {
		C = 1;
		S = B;
		while (C<E) {
			S = S*B;
			C= C+1;
		}
		cout << S; } else {
			cout << "Valore non valido :3";
		}
	}
