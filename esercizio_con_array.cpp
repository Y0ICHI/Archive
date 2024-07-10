#include<iostream>
using namespace std;
int main(){
	unsigned int dim=3;
	int i,V=0;
	int N[dim];
	for(i=0; i<=dim-1; i++){
		cout << "Inserire il " << i+1 << " numero.\n";
		cin >> N[i];
	}
	for(i=0; i<=dim-2; i++){
		if(N[i+1]<N[i])
		V=1;
	}
	if(V==1){
		cout << "I numeri inseriti non sono crescenti." << endl;
	} else {
		cout << "I numeri inseriti sono crescenti" << endl;
	}
	return 0;
}
