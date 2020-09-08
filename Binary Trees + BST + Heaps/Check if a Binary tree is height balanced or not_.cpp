class Solution {
public:
    pair<int,bool> maxDepth(TreeNode* root) {
        
        pair<int, bool> p = {0, true};
        
        if(root == NULL) {
            return p;
        }
    
        pair<int, bool> p1 = maxDepth(root -> left);
        pair<int, bool> p2 = maxDepth(root -> right);
        
        p.first = 1 + max(p1.first, p2.first);
        p.second = (p1.second && p2.second && abs(p1.first - p2.first) <= 1); 
        return p;
    }
    
    bool isBalanced(TreeNode* root) {    
        if(root == NULL)
            return true;        
        return maxDepth(root).second;
    }
};