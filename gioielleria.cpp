#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main(){
	srand(time(NULL));
	int Max = 50, oggetti, i, MaxP, MinP, posmax, posmin ,trovato=0, somma=0, minf, maxf, cercaCD;
	bool stop = false;
	string cerca, scelta;
	cout << "Numero di oggetti: ";
	cin >> oggetti;
	while(oggetti<1 || oggetti >Max){
		cout << "Errore. Riprovare." << endl;
		cin >> oggetti;
	}
	int CD[oggetti];
	double PREZ[oggetti],;
	string TI[oggetti], MAR[oggetti];
	 for(i=0; i<=oggetti-1; i++){
	 	CD[i] = rand() % 99+1;
	 }
}
