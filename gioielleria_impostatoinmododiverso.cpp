#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
void caricamento(int codice[], string tipologia[], string marca[], float prezzo[], int dim);
void ricercaMassimoMinimo(float prezzo[], int dim, int &posMin, int &posMax);
void ricercaPrezzo(float prezzo[], int dim, float prz1, float prz2, int PosV[], int &numTrovati);

int main() {
    int vMax = 50;
    int dim, i;
    int cassa = 0;
    int l[1];
    int dimPosV = 0;

    cout << "Quanti oggetti sono presenti nella gioielleria?" << endl;
    cin >> dim;
    while (dim <= 0 || dim > vMax) {
        cout << "Errore. Riprovare." << endl;
        cin >> dim;
    }
    string marca[dim];
    string tipologia[dim];
    int codice[dim];
    double prezzo[dim];

    caricamento(codice, tipologia, marca, prezzo, dim);

    int pos[2];
    ricercaMassimoMinimo(prezzo, dim, pos[0]);
    ricercaMassimoMinimo(prezzo, dim, pos[1]);
    cout << "L'oggetto piu' costoso e' " << tipologia[pos[0]] << " di marca " << marca[pos[0]] << " che costa " << prezzo[pos[0]] << endl;
    cout << "L'oggetto piu' economico e' " << tipologia[pos[1]] << " di marca " << marca[pos[1]] << " che costa " << prezzo[pos[1]] << endl;
    float prz1, prz2;
    cout << "Inserire la prima soglia di prezzo." << endl;
    cin >> prz1;
    cout << "Inserire la seconda soglia di prezzo." << endl;
    cin >> prz2;
    while (prz1 > prz2) {
        cout << "Errore. Il prezzo minimo non puo' essere maggiore del prezzo massimo." << endl;
        cout << "Inserire la prima soglia di prezzo." << endl;
        cin >> prz1;
        cout << "Inserire la seconda soglia di prezzo." << endl;
        cin >> prz2;
    }
    ricercaPrezzo(prezzo, dim, prz1, prz2, PosV, numTrovati);
    for (i=0; i<numTrovati; i++)
        cout << tipologia[posV[i]];
    /*ricercaPrezzo(prezzo, codice, dim, l, dimPosV);
    if (dimPosV != 0) {
        cout << "Sono stati trovati " << dimPosV << " oggetti!" << endl;
        for (i = 0; i < dimPosV; i++) {
            cassa = cassa + prezzo[codice[i]];
        }
        cout << "La somma totale è " << cassa << endl;
    }*/
    return 0;
}

void caricamento(int codice[], string tipologia[], string marca[], double prezzo[], int dim) {
    int i;

    for (i = 0; i < dim; i++) {
        codice[i] = rand() % 99 + 1;
        cout << i + 1 << " Codice: " << codice[i] << endl;
        cout << i + 1 << " Tipologia: " << endl;
        cin >> tipologia[i];
        cout << i + 1 << " Marca: " << endl;
        cin >> marca[i];
        cout << i + 1 << " Prezzo: " << endl;
        cin >> prezzo[i];
        while (prezzo[i] <= 0) {
            cout << "Errore. Riprovare." << endl;
            cin >> prezzo[i];
        }
    }
    return;
}
void ricercaMassimoMinimo(double prezzo[], int dim, int pos[]) {
    int i;
    double prezzoMinimo = prezzo[0];
    double prezzoMassimo = prezzo[0];
    pos[0] = -1;
    pos[1] = -1;
    for (i = 0; i < dim; i++) {
        if (prezzo[i] < prezzoMinimo) {
            prezzoMinimo = prezzo[i];
            pos[1] = i;
        } else if (prezzo[i] > prezzoMassimo) {
            prezzoMassimo = prezzo[i];
            pos[0] = i;
        }
    }
    return;
}

void ricercaPrezzo(double prezzo[], int posV[], int dim, int l[]) {
    int i, j = 0;

    for (i = 0; i < dim; i++) {
        if (prezzo[i] >= l[0] && prezzo[i] <= l[1]) {
            posV[j] = i;
            j++;
        }
    }
    l[0] = j;
    return;
}
