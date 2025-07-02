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

int minTime(TreeNode* root, int target){
    int cnt = -1;
    if(root == NULL) return 0;

    unordered_map<TreeNode*, TreeNode*> mp;
    TreeNode* targetNode = root;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* currNode = q.front();
        q.pop();
        if(currNode->val == target){
            targetNode = currNode;
        }
        if(currNode -> left){
            mp[currNode -> left] = currNode;
            q.push(currNode -> left);
        }
        if(currNode -> right){
            mp[currNode -> right] = currNode;
            q.push(currNode -> right);
        }
    }

    unordered_set<TreeNode*> vis;
    q.push(targetNode);
    while(!q.empty()){
       int size = q.size();
       for(int i=0; i<size; i++){
        TreeNode* currNode = q.front();
        q.pop();
        vis.insert(currNode);
        if(currNode -> left && vis.find(currNode -> left) == vis.end()){
            q.push(currNode -> left);
        }
        if(currNode -> right && vis.find(currNode -> right) == vis.end()){
            q.push(currNode -> right);
        }
        if(mp[currNode] && vis.find(mp[currNode]) == vis.end()){
            q.push(mp[currNode]);
        }
       } 
       cnt+=1;
    }

    return cnt;
}

int main(){
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(9);

    int time = minTime(root, 3);

    cout<<time;

    return 0;

}