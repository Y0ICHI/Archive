#include<iostream>
using namespace std;
int main(){
	int N, CD = 0, i, l = 0;
	cout << "Inserire il numero." << endl;
	cin >> N;
	while(N<0 || N> 10000){
		cout << "Errore, inserire un altro numero." << endl;
		cin >> N;
	}
	for(i=1; i<=N; i++){
		if (N%i==0){
			CD++;
		}
	}
	int D[CD];
	for(i=1; i<=N; i++){
		if(N%i==0){
		D[l] = i;
		l++;
	}
	}
	l=0;
	for(i=1; i<=CD; i++){
		cout << D[l] << endl;
		l++;
	}
	return 0;
}


