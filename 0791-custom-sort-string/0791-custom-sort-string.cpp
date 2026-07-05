class Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";
        vector<int> freq(26, 0);
        for(char ch : s){
            freq[ch - 'a']++;
        }

        for(char ch : order){
            while(freq[ch - 'a'] > 0){
                ans.push_back(ch);
                freq[ch - 'a']--;
            }
        }

        // Add remaining characters
        for(int i=0;i<26;i++){
            while(freq[i] > 0){
                ans.push_back(i + 'a');
                freq[i]--;
            }
        }
        return ans;
    }
};