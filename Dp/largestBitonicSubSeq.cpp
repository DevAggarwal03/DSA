#include "../stdc++.h"
using namespace std;

int largestBitonicArr(vector<int>& arr){
    int n = arr.size();
    vector<int> leftToRight(n, 1), rightToLeft(n, 1);
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j] && leftToRight[j] + 1 > leftToRight[i]){
                leftToRight[i] = leftToRight[j] + 1;
            }
        }
    }
    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>i; j--){
            if(arr[i] > arr[j] && rightToLeft[j] + 1 > rightToLeft[i]){
                rightToLeft[i] = rightToLeft[j] + 1;
            }
        }
    }

    int maxi = 0;
    for(int i=0; i<n; i++){
        maxi = (rightToLeft[i] + leftToRight[i] - 1, maxi);
    }
    return maxi;
}

int main(){


    return 0;

}