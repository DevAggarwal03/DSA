#include <cstdlib>
#include "./stdc++.h"

using namespace std;

int main(){
    int num = 1000;
    int arr[num][num];

    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            int random = rand() % 2;
            arr[i][j] = random;
        }
    }

    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}