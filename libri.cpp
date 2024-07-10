#include<iostream>
#include<ctime>
#include <cstdlib>
using namespace std;
int main(){
	int i, dim, cmax=0, cmin=2147483647, max=0, min=2147483647;
	dim = 10;
	srand(time(NULL));
	int codice[dim];
	for(i=0; i<=dim-1; i++)
		codice[i] = (rand()%2147483647)+1;
	double prezzo[dim];
	for(i=0; i<=dim-1; i++)
	prezzo[i] = (rand()%50)+1;
	cout << "Lista libri!" << endl;
	for(i=0; i<=dim-1; i++)
	cout << "Libro: " << i+1 << ". " << "Codice: " << codice[i] << " Prezzo " << prezzo[i] << endl; 
	for(i=0; i<=dim-1; i++){
		if(prezzo[i]>cmax){
			max = codice[i];
			cmax = prezzo[i];
		}
		if(prezzo[i]<cmin){
			min = codice[i];
			cmin=prezzo[i];
		}
	}
	cout << "Il libro piu' costo e' quello con il codice " << max << " con il prezzo di " << cmax << "\nMentre il libro meno costo e' il libro con il codice " << min << " con il prezzo di " << cmin << endl;
	int input[2];
	cout << "Inserire il prezzo del libro che deve avere come minimo." << endl;
	cin >> input[0];
	cout << "Inserire il prezzo del libro che deve avere come massimo." << endl;
	cin >> input[1];
	cout << "Ecco il codice e il prezzo dei libri tra i prezzi inseriti: " << endl;
	for (i=0; i<=dim-1; i++){
		if(prezzo[i]>=input[0] && prezzo[i]<=input[1])
		cout << "Numero libro: " << i+1 << " Codice libro: " << codice [i] <<  " Prezzo libro: " << prezzo[i] << endl;
	}
	int cercato, pos;
	cout << "Quale libro vuoi togliere? Inserire il codice" << endl;
	cin >> cercato;
	pos=-1;
	for(i=0; i<=dim-1; i++){
		if(cercato==codice[i]){
			pos = i;
			i = dim;
		}
	}
	if(pos != -1){
		for(i=pos; i<=dim-2; i++){
			codice[i]=codice[i+1];
			prezzo[i]=prezzo[i+1];
		}
		dim-=1;
		cout << "Il libro numero " << pos+1 << ", con il codice " << cercato << " e' stato tolto e ripiazzato, ecco la nuova lista." << endl;
		for(i=0; i<=dim-1; i++)
		cout << "Libro: " << i+1 << " Codice: " << codice[i] << " Prezzo: " << prezzo[i] << endl;
	} else {
		cout << "Libro non trovato!";
	}
}
