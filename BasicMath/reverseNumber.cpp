#include "../stdc++.h"
using namespace std;

int reverseNum(int num){
    int a = num;
    int reversedInt = 0;
    while(a > 0){
        int digit = a % 10;
        reversedInt = (reversedInt * 10) + digit;
        a = a/10;
    }
    return reversedInt;
}

int main(){

    int num;
    cin>>num;
    cout<<reverseNum(num);

    return 0;
}

