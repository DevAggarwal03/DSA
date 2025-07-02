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

vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    vector<vector<int> > ans;
    queue<TreeNode*> q;
    bool leftToRight = true;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> temp(size);
        for(int i=0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();

            if(leftToRight){
                temp[i] = node -> val;
            }else{
                temp[size - i - 1] = node -> val;
            }

            if(node -> left != NULL){
                q.push(node -> left);
            }
            if(node -> right != NULL){
                q.push(node -> right);
            }
        }

        leftToRight = !leftToRight;
        ans.push_back(temp);
    }

    return ans;
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

    vector<vector<int> > ans = zigzagLevelOrder(root);
    
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;

}