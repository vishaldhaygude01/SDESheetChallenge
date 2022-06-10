class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL)return l2;
        if(l2 == NULL)return l1;
        ListNode dummyNode = NULL;
        ListNode* tail = &dummyNode;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummyNode.next;
        
        /*
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        ListNode* result = NULL;
        if(l1->val <= l2->val){
            result = l1;
            result->next = mergeTwoLists(l1->next, l2);
        }
        else{
            result = l2;
            result->next = mergeTwoLists(l1,l2->next);
        }
        return result;
        
        */
    }   
};