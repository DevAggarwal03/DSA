#include "../stdc++.h"
using namespace std;

void build(int ind, int low, int high, vector<vector<int> >& seg, string& s){
    if(low == high){
        if(s[low] == '('){
            seg[ind][0] = 1;
            seg[ind][1] = 0;
            seg[ind][2] = 0;
        }else{
            seg[ind][1] = 1;
            seg[ind][0] = 0;
            seg[ind][2] = 0;
        }
        return;
    }
    int mid = (low + high) / 2;
    build(2*ind+1, low, mid, seg, s);
    build(2*ind+1, mid+1, high, seg, s);
    int full = seg[2*ind + 1][2] + seg[2*ind + 2][2] + min(seg[2*ind+1][0], seg[2*ind+2][1]);
    int open = seg[2*ind + 2][0] + seg[2*ind + 1][0] - min(seg[2*ind+1][0], seg[2*ind+2][1]); 
    int close = seg[2*ind + 1][1] + seg[2*ind + 2][1] - min(seg[2*ind+1][0], seg[2*ind+2][1]);
    seg[ind][0] = open;
    seg[ind][1] = close;
    seg[ind][2] = full;
    return;
}

vector<int> query(int ind, int low, int high, int l, int r, vector<vector<int> >& seg){
    if(r < low || l > high){
        return vector<int>(3, 0);
    }
    if(l<=low && high<=r){
        return seg[ind];
    }
    int mid = (low + high) / 2;
    vector<int> left = query(2*ind + 1, low, mid, l, r, seg);
    vector<int> right = query(2*ind + 2, mid+1, high, l, r, seg);

    int full = left[2] + right[2] + min(left[0], right[1]);
    int open = right[0] + left[0] - min(left[0], right[1]); 
    int close = left[1] + right[1] - min(left[0], right[1]);
    vector<int> ans;
    ans.push_back(open);
    ans.push_back(close);
    ans.push_back(full);
    return ans; 
}

int main(){
    string str;
    cin>>str;
    vector<vector<int> > seg(4*str.size() + 1, vector<int>(3, 0));
    build(0, 0, str.size() - 1, seg, str);
    int n;
    cin>>n;
    while(n--){
        int l, r;
        cin>>l>>r;
        cout<<query(0, 0, str.size()-1, l, r, seg)[2];
    }
    return 0;

}