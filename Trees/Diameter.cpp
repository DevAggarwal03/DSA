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

int height(node* root){
    if(root == NULL){
        return 0;
    }


    int leftHeight = height(root -> left);
    int rightHeight = height(root -> right);

    return max(leftHeight, rightHeight) + 1;
}



int Diameter(node* root){
    if(root == NULL){
        return 0;
    }

    int leftTree = Diameter(root -> left);
    int rightTree = Diameter(root -> right);
    int fullTree = height(root -> left) + height(root -> right);

    return max(leftTree, max(rightTree, fullTree));

}

pair<int, int> fastDiameter(node* root){
    if(root == NULL){
        return pair<int, int>(0, 0);
    }

    pair<int,int> leftTree = fastDiameter(root -> left);
    pair<int,int> rightTree = fastDiameter(root -> right);

    int height = max(leftTree.second, rightTree.second) + 1;
    int fullTree = leftTree.second + rightTree.second;
    int diameter = max(max(leftTree.first, rightTree.first), fullTree);


    return pair<int, int>(diameter, height);
}

int main(){
    // 8
    // 1 6
    // 3 4 9 
    node* root = new node(8);
    root->left = new node(1);
    root->right = new node(6);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(9);

    pair<int, int> ans = fastDiameter(root);
    cout<<ans.first<<endl;

    return 0;

}