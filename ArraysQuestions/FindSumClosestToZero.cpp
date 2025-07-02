#include "../stdc++.h"
using namespace std;
//using sorting and binary search
int calSumBS(vector<int> arr, int ele1){
    int s = 0;
    int e = arr.size() - 1;
    int mid = (s + e) / 2;
    int minDist = INT_MAX;

    while(s <= e){
        if(arr[mid] != ele1){
            int sum = ele1 + arr[mid];
            minDist = min(abs(sum), abs(minDist)) == abs(sum) ? sum : minDist;
            if(sum < 0){
                s = mid + 1;
            }
            if(sum == 0){
                return sum;
            }
            if(sum > 0){
                e = mid - 1;
            }
        }else{
            if(arr[mid] < 0){
                s++;
            }else{
                e--;
            }
        }
        mid = (s + e) / 2;
    }
    return minDist;
}

int findSumClosesToZero(vector<int> arr){
    sort(arr.begin(), arr.end());
    int sum = INT_MAX;
    for(int i=0; i<arr.size(); i++){
        int ele1 = arr[i];
        int res = calSumBS(arr,ele1);
        sum = min(abs(res), abs(sum)) == abs(res) ? res : sum;
    }
    return sum;
}
//using sorting and two pointer O(n*log(n));
int twoPointer(vector<int> arr){
    sort(arr.begin(), arr.end());
    int minDis = INT_MAX;

    int i = 0, j = arr.size() - 1;

    while(i < j){
        int sum = arr[i] + arr[j];
        if(sum == 0 ){
            return 0;
        }
        minDis = min(abs(sum), abs(minDis)) == abs(sum) ? sum : minDis;
        if(sum < 0){
            i++;
        }else{
            j--;
        }
    }

    return minDis;
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
    int ans = twoPointer(arr);
    cout<<ans;
}