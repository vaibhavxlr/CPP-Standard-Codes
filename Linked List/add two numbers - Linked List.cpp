class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL || l2 == NULL) 
            return l1 == NULL ? l2 : l1;
        
        int carry = 0;
        ListNode *newhead = NULL, *nex = NULL;
        
        while(l1 || l2 || carry) {
            int a = (l1) ? l1 -> val : 0;
            int b = (l2) ? l2 -> val : 0;
            int sum =  a + b + carry;
            
            ListNode *ans = new ListNode((sum % 10));
            //ut <<  -> val << endl;
            if(!newhead)
                newhead = ans, nex = ans;
            else 
                nex -> next = ans, nex = ans;
            carry = sum / 10;
            //cout << sum % 10 << "\n" << carry << endl;
            if(l1)
              l1 = l1 -> next;
            if(l2)
              l2 = l2 -> next;
        }
        
        return newhead;
    }
};