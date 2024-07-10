#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
    int LMax, Libri = 50; // Libri = Libri massimi che può contenere la libreria
     cout << "Quanti libri devi mettere? ";
    cin >> LMax;
    while(LMax < 1 || LMax > Libri){
    	if(LMax > Libri){
    		cout << "Il numero di libri che hai inserito non puo' essere maggiore di " << Libri << "!" << endl;
		} else {
			cout << "Il numero che hai inserito non puo' essere minore di 1!" << endl;
		}
		cin >> LMax;
	}
	
    int CL[LMax], NCD[LMax];     // CL = Codice libro; NCD = Numero copie disponibili
    string Tit[LMax], Aut[LMax]; // Tit = Titolo; Aut = Autore
    int i, pos = 0, j, l = 0;    // i, j, l = per le ripetizioni;
    bool trovatoaut = false, stop = false, unacopia = false;
    string cercaut, scelta;
    
    for (i = 0; i < LMax; i++) {
        cout << i + 1 << " Codice libro: ";
        cin >> CL[i];
        cout << i + 1 << " Titolo: ";
        cin >> Tit[i];
        cout << i + 1 << " Autore: ";
        cin >> Aut[i];
        cout << i + 1 << " Numero copie disponibili: ";
        cin >> NCD[i];
        cout << "----------------------------------" << endl;
    }

    cout << "Ricapitoliamo i libri che hai inserito nella libreria, inclusi possibili copie mancanti: " << endl;

    for (i = 0; i < LMax; i++) {
        cout << "Codice libro: " << CL[i] << " Titolo: " << Tit[i] << " Autore: " << Aut[i] << " Numero copie disponibili: " << NCD[i] << endl;
    }

    while (stop == false) {
        cout << "Inserire il nome dell'autore da cercare: ";
        cin >> cercaut;

        for (i = 0; i < LMax; i++) {
            if (Aut[i] == cercaut) {
                trovatoaut = true;
                stop = true;
            }
        }

        if (trovatoaut == true) {
            cout << "Autore trovato!\n Ecco i libri trovati: " << endl;

            for (i = 0; i < LMax; i++) {
                if (Aut[i] == cercaut) {
                    cout << "Titolo libro:" << Tit[i] << " con " << NCD[i] << " copie disponibili." << endl;
                }
            }
        } else {
            cout << "Autore non trovato!\n Finire la ricerca?" << endl;
            cin >> scelta;

            while (scelta != "si" && scelta != "no") {
                cout << "Errore. Riprova." << endl;
                cin >> scelta;
            }

            if (scelta == "si") {
                stop = true;
            }
        }
    }

    for (i = 0; i < LMax; i++) {
        if (NCD[i] == 1) {
            unacopia = true;
        }
    }

    if (unacopia == true) {
        cout << "Tutti i libri che hanno solo una copia rimanente: " << endl;

        for (i = 0; i < LMax; i++) {
            if (NCD[i] == 1) {
                cout << "Titolo: " << Tit[i] << " Autore: " << Aut[i] << endl;
            }
        }
    }
	for(i=0; i<=LMax-1; i++){
		if(NCD[i]==0){
			l=l+1;
		}
	}
	if(l!=0){
		cout << "Sono stati trovati " << l << " libri con 0 copie!" << endl;
		for(i=0; i<=LMax-1; i++){
			if(NCD[i]==0){
				cout << i + 1 << " Codice libro: ";
        		cin >> CL[i];
        		cout << i + 1 << " Titolo: ";
        		cin >> Tit[i];
        		cout << i + 1 << " Autore: ";
        		cin >> Aut[i];
        		cout << i + 1 << " Numero copie disponibili: ";
        		cin >> NCD[i];
        		if(l>1){
				cout << "----------------------------------" << endl;
				l--;
			}
			}
		}
	}
    return 0;
}
