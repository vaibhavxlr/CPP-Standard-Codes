/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        
        if(head == NULL) {
            return NULL;
        }
        
        
        Node* temp = head;
        
        while(temp != NULL) {
            
            //step1
        while( temp != NULL && temp -> child == NULL ) {
            temp = temp -> next;
        }
        
        if(temp == NULL) {
            return head;
        }
         
            //step2
        Node* temp2 = temp -> next; //continuation of level 1 of doubly linkedlist
        
        temp -> next = temp -> child;// connect the current node to its child
            
        temp -> child = NULL; // set current node's child to NULL
        
            //step3
        Node *temp3 = temp -> next; // save the starting of level 2 doubly linked list
        temp3 -> prev = temp;
        
        temp3 = flatten(temp3); // this will recursively flattenn all the sub lists
        
        while(temp3 -> next != NULL) {
            temp3 = temp3 -> next;  // bring temp3 to the last of level 2 linked list
        }
        
        temp3 -> next =  temp2; // connect last node of level2 LL to level 1 LL
        if(temp2 != NULL)         
            temp2 -> prev = temp3;
        
        temp = temp2;
    }
        return head;
    }
};