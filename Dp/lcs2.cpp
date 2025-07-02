#include "../stdc++.h"
using namespace std;

string lcs(string& a, string& b){
    int n = a.size();
    int m = b.size();
    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string ans = "";
    for(int i=1; i<m+1; i++){
        if(dp[n][i] != dp[n][i-1]){
            ans.push_back(b[i-1]);
        }
    }
    return ans;
}

int main(){
    string a;
    string b;
    cin>>a>>b;
    cout<<lcs(a, b);

    return 0;

}