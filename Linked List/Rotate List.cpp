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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL) {
            return head;
        }
       
        
        int len = 0;
        ListNode* temp = head;
        ListNode* late = head;
        ListNode* onTime = head;
        ListNode* newHead = NULL;
        
        while(temp != NULL) {
            len++;
            temp = temp -> next;
        }
        
        k = k % len;
        
        if(len == k || k == 0) {
            return head;
        }
        
        else {
            
            
            int count = 0;
            
            while(count < k) {
                count++;
                onTime = onTime -> next;
            }
            
            while(onTime -> next != NULL) {
                onTime = onTime -> next;
                late = late -> next;
            }
            
            newHead = late -> next;
            late -> next = NULL;
            onTime -> next = head;
        
        
        }
        
        return newHead;
        
    }
};