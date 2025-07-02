#include "../stdc++.h"
using namespace std;

class node{
    public:
        node* next;
        int val;

        node(int data){
            next = NULL;
            val = data;
        }
};

class stImpl{
        node* topNode; 
        int size;
    public:
        stImpl(){
            topNode = NULL;
            size = 0;
        }

        void push(int data){
            node* temp = new node(data);
            temp -> next = topNode;
            size++;
            topNode = temp;
        }

        void pop(){
            if(size == 0){
                cout<<"underFlow"<<endl;
                return;
            }
            node* temp = topNode;
            topNode = topNode -> next;
            size--;
            delete temp;
        }

        int top(){
            if(topNode == NULL){
                cout<<"no top available"<<endl;
                return -1;
            }
            int data = topNode -> val;
            return data;
        }

        int getSize(){
            return size;
        }
};


class qImpl{
    node* front;
    node* end;
    int size;
    public:
        qImpl(){
            front = NULL;
            end = NULL;
            size = 0;
        }
        void push(int data){
            node* temp = new node(data);
            if(size == 0){
                front = temp;
                end = temp;
            }else{
                end -> next = temp;
                end = temp;
            }
            size++;
        }
        void pop(){
            if(size == 0){
                cout<<"underflow";
                return;
            }
            node* temp = front;
            front = front -> next; 
            if(size == 1){
                end = front;
            }
            size--;
            delete temp;
        }
        int top(){
            if(size == 0){
                cout<<"no element in the q";
                return -1;
            }
            return front->val;
        }
        int getSize(){
            return size;
        }
};

int main(){
    qImpl q;
    q.push(23);
    q.push(40);
    q.push(102);

    while(q.getSize()){
        cout<<q.top();
        q.pop();
        cout<<" "<<q.getSize();
        cout<<endl;
    }


    return 0;

}