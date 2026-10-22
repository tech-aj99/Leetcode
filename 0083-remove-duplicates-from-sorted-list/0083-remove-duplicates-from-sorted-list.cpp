class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> st;
        ListNode* temp = head;

        while(temp != NULL){
            st.insert(temp->val);
            temp = temp->next;
        }        

        ListNode* dummy = new ListNode(0);
        temp = dummy;

        for(int x : st){
            temp->next = new ListNode(x);
            temp = temp->next;
        }
        return dummy->next;
    }
};