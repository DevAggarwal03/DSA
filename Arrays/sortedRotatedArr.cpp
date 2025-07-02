#include "../stdc++.h"
using namespace std;

bool isSortedRotatedArray(int arr[], int num){
    int breakk = -1;
    bool inc = arr[0] > arr[num - 1] ? true : false;
    for(int i=1; i<num; i++){
        if((inc && arr[i - 1] > arr[i]) || (!inc && arr[i - 1] < arr[i])){
            breakk++;
        }
    }
    if(breakk == 1 || breakk == 0){
        return true;
    }
    return false;
}

int main(){
    int n; 
    cin>>n;
    int arr[n];
    int num = n;
    while(num--){
        cin>>arr[n-num];
    }

    cout<<isSortedRotatedArray(arr, n)<<endl;
}