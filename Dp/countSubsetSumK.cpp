#include "../stdc++.h"
using namespace std;

int solve(int ind, int curr, vector<int>& arr){
    if(curr == 0) return 1;
    if(ind == 0){
        if(curr - arr[0] == 0) return 1;
        else return 0;
    }

    int notTaken = solve(ind - 1, curr, arr);
    int taken = 0;
    if(arr[ind] <= curr){
        taken = solve(ind - 1, curr-arr[ind], arr);
    }
    return notTaken + taken;
}

int findWays(vector<int>& arr, int k) {
    solve(arr.size()-1, k, arr);
}

int findWays(vector<int>& arr, int k){
    int n = arr.size();
    vector<vector<int> > dp(n, vector<int>(k+1, 1));
    for(int i=0; i<n; i++){
        dp[i][0] = 1;
    }
    if(arr[0] <= k){
        dp[0][arr[0]] = 1;
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<=k; j++){
            int notTake = dp[i-1][j];
            int taken = 0;
            if(arr[i] <= j){
                taken = dp[i-1][j-arr[i]];
            }
            dp[i][j] = taken + notTake;
        }
    }

    return dp[n-1][k];
}

int main(){


    return 0;

}