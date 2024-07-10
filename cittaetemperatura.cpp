#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

double temperatura1, temperatura2;
int lettura1, lettura2;

void LetturaDati();
void ElaborazioneDati();

int main(void){
	LetturaDati();
	ElaborazioneDati();
	
	system("PAUSE");
	return 0;
}

void LetturaDati(){
	int citta;
	double dato;
	do{
		cout << "Digitare il codice della citta': ";
		cin >> citta;
		if(citta!=0){
			cout << "Inserire la temperatura: ";
			cin >> dato;
			switch (citta){
				case 1:
					temperatura1+=dato;
					lettura1+=1;
					break;
				case 2:
					temperatura2+=dato;
					lettura1+=1;
					break;
			}
		} 
	} while (citta!=0);
}

void ElaborazioneDati(){
	double media1, media2;
	media1=temperatura1/lettura1;
	media2=temperatura2/lettura2;
	cout << "La prima media vale: " << media1 << endl;
	cout << "La seconda media vale: " << media2 << endl;
}

