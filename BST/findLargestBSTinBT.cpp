#include "../stdc++.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

pair<int, pair<int,int> > f(TreeNode* root){
    if(root->left == NULL && root -> right == NULL) return make_pair(1, make_pair(root -> val, root -> val));

    pair<int, pair<int,int> > left = make_pair(0, make_pair(INT_MIN,INT_MAX));
    pair<int, pair<int,int> > right = make_pair(0, make_pair(INT_MIN, INT_MAX));
    bool leftOk = true;
    bool rightOk = true;
    if(root -> left){
        left = f(root -> left);
    }
    if(root -> right){
        right = f(root -> right);
    }

}

int findLargestBST(TreeNode* root){
    return f(root).first;
}

int main(){


    return 0;

}