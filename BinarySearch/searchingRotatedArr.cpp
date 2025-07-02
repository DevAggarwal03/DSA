#include "../stdc++.h"
using namespace std;

int findElement(int arr[], int n, int key){
    int s = 0;
    int e = n - 1;
    int m = (s + e) / 2;

    while(s < e){
        if(arr[m] == key){
            return m;
        }
        else{
            if(key >= arr[0]){
                if(arr[m] >= arr[0]){
                    if(key < arr[m]){
                        e = m - 1;
                    }else{
                        s = m + 1;
                    }
                }else{
                    s = m + 1;
                }
            }
            else{
                if(arr[m] >= arr[0]){
                    s = m + 1;
                }else{
                    if(key > arr[m]){
                        s = m+1;
                    }else{
                        e = m - 1;
                    }
                }
            }
        }
        m = (s + e)/2;
    }
    if(arr[s] == key){
        return s;
    }
    return -1;
}

int main(){
    int arr[7] = {5, 10, 11, 13, 2, 3, 4};
    cout<<findElement(arr, 7, 13)<<endl;
}
