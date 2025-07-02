#include "../stdc++.h"
using namespace std;

// int f(int ind, int d, int s1, int s2, vector<int> v1, vector<int> v2, vector<int>& arr){
//     if(abs(s1 - s2) == d){
//         if(v1.size() >= v2.size()){
//             return 1;
//         }
//         else return 0;
//     }
//     if(ind == 0){
//         if(abs((s1 + arr[0]) - s2) == d){
//             if(v1.size() + 1 >= v2.size()) return 1;
//         }else if(abs((s2 + arr[0]) - s1) == d){
//             if(v2.size() + 1 <= v1.size()) return 1;
//         }else return 0;
//     }

//     v1.push_back(arr[ind]);
//     int s1Taken = f(ind-1, d, s1+arr[ind], s2, v1, v2, arr);
//     v1.pop_back();
//     v2.push_back(arr[ind]);
//     int s2Taken = f(ind-1, d, s1, s2+arr[ind], v1, v2, arr);
//     v2.pop_back();

//     return s1Taken + s2Taken;
// }

// int countPartitions(int n, int d, vector<int> &arr) {
//     return f(n-1, d, 0, 0, vector<int>(), vector<int>(), arr);
// }

int f(int n, int tar, vector<int> &arr) {
    int sum = 0;
    for(auto it: arr) sum += it;
    vector<int> dp(sum+1, 0);
    int noOfZeros = 1;
    if(arr[0] == 0) dp[0] = 2;
    else dp[0] = 1;

    if(arr[0] <= sum && arr[0] != 0) dp[arr[0]] = 1;

    for(int i=1; i<n; i++){
        vector<int> temp(sum+1, 0);
        for(int j=1; j<sum+1; j++){
            int notTaken = dp[j];
            int taken = 0;
            if(arr[i] <= j){
                taken = dp[j-arr[i]];
            }
            temp[j] = taken + notTaken;
        }
        dp = temp;
    }
    
    return dp[tar];   
}

int countPartitions(int n, int d, vector<int>& arr){
    int sum = 0;
    for(auto it: arr) sum+=it;
    if(sum - d < 0 || (sum - d) % 2) return 0;
    return f(n, (sum - d)/2, arr);
}

int main(){
    int n, d;
    cin>>n;
    vector<int> arr(n, -1);
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        arr[i] = temp;
    }
    cin>>d;
    cout<<countPartitions(n, d, arr);

    return 0;

}