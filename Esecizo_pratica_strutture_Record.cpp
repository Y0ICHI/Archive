#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

const int MAX = 100;

struct Data {
	int giorno;
	int mese;
	int anno;
};

struct Persona { //struttura
	string matricola;
	string nome;
	string indirizzo;
	struct Data DataNascita;
	string CodiceFiscale;
	bool coniugato;
};

void InserimentoDipendenti(Persona dipendente[], int dim){
	//inserimento dipendente
	for(int i=0; i<dim; i++){
	cout << i+1 << " Inserisci i valori del dipendente: "<< endl;
	cout << "Matricola: ";
	cin >> dipendente[i].matricola;
	cin.ignore();//pulisce il buffer di input
	cout << endl;
	cout << "Nome: ";
	getline(cin, dipendente[i].nome); // Spazio nelle parole (getline)
	cout << endl;
	cout << "Data di nascita: ";
	cin >> dipendente[i].DataNascita.giorno >> dipendente[i].DataNascita.mese >> dipendente[i].DataNascita.anno;
	cout << endl;
	cout << "Codice fiscale: ";
	cin >> dipendente[i].CodiceFiscale;
	cout << endl;
	cout << "Coniugato (1=si, 0 = no): ";
	cin >> dipendente[i].coniugato;
	cout << endl;
	}
}

void StampaDipendenti(Persona dipendente[], int dim){
	for(int i = 0; i<dim; i++){
		cout << i+1 << " - " << dipendente[i].matricola << " " << dipendente[i].nome << " " << dipendente[i].DataNascita.giorno << " " << dipendente[i].DataNascita.mese << " " << dipendente[i].DataNascita.anno << " " << dipendente[i].CodiceFiscale << " " << dipendente[i].coniugato;
	}
}

int main(){
	Persona dipendente[MAX];
	int dim;
	cout << "Inserire la dimensione." << endl;
	cin >> dim;
	while(dim<=0 || dim > MAX){
		cout << "Errore. Riprovare." << endl;
		cin >> dim;
	}
	InserimentoDipendenti(dipendente, dim);
	StampaDipendenti(dipendente, dim);
}
