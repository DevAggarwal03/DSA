#include "../stdc++.h"
using namespace std;

// using prefix and suffix sum;
int preSufSum(vector<int> arr){
    vector<int> prefix(arr.size(), 0);
    vector<int> suffix(arr.size(), 0);
    int ans = -1;
    for(int i=1; i<arr.size(); i++){
        prefix[i] = arr[i-1] + prefix[i-1];
    }
    for(int i=arr.size() - 2; i>=0; i--){
        suffix[i] = arr[i+1] + suffix[i+1];
    }
    for(int i=0; i<arr.size(); i++){
        if(prefix[i] == suffix[i]){
            ans = arr[i];
        }
    }

    return ans;
}

//two pointer approach
int twoPointer(vector<int> arr){
    int s = 0;
    int e = arr.size() - 1;
    int rightSum = 0;
    int leftSum = 0;
    while(s <= e){
        if(s == e){
            if(rightSum == leftSum){
                return arr[s];
            }
        }
        rightSum += rightSum + arr[e];
        leftSum += leftSum + arr[s];
        if(rightSum > leftSum){
            s++;
        }else if(rightSum == leftSum){
            e--;
            s++;
        }else{
            e--;
        }
    }
    return -1;
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
    int ans = preSufSum(arr);
    cout<<ans;
}