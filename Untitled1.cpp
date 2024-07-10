#include <iostream>
#include <cstring>

using namespace std;

int main(){
	const int Pc = 1500, P1 = 1200, P2 = 1400, P3 = 1300, Pp = 1000;
	float x, SpesaTot, Sup;
	int moltiplicatore;
	char zona;	
	bool errore = false;
	cout<<"Fornire la superficie della casa (m^2): ";
	cin>>Sup;
	if (Sup<=0){
		cout<<"Il valore non è corretto.";
	}else{
		cout<<"Inserire la zona di appartenenza dell'appartamento (C - Centro, 1 - Zona1, 2 - Zona2, 3- Zona3, P - Periferia):\n";
		cin>>zona;
		zona = toupper(zona);
		switch(zona){
			case 'C':
				moltiplicatore = Pc;
				break;
			case '1':
				moltiplicatore = P1;
				break;
			case '2':
				moltiplicatore = P2;
				break;
			case '3':
				moltiplicatore = P3;
				break;
			case 'P':
				moltiplicatore = Pp;
				break;
			default:
				cout<<"Valore della zona non corretto.";	
				errore = true;		
		}
		if (errore = false){
		SpesaTot = Sup * moltiplicatore;
		cout<<"La spesa totale e': " <<SpesaTot;
		
		cout<<"\nFornire un valore percentuale per la provvigione spettante l'agenzia: ";
		cin>>x;
		if (x>=0 && x<=100){
			SpesaTot = SpesaTot + ((SpesaTot * x)/100);
			cout<<"La spesa totale ora ammonta a:" <<SpesaTot; 
		}else{
			cout<<"Il valore della percentuale non e' compreso.";
		}
	}
	}
}
