#include "../../stdc++.h"

using namespace std;

bool checkpalindrome(string& s, int i){
    if(s.length() == 0){
        return true;
    }

    if(i > (s.length() - 1)/2){
        return true;
    }

    if(s[i] != s[s.length() - i - 1]){
        return false;
    }
    return checkpalindrome(s, i+1);
}

int main(){
    string string = "";

    cout<<checkpalindrome(string, 0)<<endl;
}