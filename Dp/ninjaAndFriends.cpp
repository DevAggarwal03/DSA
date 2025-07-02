#include "../stdc++.h"
using namespace std;

int solve(int i, int j1, int j2, int rows, int cols, vector<vector<int> >& grid, vector<vector<vector<int> > >& dp){
    if(j1 >= cols || j2 >= cols || j1 < 0 || j2 < 0) return -1e8;
    if(i == rows - 1){
        if(j1 == j2) return grid[i][j1];
        else return (grid[i][j1] + grid[i][j2]);
    }
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    int maxi = 0;
    for(int i=-1; i<2; i++){
        for(int j=-1; j<2; j++){
            if(j1 == j2){
                maxi = max(maxi, grid[i][j1] + solve(i+1, j1+i, j2+j, rows, cols, grid, dp));
            }else{
                maxi = max(maxi, grid[i][j1] + grid[i][j2] + solve(i+1, j1+i, j2+j, rows, cols, grid, dp));
            }
        }
    }

    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int> > &grid) {
    vector<vector<vector<int> > > dp(r, (vector<vector<int> >(c, vector<int>(c, -1))));
    return solve(0, 0, c-1, r, c, grid, dp);
}

int main(){


    return 0;

}