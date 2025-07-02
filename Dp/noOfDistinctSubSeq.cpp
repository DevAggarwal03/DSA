#include "../stdc++.h"
using namespace std;

int numDistinct(string& s, string& t){
    int n = s.size();
    int m = t.size();
    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
    for(int i=0; i<m; i++){
        dp[0][i] = -1;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][m];
}

int f(int i, int j, string& s, string& t, vector<vector<int> >& dp){
    if(i<0){
        if(j<0) return 1;
        else return 0;
    }
    if(j<0){
        return 1;
    }
    if(dp[i][j] != -1) return dp[i][j];

    int taken = 0, notTaken = 0;
    if(s[i] == t[j]){
        taken = f(i-1, j-1, s, t, dp);
        notTaken = f(i-1, j, s, t, dp);
        return dp[i][j] = taken + notTaken;
    }else{
        return dp[i][j] = f(i-1, j, s, t, dp);
    }
}

int numDistinct(string& s, string& t){
    vector<vector<int> > dp(s.size(), vector<int>(t.size(), -1));
    return f(s.size()-1, t.size()-1, s, t, dp);
}

int main(){


    return 0;

}