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

int findKthNode(TreeNode* root, int k, int N){
    if(root == NULL) return -1;

    queue<TreeNode*> q;
    q.push(root);
    int lv = 0;
    int ans;
    while(!q.empty()){
        int size = q.size();
        int j = 1;
        for(int i=0; i<size; i++){
            TreeNode* currNode = q.front();
            q.pop();

            if(j == k){
                if(currNode){
                    return currNode->val;
                }
                return -1;
            }
            
            q.push(currNode -> left);
            q.push(currNode -> right);
            if(lv == N){
                j += 1;
            }
        }
        lv += 1;
    }
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(9);

    cout<<findKthNode(root, 3, 2);

    return 0;

}