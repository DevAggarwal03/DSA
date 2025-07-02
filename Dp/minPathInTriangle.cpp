#include "../stdc++.h"
using namespace std;

int solve(int i, int j, int height, vector<vector<int> >& triangle, vector<vector<int> >& dp){
    if(i+1 == height) return triangle[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    int left = solve(i+1, j, height, triangle, dp);
    int right = solve(i+1, j+1, height, triangle, dp);

    return dp[i][j] = min(left, right) + triangle[i][j];
}

int minimumTotal(vector<vector<int> >& triangle){
    int n = triangle.size();
    vector<vector<int> > dp(n, vector<int>(n, -1));
    return solve(0, 0, n, triangle, dp);
}

int minimumTotalBoUp(vector<vector<int> >& triangle){
    int n = triangle.size();
    if(n == 1) return triangle[0][0];

    vector<vector<int> > dp(n, vector<int>(n, 0));
    dp[0][0] = triangle[0][0];
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(j == 0 || j == i){
                if(j==0){
                    dp[i][j] = dp[i-1][j] + triangle[i][j]; 
                }else{
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                }
            }else{
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
            }
        }
    }

    int ans = INT_MAX;
    for(int i=0; i<n; i++){
        ans = min(ans, dp[n-1][i]);
    }
    return ans;
}

int minimumTotalSpOp(vector<vector<int> >& triangle){
    int n = triangle.size();
    if(n==1) return triangle[0][0];

    vector<int> dp;
    dp.push_back(triangle[0][0]);
    for(int i=1; i<n; i++){
        vector<int> tempArr;
        for(int j=0; j<=i; j++){
            if(j==0 || j==i){
                if(j==0){
                    int temp = dp[j] + triangle[i][j];
                    tempArr.push_back(temp);
                }else{
                    int temp = dp[j-1] + triangle[i][j];
                    tempArr.push_back(temp);
                }
            }else{
                int temp = min(dp[j], dp[j-1]) + triangle[i][j];
                tempArr.push_back(temp);
            }
        }
        dp = tempArr;
        tempArr.clear();
    }

    int ans = INT_MAX;
    for(int i=0; i<n; i++){
        ans = min(ans, dp[i]);
    }
    return ans;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int> > triangle(n, vector<int>());
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            int temp;
            cin>>temp;
            triangle[i].push_back(temp);
        }
    }

    cout<<minimumTotal(triangle);
    return 0;
}