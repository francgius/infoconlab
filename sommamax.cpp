//pages.di.unipi.it ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIID3xq3k730X+1UZ/hjymRiPKgG1S+ZYQxDUmdDhM1xj
//somma massima costo lineare
#include <iostream>
using namespace std;
#include <vector>


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


int main(){
    vector<int> A = {4, -6, 3, 5, -2, 1, -4, 6, -3};

auto maxSegmentSum = sommamassima3(A);
cout << "il segmento di somma massima di A è: "<< maxSegmentSum<< endl;
return 0;
}