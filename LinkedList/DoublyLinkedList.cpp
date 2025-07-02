#include "../stdc++.h"

using namespace std;

class Node {
    public:
    int data;
    Node *prev;
    Node *next;

    Node(int data){
        this -> data = data;
        prev = NULL;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtTail(Node* &tail, int data){
    Node* newNode = new Node(data);
    tail -> next = newNode;
    newNode -> prev = tail;
    tail = tail->next;
}

void insertAtPos(Node* &head, int pos){
    
}

void printDL(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}


int main(){
    Node* HomeNode = new Node(23);
    Node* tail = HomeNode;
    Node* head = HomeNode;
    printDL(head);
    cout<<endl;
    insertAtHead(head, 100);
    printDL(head);
    cout<<endl;
    insertAtTail(tail, 45);
    printDL(head);
    cout<<endl;

    cout<<head->data<<endl;
    cout<<tail->data<<endl;
}