class Solution {
public:
    int appendCharacters(string s, string t) {
        string ans = "";
        int j = 0;

        for(int i=0;i<s.size() && j<t.size();i++){
            if(s[i] == t[j]){
                ans.push_back(t[j]);
                j++;
            }
        }
        return t.size() - ans.size();
    }
};