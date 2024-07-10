#include<iostream>
using namespace std;
int main() {
	int N = 10, S = 0;
	while (N>=10 and N<=100){
		S=S+N;
		N=N+5;
	}
	cout << S;
}
