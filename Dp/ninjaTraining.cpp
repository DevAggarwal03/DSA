#include "../stdc++.h"
using namespace std;

int solve(int day, vector<vector<int> > &points, int prev, vector<vector<int> >& dp){
    int n = points.size();
    if(day < 0) return 0;
    if(dp[day][prev] != -1) return dp[day][prev];

    int oneTaken = INT_MIN;
    if(prev != 0){
        oneTaken = solve(day - 1, points, 0, dp) + points[day][0];
    }
    int twoTaken = INT_MIN;
    if(prev != 1){
        twoTaken = solve(day - 1, points, 1, dp) + points[day][1];  
    }
    int threeTaken = INT_MIN;
    if(prev != 2){
        threeTaken = solve(day - 1, points, 2, dp) + points[day][2];  
    }
    int ans = max(threeTaken, max(twoTaken, oneTaken));
    
    return dp[day][prev] = ans;;
}

int ninjaTraining(int n, vector<vector<int> > &points){
    vector<vector<int> > dp(n, vector<int>(4, -1));
    return solve(n-1, points, 3, dp);
}

int ninjaTrainingSpOp(int n, vector<vector<int> >& points){
    vector<int> prev(3, -1);
    for(int i=0; i<3; i++){
        prev[i] = points[0][i];
    }

    int i=1;
    while(n>0 && i<n){
        vector<int> temp(3, -1);
        for(int j=0; j<3; j++){
            int res = points[i][j] + max(prev[(j+1) % 3], prev[(j+2) % 3]);
            temp[j] = res; 
        }
        for(int j=0; j<3; j++){
            prev[j] = temp[j];
        }
        i++;
    }

    int ans = 0;
    for(int i=0; i<3; i++){
        ans = max(ans, prev[i]);
    }
    return ans;
}

int ninjaTrainingBoUp(int n, vector<vector<int> >& points){
    int last = 3;
    vector<vector<int> > dp(n, vector<int>(3, -1));
    for(int i=0; i<3; i++){
        dp[0][i] = points[0][i];
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<3; j++){
            int res = points[i][j] + max(dp[i-1][(j+1) % 3], dp[i-1][(j+2) % 3]);
            dp[i][j] = res;
        }
    }
    
    int ans = 0;
    for(int i=0; i<3; i++){
        ans = max(ans, dp[n-1][i]);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int> > points(n, vector<int>(3));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            int temp;
            cin>>temp;
            points[i][j] = temp;
        }
    }
    cout<<ninjaTraining(n, points);
    return 0;
}