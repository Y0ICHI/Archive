#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;
// prototipi delle funzioni
short LeggiDimensione(int);
void Carica(string [], string [], int [], float [], short);
bool Ricerca(int [], short, int, short &);
float Vendita(string [], string [], int [], float [], short &);
void Rimuovi(string [], string [], int [], float [], short &, short);
void RicercaInterv(float [], short, float, float, short [], short &);
void Visualizza(string [], string [], int [], float [], short);
void RicercaMaxMin(float [], int&, int&, int);

int main(){
	const int MAX_DIM = 50;
	short dim, i;
	dim = LeggiDimensione(MAX_DIM);
	string Tipol[dim], Marca[dim];
	int Codice[dim];
	float Prezzo[dim], incassoVendita;
	Carica(Tipol, Marca, Codice, Prezzo, dim);
	int PosMax, PosMin;
	RicercaMaxMin(Prezzo, PosMax, PosMin, dim);
	
	// Punto 3
	short VetPos[dim];
	short dim2;
	int sogliaPrz1, sogliaPrz2;
	do{
		cout << "Inserisci la prima soglia di prezzo: ";
		cin >> sogliaPrz1;
		cout << "Inserisci la seconda soglia di prezzo: ";
		cin >> sogliaPrz2;
	}while(sogliaPrz1>sogliaPrz2);
	RicercaInterv(Prezzo, dim, sogliaPrz1, sogliaPrz2, VetPos, dim2);
	if (dim2 == 0)
		cout << "Non ho trovato oggetti in quella fascia di prezzo!" << endl;
	else{
		cout <<"Gli oggetti aventi prezzo compreso nella fascia "
		     << sogliaPrz1 << " - " << sogliaPrz2 << " sono: \n";
		for(i=0; i<dim2; i++)
			cout << Codice[i] << "   " << Tipol[i];
			cout << "   " << Marca[i] << "   " << Prezzo[i] << endl;
	}
			
	incassoVendita = Vendita(Tipol, Marca, Codice, Prezzo, dim);
	cout << "L'incasso della vendita degli oggetti è:   " << incassoVendita;
	// si visualizzano gli oggetti invenduti
	Visualizza(Tipol, Marca, Codice, Prezzo, dim);
	
	return 0;
}

short LeggiDimensione(int maxdim){
	short dimensione;
	
	cout << "Inserisci il numero di elementi:   ";
	cin >> dimensione;
	while((dimensione <=0)||(dimensione>maxdim)){
		cout << "Attenzione!! Il numero degli elementi non è corretto. Reinserisci il numero";
		cout << "Inserisci il numero di elementi:   ";
		cin >> dimensione;
	}	
	return dimensione;
}

void Carica(string A[], string B[], int C[], float D[], short n) {
    short i, pos;
    int newCod;

    for (i = 0; i <= n - 1; i++) {
        cout << "Inserisci la tipologia dell'oggetto di posto " << i << ":   ";
        cin >> A[i];
        cout << "Inserisci la marca dell'oggetto di posto " << i << ":   ";
        cin >> B[i];
        newCod = rand() % 100;
		while (Ricerca(C, i, newCod, pos)==true){
        	//cout << "Attenzione codice già utilizzato";
        	newCod = rand() % 100;
		}
        C[i] = newCod;
        
        cout << "Inserisci il prezzo dell'oggetto di posto " << i << ":   ";
        cin >> D[i];
        while (D[i] < 0) {
            cout << "Attenzione!! Il prezzo non può essere negativo" << endl;
            cout << "Inserisci il prezzo dell'oggetto di posto " << i << ":   ";
            cin >> D[i];
        }
    }
    return;
}

bool Ricerca(int A[], short n, int cercato, short &pos){
	short i=0;
	bool esito = false;	
	pos = -1;
	while ((i<n)&&(!esito))
		if (cercato==A[i]){
			esito=true;
			pos=i;
		}
		else
			i++;
		
	return esito;	
}

float Vendita(string A[], string B[], int C[], float D[], short &n){
	char risposta;
	short i, posVenduto;
	int codVenduto;
	bool trovato;
	float incasso = 0;
	
	cout << "Vuoi vendere un oggetto? (S/N)  ";
	cin >> risposta;
	
	while (toupper(risposta) =='S'){
		cout << "Inserisci il codice dell'oggetto da vendere:   ";
		cin >>codVenduto;
		trovato = Ricerca(C, n, codVenduto, posVenduto);
		if (!trovato){
			cout << "Attenzione!! L'oggetto non è presente nell'elenco. \n";
		}
		else{
			incasso = incasso + D[posVenduto];
			//si rimuove dall'elenco l'oggetto venduto
			Rimuovi(A, B, C, D, n, posVenduto);
		}
		cout << "Vuoi vendere ancora oggetti? (S/N)  ";
		cin >> risposta;		
	}		
	return incasso;	
}

void Rimuovi(string A[], string B[], int C[], float D[], short &n, short pos){
	short i;
	for(i=pos; i<n; i++){
		A[i] = A[i+1];
		B[i] = B[i+1];
		C[i] = C[i+1];
		D[i] = D[i+1];
	}
	n--;
	return;
}

void RicercaInterv(float A[], short n, float p1, float p2, short Pos[], short &n2){
	short i;
	n2=0;
	for(i=0; i<n; i++)
		if ((A[i]>=p1)&&(A[i]<=p2)){
			Pos[n2] = i;
			n2++;
		}	
	return;	
}

void Visualizza(string A[], string B[], int C[], float D[], short n){
	short i;
	cout << "Gli elementi in elenco sono: \n";
	for (i=0;i<n;i++){
		cout << A[i] << " - " << B[i] << " - "
		     << C[i] << " - " << D[i] << "\n";
	}
	return;	
}

void RicercaMaxMin(Prezzo[], PosMax, PosMin, dim){
		short j;
		int PrezzoMax = 0, PrezzoMin = 99999;
		for (j=0; j<=dim-1; j++){
			if(PrezzoMax<Prezzo[j]){
				PrezzoMax = Prezzo[j];
				PosMax = j;
			}
			if(PrezzoMin>Prezzo[j]){
				PrezzoMin = Prezzo[j];
				PosMin = j;
			}
		}
		return;
	}
