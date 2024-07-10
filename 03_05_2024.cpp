#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

const int MAX = 20;

int Random();
void VisualizzazioneVet(int Vet[], int pos);
void VisualizzazioneMat(int Mat[][MAX], int dim);
void Dimensione(int &dim);
void Caricamento(int Mat[][MAX], int dim);
bool ParioDispari(int N);
void CopiaDiagonale(int Mat[][MAX], int dim, int Vet[], int& pos);
void CopiaPerimetro(int Mat[][MAX], int dim, int Vet[], int& pos);
void CopiaPari(int Mat[][MAX], int dim, int Vet[], int& pos);
void CopiaDispari(int Mat[][MAX], int dim, int Vet[], int& pos);

int main(){
	srand(time(NULL));
	int dim;
	Dimensione(dim);
	int Mat[dim][MAX];
	Caricamento(Mat, dim);
	VisualizzazioneMat(Mat, dim);
	int Vet[(dim*2)], pos;
	CopiaDiagonale(Mat, dim, Vet, pos);
	cout << " 1 "<<endl;
	VisualizzazioneVet(Vet, pos);
	cout << endl << "2 -------------" << endl;
	int Vet2[(dim*dim)];
	pos = 0;
	CopiaPerimetro(Mat, dim, Vet2, pos);
	VisualizzazioneVet(Vet2, pos);
	int Vet3[(dim*dim)];
	cout << endl << "3 ------------" << endl;
	CopiaPari(Mat, dim, Vet3, pos);
	VisualizzazioneVet(Vet3, pos);
	int Vet4[(dim*dim)];
	CopiaDispari(Mat, dim, Vet4, pos);
	cout << endl << "4 ----------" << endl;
	VisualizzazioneVet(Vet4, pos);
}

int Random(){
	int valore = rand()%100+1;
	//cout << "Valore: " << valore << endl;
	return valore;
}

void VisualizzazioneVet(int Vet[], int pos){
	int i;
	for(i=0;i<pos; i++){
		cout << Vet[i] << "\t";
	}
}

void VisualizzazioneMat(int Mat[][MAX], int dim){
	int i,j;
	for (i=0; i<dim; i++){
		for(j=0; j<dim; j++){
		cout << Mat[i][j] << "\t";
	}
	cout << endl;
}
}

void Dimensione(int &dim){
	cout << "Inserire la dimensione della matrice." << endl;
	cin >> dim;
	//dim = Random();
	while(dim<=0 or dim >MAX){
		cout << "Errore." << endl;
		//cin >> dim;
		dim = Random();
	}
	cout << "Valore accettato: " << dim << endl;
}

void Caricamento(int Mat[][MAX], int dim){
	int i, j;
	for(i=0; i<dim; i++){
		for(j=0; j<=dim; j++){
			//cin >> Mat[i][j];
			Mat[i][j]= Random();
		}
	}
}

bool ParioDispari(int N){
	bool controllo = false;
	if(N%2==0){
		controllo = true;
	}
	return controllo;
}


void CopiaDiagonale(int Mat[][MAX], int dim, int Vet[], int& pos){
	int i;
	int conta = 0;
	int first = 0;
	int last = dim - 1;

	for(i = 0; i < dim; i++){
		Vet[conta++] = Mat[i][first];
		if (first != last) {
			Vet[conta++] = Mat[i][last];
		}
		first++;
		last--;
	}

	pos = conta;
}

void CopiaPerimetro(int Mat[][MAX], int dim, int Vet[], int& pos){
	int i, j=0, m=0;
	int first = 0, last = dim-1;
	for(i=0; i<dim; i++){
		Vet[j]=Mat[m][i];
		j++;
	}
	m++;
	for(m; m<(dim-1); m++){
		Vet[j]=Mat[m][first];
		j++;
		Vet[j]=Mat[m][last];
		j++;
	}
	for(i=0; i<dim; i++){
		Vet[j]=Mat[m][i];
		j++;
	}
	pos = j;
}

void CopiaPari(int Mat[][MAX], int dim, int Vet[], int& pos){
	int i, j, pp = 0;
	for(i=0; i<dim; i++){
		for(j=0; j<dim; j++){
			if(ParioDispari(Mat[i][j])){
				Vet[pp++]=Mat[i][j];
			}
		}
	}
	pos = pp;
}

void CopiaDispari(int Mat[][MAX], int dim, int Vet[], int& pos){
	int i, j, pp = 0;
	for(i=0;i<dim; i++){
		for(j=1; j<dim; j+=2){
			Vet[pp++]=Mat[i][j];
		}
	}
	pos = pp;
}
