#include "../stdc++.h"
using namespace std;

int knapsackBoUp(int n, int w, vector<int>& weights, vector<int>& profits){
    vector<vector<int> > dp(n, vector<int>(w+1, 0));
    for(int i=0; i<n; i++){
        dp[i][0] = 0;
    }
    for(int i=weights[0]; i<=w; i++){
        dp[0][i] = profits[0];
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<=w; j++){
            int notTake = dp[i-1][j];
            int take = 0;
            if(weights[i] <= j){
                take = dp[i-1][j-weights[i]] + profits[i];
            }

            dp[i][j] = max(take, notTake);
        }
    }

    return dp[n-1][w];
}

int f(int ind, int cw, vector<int>& weights, vector<int>& profits, vector<vector<int> >& dp){
    if(ind == 0){
        if(weights[ind] <= cw){
            return profits[ind];
        }else{
            return 0;
        }
    }
    if(dp[ind][cw] != -1) return dp[ind][cw];

    int notTake = f(ind-1, cw, weights, profits, dp);
    int take = 0;
    if(weights[ind] <= cw){
        take = profits[ind] + f(ind - 1, cw-weights[ind], weights, profits, dp);
    }

    return max(notTake, take);
}

int knapsack(vector<int> weights, vector<int> profits, int n, int cap){
    vector<vector<int> > dp(n, vector<int>(cap+1, -1));
    return f(n-1, cap, weights, profits, dp);
}

int main(){
    int n;
    int cap;
    cin>>n;
    vector<int> weights(n, -1);
    vector<int> profits(n, -1);
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        weights[i] = temp;
    }
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        profits[i] = temp;
    }
    cin>>cap;
    cout<<knapsack(weights, profits, n, cap);

    return 0;
}