#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
	int i, contaP=0, contaD=0, dimensione=30, p=0, d=0;
	int Vet[dimensione];
	srand(time(NULL));
	for(i=0; i<=dimensione-1; i++){
		Vet[i]=rand()%100;
		if(Vet[i]%2==0)
			contaP++;
		else
			contaD++;
	}
	int VetP[contaP];
	int VetD[contaD];
	for(i=0; i<=dimensione-1; i++){
		if(Vet[i]%2==0){
			VetP[p]=Vet[i];
			p++;
		}else{
			VetD[d]=Vet[i];
			d++;
		}
	cout<<"i numeri pari sono: "<<endl;
	for(i=0; i<=contaP-1; i++)
		cout<<VetP[i]<<"  ";	
	cout<<endl<<"i numeri dispari sono: "<<endl;
	for(i=0; i<=contaD-1; i++)
		cout<<VetD[i]<<"  ";
}
}

