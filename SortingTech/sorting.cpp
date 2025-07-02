#include "../stdc++.h"

using namespace std;

void selectionSortt(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int min = i;
            for(int j=i; j<n; j++){
                if(arr[j] < arr[min]){
                    min = j;
                }
            }
        swap(arr[i], arr[min]);
    }
}

void bubblesortt(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int cnt = 0;
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                cnt++;
            }
        }
        if(cnt == 0){
            break;
        }
    }
}

void insertionSortt(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=i; j>0; j--){
            if(arr[j] < arr[j-1]){
                swap(arr[j], arr[j-1]);
            }
        }
    }
}

void merging(int arr[], int a, int half, int b){
    int left = a;
    int right = half + 1;
    vector<int> temp;
    while(left <= half && right <= b){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= half){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= b){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=0; i<temp.size(); i++){
        arr[a+i] = temp[i];
    }
}

void mergeSortt(int arr[], int a, int b){
    if(a == b) return;
    int half = (a+b)/2;
    mergeSortt(arr, a, half);
    mergeSortt(arr, half+1, b);
    merging(arr, a, half, b);
}

int main(){
    int arr[7] = {23, 5, 12, 55, 56, 2, 45};
    mergeSortt(arr, 0, 6);
    for(int i=0; i<7; i++){
        cout<<arr[i]<<" ";
    }
}