#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

const int  MAX = 100;

int RichiestaRiga();
int RichiestaColonne();
void CaricaMatrice(int m[][MAX], int r, int c);

int main(){
	int righe, colonne;
	int mat [MAX][MAX];
	
	int TotRiga;
	int TotColonna;
	
	righe = RichiestaRiga();
	colonne = RichiestaColonne();
	cout << "Carica gli elementi della matrice." << endl;
	
	CaricaMatrice(mat, righe, colonne);
	cout << endl;
	
	for(int i=0; i<righe; i++){
		TotRiga = 0;
		for(int j=0; j<colonne; j++) {
			cout <<	"\t" << mat[i][j];
			TotRiga+=mat[i][j];
		}
		cout << "\t" << TotRiga << endl;	 
	}
	cout << "Inverto gli elementi della matrice per mostrarti i risultati per colonna: " << endl;
	for(int j=0; j<colonne; j++){
		TotColonna = 0;
		for(int i = 0; i<righe; i++){
			cout << "\t" << mat[i][j];
			TotColonna+=mat[i][j];
		}
		cout << "\t" << TotColonna << endl;
	}
	cout << endl;
	
	return 0;
}

int RichiestaRiga(){
	int d;
	do {
		cout << "Numero delle righe: ";
		cin >> d;
	} while (d<1 || d> MAX);
	
	return d;
}

void CaricaMatrice(int m[][MAX], int r, int c){
	for (int i = 0; i<r; i++){
		for (int j=0; j<c; j++){
			cout << "Elemento di posto " << i << " , " << j << ":";
			cin >> m[i][j];
		}
	}
}
