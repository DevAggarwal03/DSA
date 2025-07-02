#include "../stdc++.h"
using namespace std;

int rob1(vector<int>& nums, int st, int end, int ind){
    int prev2 = 0;
    int prev = nums[ind];
    for(int i=ind+1; i<=end; i++){
        int taken = prev2 + nums[i];
        int notTaken = prev;
        int temp = max(taken, notTaken);
        prev2 = prev;
        prev = temp;
    }
    return prev;
}

int rob(vector<int>& nums){
    int ans1 = rob1(nums, 0, nums.size() - 2, 0);
    int ans2 = rob1(nums, 1, nums.size() - 1, 1);
    return max(ans2, ans1);
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n, 0);
    for(int i=0; i<n ;i++){
        int temp;
        cin>>temp;
        nums[i] = temp;
    }

    cout<<rob(nums)<<endl;

    return 0;

}