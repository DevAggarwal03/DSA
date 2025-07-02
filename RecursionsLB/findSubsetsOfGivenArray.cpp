#include "../stdc++.h"

using namespace std;


void solve(vector<int> nums, int index, vector<int> output, vector<vector<int> >& ans){
    if(index >= nums.size()){
        ans.push_back(output);
        return;
    }

    //exclude
    solve(nums, index + 1, output, ans);

    //inlcude
    output.push_back(nums[index]);
    index++;
    solve(nums, index, output, ans);
}


vector<vector<int> > findSubSet(vector<int> nums){
    vector<vector<int> > ans;
    int index = 0;
    vector<int> output;

    solve(nums, index, output, ans);
    return ans;
}

int main(){
    int n;

    cin>>n;
    vector<int> inputArr;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        inputArr.push_back(x);
    }

    vector<vector<int> > ans = findSubSet(inputArr);

    for(int i=0; i<pow(2, n); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}