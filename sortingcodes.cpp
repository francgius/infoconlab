//sorting codes 

#include <vector>
#include <iostream>
#include <random>
#include <string>
#include <chrono>
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

void printArray(vector<int>& A){
    for (auto x: A){
        cout <<x << " ";
    }
    cout << endl;
}  

void selectionsort(vector<int>& A){          //richiede di utilizzare A iniziale (quello dato all'inizio della funzione
    for (auto i=0; i+1<A.size(); ++i){
        auto minimo= A[i];
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

void insertionsort(vector<int>& A){
    for ( int i =1; i<A.size(); ++i){
        auto t= A[i];
        auto j=i;
        while ( j > 0 && t<A[j-1]){
            A[j]= A[j-1];
            --j;
        }
    A[j]=t;
    }
}

int Distribuzione(vector<int>& A, int sx, int px, int dx) {
    swap(A[px], A[dx]);
    int pivot = A[dx];
    int i = sx;
    int j = dx - 1;

    while (i <= j) {
        while (i <= j && A[i] < pivot) i++;
        while (i <= j && A[j] >= pivot) j--;

        if (i < j) {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }

    swap(A[i], A[dx]);
    return i;
}


void quicksort_deterministico(vector<int>& A, int sx, int dx) {
if (sx < dx) {
int pivot = dx; // può essere qualunque valore in [sx .. dx]
int rango = Distribuzione(A, sx, pivot, dx);
quicksort_deterministico(A, sx, rango - 1);
quicksort_deterministico(A, rango + 1, dx);
}
}

void quicksort_deterministico(vector<int>& A){
    quicksort_deterministico(A, 0, A.size()-1);
}

void quicksort_random(vector<int>& A, int sx, int dx){
    if (sx<dx){
    int pivot = sx + random(0, (dx-sx));
    int rango= Distribuzione(A, sx, pivot, dx);
    quicksort_random(A, sx, rango - 1);
    quicksort_random(A, rango + 1, dx);
    }
}

void quicksort_random(vector<int>& A){
    quicksort_random(A, 0, A.size()-1);
}
//verifiche

bool verificaOrdinamento1(const vector<int>& A){
//devono valere tutte le disuguaglianze di della definizione 
    bool risultato = true;
    for (int i =0; i+1<A.size(); ++i){
        risultato = risultato && A[i+1]>= A[i];
    }
    return risultato;
};

bool verificaOrdinamento2(const vector<int>& A){
    for (auto i =0; i+1<A.size() ; ++i){
        if (A[i]>A[i+1]){
           return false;
        }    
    }
    return true;
}

bool verificaOrdinamento3(const vector<int>& A){
    auto i=0;
    while ( i+1<A.size() && A[i]<= A[i+1]) ++i;  //quando non vale quella condizione stampa il numero in cui si è fermata
    return i+1 >= A.size();
}

int main()
{    
    using FuncPtr =void (*)(vector<int> &);
    const vector<FuncPtr> funzioni ={
        selectionsort,
        insertionsort, 
        quicksort_deterministico,
        quicksort_random
    };
    const vector<string> nomi ={
        "selection sort",
        "insertion sort", 
        "quick sort deterministico", 
        "quick sort random"
    };
    const vector<string> complessita ={
        "quadratica",
        "quadratica al caso pessimo ",
        "quadratico al caso pessimo",
        "lineare logaritmico"
    };
    constexpr auto minVal= -50;
    constexpr auto maxVal=  50;
    constexpr int N= 30; 
    vector<int> A = generaArrayCasuale(N, minVal, maxVal);
        if (N<31){
            printArray(A);
        };
        cout <<endl<< "e ordinato diventa"<< endl;
    for (int i = 0;i <funzioni.size(); ++i){
        const auto f=funzioni[i];
        const auto & costo = complessita[i];
        auto B=A;
        auto start= chrono::steady_clock::now();

        f(B);

        auto stop= chrono::steady_clock::now();
        auto durata= chrono::duration_cast<chrono::microseconds>(stop -start);
    
    if (N<31){
        printArray(B);
        }
       // cout <<endl;
    if (!verificaOrdinamento3(B)){
            cout<< "non è ordinato"<< "errore in "<< nomi[i]<< endl;
        }
    else cout << "è ordinato"<< endl;
    cout << "Ordinamento (tempo " << costo <<"): " << "["<< durata.count()<< "microsecondi]"<< endl<<endl;
    }
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
