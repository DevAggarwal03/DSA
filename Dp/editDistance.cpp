#include "../stdc++.h"
using namespace std;

int minDistanceBoUp(string word1, string word2){
    int n = word1.size();
    int m = word2.size();
    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=m; i++){
        dp[0][i] = i+1;
    }
    for(int i=1; i<=n; i++){
        dp[i][0] = i+1;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int taken = INT_MAX;
            if(word1[i-1] == word2[j-1]){
                taken = dp[i-1][j-1];
            }
            int replaced = 1 + dp[i-1][j-1];
            int inserted = 1 + dp[i][j-1];
            int deleted = 1 + dp[i-1][j];
            dp[i][j] = min(taken, min(replaced, min(inserted, deleted)));
        }
    }

    return dp[n][m];
}

int f(int i, int j, string& word1, string& word2, vector<vector<int> >& dp){
    if(i < 0){
        if(j<0) return 0;
        return j+1;
    }
    if(j<0){
        return i+1;
    }
    if(dp[i][j] != -1) return dp[i][j];

    int taken = INT_MAX;
    if(word1[i] == word2[j]){
        taken = f(i-1, j-1, word1, word2, dp);
    }
    int replaced = 1 + f(i-1, j-1, word1, word2, dp);
    int inserted = 1 + f(i, j-1, word1, word2, dp);
    int deleted = 1 + f(i-1, j, word1, word2, dp);

    return dp[i][j] = min(taken, min(replaced, min(inserted, deleted)));
}

int minDistance(string word1, string word2){
    vector<vector<int> > dp(word1.size(), vector<int>(word2.size(), -1));
    return f(word1.size()-1, word2.size()-1, word1, word2, dp);
}

int main(){


    return 0;

}