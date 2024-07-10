#include<iostream>
using namespace std;
int main(){
	int NUM, sott;
	cout << "Inserire un numero, deve essere pari: ";
	cin >> NUM;
	sott=NUM;
	while(NUM>0){
		NUM-=2;
	}
	if(NUM==0){
		NUM=sott;
	} else {
		cout << "Il numero inserito non e' pari." << endl;
		return 0;
	}
	for(NUM=NUM; NUM>=0; NUM-=2){
		cout << NUM << endl;
	}
}
