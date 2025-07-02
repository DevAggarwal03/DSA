#include "../stdc++.h"
using namespace std;

class SegTree{
    vector<int> seg;
public:
    SegTree(int n){
        seg.resize(4*n + 1);
    }

    bool build(int ind, int low, int high, vector<int>& arr){
        if(low == high){
            seg[ind] = arr[low];
            return true;
        }

        int mid = (low + high) >> 1;
        int ans = build(2*ind+1, low, mid, arr);
        ans = build(2*ind+2, mid+1, high, arr);
        if(ans&1){
            seg[ind] = seg[2*ind+1] | seg[2*ind+2];
        }else{
            seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
        }
        return !ans;
    }

    pair<int,bool> update(int ind, int low, int high, int i, int val, vector<int>& arr){
        if(low == high){
            // cout<<val<<" ";
            seg[ind] = val;
            return make_pair(val, true);
        }

        int mid = (low + high) >> 1;
        pair<int,bool> ans;
        if(i <= mid){
            ans = update(2*ind + 1, low, mid, i, val, arr);
        }else{
            ans = update(2*ind+2, mid+1, high, i, val, arr);
        }
        seg[ind] = ans.second&1 ? seg[2*ind + 1] | seg[2*ind + 2] : seg[2*ind + 1] ^ seg[2*ind + 2];
        return make_pair(seg[ind], !ans.second);
    }
};

int main(){
    int x, m;
    cin>>x>>m;
    int n = pow(2, x); 
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    SegTree st(n);
    st.build(0, 0, n-1, arr);
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        cout<<st.update(0, 0, n -1, a-1, b, arr).first;
        cout<<endl;
    }

    return 0;

}