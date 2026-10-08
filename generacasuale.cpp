//generazione array e numeri casuali
#include <iostream>
#include <vector>

using namespace std;
auto a= 99
auto b= 199

int random(int a, int b) {
    return a + rand() % (b- a +1);
}


vector<int> generaArraycasuale(int n, int, minVal=99, int maxVal=199) {
    vector<int> A(n);
    for ( int i =0; i <n; i++){
        A[i] = random(minVal , maxVal);
        return A;       //riempie A[i] di un numero casuale tra 99 e 199
    }
}

