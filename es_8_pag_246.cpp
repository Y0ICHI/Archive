#include<iostream>
#include<time.h>
using namespace std;
int main(){
	int C,B;
	cout << "Quanti numeri devi inserire?" << endl;
	cin >> B;
	int N[B];
	for(C=0; C<B; C++){
		cout << C << "° numero." << endl;
		cin>>N[C];
	}
	C--;
	cout << "Ecco i valori, ribaltati." << endl;
	while(C>=0){
		cout << N[C] << endl;
		C--;
	}
}
