#include "../stdc++.h"
using namespace std;

int solve(int row, int col, int rows, int cols, vector<vector<int> >& dp){
    if(row >= rows || col >= cols || row < 0 || col < 0) return 0;
    if(row == 0 && col == 0) return 1;
    if(dp[row][col] != -1) return dp[row][col];

    int down = solve(row-1, col, rows, cols, dp);
    int right = solve(row, col-1, rows, cols, dp);
    
    return dp[row][col] = (down + right);
}

int uniquePaths(int n, int m){
    vector<vector<int> > dp(n, vector<int>(m, -1));
    return solve(n-1, m-1, n, m, dp);
}

int uniquePathsBoUp(int n, int m){
    vector<vector<int> > dp(n, vector<int>(m, -1));
    vector<int> up(m, 0);
    int left = 1;
    for(int i=0; i<n; i++){
        vector<int> tempArr(m, -1);
        for(int j=0; j<m; j++){
            if(i == 0 && j == 0){ tempArr[0] = 1; left = 1; continue;};
            int temp = up[j] + left;
            tempArr[j] = temp;
            left = temp;
        }
        up = tempArr;
        left = 0;
    }
    return up[m-1];
}

int main(){
    int n;
    int m;
    cin>>n>>m;
    cout<<uniquePathsBoUp(n, m);

    return 0;

}