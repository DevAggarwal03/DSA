#include "./../stdc++.h"
using namespace std;

int findMissingInt(vector<int> arr){
    int ans = 0;
    for(int i=0; i<arr.size(); i++){
        ans = ans ^ arr[i] ^ (i+1);
    }
    return ans ^ (arr.size() + 1);
}
// naive approach: using 2 loops
// better approach: using hash maps
// expected: use sum of first n natural numbers
// expected: use XOR operator
int main(){
    int a;
    cin>>a;
    vector<int> arr;
    for(int i=0; i<a; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    cout<<findMissingInt(arr);
}
