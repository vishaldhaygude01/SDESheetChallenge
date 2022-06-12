class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        ListNode* p = head;
        ListNode* q = head;
        while(q->next && q->next->next){
            p = p->next;
            q = q->next->next;
            if(p==q){
                return true;
            }
        }
        return false;
    }
};