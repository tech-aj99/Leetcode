class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;

        ListNode* temp = head;
        vector<int> ans;

        while(temp != NULL){
            ans.push_back(temp->val);
            temp = temp->next;
        }  

        sort(ans.begin(), ans.end());

        int i = 0;
        temp = head;
        while(i < ans.size()){
            temp->val = ans[i];
            temp = temp->next;
            i++;
        }
        return head;
    }
};