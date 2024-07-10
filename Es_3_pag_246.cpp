#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
	int max=50, min=999, T, SMax, SMax1, SMin, SMin1;
	const int C=10-1;
	T=C;
	srand(time(NULL));
	int N[C];
	//Genera numeri casuali
	for(T; T>=0; T--){
		N[T] = (rand()%270)+1;
		cout << N[T] << endl; //Visualizzazione dei numeri casuali
	}
	while(T<10){
	if(N[T]>max){
		max=N[T];
		SMax=max;
		SMax1=T;
	}
	if(N[T]<min){
		min=N[T];
		SMin=min;
		SMin1=T;
	}
	T++; 
}
cout << "Max: " << max << endl;
cout << "Min: " << min << endl;
//cout << "T: " << T << endl;
while(T>0){
	if(T==SMin){
		max=SMin;
		N[SMin1]=max;
	}
	if(T==SMax){
		min=SMax;
		N[SMax1]=min;
	}
	T--;
}
T=0;
while(T>10){
cout << N[T] << endl;
T--;
}
}
