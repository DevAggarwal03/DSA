#include "../stdc++.h"
using namespace std;

// int f(vector<int> v1, vector<int> v2, int s1, int s2, int ind, vector<int>& nums){
//     if(ind == 0){
//         if(v1.size() == v2.size()+1){
//             s2 += nums[0];
//             return abs(s1 - s2);
//         }else if(v1.size() + 1 == v2.size()){
//             s1 += nums[0];
//             return abs(s2 - s1);
//         }else{
//             return 1e9;
//         }
//     }

//     v1.push_back(nums[ind]);
//     int s1Taken = f(v1, v2, s1+nums[ind], s2, ind-1, nums);
//     v1.pop_back();
//     v2.push_back(nums[ind]);
//     int s2Taken = f(v1, v2, s1, s2+nums[ind], ind-1, nums);
//     v2.pop_back();

//     return min(s1Taken, s2Taken);
// } 


int minimumDifference(vector<int>& nums) {
    int sum = 0;
    for(auto it: nums) sum += it;
    vector<pair<bool,int> > dp(nums.size(), make_pair(false, 0));
    dp[0].first = true;

    for(int i=1; i<nums.size(); i++){
        vector<pair<bool, int> > temp(nums.size(), make_pair(false, 0));
        temp[0].first = true;
        for(int j=1; j<sum+1; j++){
            bool notTaken = dp[j].first;
            bool taken = false;
            if(nums[i] <= j){
                taken = dp[j - nums[i]].first;
            }
            if(taken == true){
                temp[j] = make_pair(true, dp[j].second+1);  
            }else{
                temp[j] = make_pair(notTaken, dp[j].second);
            }
        }
        dp = temp;
    }
    int ans = 1e9;
    for(int i=0; i<sum+1; i++){
        if(dp[i].second == nums.size() / 2){
            int diff = abs(i - (sum - i));
            ans = min(ans, i);
        }
    }
    return ans;
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

    cout<<minimumDifference(nums);

    return 0;

}