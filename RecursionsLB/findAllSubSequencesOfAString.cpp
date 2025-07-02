#include "../stdc++.h"

using namespace std;

void solve(string s, int index, string output, vector<string>& ans){
    if(index >= s.length()){
        ans.push_back(output);
        return;
    }

    //exclude
    solve(s, index + 1, output, ans);

    //include
    output.push_back(s[index]);
    index++;
    solve(s, index, output, ans);

}

vector<string > findSubSeq(string s){
    int index = 0;
    string ouput = "";
    vector<string> ans;

    solve(s, index, ouput, ans);
    return ans;
}

int main(){

    string x;
    cin>>x;

    vector<string> ans = findSubSeq(x);

    cout<<endl;

    for(int i=0; i<pow(2, x.length()); i++){
        if(ans[i].length() == 0){
            cout<<0;
        }else
        for(int j=0; j<ans[i].length(); j++){
                cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}