#include "../stdc++.h"
using namespace std;
char toLowerCase(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }
    return 'a' + (ch - 'A');
}
bool isNotAlphanumeric(char ch) {
    if ((ch < '0') || (ch > '9' && ch < 'A') || (ch > 'Z' && ch < 'a') || (ch > 'z')) {
        return true;
    }
    return false;
}

bool isPalindrome(string s) {
    int st = 0;
    int e = s.size() - 1;
    bool nonAlphanumericPass = false;
    while(st <= e){
        if(isNotAlphanumeric(s[st])){
            st++;
            nonAlphanumericPass = true;
            cout<<"inside first na: "<<s[st]<<endl;
        }
        if(isNotAlphanumeric(s[e])){
            e--;
            nonAlphanumericPass = true;
        }
        if(nonAlphanumericPass){
            nonAlphanumericPass = false;
            continue;
        }
        if(toLowerCase(s[st]) != toLowerCase(s[e])){
            return false;
        }
        st++;
        e--;
    }
    return true;
}

int main(){
    string word = "race a car";
    cout<<isPalindrome(word);
}
