#include "../stdc++.h"

using namespace std;

int ceilingElement(int arr[], int n, int element){
    int s = 0;
    int e = n - 1;
    int mid = (s + e) / 2;

    while(s < e){
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid] > element){
            e = mid - 1;
        }
        if(arr[mid] < element){
            if(arr[mid + 1] > element){
                return mid;
            }
            else{
                s = mid + 1;
            }
        }
        mid = (s + e) /2;
    }

    return -1;
}

int main (){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int element;
    cin>>element;

    cout<<ceilingElement(arr, n, element)<<endl;
}