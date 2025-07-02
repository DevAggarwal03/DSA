#include "../stdc++.h"
using namespace std;

int f(int s, int e, vector<int>& dimensions, vector<vector<int> >& dp){
    if(s == e) return 0;
    if(dp[s][e] != -1) return dp[s][e];
    int k = s;
    int ans = INT_MAX;
    while(k<e){
        int steps = ((dimensions[s-1] * dimensions[k] * dimensions[e]) + f(s, k, dimensions, dp) + f(k+1, e, dimensions, dp));
        ans = min(steps, ans);
        k++;
    }
    return dp[s][e] = ans;
}

int matChainMul(vector<int>& dimensions){
    int n = dimensions.size();
    // vector<vector<int> > dp(n, vector<int>(n, -1));
    vector<vector<int> > dp(n, vector<int>(n, 0));

    for(int i=n-2; i>=1; i--){
        for(int j=i+1; j<n; j++){
            int k = i;
            int ans = INT_MAX;
            while(k<j){
                int steps = ((dimensions[i-1] * dimensions[k] * dimensions[j]) + dp[i][k] + dp[k+1][j]);
                ans = min(steps, ans);
                k++;
            }
            dp[i][j] = ans;
        }
    }

    return dp[1][n-1];
}

int main(){
    int n;
    cin>>n; 
    vector<int> arr(n, -1);
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        arr[i] = temp;
    }
    cout<<matChainMul(arr);

    return 0;

}