#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
	int C,B;
	srand(time(NULL));
	B = (rand()%270)+1;
	//cout << "B: " << B << endl;
	int N[B];
	for(C=0; C<B; C++){
		N[C]=(rand()%1000)+1;
	//	cout << N[C] << endl;;
	}
	C--;
	cout << "Valori ribaltati." << endl;
	while(C>=0){
		cout << C << endl << N[C] << endl;
		C--;
	}
}
