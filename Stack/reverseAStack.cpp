#include "../stdc++.h"
using namespace std;

void printStack(stack<int> st, int n){
    for(int i=0; i<n; i++){
        int top = st.top();
        st.pop();
        cout<<top<<" ";
    }
}

void inputAtBottom(stack<int> st, int topElement){
    if(st.empty()){
        st.push(topElement);
        return;
    }
    int x = st.top();
    st.pop();
    inputAtBottom(st, topElement);
    st.push(x);
}

void reverse(stack<int> st){
    if(st.empty()){
        return;
    }
    int top = st.top();
    st.pop(); 
    reverse(st);

    inputAtBottom(st, top);

    return;

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

    reverse(st);

    printStack(st, n);
    return 0;
}