#include "../stdc++.h"
using namespace std;

int f(vector<int>& arr){
    int ans = 0;
    arr.push_back(0);
    for(int i=0; i<arr.size()-1; i++){
        ans += abs(arr[i] - arr[i+1]); 
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<f(arr);

    return 0;

}