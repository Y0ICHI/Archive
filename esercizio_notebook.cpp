#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

int Trovato(string Marca[], string Modello[], int posr){
	int pos=-1, i, j;
	for(i=0; i<=posr-1; i++){
		if((Marca[i]==Marca[posr]) && (Modello[i]==Modello[posr])){
			pos = i;
		}
	}
	return pos;	
}

int Trovato(string Marca[], string Modello[], int posr, string cercaMar, string cercaMod){
	int pos=-1, i, j;
	for(i=0; i<=posr-1; i++){
		if((Marca[i]==cercaMar) && (Modello[i]==cercaMod)){
			pos = i;
		}
	}
	return pos;	
}

void Caricamento(string Marca[], string Modello[], int PD[], float Prezzo[], int pos){
	int i, controllo;
	for(i=0; i<=pos-1; i++){
		do{
			cout << i+1 << " \nMarca: ";
			cin >> Marca[i];
			cout << i+1 << " \nModello: ";
			cin >> Modello[i];
			controllo = Trovato(Marca, Modello, i);
		} while(controllo!=-1);
			cout << i+1 << " \nNumero pezzi disponibili: ";
			cin >> PD[i];
			cout << i+1 << " \nPrezzo: ";
			cin >> Prezzo[i];
	}
	return;
}

int Cerca(string cerca, string Marca[], int j, int dim){ // problemi del codice: se cerca una marca e si trova alla fine o all'inizio del vettore, lo conterà due volte o non trovato
	int pos=-1, i;
	for(i=j+1; i<=dim-1; i++){
		if(cerca==Marca[i]){
			pos=i;
			i=51;
		}
	}
	return pos;
}

int Cerca(string cercaMarca, string Marca[], int j, int dim, string Modello[], string cercaModello){ // problemi del codice: se cerca una marca e si trova alla fine o all'inizio del vettore, lo conterà due volte
	int pos=-1, i;
	for(i=j+1; i<=dim-1; i++){
		if(cercaMarca==Marca[i] && cercaModello==Modello[i]){
			pos=i;
			i=51;
	}
	}
	return pos;
}

bool Maggiore(int num1, int num2){
	bool maggiore = false;
	if(num1>num2){
		maggiore = true;
	}
	return maggiore;
}

void Vendita(float& cassa, float Prezzo[], int i, int NPezzi, int PD[]){
	cassa+= (Prezzo[i] * NPezzi);
			PD[i]-= NPezzi;
}

int Trovato0(int valori[], int dim){
	int i;
	int trovato = -1;
	for(i=0; i<=dim-1; i++){
		if(valori[i]==0){
			trovato = i;
		}
	}
	return trovato;
}

void Rimozione(string Marca[],string Modello[], int NPD[], float Prezzo[], int& dim, int rimozione){
	int i;
	for(i=rimozione; i<=dim-2; i++){
		Marca[i] = Marca[i+1];
		Modello[i] = Modello[i+1];
		NPD[i] = NPD[i+1];
		Prezzo[i] = Prezzo[i+1];
	}
	dim--;
}

void Lista(string Marca[],string Modello[], int NPD[], float Prezzo[], int dim){
	int i;
	for(i=0; i<=dim-1; i++){
		cout << i+1 << " Marca: " << Marca[i] << endl;
		cout << i+1 << " Modello: " << Modello[i] << endl;
		cout << i+1 << " Numero pezzi disponibili: " << NPD[i] << endl;
		cout << i+1 << " Prezzo: " << Prezzo[i] << endl;
	}
}

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

