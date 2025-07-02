#include "../stdc++.h"
using namespace std;

int printLIS(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> hash(n, 0);
    for(int i=0; i<n; i++){
        hash[i] = i;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(nums[j] < nums[i]){
                if(1+dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
        }
    }
    int idxWithLIS = -1;
    int LIS = 0;
    for(int i=0; i<n; i++){
        if(dp[i] > LIS){
            LIS = dp[i];
            idxWithLIS = i;
        }
    }
    // for(int i=0; i<n; i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    for(int i=0; i<n; i++){
        cout<<hash[i]<<" ";
    }
    cout<<endl;
    vector<int> ans(LIS, 0);
    cout<<LIS<<endl;
    while(true){
        cout<<idxWithLIS<<" ";
        ans[LIS-1] = nums[idxWithLIS];
        LIS--;
        if(idxWithLIS == hash[idxWithLIS]) break;
        idxWithLIS = hash[idxWithLIS];
    }
    cout<<endl;
    for(int i=ans.size()-1; i>=0; i--){ cout<<ans[i]<<' ';
    }
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
    cout<<printLIS(nums);
    return 0;

}