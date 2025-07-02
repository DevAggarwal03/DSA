#include "../stdc++.h"
// #include <vector>
using namespace std;

void printAllDivisors(int num){
    vector<int> v;
    int n = 1;
    while(n*n < num){
        if(num % n == 0){
            v.push_back(n);
            if(num/n != n){
                v.push_back(num/n);
            }
        }
        n += 1;
    }
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}

int main(){

    int num;
    cin>>num;

    printAllDivisors(num);

    return 0;
}