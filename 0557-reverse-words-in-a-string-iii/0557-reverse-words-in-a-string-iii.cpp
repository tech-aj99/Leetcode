class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";

        for(int i=0;i<s.size();i++){
            if(s[i] != ' '){
                temp.push_back(s[i]);
            }
            else{
                reverse(temp.begin(), temp.end());
                ans += temp;
                ans.push_back(' ');
                temp = "";
            }
        }
        // reverse the last word
        reverse(temp.begin(), temp.end());
        ans += temp;

        return ans;
    }
};