/* scrivi un programma che legga da tastiera i dati di quattro prodotti, in particolare il codice, il prezzo e lo sconto, 
e visualizzi sullo schermo il prezzo scontato di ciascuno di essi. successivamente si indichi sullo schermo il piu costoso,
il totale degli sconti effettuati, la media dei prezzi e la media degli sconti ipotizzando di aver venduto cento unita
di un prodotto*/
#include <iostream>
using namespace std;
int main(){
    int conta;
    conta=0;
    float codice, prezzo, sconto, prezzosconto1, prezzosconto2 =0, mediascont, maxcod, Nscont=0, maxsconto=0, mediaprezzi=0;;
    while (conta<4){
        cout << "dammi il codice: ";
        cin >> codice;   
            while (codice <=0){
                cout << endl << "dammi il codice del prodotto: ";
                cin >> codice;   
            }
        cout << endl << "dammi il prezzo del prodotto: ";
        cin >> prezzo;
            while (prezzo <=0){
                cout << endl << "dammi il prezzo del prodotto: ";
                cin >> prezzo;   
            }
        cout << endl << "dammi lo sconto del prodotto: ";
        cin >> sconto;
            while (sconto <0){
                cout << endl << "dammi lo sconto del prodotto: ";
                cin >> sconto;   
            }
        if (sconto>0){
            mediascont+=sconto;
        	sconto=sconto/100;
        	prezzosconto1=prezzo-prezzo*sconto;
        	mediaprezzi+=prezzosconto1;
        Nscont++;
		}
		if (prezzosconto1>maxsconto){
			maxsconto=sconto;
			maxcod=codice;
		}
		conta++;
}
mediascont/=Nscont;
mediaprezzi/=conta;
cout << "Maxprodotto " << maxcod << endl;
cout << "sconti effettuati " << Nscont << endl;
cout << "media prezzi " << mediaprezzi << endl;
cout << "media scont " << mediascont << endl; 
}