
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(!root)
        return;
        
    else if(key == root -> key) {
        if(root -> left) {
            pre = root -> left;
            while(pre -> right) 
                pre = pre -> right;
        }
        
        if(root -> right) {
           suc = root -> right;
           while(suc -> left) 
              suc = suc -> left;
        }
    }
    
    else if(key < root -> key) {
        suc = root;
        findPreSuc(root -> left, pre, suc, key);
    }
    else {
        pre = root;
        findPreSuc(root -> right, pre, suc, key);
    }
    
// Your code goes here

}