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

int findDiff(TreeNode* root){
    if(root == NULL) return 0;

    int ans;
    int oSum = 0;
    int eSum = 0;

    queue<pair<TreeNode*, int > > q;
    q.push(make_pair(root, 1));
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        TreeNode* currNode = node.first;
        int lv = node.second;

        if(lv%2 == 0) eSum += currNode -> val;
        else oSum += currNode -> val;
        ans = oSum - eSum;
        cout<<oSum<<" "<<eSum<<endl;
        if(currNode -> left != NULL) q.push(make_pair(currNode->left,lv+1));
        if(currNode -> right != NULL) q.push(make_pair(currNode->right,lv+1));
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

    cout<<findDiff(root);

    return 0;

}