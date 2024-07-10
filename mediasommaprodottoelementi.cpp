#include<iostream>
using namespace std;

int main() {
    int NN, C = 0, MAX, MEDIA = 0, S = 0, P = 1;

    cout << "Quanti numeri devi inserire?" << endl;
    cin >> NN;

    MAX = NN;
    int N[MAX];

    while (C < MAX) {
        cin >> N[C];
        C++;
    }

    C = 0;

    while (C < MAX) {
        MEDIA += N[C];

        if (N[C] % 2 == 0) {
            S += N[C];
        } else {
            P *= N[C];
        }

        C++;
    }

    MEDIA /= C;

    cout << "Media: " << MEDIA << endl;
    cout << "Somma dei numeri pari: " << S << endl;
    cout << "Prodotto dei numeri dispari: " << P << endl;

    return 0;
}

