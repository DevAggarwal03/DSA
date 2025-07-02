#include "../stdc++.h"
using namespace std;

void shuffleArray(vector<int>& arr){
    srand(time(NULL));
    for(int i=arr.size() - 1; i>=0; i--){
        int randomNum = rand() % (i+1);
        swap(arr[i], arr[randomNum]);
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
    shuffleArray(arr);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }

    return 0;

}