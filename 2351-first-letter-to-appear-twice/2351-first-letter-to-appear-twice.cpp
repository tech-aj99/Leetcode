class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char, int> mp;

        for(char ch : s){
            mp[ch]++;
            if(mp[ch] == 2){
                return ch;
            }
        }
        return ' ';
    }
};