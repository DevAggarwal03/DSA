#include "../stdc++.h"
using namespace std;

int coinChangeBoUp(int amount, vector<int>& coins){
    vector<vector<int> > dp(coins.size(), vector<int>(amount+1, 0));
    for(int i=0; i<=amount; i++){
        if(i % coins[0] == 0) dp[0][i] = 1;
    }
    for(int i=1; i<coins.size(); i++){
        for(int j=1; j<amount+1; j++){
            int notTake = dp[i-1][j];
            int take = 0;
            if(coins[i] <= j){
                take = dp[i][j-coins[j]];
            }

            dp[i][j] = take + notTake;
        }
    }

    return dp[coins.size()-1][amount];
}

int f(int ind, int amt, vector<int>& coins, vector<vector<int> >& dp){
    if(ind == 0){
        if(amt == 0) return 1;
        if(amt % coins[ind] == 0) return 1;
        else return 0;
    }
    if(dp[ind][amt] != -1) return dp[ind][amt];

    int notTake = f(ind-1, amt, coins, dp);
    int take = 0;
    if(coins[ind] <= amt){
        take = f(ind, amt-coins[ind], coins, dp);
    }

    return dp[ind][amt] = take + notTake;
}

int change(int amount, vector<int>& coins){
    vector<vector<int> > dp(coins.size(), vector<int>(amount+1, -1));
    return f(coins.size() - 1, amount, coins, dp);
}

int main(){


    return 0;

}