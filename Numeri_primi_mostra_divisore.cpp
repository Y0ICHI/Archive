#include <iostream>
using namespace std;
int main() {
    int num;
    cout << "Inserisci un numero naturale: ";
    cin >> num;
    while (num < 1) {
        cout << "Inserisci un numero naturale: ";
        cin >> num;
    }
    int primo = 1; 
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            primo = 0;
            cout << num << " non è un numero primo. Divisori: ";
            for (int j = 1; j <= num; ++j) {
                if (num % j == 0) {
                    cout << j << " ";
                }
            }
            cout << endl;
			 break;
        }
    }
    if (primo != 0) {
        cout << num << " è un numero primo." << endl;
    }
    return 0;
}
