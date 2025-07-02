#include "../stdc++.h"

using namespace std;

int findIndexLessThan(int arr[], int index, int size){
    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;

    while(start < end){
        if(arr[mid] < arr[index]){
            start = mid + 1;
        }
        if(arr[mid] >= arr[index]){
            end = mid;
        }
        mid = (end + start) / 2;
    }
    cout<<index << " => "<<mid<<endl;
    return mid;
}

int findLongestSubSequence(int arr[], int size){
    vector<int> bucket;
    for(int i=0; i<size; i++){
        if(i==0){
            bucket.push_back(arr[i]);
        }

        if(bucket.back() < arr[i]){
            bucket.push_back(arr[i]);
        }else{
            int index = findIndexLessThan(arr, i, size);
            // cout<<"=> "<<index<<endl;
            arr[index] == arr[i];
        }
    }
    cout<<endl;
    for(int i=0; i<bucket.size(); i++){
        cout<<bucket[i]<<" ";
    }
    cout<<endl;
    return bucket.size();
}

int main(){
    int arr[7] = {14, 10, 50, 1, 55, 11, 100}; 

    cout<<findLongestSubSequence(arr, 7)<<endl;
}