#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

bool Duplicato(int N, int Vet[], int dim);
void Caricamento(string Cognomi[], int dim);
void Caricamento(int Num[], int dim);
void Caricamento(float Sec[], int dim);
void Visualizzazione(string Cong[], int Num[], float Sec[], int dim);
void SelectionSort(string Cong[], int Num[], float Sec[], int dim);
void Rimozione(string Cong[], int Num[], float Sec[], int& dim, int pos);
void Controllo(string Cong[], int Num[], float Sec[], int& dim);
void BubbleSort(string Cong[], int Num[], float Sec[], int dim);
int RicercaBi(int Num[], int dim, int C);
void InserimentoAtleta(string Cognomi[], int Num[], float Sec[], int& dim);
void Spostamento(string Cognomi[], int Num[], float Sec[], int dim, string Cognomi2[], int Num2[], float Sec2[], int& dim2);
void VisualizzazioneR(string Cong[], int Num[], float Sec[], int dim);


int main(){
	const int MAX_DIM = 100;
	int dim;
	cout << "Inserire il numero di atleti da registrare." << endl;
	cin >> dim;
	while (dim<=0 or dim>MAX_DIM){
		if(dim<=0){
			cout << "Il numero non può essere minore o uguale di 0" << endl;
		} else {
			cout << "Il numero non può essere maggiore di " << MAX_DIM << "!" << endl;
		}
		cin >> dim;
	}
	string Cognome[MAX_DIM];
	Caricamento(Cognome, dim);
	int Numero[MAX_DIM];
	Caricamento (Numero, dim);
	float Secondi[MAX_DIM];
	Caricamento(Secondi, dim);
	SelectionSort(Cognome, Numero, Secondi, dim);
	Visualizzazione(Cognome, Numero, Secondi, dim);
	Controllo(Cognome, Numero, Secondi, dim);
	BubbleSort(Cognome, Numero, Secondi, dim);
	int cerca, pos;
	cout << "----------------------- \nInserire il numero pettorale dell'atleta che ti interessa cercare." << endl;
	cin >> cerca;
	while(cerca<=0){
		cout << "Errore, riprovare." << endl;
		cin >> cerca;
	}
	pos = RicercaBi(Numero, dim, cerca);
	if(pos!=-1){
		cout << "Atleta: " << Cognome[pos] << " Numero: " << Numero[pos] << " Tempo: " << Secondi[pos] << endl;
	} else {
		cout << "Nessun atleta trovato." << endl;
	}
	InserimentoAtleta(Cognome, Numero, Secondi, dim);
	string Cognome2[MAX_DIM];
	int Numero2[MAX_DIM];
	float Secondi2[MAX_DIM];
	int dim2 = 0;
	Spostamento(Cognome, Numero, Secondi, dim, Cognome2, Numero2, Secondi2, dim2);
	VisualizzazioneR(Cognome2, Numero2, Secondi2, dim2);
	system("pause");
}

bool Duplicato(int N, int Vet[], int dim){
	bool trovato = false;
	int i=0;
	while(i<dim and trovato == false){
		if(N == Vet[i]){
			trovato = true;
		}
		i++;
	}
	return trovato;
}

void Caricamento(string Cognomi[], int dim){
	int i;
	for(i=0; i<dim; i++){
		cout << i+1 << " - Inserire il cognome dell'atleta." << endl;
		cin >> Cognomi[i];
	}
}

void Caricamento(int Num[], int dim){
	int i;
	for(i=0; i<dim; i++){
		cout << i+1 << " - Inserire il numero di Pettorale." << endl;
		cin >> Num[i];
		while(Duplicato(Num[i], Num, i)==true or Num[i]<=0){
			cout << i+1 << " - Errore! Inserire un altro numero." << endl;
			cin >> Num[i];
		}
	}
}

void Caricamento(float Sec[], int dim){
	int i;
	for(i=0; i<dim; i++){
		cout << i+1 << " - Inserisci i secondi." << endl;
		cin >> Sec[i];
	}
}

void Visualizzazione(string Cong[], int Num[], float Sec[], int dim){
	int i, j=0;
	for (i=0; i<dim; i++){
		if(Sec[i]!=0){
			cout << j+1 << " - Atleta: " << Cong[i] << " Numero: " << Num[i] << " Tempo: " << Sec[i] << "s" << endl;
			j++;
	}
	}
}

