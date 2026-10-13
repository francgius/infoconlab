//sorting codes

#include <vector>
#include <iostream>
#include <random>
#include <string>
using namespace std;

int random(int a, int b){
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> dist(a, b);
    return dist(gen);
};

vector<int> generaArrayCasuale(int n, int minVal=-30, int maxVal=30){
    vector<int> A(n);
    for (int i=0; i <n ; i++){
        A[i]= random(minVal, maxVal);
    }
    return A;
};

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

int main()
{ 
    constexpr auto minVal= -50;
    constexpr auto maxVal=  50;
    constexpr int N= 30;
    vector<int> A = generaArrayCasuale(N, minVal, maxVal);
    for ( auto x : A){
        cout<< x<< " ";
    }

    cout << endl;
    auto B=A;
    cout <<endl<< "e ordinato diventa"<< endl;
    selectionsort(B);
    
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
