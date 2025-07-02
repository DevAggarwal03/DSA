#include "../stdc++.h"

using namespace std;

int findFixedPoint(int arr[], int n){
    int s = 0;
    int e = n - 1;
    int mid = (s + e) / 2;

    while(s < e){
        if(arr[mid] < mid){
            s = mid + 1;
        }
        if(arr[mid] > mid){
            e = mid - 1;
        }
        if(arr[mid] == mid){
            return mid;
        }
        mid = (s + e)/2;
    }

    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<findFixedPoint(arr, n)<<endl;
}