#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

const int MAX_DIM = 100;

typedef struct{
	string Marca;
	string Modello;
	int Anno;
	char Tipologia;
	float Prezzo;
	int Codice;
} informazioni;

//Controlla univocità del codice
bool Unico(informazioni Orologio[], int Oggetto, short dim){
	bool Univocita = true;
	for(int i = 0; i<dim and Univocita==true; i++){
		if(Oggetto== Orologio[i].Codice){
			Univocita = false;
			//cout << "Pos: " << i << endl;
		} 
	}
	return Univocita;
}

//Caricamento
void Caricamento(informazioni Orologio[], short dim){
	for(int i = 0; i<dim; i++){
		cout << i+1 << " - Inserire la marca dell'orologio." << endl;
		cin >> Orologio[i].Marca;
		cout << i+1 << " - Inserire il modello dell'orologio." << endl;
		cin >> Orologio[i].Modello;
		cout << i+1 << " - Inserire l'anno di creazione dell'orologio." << endl;
		cin >> Orologio[i].Anno;
		cout << i+1 << " - Inserire la tipologia dell'orologio (Q = al quarzo, A = Automatico, C = Carica manuale)." << endl;
		cin >> Orologio[i].Tipologia;
		while(Orologio[i].Tipologia!= 'Q' and Orologio[i].Tipologia!= 'A' and Orologio[i].Tipologia!= 'C'){
			cout << i+1 << " - Errore, riprovare." << endl;
			cin >> Orologio[i].Tipologia;
		}
		cout << i+1 << " - Inserire il prezzo dell'orologio." << endl;
		cin >> Orologio[i].Prezzo;
		while(Orologio[i].Prezzo<=0){
			cout << i+1 << " - Errore, riprovare." << endl;
			cin >> Orologio[i].Prezzo;
		}
		cout << i+1 << " - Inserire il codice orologio." << endl;
		cin >> Orologio[i].Codice;
		while(Unico(Orologio, Orologio[i].Codice, i)==false){
			cout << i+1 << " - Nope." << endl;
			cin >> Orologio[i].Codice;
		}
	}
}

//Trova il più vecchio, restituendo la posizione in cui l'ha trovato.
int Vecchio(informazioni Orologio[], short dim){
	bool vecchio = false;
	int older = 0;
	for(int i = 0; i<dim; i++){
		if(Orologio[i].Anno < Orologio[older].Anno){
			older = i;
		}
	}
	return older;
}

//Visualizzazione
void Visualizzazione(informazioni Orologio[], short dim){
	for(int i = 0; i<dim; i++){
	cout << i+1 << " - Marca: "<< Orologio[i].Marca << "\nModello: " << Orologio[i].Modello << "\nAnno: "<< Orologio[i].Anno << "\nTipologia: " << Orologio[i].Tipologia << "\nPrezzo: "<<Orologio[i].Prezzo << "\nCodice: " << Orologio[i].Codice;
	cout << endl << "---------------" << endl;
}
}

//Ordinamento di tipo bubblesort
void BubbleSort(informazioni Orologio[], short dim){
	bool scambi = true;
	int i, k, ultimo = dim-1;
	informazioni Temp;
	k = ultimo;
	while(scambi==true){
		scambi = false;
		k = ultimo;
		for(i=0; i<k; i++){
			if(Orologio[i].Prezzo>Orologio[i+1].Prezzo){
			scambi = true;
			ultimo = i;
			
			Temp = Orologio[i];
			Orologio[i] = Orologio[i+1];
			Orologio[i+1] = Temp;
		}
		}
	}
}

//Ricerca di una marca e visualizzazione
void CercaMarca(informazioni Orologio[], string Cercato, short dim){
	int i,j=0;
	for(i=0; i<dim; i++){
		if(Cercato == Orologio[i].Marca){
			j++;
		}
	}
	if(j!=0){
	cout << "Ci sono " << j << " orologi/o di questa marca." << endl;
} else {
	cout << "Non ci sono orologi della marca selezionata!" << endl;
}
}

