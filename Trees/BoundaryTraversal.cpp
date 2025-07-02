#include "../stdc++.h"
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;
    
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void solve(node* root, vector<int>& ans){
    if(root == NULL) return;
    if(root -> left == NULL && root -> right == NULL){
        ans.push_back(root -> data);
        return;
    }

    if(root -> left) solve(root -> left, ans);
    if(root -> right) solve(root -> right, ans);
}

vector<int> boundaryTraversal(node* root){
    vector<int> ans;
    node* curr = root;
    while(curr != NULL){
        ans.push_back(curr->data);
        if(curr -> left == NULL){
            if(curr -> right != NULL){
                curr = curr-> right;
            }
            else{
                break;
            }
        }else{
            curr = curr->left;
        }
    }

    ans.pop_back();

    solve(root, ans);
    curr = root;
    while(curr -> left != NULL && curr -> right == NULL){
        curr = curr -> left;
    }
    vector<int> temp;
    if(curr -> left != NULL){
        ans.pop_back();
        while(curr != NULL){
            temp.push_back(curr -> data);
            if(curr -> right == NULL){
                if(curr -> left != NULL){
                    curr = curr -> left;
                }else{
                    break;
                }
            }else{
                curr = curr -> right;
            }
        }
    }
    for(int i=temp.size() - 1; i>0; i--){
        cout<<temp[i]<<" ";
        ans.push_back(temp[i]);
    }
    cout<<endl;

    return ans;
}

int main(){

    node* root = new node(10);
    root->left = new node(20);
    root->left->left = new node(342);
    root ->left->left->left = new node(2);
    root->left->left->right = new node(5);

    root->left->right = new node(40);

    root->left->right->left = new node(50);
    root->left->right->left->right = new node(70);
    root->left->right->left->right->right = new node(80);

    vector<int> ans = boundaryTraversal(root);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;

}