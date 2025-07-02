#include "../stdc++.h"
using namespace std;
int makeValid(string s){
    int n = s.length();
    int cnt = 0;
    if(n % 2 != 0) return -1;
    stack<char> st;
    for(int i=0; i<n; i++){
        char ch = s[i];
        if(ch == '{'){
            // if(!st.empty()){
            //     if(st.top() == )
            // }
            st.push(ch);
        }else{
            if(!st.empty()){
                if(st.top() == '{'){
                    st.pop();
                }else{
                    cnt++;
                    st.pop();
                }
            }
                st.push('}');
            }
            cnt++;
        }
    }
    int rem = 0;
    while(!st.empty()){
        rem++;
        st.pop();
    }
    cnt += rem/2;

    return cnt;
}
int main(){
    string s;
    cin>>s;

    cout<<"no of moves needed to make it valid: "<<makeValid(s)<<endl;
}