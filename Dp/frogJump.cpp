#include "../stdc++.h"
using namespace std;

int solve(vector<int>& arr, int curr, vector<int>& memTable){
    if(curr == 0) return 0;
    if(memTable[curr] != -1) return memTable[curr];

    int left = solve(arr, curr-1, memTable) + abs(arr[curr] - arr[curr - 1]);
    int right = INT_MAX;
    if(curr - 2 >= 0){
        right = solve(arr, curr-2, memTable) + abs(arr[curr] - arr[curr - 2]);
    }

    return memTable[curr] = min(left, right);
}

// int frongJumpBoUp(vector<int> arr){
//     int n = arr.size();
//     if (n == 1) return 0;
//     vector<int> dp(n, -1);
//     dp[1] = abs(arr[1] - arr[0]);
//     if(n==2) return dp[1];
//     dp[0] = 0;
//     for(int i=2; i<n; i++){
//         dp[i] = min(abs(arr[i] - arr[i-1]) + dp[i-1], abs(arr[i] - arr[i-2]) + dp[i-2]);
//     }
//     return dp[n-1];
// }

int frongJumpBoUp(vector<int> arr){
    int n = arr.size();
    if(n == 0 || n == 1) return 0;
    if(n == 2) return abs(arr[0] - arr[1]);
    int prev2 = 0;
    int prev = abs(arr[1] - arr[0]);
    for(int i=2; i<n; i++){
        int temp = min(abs(arr[i] - arr[i-1]) + prev, abs(arr[i] - arr[i-2]) + prev2);
        prev2 = prev;
        prev = temp;
    }
    return prev;
}

int frogJump(vector<int> arr){
    int n = arr.size();
    vector<int> memTable(arr.size(), -1);
    return solve(arr, n-1, memTable);
}

int main(){

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        arr[i] = temp; 
    }
    int ans = frongJumpBoUp(arr);
    cout<<ans<<endl;
    return 0;
}