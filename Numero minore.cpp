#include<iostream>
using namespace std;

int main() {
    int N, M = 2147483647;
    cout << "Inserisci il primo numero. (Deve essere necessariamente maggiore di 0 per la prima volta)" << endl;
    cin >> N;
    while (N <= 0) {
        cout << "Errore, inserire un altro numero che sia maggiore di 0." << endl;
        cin >> N;
    }
    while (N > 0) {
        if (N < M) {
            M = N;
        }
        cout << "Inserisci il prossimo numero." << endl;
        cin >> N;
    }
    cout << "Il numero più piccolo inserito è " << M << endl;
    return 0;
}

