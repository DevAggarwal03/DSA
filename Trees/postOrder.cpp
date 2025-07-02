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

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;

    stack<TreeNode*> st1;
    stack<TreeNode*> st2;

    st1.push(root);

    while(!st1.empty()){
        TreeNode* temp = st1.top();
        st1.pop();
        if(temp -> left != NULL) st1.push(temp -> left);
        if(temp -> right != NULL) st1.push(temp -> right);
        st2.push(temp);
    }

    while(!st2.empty()){
        TreeNode* temp = st2.top();
        ans.push_back(temp -> val);
        st2.pop();
    }

    return ans;
}


//using one stack TC: O(2n) SC: O(n);

// vector<int> postOrder1St(TreeNode* root){
//     vector<int> ans;
//     stack<TreeNode*> st;
//     if(root == NULL) return ans;
//     TreeNode* curr = root;
//     while(root != NULL || !st.empty()){
//         if(curr != NULL){
//             st.push(curr);
//             curr = curr -> left;
//         }
//         else{
//             TreeNode* temp = st.top();
//             if(temp -> right == NULL){
//                 ans.push_back(temp -> val);
//                 st.pop();
//                 while(!st.empty() && st.top() -> right != NULL){
//                     temp = st.top() -> right;
//                     ans.push_back(temp -> val);
//                     st.pop();
//                 }
//             }
//         }
//     }
// }

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

    vector<int> ans = postorderTraversal(root);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;

}