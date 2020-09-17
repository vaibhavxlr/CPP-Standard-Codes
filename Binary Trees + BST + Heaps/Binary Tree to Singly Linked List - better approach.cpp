class Solution {
public:
    void flatten(TreeNode* root, TreeNode* &prev) {
        if(root == NULL) {
            return;
        }
        TreeNode *rightNode = root -> right;
        if(prev == NULL) {
            prev = root;
        }
        else {
            prev -> left = NULL;
            prev -> right = root;
            prev = root;
        }
        flatten(root -> left, prev);
        flatten(rightNode, prev);
    }
    
    void flatten(TreeNode* root) {
       TreeNode* prev = NULL;
       flatten(root, prev);
    }
};