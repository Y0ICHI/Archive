#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

float CalMass(float vol){
	float massa, densita;
	densita = 2400;
	massa = densita*vol;
	
	return massa;
}

float Calpeso(float vol){
	float PesoSpecifico, peso;
	PesoSpecifico = 23540;
	peso = PesoSpecifico*vol;
	
	return peso;
}

int main(){
	float vol, Den, pSpe;
	float risultato1, risultato2;
	cout << "Inserire il volume del solido in vetro: ";
	cin >> vol;
	risultato1 = CalMass(vol);
	risultato2 = Calpeso(vol);
	cout << "La massa del solido in vetro \212 " << risultato1 << " chilogrammi" << endl;
	cout << "Il peso del solido in vetro \212 " << risultato2 << " chilogrammi";
}

