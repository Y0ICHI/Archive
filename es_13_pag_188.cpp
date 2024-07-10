#include<iostream>
using namespace std;
int main(){
	int C=0,N=0;
	//cornice 12
	while(C<12){
		cout << "*";
		C++;
	}
	while(N<10){
		C=0;
		cout << "\n*";
		while(C<10){
			cout << " ";
			C++;
		}
		cout << "*";
		N++;
	}
	C=0;
	cout << endl;
	while(C<12){
		cout << "*";
		C++;
	}
	//ripristino variabili e spazio
			C=0, N=0;
			cout << endl;
			cout << endl;
	//cornice 8
	while(C<8){
		cout << "*";
		C++;
	}
	while(N<6){
		C=0;
		cout << "\n*";
		while(C<6){
			cout << " ";
			C++;
		}
		cout << "*";
		N++;
	}
	C=0;
	cout << endl;
	while(C<8){
		cout << "*";
		C++;
	}
	
			C=0, N=0;
			cout << endl;
			cout << endl;
	//cornice 4
	while(C<4){
		cout << "*";
		C++;
	}
	while(N<2){
		C=0;
		cout << "\n*";
		while(C<2){
			cout << " ";
			C++;
		}
		cout << "*";
		N++;
	}
	C=0;
	cout << endl;
	while(C<4){
		cout << "*";
		C++;
	}
}
