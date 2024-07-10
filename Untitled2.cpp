#include <iostream>

using namespace std;

int main() {
    short Perry; // Quantità
    int Prezzo;
    float PERCENTUALS;
    
    Prezzo = 100;
    
    cout << "Dammi il numero di pezzi che vuoi acquistare: ";
    cin >> Perry;
    
    switch(Perry) {
        case 1:
        case 2:
            PERCENTUALS = 10;
            break;
        case 3:
            PERCENTUALS = 20;
            break;
        case 4:
            break;
        case 5:
            PERCENTUALS = 30;
            break;
        case 6:
        case 7:
        case 8:
        case 9:
            break;
        case 10:
            PERCENTUALS = 35;
            break;
        default:
            if (Perry > 10) {
                PERCENTUALS = 40;
            } else {
                cout << "Valore non valido!" << endl;
                return 0;
            }
    }
    
    Prezzo = (Prezzo * Perry * PERCENTUALS) / 100;
    
    cout << "Il prezzo finale da pagare e': " << Prezzo << endl;
    
    return 0;
}

