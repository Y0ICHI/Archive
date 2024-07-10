#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
using namespace std;

typedef struct{
	float base, altezza, lato[2];
} triangolo;

typedef struct{
	float base, altezza;
} rettangolo;

typedef struct{
	float lato;
} quadrato;

typedef struct{
	float raggio;
} cerchio;

void CalcolcoTriangolo(triangolo Triangolo){
	cout << "Area triangolo: " << (Triangolo.base*Triangolo.altezza)/2 << endl;
	cout << "Perimetro triangolo: " << (Triangolo.base+Triangolo.lato[0]+Triangolo.lato[1]) << endl;
}

void CalcoloRettangolo(rettangolo Rettangolo){
	cout << "Area rettangolo: " << Rettangolo.base*Rettangolo.altezza << endl;
	cout << "Perimetro rettangolo: " << (Rettangolo.base+Rettangolo.altezza)*2 << endl;
}

void CalcoloQuadrato(quadrato Quadrato){
	cout << "Area quadrato: " << Quadrato.lato*Quadrato.lato << endl;
	cout << "Perimetro quadrato: " << Quadrato.lato*4 << endl;
}

void CalcoloCerchio(cerchio Cerchio){
	cout << "Area cerchio:" << M_PI*Cerchio.raggio*Cerchio.raggio << endl;
	cout << "Perimetro cerchio: " << M_PI*Cerchio.raggio*2 << endl;
}

void CaricamentoTriangolo(triangolo& Triangolo){
	cout << "\nInserire la base del triangolo: ";
	cin >> Triangolo.base;
	cout << "\nInserire l'altezza del triangolo: ";
	cin >> Triangolo.altezza;
	cout << "\nInserire il primo lato (non la base!): ";
	cin >> Triangolo.lato[0];
	cout << "\nInserire il secondo lato (non la base!): ";
	cin >> Triangolo.lato[1];
}

void CaricamentoRettangolo(rettangolo& Rettangolo){
	cout << "\nInserire la base del rettangolo: ";
	cin >> Rettangolo.base;
	cout << "\nInserire l'altezza del rettangolo: ";
	cin >> Rettangolo.altezza;
}

void CaricamentoQuadrato(quadrato& Quadrato){
	cout << "\nInserire il lato del quadrato :) : ";
	cin >> Quadrato.lato;
}

void CaricamentoCerchio(cerchio& Cerchio){
	cout << "Inserire il raggio del cerchio: ";
	cin >> Cerchio.raggio;
}


int main(){
	char Cerca;
	cout << "Di che cosa vuoi calcolare l'area e perimetro? (T = Triangolo, R = Rettangolo, Q = Quadrato, C = Cerchio)" << endl;
	cin >> Cerca;
	while(Cerca!='T' and Cerca!='R' and Cerca!='Q' and Cerca!='C'){
		cout << "Non valido." << endl;
		cin >> Cerca;
	}
	if(Cerca=='T'){
		triangolo Triangolo;
		CaricamentoTriangolo(Triangolo);
		CalcolcoTriangolo(Triangolo);
	} else if(Cerca=='R'){
		rettangolo Rettangolo;
		CaricamentoRettangolo(Rettangolo);
		CalcoloRettangolo(Rettangolo);
	} else if(Cerca=='Q'){
		quadrato Quadrato;
		CaricamentoQuadrato(Quadrato);
		CalcoloQuadrato(Quadrato);
	} else {
		cerchio Cerchio;
		CaricamentoCerchio(Cerchio);
		CalcoloCerchio(Cerchio);
	}
	system("pause");
	return 0;
}


