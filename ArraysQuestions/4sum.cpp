#include "../stdc++.h"
using namespace std;

vector<vector<int> > find4Sum(vector<int> arr, int target){
    vector<vector<int> >  ans;
    sort(arr.begin(), arr.end());
    for(int i=0; i<arr.size() - 2; i++){
        int remaining1 = target - arr[i];
        for(int j=i+1; j<arr.size() - 1; j++){
            int remaining2 = remaining1 - arr[j];
            cout<<remaining2<<endl;
            int l = j + 1; 
            int r = arr.size() - 1;
            while(l < r){
                if(arr[l] + arr[r] > remaining2){
                    r--;
                }
                if(arr[l] + arr[r] < remaining2){
                    l++;
                }
                else{
                    vector<int> quadruplet;
                    quadruplet.push_back(arr[i]);
                    quadruplet.push_back(arr[j]);
                    quadruplet.push_back(arr[l]);
                    quadruplet.push_back(arr[r]);
                    sort(quadruplet.begin(), quadruplet.end());
                    if(find(ans.begin(), ans.end(), quadruplet) == ans.end()){
                        ans.push_back(quadruplet);
                    }
                    l++;
                }
            }
        }
    }
    return ans;
}

//[10 10 11 11 12]

int main(){
    int a;
    cin>>a;
    vector<int> arr;
    for(int i=0; i<a; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    int target;
    cin>>target;

    vector<vector<int> > ans = find4Sum(arr, target);
    cout<<endl;
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}