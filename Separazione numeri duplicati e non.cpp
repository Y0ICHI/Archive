#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    srand(time(NULL));
    int dim, i, min, max, trovato, j;
    cout << "Inserisci la dimensione: ";
    cin >> dim;
    int NC[dim], N[dim], elementi_distinti[dim], elementi_duplicati[dim];
    cout << "Numeri: ";
    for(i = 0; i < dim; i++) {
        N[i] = rand() % 29;
        cout << N[i] << " ";
        if (i == 0) {
            min = N[i];
            max = N[i];
        } else {
            if (N[i] < min) min = N[i];
            if (N[i] > max) max = N[i];
        }
    }
    cout << "\nNumeri ordine inverso: ";
    for(i = 0; i < dim; i++) {
        NC[i] = N[dim - 1 - i];
        cout << NC[i] << " ";
    }
    cout << "\nNumero minimo: " << min << "\nNumero massimo: " << max << endl;
        int contatore_distinti = 0, contatore_duplicati = 0;
    for (i = 0; i < dim; i++) {
        trovato = 0;
        for (j = 0; j < i; j++) {
            if (N[i] == N[j]) {
                trovato = 1;
                break;
            }
        }
        if (!trovato) {
            elementi_distinti[contatore_distinti++] = N[i];
        } else {
            elementi_duplicati[contatore_duplicati++] = N[i];
        }
    }
    int N_senza_duplicati[dim], contatore_senza_duplicati = 0;
    for (i = 0; i < dim; i++) {
        trovato = 0;
        for (j = 0; j < contatore_duplicati; j++) {
            if (N[i] == elementi_duplicati[j]) {
                trovato = 1;
                break;
            }
        }
        if (!trovato) {
            N_senza_duplicati[contatore_senza_duplicati++] = N[i];
        }
    }
    cout << "Numeri distinti: ";
    for (i = 0; i < contatore_distinti; i++) {
        cout << elementi_distinti[i] << " ";
    }
    cout << "\nNumeri duplicati: ";
    for (i = 0; i < contatore_duplicati; i++) {
        cout << elementi_duplicati[i] << " ";
    }
    cout << "\nVettore senza duplicati: ";
    for (i = 0; i < contatore_senza_duplicati; i++) {
        cout << N_senza_duplicati[i] << " ";
    }
    cout << endl;

    return 0;
}
