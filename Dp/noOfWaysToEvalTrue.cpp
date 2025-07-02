#include "../stdc++.h"
using namespace std;

int countWaysBoUp(string& s){

}

int f(int s, int e, bool want, string& expression, vector<vector<vector<int> > >& dp){
    if(s > e) return 0;
    if(s==e){
        if(want && expression[s]=='T') return 1;
        else if(!want && expression[s]=='F') return 1;
        else return 0;
    }
    if(dp[s][e][want] != -1) return dp[s][e][want];
    int ways = 0;
    for(int ind=s+1; ind<=e-1; ind+=2){
        char op = expression[ind]; 
        int lt = f(s, ind-1, true, expression, dp);
        int rt = f(ind+1, e, true, expression, dp);
        int lf = f(s, ind-1, false, expression, dp);
        int rf = f(ind+1, e, false, expression, dp);
        if(op == '&'){
            if(want){
                ways += rt * lt;
            }else{
                ways += (rf*lt) + (rt*lf) + (rf*lf);
            }
        }else if(op == '|'){
            if(want){
                ways += (rf*lt) + (rt*lf) + (rt*lt);
            }else{
                ways += (rf*lf);
            }
        }else{
            if(want){
                ways += (lt*rf) + (lf*rt);
            }else{
                ways += (lf*rf) + (lt*rt);
            }
        }
    }
    return dp[s][e][want] = ways;
}

int countWays(string &s) {
    // code here
    int n = s.size();
    vector<vector<vector<int> > > dp(n, vector<vector<int> >(n, vector<int>(2, -1)));
    return f(0, n-1, true, s, dp);
}

int main(){
    int n;
    cin>>n;
    string expression(n, 'f');
    for(int i=0; i<n; i++){
        char temp;
        cin>>temp;
        expression[i] = temp;
    }
    cout<<countWays(expression);

    return 0;

}