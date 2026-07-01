class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int ,int> mp;
        // count losses
        for(int i=0;i<matches.size();i++){
            int winner = matches[i][0];
            int loser = matches[i][1];

            mp[winner] += 0;    // add winner with zero losses if not present
            mp[loser]++;       // increase losers loss count
        }

        vector<int> zeroloss;
        vector<int> oneloss;

        // separate players based on lossses
        for(auto it : mp){
            if(it.second == 0){
                zeroloss.push_back(it.first);
            }
            else if(it.second == 1){
                oneloss.push_back(it.first);
            }
        }
        return {zeroloss, oneloss};
    }
};