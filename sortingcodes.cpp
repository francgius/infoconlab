//sorting codes 

#include <vector>
#include <iostream>
#include <random>
#include <string>
#include <chrono>
using namespace std;

int random(int a, int b){
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> dist(a, b);
    return dist(gen);
};

vector<int> generaArrayCasuale(int n, int minVal, int maxVal){
    vector<int> A(n);
    for (int i=0; i <n ; i++){
        A[i]= random(minVal, maxVal);
    }
    return A;
};

void printArray(vector<int>& A){
    for (auto x: A){
        cout <<x << " ";
    }
    cout << endl;
}  

void selectionsort(vector<int>& A){
    for (auto i=0; i<A.size()-1; ++i){
        auto minimo= A[i];
        auto indiceminimo =i;
        for (auto j= i+1; j<A.size(); ++j){
            if (A[j]< minimo){
                minimo = A[j];
                indiceminimo= j;
            }
        }
        A[indiceminimo]= A[i];
        A[i]= minimo;
        }
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
        insertionsort
    };
    const vector<string> nomi ={
        "selection sort",
        "insertion sort"
    };
    const vector<string> complessita ={
        "quadratica",
        "quadratica al caso pessimo "
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
        cout <<endl;
    if (!verificaOrdinamento3(B)){
            cout<< "non è ordinato"<< "errore in "<< nomi[i] <<endl;
        }
    else cout << "è ordinato"<< endl;
    cout << "Ordinamento (tempo " << costo <<"): " << "["<< durata.count()<< "microsecondi]"<< endl;
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
