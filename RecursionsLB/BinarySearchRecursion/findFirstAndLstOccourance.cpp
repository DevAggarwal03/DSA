#include "../../stdc++.h"

using namespace std;

int firstOcc(int arr[], int start, int end, int key){
    int mid = (start + end) / 2;
    
    if(start > end){
        return -1;
    }

    if(start == end && arr[start] == key){
        return start;
    }
    if(arr[mid] >= key){
        return firstOcc(arr, start, mid, key);
    }
    if(arr[mid] < key){
        return firstOcc(arr, mid + 1, end, key);
    }


}

int lastOcc(int arr[], int start, int end, int key){
    int mid = (start + end) / 2;

    if(start > end){
        return -1;
    }

    if(start + 1 == end){
        if(arr[end] == key){
            return end;
        }
        else if(arr[start] == key){
            return start;
        }
        else{
            return -1;
        }

    }
    if(start == end && arr[start] == key){
        return start;
    }
    if(arr[mid] <= key){
        return lastOcc(arr, mid, end, key);
    }
    if(arr[mid] > key){
        return lastOcc(arr, start, mid - 1, key);
    }
}

int main(){
    int arr[3] = {1, 1, 1};

    cout<<firstOcc(arr,0, 2, 10);
    cout<<endl;
    cout<<lastOcc(arr,0, 2, 11);
}