#include "../stdc++.h"
using namespace std;

void segregate(vector<int>& arr){
    int i=0, j=arr.size() - 1, k = 0;
    while(k < j){
        if(arr[k] == 1){
            k++;
            continue;
        }
        if(arr[k] == 0){
            swap(arr[i], arr[k]);
            i++;
        }else{
            swap(arr[j], arr[k]);
            j--;
        }
    }
    return;
}

int main(){    
    int a;
    cin>>a;
    vector<int> arr;
    for(int i=0; i<a; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    segregate(arr);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}