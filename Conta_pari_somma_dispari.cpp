#include<iostream>
using namespace std;
int main(){
	int N,NR,C=0,S=0;
	cout << "Inserire il primo numero: ";
	cin >> N;
	while(N<0){
		cout << "Errore, inserire un numero positivo o uguale a 0." << endl;
		cin >> N;
	}
	while(N!=0){
		NR=N;
	while(NR>0)
		NR-=2;
	if(NR==0){
		C++;
	} else {
		S+=N;
	}
	cout << "Inserire il prossimo numero: ";
	cin >> N;
	while(N<0){
		cout << "Errore." << endl;
		cin >> N;
	}
}
cout << "Sono stati inseriti " <<  C << " volte numeri pari" << endl;
cout << "La somma dei numeri dispari è " << S;
return 0;
}
