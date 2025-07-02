#include "../stdc++.h"

using namespace std;

int binarySearch(int arr[], int low, int high){
    int mid = (high + low) / 2;

    if(low >= high){
        if(arr[mid] == 1)
            return mid;
        else
            return -1;
    }

    if(arr[mid] == 0){
        return binarySearch(arr, mid + 1, high);
    }
    if(arr[mid] == 1){
        return binarySearch(arr, low, mid);
    }
}

int findIndex(int arr[]){
    int l = 0, h = 1;

    while(arr[h] == 0){
        l = h;
        h = 2 * h;
    }

    return binarySearch(arr, l, h);
}

int main(){
    int arr[] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1};

    cout<<findIndex(arr);
}