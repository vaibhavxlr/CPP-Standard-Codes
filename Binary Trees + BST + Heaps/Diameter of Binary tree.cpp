class Solution {
public:
    
    pair<int,int> cal(TreeNode *root) {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;

        if(root == NULL) {
            return p;
        }

        pair<int, int> p1 = cal(root -> right);
        pair<int, int> p2 = cal(root -> left);
        
        p.first = 1 + max(p1.first, p2.first);
        p.second = max(p1.first + p2.first, max(p1.second, p2.second));
        
        return p;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == NULL) {
            return 0;
        }
        
        pair<int, int> ans = cal(root);
        return ans.second;
    }
                  
};