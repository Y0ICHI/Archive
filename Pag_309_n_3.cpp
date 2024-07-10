#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

const int MMax = 60;
const int PMax = 60;
const int NMax = 60;

void MoltiplicazioneMatrice(int A[][PMax], int B[][NMax], int C [][NMax], int M, int P, int N);
void StampaMatrice(int Matrice[][NMax], int rige, int colonne);
void Dimensione(int &n, int &n2, int& n3);
void Caricamento(int Mat[][PMax] ,int Riga, int Colonna);

int main(){
	int M, P, N;
	Dimensione(M, P, N);
	int MatA[M][PMax];
	int MatB[PMax][NMax];
	int MatC[MMax][NMax];
	cout << "Caricamento Matrice A" << endl;
	Caricamento(MatA, M, P);
	cout << "Caricamento Matrice B" << endl;
	Caricamento(MatB, P, N);
	MoltiplicazioneMatrice(MatA, MatB, MatC, M, P, N);
	cout << "Matrice C (Prodotto di A e B):" << endl;
	StampaMatrice(MatC, M, N);
}

void MoltiplicazioneMatrice(int A[][PMax], int B[][NMax], int C [][NMax], int M, int P, int N){
	int i, j, k;
    for (i = 0; i < M; ++i) {
        for (j = 0; j < N; ++j) {
            C[i][j] = 0;
            for (k = 0; k < P; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void StampaMatrice(int Matrice[][NMax], int rige, int colonne){
	int i, j;
	for(i=0; i<rige; i++){
		for(j=0; j<colonne; j++){
			cout << Matrice[i][j] << " ";
		}
		cout << endl;
	}
}

void Dimensione(int &n, int &n2, int& n3){
	cout << "Inserire dimensioni riga A: ";
	cin >> n;
	while (n<=0 || n>MMax){
		cout << "\nErrore, riprovare: ";
		cin >> n;
	}
	cout << "Inserire dimensioni colonna A e riga B: ";
	cin >> n2;
	while (n2<=0 || n2>PMax){
		cout << "\nErrore, riprovare: ";
		cin >> n2;
	}
	cout << "Inserire collona B: ";
	cin >> n3;
	while(n3<=0 || n3>NMax){
		cout << "\nErrore, riprovare: ";
		cin >> n3;
	}
}

void Caricamento(int Mat[][PMax] ,int Riga, int Colonna){
	int i,j;
	for(i=0; i<Riga; i++){
		for (j=0; j<Colonna; j++){
			cout << "Inserisci l'elemento di riga " << i << " e colonna " << j << "." << endl;
			cin >> Mat[i][j];
		}
	}
}


