class Solution {
public:
    TreeNode* helper(vector<int> &ino, int inst, int inE, vector<int> &preo, int prst, int prE) {
    if(inst > inE) {
        return NULL;
    }    
    
    TreeNode *root = new TreeNode(preo[prst]);
    
    int rootindex = -1;
    for(int i = inst; i <= inE; i++) {
        if(preo[prst] == ino[i]) {
            rootindex = i; 
            break;
        }
    }    
    
        
    //indices for recursive calls
    int linst = inst;
    int linE = rootindex - 1;
    int lprst = prst + 1;
    int lprE = (linE - linst) + lprst;
    int rinst = rootindex + 1;
    int rinE = inE;
    int rprst = lprE + 1;
    int rprE = prE;
    
    root -> left = helper(ino, linst, linE, preo, lprst, lprE);
    root -> right = helper(ino, rinst, rinE, preo, rprst, rprE);
    return root;
}
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1);
    }
};