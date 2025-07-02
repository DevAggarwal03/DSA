#include "../stdc++.h"

using namespace std;

int noOfSteps(int n){
    if(n == 3){
        return 3;
    }

    if(n == 2){
        return 2;
    }

    if(n == 1){
        return 1;
    }

    return noOfSteps(n - 2) + noOfSteps(n - 1);
}

int main(){
    int n;
    cin>>n;

    cout<<noOfSteps(n);
}