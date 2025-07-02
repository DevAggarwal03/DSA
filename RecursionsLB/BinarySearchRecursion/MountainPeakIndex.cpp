#include "../../stdc++.h"

using namespace std;

int peakIndex(int arr[], int start, int end){
    if(start == end){
        if(arr[start] == arr[start + 1] || arr[start] == arr[start - 1]) return -1;
        else return start;
    }

    int mid = (start + end) / 2;

    if(start + 1 == end && arr[start] == arr[end]){
        return -1;
    }

    if(arr[mid] >= arr[mid + 1]){
        return peakIndex(arr, start, mid);
    }
    else{
        return peakIndex(arr, mid + 1, end);
    }
}

int main(){
    int arr[7] = {1, 4, 7, 9, 9, 3, 2};

    cout<<peakIndex(arr, 0, 6);
}