#include<iostream>
using namespace std;
int main(){
int NUM,N=0,C=0,F,D=0,L=0;
cout << "NUM" << endl;
cin >> NUM;
	while(D<NUM){
		L++;
		cout << "Tabella " << L << endl;
		while(C<10){
			N++;
			F=L*N;
			cout << L << "*" << N << " = " << F << endl;
			C++;
		}
		N=0;
		C=0;
		D++;
	}
}
