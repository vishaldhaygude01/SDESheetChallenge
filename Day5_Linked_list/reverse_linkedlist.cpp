class Solution {
public:
    ListNode* reverseList(ListNode* head) { 

        
        ListNode* newHead = NULL;
            while(head != NULL){
            ListNode* next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;

        
        /*
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* rest = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
        */
    }
};