#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

typedef struct{
	string Nome;
	float Altezza;
	float Raggio;
} bean;

//Serve per il caricamento dati.
void Caricamento(bean Lattina[], int dim){
	for(int i = 0; i<dim; i++){
		//Inserimento di cosa ci sarà nella lattina
		cout << i+1 << " - Inserire il contenuto della lattina." << endl;
		cin >> Lattina[i].Nome;
		//Inserimento della altezza della lattina
		cout << i+1 << " - Inserire l'altezza della lattina." << endl;
		cin >> Lattina[i].Altezza;
		//Controlla se l'altezza non sia minore di 0, se è minore di 0 chiederà finchè non è maggiore
		while(Lattina[i].Altezza<=0){
			cout << i+1 << " - Errore. Riprovare." << endl;
			cin >> Lattina[i].Altezza;
		}
		//Inserimento del raggio della lattina
		cout << i+1 << " - Inserire il raggio della lattina." << endl;
		cin >> Lattina[i].Raggio;
		//Contollo minore o uguale a 0
		while(Lattina[i].Raggio<=0){
			cout << i+1 << " - Errore. Riprovare." << endl;
			cin >> Lattina[i].Raggio;
		}
	}
}

//Ordinamento di tipo bubblesort
void BubbleSort(bean Lattina[], int dim){
	bool scambi = true;
	int i, k, ultimo = dim-1;
	bean temp;
	while(scambi==true){
		scambi = false;
		k = ultimo;
		for(i=0; i<k; i++){
			//Ordina in ordine alfabetico il contenuto.
			if(Lattina[i].Nome>Lattina[i+1].Nome){
				scambi = true;
				ultimo = i;
				
				temp = Lattina[i];
				Lattina[i] = Lattina[i+1];
				Lattina[i+1] = temp;
			}
		}
	}
}

//Visualizzazione classica
void Visualizzazione(bean Lattina[], int dim){
	for(int i = 0; i<dim; i++){
		cout << i+1 << " - Nome: " << Lattina[i].Nome << "\nAltezza: " << Lattina[i].Altezza << "\nRaggio: " << Lattina[i].Raggio << endl;
		cout << "---------------" << endl;
	}
}


//Visualizzazione di altezza maggiore di 5
void VisualizzazioneMaggiore5(bean Lattina[], int dim){
	int i, j=1;
	for(i=0; i<dim; i++){
		if(Lattina[i].Altezza>=5){
			cout << j++ << " - Nome: " << Lattina[i].Nome << "\nAltezza: " << Lattina[i].Altezza << "\nRaggio: " << Lattina[i].Raggio << endl;
			cout << "--------------" << endl;
		}
	}
}


int main(){
	int dim;
	//Inserimento dimensione
	cout << "Inserire la dimensione." << endl;
	cin >> dim;
	//Controllo dimensione
	while(dim<=0){
		cout << "Errore, inserire un altra dimensione." << endl;
		cin >> dim;
	}
	//Dichiarazione record vettoriale
	bean Lattina[dim];
	//Chiamata funzioni
	Caricamento(Lattina, dim);
	BubbleSort(Lattina, dim);
	Visualizzazione(Lattina, dim);
	cout << "Maggiore di 5." << endl << endl;
	VisualizzazioneMaggiore5(Lattina, dim);
	system("pause");
	return 0;
}


