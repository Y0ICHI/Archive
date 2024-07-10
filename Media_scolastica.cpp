#include<iostream>
using namespace std;
int main(){
	float N,N2,M;
	int C=0;
	cout << "Scrivi i numeri con cui fare la media.\n Per fermare la media scrivi 0" << endl;
	cin >> N;
	while(N<=0 or N>10){
		if(N<0){
			cout << "Errore, inserire almeno un numero superiore a 0." << endl;
			cin >> N;
		} else {
			if(N==0){
				cout << "Errore, il primo numero inserito non puo' fermarsi senza avere inserito almeno un numero valido." << endl;
				cin >> N;
			} else {
				cout << "Errore, il numero inserito e' maggiore di 10, inserire un numero valido." << endl;
				cin >> N;
			}
		}
	}
	N2=N;
	while(N!=0){
		C++;
		cin >> N;
		while(N<0 or N>10){
			cout << "Errore, il numero inserito non puo' essere minore di 0 oppure maggiore di 10." << endl;
			cin >> N;
		}
		N2=N+N2;
	}
	M=N2/C;
	cout << "La media dei voti inseriti e': " << M << endl;
	return 0;
}


