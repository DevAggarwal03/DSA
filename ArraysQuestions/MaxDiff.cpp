#include "../stdc++.h"
using namespace std;

// single traversal (keeping track of smaller element and finding the diff with current element);
// TC: O(n);

int singleTraversal(vector<int> arr){
    int minElement = arr[0];
    int maxDiff = 0;

    for(int i=1; i<arr.size(); i++){
        if(arr[i] - minElement > maxDiff){
            maxDiff = arr[i] - minElement;
        }

        if(arr[i] < minElement){
            minElement = arr[i];
        }
    }
    return (maxDiff == 0) ? -1 : maxDiff;
}

// using a leftMin array TC:O(n) SC:O(n);
int findMaxDiff(vector<int> arr){
    vector<int> leftMin(arr.size(), -1);
    for(int i=1; i<arr.size(); i++){
        if(leftMin[i-1] != -1){
            int minVal = min(arr[i-1], leftMin[i-1]);
            if(minVal < arr[i]){
                leftMin[i] = minVal;
            }
        }else{
           if(arr[i] > arr[i - 1]){
                leftMin[i] = arr[i-1];
           } 
        }
    }

    int maxDiff = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        if(leftMin[i] != -1){
            if((arr[i] - leftMin[i]) > maxDiff){
                maxDiff = arr[i] - leftMin[i];  
            }
        }
    }

    return (maxDiff == INT_MIN) ? -1 : maxDiff;
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

    int ans = singleTraversal(arr);
    cout<<ans;
}