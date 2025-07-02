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

TreeNode* solve(vector<int> inorder, vector<int> postorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int,int> mp){
    if(postEnd > postStart || inStart > inEnd){
        return NULL;
    }

    TreeNode* temp = new TreeNode(postorder[postStart]);
    int inPos = mp[postorder[postStart]];
    int noOfNodes = inEnd - inPos;

    temp -> right = solve(inorder, postorder, inPos+1, inEnd, postStart-1, postStart-noOfNodes, mp);
    temp -> left = solve(inorder, postorder, inStart, inPos-1, postStart - noOfNodes - 1, postEnd, mp);
    return temp;

}

TreeNode* buildTree(vector<int> inorder, vector<int> postorder){
    if(inorder.size()==0) return NULL;
    unordered_map<int,int> mp;
    for(int i=0; i<inorder.size(); i++){
        mp[inorder[i]] = i;
    }


    return solve(inorder, postorder, 0, inorder.size()-1, postorder.size()-1, 0, mp);
}

int main(){
    vector<int> inOrder;
    inOrder.push_back(9);
    inOrder.push_back(3);
    inOrder.push_back(15);
    inOrder.push_back(20);
    inOrder.push_back(7);
    vector<int> postorder;
    postorder.push_back(3);
    postorder.push_back(9);
    postorder.push_back(20);
    postorder.push_back(15);
    postorder.push_back(7);

    TreeNode* root = buildTree(inOrder, postorder);



    return 0;

}