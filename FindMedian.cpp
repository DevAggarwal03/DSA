#include "stdc++.h"

using namespace std;

int findMedian(int arr1[], int arr2[], int m, int n){
    int i = 0;
    int j = 0;
    int mid = (m + n) / 2;
    int count = 0;
    int medianIndex;
    double ans;

    while(count <= mid){
        if(arr1[i] <= arr2[j]){
            count++;
            if(count == mid){
                medianIndex = i;
            }
            i++;
        }else{
            count++;
            if(count==mid){
                medianIndex = j;
            }
            j++;
        }
    }

    int num1 = (ans == i) ? arr1[medianIndex] : arr2[medianIndex];
    int num2 = (arr1[i] > arr2[j]) ? arr2[j] : arr1[i];
    return (num1 + num2)/2;

}

int main(){
    int a[6] = {1, 12, 15, 26, 38}, b[6] = {2, 13, 17, 30, 45};

    cout<<findMedian(a, b, 5, 5)<<endl;
}