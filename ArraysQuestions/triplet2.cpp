#include "../stdc++.h"
using namespace std;

vector<int> findTriplet(vector<int> arr){
    vector<int> ans;
    int n = -1;
    for(int i=0; i<arr.size(); i++){
        if(n == -1){
            ans.push_back(arr[i]);
            n += 1;
        }else{
            int element = arr[i];
            if(ans[n] < element){
                ans.push_back(arr[i]);
                n += 1;
            }else{
                int temp = n;
                while(temp >= 0){
                    if(ans[temp] < element){
                        ans[temp + 1] = element;
                        n += 1;
                        if(n == 2){
                            break;
                        }
                        continue;
                    }
                    temp--;
                }
            }
        }
        if(n == 2){
            break;
        }
    }
    cout<<ans[n]<<endl;
    if(n < 2){
        vector<int> v(3, -1);
        return v;
    }
    return ans;
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

    vector<int> ans = findTriplet(arr);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}

// 6
// 4 2 6 3 8 7