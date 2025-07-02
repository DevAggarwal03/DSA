#include "./../stdc++.h"
using namespace std;

void union2arr(vector<int> arr1, vector<int> arr2){
    int n = arr1.size();
    int m = arr2.size();
    vector<int> ans;
    int i=0; 
    int j=0;
    while(i<n && j<m){
        if(i > 0){
            while(arr1[i] == arr1[i-1]){
                i+=1;
            }
            if(i>=n){
                break;
            }
        }
        if(j>0){
            while(arr2[j] == arr2[j-1]){
                j+=1;
            }
            if(j>=m){
                break;
            }
        }
        if(arr1[i] < arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        }
        if(arr1[i] == arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        if(arr1[i] > arr2[j]){
            ans.push_back(arr2[j]);
            j++;
        }
    }
    while(i < n){
        while(i>0 && arr1[i] == arr1[i-1]){
            i++;
        }
        ans.push_back(arr1[i]);
        i++;
    }
    while(j < m){
        while(j>0 && arr2[j] == arr2[j-1]){
            j++;
        }
        ans.push_back(arr2[j]);
        j++;
    }

    for(int k=0; k<ans.size(); k++){
        cout<<ans[k]<<" ";
    }
}

void intersection(vector<int> arr1, vector<int> arr2){
    int n = arr1.size();
    int m = arr2.size();

    vector<int> ans;
    int i = 0;
    int j = 0;

    while(i < n && j < m){
        if(i > 0 && arr1[i] == arr1[i-1]){
            i++;
            continue;
        }
        if(j > 0 && arr2[j] == arr2[j-1]){
            j++;
            continue;
        }
        if(arr1[i] < arr2[j]){
            i++;
        }
        else if(arr1[i] == arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else{
            j++;
        }
    }

    for(int k=0; k<ans.size(); k++){
        cout<<ans[k]<<" ";
    }
}

int main() {
    int a;
    cin >> a;
    vector<int> arr1;
    for(int i=0; i<a; i++){
        int temp;
        cin>>temp;
        arr1.push_back(temp);
    }
    int b;
    cin>>b;
    vector<int> arr2;
    for(int i=0; i<b; i++){
        int temp;
        cin>>temp;
        arr2.push_back(temp);
    }
    // union2arr(arr1, arr2);
    intersection(arr1, arr2);
    return 0;
}
