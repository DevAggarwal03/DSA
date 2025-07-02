#include "../stdc++.h"
using namespace std;

int subArrSumK(vector<int>& arr, int k){
    unordered_map<int, int> mp;
    int preSum = 0;
    int ans = 0;
    for(int i=0; i<arr.size(); i++){
        preSum += arr[i];
        if(preSum == k){
            ans = max(ans, i + 1);
        }
        if(mp.find(preSum - k) != mp.end()){
            ans = max(ans, (i - mp[preSum - k]));
        }
        if(mp.find(preSum) == mp.end()){
            mp[preSum] = i;
        }
    }
    return ans;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<subArrSumK(arr, k);
    return 0;

}