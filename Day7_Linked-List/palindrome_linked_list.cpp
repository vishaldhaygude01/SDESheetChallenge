class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* current = slow;
         while(current != NULL){
             next = current->next;
             current->next = prev;
             prev = current;
             current = next;
        }
        fast = head;
        while(prev != NULL){
            if(fast->val != prev->val){
                return false;
            }
            fast = fast->next;
            prev = prev->next;
        }
        return true;
    }
};
