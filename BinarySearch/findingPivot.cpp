#include "../stdc++.h"

using namespace std;

int findPivot(int arr[], int size){
    int s = 0;
    int e = size - 1;
    int mid = (s+e)/2;
    while(s<e){
        if(arr[mid] >= arr[0]){
            s = mid + 1;
        }
        else{
            e = mid; 
        }
        mid = (s+e)/2;
    }
    return arr[s];
}

int main(){
    int arr[5] = {7, 9, 1, 2, 4};
    cout<<findPivot(arr, 5)<<endl;
}
