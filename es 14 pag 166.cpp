#include <iostream>
#include <bits/c++config.h>
using namespace std;
int main(){
	int MAX, N, N2=0;
	cout << "Inserisci il numero massimo: ";
	cin >> MAX;
	do{
		cout << "inserire il numero con cui sommare." << endl;
		cin >> N;
		N2+=N;
	} while (N2<=MAX);
	N2-=MAX;
	cout << "Il numero massimo che hai inserito e' " << MAX << " e la somma supera il numero di " << N2 << " cifre";
}
