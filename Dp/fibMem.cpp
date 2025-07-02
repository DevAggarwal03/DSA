#include "../stdc++.h"
using namespace std;

int solve(int n, vector<int>& memoryTable){
    cout<<n<<endl;
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(memoryTable[n] != 0){
        return memoryTable[n];
    }

    return memoryTable[n] = solve(n-1, memoryTable) + solve(n-2, memoryTable);
}


// using memoization
// int fib(int n){
//     vector<int> memoryTable(10000, 0);
//     memoryTable[1] = 1;
//     return solve(n, memoryTable);
// }


//using table
// int fib(int n){
//     vector<int> memoryTable(n+1, 0);
//     memoryTable[1] = 1;
//     for(int i=2; i<=n; i++){
//         memoryTable[i] = memoryTable[i-1] + memoryTable[i-2];
//     }
//     return memoryTable[n];
// }


//using just 2 var
int fib(int n){
    int a = 0;
    int b = 1;
    if(n <= 1){
        return n;
    }
    for(int i=2; i<n+1; i++){
        int temp = b;
        b = a+b;
        a = temp;
    }

    return b;
}

int main(){
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}