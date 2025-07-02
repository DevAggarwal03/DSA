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

void rectifyTree(TreeNode* root, int rem){
    if(root == NULL) return;
    root -> val += rem;
    rectifyTree(root -> left, rem);
}

void convert(TreeNode* root){
    if(root == NULL) return;

    convert(root -> left);
    convert(root -> right);

    int currNodeVal = root -> val;
    int leftNodeVal = root->left ? root -> left -> val : 0;
    int rightNodeVal = root -> right ? root -> right -> val : 0;

    if(currNodeVal > leftNodeVal + rightNodeVal){
        rectifyTree(root->left, currNodeVal - (leftNodeVal + rightNodeVal));
    }
    if(currNodeVal < leftNodeVal + rightNodeVal){
        int rem = (leftNodeVal + rightNodeVal) - currNodeVal;
        root->val += rem;
    }
}

void printTree(TreeNode* root){
    if(root == NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* currNode = NULL;
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            currNode = q.front();
            q.pop();
            cout<<currNode -> val<<" ";
            if(currNode->left) q.push(currNode -> left);
            if(currNode->right) q.push(currNode -> right);
        }
        cout<<endl;
    }
}

int main(){

    TreeNode* root = new TreeNode(50); root->left = new TreeNode(7); root->right = new TreeNode(2); root->left->left = new TreeNode(3); root->left->right = new TreeNode(5); root->right->left = new TreeNode(1); root->right->right = new TreeNode(30);
    printTree(root);
    convert(root);
    cout<<endl;
    printTree(root);

    return 0;

}