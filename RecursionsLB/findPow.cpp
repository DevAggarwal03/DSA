#include "../stdc++.h"

using namespace std;

// int pow(int a, int b){
//     cout<<b<<endl;
//     if(b < 0){
//         return -1;
//     }
//     if(b == 0){
//         return 1;
//     }
//     if(b == 1){
//         return a;
//     }

//     return a * pow(a, --b);
// }

int pow(int a, int b){
    cout<<b<<endl;
    if(b == 0){
        return 1;
    }
    if(b % 2 == 0){
        int half = pow(a, b/2);
        return half * half;
    }else{
        int half = pow(a, b/2);
        return a * half * half;
    }
}

int main(){
    int a, b;
    cin>>a>>b;
    cout<<endl;

    cout<<pow(a, b)<<endl;
}