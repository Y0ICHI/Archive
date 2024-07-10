#include<iostream>
using namespace std;
int main (){
	float N;
	cout << "Dammi il numero da cui fare il conto alla rovescia, deve essere minore di 20 il numero inserito." << endl;
	cin >> N;
	while (N<0 or N>19){
		cout << "Numero inserito non valido, riprovare." << endl;
		cin >> N;
	}
	cout << "Il conto alla rovescia e' iniziato!" << endl;
	while (N>0){
		N--;
		cout << N << endl;
	}
}
