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

void f(TreeNode* root, int val, int& ans){
    if(root -> val == val){
        ans = val;
        return;
    }
    if(root -> val > val){
        ans = min(ans, root -> val);
    }
    cout<<root -> val<<" ";

    if(root -> left && val < root -> val){
        f(root -> left, val, ans); 
    }
    if(root -> right && val > root -> val){
        f(root -> right, val, ans);
    }
}

int findCiel(TreeNode* root, int val){
    int ans = INT_MAX;
    f(root, val, ans);
    return ans;
}

int main(){

    TreeNode* root = new TreeNode(10);
    root -> left = new TreeNode(5);
    root -> left -> left = new TreeNode(3);
    root -> left -> right = new TreeNode(6);
    root -> left -> left -> left = new TreeNode(2);
    root -> left -> left -> right = new TreeNode(4);
    root -> left -> right -> right = new TreeNode(9);
    root -> right = new TreeNode(13);
    root -> right -> left = new TreeNode(11);
    root -> right -> right = new TreeNode(14);
    int ans = findCiel(root, 8);
    cout<<endl;
    cout<<ans;

    return 0;

}