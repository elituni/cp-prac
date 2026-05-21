#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* left = nullptr;
    Node* right = nullptr;
    char val = '\0';
};

void re(Node* root, string pre, string post){
    root->val = pre[0];
    if(pre.size() == 1 || post.size() == 1) return;
    char lroot = pre[1];
    char rroot = post[post.size()-2];
    string lpre, rpre, lpost, rpost;
    for(int i = 0; i < pre.size(); i++){
        if(pre[i] == rroot){
            lpre = pre.substr(1,i-1);
            rpre = pre.substr(i);
        }
    }
    for(int i = 0; i < post.size(); i++){
        if(post[i] == lroot){
            lpost = post.substr(0,i+1);
            rpost = post.substr(i+1,post.size()-(i+2));
        }
    }
    if(lpre.size() != 0){
        root->left = new Node;
        re(root->left, lpre, lpost);
    }if(rpre.size() != 0){
        root->right = new Node;
        re(root->right, rpre, rpost);
    }
}

void inorder(Node* root){
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->val;
    inorder(root->right);
    delete root;
    root = nullptr;
}

int main(){
    string preorder, postorder;
    cin >> preorder;
    cin >> postorder;
    Node* root = new Node;
    re(root,preorder,postorder);
    inorder(root);
    cout << endl;
}