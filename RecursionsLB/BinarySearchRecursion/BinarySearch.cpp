#include "../../stdc++.h"

using namespace std;

bool binarySearch(int arr[], int start, int end, int key){
    int mid = (start + end) / 2;

    if(start > end){
        return false;
    }

    if(arr[mid] == key){
        return true;
    }
    if(arr[mid] > key){
        end = mid - 1;
        return binarySearch(arr, start, end, key);
    }
    if(arr[mid] < key){
        start = mid + 1;
        return binarySearch(arr, start, end, key);
    }
}

int main(){
    int n;
    cin >>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int key;
    cin>> key;
    cout<<endl;

    cout<<binarySearch(arr, 0, n, key)<<endl;
    return 0;
}