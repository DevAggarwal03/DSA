#include "../stdc++.h"
using namespace std;

int rodCuttingBoUp(vector<int>& price){
    int n = price.size();
    vector<int> dp(n+1,0);
    for(int i=1; i<n+1; i++){
        dp[i] = price[0]*i;
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<n+1; j++){
            int notCut = dp[j];
            int cut = 0;
            if(i+1 <= j){
                cut = price[i] + dp[j-(i+1)];
            }

            dp[j] = max(cut, notCut); 
        }
    }
    
    return dp[n]; 
}

int f(int ind, int len, vector<int>& prices, vector<vector<int> >& dp){
    if(ind == 0){
        if(len == 0) return 0;
        else{
            return prices[0] * len;
        }
    }
    if(dp[ind][len] != -1) return dp[ind][len];
    int notCut = f(ind - 1, len, prices, dp);
    int cut = 0;
    if(ind+1 <= len){
        cut = prices[ind] + f(ind, len-(ind+1), prices, dp);
    }

    return dp[ind][len] = max(cut, notCut);
}

int rodCutting(vector<int>& prices, int n){
    vector<vector<int> > dp(n, vector<int>(n+1, -1));
    return f(n-1, n, prices, dp);
}

int main(){

    int n;
    cin>>n;
    vector<int> prices(n, 0);
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        prices[i] = temp;
    }

    cout<<rodCutting(prices, n);

    return 0;

}