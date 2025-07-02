#include "../stdc++.h"

using namespace std;

void printStack(stack<int> st, int n){
    for(int i=0; i<n; i++){
        int top = st.top();
        st.pop();
        cout<<top<<" ";
    }
}

void placeAtCorrectLocation(stack<int>& st, int top){
    if(st.empty()){
        st.push(top);
        return;
    }
    if(st.top() > top){
        st.push(top);
        return;
    }

    int topElement = st.top();
    st.pop();
    placeAtCorrectLocation(st, top);
    st.push(topElement);
}

void sort(stack<int>& st){
    if(st.empty()){
        return;
    }

    int top = st.top();
    st.pop();
    sort(st);

    placeAtCorrectLocation(st, top);
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
    cout<<endl;

    sort(st);

    printStack(st, n);
}