class Solution {
public:
    string ans = "";
    bool solve(string &curr, vector<int> &count, string &target, int i, bool greater){
        // All characters are used
        if(i == target.size()){
            if(greater){
                ans = curr;
                return true;
            }
            return false;
        }

        // Try characters from 'a' to 'z'
        for(char ch = 'a'; ch <= 'z'; ch++){
            // Character not available
            if(count[ch - 'a'] == 0){
                continue;
            }

            // If still equal, don't choose smaller character
            if(!greater && ch < target[i]){
                continue;
            }

            // Choose character
            curr.push_back(ch);
            count[ch - 'a']--;

            // Check whether we are greater now
            bool isGreater = greater || (ch > target[i]);

            // Recurse
            if(solve(curr, count, target, i+1, isGreater)){
                return true;
            }

            // Backtrack
            curr.pop_back();
            count[ch - 'a']++;

        }
        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26, 0);

        for(char ch : s){
            count[ch - 'a']++;
        }

        string curr = "";
        solve(curr, count, target, 0, false);

        return ans;
    }
};