#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

const int MAX_VOTI = 20;

//Informazioni della materia
typedef struct{
	string Materia;
    char tipoVoto;
    short quadrimestre;
    float punteggio;
} voto;

//Informazioni studente
typedef struct{
    string Nome;
    string Cognome;
    voto votiStudente[MAX_VOTI];
} studente;

//Informazioni da salvare: numero di materie, voti, etc
typedef struct{
	int Voti[MAX_VOTI];
	short Quadrimestre[MAX_VOTI];
	string Materia[MAX_VOTI];
	char tipoVoto[MAX_VOTI];
} save;


void Inserimento(string MateInserita, studente Studente[], int dim, int& contatore){
    bool trovato = false;
    for(int i = 0; i < dim && !trovato; i++){
        for(int j = 0; j < MAX_VOTI && !trovato; j++){
            if(MateInserita == Studente[i].votiStudente[j].Materia){
                cout << "Trovato uguaglianza." << endl;
                trovato = true;
            }
        }
    }
    if(!trovato)
    contatore++;
    cout << "Contatore: " << contatore << endl;
	}

void Caricamento(studente Studente[], int dim){
	int scelta, contatore = 0;
	for(int i=0; i<dim; i++){
		cout << "Inserire il nome dello studente: ";
		cin >> Studente[i].Nome;
		cout << "\nInserire il cognome dello studente: ";
		cin >> Studente[i].Cognome;
		cout << "\nQuanti voti devi inserire? ";
		cin >> scelta;
		while(scelta<=0 || scelta>MAX_VOTI){
			cout << "\nErrore. Inserirne un altro.";
			cin >> scelta;
		}
		//Salvare numero di voti
		cout << "Inserire il quadrimestre. (1= Primo, 2 = Secondo)" << endl;
		cin >> Studente[i].votiStudente[i].quadrimestre;
		while(Studente[i].votiStudente[i].quadrimestre != 1 and Studente[i].votiStudente[i].quadrimestre != 2){
			cout << "Non valido, inserirne un altro." << endl;
			cin >> Studente[i].votiStudente[i].quadrimestre;
		}
		//Salvare il quadrimeste dove stanno inseriti i voti
		cout << "Per quale materia vuoi inserire il voto?" << endl;
		cin >> Studente[i].votiStudente[i].Materia;
		Inserimento(Studente[i].votiStudente[i].Materia, Studente, i, contatore);
		//Salvare la materia, se non è stata mai inserita (applicare una cosa del genere per il quadrimestre, forse)
		cout << "Che tipo di voto è? (S = Scritto, O = Orale, P = Pratica)" << endl;
		cin >> Studente[i].votiStudente[i].tipoVoto;
		while(Studente[i].votiStudente[i].tipoVoto!='S' and Studente[i].votiStudente[i].tipoVoto!='O' and Studente[i].votiStudente[i].tipoVoto!='P'){
			cout << "Errore. Riprovare." << endl;
			cin >> Studente[i].votiStudente[i].tipoVoto;
		}
		//Salvare il tipo di voto, non più di una volta, penso
		for(int j=0; j<scelta; j++){
			cout << "Inserire il " << j+1 << " voto." << endl;
			cin >> Studente[j].votiStudente[j].punteggio;
		}
	}
}

//Scambi
void BubbleSort(studente Studente[], int dim){
	for(int i=0; i<dim-1; i++){
        bool scambi = false;
        for(int j=0; j<dim-i-1; j++){
            if(Studente[i].votiStudente[j].Materia > Studente[i].votiStudente[j+1].Materia){
                scambi = true;
                voto t = Studente[i].votiStudente[j];
                Studente[i].votiStudente[j] = Studente[i].votiStudente[j+1];
                Studente[i].votiStudente[j+1] = t;
            }
        }
//        if(!scambi) break;
    }
}

void Media(studente Studente[], int dim, int contatore){
	int temp = contatore;
	BubbleSort(Studente, dim);
		for(int i = 0; i<dim; i++){
			for(int j = 0; j<dim && contatore == temp; j++){
				//Somma i numeri di una materia dopo averla ordinata e lo fa' finchè il contatore non aumenta a causa del numero non coincidente
				
			}
		}
	}

int main(){
	int dim;
	cout << "Dim" << endl;
	cin >> dim;
	while(dim<=0){
		cout << "Errore" << endl;
		cin >> dim;
	}
	studente Studente[dim];
	Caricamento(Studente, dim);
}

