#include <iostream>
using namespace std;
int main() {
    int N, M, P;
    short C;
    cout << "Inserisci il primo numero." << endl;
    cin >> N;
    P = N;
    M = N;
    C = 0;
    do {
    	C=C+1;
		N=M;
        cout << "Dammi il prossimo numero, deve essere crescente." << endl;
        cin >> M;
    } while (N < M);
    cout << "Hai inserito " << C << " numeri crescenti, prima di inserirne uno non valido." << endl;
    return 0;
}

