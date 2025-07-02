#include "../stdc++.h"
using namespace std;

int larBitonicSubArr(vector<int> arr){
    int dir = 1;
    int cnt = 0;
    int maxCnt = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        if(i+1 == arr.size()){
            if(dir == 0){
                if(arr[i] <= arr[i-1]){
                    cnt++;
                    maxCnt = max(maxCnt, cnt);
                    break;
                }else{
                    break;
                }
            }else{
                if(arr[i] >= arr[i-1]){
                    cnt++;
                    maxCnt = max(maxCnt, cnt);
                    break;
                }else{
                    break;
                }
            }
        }
        if(arr[i+1] > arr[i] && dir == 0){
            cnt++;
            maxCnt = max(maxCnt, cnt);
            cnt = 1;
            dir = 1;
        }else{
            if(arr[i + 1] <= arr[i]){
                dir = 0;
            }
            cnt++;
            maxCnt = max(maxCnt, cnt);
        }
    }

    if(arr.size() == 1){
        return 1;
    }

    return maxCnt;
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

    int ans = larBitonicSubArr(arr);
    cout<<endl;
    cout<<ans<<endl;

    return 0;

}