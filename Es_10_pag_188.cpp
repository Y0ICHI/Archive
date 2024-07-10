#include<iostream>
using namespace std;
int main(){
	int NUM, C=1;
	for(NUM=7; NUM<=70; NUM+=10)
	C++;
	for(NUM=71; NUM<=79; NUM++)
	C++;
	for(NUM=87; NUM<=100; NUM+=10)
	C++;
	cout << C;
}


