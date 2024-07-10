#include<iostream>
using namespace std;
int main(){
	float N1,N2,N3,C;
	C=1;
	cout << "Inserire il primo numero.\n";
	cin >> N1;
	cout << "Inserire il numero con cui volere moltiplicare.\n";
	cin >> N2;
	while(N1<0 or N2<0){
		cout << "Uno dei valori inseriti non e' valido, riprovare inserendo numeri solo positivi.\n Inserisci di nuovo il primo numero: ";
		cin >> N1;
		cout << "Inserire il secondo numero." << endl;
		cin >> N2;
	}
	N3 = N1;
	while(C<N2){
		C=C+1;
		N1=N1+N3;
	}
	cout << N1;
}

