#include <iostream>
using namespace std;
int main() {
    int NUM, somma = 0, i = 2;
    cout << "Inserisci un numero intero positivo: ";
    cin >> NUM;
    while (i <= NUM * 2) {
        somma += i;
        i += 2;
    }
    cout << "La somma dei primi " << NUM << " interi positivi pari e': " << somma << endl;
    return 0;
}
