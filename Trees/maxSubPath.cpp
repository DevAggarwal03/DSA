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

int solve(TreeNode* root, int& maxi){
    if(root == NULL) return 0;
    if(root -> left == NULL && root -> right == NULL) return root -> val; 

    int leftTree = solve(root -> left, maxi);
    int rightTree = solve(root -> right, maxi);

    maxi = max(maxi, leftTree + rightTree + root -> val);

    return root->val + max(leftTree, rightTree);
}

int maxPathSum(TreeNode* root) {
    int maxi = 0;
    solve(root, maxi);
    return maxi;
}

int main(){
    // 8
    // 1 6
    // 3 4 9 
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(9);

    cout<<maxPathSum(root)<<endl;

    return 0;

}