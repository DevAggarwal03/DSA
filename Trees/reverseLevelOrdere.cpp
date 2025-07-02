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

// method 1: calc height "h" then for every level print all the element is that level recursively;

int height(node* root){
    if(root == NULL){
        return 0;
    }

    int lheight = height(root -> left);
    int rheight = height(root -> right);

    return max(lheight, rheight) + 1;
}

void printLevel(node* root, int currLevel, int reqLevel){
    if(root == NULL){
        return;
    }

    if(currLevel == reqLevel){
        cout<< root->data <<" ";
    }

    else if(currLevel < reqLevel){
        printLevel(root -> left, currLevel+1, reqLevel);
        printLevel(root -> right, currLevel+1, reqLevel);
    }
}

void revLevelOrder(node* root){
    int h = height(root);

    for(int i=1; i<=h; i++){
        printLevel(root, 1, h-i+1);
        cout<<endl;
    }
}

//method 2: use queue and stack to arrange the nodes is a rev level order fashion
// tc: O(n) && sc: O(n);
void method2(node* root){
    stack<int> st;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* currNode = q.front();
        q.pop();
        if(currNode == NULL){
            st.push(NULL);
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            st.push(currNode -> data);
            if(currNode->right != NULL){
                q.push(currNode->right);
            }
            if(currNode->left != NULL){
                q.push(currNode->left);
            }
        }

    }

    while(!st.empty()){
        if(st.top() == NULL){
            cout<<endl;
        }else{
            cout<<st.top()<<" ";
        }
        st.pop();
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

    method2(root);

    return 0;

}