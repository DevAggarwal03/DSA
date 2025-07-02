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

// method 1 : find root to node path of p and q then see the last common node in their path that's the LCA
// method 2 : using postOrder traversal

TreeNode* solve(TreeNode* root, int p, int q){
    if(root == NULL || root -> val == p || root -> val == q) return root;

    TreeNode* leftAns = solve(root -> left, p, q);
    TreeNode* rightAns = solve(root -> right, p, q);

    if(leftAns != NULL && rightAns != NULL){
        return root;
    }else{
        if(leftAns != NULL){
            return leftAns;
        }
        if(rightAns != NULL){
            return rightAns;
        }
        return NULL;
    }
}

int lca(TreeNode* root, int p, int q){
    if(root == NULL) return -1;
    TreeNode* ans;
    ans = solve(root, p, q);
    return ans -> val;
}

int main(){
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(9);


    // lca(root, 3, 9);
    cout<<lca(root, 1, 4)<<endl;

    return 0;

}