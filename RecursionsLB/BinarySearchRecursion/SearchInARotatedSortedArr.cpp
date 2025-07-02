#include "../../stdc++.h"

using namespace std;

int searchInRotatedSortedArr(int arr[], int start, int end, int key){
    int mid = (start + end) / 2;
    int isTop = true;

    if(arr[mid] == key){
        return mid;
    }
    if(start > end){
        return -1;
    }

    if(key <= arr[end]){
        isTop = false;
    }

    if(isTop){
        if(arr[mid] < arr[end]){
            return searchInRotatedSortedArr(arr, start, mid - 1, key);
        }
        else{
            if(key > arr[mid]){
                return searchInRotatedSortedArr(arr, mid + 1, end, key);
            }else{
                return searchInRotatedSortedArr(arr, start, mid - 1, key);
            }
        }
    }else{
        if(arr[mid] > arr[end]){
            return searchInRotatedSortedArr(arr, mid + 1, end, key);
        }
        else{
            if(arr[mid] > key){
                return searchInRotatedSortedArr(arr, start, mid - 1, key);
            }else{
                return searchInRotatedSortedArr(arr, mid + 1, end, key);
            }
        }
    }

}

int main(){
    int arr[6] = {23, 45, 13, 15, 20, 21};
    cout<<searchInRotatedSortedArr(arr, 0, 5, 24)<<endl;
}