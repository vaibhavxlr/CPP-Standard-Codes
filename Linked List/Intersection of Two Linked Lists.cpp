class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     
        cout << headA << " " << headB;
        if(headA == headB) {
            return headA;
        }
       while(headA !=  NULL) {
           cout << headA -> val << " ";
           headA = headA -> next;
       }  
        cout << endl;
        while(headB != NULL) {
            cout << headB -> val << " ";
            headB = headB -> next;
        }
        return headA;
    }
};