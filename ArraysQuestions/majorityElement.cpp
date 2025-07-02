#include "../stdc++.h"
using namespace std;

// optimal approach is to keep a candidate var and a freq counter so if freq == 0 then can = arr[i]; and is arr[i] != can then cnt--;(moore voting algo);
int majorityElement(vector<int> arr){
    

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

    // int ans = findSumClosesToZero(arr);
    int ans = majorityElement(arr);

    return 0;

}