#include "../stdc++.h"

using namespace std;

bool isMajority(int arr[], int n, int element){
    int s = 0;
    int e = n - 1;
    int mid = (s + e)/2;

    int firstOccourance = -1;

    while(s < e){
        if(arr[mid] < element){
            s = mid + 1;
        }
        if(arr[mid] >= element){
            e = mid;
        }
        mid = (s + e)/2;
    }

    if(s == e) firstOccourance = e;

    if(arr[firstOccourance + (n/2)] == element){
        return true;
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int element;
    cin>>element;

    cout<<(isMajority(arr, n, element))<<endl;
}