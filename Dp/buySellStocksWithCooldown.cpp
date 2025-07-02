#include "../stdc++.h"
using namespace std;

int f(int ind, int buy, int wait, vector<int>& prices){

    if(ind >= prices.size()) return 0;

    int profit = 0;
    if(buy == 1){
        if(wait != 1){
            profit = max(-prices[ind] + f(ind+1, 0, wait, prices), f(ind+1, 1, wait, prices));
        }else{
            profit = f(ind+1, buy, 0, prices);
        }
    }else{
        profit = max(prices[ind]+f(ind+1, 1, 1, prices), f(ind+1, 0, 0, prices));
    }
    return profit;
}

int maxProfit(vector<int>& prices) {
       return f(0, 1, 0, prices); 
}

int main(){


    return 0;

}