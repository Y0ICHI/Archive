#include<iostream>
using namespace std;
// Incremento di numeri

float Incremento(int numero, float percentuale){
	float Incrementi;
	
	Incrementi = numero+(numero*percentuale/100);
	
	return Incrementi;
}

int main(){
	int num;
	float perc, NumIncrem;
	cout << "Inserire un numero intero: ";
	cin >> num;
	cout << "Di che percentuale lo vuoi incrementare? ";
	cin >> perc;
	NumIncrem = Incremento(num, perc);
	cout << "Il numero " << num << "è incrementato del " << perc << "%, \212 " << NumIncrem;
}
