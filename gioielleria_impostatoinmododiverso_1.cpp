#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

void caricamento(int[], string[], string[], float[], int);
void ricerca(int, int[], int, float, float[], int, string[], string[]);
void ricercaMassimoMinimo(float, int, int, int);
void rimuovi(int, int, string, string, int, float);
void vendita(int, int, int, float, float, int, string, string);
bool ricercaXcod(int[], int, int, int, int);

void Ordinamento(string Marca[], string Tipologia[], int codice[], float prezzo[], int dim){
	int i, j;
	float s1;
	string s2;
	for(i=0; i<=dim-2; i++){
		for(j=i+1; j<=dim-1; j++){
			if(prezzo[i]>prezzo[j]){
				s1 = prezzo[i];
				prezzo[i] = prezzo[j];
				prezzo[j] = s1;
				
				s1 = codice[i];
				codice[i] = codice[j];
				codice[j] = s1;
				
				s2 = Marca[i];
				Marca[i] = Marca[j];
				Marca[j] = s2;
				
				s2 = Tipologia[i];
				Tipologia[i] = Tipologia[j];
				Tipologia[j] = s2;
			}
		}
	}
}

int main(){
	int VMax = 50, dim, j;
	cout << "Quanti oggetti sono presenti nella gioielleria?" << endl;
	cin >> dim;
	while(dim<=0 || dim>VMax){
		cout << "Errore. Riprovare." << endl;
		cin >> dim;
	}
	string Marca[dim], Tipologia[dim];
	int Codice[dim];
	float Prezzo[dim];
	caricamento(Codice, Tipologia, Marca, Prezzo, dim);
	cout << "-----------------" << endl;
	for(j=0; j<=dim-1; j++){
		cout << "Codice: " << Codice[j] << " Tipologia: " << Tipologia[j] << " Marca: " << Marca[j] << " Prezzo: " << Prezzo[j] << endl;
	}
	int PosMax, PosMin;
	PosMax=0;
	PosMin=0;
	ricercaMassimoMinimo(Prezzo, dim, PosMax, PosMin);
	cout << "L'oggetto più costoso e' " << Tipologia[PosMax] << " di marca " << Marca[PosMax] << " che costa " << Prezzo[PosMax] << endl;
	cout << "L'oggetto meno costoso e' " << Tipologia[PosMin] << " di marca " << Marca[PosMin] << " che costa " << Prezzo[PosMin] << endl;
	int pos, cerca;
	float cassa;
	bool stop = false;
	string scelta;
	while(stop==false){
		vendita(dim, Codice, pos, cassa, Prezzo, cerca, Tipologia, Marca);
		if(pos!=-1){
			cout << "Venduto!" << endl;
			dim--;
		} else {
			cout << "Non e' stato trovato niente con quel codice!" << endl;
		}
		cout << "Continuare la ricerca?" << endl;
		cin >> scelta;
		if(scelta=="no"){
			stop = true;
		}
		Ordinamento(Marca, Tipologia, Codice, Prezzo, dim);
	}
	for(j=0; j<=dim-1; j++){
		cout << "Codice: " << Codice[j] << " Tipologia: " << Tipologia[j] << " Marca: " << Marca[j] << " Prezzo: " << Prezzo[j] << endl;
	}
}
void caricamento(int codice[], string tipologia[], string marca[], float prezzo[], int dim){
	int i, j;
	srand (time(NULL));
	int pos;
	pos = -1;
	int cassa = 0;
	int nuovoCodice;
	int l;
	bool duplicato = true;
	for(i=0; i<=dim-1; i++){
		codice[i] = rand() % 99 + 1;
		do {
			nuovoCodice = rand() % 99 +1;
			l = i;
			ricercaXcod(codice, dim, nuovoCodice, pos, l);
		} while (pos!=-1);
		cout << i+1 << " -----------------" << endl;
		cout << "Codice: " << codice[i] << endl;
		cout << "Tipologia: ";
		cin >> tipologia[i];
		cout << "\nMarca: ";
		cin >> marca[i];
		cout << "\nPrezzo: ";
		cin >> prezzo[i];
		while(prezzo[i]<=0){
			cout << "Errore. Riprovare."<< endl;
			cin >> prezzo[i];
		}
	}
}

void ricerca(int dim, int codice[], int pos, float cassa, float prezzo[], int cerca, string tipologia[], string marca[]){
	int i;
	for(i=0; i<=dim-1; i++){
		if (cerca==codice[i]){
			pos=i;
		}
	}
	return;
}

void ricercaMassimoMinimo(float prezzo[], int dim, int posmax, int posmin){
	int i;
	int PrezzoMinimo = 9999999, PrezzoMassimo = 0;
	for(i=0; i<=dim-1; i++){
		if(prezzo[i]<PrezzoMinimo){
			PrezzoMinimo = prezzo[i];
			posmin = i;
		}
		if(prezzo[i]>PrezzoMassimo){
			PrezzoMassimo = prezzo[i];
			posmax = i;
		}
	}
	//cout << "L'oggetto più costoso e' " << Tipologia[i2] << " di marca " << Marca[i2] << " che costa " << Prezzo[i2] << endl;
	//cout << "L'oggetto meno costoso e' " << Tipologia[i1] << " di marca " << Marca[i1] << " che costa " << Prezzo[i1] << endl;
	return;
}

void rimuovi(int dim, int codice[], string tipologia[], string marca[], int pos, float prezzo[]){
    for(int i = pos; i < dim - 2; i++){
        codice[i] = codice[i + 1];
        tipologia[i] = tipologia[i + 1];
        marca[i] = marca[i + 1];
        prezzo[i] = prezzo[i + 1];
    }
    return;
}

void vendita(int dim, int codice[], int &pos, float &cassa, float prezzo[], int cerca, string tipologia[], string marca[]){
    cout << "Cosa vuoi vendere?" << endl;
    cin >> cerca;
    pos = -1;
    ricerca(dim, codice, pos, cassa, prezzo, cerca, tipologia, marca);
    if(pos!=-1){
        rimuovi(dim, codice, tipologia, marca, pos, prezzo);
        cassa += prezzo[pos];
    }
    return;
}

