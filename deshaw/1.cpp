#include "../stdc++.h"
using namespace std;

int f(vector<int>& arr, int k){
    int n = arr.size();
    if(k >= n) return 0;
    if(k == 0){
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += arr[i];
        }
        return ans;
    }
    if(k==1){
        int total = 0;
        for(int i=0; i<n-1; i++){
            total += abs(arr[i] - arr[i+1]);
        }
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            
        }
        

    }
    int maxCost = 0;
    int sum = 0;
    for(int i=0; i<k-1; i++){
        sum += abs(arr[i] - arr[i+1]);
    }
    maxCost = sum;

    int endInd = 1;
    for(int i=k; i<n; i++){
        sum += abs(arr[i] - arr[i-1]);
        sum -= abs(arr[endInd] - arr[endInd - 1]);
        endInd++;
        maxCost = max(maxCost, sum);
    }

    int totalCost = 0;
    for(int i=0; i<n; i++){
        totalCost += arr[i];
    }
    return totalCost - maxCost;
}

// [3, 5, 6, 2, 6] k = 3;

int main(){
    int n;
    int k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<f(arr, k);
    

    return 0;

}