class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;
        for(char ch : word){
            mp[ch]++;
        }

        vector<int> freq;

        for(auto it : mp){
            freq.push_back(it.second);
        } 
        // Highest Freqeuncy first
        sort(freq.rbegin(), freq.rend());

        int ans = 0;
        for(int i=0;i<freq.size();i++){
            int temp = (i / 8) + 1;
            ans += freq[i] * temp;
        }
        return ans;
    }
};