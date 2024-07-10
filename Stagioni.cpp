#include <iostream>
using namespace std;
int main(){
    
         int num, gior;
         cout << "dimmi il numero del mese." << endl;
        cin >> num;
        while(num<0 or num>13){
        cout << "valore non valido, dammene un altro" <<endl;
        cin >> num;
        }
        if (num>12 and num <2){
            cout << "la stagione e' l'inverno" <<endl;
        }
        else if(num=3){
            cout << "dimmi il giorno." <<endl;
            cin >> gior;
                if(gior>20){
                    cout << "la stagione e' la primavera" <<endl;
                }
        }
     if (num>3 and num <6){
        cout << "la stagione e' la primavera" <<endl;
    }
    else if(num=6){
        cout << "dimmi il giorno." <<endl;
        cin >> gior;
            if(gior>20){
                cout << "la stagione e' l'estate" <<endl;
            }
     if (num>6 and num <9){
        cout << "la stagione e' l'estate'" <<endl;
    }
    else if(num=6){
        cout << "dimmi il giorno." <<endl;
        cin >> gior;
            if(gior>20){
                cout << "la stagione e' l'autunno" <<endl;
            }
    if (num>9 and num <12){
        cout << "la stagione e' l'autunno'" <<endl;
    }
    else if(num=6){
        cout << "dimmi il giorno." <<endl;
        cin >> gior;
            if(gior>20){
                cout << "la stagione e' l'inverno" <<endl;
            }
    return 0;
}
}