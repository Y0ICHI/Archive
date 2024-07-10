#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

bool Duplicato(int dim, int n, int n2[]){
	int i;
	bool trovato = false;
	for(i=0; i<=dim-1; i++){
		if(n2[i] == n){
			trovato = true;
		}
	}
	return trovato;
}

void Caricamento(int dim, int n[]){
	int i;
	for(i=0; i<=dim-1; i++){
		cout << i+1 << " Inserire il posto." << endl;
		cin >> n[i];
		while(Duplicato(i, n[i], n) == true){
			cout << i+1 << " Errore!\n Inserire di nuovo il posto." << endl;
			cin >> n[i];
		}
	}
	return;
}

void Caricamento(int dim, string classe[]){
	int i;
	for(i=0; i<= dim-1; i++){
		cout << i+1 << " Inserire la classe (per favore inserire tutto in minuscolo o senza errori di punteggiatura)." << endl;
		cout << "Le classi disponibili sono: prima, seconda, economica" << endl;
		cin >> classe[i];
		while(classe[i]!="prima" and classe[i]!="seconda" and classe[i]!="economica"){
			cout << i+1 << " Errore, riprovare!\n Le classi disponibili sono: prima, seconda, economica" << endl;
			cin >> classe[i];
		}
	}
	return;
}

void Caricamento(int dim, float Prezzo[]){
	int i;
	for(i=0; i<=dim-1; i++){
		cout << i+1 << " Inserire il prezzo di vendita." << endl;
		cin >> Prezzo[i];
		while(Prezzo[i]<0){
			cout << i+1 << " Errore, non può essere negativo." << endl;
			cin >> Prezzo[i];
		}
	}
	return;
}

void Caricamento(int dim, bool prenotato[]){
	int i;
	string scelta;
	for(i=0; i<=dim-1; i++){
		cout << i+1 << " \212 prenotato? (si/no)" << endl;
		cin >> scelta;
		while(scelta!="si" and scelta!="no" and scelta!="n" and scelta!="y"){
			cout << i+1 << " Errore, riprovare.\nTIP: Puoi scegliere y oppure n invece di si o no!" << endl;
			cin >> scelta;
		}
		if(scelta=="si" or scelta=="y"){
			prenotato[i]=true;
		} else {
			prenotato[i]=false;
		}
	}
	return;
}

void cercaClasse(int dim, string classe[], string cerca, int codice[]){
	int i, l=0;
	for(i=0; i<=dim-1; i++){
		if(cerca==classe[i]){
			cout << "Classe trovata!\nIl numero \212 " << codice[i] << endl;
			l=1;
		}
		if(l=0){
			cout << "Nessun posto trovato per la classe scelta." << endl;
		}
	}
	return;
}

bool controlloPrenotato(int dim, int posto[], int cercaPosto, bool prenotazione[]){
	bool prenotato = false, trovato = false;
	int i=-1;
	while(i<=dim-1 and trovato == false){
		i++;
		if(cercaPosto == posto[i]){
			prenotato = prenotazione[i];
			trovato = true;
		}
	}
	return prenotato;
}

int cercaPosto(int dim, int posto[], int cercaPosto, bool prenotato[]){
	int i=-1, postotrovato;
	bool trovato = false, controllaPrenotato = false;
	while(i<=dim-2 and trovato==false){
		i++;
		if(cercaPosto == posto[i]){
			trovato = true;
		}
	}
	if(trovato == true){
		controllaPrenotato = controlloPrenotato(dim, posto, cercaPosto, prenotato);
	}
	if(trovato == true and controllaPrenotato == false){
		postotrovato = i;
	} else {
		postotrovato = -1;
	}
	return postotrovato;
}
// Vecchio bubble
/*void Ordinamento(int dim, int coso1[], string coso2[], float coso3[], bool coso4[]){
	int i, j, s, t;
	string t1;
	float t2;
	bool t3;
	bool scambi = true;
	while(scambi==true){
		scambi = false;
		for(i=0; i<=dim-2; i++){
			if(coso1[i]>coso1[i+1]){
				scambi = true;
				t = coso1[i];
				coso1[i] = coso1[i+1];
				coso1[i+1] = t;
		
				t1 = coso2[i];
				coso2[i] = coso2[i+1];
				coso2[i+1] = t1;
		
				t2 = coso3[i];
				coso3[i] = coso3[i+1];
				coso3[i+1] = t2;
		
				t3 = coso4[i];
				coso4[i] = coso4[i+1];
				coso4[i+1] = t3;
			}
		}
	}
}
*/

