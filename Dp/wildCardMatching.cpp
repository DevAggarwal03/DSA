#include "../stdc++.h"
using namespace std;

bool isMatchBoUp(string s, string p) {  
    int n = s.size();
    int m = p.size();
    vector<vector<bool> > dp(n+1, vector<bool>(m+1, false));
    dp[0][0] = true;
    for(int i=1; i<=n; i++){
        dp[i][0] = false;
    } 
    for(int i=1; i<=m; i++){
        if(p[i-1] != '*') break;
        dp[0][i] = true;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1] == p[j-1] || p[j-1] == '?'){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = dp[i-1][j] | dp[i][j-1];
            }
        }
    }

    return dp[n][m];
}

bool f(int i, int j, string& s, string& p){
    if(i < 0){
        if(j<0) return true;
        while(j>=0){
            if(p[j] != '*') return false;
            j--;
        }
        return true;
    }
    if(j < 0){
        return false;
    }

    if(s[i] == p[j] || p[j] == '?'){
        return f(i-1, j-1, s, p);
    }
    if(p[j] == '*'){
        int zeroMatch = f(i, j-1, s, p);
        int oneMatch = f(i-1, j, s, p);
        return zeroMatch | oneMatch;
    }
    return false;
}

bool isMatch(string s, string p) {
        
}

int main(){


    return 0;

}