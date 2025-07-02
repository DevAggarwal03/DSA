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

bool solve(TreeNode* root1, TreeNode* root2){
    if(root1 == NULL && root2 == NULL) return true;

    bool leftTreeAns = solve(root1 -> right, root2 -> left);
    bool rightTreeAns = solve(root1 -> left, root2 -> right);
    bool currLevelCheck = root1 -> val == root2 -> val ? true : false;
    
    return currLevelCheck && leftTreeAns && rightTreeAns ? true : false;
}

bool isSymmetric(TreeNode* root){
    if(root == NULL) return true;
    TreeNode* root1 = root -> left;
    TreeNode* root2 = root -> right; 
    bool ans = solve(root1, root2);
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(9);

    cout<<isSymmetric(root)<<endl;

    return 0;

}