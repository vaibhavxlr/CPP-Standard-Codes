/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
      
        if(head == NULL) {
            return head;
        }
        
        Node *cur = head;
        Node *temp;
        
        while(cur != NULL) {
            
            Node *ne = new Node(cur -> val);    
            temp = cur -> next;
            ne -> next = temp;
            cur -> next = ne;
            cur = temp;
            
        }
        
        cur = head;

        while(cur != NULL && cur -> next != NULL) {
            if(cur -> random) {
                cur -> next -> random = cur -> random -> next;
            }
            
            else {
                cur -> next -> random = NULL;
            }
            
            cur = cur -> next -> next;
            
        }
        
        
        Node *newhead = head -> next;
        cur = head;
        temp = newhead;
        
        while(cur != NULL && temp != NULL ) {
            
            if(cur -> next)
               cur -> next = cur -> next -> next;

            
            if(temp -> next)
               temp -> next = temp -> next -> next;
            
            temp = temp -> next; 
            cur = cur -> next;
        }
        
        return newhead;
       
    }
};