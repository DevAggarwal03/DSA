#include "../stdc++.h"


using namespace std;

int main(){
    vector<int> arr = {23, 5, 12, 55, 23, 6};
    for(int i=0; i<6; i++){
        cout<<arr[i]<<" ";
    }
    int largest = 0;
    int secondLargest = -1;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > largest){
            secondLargest = largest;
            largest = arr[i];
        }
        if(arr[i] > secondLargest && arr[i] < largest){
            secondLargest = arr[i];
        }
    }
    cout<<secondLargest<<endl;
    return 0;
}