void Ordinamento(int dim, int coso1[], string coso2[], float coso3[], bool coso4[]){
	int i, j, s, t, k, ultimo;
	string t1;
	float t2;
	bool t3;
	ultimo = dim-1;
	k = ultimo;
	bool scambi = true;
	while(scambi==true){
		k = ultimo;
		scambi = false;
		for(i=0; i<=k-1; i++){
			if(coso1[i]>coso1[i+1]){
				scambi = true;
				ultimo = i;
				
				t = coso1[i];
				coso1[i] = coso1[i+1];
				coso1[i+1] = t;
		
				t1 = coso2[i];
				coso2[i] = coso2[i+1];
				coso2[i+1] = t1;
		
				t2 = coso3[i];
				coso3[i] = coso3[i+1];
				coso3[i+1] = t2;
		
				t3 = coso4[i];
				coso4[i] = coso4[i+1];
				coso4[i+1] = t3;
			}
		}
	}
}

void rimozione(int& dim, int pos, int coso1[], string coso2[], float coso3[], bool coso4[]){
	int i;
	for(i=pos; i<=dim-2; i++){
		coso1[i]=coso1[i+1];
		coso2[i]=coso2[i+1];
		coso3[i]=coso3[i+1];
		coso4[i]=coso4[i+1];
	}
	dim--;
}
/*
IL MAIN è QUI!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
IL MAIN è QUI!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
IL MAIN è QUI!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
IL MAIN è QUI!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
IL MAIN è QUI!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
IL MAIN è QUI!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

int main(){
	int dim, MaxDim = 50, z;
	cout << "Inserire la dimensione" << endl;
	cin >> dim;
	while(dim<=0 and dim>MaxDim){
		cout << "Inserire un altra dimensione."  << endl;
		cin >> dim;
	}
	int NumPosto[dim];
	Caricamento(dim, NumPosto);
	
	string Classe[dim];
	Caricamento(dim, Classe);
	
	float Prezzo[dim];
	Caricamento(dim, Prezzo);
	
	bool Prenotato[dim];
	Caricamento(dim, Prenotato);
	
	string cClasse;
	cout << "Inserire la classe da cercare." << endl;
	cin >> cClasse;
	while(cClasse != "prima" and cClasse != "seconda" and cClasse!= "economica"){
		cout << "Errore, inserire una classe valida.\nLe classi valide: prima, seconda, economica." << endl;
		cin >> cClasse;
	}
	cercaClasse(dim, Classe, cClasse, NumPosto);
	
	bool stop = false;
	string scelta;
	float cassa = 0;
	int cercaPosta, trovatino;
	while(stop==false){
		cout << "Inserire il posto interessato." << endl;
		cin >> cercaPosta;
		trovatino = cercaPosto(dim, NumPosto, cercaPosta, Prenotato);
		if(trovatino!=-1){
			cout << "Posto trovato e venduto con successo!" << endl;
			cassa+=Prezzo[trovatino];
			rimozione(dim, trovatino, NumPosto, Classe, Prezzo, Prenotato);
		} else {
			cout << "Il posto cerca non esiste o non è disponibile per la vendita!" << endl;
		}
		cout << "Continuare la ricerca? (si/no)" << endl;
		cin >> scelta;
		while(scelta!="si" and scelta!="no"){
			cout << "Riprovare." << endl;
			cin >> scelta;
		}
		if(scelta=="no"){
			stop = true;
			cout << "Incasso totale: " << cassa << "€" << endl;
			cout << "Posti prenotati ma non venduti: " << endl;
			for(z=0; z<=dim-1; z++){
				if(Prenotato[z] == true){
					cout << "Posto: " << NumPosto[z] << " Classe: " << Classe[z] << " Prezzo: " << Prezzo[z] << "€" << endl;
				}
			}
		}
	}
	Ordinamento(dim, NumPosto, Classe, Prezzo, Prenotato);
	cout << "Posti non prenotati e non venduti." << endl;
	for(z=0; z<=dim-1; z++){
		if(Prenotato[z] == false){
			cout << "Posto: " << NumPosto[z] << " Classe: " << Classe[z] << " Prezzo: " << Prezzo[z] << "€" << endl;
		}
	}
	return 0;	
}
