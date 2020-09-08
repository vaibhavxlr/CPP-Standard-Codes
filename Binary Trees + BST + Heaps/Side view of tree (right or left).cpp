
class Solution {
public:
    
    void helper(TreeNode* root, vector<int> &ans, int level) {
        if(root == NULL)
            return;
        
        if(ans.size() == level) ans.push_back(root -> val);// at each level, there should be only one element present, as visible from right view, for example at level 0, there should be zero elements in ans array to add one element to it
         helper(root -> right, ans, level + 1);
         helper(root -> left, ans, level + 1); //just reverse the order of both recursive calls to get left view
            
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        helper(root, ans, 0);
        return ans;
    }
};