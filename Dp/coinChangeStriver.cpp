#include "../stdc++.h"
using namespace std;

int f(int ind, int target, vector<int>& coins){
    if(target = 0) return 0;
    if(ind == 0){
        if(coins[ind] % target == 0) return target / coins[ind];
        else return 1e9;
    }

    int notTake = f(ind - 1, target, coins);
    int take = INT_MAX;
    if(coins[ind] <= target){
        take = 1 + f(ind, target - coins[ind], coins);
    }

    return min(take, notTake);
}

int coinChange(vector<int>& coins, int amt){
    return f(coins.size()-1, amt, coins);    
}

int main(){


    return 0;

}