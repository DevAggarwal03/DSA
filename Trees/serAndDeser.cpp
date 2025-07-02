#include "../stdc++.h"
#include <sstream>
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

void printTree(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            TreeNode* curr = q.front();
            q.pop();
            cout<<curr->val<<" ";

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);

        }
        cout<<endl;
    }
}

// class Codec {
// private:
//     int getMaxHeight(TreeNode* root){
//         if(root == NULL) return 0;

//         int leftHeight = getMaxHeight(root->left);
//         int rightHeight = getMaxHeight(root -> right);

//         return max(leftHeight, rightHeight) + 1;
//     }
// public:

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         if(root == NULL) return "#";

//         int maxHeight = getMaxHeight(root);
//         int lv = 0;
//         queue<TreeNode*> q;
//         q.push(root);
//         string serializedStr = "";
//         TreeNode* currNode = NULL;
//         while(!q.empty() || lv == maxHeight){
//             int size = q.size();
//             for(int i=0; i<size; i++){
//                 currNode = q.front();
//                 q.pop();
//                 string tempStr = ""; 
//                 if(currNode != NULL){
//                     tempStr = to_string(currNode->val);
//                 }else{
//                     tempStr = "#";
//                 }
//                 serializedStr += tempStr;
//                 q.push(currNode->left);
//                 q.push(currNode->right);
//             }
//             lv++;
//         }
//         cout<<"string: "<<serializedStr;
//         return serializedStr;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
        
//     }
// };

int getMaxHeight(TreeNode* root){
    if(root == NULL) return 0;

    int leftHeight = getMaxHeight(root->left);
    int rightHeight = getMaxHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

string serialize(TreeNode* root) {
    if(root == NULL) return "#";

    int maxHeight = getMaxHeight(root);
    int lv = 0;
    queue<TreeNode*> q;
    q.push(root);
    string serializedStr = "";
    TreeNode* currNode = NULL;
    while(!q.empty() && lv < maxHeight){
        int size = q.size();
        for(int i=0; i<size; i++){
            currNode = q.front();
            q.pop();
            string tempStr = ""; 
            if(currNode != NULL){
                tempStr = to_string(currNode->val);
            }else{
                tempStr = "#";
            }
            serializedStr += tempStr;
            serializedStr += "|";
            if(currNode == NULL){q.push(NULL);}else{q.push(currNode->left);};
            if(currNode == NULL){q.push(NULL);}else{q.push(currNode->right);};
        }
        lv++;
    }
    return serializedStr;
}

TreeNode* deserialized(string data){
    if(data.size() == 0) return NULL;

    stringstream s(data);
    string str;
    getline(s, str, '|');
    TreeNode* currNode = new TreeNode(stoi(str));
    TreeNode* root = currNode;
    queue<TreeNode*> q;
    q.push(currNode);
    while(!q.empty()){
        currNode = q.front();
        q.pop();
        getline(s, str, '|');
        if(str == "#"){
            currNode -> left == NULL;
        }else{
            TreeNode* leftNode = new TreeNode(stoi(str));
            q.push(leftNode);
            currNode->left = leftNode;
        }

        getline(s, str, '|');
        if(str == "#"){
            currNode -> right == NULL;
        }else{
            TreeNode* rightNode = new TreeNode(stoi(str));
            q.push(rightNode);
            currNode->right = rightNode;
        }
    }

    return root;
}

int main(){
    // Codec ser, deser;
    TreeNode* root = new TreeNode(8); root->left = new TreeNode(-1); root->right = new TreeNode(16); root->left->left = new TreeNode(3); root->left->right = new TreeNode(4); root->right->right = new TreeNode(9);
    // cout<<endl;
    printTree(root);

    // cout<<endl;
    string msg = serialize(root);
    cout<<"msg: "<<msg<<endl;
    TreeNode* ans = deserialized(msg);
    // TreeNode* ansRoot = deser.deserialize(ser.serialize(root));

    printTree(ans);
    return 0;

}