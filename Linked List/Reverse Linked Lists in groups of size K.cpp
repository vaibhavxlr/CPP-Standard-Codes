ListNode* reverseLL(ListNode *head) {
        if(head == NULL || head -> next == NULL) {
            return head;
        }
        
        ListNode *temp = reverseLL(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return temp;
        
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head ->next == NULL)
            return head;
        
        int count = 0;
        
        ListNode *temp = head, *prev = head;
        
        while(temp) {
            count++;
            temp = temp -> next;
        }
        
        int numOfGr = count / k;
        if(numOfGr == 0) 
            return head;
        
        temp = head;
        ListNode *newhead = NULL;
    
        for(int i = 0; i < k; i++) {
            prev = temp;
            temp = temp -> next;
            
        }
        prev -> next = NULL;
        temp = reverseKGroup(temp, k);
        prev = reverseLL(head);
        head -> next = temp;
        return prev;
    }
};