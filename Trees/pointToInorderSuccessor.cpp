#include "../stdc++.h"
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode* next;    
    TreeNode(int data){
        this->val = data;
        this->left = NULL;
        this->right = NULL;
        this->next = NULL;
    }
};

void inorderSuccessor(TreeNode* root){
    stack<TreeNode*> st;
    TreeNode* curr = root;
    TreeNode* leftOver = NULL;
    while(curr != NULL || !st.empty()){
        
        cout<<st.size();
        if(curr != NULL){
            cout<<" "<<curr->val<<endl;
        }else{
            cout<<" null"<<endl;
        }
        while(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        // cout<<curr->val<<endl;
        st.pop();
        if(leftOver != NULL && leftOver != curr){
            leftOver -> next = curr;
            leftOver = NULL;
        }
        if(curr -> right == NULL){
            if(!st.empty()) curr->next = st.top();
        }
        else{
            leftOver = curr;
        }


        curr = curr->right;
    }
}


int main(){
    // 8
    // 1 6
    // 3 4 9 
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(9);
    root->right = new TreeNode(7);
    root -> left -> left = new TreeNode(6);
    root -> left -> right = new TreeNode(5);
    root -> left ->right-> left = new TreeNode(8);
    root->right->right = new TreeNode(3);


    inorderSuccessor(root);
    cout<<"end of fun"<<endl;
    TreeNode* ptr = root;
    TreeNode* ptr2 = NULL;
    while(ptr != NULL){
        ptr2 = ptr;
        ptr = ptr -> left;
    }
    // int temp = 1;
    while(ptr2 != NULL){
        cout<<ptr2->val<<" ";
        ptr2 = ptr2 -> next;
        // temp++;
    }


    return 0;

}