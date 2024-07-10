#include <iostream>
using namespace std;
int main() {
int N, Pos = 0, Neg = 0, Null = 0, C = 0;
cout << "Inserisci una sequenza di numeri interi che termina con un numero negativo:" << endl;
while (C<1) {
cin >> N;
if (N > 0) {

Pos++;

} else if (N < 0) {

Neg++;

C++;

} else {

Null++;
}
}
cout << "I Numeri maggiori di zero sono: " << Pos << endl; 
cout << "I Numeri minori di zero sono: " << Neg << endl;
cout << "I Numeri nulli sono: " << Null << endl;
return 0;
}
    