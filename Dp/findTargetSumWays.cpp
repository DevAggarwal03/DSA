#include "../stdc++.h"
using namespace std;

int adjustInd(int n, int sum){
    return n + sum;
}

int findTargetSumWaysBoUp(vector<int>& nums, int target){
    int n = nums.size();
    int sum = 0;
    for(auto it: nums) sum += it;
    vector<vector<int> > dp(n, vector<int>((2*sum) + 1, 0));
         
}

int f(int curr, int ind, vector<int>& nums, int target){
    if(ind == 0){
        if(nums[0] == 0 && target == curr) return 2;
        if(curr + nums[0] == target || curr - nums[0] == target) return 1;
        else return 0;
    }

    int add = f(curr + nums[ind], ind-1, nums, target);
    int sub = f(curr - nums[ind], ind-1, nums, target);

    return add + sub;
}

int findTargetSumWays(vector<int>& nums, int target) {
    return f(0, nums.size()-1, nums, target);            
}

int main(){


    return 0;

}