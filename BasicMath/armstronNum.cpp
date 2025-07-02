#include "../stdc++.h"

using namespace std;

bool isArmstrong(int num){
    int copy = num;
    int res = 0;
    while(num > 0){
        int digit = num % 10;
        res = res + digit*digit*digit*digit;
        num = num / 10;
    }
    cout<<res<<endl;
    if(res == copy) return true;
    else return false;
}

int main(){
    int num;
    cin>>num;
    cout<<isArmstrong(num);
}