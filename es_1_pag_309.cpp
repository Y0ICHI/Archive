#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
const short MAX_COL = 20;

void Dimensione(short &n, short &n2);
void Caricamento(int Mat[][MAX_COL] ,short N, short M);
bool Pari(short r);
void Scambio(int Mat[][MAX_COL], short r, short c);
void Visualizzazione(int Mat[][MAX_COL], short N, short M);

int main(){
	short N, M;
	Dimensione(N, M);
	int Mat[N][MAX_COL];
	Caricamento(Mat, N, M);
	Scambio(Mat, N, M);
	Visualizzazione(Mat, N, M);
}

void Dimensione(short &n, short &n2){
	cout << "Inserire dimensioni riga: ";
	cin >> n;
	while (n<=0 || n>10){
		cout << "\nErrore, riprovare: ";
		cin >> n;
	}
	cout << "Inserire dimensioni colonna: ";
	cin >> n2;
	while (n2<=0 || n2>MAX_COL){
		cout << "\nErrore, riprovare: ";
		cin >> n2;
	}
}

void Caricamento(int Mat[][MAX_COL] ,short N, short M){
	int i, j;
	for(i=0; i<N; i++){
		for (j=0; j<M; j++){
			cout << "Inserisci l'elemento di riga " << i << " e colonna " << j << "." << endl;
			cin >> Mat[i][j];
		}
	}
}

bool Pari(short r){
	bool trovato = false;
	if(r%2==0)
		trovato = true;
	return trovato;
}

void Scambio(int Mat[][MAX_COL], short r, short c){
	short temp;
	int j,i;
	if(!Pari(r)){
		r-=1;
	}
	for(i=0; i<r; i+=2){
		for(j=0; j < c; j++){
		temp = Mat[i][j];
        Mat[i][j] = Mat[i+1][j];
        Mat[i+1][j] = temp;
		}
	}
}

void Visualizzazione(int Mat[][MAX_COL], short N, short M){
	for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << Mat[i][j] << " ";
        }
        cout << endl;
    }
}
