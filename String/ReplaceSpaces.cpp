#include "../stdc++.h"
using namespace std;

string replaceSpace(string str){
    for(int i=0; i<str.length(); i++){
        if(str[i] == ' '){
            str[i] = '@40';
        }
    }
    return str;
}

int main(){
    string s = "My name is Dev Aggarwal";

    cout<<replaceSpace(s);
}