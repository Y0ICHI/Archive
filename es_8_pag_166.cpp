#include<iostream>
using namespace std;
int main(){
	int NUM=0,NUM2=1,C=0,R;
	cout << "Dammi il numero." << endl;
	cin >> R;
	while(C<R){
		C++;
		NUM+=NUM2;
		NUM2++;
	}
	NUM*=2;
	cout << NUM;
}
