#include "../stdc++.h"
using namespace std;

vector<int> find2RepeaterElements(vector<int> arr){
    vector<int> ans;
    int xorVal = 0;
    int n = arr.size() - 2;
    for(int i=0; i<arr.size(); i++){
        if(i>0 && i <= n){
            xorVal = xorVal^arr[i]^i;
        }else{
            xorVal = xorVal ^ arr[i];
        }
    }

    cout<<"xorval: "<<xorVal<<endl;

    xorVal = xorVal & (-1*xorVal);
    cout<<"xorval: "<<xorVal<<endl;

    int x = 0, y = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] & xorVal){
            x = arr[i] ^ x;
        }else{
            y = arr[i] ^ y;
        }
    }
    for(int i=1; i<=n; i++){
        if(i & xorVal){
            x = i ^ x;
        }else{
            y = i ^ y;
        }
    }

    ans.push_back(x);
    ans.push_back(y);

    return ans;


}

// using 2 loops
// using sorting
// product and sum (mathematics)
// using XOR and setBit (imp)


int main(){
    int a;
    cin>>a;
    vector<int> arr;
    for(int i=0; i<a; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    vector<int> ans = find2RepeaterElements(arr);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}
