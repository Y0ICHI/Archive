#include <iostream>
using namespace std;
int main() {
    int ora;
    cout << "Che ore sono da te?" << endl << "Se devi specificare mezzanotte non usare 0:00 ma invece 24:00" << endl;
    cin >> ora;
    while (ora<1 or ora>24) {
    cout << "Orario non valido. Inserire un'ora valida, grazie." << endl;
    cin >> ora;
}
if (ora>=18 || ora<=4) {
cout << "Buonasera!" << endl;
} else { 
    if (ora>=5 && ora<=12) {
        cout << "Buongiorno!" << endl;
    } else { 
        if (ora>=13 && ora <=17)
        cout << "Buon pomeriggio!" << endl;
    }
}
return 0;
}