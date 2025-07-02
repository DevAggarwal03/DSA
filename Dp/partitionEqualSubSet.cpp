#include "../stdc++.h"
using namespace std;

bool canPartitionBoUp(vector<int>& nums){
    int sum = 0;
    int n = nums.size();
    for(auto it: nums){
        sum += it;
    }
    if(sum % 2 != 0) return false;
    vector<vector<bool> > dp(nums.size(), vector<bool>(sum/2+1));
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    dp[0][nums[0]] = true;
    for(int i=1; i<n; i++){
        for(int j=1; j<sum/2+1; j++){
            int notTaken = dp[i-1][j];
            int taken = false;
            if(nums[i] <= j){
                taken = dp[i-1][j - nums[i]];
            }
            dp[i][j] = notTaken | taken;
        }
    }

    return dp[n-1][sum/2];
}

bool f(int total, int ind, int sum, vector<int>& nums, vector<vector<int> >& dp){
    if(total == sum/2) return true;
    if(ind == 0) return (total - nums[0] == sum/2 | total == sum/2);
    if(dp[ind][total] != -1) return dp[ind][total];

    int notTaken = f(total, ind-1, sum, nums, dp);
    if(notTaken) return true;
    int taken = false;
    if(total - nums[ind] >= sum/2){
        taken = f(total - nums[ind], ind - 1, sum, nums, dp);
    } 

    return dp[ind][total] = (taken | notTaken);
}

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for(auto it: nums){
        sum += it;
    }
    if(sum % 2 != 0) return false;
    vector<vector<int> > dp(nums.size(), vector<int>(sum+1, -1));
    return f(sum, nums.size() - 1, sum, nums, dp); 
}

int main(){


    return 0;

}