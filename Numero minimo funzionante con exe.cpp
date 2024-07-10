#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int N, N2=0, M=2147483647;
	cout << "English translation powered by DeepL because of my laziness lol\n -Lupo\nEnter the first number. (It must neccesarily be greater than 0 for the first time.)" << endl;
	cin >> N;
	while(N<=0){
		cout << "Error, enter another that is greater than 0." << endl;
		cin >> N;
	}
	if(N<M){
		M=N;
	}
	while(N>0){
		cout << "Enter the next number.\n Remember that if you do not want to keep entering numbers, simply enter the number 0." << endl;
		cin >> N;
	}
	if(N==0){
		cout << "The smallest number entered is " << M << endl;
		cout << "Press ENTER to close the programm...";
	cin.ignore();
	getchar();
		return 0;
	}
	if(N<M){
		M=N;
		N2=M;
	}
	}


