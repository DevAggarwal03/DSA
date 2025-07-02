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

bool solve(TreeNode* root, int currLv, int& leafLv){
    if(root == NULL) return true;
    if(root -> left == NULL && root -> right == NULL){
        if(leafLv == 0){
            leafLv = currLv;
            return true;
        }else{
            return leafLv == currLv ? true : false;
        }
    }

    int leftAns = solve(root -> left, currLv+1, leafLv);
    int rightAns = solve(root -> right, currLv+1, leafLv);

    return leftAns && rightAns ? true : false;
    
}

int main(){
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(34);
    // root->left->left->left = new TreeNode(53);

    int leafVal = 0;
    cout<<solve(root, 1, leafVal);

    return 0;

}