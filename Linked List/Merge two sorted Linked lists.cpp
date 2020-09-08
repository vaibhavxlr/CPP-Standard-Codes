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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL || l2 == NULL) {
            return (l1 == NULL) ? l2 : l1;
        }
        
        ListNode *Next = NULL, *newhead = NULL;
        
        if(l1 -> val <= l2 -> val)
        {
            newhead = Next = l1;
            l1 = l1 -> next;
        }
        else {
            newhead = Next = l2;
            l2 = l2 -> next;
        }
        
        while(l1 != NULL && l2 != NULL) {
            if(l1 -> val <= l2 -> val) {
               Next -> next = l1;
               l1 = l1 -> next;
            }
            else {
               Next -> next = l2; 
               l2 = l2 -> next;
            }
            Next = Next -> next;
        }
        
        if(l1) {
            Next -> next = l1;
        }
        if(l2) {
            Next -> next = l2;
        }
        
        return newhead;
        
    }
};