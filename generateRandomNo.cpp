#include "./stdc++.h"
#include <cstdlib>
using namespace std;

int main(){
    vector<int> arr;
    
    for(int i=0; i<100000; i++){
        int random = rand() % 20001 - 10000;
        arr.push_back(random);
    }

    for(int i=0; i<100000; i++){
        if(i!=99999){
            cout<<arr[i]<<",";
        }
        else{
            cout<<arr[i];
        }
    }
}