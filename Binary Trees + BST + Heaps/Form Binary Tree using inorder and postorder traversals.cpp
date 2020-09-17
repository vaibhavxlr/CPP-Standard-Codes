class Solution {
public:
    TreeNode* helper(vector<int> &ino, int inst, int inE, vector<int> &pso, int psst, int psE) {
        
    if(inst > inE) {
        return NULL;
    }    
    
    TreeNode *root = new TreeNode(pso[psE]);
    
    int rootindex = -1;
    for(int i = inst; i <= inE; i++) {
        if(pso[psE] == ino[i]) {
            rootindex = i; 
            break;
        }
    }    
    
        
    //indices for recursive calls
    int linst = inst;
    int linE = rootindex - 1;
    int lpsst = psst;
    int lpsE = (linE - linst) + lpsst;
    int rinst = rootindex + 1;
    int rinE = inE;
    int rpsst = lpsE + 1;
    int rpsE = psE - 1;
    
    root -> left = helper(ino, linst, linE, pso, lpsst, lpsE);
    root -> right = helper(ino, rinst, rinE, pso, rpsst, rpsE);
    return root;
}
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};