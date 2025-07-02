#include "./../stdc++.h"
using namespace std;

void findNonRepeatingElements(vector<int> arr){
    int xorVal = 0;
    for(int i=0; i<arr.size(); i++){
        xorVal = xorVal ^ arr[i];
    }
    xorVal = xorVal & (-1*xorVal);
    cout<<"xorVal: "<<xorVal<<endl;
    vector<int> v(2,0); 

    for(int i=0; i<arr.size(); i++){
        if((xorVal & arr[i]) != 0){
            v[0] ^= arr[i];
        }
        else{
            v[1] ^= arr[i];
        }

    }

    if(v[0] > v[1]){
        swap(v[0], v[1]);
    }

    cout<<v[0]<<" "<<v[1];

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

    findNonRepeatingElements(arr);
}