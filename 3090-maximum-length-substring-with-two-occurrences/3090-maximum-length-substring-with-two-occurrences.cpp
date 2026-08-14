class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxi = 0;

        for(int left = 0;left < s.size();left++){
            for(int right = 0;right < s.size();right++){
                string strtemp = s.substr(left, right-left+1);
                
                unordered_map<char, int> mp;
                for(char ch : strtemp){
                    mp[ch]++;
                }
                bool valid = true;

                for(auto it : mp){
                    if(it.second > 2){
                        valid = false;
                        break;
                    }
                }
                if(valid){
                    maxi = max(maxi, (int)strtemp.size());
                }
            }
        }
        return maxi;
    }
};