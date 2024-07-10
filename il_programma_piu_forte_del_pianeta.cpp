#include <iostream>
using namespace std;
int main(){
	float dimensione;
	int zona, prezzo, percentuale;
	cout << "inserire la zona" << endl;
	cin >> zona;
	switch(zona){
		case 1:
			prezzo = 1500;
			cout << "il prezzo e di:" << prezzo <<"euro"<< endl;
			break;
		case 2:
			prezzo = 1200;
			cout << "il prezzo e di:" << prezzo <<"euro"<< endl;
			break;
		case 3:
			prezzo = 1400;
			cout << "il prezzo e di:" << prezzo <<"euro"<< endl;
			break;
		case 4:
			prezzo = 1300;
			cout << "il prezzo e di:" << prezzo <<"euro"<< endl;
			break;
		case 5:
			prezzo = 1000;
			cout << "il prezzo e di:" << prezzo <<"euro"<< endl;
			break;
		default:{
		    cout << "valore zona non valido" << endl;
		    break;
		}
		    
		
	}
	cout << "immetti il valore di X" << endl;
	cin >> percentuale;
	if (percentuale<0 || percentuale >100){
		cout << "valore non valido" <<endl;
	}else{
		prezzo = prezzo + ((prezzo/100)*percentuale);
		cout << "il prezzo finale e di:" << prezzo << "euro" << endl;
	}
	

}
