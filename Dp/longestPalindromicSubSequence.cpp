#include "../stdc++.h"
using namespace std;


// THIS IS WRONG VERY VERY WRONG!!!!!!!!!!!!!!!!!!!!!!!!


// int longestPalindromicSubSeqBoUp(string& a){
//     int n = a.size();
//     vector<vector<int> > dp(n, vector<int>(n, 0));
//     int ans = 0;
//     for(int ind2=0; ind2<n; ind2++){
//         for(int ind1=0; ind1<n; ind1++){
//             if(ind1 == ind2){
//                 dp[ind1][ind2] = 1;
//             }else{
//                 if(ind1 < ind2){
//                     dp[ind1][ind2] = -1;
//                 }else{
//                     if(a[ind1] == a[ind2]){
//                         dp[ind1][ind2] = 2+dp[ind1+1][ind2-1];
//                     }else{
//                         dp[ind1][ind2] = max(dp[ind1+1][ind2], dp[ind1][ind2+1]);
//                     }
//                 }
//             }
//             ans = max(ans, dp[ind1][ind2]);
//         }
//     }
//     return ans;
// }


// approach: reverse the given string and find the LCS between the reversed and the orginal string

int longestPalindromicSubSeqBoUp(string& a){
    int n = a.size();
    string b = "";
    for(int i=n-1; i>-1; i--){
        b.push_back(a[i]);
    }

    vector<int> prev(n+1, 0), curr(n+1, 0);
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(a[i-1] == b[j-1]){
                curr[j] = 1 + prev[j-1];
            }else{
                curr[j] = max(prev[j-1], curr[j-1]);
            }
        }
        prev = curr;
    }
    return prev[n];
}


int f(int ind1, int ind2, string& a, vector<vector<int> >& dp){
    if(ind1 > ind2) return 0;
    if(ind1 == ind2) return 1;
    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    if(a[ind1] == a[ind2]){
        return 2+f(ind1+1, ind2-1, a, dp);
    }
    return dp[ind1][ind2] = max(f(ind1+1, ind2, a, dp), f(ind1, ind2-1, a, dp));
}

int longestPalindromicSubSeq(string& a){
    int n = a.size();
    vector<vector<int> > dp(n, vector<int>(n, -1));
    return f(0, n-1, a, dp);
}

int main(){


    return 0;

}