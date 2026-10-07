class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* temp = head;

        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        count = count / 2 + 1;

        temp = head;

        while(count > 1){
            temp = temp->next;
            count--;
        }
        return temp;
    }
};