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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) {
            return NULL;
        }
        if(n == 0) {
            return head;
        }
        
        ListNode* temp = head;
        
        int count = 0;

        while(temp != NULL) {
            count++;
            temp = temp -> next;
        }
        // cout << count << endl;
        
        if(count == n) {
            temp = head;
            head = head -> next;
            delete temp;
            return head;
        }
        
        else { 
              head -> next = removeNthFromEnd(head -> next, n);        
              return head;    
        }
        
       // 1->2->3->4->5 -> NULL
    
        
    }
};