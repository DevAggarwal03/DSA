#include "../stdc++.h"
using namespace std;

int findMaxProduct(vector<int> arr){
    int maxProduct = 0;
    int minProduct = 0;
    int ans = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        if(i == 0){
            minProduct = arr[i];
            maxProduct = arr[i];
            if(maxProduct > ans){
                ans = maxProduct;
            }
        }else{
            int tempMin = minProduct;
            minProduct = min(min(maxProduct * arr[i], minProduct * arr[i]), arr[i]);
            maxProduct = max(max(tempMin*arr[i], maxProduct*arr[i]), arr[i]);
            if(maxProduct > ans){
                ans = maxProduct;
            }
        }
    }

    return ans;
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

    int maxProd = findMaxProduct(arr);
    cout<<endl;
    cout<<maxProd<<endl;

    return 0;

}