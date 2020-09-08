
//***********
/* 
IMPORTANT NOTE

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

*/

class Solution {
public:
    int helper(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root -> left == NULL && root -> right == NULL)
            return 1;
        
        int a = helper(root -> left);
        int b = helper(root -> right);
        
        if(a == 0 or b == 0) return max(a, b) + 1;
        else return min(a, b) + 1;
    }
        
    int minDepth(TreeNode* root) {
        return helper(root);
    }
};