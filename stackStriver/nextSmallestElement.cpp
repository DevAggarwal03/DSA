#include "../stdc++.h"
using namespace std;

vector<int> nse(vector<int>& arr){
    stack<int> st;
    vector<int> ans(arr.size(), -1);
    for(int i=0; i<=arr.size()-1; i++){
        while(!st.empty() && st.top() > arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        arr[i] = temp;
    }

    cout<<endl;
    vector<int> ans = nse(arr);
    for(auto it: ans){
        cout<<it<<" ";
    }

    return 0;

}