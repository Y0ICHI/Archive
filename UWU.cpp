#include<iostream>
using namespace std;
int main(){
	int N=1,C=0;
	while(C<=5){
		cout << N << " ";
		N+=2;
		C++;
	}
	while(N<99){
		C=0;
		cout << endl;
		while(C<=5){
			if(N>=99){
				C=100;
			}
			cout << N << " ";
			N+=2;
			C++;
		}
	}
}


