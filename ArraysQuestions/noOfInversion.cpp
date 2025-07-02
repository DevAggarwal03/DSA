#include "../stdc++.h"
using namespace std;

void merge(vector<int>& arr, int s, int mid, int e, int& glCnt, int& loCnt){
    if(e - s == 1 && arr[s] > arr[e]){
        loCnt++;
    }
    vector<int> temp;
    int i=s;
    int j=mid+1;
    while(i <= mid && j <= e){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j]);
            glCnt += mid - i + 1;
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=e){
        temp.push_back(arr[j++]);
    }

    for(int i=s; i<=e; i++){
       arr[i] = temp[i - s]; 
    }
}

void solve(vector<int>& nums, int s, int e, int& glCnt, int& loCnt){
    if(s >= e){
        return;
    }
    int mid = (s + e) / 2;
    solve(nums, s, mid, glCnt, loCnt);
    solve(nums, mid + 1, e, glCnt, loCnt);
    merge(nums, s, mid, e, glCnt, loCnt);
}

bool isIdealPermutation(vector<int>& nums){
    int glCnt = 0;
    int loCnt = 0;
    solve(nums, 0, nums.size()-1, glCnt, loCnt);

    return glCnt == loCnt ? true : false;
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

    bool ans = isIdealPermutation(arr);
    if(ans){
        cout<<"local inversion == global inversion"<<endl;
    }else{
        cout<<"local inversion != global inversion"<<endl;
    }

    return 0;

}