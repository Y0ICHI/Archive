#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

typedef struct{
    int Numero;
    string Cognome;
    float Secondi;       
} atleta;

bool Duplicato(int N, atleta Vet[], int dim){
    bool trovato = false;
    int i=0;
    while(i<dim && !trovato){
        if(N == Vet[i].Numero){
            trovato = true;
        }
        i++;
    }
    return trovato;
}

void Caricamento(atleta Atleta[], int dim){
    for(int i=0; i<dim; i++){
        cout << i+1 << " - Inserire il cognome dell'atleta." << endl;
        cin >> Atleta[i].Cognome;
    }
}

void Caricamento1(atleta Atleta[], int dim){
    for(int i=0; i<dim; i++){
        cout << i+1 << " - Inserire il numero di Pettorale." << endl;
        cin >> Atleta[i].Numero;
        while(Duplicato(Atleta[i].Numero, Atleta, i) == true || Atleta[i].Numero <= 0){
            cout << i+1 << " - Errore! Inserire un altro numero." << endl;
            cin >> Atleta[i].Numero;
        }
    }
}

void Caricamento2(atleta Atleta[], int dim){
    for(int i=0; i<dim; i++){
        cout << i+1 << " - Inserisci i secondi." << endl;
        cin >> Atleta[i].Secondi;
    }
}

void Visualizzazione(atleta Atleta[], int dim){
	int j;
    for (int i=0; i<dim; i++){
        if(Atleta[i].Secondi != 0){
            cout << j+1 << " - Atleta: " << Atleta[i].Cognome << " Numero: " << Atleta[i].Numero << " Tempo: " << Atleta[i].Secondi << "s" << endl;
            j++;
        }
    }
}

void SelectionSort(atleta Atleta[], int dim){
    for(int i=0; i<dim-1; i++){
        int min = i;
        for(int j=i+1; j<dim; j++)
            if (Atleta[j].Secondi < Atleta[min].Secondi)
                min = j;
        
        atleta temp = Atleta[min];
        Atleta[min] = Atleta[i];
        Atleta[i] = temp;
    }
}

void Rimozione(atleta Atleta[], int& dim, int pos){
    for(int i=pos; i<dim-1; i++){
        Atleta[i] = Atleta[i+1];
    }
    dim--;
}

void Controllo(atleta Atleta[], int& dim){
    for(int i=0; i<dim;){
        if(Atleta[i].Secondi == 0 || Atleta[i].Secondi > 1000){
            Rimozione(Atleta, dim, i);
        } else {
            i++;
        }
    }
}

void BubbleSort(atleta Atleta[], int dim){
	atleta temp;
	int i, j, s, t, k;
	bool scambi = true;
	int ultimo = dim-1;
	while(scambi==true){
		k=ultimo;
		scambi = false;
		for(i=0; i<=k-1; i++){
			for(i=0; i<=k-1; i++){
				if(Atleta[i].Numero>Atleta[i+1].Numero){
					scambi = true;
					ultimo = i;
					
					temp = Atleta[i];
					Atleta[i] = Atleta[i+1];
					Atleta[i+1] = temp;
				}
			}
		}
	}
}

int RicercaBi(atleta Atleta[], int dim, int C){
	bool trovato = false;
	int first, last, mid, pos = -1;
	first = 0;
	last = dim-1;	
	while(trovato == false and first<=last){
		mid=(first+last)/2;
		if(Atleta[first].Numero== C){
			trovato = true;
			pos = first;
		} else if(Atleta[last].Numero == C){
			trovato = true;
			pos = last;
		} else if(Atleta[mid].Numero == C){
			trovato = true;
			pos = mid;
		}
		if (C>Atleta[mid].Numero){
			first=mid+1;
			last-=1;
		} else {
			first++;
			last=mid-1;
		}
	}
    return pos;
}

void InserimentoAtleta(atleta Atleta[], int& dim) {
    atleta Temp;
    int i;
    cout << "Inserire il numero di pettorina dell'atleta: ";
    cin >> Temp.Numero;
    while(Temp.Numero <= 0 || Duplicato(Temp.Numero, Atleta, dim)) {
        cout << "Errore. Inserirne un altro." << endl;
        cin >> Temp.Numero;
    }
    for(i = 0; i < dim && Atleta[i].Numero < Temp.Numero; i++);

    for(int j = dim; j > i; j--) {
        Atleta[j] = Atleta[j-1];
    }

    Atleta[i] = Temp;

    cout << "Inserire il cognome dell'atleta: ";
    cin >> Atleta[i].Cognome;
    cout << "Inserire il tempo dell'atleta: ";
    cin >> Atleta[i].Secondi;
    while(Atleta[i].Secondi <= 0){
        cout << "Errore." << endl;
        cin >> Atleta[i].Secondi;
    }
    dim++;
}

void Spostamento(atleta Atleta[], int dim, atleta Atleta2[], int& dim2){
    int j = 0;
    for(int i=0; i<dim; i++){
        if(Atleta[i].Secondi >= 500 && Atleta[i].Secondi <= 800){
            Atleta2[j] = Atleta[i];
            j++;
        }
    }
    dim2 = j;
}

void VisualizzazioneR(atleta Atleta[], int dim){
    for (int i = dim-1, j = 0; i >= 0; i--){
        cout << j+1 << " - Atleta: " << Atleta[i].Cognome << " Numero: " << Atleta[i].Numero << " Tempo: " << Atleta[i].Secondi << "s" << endl;
        j++;
    }
}

int main(){
    const int MAX_DIM = 100;
    int dim;
    cout << "Inserire il numero di atleti da registrare." << endl;
    cin >> dim;
    while (dim <= 0 || dim > MAX_DIM){
        if(dim <= 0){
            cout << "Il numero non può essere minore o uguale di 0" << endl;
        } else {
            cout << "Il numero non può essere maggiore di " << MAX_DIM << "!" << endl;
        }
        cin >> dim;
    }
    atleta Atleti[MAX_DIM];
    Caricamento(Atleti, dim);
    Caricamento1(Atleti, dim);
    Caricamento2(Atleti, dim);
    SelectionSort(Atleti, dim);
    Visualizzazione(Atleti, dim);
    Controllo(Atleti, dim);
    BubbleSort(Atleti, dim);
    int cerca, pos;
    cout << "----------------------- \nInserire il numero pettorale dell'atleta che ti interessa cercare." << endl;
    cin >> cerca;
    while(cerca <= 0){
        cout << "Errore, riprovare." << endl;
        cin >> cerca;
    }
    pos = RicercaBi(Atleti, dim, cerca);
    if(pos != -1){
        cout << "Atleta: " << Atleti[pos].Cognome << " Numero: " << Atleti[pos].Numero << " Tempo: " << Atleti[pos].Secondi << "s" << endl;
    } else {
        cout << "Nessun atleta trovato." << endl;
    }
    InserimentoAtleta(Atleti, dim);
    atleta Atleti2[MAX_DIM];
    int dim2 = 0;
    Spostamento(Atleti, dim, Atleti2, dim2);
    VisualizzazioneR(Atleti2, dim2);
    system("pause");
}

