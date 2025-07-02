#include "../stdc++.h"
using namespace std;
// return the max sum of a subarray in TC: O(n);
int kadanesAlgorithm(vector<int> arr){
    int maxSum = INT_MIN;
    int ending = 0;
    for(int i=0; i<arr.size(); i++){
        if(ending < 0){
            ending = 0;
        }
        ending = ending + arr[i];
        if(ending > maxSum){
            maxSum = ending;
        }
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

    int maxSum = kadanesAlgorithm(arr);
    cout<<maxSum<<endl;
    return 0;

}