#include "../stdc++.h"
using namespace std;

void rotArr(vector<int>& arr, int d){
    int n = arr.size();
    int temp = arr[0];
    int tempIdx = 0;
    int prevTemp = 0;
    for(int i=0; i<arr.size(); i++){
          int tempNew = arr[(n - d + tempIdx) % n];
          arr[(n - d + tempIdx) % n] = i == 0 ? temp : prevTemp;
          prevTemp = tempNew;
    }
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
    int d;
    cin>>d;
    rotArr(arr, d);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;

    return 0;

}