#include "../stdc++.h"
using namespace std;

int lcsBoUp(string& a, string& b){
    int n = a.size();
    int m = b.size();
    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
    
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(a[i] == b[j]){
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
            }
            else{
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }

    return dp[n][m];
}

int f(int i1, int i2, string& a, string& b){

    if(i1 < 0 || i2 < 0){
        return 0;
    }

    // if(i1 == 0 || i2 == 0){
    //     if(a[i1] == b[i2]) return 1;
    //     return 0;
    // }

    if(a[i1] == b[i2]){
        return 1 + f(i1-1, i2-1, a, b);
    }
    return max(f(i1-1, i2, a, b), f(i1, i2-1, a, b));
}

int lcs(string& a, string& b){
    int ind1 = a.size()-1;
    int ind2 = b.size()-1;
    return f(ind1, ind2, a, b);
}

int main(){
    string a, b;
    cin>>a;
    cin>>b;
    cout<<lcsBoUp(a, b);
    return 0;

}