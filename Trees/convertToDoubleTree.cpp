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

TreeNode* convertToDoubleTree(TreeNode* root){
    if(root == NULL) return NULL;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            TreeNode* currNode = q.front();
            q.pop();

            if(currNode -> left) q.push(currNode -> left);
            if(currNode -> right) q.push(currNode -> right);

            TreeNode* newNode = new TreeNode(currNode -> val);
            TreeNode* temp = currNode -> left;
            currNode -> left = newNode;
            newNode -> left = temp;
        }
    }

    return root;
}

void printTree(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curNode = q.front();
        q.pop();

        cout<<curNode->val<<" ";

        if(curNode->left) q.push(curNode->left);
        if(curNode->right) q.push(curNode->right);
    }
}

int main(){
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(9);

    TreeNode* newRoot = convertToDoubleTree(root);
    
    printTree(newRoot);

    return 0;

}