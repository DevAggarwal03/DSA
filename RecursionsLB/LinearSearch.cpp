#include "../stdc++.h"

using namespace std;

bool isKeyPresent(int arr[], int key, int size){
    if(size == 0){
        return false;
    }

    if(arr[0] == key){
        return true;
    }else{
        return isKeyPresent(arr + 1, key, size - 1);
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
    cout<<isKeyPresent(arr, key, n)<<endl;
}