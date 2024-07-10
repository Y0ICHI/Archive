#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "./header_libraries/TestLibreria.h"
using namespace std;

int main(){
	int MAXDIM =50, dim, m, trovato, nt, ntot, npt;
	cout << "Inserire la dimensione" << endl;
	cin >> dim;
	while(dim<=0 || dim>MAXDIM){
		cout << "Errore" << endl;
		cin >> dim;
	}
	string Marca[dim], Modello[dim];
	int PD[dim];
	float Prezzo[dim];
	string cerca;
	Caricamento(Marca, Modello, PD, Prezzo, dim);
	Lista(Marca, Modello, PD, Prezzo, dim);
	cout << "Che marca di notebook vuoi cercare?" << endl;
	cin >> cerca;
	nt = 0;
	ntot = 0;
	npt = 0;
	for(m=0; m<=dim-2; m++){
		trovato = Cerca(cerca, Marca, m, dim); // errore, non funzionante
		if (trovato!=-1){
			nt++;
			ntot+=Prezzo[trovato];
			npt+=PD[trovato];
		}
	}
	if(nt!=0){
		cout << "Sono stati trovati " << nt << " di notebook con un valore totale di " << ntot << " con " << npt << " pezzi trovati!" << endl;
	} else {
		cout << "Nessun notebook trovato!" << endl;
	}
	string cMar, cMod;
	cout << "marca" << endl;
	cin >> cMar;
	cout << "Modello" << endl;
	cin >> cMod;
	trovato=-1;
	m = 0;
	while((m<=dim-1) && (trovato==-1)){
		trovato = Trovato(Marca, Modello, dim, cMar, cMod);
		if(trovato!=-1){
			cout << "Trovato!\n Il numero di pezzi disponibili \212 " << PD[trovato] << " mentre il valore \212 di " << Prezzo[trovato] << endl; 
		}
		m++;
	}
	if(trovato==-1)
	cout << "Non trovato!" << endl;
	string cMarca, cModello;
	cout << "Inserire la marca del notebook che vuoi acquistare: ";
	cin >> cMarca;
	cout << "Inserire il modello del notebook che vuoi acquistare: ";
	cin >> cModello;
	int start = 0;
	int vendita;
	float cassa;
	string scelta;
	trovato = Cerca(cMarca, Marca, start, dim, Modello, cModello);
	if(trovato!=-1){
		cout << "Notebook trovato! Ci sono un totale di " << PD[trovato] << " pezzi disponibili" << endl;
		cout << "Quanti notebook vuoi acquistare?" <<endl;
		cin >> vendita;
		if(Maggiore(PD[trovato], vendita)==false){
			cout << "\212 oltre il numero di pezzi disponibili! Vuoi acquistare tutti i pezzi disponibili?" << endl;
			cin >> scelta;
			if(scelta=="si"){
				vendita = PD[trovato];
				Vendita(cassa, Prezzo, trovato, vendita, PD);
			}
		} else {
			Vendita(cassa, Prezzo, trovato, vendita, PD);
			cout << "Comprati!" << endl;
			//cout << "Debug pezzi disponibili: " << PD[trovato] << endl;
			//cout << "Debug cassa: " << cassa << endl;
		}
	} else {
		cout << "Notebook non trovato!" << endl;
	}
	trovato = Trovato0(PD, dim);
	if(trovato!=-1){
		cout << "Trovato 0 copie nella posizione " << trovato << endl;
		Rimozione(Marca,Modello,PD, Prezzo, dim, trovato);
	}
	Lista(Marca, Modello, PD, Prezzo, dim);
	return 0;
}
