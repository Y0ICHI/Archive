#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
	srand(time(NULL));
	int i, somma, media, min, max=0;
	unsigned int dim = 10;
	int N[dim];
	for(i=0; i<=dim-1; i++){
		N[i] = rand() % 100+1;
		cout << "Debug: " << N[i] << endl;
	}
	somma = N[0];
	min = N[0];
	for(i=1; i<=dim-1; i++)
	somma+=N[i];
	cout << "la somma e' uguale a: " << somma << endl;
	media = somma/dim;
	cout << "La media e': " << media << endl;
	for(i=0; i<=dim-1; i++){
		if(N[i]>max){
			max = N[i];
		}
		if(N[i]<min){
			min = N[i];
		}
	}
	cout << "Il numero massimo e': " << max << endl << "Il numero minimo e': " << min << endl;
}
