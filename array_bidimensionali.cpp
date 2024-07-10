#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

const int dim = 11;

void Tabellina(int Mat[][dim], int dim){
	int i, j;
	for(i=0; i<dim; i++){
		for(j=0; j<dim; j++){
			Mat[i][j] = i*j;
		}
	}
}

void VisualizzazionePerColonna(int Mat[][dim], int dim){
	int i, j=0;
	while(j!=dim){
		cout << "Tabbelina del " << j << endl;
	for(i=0; i<dim; i++){
		cout << Mat[i][j] << "\t";
	}
	j++;
}
}

void VisualizzazionePerRiga(int Mat[][dim], int dim){
	int i, j=0;
	for(i=0; i<dim; i++){
		cout << "Tabellina del " << i < " ";
		for(j=0; j<dim; j++){
			cout << Mat[i][j] << "\t" ; 
		}
		cout << endl;
	}
}

int main(){
	int Mat[dim][dim];
	Tabellina(Mat, dim);
	//VisualizzazionePerColonna(Mat, dim);
	VisualizzazionePerRiga(Mat, dim);
}
