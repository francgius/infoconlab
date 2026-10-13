//sorting codes

#include <vector>
#include <iostream>
#include <random>
#include <string>
using namespace std;

int random(int a, int b){      //distribuzione uniforme di interi. a e b estremi
    static random_device rd;         //rende dispoibile la sua chiamata anche all'esterno della funzione
    static mt19937 gen(rd());
    uniform_int_distribution<int> dist(a, b);
    return dist(gen);
};

vector<int> generaArrayCasuale(int n, int minVal=-30, int maxVal=30){ //metti le virgole tra le variabili della funzione
    vector<int> A(n);
    for (int i=0; i <n ; i++){    //questa funzione riempie un vettore a (size=n) 
        A[i]= random(minVal, maxVal);     //di interi random
    }
    return A;
};

void selectionsort(vector<int>& A){          //richiede di utilizzare A iniziale (quello dato all'inizio della funzione
    for (auto i=0; i<A.size()-1; ++i){   
        auto minimo= A[i];    //definisce il primo numero ome minimo
        auto indiceminimo =i;
        for (auto j= i+1; j<A.size(); ++j){  //guarda i successivi per capire quale è il minimo effettivo
            if (A[j]< minimo){
                minimo = A[j];       //quel numero trovato è il nuovo minimo 
                indiceminimo= j;       //(attenzione all'ordine
            }
        }
        A[indiceminimo]= A[i];  //il minimo viene spostato alla casella da cui ha iniziato a contare
        A[i]= minimo;          
        }    //riprende a stabilire minimi e a spostarli fino alla penultima posizione
}

int main()
{ 
    constexpr auto minVal= -50;     //constexpr una variabile o una funzione può essere valutata a
    constexpr auto maxVal=  50;     // tempo di compilazione, cioè prima che il programma venga eseguito
    constexpr int N= 30;
    vector<int> A = generaArrayCasuale(N, minVal, maxVal);
    for ( auto x : A){           //ciclo O(n) che stampa tutti i valori di un array
        cout<< x<< " ";
    }

    cout << endl;
    auto B=A;
    cout <<endl<< "e ordinato diventa"<< endl;
    selectionsort(B);         //la funzione è void e non restituisce un vettore (cambia B tho)
    
    for (auto x : B ){
        cout  <<x<< " ";        
    }
    
    cout <<endl;
    return 0;
}

/*
int insertion sort(const vector<int>& A){    
    for (i=0; i<n-1; i++){
        if (A[i] >A[i+]) 
            A[i-1] = A[i]

    }
}
*/
