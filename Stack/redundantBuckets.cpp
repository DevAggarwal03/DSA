#include "../stdc++.h"

using namespace std;

// bool notBrackets(char ch){
//     if(ch != '('){
//         if(ch != ')'){
//             return true;
//         }
//         return false;
//     }
//     return false;
// }

bool redundantBrackets(string s){
    int n = s.length();
    stack<char> st;
    bool doubleWarning = false;
    for(int i=0; i<n; i++){
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else{
            if(ch == ')'){
                bool isRedundant = true;
                while(st.top() != '('){
                    // st.pop();
                    char top = st.top();
                    if(top == '(' || top == '+' || top == '-' || top == '*' || top == '/'){
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant) return true;
                st.pop();
            }
        }
    }
    return false;
}

int main(){
    string s;
    cin>>s;

    if(redundantBrackets(s)){
        cout<<"the string contains redundant brackets"<<endl;
    }else{
        cout<<'The string do not have redundant brackets'<<endl;
    }
}