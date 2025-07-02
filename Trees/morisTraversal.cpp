#include "../stdc++.h"
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
    
    TreeNode(int data){
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void morisTraversal(TreeNode* root){
    if(root == NULL) {cout<<"root is NULL"; return;}
    TreeNode* currNode = root;
    while(currNode != NULL){
        if(currNode -> left == NULL){
            cout<<currNode->val<<" ";
            currNode = currNode -> right;
        }else{
            TreeNode* tempNode = currNode -> left;
            while(tempNode->right != NULL && tempNode -> right != currNode){
                tempNode = tempNode -> right; 
            }

            if(tempNode->right == NULL){
                tempNode->right = currNode;
                currNode=currNode->left;
            }else{
                tempNode -> right = NULL;
                cout<<currNode->val<<" ";
                currNode = currNode -> right;
            }
        }    
    }
}

int main(){

    TreeNode* root = new TreeNode(8); root->left = new TreeNode(1); root->right = new TreeNode(6); root->left->left = new TreeNode(3); root->left->right = new TreeNode(4); root->right->left = new TreeNode(9);

    morisTraversal(root);

    return 0;

}