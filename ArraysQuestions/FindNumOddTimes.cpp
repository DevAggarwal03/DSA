#include "./../stdc++.h"
using namespace std;

int findOdd(vector<int> arr){
    int ans = 0;
    for(int i=0; i<arr.size(); i++){
        ans = ans ^ arr[i];
    }
    return ans;
}

// naive solution: use 2 loops
// better solution: use hash map
// best solution: XOR operator

int main(){
    int a;
    cin>>a;
    vector<int> arr;
    for(int i=0; i<a; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    cout<<findOdd(arr);
}