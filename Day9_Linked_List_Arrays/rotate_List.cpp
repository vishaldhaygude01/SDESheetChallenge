class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }
        ListNode* current = head;
        int count = 1;
        while(current->next != NULL && ++count){
            current = current->next;
        }
        current->next = head;
        k = k % count;
        k = count - k;
        while(k--){
            current = current->next;
        }
        head = current->next;
        current->next = NULL;
        return head;
    } 
};