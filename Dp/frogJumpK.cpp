#include "../stdc++.h"
using namespace std;

int solve(int ind, vector<int>& arr, int k, vector<int>& dp){
    if(ind == 0) return 0;
    if(dp[ind] != -1) return dp[ind];

    int ans = INT_MAX;
    for(int i=0; i<k; i++){
        if(ind - (i+1) >= 0){
            int res = solve(ind - (i+1), arr, k, dp) + abs(arr[ind] - arr[ind-(i+1)]);
            ans = min(res, ans);
        }
    }

    return dp[ind] = ans;
}

int frogJumpK(vector<int> arr, int k){
    int n = arr.size();
    if(n == 0 || n==1) return 0;
    //using memoization;
    vector<int> dp(n, -1);
    dp[0] = 0;
    return solve(n-1, arr, k, dp);
}

int frogJumpKBoUp(vector<int> arr, int k){
    int n = arr.size();
    if(n == 0 || n == 1) return 0;
    vector<int> dp(n, 0);
    for(int i=1; i<n; i++){
        int temp = INT_MAX;
        for(int j=0; j<k; j++){
            if(i - (j+1) >= 0){
                int res = dp[i - (j+1)] + abs(arr[i] - arr[i - (j+1)]);
                temp = min(temp, res);
            }
        }
        dp[i] = temp;
    }
    return dp[n-1];
}

int main(){
    int n;
    int k;
    cin>>n;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        arr[i] = temp;
    }
    cin>>k;
    int ans = frogJumpKBoUp(arr, k); 
    cout<<ans;
    return 0;
}