#include "../stdc++.h"
using namespace std;

int solve(int i, int j, int rows, int cols, vector<vector<int> >& obstacleGrid, vector<vector<int> >& dp){
    if(i >= rows || j >= cols || i<0 || j<0 || obstacleGrid[i][j] == 1) return 0;
    if(i == 0 && j == 0) return 1;
    if(dp[i][j] != -1) return dp[i][j];

    int left = solve(i, j-1, rows, cols, obstacleGrid, dp);
    int right = solve(i-1, j, rows, cols, obstacleGrid, dp);

    return dp[i][j] = left + right;
}

int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<vector<int> > dp(n, vector<int>(m, -1));
    return solve(n-1, m-1, n, m, obstacleGrid, dp);        
}

int uniquepathsWithObstaclesBoUp(vector<vector<int> >& obstacleGrid){
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    if(n == 1 && m == 1){
        if(obstacleGrid[n][m] == 0) return 1;
        return 0;
    };
    vector<vector<int> > dp(n, vector<int>(m, -1));
    if(obstacleGrid[0][0] == 0){ 
        dp[0][0] = 1;
    }else{ 
        return 0; 
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i == 0 && j == 0){
                continue;
            }
            int left = 0;
            if(j-1 > 0 && obstacleGrid[i][j-1] != 1){
                left = dp[i][j-1];
            }
            int up = 0;
            if(i-1 > 0 && obstacleGrid[i-1][j] != 1){
                up = dp[i-1][j];
            }
            dp[i][j] = left + up;
        }
    } 
    return dp[n-1][m-1];
}

int uniquePathsWithObstaclesSpOp(vector<vector<int> >& obstacleGrid){
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    if(obstacleGrid[0][0] == 1) return 0;
    vector<int> dp(m, 0);
    int left = 0;
    for(int i=0; i<n; i++){ 
        vector<int> tempArr(m, -1);
        for(int j=0; j<m; j++){
            if(i == 0 && j == 0){
                left = 1;
                tempArr[0] = 1;
                continue;
            }
            if(obstacleGrid[i][j] == 1){
                tempArr[j] = 0;
                left = 0;
                continue;
            } 
            int temp = dp[j] + left;
            tempArr[j] = temp;
            left = temp;
        }
        dp = tempArr;
        left = 0;
        tempArr.clear();
    }
    return dp[m-1];
}

int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int> > obstacleGrid(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int temp;
            cin>>temp;
            obstacleGrid[i][j] = temp;
        }
    }
    cout<<uniquePathsWithObstaclesSpOp(obstacleGrid);

    return 0;

}