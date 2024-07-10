#include<iostream>
using namespace std;
int main(){
	float A, B, S=0, R;
	cout << "Inserire il primo numero." << endl;
	cin >> A;
	while(A<0){
		cout << "Numero inserito non valido, inserirne un altro." << endl;
		cin >> A;
	}
	R=A;
	cout << "Inserire il secondo numero." << endl;
	cin >> B;
	while(B<0){
		cout << "Numero inserito non valido, inserirne un altro." << endl;
		cin >> B;
	}
	while(R>=B){
		R=R-B;
		S++;
	}
	cout << "Il quoziente e': " << S << endl; 
	cout << "Mentre il resto e' " << R;
	return 0; 
}


