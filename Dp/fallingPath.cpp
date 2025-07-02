#include "../stdc++.h"
using namespace std;

int solve(int i, int j, vector<vector<int> >& matrix, int n, vector<vector<int> >& dp){
    if(i==0) return dp[i][j] = matrix[0][j];
    if(dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;
    for(int k=0; k<3; k++){
        if(j - 1 + k >= 0 && j - 1 + k < n){
            ans = min(ans, solve(i-1, j - 1 + k, matrix, n, dp)); 
        }
    }

    return dp[i][j] = ans + matrix[i][j];
}

int minimumFallingPathSum(vector<vector<int> >& matrix){
    int n = matrix.size();
    vector<vector<int> > dp(n, vector<int>(n, -1));
    for(int i=0; i<n; i++){
        solve(n-1, i, matrix, n, dp);
    }
    int ans = INT_MAX;
    for(int i=0; i<n; i++){
        ans = min(ans, dp[n-1][i]);
    }
    return ans;
}

int minFallingPathSum(vector<vector<int> >& matrix){
    int n = matrix.size();
    vector<vector<int> > dp(n, vector<int>(n, INT_MAX));
    for(int i=0; i<n; i++){
        dp[0][i] = matrix[0][i];
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
            int ans = INT_MAX;
            for(int k=0 ;k<3; k++){
                if(j - 1 + k >= 0 && j - 1 + k < n){
                    ans = min(ans, dp[i-1][j-1+k]);
                }
            }
            dp[i][j] = ans + matrix[i][j];
        }
    }

    int ans = INT_MAX;
    for(int i=0; i<n; i++){
        ans = min(ans, dp[n-1][i]);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int> > matrix(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int temp;
            cin>>temp;
            matrix[i][j] = temp;
        }
    }
    cout<<minFallingPathSum(matrix);
    return 0;
}