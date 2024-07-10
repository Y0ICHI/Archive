#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

const int MAXCAM = 20;
const int piani = 2;
const float doppia = 110;
const float tripla = 135;
const float matrimoniale = 120;

typedef struct{
	int num;
	int nBam;
	float Prezzo;
	char tipoC;
	bool prenotato;
} camera;

typedef struct{
	int nome;
	camera Cam[MAXCAM];
	short nCam;
} piano;

void Visualizzazione(piano Pian[]){
	for(int j = 0; j<piani; j++){
		cout << "-------------" << endl;
		cout << "Piano numero " << j+1 << endl;
		for(int i = 0; i<Pian[j].nCam; i++){
			cout << "Stanza numero: " << i+1 << endl;
			cout << "Prenotata: " << Pian[j].Cam[i].prenotato << endl;
			if(Pian[j].Cam[i].prenotato){
				cout << "Numero persone: " << Pian[j].Cam[i].num << endl;
				if(Pian[j].Cam[i].nBam!=0){
					cout << "Numero bambini: " << Pian[j].Cam[i].nBam << endl;
				}
				cout << "Tipo di stanza prenotata: " << Pian[j].Cam[i].tipoC << endl;
			}
		}
	}
}

void VisualizzazionePiano(piano Pian[], int Cerca){
	int conta = 0;
	for(int j = Cerca; j<Cerca+1; j++){
		for(int i = 0; i<Pian[j].nCam; i++){
			if(Pian[j].Cam[i].tipoC == 'Q'){
				conta++;
			}
		}
	}
	cout << "Ci sono " << conta << " stanze disponibili quadruple." << endl;
}

void Disponibili(piano Pian[]){
	int conta = 0;
	for(int j = 0; j<piani; j++){
		for(int i = 0; i<Pian[j].nCam; i++){
			if(!Pian[j].Cam[i].prenotato){
				conta++;
			}
		}
	}
	cout << "Ci sono " << conta << " stanze disponibili." << endl;
}

int main(){
	int dim;
	char scelta;
	piano Pian[piani];
	for(int j=0; j<piani; j++){
		cout << "Inserire il numero di piani per il " << j+1 << " piano." << endl;
		cin >> dim;
		Pian[j].nCam = dim;
		for(int i=0; i<dim; i++){
			cout << i+1 << " - Inserimento dati della stanza." << endl;
			cout << i+1 << " - \212 prenotata? Y/N" << endl;
			cin >> scelta;
			if(scelta=='Y'){
				Pian[j].Cam[i].prenotato = true;
				cout << i+1 << " - Inserire il numero di persone." << endl;
			cin >> Pian[j].Cam[i].num;
			cout << i+1 << " - Ci sono bambini? Y/N" << endl;
			cin >> scelta;
			if(scelta=='Y'){
				cout << i+1 << " -  Inserire il numero di bambini." << endl;
				cin >> Pian[j].Cam[i].nBam;
			} else {
				Pian[j].Cam[i].nBam = 0;
			}
			cout << i+1 << " - Inserire il tipo di stanza da prendere. (D = Doppia, T = Tripla, Q = Quadrupla)" << endl;
			cin >> Pian[j].Cam[i].tipoC;
			} else {
				Pian[j].Cam[i].prenotato = false;
				Pian[j].Cam[i].num = 0;
				Pian[j].Cam[i].nBam = 0;
				Pian[j].Cam[i].tipoC = 'N'; //N = null;
			}
	}
}
	//Visualizzazione(Pian);
	int SceltaN;
	cout << "Inserire il piano in cui ti interessa vedere le stanze Quadruple disponibili. " << endl;
	cin >> SceltaN;
	SceltaN=-1;
	VisualizzazionePiano(Pian, SceltaN);
	Disponibili(Pian);
}
