#include <iostream>
using namespace std;
int main() {
    int NP=0, N, S, i=0;
    while (NP<3) {
        cout << "Inserire un numero positivo: ";
        cin >> N;
        while (N<=0) {
            cout << "Errore. Inserire un numero positivo: ";
            cin >> N;
        }
        S=0;
        for (i=1; i < N; i++) {
            if (N%i==0) {
                S+=i;
            }
        }
        if (S==N) {
            cout << "Il numero " << N << " è perfetto!" << endl;
            NP++;
        } else {
            cout << "Il numero " << N << " non è perfetto." << endl;
        }
    }
    return 0;
}
