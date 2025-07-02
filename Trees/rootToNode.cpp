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

bool solve(TreeNode* root, int key, vector<int>& ans){
    if(root == NULL) return false;

    ans.push_back(root -> val);
    if(root -> val == key) return true;
    int leftAns = solve(root -> left, key, ans);
    int rightAns = solve(root -> right, key, ans);
    if(leftAns==true){
        return true;
    }
    if(leftAns || rightAns){
        return true;
    }
    ans.pop_back();
    return false;
}

vector<int> rootToNode(TreeNode* root, int key){
    vector<int> ans;
    solve(root, key, ans);
    return ans;
}

int main(){

    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(30);
    root->right->left->left = new TreeNode(10);
    root->right->left->right = new TreeNode(13);

    int key = 30;
    vector<int> ans = rootToNode(root, key);
    
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;

}