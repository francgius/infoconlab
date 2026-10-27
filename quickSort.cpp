#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// per creare numeri casuali
#include <random>

/*


void QuickSort(vector<int> & A, int sx, int dx){
    if (sx < dx){
        int pivot= dx;
        int rango= Distribuzione(A, sx, pivot, dx);
        QuickSort(A, sx, rango-1);
        QuickSort(A, rango+1, dx);
    }
}


int Distribuzione(vector<int>& A, int sx, int px, int dx){
    swap(A[px], A[dx]);
    int i=sx;
    int j= dx-1;
    while (j<i){
    while (i<j && A[i]< A[dx]) i++;   //condizioni di bordo
    while (i<j && A[j]< A[dx]) j--;
    swap( A[i], A[j]);
    }

} */

using namespace std;

/* UTILITY */

int random(int a, int b){ // restituisce un numero random in [a..b]
static random_device rd; // per inizializzare il generatore
static mt19937 gen(rd()); // static evita di creare ogni volta il generatore a ogni chiamata
uniform_int_distribution<int> dist(a, b);

return dist(gen);
}

vector<int> generaArrayCasuale(int n, int minVal = -100, int maxVal = 100){ // accetta solo n > 0 oppure tutti gli argomenti
vector<int> A(n); // vettore di n interi da riempire
for (auto i = 0; i < n; i++){
A[i] = random(minVal,maxVal);
}
return A; // non fa la copia!
}

void printArray(const vector<int>& B){
for (auto x : B){
cout << x << " ";
}
cout << endl;
}


bool verificaOrdinamento3(const vector<int>& A){
    auto i=0;
    while ( i+1<A.size() && A[i]<= A[i+1]) ++i;  //quando non vale quella condizione stampa il numero in cui si è fermata
    return i+1 >= A.size();
}

/* DA COMPLETARE E FARE DEBUG */

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


void QuickSort(vector<int>& A, int sx, int dx) {
if (sx < dx) {
int pivot = dx; // può essere qualunque valore in [sx .. dx]
int rango = Distribuzione(A, sx, pivot, dx);
QuickSort(A, sx, rango - 1);
QuickSort(A, rango + 1, dx);
}
}




int main(){
constexpr auto minVal = -100;
constexpr auto maxVal = 100;

vector<int> A = generaArrayCasuale(30, minVal, maxVal);
//vector<int> A{15, 7, 8, 3, 10, 5, 16};
int N = A.size();
printArray(A);
QuickSort(A, 0, N-1);
printArray(A);
if (!verificaOrdinamento3(A)){
            cout<< "non è ordinato"<</* "errore in "<< i <<*/ endl;
        }
    else cout << "è ordinato"<< endl;
return 0;
}