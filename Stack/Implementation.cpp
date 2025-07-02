#include "../stdc++.h"
using namespace std;

class Stack{
    private:
        int* st;
        int top;
        int size;
    public:
        Stack(int n){
            top = -1;
            st = new int[n];
            size = n;
        }

        void push(int x){
            if(top == size-1){
                cout<<"overflow error"<<endl;
                return;
            }
            top+=1;
            st[top] = x;
            
        }

        void pop(){
            if(top == -1){
                cout<<"underflow error"<<endl;
                return;
            }
            top-=1;
        }

        int peek(){
           return st[top]; 
        }
};

int main(){
    Stack* st = new Stack(5);
    st->push(23);
    st->push(33);
    st->push(33);
    st->push(33);
    st->push(33);
    st->push(33);
    cout<<st->peek()<<endl;
    st->pop();
    cout<<st->peek()<<endl;
    st->pop();
    st->pop();
    st->pop();
    st->pop();
    return 0;
}