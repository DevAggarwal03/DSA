#include "../stdc++.h"
using namespace std;

int main(){
    int num = 5;
    int *p = &num;
    int ** dp = &p;
    int *** tp = &dp;
    cout<<p<<endl;
    cout<<*dp<<endl;
    cout<<**tp<<endl;

    int arr[3] = {23, 5, 1};
    cout<<&arr<<endl;
    cout<<*arr<<endl;  
    int *arrPtr = arr;
    cout<<&arrPtr[0]<<endl;
}