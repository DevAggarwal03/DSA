#include "../stdc++.h"
using namespace std;

vector<int> reverseArray(vector<int> arr, int start, int end){
    if(start >= end){
        return arr;
    }
    swap(arr[start], arr[end]);
    return reverseArray(arr, start+1, end-1);
}

bool checkPalindrome(string a, string b){
    if(a.length() == b.length()){
        cout<<b<<" ";
        if(a == b) return true;
        else return false;
    }
    b = b + a[a.length() - 1 - b.length()];
    // cout<<b<<" ";
    return checkPalindrome(a, b);
}

bool checkPalindrome2(string &a, int cnt){
    if(cnt >= a.length()/2){
        return true;
    }
    if(a[cnt] != a[a.length() - 1 - cnt]){
        return false;
    }
    return checkPalindrome2(a, cnt + 1);
}

int main(){
    // vector<int> v;
    // v.push_back(23);
    // v.push_back(33);
    // v.push_back(34);
    // v.push_back(55);
    // v.push_back(234);
    // vector<int> v1(reverseArray(v, 0, v.size() - 1));
    // for(int i=0; i<v1.size(); i++){
    //     cout<<v1[i]<<" ";
    // }
    string temp = "god gog";
    cout<<checkPalindrome2(temp, 0)<<endl;
    return 0;
}