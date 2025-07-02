#include "../stdc++.h"

using namespace std;

void bubbleSort(int arr[], int size, int index){

    if(size == 0 || size == 1){
        return;
    }
    if(size == 2){
        if(arr[0] > arr[1]) swap(arr[0], arr[1]);
        return;
    }

    int start = 0;

    if(index == size - 1){
        return bubbleSort(arr, size - 1, 0);
    }

    if(arr[index] > arr[index+1]){
        swap(arr[index], arr[index + 1]);
    }

    return bubbleSort(arr, size, index + 1);


}   

int main(){
    int arr[7] = {23, 51, 1, 50, 24, 11, 20};

    bubbleSort(arr, 7, 0);

    for(int i=0; i<7; i++){
        cout<<arr[i]<<" ";
    }
}