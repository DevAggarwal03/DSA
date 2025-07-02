#include "../stdc++.h"
using namespace std;

char toLowerCase(char ch){
    if(ch >= 'a' && ch <= 'z') return ch;
    return 'a'+(ch - 'A');
}

char toUpperCase(char ch){
    if(ch >= 'A' && ch <= 'Z') return ch;
    return 'A' + (ch - 'a');
}

int main() {
    cout<<toLowerCase('f');
    cout<<endl<<toUpperCase('C');
}