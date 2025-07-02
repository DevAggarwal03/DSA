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

void solve(TreeNode* root, int lv, vector<int>& ans){
    if(root == NULL) return;
    if(ans.size() == lv) ans.push_back(root -> val);

    solve(root -> left, lv + 1, ans);
    solve(root -> right, lv + 1, ans);
}

vector<int> leftView(TreeNode* root){
    vector<int> ans;
    solve(root, 0, ans);

    return ans;
}

int main(){
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(9);

    vector<int> ans = leftView(root);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;

}