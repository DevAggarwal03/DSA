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

vector<int> inOrder(node* root){
    vector<int> ans;
    if(root == NULL) return ans;
    stack<node*> st;
    node* currNode = root;
    // st.push(currNode);
    while(true){
        if(currNode == NULL){
            if(st.empty() == true) break;
            currNode = st.top();
            st.pop();
            ans.push_back(currNode -> data);
            currNode = currNode -> right;
        }else{
            st.push(currNode);
            currNode = currNode -> left;
        }
    }

    return ans;
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

    vector<int> ans = inOrder(root);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;

}