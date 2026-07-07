class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26,0);
        for(char ch : s){
            freq[ch - 'a']++;
        }
        string ans = "";
        for(char ch : s){
            freq[ch - 'a']--;
            // skip if it already present in answer
            if(ans.find(ch) != string::npos){
                continue;
            }
            //Remove larger character if they appear
            while(!ans.empty() && ans.back() > ch  && freq[ans.back() - 'a'] > 0){
                ans.pop_back();
            }
            // Add current character
            ans.push_back(ch);
        }
        return ans;
    }
};