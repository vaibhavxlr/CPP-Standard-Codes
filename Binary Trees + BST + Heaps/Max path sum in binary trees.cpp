class Solution {
    
public:
    
    pair<int, int> helper(TreeNode* root) {
        
        pair<int, int> ans;
        ans.first = 0; //max path coming from subtrees upto the root node
        ans.second = INT_MIN; // max path within the subtrees
        
        if(root == NULL) {
            return ans;
        }
        
        pair<int, int> left_ans = helper(root -> left);
        pair<int, int> right_ans = helper(root -> right);
        
        //from both the left and right subtrees find out which is max path coming upto root node, finding max out of the two and if it's negative then we don't need it
        ans.first = max(0, max(left_ans.first, right_ans.first)) + root -> val; 
        //there's chance that max path just doesn't end at root and pass through it to the other side
        int temp = root -> val + right_ans.first + left_ans.first;
        
        //max contains the maximum possible path of all the possible cases
        /* possible cases:-
            
            a       a            a
           /       / \          %
          b       b   c        b
         /                    / \
        c                    c   d
        max        max       max present
        ending     passing   in any of the
        at root    through   subtrees
                   root        
        */
        ans.second = max(max(ans.first, temp), max(left_ans.second, right_ans.second));

        
        return ans;
    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        return helper(root).second;
    }
};