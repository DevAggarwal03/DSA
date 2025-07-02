#include "../stdc++.h"
using namespace std;
// naive: 2loops
// better: sort array then binary search
// better: sort array then 2 pointer
// expected: use unordered set to complement
pair<int,int> find2Sum(vector<int> arr, int target){
    unordered_set<int> set;
    pair<int,int> ans;
    bool isPresent = false;
    int i=0; 
    while(i<arr.size()){
        int complement = target - arr[i];
        if(set.find(complement) != set.end()){
            ans.first = i;
            isPresent = true;
            break;
        }
        set.insert(arr[i]);
        i++;
    }
    if(isPresent){
        int complement = target - arr[ans.first];
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == complement){
                ans.second = i;
            }
        }
        return ans;
    }else{
        return pair<int,int>(-1, -1);
    }

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
    int target;
    cin>>target;

    pair<int,int> ans = find2Sum(arr, target);
    cout<<endl;
    cout<<ans.first<<" "<<ans.second<<endl;
}