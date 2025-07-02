#include "../stdc++.h"
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode* next;    
    TreeNode(int data){
        this->val = data;
        this->left = NULL;
        this->right = NULL;
        this->next = NULL;
    }
};

vector<TreeNode*> NodesInLevel(TreeNode* root){
    vector<TreeNode*> ans;
    if(root == NULL){
        return ans;
    }
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        TreeNode* ptr = q.front();
        for(int i=0; i<size; i++){
            TreeNode* temp = q.front();
            q.pop();
            if(i<size-1) temp -> next = q.front();

            if(temp -> left != NULL) q.push(temp -> left); 
            if(temp -> right != NULL) q.push(temp -> right); 
        }
        ans.push_back(ptr);
    }

    return ans;
}

int main(){
    // 8
    // 1 6
    // 3 4 9 
    // TreeNode* root = new TreeNode(8);
    // root->left = new TreeNode(9);
    // root->right = new TreeNode(7);
    // root -> left -> left = new TreeNode(6);
    // root -> left -> right = new TreeNode(5);
    // root -> left ->right-> left = new TreeNode(8);
    // root->right->right = new TreeNode(3);

    // 8
    // 1 6
    // 3 4 9 
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(9);


    vector<TreeNode*> ans = NodesInLevel(root);
    for(int i=0; i<ans.size(); i++){
        TreeNode* temp = ans[i];
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp -> next;
        }
        cout<<endl;
    }

    return 0;

}