#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

void riempiManuale(){
	int x,y;
	int valore;
	for(x=0; x < GIORNI; x++)
		for(y=0; y<ORE; y++){
			cout << "Inserisci la tempreratura: ";
			cin >> valore;
			miaMat[x][y];
	}
}	

void calcolaMassimo(){
	int x,y;
	tempMAX = 0;
	oraMAX = 0;
	giornoMAX = 0;
	for(y = 0; y<ORE; y++){
		for(x = 0; x< GIORNI; x++){
			if(miaMat[x][y]>tempMAX){
				tempMAX = miaMat[x][y];
				oraMAX = y;
				giornoMAX = x;
			}
		}
	}
	cout<<"\nTemperatura massima: " << tempMAX;
	cout << "\nFascia oraria	: ";
	decodFascia(oraMAX);	
}

void calcolaMedia(){
	int x,y, media;
	for(y=0; y < ORE; y++){
		media = 0;
		for(x=0; x < GIORNI; x++){
			media+=miaMat[x][y];
		}
		medie[y] = media / GIORNI;
	}
}

int main(){
	riempiManuale(); //
	mostraMatrice(); 
	calcolaMassimo(); //
	calcolaMedia(); //
	mostraVettore(); 
	system("pause");
}
