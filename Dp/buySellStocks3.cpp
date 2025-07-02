#include "../stdc++.h"
using namespace std;

int maxProfitBoUp(vector<int>& prices){
    vector<vector<vector<int> > > dp(prices.size()+1, vector<vector<int> >(2, vector<int>(4, 0)));
    for(int ind=prices.size()-1; ind>=0; ind--){
        for(int buy=0; buy<2; buy++){
            for(int lim=0; lim<3; lim++){
                int profit = 0;
                if(buy){
                    dp[ind][buy][lim] =  max(-prices[ind] + dp[ind+1][0][lim+1], dp[ind+1][1][lim]);
                }else{
                    dp[ind][buy][lim] = max(prices[ind] + dp[ind+1][1][lim], dp[ind+1][0][lim]);
                }
            }
        }
    }
    return dp[prices.size()-1][1][0];
}

int f(int ind, int buy, int lim, vector<int>& prices, vector<vector<vector<int> > >& dp){
    if(lim > 2){
        return 0;
    }
    if(ind >= prices.size()){
        return 0;
    }
    if(dp[ind][buy][lim] != -1) return dp[ind][buy][lim];

    int profit = 0;
    if(buy){
        profit =  max(-prices[ind] + f(ind+1, 0, lim+1, prices, dp), f(ind+1, 1, lim, prices, dp));
    }else{
        profit = max(prices[ind] + f(ind+1, 1, lim, prices, dp), f(ind+1, 0, lim, prices, dp));
    }
    return dp[ind][buy][lim] = profit;
}
int maxProfit(vector<int>& prices) {
    vector<vector<vector<int> > > dp(prices.size(), vector<vector<int> >(2, vector<int>(3, -1)));
    return f(0, 1, 0, prices, dp);
}

int main(){


    return 0;

}