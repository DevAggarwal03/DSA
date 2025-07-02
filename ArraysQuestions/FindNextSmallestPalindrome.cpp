#include "../stdc++.h"
using namespace std;

bool all9s(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        if(arr[i] != 9) return false;
    }
    return true;
}

void findNextPalindrome(vector<int>& arr){
    int isSmaller = false;
    int i=0;
    int j=arr.size() - 1;
    int nextIncreased = false;
    for(int k=0; k<arr.size(); k++){
        if(all9s(arr)){
            for(int i=0; i<arr.size(); i++){
                if(i!=0){
                    arr[i] = 0;
                }else{
                    arr[i] = 1;
                }
            }
            arr.push_back(1);
            return;
        }
        if(i==j){
            if(isSmaller){
                arr[j] += 1;  
                if(arr[j] == 10){
                    arr[j] = 0;
                    arr[j-1]++;
                    nextIncreased = true;
                    j--;
                    i++;
                    continue;
                }
            }
            return;
        }
        if(i > j){
            if(isSmaller){
                if(!nextIncreased){
                    arr[j]++;
                }
                arr[i] = arr[j];
                return;
            }
        }else{
            if(arr[i] != arr[j]){
                if(arr[j] > arr[i]){
                    isSmaller = true;
                }else{
                    isSmaller = false;
                }
                arr[j] = arr[i];
            }
            j--;
            i++;
        }
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

    findNextPalindrome(arr);
    for(int i=0; i<a; i++){
        cout<<arr[i]<<" ";
    }
}