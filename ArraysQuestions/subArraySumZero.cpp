#include "../stdc++.h"
using namespace std;

// x + {sub array with sum 0} = x  (this is the intution behind this approach)

vector<int> isSubArraySumZero(vector<int> arr){
    // unordered_set<int> set;
    unordered_map<int, int> mp;
    vector<int> ans;
    int sum = 0;
    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
        if(sum == 0){
            ans.push_back(i);
            return ans;
        }
        auto it = mp.find(sum);
        if(it != mp.end()){
            int start = it->second;
            for(int j=start+1; j<=i; j++){
                ans.push_back(arr[j]);
            }
            return ans;
        }
        mp[sum] = i;
    }
    return ans;
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

    // int ans = findSumClosesToZero(arr);
    vector<int> ans = isSubArraySumZero(arr);
    if(ans.size() == 0){
        cout<<-1;
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    
}