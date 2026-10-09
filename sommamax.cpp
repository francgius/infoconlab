//pages.di.unipi.it ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIID3xq3k730X+1UZ/hjymRiPKgG1S+ZYQxDUmdDhM1xj
//somma massima costo lineare
#include <iostream>
using namespace std;
#include <vector>

//costo 3 ----------------------------------
int sommamassima3(vector<int> B) {
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
int sommamassima2 (vector<int> B) {
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
int sommamassima1(){
    auto maxs=0;
    auto somma=0;

    for (auto j=0; j<B.size; j++){
        if (somma>0){
            somma += B[j];
        else 
        somma =B[j];
        }
    }
    if (somma>maxs){
        maxs = somma;
    }
    return maxs;
}
int main(){
    vector<int> A = {4, -6, 3, 5, -2, 1, -4, 6, -3};

auto maxSegmentSum3 = sommamassima3(A);
cout << "il segmento di somma massima dell'alg di costo 3 di A è: "<< maxSegmentSum3<< endl;
auto maxSegmentSum2 = sommamassima2(A);
cout << "il segmento di somma massima dell'alg di costo 2 di A è: "<< maxSegmentSum2<< endl;
auto maxSegmentSum1 = sommamassima1(A);
cout << "il segmento di somma massima dell'alg di costo 1 di A è: "<< maxSegmentSum1<< endl;
return 0;
}

