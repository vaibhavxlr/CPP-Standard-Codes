class Solution {
public:

    
    void flatten(TreeNode* root) {
        if(root == NULL)
           return;
        
        flatten(root -> left);
        TreeNode *temp = root -> right;
        
        root -> right = root -> left;
        root -> left = NULL;
        
        flatten(temp);
        TreeNode *temp2 = root;
        
        while(root -> right != NULL)
            root = root -> right;
        root -> right = temp;
    }
};