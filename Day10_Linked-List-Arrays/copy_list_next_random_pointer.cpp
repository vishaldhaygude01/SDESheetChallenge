class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *current = head, *next;
        while (current != NULL) {
            next = current->next;

            Node* copy=new Node(current->val);
            current->next = copy;
            copy->next = next;

            current = next;
          }
          current = head;
          while (current != NULL) {
            if (current->random != NULL) {
              current->next->random = current->random->next;
            }
            current = current->next->next;
          }
          current = head;
          Node* dummy = new Node(0);
          Node* copy, *copyTail = dummy;
          while (current != NULL) {
            next = current->next->next;
            // extract the copy
            copy = current->next;
            copyTail->next = copy;
            copyTail = copy;
            // restore the original list
            current->next = next;
            current = next;
          }
          return dummy->next;
    }
};