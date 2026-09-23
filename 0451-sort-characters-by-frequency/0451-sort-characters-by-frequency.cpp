class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char , int> mp;
        string ans = "";

        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }

        while(!mp.empty()){
            char maxChar;
            int maxFreq = 0;

            for(auto it : mp){
                if(it.second > maxFreq){
                    maxFreq = it.second;
                    maxChar = it.first;
                }
            }

            for(int i=0;i<maxFreq;i++){
                ans += maxChar;
            }
            
            mp.erase(maxChar);
        }
        return ans;
    }
};