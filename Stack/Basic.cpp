#include "../stdc++.h"

using namespace std;

void printStack(stack<int> st, int n){
    cout<<st.size()<<endl;
    for(int i=0; i<n; i++){
        int top = st.top();
        st.pop();
        cout<<top<<" ";
    }
    cout<<endl<<st.size();
}

int main(){
    stack<int> st;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        st.push(x);
    }
    printStack(st, n);
    return 0;
}