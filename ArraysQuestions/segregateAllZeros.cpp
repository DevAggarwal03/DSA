#include "../stdc++.h"
using namespace std;

void segregate(vector<int>& arr){
    int i=0;
    int j=1;
    while(j < arr.size()){
        if(arr[i] != 0){
            i++;
            j++;
        }
        else{
            while(arr[j] == 0){
                j++;
                if(j >= arr.size()){
                    break;
                }
            }
            if(j < arr.size()){
                swap(arr[i], arr[j]);
            }
        }
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