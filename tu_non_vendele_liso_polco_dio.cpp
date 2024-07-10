#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

void Caricamento(int dim, int n[]){
	srand(time(NULL));
	int i;
	for(i=0; i<=dim; i++){
		n[i] = rand() % 41 - 20;
	}
}

void Ordinamento(int dim, int n[]) {
	int i, j;
    for (int i = 0; i < dim - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < dim; ++j) {
            if (n[j] < n[minIndex]) {
                minIndex = j;
            }
        }
	int t = n[minIndex];
        n[minIndex] = n[i];
        n[i] = t;
    }
}
    
void Lista(int dim, int n[]) {
	int i;
	for(i=0; n[i]<0; i++){
		cout << n[i] << " ";
	}
	cout << " |  ";
	for(i; i<=dim-1; i++){
		cout << n[i] << " ";
	}
}

int main(){
	int dim;
	cout << "Inserire la dimensione." << endl;
	cin >> dim;
	while(dim<=0){
		cout << "Errore." << endl;
		cin >> dim;
	}
	int n[dim];
	Caricamento(dim, n);
	Ordinamento(dim , n);
	Lista(dim, n);
}


