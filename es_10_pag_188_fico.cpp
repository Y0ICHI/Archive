#include<iostream>
using namespace std;
int main(){
	int i, conta =0;
	for(i==1; i<=100; i++){
		if(i==77){
			conta+=2;
			//cout << i << endl;
		} else {
			if(i==7 or i/10==7 or i%10==7){
				conta++;
				//cout << i << endl;
			}
		}
	}
	cout << conta;
}
