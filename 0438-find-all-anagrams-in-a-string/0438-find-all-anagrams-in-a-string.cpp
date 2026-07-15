class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()){
            return {};
        }
        
        vector<int> ans;
        unordered_map<char, int> mp1;
        // Frequency at p
        for(char ch : p){
            mp1[ch]++;
        }

        for(int i=0;i<=s.size()-p.size();i++){
            unordered_map<char, int> mp2;

            // create freqency of current substring
            for(int j=i;j<i+p.size();j++){
                mp2[s[j]]++;
            }

            if(mp1 == mp2){
            ans.push_back(i);
            }  
        }
        return ans;
    }
};