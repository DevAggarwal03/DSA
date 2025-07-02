#include "../stdc++.h"
using namespace std;

int findMinPosMissingInt(vector<int> arr){
    int i=0;
    while(i < arr.size()){
        if(arr[i] - 1 == i){
            i++;
        }else{
            if(arr[i] < 1 || arr[i] > arr.size()){
                i++;
            }else{
                if(arr[arr[i] - 1] == arr[i]){
                    i++;
                }else{
                    swap(arr[i], arr[arr[i] - 1]);
                }
            }
        }
    }

    for(i=0; i<arr.size(); i++){
        if(arr[i] - 1 != i){
            return i+1;
        }
    }
    return arr.size() + 1;
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
    int ans = findMinPosMissingInt(arr);
    cout<<ans<<endl;
}