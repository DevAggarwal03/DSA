#include "../stdc++.h"
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }    
};

Node* buildTree(Node* root){
    cout<<"Enter the data:"<<endl;
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    root = new Node(data);

    cout<<"What should be at the left of the prev node?: " << data<<endl;
    root -> left = buildTree(root -> left);
    cout<<"What should be at the right of the prev node?: " << data<<endl;
    root -> right = buildTree(root -> right);

    return root;

}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* currNode = q.front();
        q.pop();
        if(currNode == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<currNode->data<<" ";
            if(currNode -> left != NULL){
                q.push(currNode -> left);
            }
            if(currNode -> right != NULL){
                q.push(currNode -> right);
            }
        }
    }
}

// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

int main(){
    Node* root = NULL;
    root = buildTree(root);

    levelOrderTraversal(root);

    return 0;

}