#include<iostream>
using namespace std;
int main(){
	int NUM, EXP, R, C, F;
	cout << "Inserire il numero: ";
	cin >> NUM;
	while(NUM<=0){
		cout << "\nInserire un numero valido. ";
		cin >> NUM;
	}
	cout << "Inserire il numero con cui fare alla EXP: ";
	cin >> EXP;
	while(EXP<=0){
		cout << "Non valido." << endl;
		cin >> EXP;
	}
	C=NUM;
	//R=1;
	EXP--;
	for(R=0; R<EXP; R++){
		NUM*=C;
		cout << "NUM: "<< NUM << endl << "R: " << R << endl;
	}
	/*while(R!=EXP){
		NUM*=C;
		R++;
		cout << "NUM: "<< NUM << endl << "R: " << R << endl;
	}*/
	cout << NUM;
}
