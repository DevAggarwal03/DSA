#include "../stdc++.h"
using namespace std;

int solve(int ind, vector<int>& nums, vector<int>& dp){
    if(ind < 0) return 0;
    if(dp[ind] != -1){
        return dp[ind];
    }
    if(ind == 0) return nums[0];

    int notTaken = solve(ind-1, nums, dp);
    int taken = solve(ind-2, nums, dp) + nums[ind];

    return dp[ind] = max(notTaken, taken);
}

int robBoUp(vector<int>& nums){
    int n = nums.size();
    if(n==0) return 0;
    if(n == 1) return nums[0];
    vector<int> dp(nums.size());
    for(int i=1; i<n; i++){
        int take = INT_MIN;
        if(i-2>0){
            take = dp[i-2] + nums[i];
        }
        int notTake = dp[i-1];
        dp[i] = max(notTake, take);
    }

    return dp[n-1];
}

int rob(vector<int>& nums){
    vector<int> dp(nums.size(), -1);
    return solve(nums.size() - 1, nums, dp);
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n, 0);
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        nums[i] = temp;
    }
    cout<<rob(nums)<<endl;

    return 0;

}