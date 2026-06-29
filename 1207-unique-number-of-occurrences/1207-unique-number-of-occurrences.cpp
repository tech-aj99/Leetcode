class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;   // store -> frequency
        unordered_set<int> s;         // store unique frequencies

        // count frequency of each number
        for(int x : arr){
            mp[x]++;
        }

        // check if any frequencies repeats
        for(auto it : mp){
            if(s.count(it.second)){      // Frequency already exists
                return false;
            }
            s.insert(it.second);         // Store new frequency
        }
        return true;
    }
};