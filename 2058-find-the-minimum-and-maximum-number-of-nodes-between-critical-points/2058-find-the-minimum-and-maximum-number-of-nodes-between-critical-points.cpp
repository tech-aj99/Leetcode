class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        if(head == NULL || head->next == NULL || head->next->next == NULL){
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;

        int pos = 1;

        int firstCritical = -1;
        int prevCritical = -1;

        int minDist = INT_MAX;
        int maxDist = -1;

        while(curr->next != NULL){

            bool isCritical = (curr->val > prev->val && curr->next->val < curr->val) || 
                              (curr->val < prev->val && curr->next->val > curr->val);

            if(isCritical){

                if(firstCritical == -1){
                    firstCritical = pos;
                }

                else{
                    int dist = pos - prevCritical;
                    minDist = min(minDist, dist);
                }

                prevCritical = pos;
                maxDist = pos - firstCritical;
            }

            prev = curr;
            curr = curr->next;
            pos++;
        }

        if(firstCritical == prevCritical){
            return {-1, -1};
        }

        return {minDist, maxDist};
    }
};