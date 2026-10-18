class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;\
        
        // A = head
        // B = head->next
        // C = head->next->next
        // A -> B -> C -> ...

        ListNode* temp = head->next;
        head->next = swapPairs(head->next->next);
        temp->next = head;

        return temp;
    }
};