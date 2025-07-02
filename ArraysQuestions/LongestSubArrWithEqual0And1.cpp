#include "../stdc++.h"
using namespace std;

// using hashmap and prefix sum: here take 0 as -1 while adding to the sum
// here we have to find the max length hence we are not updating the sum which is already there

int solve(vector<int> nums){
    int maxLen = 0;
    int currSum = 0;
    unordered_map<int, int> mp;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] == 0){
            currSum--;
        }else{
            currSum++;
        }
        if(currSum == 0){
            maxLen = i+1;
        }else{
            if(mp.find(currSum) != mp.end()){
                int len = i - mp.find(currSum)->second;
                maxLen = max(maxLen, len);
            }
        }
        if(mp.find(currSum) == mp.end()){
            mp[currSum] = i;
        }
    }

    return maxLen;
}

int main(){


    return 0;

}