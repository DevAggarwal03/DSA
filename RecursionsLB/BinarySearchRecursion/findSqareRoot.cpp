#include "../../stdc++.h"

using namespace std;

int findSquareRoot(int start, int end, int element){
    int mid = (start + end)/2;

    if(start == end){
        return mid;
    }

    if(start + 1 == end){
        return start;
    }


    if(mid*mid == element){
        return mid;
    }
    if(mid*mid > element){
        return findSquareRoot(start, mid, element);
    }
    if(mid*mid < element){
        return findSquareRoot(mid, end, element);
    }
}

int main(){
    int n;
    cin>>n;
    cout<<findSquareRoot(0, n, n);
}