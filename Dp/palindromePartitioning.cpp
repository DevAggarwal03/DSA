#include "../stdc++.h"
using namespace std;

int check(int s, int e, string& str){
    while(s < e){
        if(str[s] == str[e]){
            e--; s++;
        }else{
            return false;
        }
    }
    return true;
}

// bottomUp (tabulation)
int minCutBoUp(string s){
    int n = s.size();
    vector<int> dp(n+1, 0);

    for(int i=n-1; i>=0; i--){
        int cuts = 1e9;
        for(int k=i; k<s.size(); k++){
            if(check(i, k, s)){
                int res = 1 + f1(k+1, s, dp);
                cuts = min(cuts, res);
            }
        }
        dp[i] = cuts;
    }
    return dp[0];
}

// front partitioning
int f1(int i, string& str, vector<int>& dp){
    if(i >= str.size()) return 0;
    if(dp[i] != -1) return dp[i];

    int cuts = 1e9;
    for(int k=i; k<str.size(); k++){
        if(check(i, k, str)){
            int res = 1 + f1(k+1, str, dp);
            cuts = min(cuts, res);
        }
    }
    return dp[i] = cuts;
}

int minCut(string s){
    int n = s.size();
    vector<int> dp(n, -1);
    return f1(0, s, dp) - 1;
}

// this is not optimal (gives TLE) 
int f(int s, int e, string& str, vector<vector<int> >& dp){
    if (s >= e) return 0;
    if(dp[s][e] != -1) return dp[s][e];

    int res = check(s, e, str);
    int cuts = INT_MAX;
    if(!res){
        for(int k=s; k<e; k++){
            int res = 1 + f(s, k, str, dp) + f(k+1, e, str, dp);
            cuts = min(cuts, res);
        }
    }else{
        return dp[s][e] = 0;
    }

    return dp[s][e] = cuts;
}

int minCut(string s){
    int n = s.size();
    vector<vector<int> > dp(n, vector<int>(n, -1));
    return f(0, n-1, s, dp);
}

int main(){


    return 0;

}