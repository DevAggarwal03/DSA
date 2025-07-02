#include "../stdc++.h"
using namespace std;

// sliding window does not work for -ve numbers, so use hashing and prefix sum for -ve numbers
int subArrGivenSum(vector<int> nums, int k){
    int i = 0;
    int j = 0;
    int ans = 0;
    int sum = 0;
    for(int l = 0; l<nums.size(); l++){
        if(j >= nums.size()){
            break;
        }
       sum+=nums[l];
       while(sum > k && i <= j){
            sum -= nums[i];
            i++;
       }
       if(sum == k){
            // j++;
            ans++;
       }
       j+=1;
    }
    // [1,1,1] k=2

    return ans;
}

//using hashmap
int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> subNum;
        subNum[0] = 1;
        int total = 0, count = 0;

        for (int n : nums) {
            total += n;

            if (subNum.find(total - k) != subNum.end()) {
                count += subNum[total - k];
            }

            subNum[total]++;
        }

        return count;
    }

int main(){
    int a;
    cin>>a;
    vector<int> arr;
    for(int i=0; i<a; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    int target;
    cin>>target;
    int ans = subarraySum(arr, target);
    cout<<ans;

    return 0;

}