#include<iostream>
using namespace std;
int main(){
	int NUM, S,L;
	cout << "Inserire il primo numero: ";
	cin >> NUM;
	cout << "Inserire il secondo numero: ";
	cin >> S;
	L=NUM;
	for(S-=2; S>=0; S--)
		NUM+=L;
	cout << NUM;
}


