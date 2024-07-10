/*secondo tentativo della codificazione
Antonio d'Agostino 3Di */
#include<iostream>
using namespace std;
int main () {
	int stipendio, scaglione, famiglia, nfam, trattenuto, sf;
	cout << "Quanto e' il tuo stipendio?" << endl;
	cin >> stipendio;
	cout << "Che numero di scaglione sei?" << endl;
	cin >> scaglione;
	cout << "Quanti familiari hai in carico?";
	cin >> famiglia;
	if (scaglione >=1 && scaglione <=5) {
		if (stipendio > 1) {
			if (scaglione<=3) {
				nfam = ( famiglia*50)
				} else {
					nfam = (famiglia*25)} else {
						
			} } 
			}else{
			cout << "Nuero stipendio non valido.";	
			}
			} else { 
			cout << "Numero di scaglione non valido.";
				
			}
		}
	}
