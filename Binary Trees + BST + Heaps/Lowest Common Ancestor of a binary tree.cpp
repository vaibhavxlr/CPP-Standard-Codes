class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)     {
        if(root == NULL) {
            return NULL;
        }
        
        if(p == root || q == root) {
            return root;
        }
        
        TreeNode *rleft = NULL, *rright = NULL;
        
        if(root -> left != NULL) {
            rleft = lowestCommonAncestor(root -> left, p, q);
        }
        
        if(root -> right != NULL) {
            rright = lowestCommonAncestor(root -> right, p, q);
        }
        
        if(rleft == NULL)
            return rright;
        if(rright == NULL)
            return rleft;
       
        return root;
        
    }
};