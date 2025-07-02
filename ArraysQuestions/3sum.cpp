#include "../stdc++.h"
using namespace std;

bool find3Sum(vector<int> arr, int target){
    if(arr.size()<=2){
        return false;
    }
    unordered_set<int> set;
    for(int i=0; i<arr.size(); i++){
        int complement = target - arr[i];
        set.insert(complement);
    }
    for(int i=0; i<arr.size()-2; i++){
        for(int j=i+1; j<arr.size()-1; j++){
            int remaining = arr[i] + arr[j];
            if(set.find(remaining) != set.end()){
                return true;
            }
        }
    }
    return false;
}

// using 3 loops
// using hash set
// using 2 pointer for every element from 1 to n

//leetcode solution


int main(){
    int a;
    cin>>a;
    vector<int> arr;
    for(int i=0; i<a; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    int target;
    cin>>target;

    bool ans = find3Sum(arr, target);
    cout<<endl;
    if(ans){
        cout<<"there is a triplet"<<endl;
    }else{
        cout<<"there is no triplet"<<endl;
    }
}