//Chiede all'utente la fascia di prezzo in cui vuole cercare un orologio che si trovi in quella fascia, per poi visualizzarlo.
void VisualizzazioneFasciaPrezzo(informazioni Orologio[], short dim){
	int min, max, j=0;
	cout << "Inserire la soglia di prezzo che ti interessa. (min)" << endl;
	cin >> min;
	cout << "Inserire la soglia di prezzo che ti interessa. (max)" << endl;
	cin >> max;
	for(int i=0; i<dim; i++){
		if(Orologio[i].Prezzo>=min and Orologio[i].Prezzo<=max){
			cout << j++ << " - Marca: "<< Orologio[i].Marca << "\nModello: " << Orologio[i].Modello << "\nAnno: "<< Orologio[i].Anno << "\nTipologia: " << Orologio[i].Tipologia << "\nPrezzo: "<<Orologio[i].Prezzo << "\nCodice: " << Orologio[i].Codice;
			cout << endl << "---------------" << endl;
		}
	}
}

//SelectionSort
void SelectionSort(informazioni Orologio[], short dim){
	for(int i = 0; i<dim; i++){
		int min = i;
		for(int j=i+1; j<dim; j++){
			if(Orologio[j].Codice < Orologio[min].Codice){
				min = j;
				
				informazioni temp = Orologio[min];
				Orologio[min] = Orologio[i];
				Orologio[i] = temp;	
			}
		}
	}
}

//RicercaBinaria che restituisce -1 se non ha trovato niente
int RicercaBi(informazioni Orologio[], short dim, int C){
	bool trovato = false;
	int first, last, mid, pos = -1;
	first = 0;
	last = dim-1;	
	while(trovato == false and first<=last){
		mid=(first+last)/2;
		//Controlla se si trova nella prima posizione
		if(Orologio[first].Codice== C){
			trovato = true;
			pos = first;
		//Controlla se si trova nell'ultima posizione
		} else if(Orologio[last].Codice == C){
			trovato = true;
			pos = last;
		//Controlla se si trova nel posizione centrale 
		} else if(Orologio[mid].Codice == C){
			trovato = true;
			pos = mid;
		}
		//Controlla se quello cercato è maggiore della posizione centrale, così da rimuovere numeri che non sono inutili da ricontrollare
		if (C>Orologio[mid].Codice){
			first=mid+1;
			last-=1;
		} else {
			first++;
			last=mid-1;
		}
	}
	//restituisce la posizione
    return pos;
}

void Rimozione(informazioni Orologio[], short& dim, int pos){
	for(int i=pos; i<dim-1; i++){
		Orologio[i] = Orologio[i+1];
	}
	dim--;
}

int main(){
	short dim;
	cout << "Inserire la dimensione: ";
	cin >> dim;
	while(dim<=0 || dim>MAX_DIM){
		cout << "Errore, riprovare." << endl;
		cin >> dim;
	}
	informazioni Orologio[dim];
	Caricamento(Orologio, dim);
	int pos = Vecchio(Orologio, dim);
	cout << "L'orologio più vecchio \212: " << "\nMarca: " << Orologio[pos].Marca << "\nModello: " << Orologio[pos].Modello << "\nTipologia: " << Orologio[pos].Tipologia << endl;
	cout << "-------------" << endl;
	BubbleSort(Orologio, dim);
	Visualizzazione(Orologio, dim);
	string CercatoS;
	cout << "Inserire la marca che vuoi cercare." << endl;
	cin >> CercatoS;
	CercaMarca(Orologio, CercatoS, dim);
	VisualizzazioneFasciaPrezzo(Orologio, dim);
	float cassa = 0;
	SelectionSort(Orologio, dim);
	int CercatoN;
	bool stop = false;
	char scelta;
	while(stop==false){
	cout << "Inserire il codice del prodotto che ti interessa acquistare." << endl;
	cin >> CercatoN;
	SelectionSort(Orologio, dim);
	pos = RicercaBi(Orologio, dim, CercatoN);
	if(pos!=-1){
		cassa+= Orologio[pos].Prezzo;
		Rimozione(Orologio, dim, pos);
		cout << "Prodotto venduto con successo!" << endl;
	} else {
		cout << "Prodotto non trovato :(" << endl;
	}
	cout << "Continuare gli acquisti? Y/N" << endl;
	cin >> scelta;
	while(scelta!='Y' and scelta!='N'){
		cout << "Errore." << endl;
		cin >> scelta;
	}
	if(scelta=='N'){
		stop = true;
	}
}
	Visualizzazione(Orologio, dim);
	cout << "Cassa: " << cassa;
}
