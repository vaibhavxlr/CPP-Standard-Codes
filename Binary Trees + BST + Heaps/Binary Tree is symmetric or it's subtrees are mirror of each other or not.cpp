class Solution {
public:
    
    bool helper(TreeNode *root1, TreeNode *root2) {
        
        if(root1 == NULL && root2 == NULL)
            return true;
        
        if(root1 == NULL || root2 == NULL)
            return false;
        
        return (root1 -> val == root2 -> val) && helper(root1 -> left, root2 -> right) && helper(root1 -> right , root2 -> left);
        
    }
    
    bool isSymmetric(TreeNode* root) {
       return helper(root, root);
    }
};