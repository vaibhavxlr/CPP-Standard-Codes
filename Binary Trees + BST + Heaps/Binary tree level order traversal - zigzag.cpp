class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root == NULL) {
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        int count = 0;
        
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
            if(count % 2 != 0)
                reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            count++;
        }
        return ans;
    }
};