#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main() {
    const int PC = 29;
    const int DC = 29;
    int N, i;
    int P[PC], D[DC], Numeri[PC + DC];
    srand(time(NULL));

    int countP = 0, countD = 0;

    for (N = 0; N < PC + DC; N++) {
        Numeri[N] = (rand() % 270) + 1;
        if (Numeri[N] % 2 == 0) {
            P[countP] = Numeri[N];
            countP++;
        } else {
            D[countD] = Numeri[N];
            countD++;
        }
    }

    cout << "Numeri pari: ";
    for (i = 0; i < countP; i++)
        cout << P[i] << " ";

    cout << "\nNumeri dispari: ";
    for (i = 0; i < countD; i++)
        cout << D[i] << " ";

    return 0;
}
