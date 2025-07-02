#include "stdc++.h"
using namespace std;

int main(){
    int n;
    cin >>n;
    int arr[n];
    for(int i=0;i<n; i++){
        cin>>arr[i];
    }

    int maxFreqNo=0;
    int minFreqNo=0;
    int minFreq=n;
    
    unordered_map<int, int> ump;
    for(int i=0; i<n; i++){
        ump[arr[i]]++;
        if(ump[arr[i]] < minFreq) minFreq = ump[arr[i]];
        if(ump[arr[i]] > ump[maxFreqNo]) maxFreqNo = arr[i];
    }

    cout<<maxFreqNo<<" "<<ump[maxFreqNo]<<endl;

    for(auto it : ump){
        if(it.second == minFreq) minFreqNo = it.first;
    }

    cout<<minFreqNo<<" "<<ump[minFreqNo]<<endl;
}