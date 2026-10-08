class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }

        ListNode* temp = head;
        int count = 0;

        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        count = count / 2 + 1;

        int k = 0;
        temp = head;
        ListNode* prev = NULL;

        while(temp != NULL){
            k++;
            
            if(count == k){
                prev->next = prev->next->next;
                delete(temp);
                break;
            }

            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};