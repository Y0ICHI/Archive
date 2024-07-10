#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
	srand(time(NULL));
	int max=0, min, media=0, i;
	unsigned int dim = 12;
	int mesi[dim];
	int presenza[dim];
	cout << "Lista presenze in tutto l'anno." << endl;
		for(i=0; i<=dim-1; i++){
			presenza[i]=rand() % 100+20;
	cout << i+1 << " " << presenza[i] << endl;
	}
			min = presenza[0];
		for(i=0; i<=dim-1; i++)
			media+=presenza[i];
			media/=dim;
	cout << "Media presenze dell'intero anno: " << media << endl;
			media = 0;
		for(i=6-1; i<=8-1; i++)
			media+=presenza[i];
			media/=3;
	cout << "Presenze nei mesi estivi: " << media << endl;
		for(i=0; i<=dim-1; i++){
			if(max<presenza[i])
				max=presenza[i];
			if(min>presenza[i])
				min=presenza[i];
	}
	cout << "Max presenze: " << max << endl << "Min presenze: " << min << endl;
			media=0;
		for(i=0; i<=dim-1; i++){
			if(i>=6-1 and i<=8-1){
			} else {
				media+=presenza[i];
			}
		}
			media/=dim-3;
	cout << "Media presenze, esclusi i mesi estivi: " << media;
	return 0;
}


