#include "../stdc++.h"
using namespace std;

int solve(int n, int curr, vector<int>& coins, int amt, vector<int>& dp){
    if(curr < 0) return 1e8;
    if(curr == 0){
        return 0;
    }
    if(dp[curr] != -1) return dp[amt];

    int noCoins = 1e8;
    for(int i=0; i<n; i++){
        int res = solve(n, curr-coins[i], coins, amt, dp);
        noCoins = min(noCoins, res);
    }
    return dp[curr] = noCoins + 1;
}

int coinChange(vector<int>& coins, int amt){
    int n = coins.size();
    vector<int> dp(amt+1, -1);
    return solve(n, amt, coins, amt, dp);
}

int coinChageBoUp(vector<int>& coins, int amt){
    int n = coins.size();
    vector<int> dp(amt+1, INT_MAX);
    dp[0] = 0;
    for(int i=1; i<amt+1; i++){
        int ans = INT_MAX;
        for(int j=0; j<coins.size(); j++){
            int res = INT_MAX; 
            if(i - coins[j] >= 0){
                res = dp[i - coins[j]];
                ans = min(res, ans);
            }
        }
        dp[i] = ans + 1;
    } 

    return dp[amt];
}

int main(){
    int m;
    cin>>m;
    vector<int> coins(m, 0);
    for(int i=0; i<m; i++){
        int temp;
        cin>>temp;
        coins[i] = temp;
    }
    int amt;
    cin>>amt;
    cout<<coinChageBoUp(coins, amt);

    return 0;

}