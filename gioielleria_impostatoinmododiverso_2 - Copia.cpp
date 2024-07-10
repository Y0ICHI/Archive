#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void caricamento(int*, string*, string*, float*, int);
void ricerca(int, int*, int&, float&, float*, int, string*, string*);
void ricercaMassimoMinimo(float*, int, int&, int&);
void rimuovi(int&, int, int*, string*, string*, float*);
void vendita(int&, int*, int&, float&, float*, int, string*, string*);
bool ricercaXcod(int*, int, int, int&, int);

void Ordinamento(string* Marca, string* Tipologia, int* codice, float* prezzo, int dim){
	int i, j;
	float s1;
	string s2;
	int s3;
	for(i=0; i<dim-1; i++){
		for(j=i+1; j<dim; j++){
			if(prezzo[i] > prezzo[j]){
				// Scambia Prezzo
				s1 = prezzo[i];
				prezzo[i] = prezzo[j];
				prezzo[j] = s1;
				
				// Scambia Codice
				s3 = codice[i];
				codice[i] = codice[j];
				codice[j] = s3;
				
				// Scambia Marca
				s2 = Marca[i];
				Marca[i] = Marca[j];
				Marca[j] = s2;
				
				// Scambia Tipologia
				s2 = Tipologia[i];
				Tipologia[i] = Tipologia[j];
				Tipologia[j] = s2;
			}
		}
	}
}

int main() {
	int VMax = 50, dim, j;
	cout << "Quanti oggetti sono presenti nella gioielleria?" << endl;
	cin >> dim;
	while(dim <= 0 || dim > VMax) {
		cout << "Errore. Riprovare." << endl;
		cin >> dim;
	}

	// Allocazione dinamica della memoria
	string* Marca = new string[dim];
	string* Tipologia = new string[dim];
	int* Codice = new int[dim];
	float* Prezzo = new float[dim];
	
	caricamento(Codice, Tipologia, Marca, Prezzo, dim);
	cout << "-----------------" << endl;
	for(j=0; j<dim; j++){
		cout << "Codice: " << Codice[j] << " Tipologia: " << Tipologia[j] << " Marca: " << Marca[j] << " Prezzo: " << Prezzo[j] << endl;
	}
	int PosMax, PosMin;
	PosMax=0;
	PosMin=0;
	ricercaMassimoMinimo(Prezzo, dim, PosMax, PosMin);
	cout << "L'oggetto più costoso e' " << Tipologia[PosMax] << " di marca " << Marca[PosMax] << " che costa " << Prezzo[PosMax] << endl;
	cout << "L'oggetto meno costoso e' " << Tipologia[PosMin] << " di marca " << Marca[PosMin] << " che costa " << Prezzo[PosMin] << endl;
	int pos, cerca;
	float cassa = 0.0;
	bool stop = false;
	string scelta;
	while(!stop){
		vendita(dim, Codice, pos, cassa, Prezzo, cerca, Tipologia, Marca);
		if(pos != -1){
			cout << "Venduto!" << endl;
			dim--;
		} else {
			cout << "Non e' stato trovato niente con quel codice!" << endl;
		}
		cout << "Continuare la ricerca?" << endl;
		cin >> scelta;
		if(scelta == "no"){
			stop = true;
		}
		Ordinamento(Marca, Tipologia, Codice, Prezzo, dim);
	}
	for(j=0; j<dim; j++){
		cout << "Codice: " << Codice[j] << " Tipologia: " << Tipologia[j] << " Marca: " << Marca[j] << " Prezzo: " << Prezzo[j] << endl;
	}
	delete[] Marca;
	delete[] Tipologia;
	delete[] Codice;
	delete[] Prezzo;

	return 0;
}

void caricamento(int* codice, string* tipologia, string* marca, float* prezzo, int dim) {
	srand(time(NULL));
	int pos, nuovoCodice;
	for(int i=0; i<dim; i++){
		do {
			nuovoCodice = rand() % 99 + 1;
		} while (ricercaXcod(codice, i, nuovoCodice, pos, i));
		codice[i] = nuovoCodice;

		cout << i+1 << " -----------------" << endl;
		cout << "Codice: " << codice[i] << endl;
		cout << "Tipologia: ";
		cin >> tipologia[i];
		cout << "Marca: ";
		cin >> marca[i];
		cout << "Prezzo: ";
		cin >> prezzo[i];
		while(prezzo[i] <= 0){
			cout << "Errore. Riprovare." << endl;
			cin >> prezzo[i];
		}
	}
}

void ricerca(int dim, int* codice, int& pos, float& cassa, float* prezzo, int cerca, string* tipologia, string* marca) {
	pos = -1;
	for(int i=0; i<dim; i++){
		if (cerca == codice[i]){
			pos = i;
			break;
		}
	}
}

void ricercaMassimoMinimo(float* prezzo, int dim, int& posmax, int& posmin) {
	posmin = 0;
	posmax = 0;
	for(int i=1; i<dim; i++){
		if(prezzo[i] < prezzo[posmin]){
			posmin = i;
		}
		if(prezzo[i] > prezzo[posmax]){
			posmax = i;
		}
	}
}

void rimuovi(int& dim, int pos, int* codice, string* tipologia, string* marca, float* prezzo) {
	for(int i = pos; i < dim - 1; i++){
		codice[i] = codice[i + 1];
		tipologia[i] = tipologia[i + 1];
		marca[i] = marca[i + 1];
		prezzo[i] = prezzo[i + 1];
	}
}

void vendita(int& dim, int* codice, int& pos, float& cassa, float* prezzo, int cerca, string* tipologia, string* marca) {
	cout << "Cosa vuoi vendere? Inserisci il codice: ";
	cin >> cerca;
	pos = -1;
	ricerca(dim, codice, pos, cassa, prezzo, cerca, tipologia, marca);
	if(pos != -1){
		cassa += prezzo[pos];
		rimuovi(dim, pos, codice, tipologia, marca, prezzo);
	}
}

bool ricercaXcod(int* codice, int dim, int cerca, int& pos, int n) {
	for(int i = 0; i < n; i++){
		if(codice[i] == cerca){
			pos = i;
			return true;
		}
	}
	pos = -1;
	return false;
}
