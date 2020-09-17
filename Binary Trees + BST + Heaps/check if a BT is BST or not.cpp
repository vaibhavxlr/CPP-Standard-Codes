class Solution {
public:
    bool help(TreeNode* root, TreeNode *ninf, TreeNode *pinf) {
        if(root == NULL) {
            return true;
        }//INT_MIN AND INT_MAX don't work here
    
        if((ninf && (root -> val <= ninf -> val)) || (pinf && root -> val >= pinf -> val)) {
            return false;
        }
        
        return (help(root -> left, ninf, root) && help(root -> right, root, pinf));
        
    }
    
    bool isValidBST(TreeNode* root) {
        
        if((root == NULL))
            return true;      
        return help(root, NULL, NULL);
    }
};