#include "../stdc++.h"
using namespace std;

int nextSmallest(vector<int>& heights, vector<int>& nextSmallest){
    int n = heights.size();
    stack<int> st;
    for(int i=n-1; i>=0; i--){
        while(!st.empty()){
            int top = st.top();
            if(heights[top]>=heights[i]){
                st.pop();
            }else{
                nextSmallest[i] = top;
                break;
            }
        }
        st.push(i);
    }
}

int main(){
    int n;
    cin>>n;
    int i=n;
    vector<int> arr(n, 0);
    while(i){
        int temp;
        cin>>temp;
        arr[i] = temp;
        i--;
    }
    vector<int> nextSmallent(n, -1);
    getNextSmallest(nextSmallent, arr, n);
    for(auto it: nextSmallent){
        cout<<it<<" ";
    }

    return 0;

}