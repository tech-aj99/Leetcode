class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> need(26, 0);
        for(string word : words2){
            vector<int> freq(26 ,0);
            for(char ch : word){
                freq[ch - 'a']++;
            }
            for(int i=0;i<26;i++){
                need[i] = max(need[i] , freq[i]);
            }
        }

        for(string word : words1){
            vector<int> freq(26, 0);
            for(char ch : word){
                freq[ch - 'a']++;
            }
            bool ok = true;
            for(int i=0;i<26;i++){
                if(freq[i] < need[i]){
                    ok = false;
                    break;
                }
            }
            if(ok){
                ans.push_back(word);
            }
        }
        return ans;
    }
};