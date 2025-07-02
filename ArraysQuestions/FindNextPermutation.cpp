#include "../stdc++.h"
using namespace std;

void FindNextPermutation(vector<int>& arr){
    int pivoteElement = arr.size() - 1;
    int i = arr.size()-1;
    if(i == 0){
        cout<< arr[0]<<endl;
        return;
    }
    while(i >= 0){
        if(i != arr.size()-1){
           if(arr[i] < arr[i+1]){
                pivoteElement = i;
                break; 
           } 
        }  
        i--;
    }
    if(pivoteElement == arr.size() - 1){
        for(int i=0; i<arr.size()/2; i++){
            swap(arr[i], arr[arr.size()-i-1]);
        }
        return; 
    }
    i = arr.size() - 1;
    while(i > pivoteElement){
        if(arr[i] > arr[pivoteElement]){
            swap(arr[i], arr[pivoteElement]);
            break;
        }
        i--;
    }
    i = pivoteElement+1;
    int j = arr.size()-1;
    while(i < j){
        swap(arr[i++], arr[j--]);
    }
    return;

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

    FindNextPermutation(arr);
    for(int i=0; i<a; i++){
        cout<<arr[i]<<" ";
    }
}
