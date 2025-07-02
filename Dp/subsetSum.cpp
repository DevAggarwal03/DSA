#include "../stdc++.h"
using namespace std;

bool subSetSumSpOp(int n, int k, vector<int>& arr){
    vector<bool> prev(k+1, false);
    prev[0] = true;
    if(arr[0] <= k){
        prev[arr[0]] = true;
    }
    for(int i=1; i<n; i++){
        vector<bool> temp(k+1, false);
        for(int j=1; j<=k; j++){
            int notTaken = prev[j];
            int taken = false;
            if(arr[i] <= j){
                taken = prev[j - arr[i]];
            }
            temp[j] = taken | notTaken;
        }
        prev = temp;
    }
    return prev[k];
}

bool subSetSum(int n, int k, vector<int>& arr){
    vector<vector<bool> > dp(n, vector<bool>(k+1, false));
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }

    if(arr[0] <= k){
        dp[0][arr[0]] = true;
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<k+1; j++){
            int notTaken = dp[i-1][j];
            int taken = false;
            if(arr[i] <= j){
                taken = dp[i-1][j-arr[i]];
            }
            dp[i][j] = taken | notTaken;
        } 
    }

    return dp[n-1][k];
}

bool subSetSum(int ind, int curr, vector<int>& arr, vector<vector<int> >& dp){
    if(curr == 0) return true;
    if(curr < -1 || ind >= arr.size()) return false;
    if(dp[ind][curr] != -1) return dp[ind][curr];

    bool notTaken = subSetSum(ind+1, curr, arr, dp);
    if(notTaken == false){
        bool taken = subSetSum(ind + 1, curr - arr[ind], arr, dp);
        return taken;
    }
    return dp[ind][curr] = notTaken;
}

bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<vector<int> > dp(n, vector<int>(k + 1, -1));
    return subSetSum(0, k, arr, dp);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        arr[i] = temp; 
    }
    int k;
    cin>>k;
    cout<<subsetSumToK(n, k, arr);
    return 0;

}