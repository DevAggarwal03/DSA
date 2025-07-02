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

int calLeftHeight(TreeNode* root){
    if(root == NULL) return 0;
    TreeNode* currNode = root;
    int ans = 0;
    while(currNode != NULL){
        ans++;
        currNode = currNode -> left;
    }
    return ans;
}

int calRightHeight(TreeNode* root){
    if(root == NULL) return 0;
    TreeNode* currNode = root;
    int ans = 0;
    while(currNode != NULL){
        ans++;
        currNode = currNode -> right;
    }
    return ans;
}

int cntNoOfNodes(TreeNode* root){
    if(root == NULL) return 0;

    int leftHeight = calLeftHeight(root);
    int rightHeight = calRightHeight(root);

    if(leftHeight == rightHeight){
        return (1 << leftHeight) - 1;
    }

    return cntNoOfNodes(root -> right) + cntNoOfNodes(root -> left) + 1;
}

int main(){
    TreeNode* root = new TreeNode(8); root->left = new TreeNode(1); root->right = new TreeNode(6); root->left->left = new TreeNode(3); root->left->right = new TreeNode(4); root->right->left = new TreeNode(9);

    cout<<cntNoOfNodes(root);

    return 0;

}