#include "../../stdc++.h"

using namespace std;

int findPivot(int arr[], int start, int end){
    int mid = (start + end) /2;

    if(start == end){
        return end;
    }

    if(arr[mid] > arr[mid - 1]){
        if(arr[mid] > arr[end])
            return findPivot(arr, mid + 1, end);

        if(arr[mid] < arr[end]){
            return findPivot(arr, start, mid);
        }
    }else{
        return mid;
    }
}

int main(){
    int arr[7] = {23, 45, 12, 16, 19, 20, 21};

    cout<<findPivot(arr, 0, 6);
}