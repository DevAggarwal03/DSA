#include "../stdc++.h"

using namespace std;

class TwoStacks{
    int* arr;
    int top1;
    int top2;
    int size;

    TwoStacks(int n){
        size = n;
        top1 = -1;
        top2 = n;
        arr = new int[size];
    }

    void push1(int x){
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = x;
        }else{
            cout<<"stack overflow"<<endl;
        }
    }

    void push2(int x){
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = x;
        }else{
            cout<<"stack overflow"<<endl;
        }
    }

    void pop1(){
        if(top1 != -1){
            top1--;
        }else{
            cout<<"stack underflow"<<endl;
        }
    }

    void pop2(){
        if(top2 != this->size){
            top2++;
        }else{
            cout<<"stack underflow"<<endl;
        }
    }

    int seek1(){
        if(top1 > -1){
            return arr[top1];
        }else{
            cout<<"stack is empty"<<endl;
        }
    }

    int seek2(){
        if(top2 < this->size){
            return arr[top2];
        }else{
            cout<<"stack is empty"<<endl;
        }
    }
};

int main(){

}