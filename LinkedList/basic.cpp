#include "../stdc++.h"

using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node (int data) {
        this -> data = data;
        this -> next = NULL;
    }

};

void insertAtHead (Node* &head, int data){
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void printLL (Node* head){
    while(head != NULL){
        if(head->next == NULL){
            cout<<head -> data;
        }else{
            cout<<head->data<<" -> ";
        }
        head = head -> next;
    }
    // cout<<head->data;
    cout<<endl;
}

void insertAtEnd(Node* &tail, int data){
    // Node* temp = head;
    // while(temp -> next != NULL){
    //     temp = temp->next;
    // }
    Node* tempNode = new Node(data);
    tail -> next = tempNode;
    tail = tempNode;

}

void insertInTheMiddle(Node* &head, Node* &tail, int data, int index){
    Node* temp = head;
    if(index == 0){
        insertAtHead(head, data);
        return;
    }
    for(int i=0; i<index - 1; i++){
        temp = temp -> next;
    }
    if(temp == NULL){
        cout<<"not correct index"<<endl;
    }
    if(temp -> next == NULL){
        insertAtEnd(tail, data);
        return;
    }
    // Node* nextNode = temp -> next; 
    Node* newNode = new Node(data);
    newNode -> next = temp -> next; 
    temp -> next = newNode;
}

void deleteAtTail(Node* &tail, Node* &head){
    Node* temp = head;
    while(temp -> next != tail){
        temp = temp -> next;
    }
    tail = temp;
    temp = temp -> next;
    tail -> next = NULL;
    delete temp;
}

void deleteAtStart(Node* &head){
    Node* temp = head;
    head = head -> next;
    temp -> next = NULL;
    delete temp;
}

void deleteAtIndex(Node* &head, int index, Node* &tail){
    if(index == 0){
        deleteAtStart(head);
        return;
    }
    Node* temp = head;
    for(int i=0; i<index - 1; i++){
        temp = temp->next;
    }

    if(temp -> next -> next == NULL){
        deleteAtTail(tail, head);
        return;
    }

    Node* deleteNode = temp -> next;
    temp -> next = deleteNode -> next;
    deleteNode->next = NULL;
    delete deleteNode;
}

int main(){
    Node *HomeNode = new Node(23);
    Node *head = HomeNode;
    Node *tail = HomeNode;
    // cout<<HomeNode->data<<endl;
    // cout<<HomeNode->next<<endl;

    insertAtHead(head, 12);
    insertAtEnd(tail, 33);
    insertInTheMiddle(head, tail, 52, 2);
    insertInTheMiddle(head, tail, 100, 4);
    insertInTheMiddle(head, tail, 123, 4);
    printLL(head);

    deleteAtTail(tail, head);
    deleteAtStart(head);
    deleteAtIndex(head, 0, tail);

    cout<<endl;
    printLL(head);

    cout<<endl;
    cout<<head->data;
    cout<<endl;
    cout<<tail->data;
    return 1;
}