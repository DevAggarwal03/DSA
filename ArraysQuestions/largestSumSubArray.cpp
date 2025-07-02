#include "../stdc++.h"
using namespace std;

int findMaxSumSubArray(vector<int> arr){
    vector<int> ans;
    int maxSum = INT_MIN;
    int currSum = 0;
    int currStart = 0;
    int resStart = 0, resEnd = 0;
    for(int i=0; i<arr.size(); i++){
      if(currSum + arr[i] > arr[i]){
        currSum = currSum + arr[i];
        if(currSum > maxSum){
            if(resStart != currStart){
                resStart = currStart;
            }
            maxSum = currSum;
            resEnd = i;
        }
      }else{
        currStart = i;
        currSum = arr[i];
        if(currSum > maxSum){
            if(resStart != currStart){
                resStart = currStart;
            }
            maxSum = currSum;
            resEnd = i;
        }
      }
    }


    for(int i=resStart; i<=resEnd; i++){
        cout<<arr[i]<<" ";
    }

    return maxSum;
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

    int maxSum = findMaxSumSubArray(arr);
    cout<<endl;
    cout<<maxSum<<endl;
    return 0;

}