void SelectionSort(string Cong[], int Num[], float Sec[], int dim){
	int i, j, min;
	string tem;
	float temp;
	for(i=0;i<dim-1;i++)
    {
	min=i;
        for(j=i+1;j<dim;j++)
        	if (Sec[j]<Sec[min])
        	     min= j;
        	     
        temp=Sec[min];
        Sec[min]=Sec[i];
        Sec[i]=temp;
        
        tem=Cong[min]; //
        Cong[min]=Cong[i];
        Cong[i]=tem;
        
        temp=Num[min]; //
        Num[min]=Num[i];
        Num[i]=temp;      
    }
}

void Rimozione(string Cong[], int Num[], float Sec[], int& dim, int pos){
	int i;
	for(i=pos; i<dim-1; i++){
		Cong[i] = Cong[i+1];
		Num[i] = Num[i+1];
		Sec[i] = Sec[i+1];
	}
	dim--;
	cout << "Valore rimosso nella posizione: " << pos << endl;
}

void Controllo(string Cong[], int Num[], float Sec[], int& dim){
	for(int i=0; i<dim;){
		if(Sec[i] == 0 or Sec[i]>1000){
			Rimozione(Cong, Num, Sec, dim, i);
		} else {
			i++;
		}
	}
}

void BubbleSort(string Cong[], int Num[], float Sec[], int dim){
	int i, j, s, t, k, ultimo;
	string t1;
	float t2;
	ultimo = dim-1;
	k = ultimo;
	bool scambi = true;
	while(scambi==true){
		k = ultimo;
		scambi = false;
		for(i=0; i<=k-1; i++){
			if(Num[i]>Num[i+1]){
				scambi = true;
				ultimo = i;
				
				t1 = Cong[i];
				Cong[i] = Cong[i+1];
				Cong[i+1] = t1;
		
				t2 = Num[i];
				Num[i] = Num[i+1];
				Num[i+1] = t2;
		
				t2 = Sec[i];
				Sec[i] = Sec[i+1];
				Sec[i+1] = t2;
			}
		}
	}
}

int RicercaBi(int Num[], int dim, int C){
	bool trovato = false;
	int first, last, mid, pos = -1;
	first = 0;
	last = dim-1;	
	while(trovato == false and first<=last){
		mid=(first+last)/2;
		if(Num[first]== C){
			trovato = true;
			pos = first;
		} else if(Num[last] == C){
			trovato = true;
			pos = last;
		} else if(Num[mid] == C){
			trovato = true;
			pos = mid;
		}
		if (C>Num[mid]){
			first=mid+1;
			last-=1;
		} else {
			first++;
			last=mid-1;
		}
	}
	return pos;
}

void InserimentoAtleta(string Cognomi[], int Num[], float Sec[], int& dim) {
    int Temp, i, j;
    cout << "Inserire il numero di pettorina dell'atleta: ";
    cin >> Temp;
    while(Temp <= 0 || Duplicato(Temp, Num, dim)) {
        cout << "Errore. Inserirne un altro." << endl;
        cin >> Temp;
    }
	//Serve per trovare la posizione dove inserire la pettorina, prima di potere inserire gli altri dati.
    for(i = 0; i < dim && Num[i] < Temp; i++);

    for(j = dim; j > i; j--) {
        Num[j] = Num[j-1];
        Cognomi[j] = Cognomi[j-1];
        Sec[j] = Sec[j-1];
    }

    Num[i] = Temp;

    cout << "Inserire il cognome dell'atleta: ";
    cin >> Cognomi[i];
    cout << "Inserire il tempo dell'atleta: ";
    cin >> Sec[i];
    while(Sec[i]<=0){
    	cout << "Errore." << endl;
    	cin >> Sec[i];
	}
    dim++;
}

void Spostamento(string Cognomi[], int Num[], float Sec[], int dim, string Cognomi2[], int Num2[], float Sec2[], int& dim2){
	int j = 0;
	for(int i=0; i<dim; i++){
		if(Sec[i]>=500 and Sec[i]<=800){
			Cognomi2[j]=Cognomi[i];
			Num2[j]=Num[i];
			Sec2[j]=Sec[i];
			j++;
		}
	}
	dim2 = j;
}

void VisualizzazioneR(string Cong[], int Num[], float Sec[], int dim){
    int i, j = 0;
    for (i = dim-1; i >= 0; i--){
        cout << j+1 << " - Atleta: " << Cong[i] << " Numero: " << Num[i] << " Tempo: " << Sec[i] << "s" << endl;
        j++;
    }
}
