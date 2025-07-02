#include "../stdc++.h"
using namespace std;

void moveZeros(vector<int>& nums){
    for(int i=0; i<nums.size(); i++){
        if(nums[i] == 0){
            int j = i+1;
            while(j < nums.size()){
                if(nums[j] != 0){
                    break;
                }
                j++;
            }
            swap(nums[i], nums[j]);
        }
    }
}

int main(){
    vector<int> nums;
    // [0,1,0,3,12]
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(12);
    nums.push_back(34);

    
    
    cout<<&nums;


    // moveZeros(nums);

    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }

}