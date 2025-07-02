#include "../stdc++.h"
using namespace std;

vector<int> returnProductArray(vector<int> arr){
    vector<int> prefixProduct(arr.size(), 1);
    vector<int> suffixProduct(arr.size(), 1);
    for(int i=1; i<arr.size(); i++){
        if(i-1 == 0){
            prefixProduct[i] = arr[i-1];
            suffixProduct[arr.size() - i - 1] = arr[arr.size() - 1];
        }else{
            prefixProduct[i] = arr[i-1] * prefixProduct[i-1]; 
            suffixProduct[arr.size() - i - 1] = arr[arr.size() - i] * suffixProduct[arr.size() - i];
        }
    }

    vector<int> ans;
    for(int i=0; i<arr.size(); i++){
        ans.push_back(prefixProduct[i] * suffixProduct[i]);
    }

    return ans;
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
    vector<int> productArr = returnProductArray(arr);
    for(int i=0; i<productArr.size(); i++){
        cout<<productArr[i]<<" ";
    }

    return 0;

}