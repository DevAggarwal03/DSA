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

void insertAtEnd(Node* &tail, int data){
    Node* tempNode = new Node(data);
    tail -> next = tempNode;
    tail = tempNode;
}

void replaceToStart(Node* temp, Node*& start){
    Node* nextNode = temp -> next;
    temp -> next = nextNode -> next;
    nextNode -> next = start;
    start = nextNode;
}
void replaceToEnd(Node* temp, Node*& end){
    Node* nextNode = temp -> next;
    temp -> next = nextNode->next;
    end -> next = nextNode;
    end = nextNode;
    end->next = NULL;
}
// Function to sort a linked list of 0s, 1s and 2s.
Node* segregate(Node* head) {
   if(head -> next == nullptr) return head;
   Node* start = head;
   while(start->next != nullptr){
       start = start -> next;
   }
   Node* end = start;
   Node* tail = end;
   start = head;
   
   Node* temp = head;
   while(temp->next != nullptr){
    //   cout << temp->data << endl;
       if(temp -> next == tail){
           if(temp -> next -> data == 0){
               replaceToStart(temp, start);
           }
           break;
       }
       if(temp -> next -> data == 0){
           replaceToStart(temp, start);
           continue;
       }
       else if(temp -> next -> data == 2){
           replaceToEnd(temp, end);
           continue;
       }
       temp = temp -> next;
   }
   return start;
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

int main(){
    Node *HomeNode = new Node(1);
    //1 2 2 0 2 1 0 2
    Node *head = HomeNode;
    Node *tail = HomeNode;

    insertAtEnd(tail, 2);
    insertAtEnd(tail, 2);
    insertAtEnd(tail, 0);
    insertAtEnd(tail, 2);
    insertAtEnd(tail, 1);
    insertAtEnd(tail, 0);
    insertAtEnd(tail, 2);

    Node* newList = segregate(head);

    printLL(newList);

    return 0;

}