#include "../stdc++.h"
using namespace std;

int unboundKnapsackBoUp(int W, vector<int>& weights, vector<int>& profits){
    int n = weights.size();
    // vector<vector<int> > dp(n, vector<int>(W+1, 0));
    vector<int> prev(W+1, 0);
    for(int i=weights[0]; i<=W; i++){
        prev[i] = ((i/weights[0]) * profits[0]);
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<=W; j++){
            int notTake = prev[j];
            int take = 0;
            if(weights[i] <= j){
                take = profits[i] + prev[j - weights[i]];
            }
            prev[j] = max(notTake, take);
        }
    }

    return prev[W];
}

int f(int ind, int W, vector<int>& weights, vector<int>& profits, vector<vector<int> >& dp){
    if(ind == 0){
        if(weights[ind] > W) return 0;
        else{
            return ((W/weights[0])* profits[0]); 
        }
    }
    if(dp[ind][W] != -1) return dp[ind][W];

    int notTake = f(ind-1, W, weights, profits, dp);
    int take = INT_MIN;
    if(weights[ind] <= W){
        take = profits[ind] + f(ind, W-weights[ind], weights, profits, dp);
    }

    return dp[ind][W] = max(notTake, take);
}

// int unboundedKnapsack(int W, vector<int>& weights, vector<int>& profits){
//     return f(weights.size()-1, W, weights, profits);
// }

int main(){
    int n;
    cin>>n;
    vector<int> weights(n, 0), profits(n, 0);
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
    int w;
    cin>>w;
    cout<<unboundKnapsackBoUp(w, weights, profits);
    return 0;
}