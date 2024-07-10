#include <iostream>
using namespace std;

int main() {
    int num, gior;
    cout << "Dimmi il numero del mese." << endl;
    cin >> num;

    while (num < 1 or num > 12) {
        cout << "Valore non valido, dammene un altro." << endl;
        cin >> num;
    }

    if (num == 3 or num == 6 or num == 9 or num == 12) {
        cout << "Che giorno precisamente del mese?" << endl;
        cin >> gior;
    }

    switch (num) {
        case 1:
        case 2:
        case 3: 
            if (gior < 20) {
                cout << "La stagione � inverno" << endl;
            } else {
                cout << "La stagione � primavera" << endl;
            }
            break;

        case 4:
        case 5:
        case 6: 
            if (gior > 20) {
                cout << "La stagione � estate" << endl;
            } else {
                cout << "La stagione � primavera" << endl;
            }
            break;

        case 7:
        case 8:
        case 9: 
            if (gior > 20) {
                cout << "La stagione � autunno" << endl;
            } else {
                cout << "La stagione � estate" << endl;
            }
            break;

        case 10:
        case 11:
        case 12: 
            if (gior > 20) {
                cout << "La stagione � inverno" << endl;
            } else {
                cout << "La stagione � autunno" << endl;
            }
            break;
    }

    return 0;
}

