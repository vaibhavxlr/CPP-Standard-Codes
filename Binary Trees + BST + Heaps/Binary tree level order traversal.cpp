class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
       
        if(root == NULL) {
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        // vector <int> temp;
        // temp.push_back(root -> val);
        // ans.push_back(temp);
        
        
        while(!q.empty()) {
            int n = q.size();
            vector <int> temp;
            
            for(int i = 0; i < n; i++) {
                
                TreeNode *ptr = q.front();
                q.pop();
                temp.push_back(ptr -> val);
                if(ptr -> left)
                   q.push(ptr -> left);

                if(ptr -> right)
                   q.push(ptr -> right);
                
            }
            
            ans.push_back(temp);

        }
        return ans;
    }
};