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

TreeNode* solve(vector<int> preorder, vector<int> inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int> mp){
    if(preEnd < preStart || inEnd < inStart){
        return NULL;
    }

    TreeNode* temp = new TreeNode(preorder[preStart]);
    int pos = mp[preorder[preStart]];
    int noOfNodes = pos - inStart;

    temp -> left = solve(preorder, inorder, preStart+1, preStart + noOfNodes, inStart, pos-1, mp);
    temp -> right = solve(preorder, inorder, preStart+noOfNodes+1, preEnd, pos+1, inEnd, mp);

    return temp;

}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
    unordered_map<int, int> mp;
    for(int i=0; i<inorder.size(); i++){
        mp[inorder[i]] = i;
    }

    TreeNode* ans = solve(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size()-1, mp);
    return ans;
}

int main(){

    vector<int> inOrder;
    inOrder.push_back(9);
    inOrder.push_back(3);
    inOrder.push_back(15);
    inOrder.push_back(20);
    inOrder.push_back(7);
    vector<int> preOrder;
    preOrder.push_back(3);
    preOrder.push_back(9);
    preOrder.push_back(20);
    preOrder.push_back(15);
    preOrder.push_back(7);

    TreeNode* root = buildTree(inOrder, preOrder);

    return 0;

}