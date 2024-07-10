#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
	int N, i, N2,L=0;
	cin >> N2;
int vetA[N2];
srand(time(NULL));
	for(i=0; i<=N2; i++){
		vetA[i]=(rand() % 120) + 1;
		cout << "vetA[" << i << "]" << " " << vetA[i] << endl;
		while(L<vetA[i]){
			cout << "*";
			L++;
		}
		cout << endl;
		L=0;
	}
	return 0;
}
