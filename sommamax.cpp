//pages.di.unipi.it ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIID3xq3k730X+1UZ/hjymRiPKgG1S+ZYQxDUmdDhM1xj
//somma massima costo lineare
#include <iostream>
#include <vector>
#include <random> //PER CREARE NUMERI CASUALI
#include <chrono> //PER MISURARE IL TEMPO DI ESECUZIONE
using namespace std;


//costo 3 ----------------------------------
int sommamassima3(const vector<int>& B ) {
    auto maxs = 0;
        for (auto i =0; i<B.size(); i++){
        for (auto j= i; j< B.size(); j++){
        auto somma = 0;
        for (auto k=i; k<=j; k++){
            somma += B[k];
        if (somma> maxs) {
            maxs = somma;

        }   
    }    
        }
    }
    return maxs;
}
//costo 2 ----------------------------------
int sommamassima2 (const vector<int>& B) {
    auto maxs = 0;
    for (auto i =0; i<B.size(); i++){ 
        auto somma = 0;
        for (auto j= i; j< B.size(); j++){      
            somma += B[j];
        if (somma> maxs) {
            maxs = somma;
        }   
        }       
    }
    return maxs;
}

//costo1 ----------------------------------
int sommamassima1(const vector<int>& B){
    auto maxs=0;
    auto somma=0;

    for (auto j = 0; j < B.size(); j++){
        if (somma > 0)
            somma += B[j];
        else 
            somma = B[j];
        
        if (somma > maxs)
            maxs = somma;
        
    }
    return maxs;
}

int random(int a, int b){
    static random_device rd;
    static mt19937 gen(rd());   //static fa in modo che questi oggetti esistano anche al di fuori
                                // (durante e dopo) la funzione random
    uniform_int_distribution<int> dist(a, b);

    return dist(gen);
}

vector<int> generaArrayCasuale(int n, int minVal, int maxVal){
    vector<int> A(n);
    for (auto i =0; i<n ; i++){
        A[i] =random(minVal, maxVal);
    }
    return A;
}




void printVector(const vector<int>& B) {
   for (auto x: B) {
    cout << x<< " ";
   }
   cout << endl;
}

int main()
{
 //   vector<int> A = {4, -6, 3, 5, -2, 1, -4, 6, -3};
    constexpr auto N= 100;
    constexpr auto minVal= -500;
    constexpr auto maxVal=  500;
    vector<int> A = generaArrayCasuale(N, minVal, maxVal);
    A[0] =5; A[1]= -5;
    if (N<100) printVector(A);
    
    using FuncPtr = int (*)(const vector<int> &);
    FuncPtr funzioni[] = {
        sommamassima1,    //considera anche l'ordine
        sommamassima2,
        sommamassima3
    };
    string complessita[] = {
        "lineare",
        "quadratica",
        "cubica"
    };

    for (auto i=0; i <3; i++){
        auto f=funzioni[i];
        auto costo = complessita[i];
        auto start = chrono::high_resolution_clock::now();  //inizio tempo: now!
        auto risultato = f(A);
        auto stop = chrono::high_resolution_clock::now();
        auto durata = chrono::duration_cast<chrono::microseconds>(stop- start);      
        
        cout << "Somma massima (tempo " <<costo<<") = " << risultato << "[durata " << durata.count() << " microsecondi]" <<endl;
    }
    return 0;
}

/*
auto maxSegmentSum3 =  sommamassima3(A);
cout << "il segmento di somma massima dell'alg di costo 3 di A è: "<< maxSegmentSum3<< endl;
auto maxSegmentSum2 = sommamassima2(A);
cout << "il segmento di somma massima dell'alg di costo 2 di A è: "<< maxSegmentSum2<< endl;
auto maxSegmentSum1 = sommamassima1(A);
cout << "il segmento di somma massima dell'alg di costo 1 di A è: "<< maxSegmentSum1<< endl;
    return 0;
}
*/
