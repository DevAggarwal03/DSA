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

vector<int> topLevelView(TreeNode* root){
    vector<int> ans;
    if(root == NULL) return ans;

    map<int, map<int, int> > mp;
    queue<pair<TreeNode*, pair<int, int> > > q;

    q.push(make_pair(root, make_pair(0, 0)));

    while(!q.empty()){
        auto node = q.front();
        q.pop();
        TreeNode* currNode = node.first;
        int x = node.second.first , y = node.second.second;

        if(mp.find(x) == mp.end()) mp[x][y] = currNode -> val;

        if(currNode -> left != NULL) q.push(make_pair(currNode -> left, make_pair(x-1, y+1)));
        if(currNode -> right != NULL) q.push(make_pair(currNode -> right, make_pair(x+1, y+1)));
    }

    for(auto i : mp){
        for(auto j : i.second){
            ans.push_back(j.second);
        }
    }

    return ans;
}

int main(){
    TreeNode* root = new TreeNode(8); root->left = new TreeNode(1); root->right = new TreeNode(6); root->left->left = new TreeNode(3); root->left->right = new TreeNode(4); root->right->left = new TreeNode(9);
    vector<int> ans = topLevelView(root);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}