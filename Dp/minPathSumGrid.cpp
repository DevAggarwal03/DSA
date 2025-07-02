#include "../stdc++.h"
using namespace std;

int solve(int i, int j, int rows, int cols, vector<vector<int> >& grid, vector<vector<int> >& dp){
    if(i < 0 || j < 0) return INT_MAX;
    if(i==0 && j==0) return grid[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    int left = solve(i, j-1, rows, cols, grid, dp);
    int up = solve(i-1, j, rows, cols, grid, dp);

    return dp[i][j] = min(left, up) + grid[i][j];
}

int minPathSum(vector<vector<int> >& grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int> >dp(n, vector<int>(m, -1));
    return solve(n-1, m-1, n, m, grid, dp);
}

int minPathSumBoUp(vector<vector<int> >& grid){
    int n = grid.size();
    int m = grid[0].size();
    if(n == 1 && m == 1) return grid[0][0];

    vector<vector<int> > dp(n, vector<int>(m));
    dp[0][0] = grid[0][0];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i == 0 && j == 0){
                continue;
            }
            int up = INT_MAX;
            if(i - 1 >= 0){
                up = dp[i-1][j];
            }
            int left = INT_MAX;
            if(j - 1 >= 0){
                left = dp[i][j-1];
            }
            dp[i][j] = min(left, up) + grid[i][j]; 
        }
    }

    return dp[n-1][m-1];
}

int minPathSumSpOp(vector<vector<int> >& grid){
    int n = grid.size();
    int m = grid[0].size();
    if(n == 1 && m == 1) return grid[0][0];

    vector<int> prev(m, INT_MAX);
    int left = -1;
    for(int i=0; i<n; i++){
        vector<int> tempArr(m, -1); 
        for(int j=0; j<m; j++){
            if(i==0 && j==0){
                left = grid[0][0];
                tempArr[0] = left;
                continue;
            }
            int up = prev[j];
            tempArr[j] = min(up, left) + grid[i][j];
            left = tempArr[j];  
        }
        prev = tempArr;
        left = INT_MAX;
    }

    return prev[m-1];
}

int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int> > grid(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int temp;
            cin>>temp;
            grid[i][j] = temp;
        }
    }

    int ans = minPathSumSpOp(grid);
    cout<<ans;
    return 0;
}