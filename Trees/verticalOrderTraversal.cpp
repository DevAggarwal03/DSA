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

void solve(TreeNode* root, map<int, map<int, multiset<int> > >& mp, int hd, int level ){
    if(root == NULL) return;

    mp[hd][level].insert(root -> val);

    solve(root -> left, mp, hd - 1, level + 1);
    solve(root -> right, mp, hd + 1, level - 1);
}

vector<vector<int> > verticalTraversal(TreeNode* root){
    vector<vector<int> > ans;
    if(root == NULL) return ans;
    map<int, map<int, multiset<int> > > mp;
    queue<pair<TreeNode*, pair<int, int> > > q;
    q.push(make_pair(root, make_pair(0, 0)));
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        TreeNode* treeNode = node.first;
        int x = node.second.first;
        int y = node.second.second;
        mp[x][y].insert(treeNode -> val);
        if(treeNode -> left) q.push(make_pair(treeNode -> left, make_pair(x - 1, y + 1)));
        if(treeNode -> right) q.push(make_pair(treeNode -> right, make_pair(x + 1, y + 1)));
    }
    
   for(auto i : mp){
        // cout<<i.second[0][0];
        for(auto j : i.second){
            vector<int>temp;
            for(auto k : j.second){
                temp.push_back(k);
            }
            ans.push_back(temp);
            temp.clear();
        }
    }
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(9);

    vector<vector<int> > ans = verticalTraversal(root);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;

}