#include "../stdc++.h"
using namespace std;

int bs(int s, int e, vector<int>& bucket, int element){
    int mid = (s + e) / 2;
    while(s<e){
        if(bucket[mid] < element){
            s = mid + 1;
        }
        if(bucket[mid] > element){
            e = mid;
        }
        if(bucket[mid] == element) return mid;

        mid = (s + e) / 2;
    }
    return s;
}

int LIS(vector<int>& nums){
    vector<int> bucket;
    for(int i=0; i<nums.size(); i++){
        if(bucket.size() == 0 || nums[i] > bucket.back()){
            bucket.push_back(nums[i]);
        }else{
            int idx = bs(0, bucket.size()-1, bucket, nums[i]);
            bucket[idx] = nums[i];
        }
    }
    return bucket.size();
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
    cout<<LIS(nums);

    return 0;

}