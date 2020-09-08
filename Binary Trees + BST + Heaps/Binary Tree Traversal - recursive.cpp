#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left, *right;
    node(int x) {
        val = x;
        left = right = NULL;
    }
};


void inorder(node *root) {
    if(root == NULL) {
        return;
    }
    
    inorder(root -> left);
    cout << root -> val << " ";
    inorder(root -> right);
}

void preorder(node *root) {
    if(root == NULL) {
        return;
    }
    
    cout << root -> val << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(node *root) {
    if(root == NULL) {
        return;
    }
    
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> val << " ";
}

void traversal(node *root) {
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
}

int main()
{
    node *root = new node(7); 
    node *t = root;
    root->left = new node(3); root->right = new node(10);
    root->left->left = new node(2); root->left->right = new node(5);
    root->left->left->left = new node(1);
    root->right->left = new node(8); 
    root->right->right = new node(12);
    
    traversal(root);
}