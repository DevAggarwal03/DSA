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

// TreeNode* findTarget(TreeNode* root, TreeNode* target, int& height){
//     if(root == NULL || root == target) return root;

//     height += 1;
//     TreeNode* leftAns = findTarget(root->left, target, height);
//     if(leftAns == target) return leftAns;
//     TreeNode* rightAns = findTarget(root->right, target, height);
//     if(rightAns == target) return rightAns;
//     else return NULL;
// }

// void findAllNodesAtDist(TreeNode* root, int h, int hegiht, vector<int>& ans){
//     if(root == NULL) return;
//     if(h == hegiht){
//         ans.push_back(root -> val);
//         return; 
//     }
//     findAllNodesAtDist(root -> left, h+1, hegiht, ans);
//     if(hegiht != 0){
//         findAllNodesAtDist(root -> right, h+1, hegiht, ans);
//     }
// }


vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
    vector<int> ans;
    unordered_map<TreeNode*, TreeNode*> mp;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* currNode = q.front();
        q.pop();

        if(currNode->left){
            q.push(currNode->left);
            mp[currNode->left] = currNode;
        }

        if(currNode->right){
            q.push(currNode->right);
            mp[currNode->right] = currNode;
        }
    }

    int dist = 0;
    unordered_set<TreeNode*> vis;

    if (target == NULL) return ans;

    q.push(target);

    while (!q.empty() && dist <= k) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* temp = q.front(); q.pop();
            vis.insert(temp);

            if (dist == k) {
                ans.push_back(temp->val);
            }

            if (temp->left && vis.find(temp->left) == vis.end()) {
                q.push(temp->left);
            }
            if (temp->right && vis.find(temp->right) == vis.end()) {
                q.push(temp->right);
            }
            if (mp[temp] && vis.find(mp[temp]) == vis.end()) {
                q.push(mp[temp]);
            }
        }
        dist++;
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

    vector<int> ans = distanceK(root, root -> left, 1);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;

}
