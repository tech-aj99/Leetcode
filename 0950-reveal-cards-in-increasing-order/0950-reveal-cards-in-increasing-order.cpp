class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n = deck.size();
        vector<int> ans(n);
        queue<int> q;

        // Store all indices in the queue
        for(int i=0;i<n;i++){
            q.push(i);
        }

        // Place each sorted card at the correct position
        for(int card : deck){
            int index = q.front();
            q.pop();

            ans[index] = card;

            // Move the next index to the back
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};