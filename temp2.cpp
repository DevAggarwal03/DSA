#include "./stdc++.h"
using namespace std;

void printPattern(int n){
    int start = n*n;
    int i = n;
    while(start >= 1){
        while(i >= 1){
            cout<<start<<" ";
            start -= 1;
            i--;
        }
        i = n;
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    printPattern(n);

    return 0;

}