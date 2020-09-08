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
    //inorder
    stack<pair<node*, int>> S;
    S.push({root, 0});
    
    while(!S.empty()){
        pair<node*, int> t = S.top();
        node* cur = t.first;
        int state = t.second;
        
        S.pop();

        if(cur == NULL or state == 3) continue;
        
        S.push({cur, state+1});
        
        if (state == 0) S.push({cur->left, 0});
        else if (state == 1) cout << cur->val << " " ;
        else if (state == 2) S.push({cur->right, 0});
    }
}

void preorder(node *root) {
    
    stack <pair<node*, int>> S;
    S.push({root, 0});
  
    while(!S.empty()) {
        pair<node*, int> t = S.top();
        node* cur = t.first;
        int state = t.second;
        
        S.pop();
        
        if(cur == NULL or state == 3) continue;
        
        S.push({cur, state + 1});
        
        if(state == 0) cout << cur -> val << " ";
        else if(state == 1) S.push({cur -> left, 0});
        else if(state == 2) S.push({cur -> right, 0});
    }
}

void postorder(node *root) {
    stack<pair<node*, int> > S;
    S.push({root, 0});
    
    while(!S.empty()) {
        pair<node*, int> t = S.top();
        node* cur = t.first;
        int state = t.second;
        
        S.pop();
        
        if(cur == NULL or state == 3) continue;
        
        S.push({cur, state + 1});
        
        if(state == 0) S.push({cur -> left, 0});
        else if(state == 1) S.push({cur -> right, 0});
        else if(state == 2) cout << cur -> val << " ";
    }
    
    
}

// 1 2 3 5 7 8 10 12 
// 7 3 2 1 5 10 8 12 
// 1 2 5 3 8 12 10 7 

int main()
{
    node *root = new node(7); 
    node *t = root;
    root->left = new node(3); root->right = new node(10);
    root->left->left = new node(2); root->left->right = new node(5);
    root->left->left->left = new node(1);
    root->right->left = new node(8); 
    root->right->right = new node(12);
    
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
}