
class Solution {
public:
    Node* connect(Node* root) {
        //https://www.youtube.com/watch?v=bmjAiDsIDas
        
        Node* leftnode = root;
        while(leftnode != NULL && leftnode -> left != NULL) {
            goconnect(leftnode);
            leftnode = leftnode -> left;
        }
        return root;
    }
    
    void goconnect(Node* leftnode) {
        
        if(leftnode -> left == NULL && leftnode -> right == NULL) {
            return;
        }
        
        Node *temp = leftnode;
        while(temp != NULL) {
            temp -> left -> next = temp -> right;
            if(temp -> next != NULL )
                temp -> right -> next = temp -> next -> left;
            temp = temp -> next;
        }
    }
};