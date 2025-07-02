#include "../stdc++.h"

using namespace std;

void mergee(int arr[], int start, int mid, int end){
    int temp[end - start + 1];

    int i = start;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= end){
        if(arr[i] > arr[j]){
            temp[k] = arr[j];
            j++;
        }else{
            temp[k] = arr[i];
            i++;
        }
        k++;
    }

    while(j <= end){
        temp[k] = arr[j];
        j++;
        k++;
    }

    while(i <= mid){
        temp[k] = arr[i];
        i++;
        k++;
    }

    for(int i=0; i<k; i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;

    for (int m = 0; m < k; m++) {
        arr[start + m] = temp[m];
    }
}

void mergeSortt(int arr[], int start, int end){
    int mid = (start + end) / 2;

    if(start >= end){
        return;
    }

    mergeSortt(arr, start, mid);
    mergeSortt(arr, mid+1, end);
    mergee(arr, start, mid, end);

    return;
}

int main(){
    int arr[7] = {23, 1, 55, 43, 62, 33, 6};

    mergeSortt(arr, 0, 6);
    cout<<endl<<endl;
    for(int i=0; i<7; i++){
        cout<<arr[i]<<" ";
    }
}