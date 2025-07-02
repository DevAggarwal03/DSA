#include "../stdc++.h"

using namespace std;

void printName5Times(string name, int times){
    if(times == 0) return;
    cout<<name<<endl;
    times--;
    printName5Times(name, times);
}

void printLinearlyFrom1toN(int start, int end){
    if(start > end) return;
    cout<<start<<" ";
    printLinearlyFrom1toN(++start, end);
}

void printLinearlyFromNto1(int end){
    if(end == 0) return;
    cout<<end<<" ";
    printLinearlyFromNto1(--end);
}

void print1ToNBackTracking(int start, int end){
    if(end < start) return;
    print1ToNBackTracking(start, end - 1);
    cout<<end<<" ";
}

void printNTo1BackTracking(int start, int end){
    if(start > end) return;
    printNTo1BackTracking(start + 1, end);
    cout<<start<<" ";
}

int main(){
    // printName5Times("dev", 5);
    // printLinearlyFrom1toN(1, 10);
    // printLinearlyFromNto1(10);
    printNTo1BackTracking(1, 10);
}