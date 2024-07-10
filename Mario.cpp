#include<iostream>
using namespace std;
int main(){
	int N;
	float CM=1,CPas=0,CPan=0,CostPas=1;
	double soldi, CostPan=1.5;
	cout << "Inserire il numero di soldi dare a Mario (in euro)" << endl;
	cin >> soldi;
	while(soldi<=0){
	cout << "Hai inserito un numero non valido di soldi, inserirne uno nuovo." << endl;
	cin >> soldi;
	}
	cout << "Primo giorno! Cosa vuoi fare mangiare a Mario?\n Scrivi 1 per indicare il panino (1.5 euro) mentre 2 per indicare la pastina (1 euro)" << endl;
	cin >> N;
	if(N<1 or N>2){
		while(N<1 or N>2){
			cout << "Valore non valido, riprovare." << endl;
			cin >> N;
		}
	}
	if(N==1){
		soldi-=CostPan;
		CPan++;
		cout << "Hai adesso: " << soldi << " euro." << endl;
	} else {
		soldi-=CostPas;
		CPas++;
		cout << "Hai adesso: " << soldi << " euro." << endl;
	}
	while(soldi>0){
	cout << "Nuovo giorno! Cosa vuoi fare mangiare a Mario?\n Piccolo reminder: 1 per panino (costo 1.5 euro), 2 per pastina (costo 1 euro)" << endl;
	cin >> N;
	while(N<1 or N>2){
			cout << "Valore non valido, riprovare." << endl;
			cin >> N;
		}
	if(N==1){
		if(soldi<CostPan){
			soldi-CostPan;
			cout << "Oh no! Sembra che non hai piu' soldi neccesari! Eccoti un recap di tutto quello che hai fatto mangiare a Mario." << endl;
			soldi-=CostPan;
		} else {
			soldi-=CostPan;
			cout << "Hai adesso: " << soldi << " euro." << endl;
			CPan++;
			CM++;
		}
	} else {
		if(soldi<CostPas){
			soldi-=CostPas;
			cout << "Oh no! Sembra che non hai piu' soldi neccesari! Eccoti un recap di tutto quello che hai fatto mangiare a Mario." << endl;
			soldi-=CostPas;
		} else {
			soldi-=CostPas;
			cout << "Hai adesso: " << soldi << " euro." << endl;
			CPas++;
			CM++;
		}
	}
	}
	cout << "Mario ha mangiato " << CM << " volte.\n" 
	<< "Ha mangiato " << CPas << " pastine/a\n" 
	<< "Mentre ha mangiato " << CPan << " panini/o" << endl;
	return 0;
}
