#include "../stdc++.h"
using namespace std;

void segregate(vector<int>& arr){
    int i = 0, j = arr.size() - 1;

    while(i < j){
        while(arr[i] % 2 == 0 && i < j){
            i++;
        }
        while(arr[j] % 2 != 0 && i < j){
            j--;
        }

        if(i < j) swap(arr[i], arr[j]);
    }
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