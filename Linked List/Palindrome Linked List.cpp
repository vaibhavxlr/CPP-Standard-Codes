/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverseLL(ListNode *head) {
        if(head == NULL || head -> next == NULL) {
            return head;
        }
        
        ListNode *temp = reverseLL(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return temp;
        
    }
    
    
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL) {
            return true;
        }
        
        ListNode *temp = head;
        ListNode *head2 = NULL;
        ListNode *tail2 = NULL;
        
        while(temp != NULL) {
            if(head2 == NULL) {
                head2 = new ListNode(temp -> val);
                tail2 = head2;
            }      
            
            else {
                tail2 -> next = new ListNode(temp -> val);
                tail2 = tail2 -> next;
            }
            temp = temp -> next;
        }
        
        head2 = reverseLL(head2);
        temp = head2;
        
        while(head != NULL && head2 != NULL) {
            if(head -> val == head2 -> val) {
                head = head -> next;
                head2 = head2 -> next;
            }
            else {
                return false;
            }
        }
        
        while(temp != NULL) {
            head2 = temp;
            temp = temp -> next;
            delete head2;
        }
        
        return true;
        
       
    }
};