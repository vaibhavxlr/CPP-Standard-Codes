void helper(Node *root, Node *&prev, Node *&head) {
    if(root == NULL)
        return;
        
    helper(root -> left, prev, head);
    
    if(prev == NULL) {
        prev = root;
        head = root;
    }
    else {
        prev -> right = root;
        root -> left = prev;
        prev = root;
    }
    
    helper(root -> right, prev, head);
}

Node * bToDLL(Node *root)
{
    Node *prev = NULL, *head = NULL;
    helper(root, prev, head);
    return head;
}

