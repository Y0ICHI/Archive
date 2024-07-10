#include <iostream>
using namespace std;
int main() {
    int num;
    cout << "Inserisci un numero naturale: ";
    cin >> num;
    int primo = 1; 
    while (num < 1) {
        cout <<endl<< "Inserisci un numero naturale: ";
        cin >> num;
    } {
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                primo = 0;
                break;
            }
        }
    }
    if (primo!=0) {
        cout << num << " è un numero primo." << endl;
    } else {
        cout << num << " non è un numero primo." << endl;
    }
    return 0;
}
