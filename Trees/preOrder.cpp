#include "../stdc++.h"
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;
    
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void preOrder(node* root){
   stack<node*> st;
   st.push(root);
   while(!st.empty()){
        node* currNode = st.top();
        st.pop();
        cout<<currNode -> data<<" ";
        if(currNode -> right) st.push(currNode -> right);
        if(currNode -> left) st.push(currNode -> left);
   } 
}

int main(){
    // 8
    // 1 6
    // 3 4 9 
    node* root = new node(8);
    root->left = new node(1);
    root->right = new node(6);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(9);

    preOrder(root);

    return 0;

}